#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <array>

namespace slm
{

    /// Section comparing the coordinate turnover at a Schwarzschild horizon
    /// with the signature change across Sigma.
    class BlackHoleHorizon : public Section
    {
    public:
        /// Schwarzschild lapse f(r) = 1 - r_s / r.
        static double lapse(double r, double schwarzschildRadius);

        /// Diagonal Schwarzschild metric at the given radius and polar angle.
        static Matrix4 schwarzschildMetric(double r, double schwarzschildRadius, double theta);

        /// Signature of a diagonal metric.
        /// \return Counts of positive, negative and zero entries, in order.
        static std::array<int, 3> signature(const Matrix4 &metric);

        /// Candidate continuous path between the two signature classes,
        /// diag(1, -cos L, -cos L, -cos L).
        /// \param lambda Path parameter; the metric degenerates at pi/2.
        static Matrix4 interpolatedMetric(double lambda);

        std::string title() const override
        {
            return "Full comparison with a black hole horizon";
        }
        void run(Report &report) const override;
    };

}
