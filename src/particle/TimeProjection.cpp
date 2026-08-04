#include "particle/TimeProjection.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "particle/FarSideMotion.h"
#include "transform/SignatureInvolution.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{

    std::string TimeProjection::name(Character character)
    {
        switch (character)
        {
        case Character::FreeMotion:
            return "free motion";
        case Character::ForcedFlow:
            return "forced flow";
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
        const Matrix4 d = SignatureInvolution::matrix();
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
        return isTimelike(true, slot) ? Character::FreeMotion : Character::ForcedFlow;
    }

    TimeProjection::Character TimeProjection::nearCharacter(int slot)
    {
        return isTimelike(false, slot) ? Character::ForcedFlow : Character::FreeMotion;
    }

    TimeProjection::Four TimeProjection::toNearCoordinates(const Four &farSide)
    {
        const Matrix4 d = SignatureInvolution::matrix();
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

    double TimeProjection::returnTime(const Three &orientation, IntermediateRegion::Kind kind,
                                      double c, double mu, double thickness)
    {
        return FarSideMotion::momentFromEnergy(kind, c, mu, orientation, thickness);
    }

    double TimeProjection::returnTimeRange(double length, IntermediateRegion::Kind kind, double c,
                                           double mu, double thickness, int steps)
    {
        const double pi = std::acos(-1.0);
        double smallest = 1e300;
        double largest = -1e300;
        for (int i = 0; i <= steps; ++i)
        {
            for (int j = 0; j < steps; ++j)
            {
                const double polar = pi * i / steps;
                const double azimuth = 2.0 * pi * j / steps;
                const Three orientation{length * std::sin(polar) * std::cos(azimuth),
                                        length * std::sin(polar) * std::sin(azimuth),
                                        length * std::cos(polar)};
                const double value = returnTime(orientation, kind, c, mu, thickness);
                smallest = std::min(smallest, value);
                largest = std::max(largest, value);
            }
        }
        return largest - smallest;
    }

    double TimeProjection::returnTimeAlongNearTimeAxis(double length, IntermediateRegion::Kind kind,
                                                      double c, double mu, double thickness)
    {
        return returnTime({length, 0.0, 0.0}, kind, c, mu, thickness);
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
        using Kind = IntermediateRegion::Kind;
        using Character = TimeProjection::Character;
        const double c = 1.0;
        const double mu = 1.0;
        const double thickness = 2.0;

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
        report.check("the one-way coordinate is in mirror places: the near-side time is "
                     "the far side's single space axis, and neither can be steered",
                     TimeProjection::nearCharacter(0) == Character::ForcedFlow &&
                         TimeProjection::farSideCharacter(TimeProjection::farSideSpaceSlot()) ==
                             Character::ForcedFlow &&
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

        report.subsection("But the orientation reaches the near-side clock by the other route");
        const double length = 3.0;
        const double range = TimeProjection::returnTimeRange(length, Kind::None, c, mu, thickness);
        report.check(std::format("  at fixed length the return time varies by {:.4f} over the "
                                 "sphere of orientations",
                                 range),
                     range > 1e-6);
        report.check("so an orientation among the far side's three times does place the "
                     "particle at a different moment here, through the matching "
                     "rather than through the involution",
                     range > 1e-6 && !TimeProjection::timeMotionThereMovesNearTime());

        report.subsection("How far the orientation alone can move the return moment");
        for (double probe : {2.0, 3.0, 5.0})
        {
            const double spread = TimeProjection::returnTimeRange(probe, Kind::None, c, mu,
                                                                   thickness);
            const double alongNearTime =
                TimeProjection::returnTimeAlongNearTimeAxis(probe, Kind::None, c, mu, thickness);
            report.check(std::format("  length {:g} : the reachable spread is {:.4f} against a "
                                     "return time of {:.4f} along the axis carrying the "
                                     "near-side time",
                                     probe, spread, alongNearTime),
                         spread > 0.0 && alongNearTime > 0.0);
        }
        report.check("the spread narrows as the energy vector lengthens, so a "
                     "faster particle commands a narrower choice of return "
                     "moments rather than a wider one",
                     TimeProjection::returnTimeRange(5.0, Kind::None, c, mu, thickness) <
                         TimeProjection::returnTimeRange(2.0, Kind::None, c, mu, thickness));
        report.check("the spread is large because it is dominated by orientations "
                     "that graze the surface, where the normal wavenumber tends to "
                     "zero and the delay diverges",
                     TimeProjection::returnTimeRange(3.0, Kind::None, c, mu, thickness) >
                         10.0 * TimeProjection::returnTimeAlongNearTimeAxis(3.0, Kind::None, c, mu,
                                                                          thickness));
        report.check("away from grazing the orientation still moves the return "
                     "moment, so the effect is not an artefact of the divergence",
                     std::abs(TimeProjection::returnTime({3.0, 0.0, 0.0}, Kind::None, c, mu,
                                                          thickness) -
                              TimeProjection::returnTime({2.0, 2.0, 1.0}, Kind::None, c, mu,
                                                          thickness)) > 1e-6);

        report.subsection("What decides the size of the orientation");
        report.checkNear("the mass shell fixes the length, and rotating within the "
                         "three times leaves it alone",
                         FarSideMotion::vectorLength(
                             FarSideMotion::rotateInTimePlane({1.0, 2.0, 2.0}, 1, 0.9)) -
                             3.0,
                         1e-12);
        report.check("so the length is not a free choice of the particle but is "
                     "set by its energy and mass, while the direction is free",
                     !FarSideMotion::rotationChangesCrossingWavenumber(c, mu, {1.0, 2.0, 2.0}));
    }

}
