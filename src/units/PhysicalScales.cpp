#include "units/PhysicalScales.h"

#include "core/Report.h"

#include <cmath>
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

    double PhysicalScales::distanceForAdvance(double seconds)
    {
        return kLightSpeed * seconds;
    }

    double PhysicalScales::advanceForDistance(double metres)
    {
        return metres / kLightSpeed;
    }

    void PhysicalScalesSection::run(Report &report) const
    {
        report.subsection("The constants the laboratory conversions rest on");
        report.check(std::format("  the electron rest mass is {:.6e} kg and the proton rest mass "
                                 "is {:.6e} kg",
                                 PhysicalScales::electronMass(), PhysicalScales::protonMass()),
                     PhysicalScales::protonMass() > PhysicalScales::electronMass());
        report.check(std::format("  the hydrogen atom's rest mass is {:.6e} kg, the proton and "
                                 "the electron less the mass their binding energy carries",
                                 PhysicalScales::hydrogenAtomMass()),
                     PhysicalScales::hydrogenAtomMass() <
                         PhysicalScales::protonMass() + PhysicalScales::electronMass());

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
    }

}
