#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <array>
#include <vector>

namespace slm
{

    /// Section that brute forces every signed permutation matrix and keeps
    /// the ones satisfying the metric relation.
    class PermutationScan : public Section
    {
    public:
        /// One candidate produced by the scan, kept together with the
        /// permutation and signs that generated it.
        struct Candidate
        {
            /// permutation[r] is the input axis taken by row r.
            std::array<int, 4> permutation{};
            /// Sign applied to that entry, +1 or -1.
            std::array<int, 4> signs{};
            Matrix4 matrix;
        };

        /// Every signed permutation matrix passing the metric test.
        /// \return The surviving candidates, in scan order.
        static std::vector<Candidate> metricPreserving();

        /// The candidates surviving all three filters: the metric relation,
        /// involution, and unit determinant.
        /// \return The eight surviving candidates, in scan order.
        static std::vector<Candidate> admissible();

        std::string title() const override
        {
            return "Scan over the 384 signed permutation matrices";
        }
        void run(Report &report) const override;
    };

}
