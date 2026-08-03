#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm

{

    /// Whether the return event precedes the entry event, and at what weight.
    ///
    /// The return moment has two contributions and they behave differently with
    /// the thickness of the intermediate region. The crossing itself contributes
    /// the delay read off the phase of the two-crossing amplitude, and in the
    /// barrier regime that delay saturates: past a modest thickness it stops
    /// growing. Travel along the far side's distinguished axis contributes a
    /// displacement on the same clock, one to one in the amount, and that does
    /// not saturate.
    ///
    /// A bounded quantity added to an unbounded one has a sign that the
    /// unbounded one eventually decides. So on the branch that carries the
    /// displacement backwards there is a far-side distance beyond which the
    /// arrival precedes the departure, and this class computes where that
    /// crossover sits.
    ///
    /// Two things are needed to read the result honestly and both are computed
    /// here rather than left to the reader. The first is that the backward
    /// branch has to be available, which is a separate question settled
    /// elsewhere by enumerating the admissible crossings. The second is the
    /// weight: the configurations where the crossover occurs are the thick
    /// barriers, and a thick barrier transmits almost nothing, so the amplitude
    /// for the whole sequence is small and is reported alongside the time.
    ///
    /// The two contributions are added as independent terms. That independence
    /// is an assumption of the surrounding construction and not a result of it,
    /// and every number here inherits it.
    class ArrivalOrder
    {
    public:
        /// Direction of travel along the far side's distinguished axis.
        enum class Direction
        {
            Forward, ///< Displacement adds to the elapsed time.
            Backward ///< Displacement subtracts from it.
        };

        /// Delay contributed by the crossing alone, from the phase of the
        /// two-crossing amplitude, for a representative far-side orientation.
        static double crossingDelay(IntermediateRegion::Kind kind, double c, double mu,
                                    double thickness);

        /// Displacement contributed on the same clock by travelling the given
        /// distance along the far side's distinguished axis in the given
        /// direction.
        static double travelContribution(Direction direction, double distance);

        /// Arrival moment measured from the entry event.
        static double arrivalMoment(IntermediateRegion::Kind kind, double c, double mu,
                                    double thickness, Direction direction, double distance);

        /// True when the arrival precedes the entry.
        static bool arrivesBeforeEntry(IntermediateRegion::Kind kind, double c, double mu,
                                       double thickness, Direction direction, double distance);

        /// Far-side distance at which the arrival moment changes sign on the
        /// backward branch, which is just the crossing delay.
        static double crossoverDistance(IntermediateRegion::Kind kind, double c, double mu,
                                        double thickness);

        /// Whether the crossing delay has stopped growing with thickness, which
        /// is what makes the crossover distance bounded.
        static bool delaySaturates(IntermediateRegion::Kind kind, double c, double mu,
                                   double firstThickness = 2.0, double secondThickness = 8.0,
                                   double tolerance = 1e-3);

        /// Transmission weight of the crossing that carries the sequence, so the
        /// time and its likelihood are read together.
        static double weight(IntermediateRegion::Kind kind, double c, double mu,
                             double transverseSquared, double thickness);
    };

    /// Section computing whether the return can precede the departure, and at
    /// what weight.
    class ArrivalOrderSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A bounded delay against an unbounded displacement";
        }
        void run(Report &report) const override;
    };

}
