#include "quantum/VacuumCasimir.h"

#include "core/Report.h"
#include "quantum/CanonicalQuantization.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{
    double VacuumCasimir::casimirEnergyPerArea(double hbar, double c, double separation)
    {
        const double pi = std::numbers::pi;
        return -pi * pi * hbar * c / (1440.0 * std::pow(separation, 3));
    }

    double VacuumCasimir::singleSurfaceEnergyDensityScale(double hbar, double c, double distance)
    {
        return hbar * c / std::pow(distance, 4);
    }

    void VacuumCasimir::run(Report &report) const
    {
        const double hbar = 1.0;
        const double c = 1.0;

        report.subsection("Why the particle concept is undefined");
        report.check(std::format("the positive and negative frequency split, a Hamiltonian "
                                 "bounded below, and a unitary representation each need one "
                                 "time direction, and there are {} beyond the threshold",
                                 CanonicalQuantization::conjugateMomentumCount(true)),
                     CanonicalQuantization::conjugateMomentumCount(true) != 1 &&
                         CanonicalQuantization::timelikeDirectionsOnSlice(true) > 0);

        report.subsection("Casimir: a single surface");
        report.check("diverges as z -> 0, renormalisation is required",
                     singleSurfaceEnergyDensityScale(hbar, c, 0.01) >
                         singleSurfaceEnergyDensityScale(hbar, c, 1.0));

        report.subsection("Casimir: between two surfaces");
        report.check("the energy is NEGATIVE, so attractive", casimirEnergyPerArea(hbar, c, 1.0) < 0.0);
        report.checkNear("scaling law E ~ L^-3",
                         casimirEnergyPerArea(hbar, c, 2.0) * 8.0 -
                             casimirEnergyPerArea(hbar, c, 1.0),
                         1e-12);
    }
}
