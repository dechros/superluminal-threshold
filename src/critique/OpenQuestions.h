#pragma once

#include "core/Section.h"

#include <string>

namespace slm

{

    /// The state of each question the surrounding literature leaves unsettled,
    /// sorted by what kind of question it is and, where the tools here can
    /// decide it, decided.
    ///
    /// Four kinds are distinguished and they call for different treatment. A
    /// question is WITHDRAWN when a claim once made has since been refuted,
    /// whether from outside or by these calculations. It is a GAP when no
    /// published result covers it, so there is nothing to agree or disagree
    /// with. It is OPEN when it is unsettled both outside and here. It is
    /// DISPUTED when two published treatments give different answers to one
    /// question, which is the only kind an experiment could close.
    ///
    /// The classification is not a matter of opinion where a computation can
    /// reach it. Each item that can be decided by the libraries here is decided
    /// by calling them, and the count in each class follows from those calls
    /// rather than being declared.
    class OpenQuestions
    {
    public:
        enum class Status
        {
            Withdrawn,
            Gap,
            Open,
            Disputed
        };

        static std::string name(Status status);

        /// Whether the claim that a continuous path between the signatures
        /// cannot be built has been withdrawn, which it has, since a path
        /// exists at the cost of passing through a two-time region.
        static bool continuousPathClaimWithdrawn();

        /// Whether the claim that the far side is ill posed for everything has
        /// been withdrawn, which it has, since the modes reachable by crossing
        /// lie on a shell where nothing grows.
        static bool illPosedForEverythingWithdrawn();

        /// Whether the reading of the saturating delay as a fast transit has
        /// been withdrawn, which it has, since the delay is not independent of
        /// the stored norm in that regime.
        static bool fastTransitReadingWithdrawn();

        /// Whether the claim that the transmitting junction is energetically
        /// benign has been withdrawn, which it has.
        static bool benignLayerClaimWithdrawn();

        /// Number of claims withdrawn, counted from the four above.
        static int withdrawnCount();

        /// Whether a published transmission coefficient across a signature
        /// change exists to compare against, which it does not.
        static bool publishedTransmissionExists();

        /// Whether a published treatment of a wave packet crossing a signature
        /// change exists, which it does not.
        static bool publishedPacketCrossingExists();

        /// Whether a published map from a far-side orientation to the return
        /// event exists, which it does not.
        static bool publishedReturnMapExists();

        /// Number of gaps, counted from the three above.
        static int gapCount();

        /// Whether the distribution over the reachable outcomes is known,
        /// which it is not, since only the finite set they range over has been
        /// computed and not the weight on each.
        static bool outcomeDistributionKnown();

        /// Whether the capacity of the gravitational channel is known, as
        /// opposed to its existence.
        static bool gravitationalCapacityKnown();

        /// Whether an allowability criterion has been adopted for the
        /// complex-time construction the return uses.
        static bool allowabilityCriterionAdopted();

        /// Whether the degeneracy between a returning particle and a created
        /// pair has been broken.
        static bool pairDegeneracyBroken();

        /// Number of questions still open, counted from the four above.
        static int openCount();

        /// Number of disagreements where two positions give different numbers
        /// for one measurement, taken from the reconciliation calculation
        /// rather than restated here.
        static int disputedCount();

        /// Total number of items tracked.
        static int totalCount();
    };

    /// Section reporting the status of every unsettled question.
    class OpenQuestionsSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What is withdrawn, what has no counterpart, what is open, what is disputed";
        }
        void run(Report &report) const override;
    };

}
