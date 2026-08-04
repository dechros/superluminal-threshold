#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the imaginary rotation and the Euclidean propagator.
    class PathIntegral : public Section
    {
    public:
        /// Which axes a imaginary rotation turns.
        enum class ImaginaryRotationChoice
        {
            AllThreeTimes, ///< Rotate the three time axes together.
            SingleSpace,   ///< Rotate the single space axis.
            Composite      ///< A composite direction, which is not O(3) invariant.
        };

        /// Euclidean kernel produced by the given rotation.
        /// \throws std::domain_error for ImaginaryRotationChoice::Composite.
        static double euclideanKernel(ImaginaryRotationChoice choice, double c, double mu,
                                      double kSquared, double q);

        /// Whether the kernel stays positive over a wide range of modes, so
        /// that the Gaussian integral converges.
        static bool isPositiveDefinite(ImaginaryRotationChoice choice, double c, double mu);

        /// Euclidean propagator, the reciprocal of the convergent kernel.
        static double euclideanPropagator(double c, double mu, double kSquared, double q);

        std::string title() const override
        {
            return "Path integral, imaginary rotation and the shared Euclidean theory";
        }
        void run(Report &report) const override;
    };

}
