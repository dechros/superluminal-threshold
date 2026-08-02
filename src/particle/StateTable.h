#pragma once

#include "core/Section.h"

#include <array>
#include <string>

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
    /// The table is filled by computing, for each cell, what an observer on our
    /// side measures. The result the article has to face is that most cells are
    /// degenerate with ordinary processes, so the dictionary says as much about
    /// what cannot be told apart as about what can.
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

        /// Our four-momentum after the journey, for a given turn.
        static Four returned(const Four &ours, Turn turn);

        /// Change in our energy over the journey, which the model says is zero.
        static double energyChange(const Four &ours, Turn turn);

        /// Change in the magnitude of our momentum, also zero.
        static double speedChange(const Four &ours, Turn turn);

        /// Deflection of our momentum, in radians.
        static double deflection(const Four &ours, Turn turn);

        /// Whether an ordinary elastic process on our own side could produce
        /// the same measurement, which is what decides if the cell is a
        /// prediction or only an interpretation.
        static bool degenerateWithOrdinaryPhysics(Exit exit, Turn turn);
    };

    /// Section filling the table and reading it as a dictionary.
    class StateTableSection : public Section
    {
    public:
        std::string number() const override { return "18"; }
        std::string title() const override
        {
            return "What can happen over there, and what each one looks like here";
        }
        void run(Report &report) const override;
    };

}
