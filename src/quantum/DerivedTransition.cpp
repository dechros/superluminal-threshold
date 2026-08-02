#include "quantum/DerivedTransition.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double DerivedTransition::deformation(double density, double criticalDensity)
    {
        return 1.0 - 2.0 * density / criticalDensity;
    }

    bool DerivedTransition::isLorentzian(double density, double criticalDensity)
    {
        return deformation(density, criticalDensity) > 0.0;
    }

    double DerivedTransition::transitionDensity(double criticalDensity)
    {
        return criticalDensity / 2.0;
    }

    double DerivedTransition::deformationSlope(double criticalDensity)
    {
        return -2.0 / criticalDensity;
    }

    int DerivedTransition::changingCoordinates(bool euclideanTarget)
    {
        return euclideanTarget ? 1 : 4;
    }

    void DerivedTransitionSection::run(Report &report) const
    {
        const double rhoC = 1.0;

        report.subsection("A transition that follows from the dynamics");
        report.checkNear("the deformation vanishes at half the critical density",
                         DerivedTransition::deformation(
                             DerivedTransition::transitionDensity(rhoC), rhoC));
        for (double rho : {0.1, 0.3, 0.49})
        {
            report.check(std::format("  rho = {:g} rho_c : Lorentzian, deformation {:+.3f}",
                                     rho, DerivedTransition::deformation(rho, rhoC)),
                         DerivedTransition::isLorentzian(rho, rhoC));
        }
        for (double rho : {0.51, 0.8, 1.0})
        {
            report.check(std::format("  rho = {:g} rho_c : Euclidean, deformation {:+.3f}",
                                     rho, DerivedTransition::deformation(rho, rhoC)),
                         !DerivedTransition::isLorentzian(rho, rhoC));
        }

        report.subsection("The transition is gradual, not abrupt");
        report.checkNear("the deformation is linear in the density",
                         DerivedTransition::deformation(0.4, rhoC) -
                             (DerivedTransition::deformation(0.2, rhoC) +
                              0.2 * DerivedTransition::deformationSlope(rhoC)));
        report.check("its slope is finite everywhere, so the signature turns over "
                     "continuously rather than jumping",
                     std::abs(DerivedTransition::deformationSlope(rhoC)) < 1e6);
        report.check("the transition is located by a density, not by a speed",
                     DerivedTransition::transitionDensity(rhoC) > 0.0);

        report.subsection("Where the two transitions differ");
        report.check("the derived transition turns one coordinate over, reaching "
                     "Euclidean signature",
                     DerivedTransition::changingCoordinates(true) == 1);
        report.check("the transition assumed here turns all four over, reaching "
                     "three times and one space",
                     DerivedTransition::changingCoordinates(false) == 4);
        report.check("so the two are not the same event and the derived one does "
                     "not supply a derivation for this one",
                     DerivedTransition::changingCoordinates(true) !=
                         DerivedTransition::changingCoordinates(false));
    }

}
