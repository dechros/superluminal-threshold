#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// What a closed loop needs before its return can precede its departure.
    ///
    /// The claim that covering distance faster than light reaches an earlier
    /// moment is old, and so is the objection to the naive form of it: an out and
    /// back trip at superluminal speed, described throughout in one frame, returns
    /// later than it left, not earlier. The published counterexample matters here
    /// because the account this class belongs to also describes an out and back
    /// trip, so the difference has to be located rather than assumed.
    ///
    /// Three routes to the same event are compared. The first is that naive loop.
    /// The second is the relay: the outbound leg is superluminal in one frame and
    /// the return leg is superluminal in the frame of a relay that is itself in
    /// motion, which is the construction the objection leaves standing. The third
    /// is the route built here, where the return moment is a bounded delay
    /// against a displacement covered on the far side.
    ///
    /// The quantity that separates them is the relative velocity the loop needs.
    /// The relay reaches the past only above a threshold velocity that is positive
    /// for every finite superluminal speed, so it needs two frames in relative
    /// motion and inherits its sign from the disagreement between them. The naive
    /// loop is the same construction at zero relative velocity, which is why it
    /// fails. The third route is computed at zero relative velocity throughout and
    /// still reaches the past, because its sign comes from which crossing is
    /// realised rather than from a frame mismatch.
    ///
    /// Units are those in which the speed in the outer region is one.
    class LoopClosure
    {
    public:
        /// Return moment of an out and back trip at one superluminal speed,
        /// described in a single frame.
        static double sameFrameReturn(double distance, double speed);

        /// Return moment when the return leg is superluminal in the frame of a
        /// relay moving at @p relayVelocity, the outbound leg being superluminal
        /// in the original frame.
        static double relayReturn(double distance, double speed, double relayVelocity);

        /// Least relay velocity at which the relay route returns before it left.
        static double relayThreshold(double speed);

        /// Whether the relay route returns before it left.
        static bool relayReachesPast(double distance, double speed, double relayVelocity);

        /// Return moment of the route built here, on the branch that carries the
        /// displacement backwards, with no relative velocity anywhere in it.
        static double crossingReturn(IntermediateRegion::Kind kind, double c, double mu,
                                     double thickness, double distance);

        /// Whether that route returns before it left.
        static bool crossingReachesPast(IntermediateRegion::Kind kind, double c, double mu,
                                       double thickness, double distance);
    };

    /// Section locating what the loop needs before it can close on the past.
    class LoopClosureSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What a loop needs before it can close on the past";
        }
        void run(Report &report) const override;
    };

}
