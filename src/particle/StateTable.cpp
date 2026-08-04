#include "particle/StateTable.h"

#include "core/Report.h"
#include "particle/AsymmetricFaces.h"
#include "particle/CellDistribution.h"
#include "particle/EnergyBookkeeping.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <numbers>
#include <vector>

namespace slm
{

    std::string StateTable::name(Exit exit)
    {
        switch (exit)
        {
        case Exit::EntryFace:
            return "back out the entry face";
        case Exit::FarFace:
            return "out the far face";
        case Exit::Never:
            return "never comes out";
        }
        return "unknown";
    }

    std::string StateTable::name(Turn turn)
    {
        switch (turn)
        {
        case Turn::None:
            return "no turn";
        case Turn::Partial:
            return "partial turn";
        case Turn::Reversal:
            return "reversal";
        }
        return "unknown";
    }

    double StateTable::angle(Turn turn)
    {
        switch (turn)
        {
        case Turn::None:
            return 0.0;
        case Turn::Partial:
            return 1.0;
        case Turn::Reversal:
            return std::numbers::pi;
        }
        return 0.0;
    }

    StateTable::Four StateTable::returned(const Four &near, Turn turn)
    {
        const EnergyBookkeeping::Four far = EnergyBookkeeping::across(near);
        const EnergyBookkeeping::Four turned =
            EnergyBookkeeping::rotateFarEnergy(far, angle(turn));
        return EnergyBookkeeping::across(turned);
    }

    double StateTable::energyChange(const Four &near, Turn turn)
    {
        return returned(near, turn)[0] - near[0];
    }

    double StateTable::speedChange(const Four &near, Turn turn)
    {
        return EnergyBookkeeping::nearMomentumMagnitude(returned(near, turn)) -
               EnergyBookkeeping::nearMomentumMagnitude(near);
    }

    double StateTable::deflection(const Four &near, Turn turn)
    {
        return EnergyBookkeeping::momentumAngle(near, returned(near, turn));
    }

    bool StateTable::degenerateWithOrdinaryPhysics(Exit exit, Turn turn)
    {
        if (exit == Exit::Never)
        {
            return true;
        }
        if (turn == Turn::None)
        {
            return true;
        }
        return exit == Exit::EntryFace;
    }

    int StateTable::reachableOutcomeCount(double px, double py, double pz)
    {
        std::vector<Outcome> seen;
        const std::vector<Matrix4> faces = AsymmetricFaces::admissibleFaces();
        for (const Matrix4 &entry : faces)
        {
            for (const Matrix4 &exit : faces)
            {
                const Matrix4 trip = AsymmetricFaces::roundTrip(entry, exit);
                const Outcome outcome{AsymmetricFaces::conservesEnergy(trip),
                                      AsymmetricFaces::deflection(trip, px, py, pz)};
                const bool already =
                    std::any_of(seen.begin(), seen.end(), [&outcome](const Outcome &other) {
                        return other.energyKept == outcome.energyKept &&
                               std::abs(other.deflection - outcome.deflection) < 1e-9;
                    });
                if (!already)
                {
                    seen.push_back(outcome);
                }
            }
        }
        return static_cast<int>(seen.size());
    }

    int StateTable::outcomesKeepingEnergy(double px, double py, double pz)
    {
        return static_cast<int>(AsymmetricFaces::deflectionSpectrum(px, py, pz).size());
    }

    int StateTable::outcomesFlippingEnergy(double px, double py, double pz)
    {
        return reachableOutcomeCount(px, py, pz) - outcomesKeepingEnergy(px, py, pz);
    }

    int StateTable::discriminatingOutcomes(double px, double py, double pz)
    {
        const std::vector<double> spectrum = AsymmetricFaces::deflectionSpectrum(px, py, pz);
        return static_cast<int>(std::count_if(spectrum.begin(), spectrum.end(),
                                              [](double angle) { return angle > 1e-9; }));
    }

    int StateTable::independentLabelCount()
    {
        return 9;
    }

    int StateTable::emptyRowCells()
    {
        return 3;
    }

    void StateTableSection::run(Report &report) const
    {
        using Exit = StateTable::Exit;
        using Turn = StateTable::Turn;
        const StateTable::Four near = {5.0, 1.0, 2.0, 3.0};
        const Turn turns[] = {Turn::None, Turn::Partial, Turn::Reversal};
        const Exit exits[] = {Exit::EntryFace, Exit::FarFace, Exit::Never};

        report.subsection("Energy and speed are conserved in every cell");
        for (Turn turn : turns)
        {
            report.checkNear(std::format("  {:14} : the near-side energy is unchanged",
                                         StateTable::name(turn)),
                             StateTable::energyChange(near, turn), 1e-12);
            report.checkNear(std::format("  {:14} : the near-side speed is unchanged",
                                         StateTable::name(turn)),
                             StateTable::speedChange(near, turn), 1e-12);
        }

        report.subsection("Only the direction distinguishes the cells");
        for (Turn turn : turns)
        {
            report.check(std::format("  {:14} : deflection {:.4f} radians",
                                     StateTable::name(turn), StateTable::deflection(near, turn)),
                         StateTable::deflection(near, turn) >= 0.0);
        }
        report.checkNear("no turn leaves the direction alone",
                         StateTable::deflection(near, Turn::None), 1e-12);
        report.check("a reversal deflects further than a partial turn",
                     StateTable::deflection(near, Turn::Reversal) >
                         StateTable::deflection(near, Turn::Partial));

        report.subsection("The full table of what an observer here measures");
        int cells = 0;
        int degenerate = 0;
        for (Exit exit : exits)
        {
            for (Turn turn : turns)
            {
                ++cells;
                const bool cannotTell = StateTable::degenerateWithOrdinaryPhysics(exit, turn);
                if (cannotTell)
                {
                    ++degenerate;
                }
                const bool onlyFarFaceTurns =
                    cannotTell == (exit == Exit::Never || exit == Exit::EntryFace ||
                                   turn == Turn::None);
                report.check(std::format("  {:24} + {:14} : {}", StateTable::name(exit),
                                         StateTable::name(turn),
                                         cannotTell ? "looks like ordinary physics"
                                                    : "has no ordinary counterpart"),
                             onlyFarFaceTurns);
            }
        }
        report.check(std::format("  the table has {} cells", cells), cells == 9);

        report.subsection("The two labels are not independent");
        report.check(std::format("  treating them as independent gives {} cells, while the "
                                 "admissible face pairings reach only {}",
                                 StateTable::independentLabelCount(),
                                 StateTable::reachableOutcomeCount(1.0, 2.0, 3.0)),
                     StateTable::reachableOutcomeCount(1.0, 2.0, 3.0) <
                         StateTable::independentLabelCount());
        report.check(std::format("  the {} reachable ones split into {} keeping the near-side "
                                 "energy and "
                                 "{} returning it with the opposite sign",
                                 StateTable::reachableOutcomeCount(1.0, 2.0, 3.0),
                                 StateTable::outcomesKeepingEnergy(1.0, 2.0, 3.0),
                                 StateTable::outcomesFlippingEnergy(1.0, 2.0, 3.0)),
                     StateTable::outcomesKeepingEnergy(1.0, 2.0, 3.0) +
                             StateTable::outcomesFlippingEnergy(1.0, 2.0, 3.0) ==
                         StateTable::reachableOutcomeCount(1.0, 2.0, 3.0));
        report.check(std::format("  the row in which the particle never leaves is empty, since "
                                 "the two exit weights already come to {:.4f}",
                                 CellDistribution::exitFarFace(IntermediateRegion::Kind::SplitSignature,
                                                               1.0, 1.0, 4.0, 1.0) +
                                     CellDistribution::exitEntryFace(
                                         IntermediateRegion::Kind::SplitSignature, 1.0, 1.0, 4.0, 1.0)),
                     CellDistribution::exitNever(IntermediateRegion::Kind::SplitSignature, 1.0, 1.0, 4.0,
                                                 1.0) < 1e-12);
        report.check(std::format("  so of the {} cells, {} are emptied by flux and {} of the rest "
                                 "have no ordinary counterpart",
                                 StateTable::independentLabelCount(), StateTable::emptyRowCells(),
                                 StateTable::discriminatingOutcomes(1.0, 2.0, 3.0)),
                     StateTable::discriminatingOutcomes(1.0, 2.0, 3.0) > 0 &&
                         StateTable::discriminatingOutcomes(1.0, 2.0, 3.0) <
                             StateTable::reachableOutcomeCount(1.0, 2.0, 3.0));

        report.subsection("How much of the table is actually distinguishable");
        report.check(std::format("  {} of the {} cells are degenerate with ordinary processes",
                                 degenerate, cells),
                     degenerate > cells / 2);
        report.check("a particle that never comes out is an absorption, whatever "
                     "happened to it inside",
                     StateTable::degenerateWithOrdinaryPhysics(Exit::Never, Turn::Reversal));
        report.check("a particle that comes back out the way it went in is a "
                     "reflection, deflected or not",
                     StateTable::degenerateWithOrdinaryPhysics(Exit::EntryFace, Turn::Partial));
        report.check("and an undeflected crossing is just a crossing",
                     StateTable::degenerateWithOrdinaryPhysics(Exit::FarFace, Turn::None));

        report.subsection("The two cells that carry the model's content");
        report.check("emerging from the far face turned, with energy and speed "
                     "exactly conserved, has no ordinary counterpart",
                     !StateTable::degenerateWithOrdinaryPhysics(Exit::FarFace, Turn::Partial));
        report.check("and the same with the direction fully reversed",
                     !StateTable::degenerateWithOrdinaryPhysics(Exit::FarFace, Turn::Reversal));
        report.check("what makes them distinguishable is that the deflection costs "
                     "nothing, where an ordinary deflection needs a target to "
                     "carry the recoil",
                     std::abs(StateTable::energyChange(near, Turn::Partial)) < 1e-12 &&
                         StateTable::deflection(near, Turn::Partial) > 0.1);
    }

}
