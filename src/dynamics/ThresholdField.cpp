#include "dynamics/ThresholdField.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    ThresholdField::Diagonal ThresholdField::regionOneMetric()
    {
        return {1.0, -1.0, -1.0, -1.0};
    }

    ThresholdField::Diagonal ThresholdField::metric(double theta)
    {
        const double scale = std::cos(2.0 * theta);
        const auto base = regionOneMetric();
        return {base[0] * scale, base[1] * scale, base[2] * scale, base[3] * scale};
    }

    bool ThresholdField::isDegenerate(double theta, double tolerance)
    {
        for (double entry : metric(theta))
        {
            if (std::abs(entry) > tolerance)
            {
                return false;
            }
        }
        return true;
    }

    double ThresholdField::requiredMomentumSquared(double theta, double mu, double energySquared)
    {
        return std::cos(2.0 * theta) * (energySquared - mu);
    }

    void ThresholdFieldSection::run(Report &report) const
    {
        const double pi = 3.14159265358979323846;

        report.subsection("The two endpoints");
        const auto atZero = ThresholdField::metric(0.0);
        const auto regionOne = ThresholdField::regionOneMetric();
        for (std::size_t i = 0; i < 4; ++i)
        {
            report.checkNear(std::format("  theta = 0, slot {} matches the Region I metric", i),
                             atZero[i] - regionOne[i]);
        }
        const auto atHalfPi = ThresholdField::metric(pi / 2.0);
        for (std::size_t i = 0; i < 4; ++i)
        {
            report.checkNear(std::format("  theta = pi/2, slot {} is the Region I entry reversed", i),
                             atHalfPi[i] + regionOne[i]);
        }

        report.subsection("The single degenerate point");
        report.check("  theta = pi/4 is degenerate", ThresholdField::isDegenerate(pi / 4.0, 1e-9));
        for (double theta : {0.0, pi / 8.0, pi / 3.0, pi / 2.0})
        {
            report.check(std::format("  theta = {:.4f} is not degenerate", theta),
                         !ThresholdField::isDegenerate(theta, 1e-9));
        }

        report.subsection("A fixed mass cannot ride this family across the degenerate point");
        const double mu = 1.0;
        const double energySquared = 3.0;
        int realBelow = 0;
        int realAbove = 0;
        for (double theta : {0.0, pi / 16.0, pi / 8.0, 3.0 * pi / 16.0})
        {
            const double needed = ThresholdField::requiredMomentumSquared(theta, mu, energySquared);
            report.check(std::format("  theta = {:.4f} < pi/4 : a real momentum exists (needed = {:.6f})",
                                     theta, needed),
                         needed >= 0.0);
            if (needed >= 0.0)
            {
                ++realBelow;
            }
        }
        for (double theta : {5.0 * pi / 16.0, 3.0 * pi / 8.0, 7.0 * pi / 16.0, pi / 2.0})
        {
            const double needed = ThresholdField::requiredMomentumSquared(theta, mu, energySquared);
            report.check(std::format("  theta = {:.4f} > pi/4 : no real momentum exists (needed = {:.6f})",
                                     theta, needed),
                         needed < 0.0);
            if (needed < 0.0)
            {
                ++realAbove;
            }
        }
        report.check("  every angle below pi/4 admitted a real momentum, every angle above did not",
                     realBelow == 4 && realAbove == 4);
        report.check("  the required momentum falls to exactly zero at theta = pi/4 itself",
                     std::abs(ThresholdField::requiredMomentumSquared(pi / 4.0, mu, energySquared)) < 1e-9);
    }

}
