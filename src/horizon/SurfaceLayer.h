#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    /// Extrinsic curvature of the interpolation, and whether a surface layer
    /// appears at the signature change.
    ///
    /// The junction condition of section 9 was argued on the matter side, from
    /// the conjugate momentum. On the gravitational side the same choice
    /// reappears as a condition on the extrinsic curvature of the transition
    /// surface: the strong condition asks it to vanish there, the weak one only
    /// asks it to be continuous. A distributional term in the stress tensor,
    /// that is a surface layer, is absent exactly when the extrinsic curvature
    /// is continuous.
    ///
    /// The metric is taken as diag(1, -cos(profile(xi)), -1, -1), the first leg
    /// of the staged path of section 13.5 promoted to a function of a
    /// coordinate. The signature changes where the profile passes pi/2.
    class SurfaceLayer
    {
    public:
        /// Which interpolation profile carries the metric across.
        enum class Profile
        {
            Linear,         ///< lambda = pi (xi + 1) / 2, constant slope
            FlatAtCrossing, ///< lambda = pi/2 + (pi/2) sin^3(pi xi / 2), slope vanishing at the crossing
            Tanh            ///< smooth step, steepest at the crossing
        };

        /// Value of the profile at the given coordinate, on xi in [-1, 1].
        static double profile(Profile shape, double xi);

        /// Derivative of the profile, by central difference.
        static double profileSlope(Profile shape, double xi, double h = 1e-6);

        /// Metric at the given coordinate.
        static Matrix4 metric(Profile shape, double xi);

        /// Coordinate at which the signature changes, where the profile
        /// reaches pi/2. Found by bisection.
        static double crossing(Profile shape);

        /// The one non-trivial component of the extrinsic curvature of the
        /// surfaces of constant xi, K = (1/2) d(g_11)/d(xi).
        static double extrinsicCurvature(Profile shape, double xi, double h = 1e-6);

        /// Jump in the extrinsic curvature across the crossing.
        static double curvatureJump(Profile shape, double delta = 1e-4);

        /// Whether the strong condition holds, that the extrinsic curvature
        /// vanishes at the crossing.
        static bool satisfiesStrongCondition(Profile shape, double tolerance = 1e-6);

        /// Whether the weak condition holds, that the extrinsic curvature is
        /// continuous across the crossing.
        static bool satisfiesWeakCondition(Profile shape, double tolerance = 1e-6);
    };

    /// Section relating the junction condition of section 9 to the geometry of
    /// the transition.
    class SurfaceLayerSection : public Section
    {
    public:
        std::string number() const override { return "9.2"; }
        std::string title() const override
        {
            return "The same choice seen on the gravitational side";
        }
        void run(Report &report) const override;
    };

}
