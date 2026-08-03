#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <array>
#include <string>

namespace slm
{

    /// One massive particle carried through the whole chain, end to end, with
    /// every number that describes the journey printed in one place.
    ///
    /// Every link of the chain is built and checked elsewhere. What is missing
    /// is a single closed example: a particle with a stated energy, sent in,
    /// carried across, moved a stated distance on the far side, brought back,
    /// and found at a stated moment relative to its departure. That is what
    /// this class produces. It computes nothing new; it calls the libraries
    /// that already hold each step and refuses to restate any of their
    /// formulas, so that a disagreement between the example and its parts is
    /// impossible rather than unlikely.
    ///
    /// Three journeys are worked, and they are chosen to show that the outcome
    /// is a matter of how far the particle goes and not of what it is. The
    /// first falls short of the threshold and returns after it left. The
    /// second sits on the threshold and returns at the moment it left. The
    /// third passes the threshold and returns before it left.
    ///
    /// The amplitude is carried alongside at every step, because the journey is
    /// not free and the honest form of the result states its weight in the same
    /// breath as its timing.
    class WorkedRoundTrip
    {
    public:
        using Three = std::array<double, 3>;

        /// The energy vector the worked example uses, at the given total.
        static Three energyAtTotal(double total);

        /// Frequency the mass shell assigns to that vector.
        static double frequency(const Three &energy, double c, double mu);

        /// Time the round trip spends inside the region, which is twice the
        /// single traversal.
        static double roundTripDelay(const Three &energy, IntermediateRegion::Kind kind, double c,
                                     double mu, double thickness);

        /// Far-side distance at which the return lands exactly on the
        /// departure, which is that delay.
        static double thresholdDistance(const Three &energy, IntermediateRegion::Kind kind,
                                        double c, double mu, double thickness);

        /// Moment the particle is found at, measured from its departure, after
        /// covering the given distance on the far side. Negative means it
        /// returned before it left.
        static double returnMoment(const Three &energy, IntermediateRegion::Kind kind, double c,
                                   double mu, double thickness, double farSideDistance,
                                   int branch);

        /// Whether the return falls before the departure.
        static bool returnsBeforeDeparture(const Three &energy, IntermediateRegion::Kind kind,
                                           double c, double mu, double thickness,
                                           double farSideDistance, int branch);

        /// Weight the particle comes back with, which is the two-way
        /// transmission.
        static double returnedWeight(const Three &energy, IntermediateRegion::Kind kind,
                                     double thickness);

        /// Whether the moment computed here agrees with the closed formula for
        /// the return event, which is the check that this example is the chain
        /// and not a retelling of it.
        static bool agreesWithClosedFormula(const Three &energy, IntermediateRegion::Kind kind,
                                            double c, double mu, double thickness);

        /// Whether the threshold distance agrees with the one the threshold
        /// optimum computes by its own route.
        static bool agreesWithThresholdOptimum(double total, IntermediateRegion::Kind kind,
                                               double c, double mu, double thickness,
                                               double tolerance);

        /// Whether raising the total energy lowers the distance the journey
        /// needs, at an unchanged returned weight.
        static bool higherEnergyBuysDistance(IntermediateRegion::Kind kind, double c, double mu,
                                             double depth, double tolerance);

        /// The whole journey as one record, so that every intermediate quantity
        /// of a single trip can be printed together rather than assembled by a
        /// reader from separate sections.
        struct Journey
        {
            double total;
            double normalPart;
            double transversePart;
            double frequency;
            double outsideWavenumber;
            double interiorDecay;
            double depth;
            double singleDelay;
            double roundTripDelay;
            double thresholdDistance;
            double farSideDistance;
            double returnElapsed;
            double returnCrossing;
            double returnTransverseFirst;
            double returnTransverseSecond;
            double returnedWeight;
            double lightRoundTrip;
            double advanceOverLight;
            int branch;
        };

        /// Everything about one trip, computed by calling the libraries that
        /// own each step. The four coordinates of the return event come from
        /// ReturnEvent so that this record cannot drift from the closed
        /// formula; only the far-side displacement is added here, and it is
        /// added to the time coordinate alone.
        static Journey journey(double total, IntermediateRegion::Kind kind, double c, double mu,
                               double thickness, double farSideDistance, int branch);

        /// Whether the record's elapsed time is the one ReturnEvent computes,
        /// which is what makes the record a view of the chain rather than a
        /// second implementation of it.
        static bool journeyAgreesWithReturnEvent(const Journey &record,
                                                 IntermediateRegion::Kind kind, double c,
                                                 double mu, double thickness);

        /// Whether the journey beats a light signal covering the same round
        /// trip, which is the comparison the article makes and which needs both
        /// sides to be a round trip.
        static bool beatsLight(const Journey &record);

        /// Every outcome a round trip can have, so that the branch sending the
        /// particle back is presented as one case of a family rather than as
        /// the only case. Two choices are free, the branch and the distance,
        /// and a third axis is the regime.
        enum class Outcome
        {
            LaterThanDeparture,
            ExactlyAtDeparture,
            EarlierThanDeparture
        };

        static std::string outcomeName(Outcome outcome);

        /// Which of the three a given branch and distance produce.
        static Outcome outcomeOf(const Three &energy, IntermediateRegion::Kind kind, double c,
                                 double mu, double thickness, double farSideDistance,
                                 int branch);

        /// Whether the forward branch ever reaches an earlier moment, at any
        /// distance. It does not, and that is what makes the branch and not the
        /// journey the thing that decides the sign.
        static bool forwardBranchEverArrivesEarlier(const Three &energy,
                                                    IntermediateRegion::Kind kind, double c,
                                                    double mu, double thickness);

        /// Delay a particle pays when it travels no distance at all over there,
        /// which is the floor two crossings impose on any trip.
        static double delayWithoutTravelling(const Three &energy, IntermediateRegion::Kind kind,
                                             double c, double mu, double thickness);

        /// Whether the threshold distance is independent of the thickness,
        /// which holds in the evanescent regime and is what makes the price a
        /// fixed number there.
        static bool thresholdIsThicknessFree(const Three &energy, IntermediateRegion::Kind kind,
                                             double c, double mu, double tolerance);

        /// Whether the threshold grows with thickness in a propagating region,
        /// which is the regime where the price is not a fixed number.
        static bool thresholdGrowsWithThickness(const Three &energy,
                                                IntermediateRegion::Kind kind, double c,
                                                double mu);
    };

    /// Section carrying one particle through the whole chain.
    class WorkedRoundTripSection : public Section
    {
    public:
        std::string title() const override
        {
            return "One massive particle carried through the whole chain, end to end";
        }
        void run(Report &report) const override;
    };

}
