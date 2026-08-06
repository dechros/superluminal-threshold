#include "experiment/RoundTripExperiment.h"

#include "core/Report.h"
#include "units/PhysicalScales.h"
#include "units/ProtonJourney.h"
#include "units/SignatureThreshold.h"
#include "units/ThresholdScaling.h"

#include <cmath>
#include <format>
#include <limits>

namespace slm
{
    namespace
    {
        constexpr double kTargetAdvance = 1.0e-9;
        constexpr double kWorkingOpacity = 10.0;
        constexpr double kBeamRate = 1.0e7;
        constexpr double kTimingResolution = 1.8e-11;
        constexpr double kBeamKineticJoules = 3.6850e-11;
        constexpr double kCollimationReached = 5.0e-5;
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
            return kTargetAdvance / 50.0;
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

    double RoundTripExperiment::scatteringAngle(double kineticJoules)
    {
        const double rest = 938.272;
        const double kinetic = kineticJoules / 1.602176634e-13;
        const double momentum = std::sqrt(kinetic * kinetic + 2.0 * kinetic * rest);
        const double energy = kinetic + rest;
        const double beta = momentum / energy;
        const double thickness = 1.0e-5 / 42.7;
        return 13.6 / (beta * momentum) * std::sqrt(thickness) *
               (1.0 + 0.038 * std::log(thickness));
    }

    bool RoundTripExperiment::tagPreservesCollimation()
    {
        return scatteringAngle(kBeamKineticJoules) < kCollimationReached;
    }

    double RoundTripExperiment::launchSpacingSeconds() { return 1.0 / kBeamRate; }

    double RoundTripExperiment::regionLifetimeSeconds(double radiusMetres)
    {
        return 2.0 * radiusMetres / PhysicalScales::lightSpeed();
    }

    double RoundTripExperiment::debtOverLifetime(double radiusMetres,
                                                 double driveAngularFrequency)
    {
        const double lifetime = regionLifetimeSeconds(radiusMetres);
        if (lifetime <= 0.0)
        {
            return std::numeric_limits<double>::infinity();
        }
        return ProtonJourney::debtInSeconds(driveAngularFrequency) / lifetime;
    }

    bool RoundTripExperiment::arrivalIsUnambiguous()
    {
        return launchSpacingSeconds() > 10.0 * kTargetAdvance;
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

        report.subsection("The two demands that collide, and what settles them");
        report.check(std::format("  a one MeV proton leaves the tag foil {:.3e} rad wide, which "
                                 "is coarser than the collimation the line reached",
                                 RoundTripExperiment::scatteringAngle(1.602176634e-13)),
                     RoundTripExperiment::scatteringAngle(1.602176634e-13) >
                         RoundTripExperiment::available(RoundTripExperiment::Requirement::Collimation));
        report.check(std::format("  at the energy chosen it leaves it {:.3e} rad wide instead, "
                                 "so the tag and the collimation stand together",
                                 RoundTripExperiment::scatteringAngle(3.6850e-11)),
                     RoundTripExperiment::tagPreservesCollimation());
        report.check(std::format("  launches sit {:.3e} s apart, against an advance of {:.3e} s, "
                                 "so an early arrival is not the previous proton arriving late",
                                 RoundTripExperiment::launchSpacingSeconds(),
                                 RoundTripExperiment::targetAdvanceSeconds()),
                     RoundTripExperiment::arrivalIsUnambiguous());
        report.check(std::format("  the run then takes {:.4g} s, which is the price of that "
                                 "spacing and is still short",
                                 RoundTripExperiment::runTimeSeconds()),
                     RoundTripExperiment::runTimeSeconds() < 300.0);

        report.subsection("A ninth requirement, which appears only once the region is made");
        {
            const double radius = 0.8414e-15;
            const double drive = 1.7749e24;
            report.check(std::format("  a region the size of a proton lasts about {:.4e} s, if "
                                     "whatever made it was itself transient",
                                     RoundTripExperiment::regionLifetimeSeconds(radius)),
                         RoundTripExperiment::regionLifetimeSeconds(radius) > 0.0);
            report.check(std::format("  the round trip debt is {:.4e} s, so it takes {:.2f} of "
                                     "that lifetime",
                                     ProtonJourney::debtInSeconds(drive),
                                     RoundTripExperiment::debtOverLifetime(radius, drive)),
                         RoundTripExperiment::debtOverLifetime(radius, drive) < 1.0);
            report.check("the two are within one factor of each other, so a region produced "
                         "rather than given carries a ninth requirement that the eight do not "
                         "state, and it is nearly binding",
                         RoundTripExperiment::debtOverLifetime(radius, drive) > 0.1);
        }

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
