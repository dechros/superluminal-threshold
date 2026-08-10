#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <string>
#include <vector>

namespace slm
{

    /// Which time-sense each admissible signature-reversing matrix assigns
    /// to a step along the far side's single space axis.
    ///
    /// A matrix surviving the metric relation, involution and unit
    /// determinant is not thereby pinned to a physical direction: applying
    /// it to a positive step along that axis sends the near side's time
    /// coordinate one way, and nothing in those three filters says which
    /// way. This class applies each surviving matrix to both a positive and
    /// a negative unit step and reads the sign off the result, rather than
    /// assuming it. Reversing the step reverses the sign for every matrix
    /// here, because the map is linear; what varies matrix to matrix is
    /// which sign a positive step gets in the first place.
    class DirectionFamily : public Section
    {
    public:
        /// One admissible matrix, together with the near-side time it
        /// produces from a unit step each way along the far side's space
        /// axis.
        struct Outcome
        {
            Matrix4 matrix;
            double fromPositiveStep = 0.0; ///< Near-side time from a +1 step.
            double fromNegativeStep = 0.0; ///< Near-side time from a -1 step.

            /// Whether a positive step lands later (true) or earlier
            /// (false) on the near side.
            bool sendsLater() const;
        };

        /// One outcome per matrix admitted by PermutationScan::admissible(),
        /// in the same order.
        static std::vector<Outcome> outcomes();

        std::string title() const override
        {
            return "Which of the admissible matrices send a step later, and which earlier";
        }
        void run(Report &report) const override;
    };

}
