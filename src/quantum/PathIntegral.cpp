#include "quantum/PathIntegral.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <stdexcept>

namespace slm
{
    double PathIntegral::euclideanKernel(WickChoice choice, double c, double mu,
                                         double kSquared, double q)
    {
        switch (choice)
        {
        case WickChoice::AllThreeTimes:
            return mu - kSquared - q * q / (c * c);
        case WickChoice::SingleSpace:
            return kSquared + q * q / (c * c) + mu;
        case WickChoice::Composite:
            throw std::domain_error(
                "Wick choice (c): a composite direction is not O(3) invariant, undefined");
        }
        throw std::domain_error("unknown Wick choice");
    }

    bool PathIntegral::isPositiveDefinite(WickChoice choice, double c, double mu)
    {
        if (choice == WickChoice::Composite)
        {
            return false;
        }
        for (double kSquared : {0.0, 0.5, 2.0, 50.0, 1e4, 1e8})
        {
            for (double q : {0.0, 0.5, 3.0, 100.0, 1e4})
            {
                if (euclideanKernel(choice, c, mu, kSquared, q) <= 0.0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    double PathIntegral::euclideanPropagator(double c, double mu, double kSquared, double q)
    {
        return 1.0 / euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, q);
    }

    void PathIntegral::run(Report &report) const
    {
        const double c = 1.0;
        const double mass = 1.0;
        const double hbar = 1.0;
        const double mu = (mass * c / hbar) * (mass * c / hbar);

        report.subsection("Wick rotation: three options tested");
        double previousKernel = mu + 1.0;
        for (double kSquared : {0.0, 1.0, 100.0})
        {
            const double kernel = euclideanKernel(WickChoice::AllThreeTimes, c, mu, kSquared, 1.0);
            report.check(std::format("  (a) k^2 = {:g} : kernel decreasing", kSquared),
                         kernel < previousKernel);
            previousKernel = kernel;
        }
        report.check("(a) NOT positive definite, the Gaussian integral DIVERGES",
                     !isPositiveDefinite(WickChoice::AllThreeTimes, c, mu));

        for (double kSquared : {0.0, 1.0, 100.0})
        {
            report.check(std::format("  (b) k^2 = {:g} : kernel positive", kSquared),
                         euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, 1.0) > 0.0);
        }
        report.check("(b) POSITIVE DEFINITE, the Gaussian integral CONVERGES",
                     isPositiveDefinite(WickChoice::SingleSpace, c, mu));

        bool compositeUndefined = false;
        try
        {
            (void)euclideanKernel(WickChoice::Composite, c, mu, 1.0, 1.0);
        }
        catch (const std::domain_error &)
        {
            compositeUndefined = true;
        }
        report.check("(c) UNDEFINED", compositeUndefined);

        report.subsection("Euclidean propagator: no singularity");
        double smallestDenominator = 1e300;
        for (double kSquared : {0.0, 1.0, 25.0, 1e4})
        {
            for (double q : {0.0, 2.0, 50.0})
            {
                const double denominator = euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, q);
                smallestDenominator = std::min(smallestDenominator, denominator);
            }
        }
        report.check("the denominator is always >= mu > 0, so there is NO "
                     "POLE", smallestDenominator >= mu - 1e-12);

        report.subsection("The m = 0 case");
        const double masslessKernelAtZero = euclideanKernel(WickChoice::SingleSpace, c, 0.0, 0.0, 0.0);
        const double masslessKernelNearby = euclideanKernel(WickChoice::SingleSpace, c, 0.0, 1e-6, 0.0);
        report.check("the denominator vanishes only at k = q = 0",
                     masslessKernelAtZero == 0.0 && masslessKernelNearby > 0.0);

        report.subsection("Main finding: one shared Euclidean theory");
        for (double kSquared : {0.5, 7.0, 120.0})
        {
            const double regionI = kSquared + 1.0 + mu;
            const double regionII = euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, c);
            report.checkNear(std::format("  k^2 = {:g}: both regions share the same Euclidean "
                                         "kernel", kSquared),
                             regionI - regionII);
        }
    }
}
