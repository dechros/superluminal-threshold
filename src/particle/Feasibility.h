#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <string>
#include <vector>

namespace slm
{

    /// What stands between the chain and an experiment, sorted by kind.
    ///
    /// The paper establishes a conditional: if such a crossing is realised, the
    /// return moment is a computed number. This class takes the antecedent
    /// seriously and asks what would have to be true for the round trip to be
    /// attempted rather than described. It does not argue that the trip is
    /// possible. It sorts the obstacles, computes the ones that can be
    /// computed, and says plainly which are not obstacles of degree but of
    /// kind.
    ///
    /// The distinction that organises everything here is between an obstacle
    /// that a better apparatus removes and one that no apparatus removes. A
    /// small amplitude is the first: it is a rate, and rates are bought with
    /// attempts. A quantity that no measurement here can reach is the
    /// second, and calling it an engineering problem would be dishonest.
    ///
    /// Four obstacles are examined. Two are rates and are priced. One is a
    /// choice the metric does not make, which no rate touches. One is a
    /// question about whether the configuration exists at all, which is where
    /// the whole conditional sits.
    class Feasibility
    {
    public:
        /// How an obstacle behaves as the apparatus improves.
        enum class Kind
        {
            Rate,      ///< Bought with attempts; a number, not a barrier.
            Selection, ///< A choice nothing in the model makes; no rate helps.
            Existence  ///< Whether the configuration can be built at all.
        };

        static std::string kindName(Kind kind);

        struct Obstacle
        {
            std::string what;
            Kind kind;
            std::string whatWouldSettleIt;
        };

        static std::vector<Obstacle> obstacles();

        static int countOfKind(Kind kind);

        /// Expected number of successful round trips from a run: the returned
        /// weight times the attempts. This is the whole of the rate question
        /// and it is deliberately trivial, because the point is that it is a
        /// multiplication and not a barrier.
        static double expectedEvents(double returnedWeight, double attemptsPerSecond,
                                     double seconds);

        /// Attempts needed for one event on average.
        static double attemptsForOneEvent(double returnedWeight);

        /// Returned weight at a given total energy, holding the saturation
        /// depth fixed. Raising the energy does NOT move it, which is computed
        /// here rather than hoped: the rate has to be bought with attempts.
        static double weightAtTotal(double total, IntermediateRegion::Kind kind, double c,
                                    double mu, double depth);

        /// Far-side distance the particle must cover at that energy, which is
        /// what the experiment has to arrange on the other side and which
        /// falls as the energy rises.
        static double distanceAtTotal(double total, IntermediateRegion::Kind kind, double c,
                                      double mu);

        /// Whether the two demands pull in the same direction, so that buying
        /// the rate also buys the distance rather than trading against it.
        static bool energyBuysBothDemands(IntermediateRegion::Kind kind, double c, double mu,
                                          double depth);

        /// Whether any amount of energy settles which crossing is realised,
        /// which it does not, and which is why that obstacle is of a different
        /// kind from the others.
        static bool energySettlesTheSelection();
    };

    /// Section sorting what stands between the chain and an experiment.
    class FeasibilitySection : public Section
    {
    public:
        std::string title() const override
        {
            return "What stands between this chain and an experiment, sorted by kind";
        }
        void run(Report &report) const override;
    };

}
