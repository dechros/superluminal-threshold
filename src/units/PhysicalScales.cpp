#include "units/PhysicalScales.h"

#include "core/Report.h"

#include <cmath>
#include <limits>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kLightSpeed = 2.99792458e8;
        constexpr double kReducedPlanck = 1.054571817e-34;
        constexpr double kElementaryCharge = 1.602176634e-19;
        constexpr double kElectronMass = 9.1093837015e-31;
        constexpr double kProtonMass = 1.67262192369e-27;
        constexpr double kSecondsPerYear = 3.155695e7;
        constexpr double kHydrogenBindingEnergyEv = 13.598434;
    }

    double PhysicalScales::lightSpeed() { return kLightSpeed; }
    double PhysicalScales::reducedPlanck() { return kReducedPlanck; }
    double PhysicalScales::elementaryCharge() { return kElementaryCharge; }
    double PhysicalScales::electronMass() { return kElectronMass; }
    double PhysicalScales::protonMass() { return kProtonMass; }

    double PhysicalScales::hydrogenBindingEnergyJoules()
    {
        return kHydrogenBindingEnergyEv * kElementaryCharge;
    }

    double PhysicalScales::hydrogenAtomMass()
    {
        return kProtonMass + kElectronMass - hydrogenBindingEnergyJoules() / (kLightSpeed * kLightSpeed);
    }

    double PhysicalScales::driveQuantum(double angularFrequency)
    {
        return kReducedPlanck * angularFrequency;
    }

    double PhysicalScales::heaviestMass(double angularFrequency)
    {
        return driveQuantum(angularFrequency) / (kLightSpeed * kLightSpeed);
    }

    double PhysicalScales::frequencyNeededFor(double massInKilograms)
    {
        return massInKilograms * kLightSpeed * kLightSpeed / kReducedPlanck;
    }

    double PhysicalScales::restEnergyInElectronvolts(double massInKilograms)
    {
        return massInKilograms * kLightSpeed * kLightSpeed / kElementaryCharge;
    }

    bool PhysicalScales::driveCanCarry(double angularFrequency, double massInKilograms)
    {
        return massInKilograms < heaviestMass(angularFrequency);
    }

    double PhysicalScales::distanceForAdvance(double seconds)
    {
        return kLightSpeed * seconds;
    }

    double PhysicalScales::advanceForDistance(double metres)
    {
        return metres / kLightSpeed;
    }

    double PhysicalScales::returnedWeight(double opacity)
    {
        return std::exp(-2.0 * opacity);
    }

    double PhysicalScales::largestOpacityForFloor(double floor)
    {
        if (floor <= 0.0 || floor >= 1.0)
        {
            return 0.0;
        }
        return -0.5 * std::log(floor);
    }

    bool PhysicalScales::returnsVisibly(double opacity, double floor)
    {
        return returnedWeight(opacity) > floor;
    }

    double PhysicalScales::launchesPerReturn(double opacity)
    {
        const double weight = returnedWeight(opacity);
        return weight > 0.0 ? 1.0 / weight : std::numeric_limits<double>::infinity();
    }

    void PhysicalScalesSection::run(Report &report) const
    {
        report.subsection("The heaviest state a drive can send, by drive");
        struct Drive
        {
            const char *label;
            double angularFrequency;
        };
        const Drive drives[] = {{"visible laser        ", 3.0e15},
                                {"hard X-ray source    ", 1.5e19},
                                {"gamma ray at 511 keV ", 7.764e20},
                                {"gamma ray at 938 MeV ", 1.4255e24}};
        for (const Drive &drive : drives)
        {
            const double mass = PhysicalScales::heaviestMass(drive.angularFrequency);
            report.check(std::format("  {} : quantum {:.4e} J, heaviest mass {:.4e} kg, that is "
                                     "{:.4e} eV over c squared",
                                     drive.label, PhysicalScales::driveQuantum(
                                                      drive.angularFrequency),
                                     mass, PhysicalScales::restEnergyInElectronvolts(mass)),
                         mass > 0.0);
        }
        report.check(std::format("an electron needs {:.4e} radians per second and a proton needs "
                                 "{:.4e}, so the wall is the rest energy and nothing else",
                                 PhysicalScales::frequencyNeededFor(
                                     PhysicalScales::electronMass()),
                                 PhysicalScales::frequencyNeededFor(
                                     PhysicalScales::protonMass())),
                     PhysicalScales::frequencyNeededFor(PhysicalScales::protonMass()) >
                         PhysicalScales::frequencyNeededFor(PhysicalScales::electronMass()));
        report.check("a visible laser cannot carry an electron, and a hard X-ray source cannot "
                     "either, so the drives that exist fall short of the lightest charged state "
                     "by orders of magnitude rather than by a factor",
                     !PhysicalScales::driveCanCarry(3.0e15, PhysicalScales::electronMass()) &&
                         !PhysicalScales::driveCanCarry(1.5e19, PhysicalScales::electronMass()));
        report.check("and a drive able to carry a proton has to supply a quantum of the proton "
                     "rest energy, which is the whole of the admission price stated in one number",
                     PhysicalScales::driveCanCarry(1.5e24, PhysicalScales::protonMass()) &&
                         !PhysicalScales::driveCanCarry(1.4e24, PhysicalScales::protonMass()));

        report.subsection("What a second of recovered time costs in metres");
        for (double seconds : {1e-9, 1e-3, 1.0, 60.0, kSecondsPerYear})
        {
            report.check(std::format("  {:>12.4e} s of advance costs {:>12.4e} m of far-side "
                                     "travel",
                                     seconds, PhysicalScales::distanceForAdvance(seconds)),
                         PhysicalScales::distanceForAdvance(seconds) > 0.0);
        }
        report.check(std::format("one metre of far-side travel buys {:.4e} s, so the exchange rate "
                                 "is the speed of light and the bill is the light travel distance "
                                 "of the time recovered",
                                 PhysicalScales::advanceForDistance(1.0)),
                     std::abs(PhysicalScales::advanceForDistance(
                                  PhysicalScales::distanceForAdvance(1.0)) -
                              1.0) < 1e-12);
        report.check("a year of advance therefore costs a light year of travel over there, which "
                     "is the statement that makes the scale of the proposal plain",
                     std::abs(PhysicalScales::distanceForAdvance(kSecondsPerYear) - 9.4605e15) <
                         1e13);

        report.subsection("What weakens about the state that comes back");
        report.check("the transmission is a probability, so the number reported for the return is "
                     "the chance of the state arriving and not a fraction of the state",
                     PhysicalScales::returnedWeight(0.0) == 1.0);
        report.check("a state that does arrive carries the mass it left with and the charge it "
                     "left with, since the crossing scales mode amplitudes and moves no mode "
                     "label, so nothing about it is diminished",
                     true);
        for (double opacity : {5.0, 20.0, 40.0})
        {
            report.check(std::format("  opacity {:>5.1f} : the return has probability {:.4e}, so "
                                     "{:.4e} launches are needed for one arrival",
                                     opacity, PhysicalScales::returnedWeight(opacity),
                                     PhysicalScales::launchesPerReturn(opacity)),
                         PhysicalScales::returnedWeight(opacity) > 0.0);
        }
        report.check(std::format("holding the return above one part in a billion caps the opacity "
                                 "at {:.4f}, and the saturated delay needs that product to be "
                                 "large, so the two requirements pull against each other",
                                 PhysicalScales::largestOpacityForFloor(1e-9)),
                     PhysicalScales::largestOpacityForFloor(1e-9) > 0.0 &&
                         PhysicalScales::largestOpacityForFloor(1e-9) < 15.0);
        report.check("that tension is the real obstacle rather than the mass wall: a thin enough "
                     "barrier to be seen through is not opaque enough for the delay to have "
                     "saturated, and the delay is what the journey is bought with",
                     PhysicalScales::returnsVisibly(10.0, 1e-9) &&
                         !PhysicalScales::returnsVisibly(20.0, 1e-9));
    }

}
