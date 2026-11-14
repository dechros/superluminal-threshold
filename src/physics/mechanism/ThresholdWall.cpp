#include "physics/mechanism/ThresholdWall.h"

#include "core/Report.h"
#include "physics/dynamics/ThresholdField.h"

#include <cmath>
#include <numbers>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kPi = std::numbers::pi;
    }

    double ThresholdWall::potential(double lambdaScale, double theta)
    {
        const double s = std::sin(2.0 * theta);
        return lambdaScale * lambdaScale * lambdaScale * lambdaScale * s * s;
    }

    double ThresholdWall::potentialSlope(double lambdaScale, double theta)
    {
        const double quartic = lambdaScale * lambdaScale * lambdaScale * lambdaScale;
        return 2.0 * quartic * std::sin(4.0 * theta);
    }

    double ThresholdWall::widthFromCouplings(double stiffness, double lambdaScale)
    {
        const double quartic = lambdaScale * lambdaScale * lambdaScale * lambdaScale;
        return std::sqrt(stiffness / (8.0 * quartic));
    }

    double ThresholdWall::profile(double x, double width)
    {
        return std::atan(std::exp(x / width));
    }

    double ThresholdWall::slope(double x, double width)
    {
        return std::sin(2.0 * profile(x, width)) / (2.0 * width);
    }

    double ThresholdWall::tension(double stiffness, double width)
    {
        return stiffness / (2.0 * width);
    }

    double ThresholdWall::distanceToReach(double width, double tolerance)
    {
        return width * std::log(1.0 / std::tan(tolerance));
    }

    double ThresholdWall::massParameter(double mu, double force, double theta)
    {
        return mu + 2.0 * force * theta;
    }

    double ThresholdWall::restEnergyRatio(double mu, double force)
    {
        return std::sqrt(massParameter(mu, force, kPi / 2.0)) / std::sqrt(mu);
    }

    double ThresholdWall::smallestAdmissibleForce(double mu)
    {
        return -mu / kPi;
    }
}
