#include "physics/units/PhysicalScales.h"

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
}
