#include "particle/StateTable.h"

#include "core/Report.h"
#include "particle/EnergyBookkeeping.h"

#include <cmath>
#include <format>
#include <numbers>

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

    StateTable::Four StateTable::returned(const Four &ours, Turn turn)
    {
        const EnergyBookkeeping::Four far = EnergyBookkeeping::across(ours);
        const EnergyBookkeeping::Four turned =
            EnergyBookkeeping::rotateFarEnergy(far, angle(turn));
        return EnergyBookkeeping::across(turned);
    }

    double StateTable::energyChange(const Four &ours, Turn turn)
    {
        return returned(ours, turn)[0] - ours[0];
    }

    double StateTable::speedChange(const Four &ours, Turn turn)
    {
        return EnergyBookkeeping::ourMomentumMagnitude(returned(ours, turn)) -
               EnergyBookkeeping::ourMomentumMagnitude(ours);
    }

    double StateTable::deflection(const Four &ours, Turn turn)
    {
        return EnergyBookkeeping::momentumAngle(ours, returned(ours, turn));
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

    void StateTableSection::run(Report &report) const
    {
        using Exit = StateTable::Exit;
        using Turn = StateTable::Turn;
        const StateTable::Four ours = {5.0, 1.0, 2.0, 3.0};
        const Turn turns[] = {Turn::None, Turn::Partial, Turn::Reversal};
        const Exit exits[] = {Exit::EntryFace, Exit::FarFace, Exit::Never};

        report.subsection("18.1  Energy and speed are conserved in every cell");
        for (Turn turn : turns)
        {
            report.checkNear(std::format("  {:14} : our energy is unchanged",
                                         StateTable::name(turn)),
                             StateTable::energyChange(ours, turn), 1e-12);
            report.checkNear(std::format("  {:14} : our speed is unchanged",
                                         StateTable::name(turn)),
                             StateTable::speedChange(ours, turn), 1e-12);
        }

        report.subsection("18.2  Only the direction distinguishes the cells");
        for (Turn turn : turns)
        {
            report.check(std::format("  {:14} : deflection {:.4f} radians",
                                     StateTable::name(turn), StateTable::deflection(ours, turn)),
                         StateTable::deflection(ours, turn) >= 0.0);
        }
        report.checkNear("no turn leaves the direction alone",
                         StateTable::deflection(ours, Turn::None), 1e-12);
        report.check("a reversal deflects further than a partial turn",
                     StateTable::deflection(ours, Turn::Reversal) >
                         StateTable::deflection(ours, Turn::Partial));

        report.subsection("18.3  The full table of what an observer here measures");
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

        report.subsection("18.4  How much of the table is actually distinguishable");
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

        report.subsection("18.5  The two cells that carry the model's content");
        report.check("emerging from the far face turned, with energy and speed "
                     "exactly conserved, has no ordinary counterpart",
                     !StateTable::degenerateWithOrdinaryPhysics(Exit::FarFace, Turn::Partial));
        report.check("and the same with the direction fully reversed",
                     !StateTable::degenerateWithOrdinaryPhysics(Exit::FarFace, Turn::Reversal));
        report.check("what makes them distinguishable is that the deflection costs "
                     "nothing, where an ordinary deflection needs a target to "
                     "carry the recoil",
                     std::abs(StateTable::energyChange(ours, Turn::Partial)) < 1e-12 &&
                         StateTable::deflection(ours, Turn::Partial) > 0.1);
    }

}
