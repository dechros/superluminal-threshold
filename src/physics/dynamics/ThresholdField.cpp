#include "physics/dynamics/ThresholdField.h"

#include "core/Report.h"

#include <cmath>
#include <numbers>
#include <format>

namespace slm
{
    ThresholdField::Diagonal ThresholdField::regionOneMetric()
    {
        return {1.0, -1.0, -1.0, -1.0};
    }

    ThresholdField::Diagonal ThresholdField::metric(double theta)
    {
        const double scale = std::cos(2.0 * theta);
        const auto base = regionOneMetric();
        return {base[0] * scale, base[1] * scale, base[2] * scale, base[3] * scale};
    }

    bool ThresholdField::isDegenerate(double theta, double tolerance)
    {
        for (double entry : metric(theta))
        {
            if (std::abs(entry) > tolerance)
            {
                return false;
            }
        }
        return true;
    }

    double ThresholdField::requiredMomentumSquared(double theta, double mu, double energySquared)
    {
        return std::cos(2.0 * theta) * (energySquared - mu);
    }
}
