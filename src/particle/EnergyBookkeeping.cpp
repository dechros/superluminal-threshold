#include "particle/EnergyBookkeeping.h"

#include "core/Report.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{

    EnergyBookkeeping::Four EnergyBookkeeping::across(const Four &ours)
    {
        return {ours[3], ours[2], ours[1], ours[0]};
    }

    double EnergyBookkeeping::farEnergyMagnitude(const Four &far)
    {
        return std::sqrt(far[0] * far[0] + far[1] * far[1] + far[2] * far[2]);
    }

    double EnergyBookkeeping::farMomentum(const Four &far)
    {
        return far[3];
    }

    EnergyBookkeeping::Four EnergyBookkeeping::rotateFarEnergy(const Four &far, double angle)
    {
        const double cosine = std::cos(angle);
        const double sine = std::sin(angle);
        return {cosine * far[0] - sine * far[1], sine * far[0] + cosine * far[1], far[2], far[3]};
    }

    double EnergyBookkeeping::invariant(const Four &vector, bool farSide)
    {
        if (farSide)
        {
            return vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2] -
                   vector[3] * vector[3];
        }
        return vector[0] * vector[0] - vector[1] * vector[1] - vector[2] * vector[2] -
               vector[3] * vector[3];
    }

    double EnergyBookkeeping::ourMomentumMagnitude(const Four &ours)
    {
        return std::sqrt(ours[1] * ours[1] + ours[2] * ours[2] + ours[3] * ours[3]);
    }

    double EnergyBookkeeping::momentumAngle(const Four &first, const Four &second)
    {
        const double dot = first[1] * second[1] + first[2] * second[2] + first[3] * second[3];
        const double lengths = ourMomentumMagnitude(first) * ourMomentumMagnitude(second);
        if (lengths == 0.0)
        {
            return 0.0;
        }
        return std::acos(std::clamp(dot / lengths, -1.0, 1.0));
    }

    void EnergyBookkeepingSection::run(Report &report) const
    {
        using Four = EnergyBookkeeping::Four;
        const Four ours = {5.0, 1.0, 2.0, 3.0};

        report.subsection("What the three far-side energies are in our terms");
        const Four far = EnergyBookkeeping::across(ours);
        report.checkNear("the far-side energy vector is our three-momentum, reordered",
                         EnergyBookkeeping::farEnergyMagnitude(far) -
                             EnergyBookkeeping::ourMomentumMagnitude(ours),
                         1e-12);
        report.checkNear("and the far side's single momentum is our energy",
                         EnergyBookkeeping::farMomentum(far) - EnergyBookkeeping::ourEnergy(ours),
                         1e-12);
        report.checkNear("the invariant flips sign, as the metrics require",
                         EnergyBookkeeping::invariant(far, true) +
                             EnergyBookkeeping::invariant(ours, false),
                         1e-12);

        report.subsection("A plain round trip returns everything exactly");
        const Four back = EnergyBookkeeping::across(far);
        for (int slot = 0; slot < 4; ++slot)
        {
            report.checkNear(std::format("  slot {} comes back unchanged", slot),
                             back[slot] - ours[slot], 1e-15);
        }
        report.check("so the transformation itself loses nothing, and every loss "
                     "the model reports comes from the interface instead",
                     back == ours);

        report.subsection("Only the length of the far energy is physical");
        for (double angle : {0.3, 1.0, 2.5})
        {
            const Four turned = EnergyBookkeeping::rotateFarEnergy(far, angle);
            report.checkNear(std::format("  angle {:g} : the energy length is unchanged", angle),
                             EnergyBookkeeping::farEnergyMagnitude(turned) -
                                 EnergyBookkeeping::farEnergyMagnitude(far),
                             1e-12);
            report.checkNear(std::format("  angle {:g} : the far momentum is untouched", angle),
                             EnergyBookkeeping::farMomentum(turned) -
                                 EnergyBookkeeping::farMomentum(far),
                             1e-15);
            report.checkNear(std::format("  angle {:g} : the invariant is untouched", angle),
                             EnergyBookkeeping::invariant(turned, true) -
                                 EnergyBookkeeping::invariant(far, true),
                             1e-12);
        }

        report.subsection("What that rotation costs once the particle is back");
        for (double angle : {0.3, 1.0, 2.5})
        {
            const Four turned = EnergyBookkeeping::rotateFarEnergy(far, angle);
            const Four returned = EnergyBookkeeping::across(turned);
            report.checkNear(std::format("  angle {:g} : our energy comes back the same", angle),
                             EnergyBookkeeping::ourEnergy(returned) -
                                 EnergyBookkeeping::ourEnergy(ours),
                             1e-12);
            report.checkNear(std::format("  angle {:g} : the length of our momentum is the same",
                                         angle),
                             EnergyBookkeeping::ourMomentumMagnitude(returned) -
                                 EnergyBookkeeping::ourMomentumMagnitude(ours),
                             1e-12);
            report.check(std::format("  angle {:g} : but its direction has turned by {:.4f} radians",
                                     angle, EnergyBookkeeping::momentumAngle(ours, returned)),
                         EnergyBookkeeping::momentumAngle(ours, returned) > 1e-6);
        }

        report.subsection("The mass shell survives the whole journey");
        for (double angle : {0.0, 0.3, 1.0, 2.5})
        {
            const Four returned =
                EnergyBookkeeping::across(EnergyBookkeeping::rotateFarEnergy(far, angle));
            report.checkNear(std::format("  angle {:g} : the mass is unchanged", angle),
                             EnergyBookkeeping::invariant(returned, false) -
                                 EnergyBookkeeping::invariant(ours, false),
                             1e-12);
        }

        report.subsection("The one thing a round trip can do for free");
        const Four turned = EnergyBookkeeping::rotateFarEnergy(far, 1.0);
        const Four returned = EnergyBookkeeping::across(turned);
        report.check("energy conserved, speed conserved, mass conserved, direction changed",
                     std::abs(EnergyBookkeeping::ourEnergy(returned) -
                              EnergyBookkeeping::ourEnergy(ours)) < 1e-12 &&
                         std::abs(EnergyBookkeeping::ourMomentumMagnitude(returned) -
                                  EnergyBookkeeping::ourMomentumMagnitude(ours)) < 1e-12 &&
                         EnergyBookkeeping::momentumAngle(ours, returned) > 1e-6);
        report.check("a rotation that is pure gauge over there is an observable "
                     "deflection over here",
                     EnergyBookkeeping::momentumAngle(ours, returned) > 0.1);
    }

}
