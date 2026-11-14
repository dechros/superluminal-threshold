#include "particle/TimeProjectionSection.h"
#include "particle/TimeProjection.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "particle/EnergyVector.h"
#include "physics/transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{

    void TimeProjectionSection::run(Report &report) const
    {
        using Character = TimeProjection::Character;
        const double c = 1.0;
        const double mu = 1.0;

        report.subsection("Which slots are times and which is space, on each side");
        report.check(std::format("  on the near side one slot is timelike, and it is slot {}",
                                 TimeProjection::isTimelike(false, 0) ? 0 : -1),
                     TimeProjection::isTimelike(false, 0) && !TimeProjection::isTimelike(false, 1) &&
                         !TimeProjection::isTimelike(false, 2) &&
                         !TimeProjection::isTimelike(false, 3));
        const std::array<int, 3> times = TimeProjection::farSideTimeSlots();
        report.check(std::format("  beyond the threshold three slots are timelike, {} {} and {}",
                                 times[0], times[1], times[2]),
                     TimeProjection::farSideSpaceSlot() == 3);

        report.subsection("What each far-side coordinate carries here");
        for (int slot = 0; slot < 4; ++slot)
        {
            const int image = TimeProjection::imageSlot(slot);
            const bool timeThere = TimeProjection::isTimelike(true, slot);
            const bool timeHere = TimeProjection::isTimelike(false, image);
            report.check(std::format("  the far-side slot {} is {} and lands on near-side slot "
                                     "{}, which is {}",
                                     slot, timeThere ? "a time " : "space", image,
                                     timeHere ? "the near-side time" : "a space direction"),
                         timeThere != timeHere);
        }
        report.check("so every coordinate changes character across the threshold, "
                     "with no slot keeping its kind",
                     !TimeProjection::isTimelike(true, TimeProjection::farSideSpaceSlot()) &&
                         TimeProjection::isTimelike(
                             false, TimeProjection::imageSlot(TimeProjection::farSideSpaceSlot())));

        report.subsection("The dictionary of motion");
        for (int slot = 0; slot < 4; ++slot)
        {
            const Character there = TimeProjection::farSideCharacter(slot);
            const Character here = TimeProjection::nearCharacter(TimeProjection::imageSlot(slot));
            report.check(std::format("  the far-side slot {}: {} there, {} on the slot it "
                                     "carries here",
                                     slot, TimeProjection::name(there),
                                     TimeProjection::name(here)),
                         there == here);
        }
        report.check("so freedom of motion is preserved slot by slot even though "
                     "the kind of coordinate is reversed: the far side's free times carry "
                     "the near side's free space directions",
                     TimeProjection::farSideCharacter(0) == Character::FreeMotion &&
                         TimeProjection::nearCharacter(TimeProjection::imageSlot(0)) ==
                             Character::FreeMotion);
        report.check("the directed coordinate is in mirror places: the near-side time is "
                     "the far side's single space axis, and both split into two senses "
                     "that no rotation connects",
                     TimeProjection::nearCharacter(0) == Character::Directed &&
                         TimeProjection::farSideCharacter(TimeProjection::farSideSpaceSlot()) ==
                             Character::Directed &&
                         TimeProjection::imageSlot(TimeProjection::farSideSpaceSlot()) == 0);

        report.subsection("Moving in the far-side times does not move the near-side time directly");
        report.check("a displacement lying wholly within the three far-side times "
                     "produces no displacement in the near-side time slot",
                     !TimeProjection::timeMotionThereMovesNearTime());
        report.check("while a displacement along the far side's single space axis is "
                     "exactly a displacement in the near-side time",
                     TimeProjection::spaceMotionThereMovesNearTime());
        for (int slot : TimeProjection::farSideTimeSlots())
        {
            TimeProjection::Four step{};
            step[static_cast<std::size_t>(slot)] = 1.0;
            const TimeProjection::Four image = TimeProjection::toNearCoordinates(step);
            report.checkNear(std::format("  a unit step in the far-side time {} moves the "
                                         "near-side space, not the near-side "
                                         "clock",
                                         slot),
                             image[0], 1e-12);
        }

        report.subsection("What decides the size of the orientation");
        report.checkNear("the mass shell fixes the length, and rotating within the "
                         "three times leaves it alone",
                         EnergyVector::length(
                             EnergyVector::rotateInPlane({1.0, 2.0, 2.0}, 1, 0.9)) -
                             3.0,
                         1e-12);
        report.check("so the length is not a free choice of the particle but is "
                     "set by its energy and mass, while the direction is free",
                     !EnergyVector::rotationChangesFrequency(c, mu, {1.0, 2.0, 2.0}));
    }
}
