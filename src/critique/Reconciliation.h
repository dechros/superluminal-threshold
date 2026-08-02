#pragma once

#include "core/Section.h"

namespace slm
{

    /// Sorting the model's disagreements into the two kinds there are.
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
    /// The second kind is counted and left standing, with the measurement that
    /// would decide it named in the article.
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

        /// Number left standing as genuine contradictions.
        static int standingContradictionCount();
    };

    /// Section applying the inclusive method and counting what it cannot absorb.
    class ReconciliationSection : public Section
    {
    public:
        std::string number() const override { return "24"; }
        std::string title() const override
        {
            return "Which disagreements are one coin seen twice, and which are not";
        }
        void run(Report &report) const override;
    };

}
