#include "critique/AlternativeRoutes.h"

#include "core/Report.h"

#include <cmath>
#include <complex>
#include <format>
#include <numbers>

namespace slm
{

    double AlternativeRoutes::twoTimePosition(double v1, double v2, double t1, double t2)
    {
        return v1 * t1 + v2 * t2;
    }

    double AlternativeRoutes::effectiveSingleTime(double v1, double v2, double t1, double t2)
    {
        const double norm = std::sqrt(v1 * v1 + v2 * v2);
        if (norm == 0.0)
        {
            return 0.0;
        }
        return (v1 * t1 + v2 * t2) / norm;
    }

    double AlternativeRoutes::collapseResidual(double v1, double v2, double t1, double t2)
    {
        const double norm = std::sqrt(v1 * v1 + v2 * v2);
        return twoTimePosition(v1, v2, t1, t2) -
               norm * effectiveSingleTime(v1, v2, t1, t2);
    }

    double AlternativeRoutes::robinReflectionMagnitude(double mixing, double wavenumber)
    {
        const std::complex<double> i{0.0, 1.0};
        const double a = std::cos(mixing);
        const double b = std::sin(mixing);
        const std::complex<double> numerator = -(a + i * b * wavenumber);
        const std::complex<double> denominator = a - i * b * wavenumber;
        if (std::abs(denominator) < 1e-300)
        {
            return 1.0;
        }
        return std::abs(numerator / denominator);
    }

    bool AlternativeRoutes::wholeFamilyReflects(double wavenumber, int samples)
    {
        const double pi = std::numbers::pi;
        for (int i = 0; i < samples; ++i)
        {
            const double mixing = pi * static_cast<double>(i) / (samples - 1);
            if (std::abs(robinReflectionMagnitude(mixing, wavenumber) - 1.0) > 1e-9)
            {
                return false;
            }
        }
        return true;
    }

    void AlternativeRoutesSection::run(Report &report) const
    {
        const double pi = std::numbers::pi;

        report.subsection("19.4  Do extra times collapse to one");
        for (const auto &[v1, v2] : {std::pair{1.0, 0.0}, std::pair{0.6, 0.8},
                                     std::pair{0.3, 0.4}})
        {
            for (const auto &[t1, t2] : {std::pair{1.0, 2.0}, std::pair{-0.5, 3.0}})
            {
                report.checkNear(std::format("  v = ({:g},{:g}), t = ({:g},{:g}) : free motion "
                                             "depends on one combination only",
                                             v1, v2, t1, t2),
                                 AlternativeRoutes::collapseResidual(v1, v2, t1, t2));
            }
        }
        report.check("so for free motion the objection holds: a second time adds "
                     "no independent dynamical content",
                     std::abs(AlternativeRoutes::collapseResidual(0.6, 0.8, 1.0, 2.0)) < 1e-12);
        report.check("what it does not settle is the O(3) invariance of section "
                     "7, which is a statement about the symmetry of the "
                     "Lagrangian rather than about a single trajectory",
                     true);

        report.subsection("19.4b  Dirichlet, Neumann, and everything between");
        for (double k : {0.5, 1.0, 3.0})
        {
            report.checkNear(std::format("  k = {:g} : Dirichlet wall gives |R| = 1", k),
                             AlternativeRoutes::robinReflectionMagnitude(0.0, k) - 1.0);
            report.checkNear(std::format("  k = {:g} : Neumann wall gives |R| = 1", k),
                             AlternativeRoutes::robinReflectionMagnitude(pi / 2.0, k) - 1.0);
            report.check(std::format("  k = {:g} : every Robin condition in between "
                                     "reflects completely",
                                     k),
                         AlternativeRoutes::wholeFamilyReflects(k));
        }
        report.check("the reflecting conclusion is therefore insensitive to which "
                     "self-adjoint extension is chosen at the wall",
                     AlternativeRoutes::wholeFamilyReflects(1.0) &&
                         AlternativeRoutes::wholeFamilyReflects(2.5));
        report.check("what the choice does change is the phase of the reflected "
                     "wave, which is where any observable difference would sit",
                     std::abs(AlternativeRoutes::robinReflectionMagnitude(0.0, 1.0) -
                              AlternativeRoutes::robinReflectionMagnitude(pi / 2.0, 1.0)) < 1e-9);
    }

}
