#pragma once

#include "core/Section.h"

#include <array>
#include <string>
#include <vector>

namespace slm
{

    /// Everything the particle can do over there, and what each one looks like
    /// here.
    ///
    /// Two independent labels exhaust the cases. The first is which face the
    /// particle leaves by, since the intermediate region has two and it may
    /// leave by neither. The second is how far its far-side energy vector has
    /// turned between entry and exit, which is the only thing about its
    /// orientation that is not pure gauge.
    ///
    /// Each cell is filled by computing what an observer on the subluminal
    /// side measures. Most cells turn out degenerate with ordinary processes,
    /// so the table records what cannot be told apart as well as what can.
    class StateTable
    {
    public:
        using Four = std::array<double, 4>;

        enum class Exit
        {
            EntryFace,
            FarFace,
            Never
        };

        enum class Turn
        {
            None,
            Partial,
            Reversal
        };

        static std::string name(Exit exit);
        static std::string name(Turn turn);

        /// Rotation angle each turn class stands for.
        static double angle(Turn turn);

        /// The near-side four-momentum after the journey, for a given turn.
        static Four returned(const Four &near, Turn turn);

        /// Change in the near-side energy over the journey.
        static double energyChange(const Four &near, Turn turn);

        /// Change in the magnitude of the near-side momentum, also zero.
        static double speedChange(const Four &near, Turn turn);

        /// One reachable outcome of a round trip, as the two faces produce it:
        /// whether the near-side energy came back with the sign it left with, and how far
        /// the momentum turned.
        struct Outcome
        {
            bool energyKept;
            double deflection;
        };

        /// Distinct outcomes the admissible face pairings actually produce.
        /// The two labels of the table are not independent, since one pair of
        /// faces fixes both, so this is smaller than their product.
        static int reachableOutcomeCount(double px, double py, double pz);

        /// Outcomes counted by treating the two labels as independent, which
        /// is what a full table of cells would assume.
        static int independentLabelCount();

        /// Cells the flux calculation empties, namely the row in which the
        /// particle never leaves.
        static int emptyRowCells();

        /// Reachable outcomes in which the near-side energy came back with the sign it
        /// left with, which is the number of quantised turns available.
        static int outcomesKeepingEnergy(double px, double py, double pz);

        /// Reachable outcomes that return the energy with the opposite sign,
        /// which is the branch a pair-creation reading claims.
        static int outcomesFlippingEnergy(double px, double py, double pz);

        /// Outcomes with no ordinary counterpart: energy kept and the momentum
        /// nonetheless turned.
        static int discriminatingOutcomes(double px, double py, double pz);

        /// Deflection of the near-side momentum, in radians.
        static double deflection(const Four &near, Turn turn);

        /// Whether an ordinary elastic process on the near side could produce
        /// the same measurement, which is what decides if the cell is a
        /// prediction or only an interpretation.
        static bool degenerateWithOrdinaryPhysics(Exit exit, Turn turn);
    };

    /// Section filling the table and reading it as a dictionary.
    class StateTableSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What can happen over there, and what each one looks like here";
        }
        void run(Report &report) const override;
    };

}
