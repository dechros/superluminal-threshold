#include "particle/BoundPair.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "particle/FarSideMotion.h"
#include "particle/ReturnEvent.h"
#include "units/PhysicalScales.h"
#include "units/ProtonJourney.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kOmega = 2.8;
        constexpr double kThickness = 8.0;
        constexpr double kPolar = 1.0471975511965976;
        constexpr double kAzimuth = 0.9;
        constexpr double kDrive = 1.5e24;
    }

    void BoundPairSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;

        const double muProton = 1.0;
        const double muElectron = muProton * (PhysicalScales::electronMass() / PhysicalScales::protonMass());

        report.subsection("One shared drive, two mass-shell lengths");
        const double lengthProton = std::sqrt(kOmega * kOmega / (c * c) - muProton);
        const double lengthElectron = std::sqrt(kOmega * kOmega / (c * c) - muElectron);
        report.check(std::format("  mu(proton) = {:.6f}, length {:.6f}; mu(electron) = {:.6e}, "
                                 "length {:.6f}, from the one drive both share",
                                 muProton, lengthProton, muElectron, lengthElectron),
                    std::isfinite(lengthProton) && std::isfinite(lengthElectron) &&
                        lengthProton > 0.0 && lengthElectron > 0.0);

        report.subsection("The same orientation and branch carried at each mass");
        const ReturnEvent::State stateProton =
            ReturnEvent::stateFromAngles(kPolar, kAzimuth, lengthProton, 1);
        const ReturnEvent::State stateElectron =
            ReturnEvent::stateFromAngles(kPolar, kAzimuth, lengthElectron, 1);
        const ReturnEvent::Event eventProton =
            ReturnEvent::map(stateProton, Kind::Euclidean, c, muProton, kThickness);
        const ReturnEvent::Event eventElectron =
            ReturnEvent::map(stateElectron, Kind::Euclidean, c, muElectron, kThickness);

        report.check(std::format("  proton returns at t = {:.6f}, electron at t = {:.6f}",
                                 eventProton.elapsed, eventElectron.elapsed),
                    std::isfinite(eventProton.elapsed) && std::isfinite(eventElectron.elapsed));
        report.check(std::format("  proton transverse ({:+.6f}, {:+.6f}), electron transverse "
                                 "({:+.6f}, {:+.6f})",
                                 eventProton.transverseFirst, eventProton.transverseSecond,
                                 eventElectron.transverseFirst, eventElectron.transverseSecond),
                    std::isfinite(eventProton.transverseFirst) &&
                        std::isfinite(eventElectron.transverseFirst));

        report.subsection("Whether the pair returns to the same event");
        const double elapsedGap = eventElectron.elapsed - eventProton.elapsed;
        const double firstGap = eventElectron.transverseFirst - eventProton.transverseFirst;
        const double secondGap = eventElectron.transverseSecond - eventProton.transverseSecond;
        report.check(std::format("  elapsed time differs by {:+.6f}, not zero", elapsedGap),
                    std::abs(elapsedGap) > 1e-6);
        report.check(std::format("  the transverse position differs by ({:+.6f}, {:+.6f}), not "
                                 "zero in either slot",
                                 firstGap, secondGap),
                    std::abs(firstGap) > 1e-6 && std::abs(secondGap) > 1e-6);
        report.check(std::format("  the exit face agrees, {:.4f} against {:.4f}, since both were "
                                 "given the same branch",
                                 eventProton.crossing, eventElectron.crossing),
                    std::abs(eventProton.crossing - eventElectron.crossing) < 1e-12);
        report.check("so a pair launched with the same orientation and branch, differing only in "
                    "mass, is carried by this map to two distinct events rather than one: the "
                    "lighter mass both returns at a different moment and lands at a different "
                    "transverse position, so the map does not keep the pair bound on return",
                    std::abs(elapsedGap) > 1e-6 && std::abs(firstGap) > 1e-6);

        report.subsection("The same gap, in seconds and metres, at the drive used throughout");
        const double secondsPerUnit = ProtonJourney::secondsPerUnit(kDrive);
        const double timeGapSeconds = elapsedGap * secondsPerUnit;
        const double firstGapMetres = firstGap * secondsPerUnit * PhysicalScales::lightSpeed();
        const double secondGapMetres = secondGap * secondsPerUnit * PhysicalScales::lightSpeed();
        report.check(std::format("  {:.4e} s between the two arrivals, {:.4e} m and {:.4e} m "
                                 "between the two transverse landing points",
                                 std::abs(timeGapSeconds), std::abs(firstGapMetres),
                                 std::abs(secondGapMetres)),
                    std::isfinite(timeGapSeconds) && std::isfinite(firstGapMetres));

        report.subsection("What this does and does not show");
        report.check("this section gives a kinematic test only: two states sharing one drive, one "
                    "orientation and one branch, differing only in mass, carried by the map "
                    "already verified for a single mass; no force, potential or bond dynamics is "
                    "represented anywhere in this project, in region I or in region II",
                    true);
        report.check("so the gap computed here is what this project's own single-particle map "
                    "gives for two masses launched alike, not a solved two-body trajectory; it "
                    "shows the map is not rigid across a mass difference, and it does not show "
                    "what force would be needed to hold two such masses together, nor what a "
                    "bound state's relative coordinate becomes in a region of one space axis and "
                    "three time axes, which this project does not model",
                    true);
    }

}
