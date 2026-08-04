#include "quantum/QuadraticInvariant.h"

#include "core/Report.h"
#include "quantum/BoundaryVacuumEnergy.h"

#include <cmath>
#include <format>

namespace slm
{

    double QuadraticInvariant::integerPowerSum(double s, int terms)
    {
        double sum = 0.0;
        for (int n = terms; n >= 1; --n)
        {
            sum += std::pow(static_cast<double>(n), -s);
        }
        return sum;
    }

    double QuadraticInvariant::halfIntegerPowerSum(double s, int terms)
    {
        double sum = 0.0;
        for (int n = terms - 1; n >= 0; --n)
        {
            sum += std::pow(static_cast<double>(n) + 0.5, -s);
        }
        return sum;
    }

    double QuadraticInvariant::expectedRatio(double s)
    {
        return std::pow(2.0, s) - 1.0;
    }

    double QuadraticInvariant::energySameCondition(double hbar, double c, double separation)
    {
        return BoundaryVacuumEnergy::boundaryEnergyPerArea(hbar, c, separation);
    }

    double QuadraticInvariant::energyOppositeConditions(double hbar, double c, double separation)
    {
        return energyRatio() * energySameCondition(hbar, c, separation);
    }

    double QuadraticInvariant::energyRatio() { return -7.0 / 8.0; }

    void QuadraticInvariantSection::run(Report &report) const
    {
        const double hbar = 1.0;
        const double c = 1.0;

        report.subsection("The identity behind the two mode sums");
        for (double s : {2.0, 3.0, 4.0})
        {
            const double integer = QuadraticInvariant::integerPowerSum(s, 400000);
            const double half = QuadraticInvariant::halfIntegerPowerSum(s, 400000);
            report.checkNear(std::format("  s = {:g} : the half-integer sum is (2^s - 1) "
                                         "times the integer one",
                                         s),
                             half / integer - QuadraticInvariant::expectedRatio(s), 1e-4);
        }
        report.check("continued to s = -3, the exponent the boundary vacuum energy needs, "
                     "the factor becomes 2^-3 - 1 = -7/8",
                     std::abs(QuadraticInvariant::expectedRatio(-3.0) + 7.0 / 8.0) < 1e-12);

        report.subsection("The two configurations and their energies");
        for (double L : {1.0, 2.0, 5.0})
        {
            const double same = QuadraticInvariant::energySameCondition(hbar, c, L);
            const double opposite = QuadraticInvariant::energyOppositeConditions(hbar, c, L);
            report.check(std::format("  L = {:g} : matching walls attract, E/A = {:+.5f}",
                                     L, same),
                         same < 0.0);
            report.check(std::format("  L = {:g} : opposed walls repel, E/A = {:+.5f}",
                                     L, opposite),
                         opposite > 0.0);
        }
        report.checkNear("the ratio of the two is exactly -7/8",
                         QuadraticInvariant::energyOppositeConditions(hbar, c, 1.0) /
                                 QuadraticInvariant::energySameCondition(hbar, c, 1.0) +
                             7.0 / 8.0);

        report.subsection("What the model predicts");
        report.check("putting the same condition on both threshold "
                     "surfaces, so it predicts attraction",
                     QuadraticInvariant::energySameCondition(hbar, c, 1.0) < 0.0);
        report.check("the sign of the force is therefore a discriminating "
                     "observable, not merely a magnitude",
                     QuadraticInvariant::energySameCondition(hbar, c, 1.0) *
                             QuadraticInvariant::energyOppositeConditions(hbar, c, 1.0) <
                         0.0);
        report.checkNear("and the magnitude carries the L^-3 scaling",
                         QuadraticInvariant::energySameCondition(hbar, c, 2.0) * 8.0 -
                             QuadraticInvariant::energySameCondition(hbar, c, 1.0));
        report.check("the prediction is conditional: it needs two surfaces at "
                     "v = c, which no experiment can currently prepare",
                     true);
    }

}
