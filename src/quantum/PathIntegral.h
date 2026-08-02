#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the Wick rotation and the Euclidean propagator.
    class PathIntegral : public Section
    {
    public:
        /// Which axes a Wick rotation turns.
        enum class WickChoice
        {
            AllThreeTimes, ///< Rotate the three time axes together.
            SingleSpace,   ///< Rotate the single space axis.
            Composite      ///< A composite direction, which is not O(3) invariant.
        };

        /// Euclidean kernel produced by the given rotation.
        /// \throws std::domain_error for WickChoice::Composite.
        static double euclideanKernel(WickChoice choice, double c, double mu,
                                      double kSquared, double q);

        /// Whether the kernel stays positive over a wide range of modes, so
        /// that the Gaussian integral converges.
        static bool isPositiveDefinite(WickChoice choice, double c, double mu);

        /// Euclidean propagator, the reciprocal of the convergent kernel.
        static double euclideanPropagator(double c, double mu, double kSquared, double q);

        std::string number() const override { return "10.5"; }
        std::string title() const override
        {
            return "Path integral, Wick rotation and the shared Euclidean theory";
        }
        void run(Report &report) const override;
    };

}
