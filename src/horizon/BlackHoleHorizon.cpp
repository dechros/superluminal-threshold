#include "horizon/BlackHoleHorizon.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>
#include <stdexcept>

namespace slm
{
    double BlackHoleHorizon::lapse(double r, double schwarzschildRadius)
    {
        return 1.0 - schwarzschildRadius / r;
    }

    Matrix4 BlackHoleHorizon::schwarzschildMetric(double r, double schwarzschildRadius,
                                                  double theta)
    {
        const double f = lapse(r, schwarzschildRadius);
        const double sinTheta = std::sin(theta);
        return Matrix4::diagonal(f, -1.0 / f, -r * r, -r * r * sinTheta * sinTheta);
    }

    std::array<int, 3> BlackHoleHorizon::signature(const Matrix4 &metric)
    {
        std::array<int, 3> counts{0, 0, 0};
        for (int i = 0; i < 4; ++i)
        {
            const double value = metric.at(i, i);
            if (value > kEps)
            {
                ++counts[0];
            }
            else if (value < -kEps)
            {
                ++counts[1];
            }
            else
            {
                ++counts[2];
            }
        }
        return counts;
    }

    Matrix4 BlackHoleHorizon::interpolatedMetric(double lambda)
    {
        const double value = -std::cos(lambda);
        return Matrix4::diagonal(1.0, value, value, value);
    }

    void BlackHoleHorizon::run(Report &report) const
    {
        const double schwarzschildRadius = 1.0;
        const double theta = std::numbers::pi / 2.0;

        report.subsection("13.1  Horizon: how many coordinates turn over");
        for (double r : {3.0, 2.0, 1.5, 0.9, 0.5})
        {
            const Matrix4 metric = schwarzschildMetric(r, schwarzschildRadius, theta);
            const auto counts = signature(metric);
            report.check("  the signature class STAYS (1,3)",
                         counts[0] == 1 && counts[1] == 3);
        }

        report.subsection("13.1b  Sigma: all four coordinates at once");
        const auto regionICounts = signature(metricRegionI());
        const auto regionIICounts = signature(metricRegionII());
        report.check("across Sigma the signature CLASS changes: (1,3) -> (3,1)",
                     regionICounts[0] == 1 && regionIICounts[0] == 3);

        report.subsection("13.2  At the horizon f passes through zero continuously");
        report.checkNear("f(r_s) = 0, continuous crossing", lapse(1.0, schwarzschildRadius));

        report.subsection("13.3  Can a continuous bridge be built?");
        const double pi = std::numbers::pi;
        for (double lambda : {0.0, pi / 4.0, pi / 2.0, 3.0 * pi / 4.0, pi})
        {
            const auto counts = signature(interpolatedMetric(lambda));
            report.check(std::format("lambda = {:.4f} : the signature never REACHES (3,1)", lambda),
                         !(counts[0] == 3 && counts[1] == 1));
        }
        const Matrix4 degenerate = interpolatedMetric(pi / 2.0);
        report.checkNear("at lambda = pi/2, det g = 0: DEGENERATE METRIC",
                         degenerate.determinant(), 1e-12);

        bool inverseFails = false;
        try
        {
            (void)degenerate.inverse();
        }
        catch (const std::domain_error &)
        {
            inverseFails = true;
        }
        report.check("at the degenerate point the inverse metric does not exist, the field equation is undefined",
                     inverseFails);
    }
}
