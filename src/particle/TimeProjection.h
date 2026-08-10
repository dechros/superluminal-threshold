#pragma once

#include "core/Section.h"

#include <array>
#include <string>

namespace slm
{

    /// What each coordinate on the far side becomes here, and whether motion
    /// along it is free, forced, or unavailable.
    ///
    /// The two metrics are diag(1,-1,-1,-1) and diag(1,1,1,-1), and the
    /// involution sends (ct, x, y, z) to (z, y, x, ct). Reading that off slot
    /// by slot gives the dictionary this class computes rather than asserts:
    /// the three positive slots beyond the threshold are times and they carry
    /// the near side's three space directions, while the one negative slot there is a
    /// space direction and it carries the near-side time.
    ///
    /// The consequence is that the two sides are one-way in mirror places. The near side's
    /// time flows one way and cannot be steered; so does the far side's single space
    /// axis, and it is the same coordinate. Their three times are free in the
    /// way the near side's three space directions are free.
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
            FreeMotion,    ///< Motion along it is free in both directions.
            ForcedFlow,    ///< Motion along it is one way and cannot be steered.
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
