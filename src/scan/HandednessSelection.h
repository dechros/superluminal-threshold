#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <vector>

namespace slm
{

    /// The fourth filter, which removes the one choice the first three left
    /// open.
    ///
    /// Three filters cut the 384 signed permutations to 8, and those 8 split
    /// evenly: four send a step along the far side's space axis to a later
    /// near-side time, four send it to an earlier one. Nothing in the three
    /// filters decides between the halves, so the time difference that the
    /// whole construction is for was, until here, selected by hand.
    ///
    /// The filter added here is handedness. Three of the far side's
    /// coordinates carry free motion and land on the three near-side
    /// directions that also carry free motion; @ref freeBlockDeterminant is
    /// the determinant of that three by three block. A map reached as the
    /// endpoint of a continuous crossing cannot carry a reflection in those
    /// directions, because a reflection is not connected to the identity in the
    /// rotation group and the crossing never leaves the real path. Demanding
    /// the determinant be positive is therefore not an extra assumption but the
    /// statement that the discrete map is the limit of the continuous one.
    ///
    /// The demand settles the question, and it settles it in the direction the
    /// construction needed: the four maps with a proper free block are exactly
    /// the four that send a positive step to an earlier near-side time. The
    /// lock is exact and is checked over all eight in @ref run: the sign of the
    /// near-side time and the determinant of the free block always multiply to
    /// minus one, so fixing either fixes the other.
    class HandednessSelection
    {
    public:
        /// The determinant of the block carrying the far side's three times
        /// into the near side's three space directions.
        static double freeBlockDeterminant(const Matrix4 &matrix);

        /// The near-side time produced by a unit step along the far side's
        /// single space axis, which is the entry in row zero, column three.
        static double nearTimeCoefficient(const Matrix4 &matrix);

        /// True when the free block is a proper rotation rather than a
        /// reflection.
        static bool preservesHandedness(const Matrix4 &matrix);

        /// The admissible maps that survive the handedness filter.
        static std::vector<Matrix4> selected();

        /// The reflection exchanging the two families, the diagonal matrix
        /// reversing the near-side time and one near-side space direction. Its
        /// determinant is positive, which is why the third filter did not
        /// remove either family.
        static Matrix4 exchange();
    };

    /// Section verifying that handedness cuts the eight to four, that the four
    /// it keeps are the ones that recover time, and that the two families
    /// differ by a single reflection the earlier filters could not see.
    class HandednessSelectionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Handedness as a fourth filter, which leaves one family and makes the direction of the time difference a result rather than a choice";
        }
        void run(Report &report) const override;
    };

}
