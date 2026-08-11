#pragma once

#include "core/Section.h"

namespace slm

{

    /// Two particles sent across the threshold together, one driven along
    /// @f$ +r @f$ and one along @f$ -r @f$ over the same distance, and what the
    /// time spent crossing does to each.
    ///
    /// The far side's single space axis carries a sign, and the map sends a
    /// displacement along it to the near-side clock with coefficient minus one.
    /// A particle driven along @f$ +r @f$ therefore returns earlier than it
    /// left and one driven along @f$ -r @f$ returns later, by the same amount,
    /// so both directions in time follow from one apparatus and one distance.
    ///
    /// The crossing itself is not free. Reaching the far minimum means
    /// traversing the wall, and the wall has a thickness: the particle spends
    /// @ref singleCrossingDelay of near-side time getting in and the same
    /// getting out. That delay is positive for both particles and it does not
    /// depend on which way either was driven, so it adds to the later one and
    /// subtracts from the earlier one. Two consequences follow and they are not
    /// symmetric.
    ///
    /// Travelling forward in time needs no minimum distance, because the delay
    /// pushes in the direction the particle was already going. Travelling
    /// backward needs the far-side distance to beat the round trip through the
    /// wall, and @ref breakEvenDistance is where the two cancel exactly. Below
    /// that distance the apparatus returns both particles later than they left
    /// and displaces neither one backward.
    ///
    /// The separation between the two particles is the quantity the delay
    /// cannot touch. @ref separation is twice the light travel time of the
    /// distance, free of the wall's thickness, of the crossing speed and of
    /// the tolerance at which the crossing is called complete, provided the two
    /// particles crossed under the same conditions. @ref delayMismatch is what
    /// remains when they did not.
    class PairedExcursion
    {
    public:
        /// Which way the particle is driven along the far side's space axis.
        enum class Sense
        {
            PlusR,
            MinusR
        };

        /// The near-side time in seconds that a distance of @p metres along the
        /// given sense contributes, negative for @c PlusR.
        static double mapContribution(double metres, Sense sense);

        /// The near-side time in seconds spent traversing the wall once, for a
        /// wall of width @p wallWidth metres crossed at speed @p beta in units
        /// of the speed of light, with the crossing called complete when the
        /// field is within @p tolerance of the far minimum.
        static double singleCrossingDelay(double wallWidth, double tolerance, double beta);

        /// Twice @ref singleCrossingDelay, the delay of getting there and back.
        static double roundTripDelay(double wallWidth, double tolerance, double beta);

        /// The net near-side time between departure and return, negative when
        /// the particle returns before it left.
        static double netShift(double metres, Sense sense, double wallWidth, double tolerance,
                               double beta);

        /// The far-side distance in metres at which the map's contribution and
        /// the round trip through the wall cancel. A @c PlusR particle returns
        /// before it left only beyond this distance.
        static double breakEvenDistance(double wallWidth, double tolerance, double beta);

        /// The gap in seconds between the two returning particles, which is
        /// twice the light travel time of @p metres and carries no trace of the
        /// crossing.
        static double separation(double metres);

        /// The part of the gap that survives when the two particles cross at
        /// different speeds, which is the only way the crossing enters a
        /// measurement of the gap.
        static double delayMismatch(double wallWidth, double tolerance, double firstBeta,
                                    double secondBeta);
    };

    /// Section verifying that one apparatus reaches both directions in time,
    /// that only the backward direction carries a minimum distance, and that
    /// the gap between the two particles is free of the crossing.
    class PairedExcursionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "One apparatus, two directions in time, and what the thickness of the wall costs each of them";
        }
        void run(Report &report) const override;
    };

}
