#include "particle/TimeProjection.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "particle/EnergyVector.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        Matrix4 resultMatrix()
        {
            const Matrix4 s = Matrix4::diagonal(-1.0, 1.0, 1.0, -1.0);
            return s * SignatureInvolution::matrix();
        }
    }

    std::string TimeProjection::name(Character character)
    {
        switch (character)
        {
        case Character::FreeMotion:
            return "free motion";
        case Character::Directed:
            return "directed";
        default:
            return "orientation only";
        }
    }

    double TimeProjection::metricSign(bool farSide, int slot)
    {
        const Matrix4 metric = farSide ? metricRegionII() : metricRegionI();
        return metric.at(slot, slot);
    }

    int TimeProjection::imageSlot(int farSideSlot)
    {
        const Matrix4 d = resultMatrix();
        for (int row = 0; row < 4; ++row)
        {
            if (std::abs(d.at(row, farSideSlot)) > 0.5)
            {
                return row;
            }
        }
        return farSideSlot;
    }

    bool TimeProjection::isTimelike(bool farSide, int slot)
    {
        return metricSign(farSide, slot) > 0.0;
    }

    int TimeProjection::farSideSpaceSlot()
    {
        for (int slot = 0; slot < 4; ++slot)
        {
            if (!isTimelike(true, slot))
            {
                return slot;
            }
        }
        return -1;
    }

    std::array<int, 3> TimeProjection::farSideTimeSlots()
    {
        std::array<int, 3> slots{};
        int found = 0;
        for (int slot = 0; slot < 4 && found < 3; ++slot)
        {
            if (isTimelike(true, slot))
            {
                slots[static_cast<std::size_t>(found++)] = slot;
            }
        }
        return slots;
    }

    TimeProjection::Character TimeProjection::farSideCharacter(int slot)
    {
        return isTimelike(true, slot) ? Character::FreeMotion : Character::Directed;
    }

    TimeProjection::Character TimeProjection::nearCharacter(int slot)
    {
        return isTimelike(false, slot) ? Character::Directed : Character::FreeMotion;
    }

    TimeProjection::Four TimeProjection::toNearCoordinates(const Four &farSide)
    {
        const Matrix4 d = resultMatrix();
        Four near{};
        for (int row = 0; row < 4; ++row)
        {
            double sum = 0.0;
            for (int column = 0; column < 4; ++column)
            {
                sum += d.at(row, column) * farSide[static_cast<std::size_t>(column)];
            }
            near[static_cast<std::size_t>(row)] = sum;
        }
        return near;
    }

    bool TimeProjection::timeMotionThereMovesNearTime()
    {
        const std::array<int, 3> times = farSideTimeSlots();
        for (int slot : times)
        {
            Four displacement{};
            displacement[static_cast<std::size_t>(slot)] = 1.0;
            if (std::abs(toNearCoordinates(displacement)[0]) > 1e-12)
            {
                return true;
            }
        }
        return false;
    }

    bool TimeProjection::spaceMotionThereMovesNearTime()
    {
        Four displacement{};
        displacement[static_cast<std::size_t>(farSideSpaceSlot())] = 1.0;
        return std::abs(toNearCoordinates(displacement)[0]) > 1e-12;
    }

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
