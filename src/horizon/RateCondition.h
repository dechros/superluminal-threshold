#pragma once

#include "core/Section.h"
#include "horizon/SurfaceLayer.h"

namespace slm
{

    /// Whether the normal derivative dies off fast enough at the crossing for
    /// the weak choice to be consistent, which is a rate rather than a
    /// preference.
    ///
    /// The objection this answers is the strongest one raised against allowing
    /// a nonvanishing normal derivative at a signature change, and it is not a
    /// philosophical objection. Writing the field equations across the surface
    /// produces a term of the form (normal derivative) times a delta divided by
    /// the lapse. As the lapse goes to zero at the crossing that term is of the
    /// form zero over zero, and it cannot be set to zero by declaration: the
    /// numerator has to be shown to vanish faster than the denominator. If it
    /// does, the term drops and the weak choice survives; if it does not, the
    /// term stays and the equations are inconsistent unless the derivative is
    /// made to vanish outright, which is the strong condition.
    ///
    /// So the disagreement reduces to one computable exponent. In the metric
    /// family used here the lapse goes as the square root of the vanishing
    /// metric component, and the normal derivative is the extrinsic curvature
    /// already computed for the layer. Their ratio, followed towards the
    /// crossing, decides the question profile by profile, and the answer is not
    /// the same for every profile.
    class RateCondition
    {
    public:
        /// Lapse of the transition at the given coordinate, the square root of
        /// the magnitude of the metric component that changes sign.
        static double lapse(SurfaceLayer::Profile shape, double xi);

        /// Normal derivative whose rate is in question, which is the extrinsic
        /// curvature of the surfaces of constant coordinate.
        static double normalDerivative(SurfaceLayer::Profile shape, double xi);

        /// The ratio whose limit decides the question. Bounded means the term
        /// drops out and the weak choice survives; unbounded means it does not.
        static double ratio(SurfaceLayer::Profile shape, double xi);

        /// The ratio evaluated at a given distance from the crossing, on the
        /// side the coordinate is approached from.
        static double ratioAtDistance(SurfaceLayer::Profile shape, double distance);

        /// Power with which the ratio behaves in the distance from the
        /// crossing, estimated from two distances. Negative means the ratio
        /// diverges, positive means it dies.
        static double ratioExponent(SurfaceLayer::Profile shape, double nearDistance,
                                    double farDistance);

        /// Whether the ratio goes to zero as the crossing is approached, which
        /// is the condition the weak choice needs.
        static bool satisfiesRateCondition(SurfaceLayer::Profile shape);

        /// Whether any profile satisfies the rate condition while still
        /// carrying a layer, which is what the weak choice would need in order
        /// to be a generic option rather than a tuned one.
        static bool anyProfileKeepsLayerAndRate();
    };

    /// Section computing the rate at which the normal derivative dies against
    /// the rate at which the lapse does.
    class RateConditionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Does the normal derivative die faster than the lapse";
        }
        void run(Report &report) const override;
    };

}
