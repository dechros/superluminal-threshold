#pragma once

#include "core/Section.h"

#include <array>

namespace slm
{

    /// The one-parameter family of diagonal metrics carrying the Region I
    /// metric to its Region II counterpart, and why a fixed mass cannot ride
    /// along it on its own.
    ///
    /// Each Region I diagonal entry is scaled by the same factor cos(2 theta).
    /// At theta = 0 the family is the Region I metric; at theta = pi/2 it is
    /// its negative, the same signature with the sign pattern reversed; at
    /// theta = pi/4 every entry vanishes at once, a single degenerate point
    /// rather than the two-step path a signature change can also take. A
    /// particle whose own mass parameter is held fixed while only the metric
    /// is driven through that point has no real conjugate momentum on the far
    /// side of it: the family alone does not move anything across. What
    /// crosses it is a separate question, answered elsewhere by an applied
    /// force rather than by this family's geometry.
    class ThresholdField
    {
    public:
        using Diagonal = std::array<double, 4>;

        /// The fixed Region I diagonal metric, the theta = 0 endpoint.
        static Diagonal regionOneMetric();

        /// The diagonal metric at the given crossing angle.
        static Diagonal metric(double theta);

        /// Whether every entry of metric(theta) is within tolerance of zero.
        static bool isDegenerate(double theta, double tolerance);

        /// The squared conjugate momentum a fixed-mass, fixed-energy particle
        /// would need at the given angle to sit on the metric-scaled shell
        /// cos(2 theta) * (energySquared - mu) - p^2 = 0. Negative where no
        /// real momentum exists.
        static double requiredMomentumSquared(double theta, double mu, double energySquared);
    };

    /// Section verifying the metric family's endpoints, its single degenerate
    /// point, and the naive fixed-mass attempt's failure to cross it.
    class ThresholdFieldSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A family of metrics carrying one signature to the other, and why mass alone does not cross it";
        }
        void run(Report &report) const override;
    };

}
