#include "boundary/ModeFilter.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double ModeFilter::growthCoefficient(double c, double mu, double k2, double k3, double q)
    {
        return k2 * k2 + k3 * k3 + mu - (q * q) / (c * c);
    }

    bool ModeFilter::isGrowing(double c, double mu, double k2, double k3, double q)
    {
        return growthCoefficient(c, mu, k2, k3, q) > 0.0;
    }

    double ModeFilter::onShellNormalSquared(double c, double mu, double k1, double k2, double k3)
    {
        return c * c * (k1 * k1 + k2 * k2 + k3 * k3 + mu);
    }

    double ModeFilter::dispersionResidual(double c, double mu, double k1, double k2, double k3,
                                          double q)
    {
        return k1 * k1 + k2 * k2 + k3 * k3 - (q * q) / (c * c) + mu;
    }

    double ModeFilter::onShellGrowthCoefficient(double c, double mu, double k1, double k2,
                                                double k3)
    {
        const double q = std::sqrt(onShellNormalSquared(c, mu, k1, k2, k3));
        return growthCoefficient(c, mu, k2, k3, q);
    }

    void ModeFilterSection::run(Report &report) const
    {
        const double c = 1.0;
        const double mu = 1.0;

        report.subsection("Growing modes exist when the wavenumbers are free");
        report.check("a mode with little normal wavenumber grows, which is the "
                     "ill-posedness of the free initial value problem",
                     ModeFilter::isGrowing(c, mu, 2.0, 2.0, 0.5));
        report.check("a mode with large normal wavenumber does not grow",
                     !ModeFilter::isGrowing(c, mu, 2.0, 2.0, 8.0));
        report.check("the growth coefficient is unbounded above as the time "
                     "wavenumbers increase",
                     ModeFilter::growthCoefficient(c, mu, 50.0, 50.0, 0.5) >
                         ModeFilter::growthCoefficient(c, mu, 5.0, 5.0, 0.5));

        report.subsection("A mode arriving by crossing is on the far-side shell");
        for (double k1 : {0.0, 0.5, 2.0})
        {
            for (double k2 : {0.0, 1.5, 4.0})
            {
                const double q = std::sqrt(ModeFilter::onShellNormalSquared(c, mu, k1, k2, 0.7));
                report.checkNear(std::format("  k1 = {:g}, k2 = {:g} : the transmitted mode "
                                             "solves the far-side equation",
                                             k1, k2),
                                 ModeFilter::dispersionResidual(c, mu, k1, k2, 0.7, q));
            }
        }

        report.subsection("On the shell the growth coefficient collapses to -k1^2");
        for (double k1 : {0.0, 0.3, 1.0, 3.0, 7.0})
        {
            for (double k2 : {0.0, 2.0, 6.0})
            {
                const double coefficient = ModeFilter::onShellGrowthCoefficient(c, mu, k1, k2, 1.1);
                report.checkNear(std::format("  k1 = {:g}, k2 = {:g} : coefficient equals -k1^2",
                                             k1, k2),
                                 coefficient + k1 * k1, 1e-10);
            }
        }

        report.subsection("Therefore no mode reachable by crossing grows");
        const double tolerance = 1e-9;
        int scanned = 0;
        int growing = 0;
        int marginal = 0;
        for (int i1 = 0; i1 <= 12; ++i1)
        {
            for (int i2 = 0; i2 <= 12; ++i2)
            {
                for (int i3 = 0; i3 <= 12; ++i3)
                {
                    const double k1 = 0.5 * i1;
                    const double k2 = 0.5 * i2;
                    const double k3 = 0.5 * i3;
                    const double coefficient = ModeFilter::onShellGrowthCoefficient(c, mu, k1, k2,
                                                                                    k3);
                    ++scanned;
                    if (coefficient > tolerance)
                    {
                        ++growing;
                    }
                    else if (coefficient > -tolerance)
                    {
                        ++marginal;
                    }
                }
            }
        }
        report.check(std::format("  scanned {} on-shell modes, {} of them grow", scanned, growing),
                     growing == 0);
        report.check(std::format("  {} of them are marginal, and every one has k1 = 0", marginal),
                     marginal == 13 * 13);
        report.check("growth needs k1^2 < 0, that is data off the far-side shell",
                     ModeFilter::onShellGrowthCoefficient(c, mu, 0.0, 3.0, 3.0) <= 0.0);

        report.subsection("The one marginal case");
        report.checkNear("k1 = 0 sits exactly on the boundary, neither growing nor decaying",
                         ModeFilter::onShellGrowthCoefficient(c, mu, 0.0, 2.0, 2.0));
        report.check("and it is marginal rather than growing, so prediction "
                     "survives on the modes the threshold can inject",
                     !ModeFilter::isGrowing(
                         c, mu, 2.0, 2.0,
                         std::sqrt(ModeFilter::onShellNormalSquared(c, mu, 0.0, 2.0, 2.0))));
    }

}
