#pragma once

#include "core/Section.h"

namespace slm
{

    /// Sorting disagreements between two treatments into the two kinds.
    ///
    /// Some are two views of one object: the positions differ in what they look
    /// at or from where, and once the parameter separating them is named, both
    /// are right. Others are genuine contradictions: they predict different
    /// numbers for the same measurement, and one of them is wrong.
    ///
    /// Only the first kind is settled here, and it is settled by computing both
    /// views and exhibiting the parameter that turns one into the other. A
    /// disagreement is not called reconciled because the two sides can be
    /// talked into agreement; it is called reconciled when both readings come
    /// out of one calculation with a parameter changed.
    ///
    /// The second kind is counted and left standing rather than absorbed.
    class Reconciliation
    {
    public:
        /// A Kleinian region is a cavity or a barrier according to which axis
        /// turns over, and nothing else.
        static bool cavityAndBarrierAreOneCoin();

        /// The delay and the mixing disagree about the thickness because they
        /// are different observables of one amplitude.
        static bool delayAndMixingAreOneCoin();

        /// Total reflection is the thick limit of tunnelling rather than a
        /// separate claim.
        static bool reflectionIsTheThickLimit();

        /// The far side is ill posed off its own mass shell and well posed on
        /// it, so both verdicts hold, of different data.
        static bool illPosedAndWellPosedAreOneCoin();

        /// The exit face and the turn looked like independent labels and are
        /// two parts of one vector.
        static bool exitFaceAndTurnAreOneVector();

        /// Number of disagreements this section reconciles by calculation.
        static int reconciledCount();

        /// The two numbers two rival positions give for one measurement. A
        /// disagreement counts as a genuine contradiction exactly when the two
        /// differ, so the count is derived rather than declared.
        struct Rivals
        {
            double first;
            double second;
            /// Whether the two positions actually disagree numerically.
            bool disagree(double tolerance = 1e-9) const;
        };

        /// Transmitted flux fraction through the threshold, under the strong
        /// junction condition and under the weak one with a slab present.
        /// Decided by measuring how much gets through.
        static Rivals transmittedFlux(double thickness);

        /// Strength of the surface layer the junction carries, for a generic
        /// transition profile and for one stationary at the crossing. Decided
        /// by measuring the surface energy density.
        static Rivals surfaceLayer(double thickness);

        /// Casimir energy per unit area between two threshold surfaces, when
        /// they carry the same self-adjoint condition and when they carry
        /// opposite ones. Decided by measuring the sign of the force.
        static Rivals casimirEnergy(double separation);

        /// Quanta arriving at the entry face after a return through the
        /// opposite face, read as one particle of negative energy and as a
        /// created pair. Decided by counting arrivals in coincidence.
        static Rivals returnedQuanta();

        /// Net energy delivered here by that same return, under the same two
        /// readings. Decided by measuring the sign of the energy deposited.
        static Rivals returnedEnergy(double magnitude);

        /// How many of the four disagreements above come out with different
        /// numbers, and therefore stand as contradictions.
        static int standingContradictionCount();
    };

    /// Section applying the inclusive method and counting what it cannot absorb.
    class ReconciliationSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Which disagreements are one coin seen twice, and which are not";
        }
        void run(Report &report) const override;
    };

}
