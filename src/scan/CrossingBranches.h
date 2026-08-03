#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <array>
#include <vector>

namespace slm
{

    /// The admissible crossing maps, classified by the sign they give the slot
    /// that carries our time.
    ///
    /// A scan elsewhere in this project filters the signed permutation matrices
    /// by three conditions: the metric relation between the two signatures,
    /// closure under a second application, and unit determinant. Eight survive,
    /// and all eight send our time slot to the same single axis on the far side.
    /// That much is already established.
    ///
    /// What this class adds is the sign on that slot. It is not fixed by any of
    /// the three conditions: the eight survivors divide evenly, four sending a
    /// positive far-side displacement to a later moment here and four sending it
    /// to an earlier one. The division persists at every stage of the filter
    /// chain, so no strengthening of those conditions removes it.
    ///
    /// The two families differ by reversing our own time axis, which is an
    /// isometry of our metric. Anything that selects between them therefore lies
    /// outside the metric, and the same holds on the far side, where reversing
    /// its distinguished axis is likewise an isometry. This class computes the
    /// division and the relation between the families; it does not select, and
    /// records that the selection is not available here.
    class CrossingBranches
    {
    public:
        /// A surviving crossing map together with what it does to the time slot.
        struct Branch
        {
            Matrix4 matrix;
            /// Far-side axis the time slot is carried to.
            int farSideAxis = -1;
            /// Sign given to that slot, +1 for later and -1 for earlier.
            int timeSign = 0;
        };

        /// Every signed permutation matrix satisfying the metric relation.
        static std::vector<Branch> metricAdmissible();

        /// Those of them that are also involutions, so that crossing twice
        /// returns the frame it started in.
        static std::vector<Branch> closedUnderRepetition();

        /// Those that in addition have unit determinant.
        static std::vector<Branch> orientationPreserving();

        /// Number of branches in the given set carrying the given time sign.
        static int countWithSign(const std::vector<Branch> &branches, int sign);

        /// Whether every branch in the set sends the time slot to the same
        /// far-side axis, which is what makes the sign the only remaining
        /// freedom.
        static bool axisIsCommon(const std::vector<Branch> &branches);

        /// Reversal of our time axis together with the far side's distinguished
        /// axis, @f$ \mathrm{diag}(-1,+1,+1,-1) @f$.
        ///
        /// Reversing either axis on its own does not do it. A single-axis
        /// reversal turns the determinant negative and destroys the closure, so
        /// it leaves the admissible set at once. The two axes reversed together
        /// keep both, and they are exactly the pair the crossing identifies with
        /// each other, so the operation has a reading: travel the other way
        /// along their space direction and arrive the other way along our time.
        static Matrix4 pairedReversal();

        /// Whether the paired reversal maps the set onto itself while flipping
        /// every time sign.
        ///
        /// When it does, the two families are one family seen through a
        /// transformation that satisfies every condition imposed on a crossing:
        /// it is an isometry of both metrics and its determinant is one. Nothing
        /// in those conditions can then prefer one family.
        static bool familiesDifferByPairedReversal(const std::vector<Branch> &branches);

        /// Whether the given map is an isometry of both region metrics, which is
        /// what makes a candidate relation between the families admissible on
        /// both sides rather than only on ours.
        static bool isIsometryOfBothRegions(const Matrix4 &map);

        /// Displacement produced on our clock by a unit far-side displacement,
        /// for the given branch. Its sign is the branch's time sign.
        static double ourTimeFromUnitFarSide(const Branch &branch);
    };

    /// Section computing whether the admissible crossings fix the direction of
    /// the displacement they produce on our clock.
    class CrossingBranchesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The admissible crossings do not fix which way the clock moves";
        }
        void run(Report &report) const override;
    };

}
