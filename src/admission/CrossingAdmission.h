#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <string>
#include <vector>

namespace slm

{

    /// Every condition a state has to meet to cross into the far region, move
    /// there, and come back earlier than it left, collected in one place.
    ///
    /// The conditions are scattered across the libraries that establish them,
    /// which is right for computing them and wrong for reading them. A reader
    /// asking what it takes should not have to assemble eight separate results,
    /// and an author adding a ninth condition should have one place to add it.
    /// So each condition is stated here as a named test with its own threshold,
    /// and the verdict is the conjunction.
    ///
    /// Two of the conditions bound the state, two bound the region, one bounds
    /// the geometry of the surface, one bounds the branch, and one bounds the
    /// distance travelled on the far side. They fail in different ways and the
    /// difference matters: a state above the mass ceiling has no journey to
    /// price, whereas a state that has not travelled far enough has a journey
    /// whose arrival simply falls after its departure. Only the last is a
    /// matter of paying more.
    class CrossingAdmission
    {
    public:
        enum class Condition
        {
            BandAboveCutoff,     ///< the band centre clears the frequency below which nothing leaves
            BandWidthAdmissible, ///< the whole band, not only its centre, clears that frequency
            MassBelowCeiling,    ///< the mass parameter leaves room for the band to clear it
            InteriorBlocks,      ///< the region is a barrier, so there is a threshold to cross
            WeightSurvives,      ///< the two crossings leave a non-zero amplitude
            MatchingAdmitsExit,  ///< some imposable matching requirement allows an outgoing-only wave
            ReversingBranch,     ///< the crossing realised is the one that reverses the orientation
            DistanceExceedsPrice ///< the far-side travel exceeds what the round trip costs
        };

        static std::vector<Condition> all();

        static std::string name(Condition condition);

        /// What failing this condition costs: whether it removes the journey or
        /// merely leaves the arrival late.
        static std::string failureMeaning(Condition condition);

        /// Whether failing this condition can be remedied by paying more, which
        /// is true of exactly one of them.
        static bool remediableByPaying(Condition condition);

        /// The state and region a verdict is asked about, gathered so that a
        /// condition cannot be evaluated against a different configuration from
        /// its neighbour.
        struct Setup
        {
            IntermediateRegion::Kind kind;
            double c;
            double mu;
            double transverseSquared;
            double thickness;
            double centre;
            double spread;
            double bandReach;
            double farSideDistance;
            int branch;
        };

        static bool holds(Condition condition, const Setup &setup);

        /// Margin by which the condition is met, in the units natural to it,
        /// positive when met. Reported alongside the verdict because a
        /// condition met by a hair and one met by orders of magnitude are
        /// different situations.
        static double margin(Condition condition, const Setup &setup);

        /// Whether every condition holds.
        static bool admitted(const Setup &setup);

        /// How many hold.
        static int holdingCount(const Setup &setup);

        /// The first condition that fails, for reporting which wall was hit.
        static Condition firstFailure(const Setup &setup);

        /// The setup a proton corresponds to, in the dimensionless units the
        /// libraries use, with the band placed above its own cutoff.
        static Setup protonSetup(double farSideDistance);

        /// Moment the state returns, measured from its departure, once every
        /// condition is met. Negative means it is back before it left.
        static double returnMoment(const Setup &setup);

        /// Smallest far-side distance that turns the return negative, which is
        /// the price of the journey for this setup.
        static double priceOfTheJourney(const Setup &setup);
    };

    /// Section listing every admission condition and applying them together.
    class CrossingAdmissionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What it takes to cross, travel there, and return early";
        }
        void run(Report &report) const override;
    };

}
