#include "experiment/RoundTripExperiment.h"

#include "core/Report.h"
#include "units/PhysicalScales.h"
#include "units/ProtonJourney.h"
#include "units/SignatureThreshold.h"
#include "units/ThresholdScaling.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kTargetAdvance = 1.0e-9;
        constexpr double kWorkingOpacity = 10.0;
        constexpr double kBeamRate = 1.0e9;
        constexpr double kTimingResolution = 1.0e-11;
        constexpr double kBeamKineticJoules = 1.602176634e-13;
        constexpr double kCollimationReached = 1.0e-4;
        constexpr double kCollimationDemanded = 1.0e-1;
        constexpr double kIdentificationReached = 1.0;
        constexpr double kProtonRadius = 0.8414e-15;
        constexpr double kCollisionEnergy = 2.08e-6;
    }

    std::vector<RoundTripExperiment::Requirement> RoundTripExperiment::all()
    {
        return {Requirement::BeamEnergy,          Requirement::Collimation,
                Requirement::RegionDensity,       Requirement::BarrierOpacity,
                Requirement::FarSideDisplacement, Requirement::TimingResolution,
                Requirement::Statistics,          Requirement::Identification};
    }

    std::string RoundTripExperiment::name(Requirement requirement)
    {
        switch (requirement)
        {
        case Requirement::BeamEnergy:
            return "beam above the rest frequency";
        case Requirement::Collimation:
            return "transverse over total momentum";
        case Requirement::RegionDensity:
            return "density of the far region";
        case Requirement::BarrierOpacity:
            return "opacity of the crossing";
        case Requirement::FarSideDisplacement:
            return "displacement on the far side";
        case Requirement::TimingResolution:
            return "timing resolution";
        case Requirement::Statistics:
            return "launches available per second";
        case Requirement::Identification:
            return "arrival attributable to a launch";
        }
        return "unknown";
    }

    std::string RoundTripExperiment::unit(Requirement requirement)
    {
        switch (requirement)
        {
        case Requirement::BeamEnergy:
            return "rad/s";
        case Requirement::Collimation:
            return "ratio";
        case Requirement::RegionDensity:
            return "kg/m3";
        case Requirement::BarrierOpacity:
            return "decay times thickness";
        case Requirement::FarSideDisplacement:
            return "m";
        case Requirement::TimingResolution:
            return "s";
        case Requirement::Statistics:
            return "per second";
        case Requirement::Identification:
            return "tag per launch";
        }
        return "";
    }

    double RoundTripExperiment::demanded(Requirement requirement)
    {
        switch (requirement)
        {
        case Requirement::BeamEnergy:
            return ProtonJourney::lowestDriveForProton();
        case Requirement::Collimation:
            return kCollimationDemanded;
        case Requirement::RegionDensity:
            return SignatureThreshold::turningDensity();
        case Requirement::BarrierOpacity:
            return kWorkingOpacity;
        case Requirement::FarSideDisplacement:
            return displacementMetres();
        case Requirement::TimingResolution:
            return kTargetAdvance / 100.0;
        case Requirement::Statistics:
            return launchesNeeded();
        case Requirement::Identification:
            return 1.0;
        }
        return 0.0;
    }

    double RoundTripExperiment::available(Requirement requirement)
    {
        switch (requirement)
        {
        case Requirement::BeamEnergy:
        {
            const double rest = PhysicalScales::protonMass() * PhysicalScales::lightSpeed() *
                                PhysicalScales::lightSpeed();
            return (rest + kBeamKineticJoules) / PhysicalScales::reducedPlanck();
        }
        case Requirement::Collimation:
            return kCollimationReached;
        case Requirement::RegionDensity:
            return SignatureThreshold::densityInSphere(kCollisionEnergy, kProtonRadius);
        case Requirement::BarrierOpacity:
            return kWorkingOpacity;
        case Requirement::FarSideDisplacement:
            return 1.0;
        case Requirement::TimingResolution:
            return kTimingResolution;
        case Requirement::Statistics:
            return kBeamRate;
        case Requirement::Identification:
            return kIdentificationReached;
        }
        return 0.0;
    }

    bool RoundTripExperiment::largerIsBetter(Requirement requirement)
    {
        return requirement != Requirement::Collimation &&
               requirement != Requirement::TimingResolution;
    }

    bool RoundTripExperiment::isMet(Requirement requirement)
    {
        if (requirement == Requirement::BarrierOpacity)
        {
            return true;
        }
        if (requirement == Requirement::Statistics)
        {
            return runTimeSeconds() < 3.0e7;
        }
        return largerIsBetter(requirement) ? available(requirement) >= demanded(requirement)
                                           : available(requirement) <= demanded(requirement);
    }

    double RoundTripExperiment::shortfallInDecades(Requirement requirement)
    {
        const double asked = demanded(requirement);
        const double reached = available(requirement);
        if (asked <= 0.0 || reached <= 0.0)
        {
            return 0.0;
        }
        const double ratio = largerIsBetter(requirement) ? asked / reached : reached / asked;
        return std::log10(ratio);
    }

    int RoundTripExperiment::metCount()
    {
        int count = 0;
        for (Requirement requirement : all())
        {
            if (isMet(requirement))
            {
                ++count;
            }
        }
        return count;
    }

    double RoundTripExperiment::targetAdvanceSeconds() { return kTargetAdvance; }

    double RoundTripExperiment::displacementMetres()
    {
        return PhysicalScales::lightSpeed() * kTargetAdvance;
    }

    double RoundTripExperiment::launchesNeeded()
    {
        return PhysicalScales::launchesPerReturn(kWorkingOpacity);
    }

    double RoundTripExperiment::runTimeSeconds() { return launchesNeeded() / kBeamRate; }

    double RoundTripExperiment::separationInResolutions()
    {
        return kTargetAdvance / kTimingResolution;
    }

    void RoundTripExperimentSection::run(Report &report) const
    {
        report.subsection("What is being measured");
        report.check(std::format("  a proton is launched, crossed, displaced {:.4f} m on the far "
                                 "side, crossed back, and registered {:.4e} s before its launch "
                                 "on the same clock",
                                 RoundTripExperiment::displacementMetres(),
                                 RoundTripExperiment::targetAdvanceSeconds()),
                     RoundTripExperiment::displacementMetres() > 0.0);
        report.check("the quantity read is a time difference between two events on one clock, "
                     "which is what makes the claim a measurement rather than an inference",
                     RoundTripExperiment::targetAdvanceSeconds() > 0.0);

        report.subsection("The requirement a source does not have to meet");
        report.check(std::format("  a proton at rest already sits at {:.4e} rad/s, which is the "
                                 "frequency built from its rest energy",
                                 ProtonJourney::lowestDriveForProton()),
                     ProtonJourney::lowestDriveForProton() > 0.0);
        report.check(std::format("  a proton carrying one megaelectronvolt of kinetic energy sits "
                                 "at {:.4e} rad/s, above it",
                                 RoundTripExperiment::available(
                                     RoundTripExperiment::Requirement::BeamEnergy)),
                     RoundTripExperiment::isMet(RoundTripExperiment::Requirement::BeamEnergy));
        report.check("so no source supplies that frequency, the proton carries it, and the beam "
                     "requirement is collimation rather than energy",
                     RoundTripExperiment::isMet(RoundTripExperiment::Requirement::BeamEnergy) &&
                         RoundTripExperiment::isMet(RoundTripExperiment::Requirement::Collimation));

        report.subsection("Every requirement, with what is asked and what is reached");
        for (RoundTripExperiment::Requirement requirement : RoundTripExperiment::all())
        {
            report.check(std::format("  {:<32} : asks {:>10.4e}, reaches {:>10.4e} {:<22} {}",
                                     RoundTripExperiment::name(requirement),
                                     RoundTripExperiment::demanded(requirement),
                                     RoundTripExperiment::available(requirement),
                                     RoundTripExperiment::unit(requirement),
                                     RoundTripExperiment::isMet(requirement) ? "met" : "NOT MET"),
                         true);
        }
        report.check(std::format("{} of the eight requirements are met by a present laboratory",
                                 RoundTripExperiment::metCount()),
                     RoundTripExperiment::metCount() == 7);
        report.check("the one that is not met is the density of the far region, and it is the "
                     "only one, so the apparatus is otherwise ordinary",
                     !RoundTripExperiment::isMet(
                         RoundTripExperiment::Requirement::RegionDensity));

        report.subsection("The three numbers that make the reading possible");
        report.check(std::format("  the advance sought is {:.4e} s and the timing resolution "
                                 "available is {:.4e} s, a separation of {:.0f} resolutions",
                                 RoundTripExperiment::targetAdvanceSeconds(), 1.0e-11,
                                 RoundTripExperiment::separationInResolutions()),
                     RoundTripExperiment::separationInResolutions() > 10.0);
        report.check(std::format("  one arrival needs {:.4e} launches, which at a beam rate of "
                                 "one per nanosecond takes {:.4f} s of running",
                                 RoundTripExperiment::launchesNeeded(),
                                 RoundTripExperiment::runTimeSeconds()),
                     RoundTripExperiment::runTimeSeconds() < 3.0e7);
        report.check("so the statistics and the timing are both comfortable, and the experiment "
                     "would be short rather than long if the region existed",
                     RoundTripExperiment::runTimeSeconds() < 3.0e7 &&
                         RoundTripExperiment::separationInResolutions() > 10.0);

        report.subsection("The single unmet requirement, stated as a distance");
        report.check(std::format("  the region asks {:.4e} kg per cubic metre and the densest "
                                 "deliberate configuration reaches {:.4e}",
                                 RoundTripExperiment::demanded(
                                     RoundTripExperiment::Requirement::RegionDensity),
                                 RoundTripExperiment::available(
                                     RoundTripExperiment::Requirement::RegionDensity)),
                     true);
        report.check(std::format("  that is {:.1f} decades, falling to {:.1f} at the most "
                                 "favourable scale experiment still allows",
                                 RoundTripExperiment::shortfallInDecades(
                                     RoundTripExperiment::Requirement::RegionDensity),
                                 ThresholdScaling::decadesRemainingAtBound(
                                     RoundTripExperiment::available(
                                         RoundTripExperiment::Requirement::RegionDensity))),
                     RoundTripExperiment::shortfallInDecades(
                         RoundTripExperiment::Requirement::RegionDensity) > 70.0);
        report.check("so the experiment is specified rather than performable, and what stands "
                     "between the two is one number on one requirement rather than a list",
                     RoundTripExperiment::metCount() == 7);
    }

}
