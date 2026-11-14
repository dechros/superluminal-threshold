#include "physics/transform/RelabellingObstruction.h"

#include "core/Report.h"
#include "physics/dynamics/ThresholdField.h"

#include <cmath>
#include <numbers>
#include <format>

namespace slm
{

    int RelabellingObstruction::freeDirections(const Matrix4 &metric, double mu)
    {
        int count = 0;
        for (int axis = 0; axis < 4; ++axis)
        {
            const double entry = metric.at(axis, axis);
            if (entry * mu > 0.0)
            {
                ++count;
            }
        }
        return count;
    }

    double RelabellingObstruction::axisMomentum(const Matrix4 &metric, double mu, int axis)
    {
        const double entry = metric.at(axis, axis);
        if (entry * mu <= 0.0)
        {
            return 0.0;
        }
        return std::sqrt(mu / entry);
    }

    int RelabellingObstruction::positiveEntries(double theta)
    {
        int count = 0;
        for (double entry : ThresholdField::metric(theta))
        {
            if (entry > 0.0)
            {
                ++count;
            }
        }
        return count;
    }
}
