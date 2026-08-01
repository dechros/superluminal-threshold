#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section counting why the canonical quantisation route closes off on
    /// the far side.
    class CanonicalQuantization : public Section
    {
    public:
        /// Number of conjugate momentum components.
        /// \param regionII Selects the region.
        /// \return One in region I, three in region II.
        static int conjugateMomentumCount(bool regionII);

        /// Timelike directions left on a slice of constant first coordinate.
        /// \return Zero in region I, so the slice is spacelike; two in
        ///         region II, so it is not.
        static int timelikeDirectionsOnSlice(bool regionII);

        /// Whether the equal-time commutator balances its index count.
        static bool commutatorIndicesConsistent(bool regionII);

        std::string number() const override { return "14"; }
        std::string title() const override
        {
            return "Quantisation: three independent obstructions to the canonical route";
        }
        void run(Report &report) const override;
    };

}
