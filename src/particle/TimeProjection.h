#pragma once

#include "core/Section.h"

#include <array>
#include <string>

namespace slm
{

    /// What each coordinate on the far side becomes here, and how many
    /// dimensions of its own character it shares that role with.
    ///
    /// The two metrics are diag(1,-1,-1,-1) and diag(1,1,1,-1). Two
    /// self-inverse maps carry one to the negative of the other: a plain
    /// axis swap, and that same swap with the sign flipped on the pair of
    /// slots the near-side time and the far-side space axis occupy. Both
    /// pass every structural test available (the metric relation,
    /// involution, unit determinant), and nothing in those tests picks
    /// between them; this class computes on the one whose sign the study's
    /// results are stated in. Reading either off slot by slot gives the
    /// same dictionary for which coordinate carries which: the three
    /// positive slots beyond the threshold are times and they carry the
    /// near side's three space directions, while the one negative slot
    /// there is a space direction and it carries the near-side time. Only
    /// the sign on that carried pair depends on which of the two maps is
    /// used.
    ///
    /// A set of three same-signed axes admits a continuous rotation from any
    /// unit vector to its own negative, so no consistent split into two senses
    /// exists there. A single axis admits no such rotation, so it does split
    /// into two senses. This class labels character by that count alone; it
    /// does not assert that either sense is inaccessible to a mechanism
    /// supplied elsewhere.
    ///
    /// The question this leaves is whether an orientation among their three
    /// times can move the time coordinate of the return event here directly,
    /// that is through the involution alone rather than through whatever
    /// process reads a moment off the far-side state. These functions show
    /// that it cannot: such an orientation lands in the near-side space, not
    /// in the near-side time.
    class TimeProjection
    {
    public:
        using Four = std::array<double, 4>;
        using Three = std::array<double, 3>;

        /// What a coordinate is used for in the region it belongs to.
        enum class Character
        {
            FreeMotion, ///< Three same-signed axes; a continuous rotation reaches either sense.
            Directed,   ///< One axis; the two senses are not connected by any rotation.
            OrientationOnly ///< A direction can be taken in it, but no displacement is observable.
        };

        static std::string name(Character character);

        /// Sign of the metric on the given slot, positive for the region's
        /// time-like slots.
        /// \param farSide Selects the region.
        static double metricSign(bool farSide, int slot);

        /// Slot of the near-side coordinates that the given far-side slot carries.
        static int imageSlot(int farSideSlot);

        /// Whether the given slot is time-like in its own region.
        static bool isTimelike(bool farSide, int slot);

        /// Character of the given far-side slot, decided from the metric
        /// signs and from whether displacement along it is observable here.
        static Character farSideCharacter(int slot);

        /// Character of the given near-side slot.
        static Character nearCharacter(int slot);

        /// Push a far-side displacement through the involution.
        static Four toNearCoordinates(const Four &farSide);

        /// The single far-side slot that is space-like, which is the one
        /// carrying the near-side time.
        static int farSideSpaceSlot();

        /// The three far-side slots that are time-like.
        static std::array<int, 3> farSideTimeSlots();

        /// Whether a displacement purely within the three far-side times
        /// produces any displacement in the near-side time.
        static bool timeMotionThereMovesNearTime();

        /// Whether a displacement along the far side's single space axis
        /// produces a displacement in the near-side time.
        static bool spaceMotionThereMovesNearTime();
    };

    /// Section computing what motion along each far-side coordinate means here.
    class TimeProjectionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Which coordinates can be moved in, which only flow, and what that means here";
        }
        void run(Report &report) const override;
    };

}
