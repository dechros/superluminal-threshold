#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

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
    /// our three space directions, while the one negative slot there is a
    /// space direction and it carries our time.
    ///
    /// The consequence is that the two sides are one-way in mirror places. Our
    /// time flows one way and cannot be steered; so does their single space
    /// axis, and it is the same coordinate. Their three times are free in the
    /// way our three space directions are free.
    ///
    /// The question this leaves is whether an orientation among their three
    /// times can move the time coordinate of the return event here. Directly it
    /// cannot, because that orientation lands in our space. Indirectly it can,
    /// because the transverse components of the same vector enter the matching
    /// at the two surfaces and therefore the phase the return moment is read
    /// from. These functions separate the two routes and measure the second.
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

        /// Slot of our own coordinates that the given far-side slot carries.
        static int imageSlot(int farSideSlot);

        /// Whether the given slot is time-like in its own region.
        static bool isTimelike(bool farSide, int slot);

        /// Character of the given far-side slot, decided from the metric
        /// signs and from whether displacement along it is observable here.
        static Character farSideCharacter(int slot);

        /// Character of the given slot of ours.
        static Character ourCharacter(int slot);

        /// Push a far-side displacement through the involution.
        static Four toOurCoordinates(const Four &farSide);

        /// The single far-side slot that is space-like, which is the one
        /// carrying our time.
        static int farSideSpaceSlot();

        /// The three far-side slots that are time-like.
        static std::array<int, 3> farSideTimeSlots();

        /// Time coordinate of the return event for a given orientation of the
        /// far-side energy vector, at fixed length.
        static double returnTime(const Three &orientation, IntermediateRegion::Kind kind, double c,
                                 double mu, double thickness);

        /// Largest and smallest return time over the sphere of orientations at
        /// fixed length, which is the range an orientation alone commands.
        static double returnTimeRange(double length, IntermediateRegion::Kind kind, double c,
                                      double mu, double thickness, int steps = 24);

        /// Return time at the orientation pointing along the slot that carries
        /// our own time under the involution.
        static double returnTimeAlongOurTimeAxis(double length, IntermediateRegion::Kind kind,
                                                 double c, double mu, double thickness);

        /// Whether a displacement purely within the three far-side times
        /// produces any displacement in our time.
        static bool timeMotionThereMovesOurTime();

        /// Whether a displacement along the far side's single space axis
        /// produces a displacement in our time.
        static bool spaceMotionThereMovesOurTime();
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
