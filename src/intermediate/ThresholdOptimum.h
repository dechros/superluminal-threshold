#pragma once

#include "core/Section.h"

namespace slm
{

    /// How small the saturated delay can be made, and what that costs.
    ///
    /// The saturated delay is usually treated as a fact about a barrier rather
    /// than as a quantity with free parameters, and the question of how small it
    /// can be made is not one the surrounding literature asks. It matters here
    /// because the delay is the distance an object has to cover on the far side
    /// before its arrival falls before its departure: the delay is the price,
    /// and the price is not fixed.
    ///
    /// The closed form makes the question tractable. Writing the first squared
    /// component of the energy vector as the normal part and the remaining two
    /// as the transverse part, the delay depends on those two numbers and the
    /// mass alone, and the thickness does not appear. So the delay can be
    /// minimised over them.
    ///
    /// Two separate movements come out of that, and they should not be run
    /// together. At fixed total energy there is an interior optimum in how the
    /// energy is split between normal and transverse, and it is a mild effect.
    /// Raising the total energy at a fixed split is not mild: the delay falls
    /// without bound, so the required distance can be made as small as one
    /// likes.
    ///
    /// Whether that is a real gain depends on what happens to the transmitted
    /// amplitude, which is the reason the second half of this class exists. The
    /// amplitude is set by the product of the decay constant and the thickness,
    /// while saturation itself only requires that product to be large. Holding
    /// it fixed is therefore the honest comparison, and it is the one made here.
    class ThresholdOptimum
    {
    public:
        /// Squared decay constant inside the region, from the normal and
        /// transverse parts of the energy and the number of turned directions.
        static double decaySquared(double normalPart, double transversePart, int turned);

        /// Whether the configuration is in the barrier regime at all.
        static bool isBarrier(double normalPart, double transversePart, int turned);

        /// Frequency the mass shell assigns.
        static double frequency(double normalPart, double transversePart, double mu, double c);

        /// Saturated delay for a SINGLE traversal. The round trip crosses the
        /// region twice and is therefore twice this; the distance that has to
        /// be covered on the far side is compared against the round trip, so
        /// use the function below for that and not this one. Keeping the two
        /// apart matters: conflating them has cost this work a factor of two
        /// twice already, both times because a name did not say which it was.
        static double saturatedDelay(double normalPart, double transversePart, double mu, double c,
                                     int turned);

        /// Distance that has to be covered on the far side for the arrival to
        /// fall before the departure, which is the round trip delay.
        static double thresholdDistance(double normalPart, double transversePart, double mu,
                                        double c, int turned);

        /// Whether the finite-thickness delay has actually reached the
        /// saturated value at the given depth, which the whole comparison
        /// assumes and which is therefore checked rather than trusted.
        static bool delayHasSaturatedAtDepth(double normalPart, double transversePart, double mu,
                                             double c, int turned, double depth,
                                             double tolerance);

        /// The split of a given total energy between normal and transverse that
        /// makes the delay smallest, returned as the normal part.
        static double optimalNormalPart(double total, int turned);

        /// The smallest single-traversal delay available at that total, from
        /// the split above.
        static double smallestDelayAtTotal(double total, double mu, double c, int turned);

        /// The smallest far-side distance that has to be covered at that total,
        /// which is twice the above.
        static double smallestThresholdAtTotal(double total, double mu, double c, int turned);

        /// Thickness at which the delay has saturated to the given depth, where
        /// depth is the product of the decay constant and the thickness.
        static double thicknessForDepth(double normalPart, double transversePart, int turned,
                                        double depth);

        /// Transmitted amplitude at that thickness, which is what the shrinking
        /// distance has to be paid for out of.
        static double amplitudeAtDepth(double normalPart, double transversePart, double mu,
                                       double c, int turned, double depth);

        /// Whether raising the total energy at a fixed split drives the delay
        /// towards zero.
        static bool delayFallsWithoutBound(double mu, double c, int turned);

        /// Whether the amplitude at fixed saturation depth is unchanged by that
        /// same rise, which is what turns the falling delay into a real gain
        /// rather than a trade.
        static bool amplitudeHoldsAtFixedDepth(double mu, double c, int turned,
                                               double tolerance);
    };

    /// Section minimising the saturated delay and pricing the result.
    class ThresholdOptimumSection : public Section
    {
    public:
        std::string title() const override
        {
            return "How small the saturated delay can be made, and what it costs";
        }
        void run(Report &report) const override;
    };

}
