#include "field/ScalarWaveField.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{
    double ScalarWaveField::regionIGrowthCoefficient(double c, double mu, double kSquared)
    {
        return -c * c * (kSquared + mu);
    }

    double ScalarWaveField::regionIIGrowthCoefficient(double c, double mu,
                                                       double kTransverseSquared, double q)
    {
        return kTransverseSquared - q * q / (c * c) + mu;
    }

    double ScalarWaveField::regionIResidual(double c, double mu, double omega, double kSquared)
    {
        return omega * omega / (c * c) - kSquared - mu;
    }

    double ScalarWaveField::regionIIResidual(double c, double mu, double kSquared, double q)
    {
        return kSquared - q * q / (c * c) + mu;
    }

    void ScalarWaveField::run(Report &report) const
    {
        const double c = 1.0;
        const double mass = 1.0;
        const double hbar = 1.0;
        const double mu = (mass * c / hbar) * (mass * c / hbar);

        report.subsection("Do plane waves satisfy both field equations?");
        for (double kSquared : {0.0, 1.0, 9.0, 100.0})
        {
            const double omega = c * std::sqrt(kSquared + mu);
            report.checkNear(std::format("Region I : k^2 = {:g}, omega = {:.6g} -> field "
                                         "equation residual",
                                         kSquared, omega),
                             regionIResidual(c, mu, omega, kSquared));

            const double q = c * std::sqrt(kSquared + mu);
            report.checkNear(std::format("Region II: kappa^2 = {:g}, q = {:.6g} -> field "
                                         "equation residual",
                                         kSquared, q),
                             regionIIResidual(c, mu, kSquared, q));
        }

        report.subsection("Determinism: the Region I initial value problem");
        for (double kSquared : {0.0, 1.0, 1e2, 1e6, 1e12})
        {
            const double coefficient = regionIGrowthCoefficient(c, mu, kSquared);
            report.check("  coefficient NEGATIVE -> bounded mode, stable evolution",
                         coefficient < 0.0);
        }

        report.subsection("Loss of determinism: the Region II initial value problem");
        const double qFixed = 1.0;
        bool sawBlowUp = false;
        double lastRate = 0.0;
        for (double kTransverseSquared : {0.0, 1.0, 1e2, 1e6, 1e12})
        {
            const double coefficient = regionIIGrowthCoefficient(c, mu, kTransverseSquared, qFixed);
            const double rate = coefficient > 0.0 ? std::sqrt(coefficient) : 0.0;
            if (coefficient > 0.0)
            {
                sawBlowUp = true;
            }
            lastRate = rate;
        }
        report.check("Region II admits modes with a POSITIVE coefficient, exponential "
                     "growth", sawBlowUp);
        report.check("the growth rate is UNBOUNDED as k_T -> infinity", lastRate > 1e5);
    }
}
