#pragma once

#include "core/Section.h"

namespace slm
{

    /// What a region that reverses time looks like from outside it, when the
    /// only thing available is a count at the boundary.
    ///
    /// A body that enters a region where the time orientation fails and comes
    /// back cannot be followed through. What an outside observer has instead is
    /// bookkeeping at the boundary: how many worldlines cross it, in which
    /// direction, and what they carry. Two consequences of that bookkeeping are
    /// standard, and both bear on a question this work leaves open, namely
    /// whether a returning particle can be told from a freshly created pair.
    ///
    /// The first is that a failure of time orientability looks like a pair
    /// event. A worldline that enters the region running forward and leaves it
    /// running backward is, to an observer who insists on a single time
    /// direction, two worldlines meeting the boundary: one arriving and one
    /// arriving, or one leaving and one leaving, never one of each. So the
    /// boundary count changes by two rather than by zero, and it changes in the
    /// same way an annihilation or a creation would.
    ///
    /// The second is that the same boundary carries a net flux even when
    /// nothing is created. Reversing a worldline's time sense reverses the sign
    /// of what it carries, so a region that reverses time presents an apparent
    /// charge to the outside, whose size is fixed by how many lines are turned
    /// and not by any charge placed there.
    ///
    /// These functions compute both from the same count, so the relation
    /// between them is arithmetic rather than analogy, and then ask the
    /// question this work needs: whether the two readings differ in anything an
    /// outside observer could measure.
    class TimeReversalSignature
    {
    public:
        /// Change in the number of worldlines crossing the boundary in the
        /// forward sense, when the given number of lines are turned round
        /// inside.
        static int forwardCountChange(int turnedLines);

        /// Change in the number crossing in the backward sense.
        static int backwardCountChange(int turnedLines);

        /// Net flux the boundary presents, which is the apparent charge.
        static double apparentCharge(int turnedLines, double chargePerLine);

        /// Whether the boundary count changes by an even number, which is what
        /// makes a turned line indistinguishable from a pair event.
        static bool changeIsEven(int turnedLines);

        /// Count an observer records for a genuine pair creation of the given
        /// number of pairs.
        static int pairCreationCount(int pairs);

        /// Whether a turned line and a created pair give the same boundary
        /// count, which is the degeneracy this work carries as open.
        static bool countsAreDegenerate(int turnedLines);

        /// Whether the apparent charge distinguishes them, which it does not
        /// when the charge per line is the same on both readings.
        static bool chargeDistinguishes(int turnedLines, double chargePerLine);

        /// Energy the two readings assign, which is where they part company:
        /// a created pair costs twice the rest energy and a turned line costs
        /// nothing.
        static double energyCost(bool isPair, double restEnergy, int turnedLines);

        /// Whether energy tells them apart, which it does, and which is the
        /// one measurement that would close the degeneracy.
        static bool energyDistinguishes(double restEnergy, int turnedLines);
    };

    /// Section computing what a time-reversing boundary shows an outside
    /// observer, and which of the two readings a measurement could pick out.
    class TimeReversalSignatureSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A turned worldline and a created pair, seen only at the boundary";
        }
        void run(Report &report) const override;
    };

}
