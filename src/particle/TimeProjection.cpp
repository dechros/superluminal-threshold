#include "particle/TimeProjection.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "particle/EnergyVector.h"
#include "physics/transform/SignatureInvolution.h"

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

    TimeProjection::Four TimeProjection::toFarCoordinates(const Four &nearSide)
    {
        return toNearCoordinates(nearSide);
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
}
