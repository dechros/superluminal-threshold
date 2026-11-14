#include "particle/VelocityCrossing.h"

#include "core/Report.h"
#include "physics/dynamics/ThresholdField.h"
#include "particle/ContinuousCrossing.h"
#include "physics/transform/SignatureInvolution.h"

#include <cmath>
#include <numbers>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kPi = std::numbers::pi;
    }

    double VelocityCrossing::angleFromSpeed(double beta)
    {
        return std::atan(beta);
    }

    double VelocityCrossing::speedFromAngle(double theta)
    {
        return std::tan(theta);
    }

    double VelocityCrossing::metricScale(double beta)
    {
        return (1.0 - beta * beta) / (1.0 + beta * beta);
    }

    double VelocityCrossing::lorentzFactor(double theta)
    {
        return std::cos(theta) / std::sqrt(std::cos(2.0 * theta));
    }

    double VelocityCrossing::standardAngle(double c, double acceleration, double properTime)
    {
        return std::atan(std::tanh(acceleration * properTime / c));
    }

    double VelocityCrossing::standardAngularRate(double c, double acceleration,
                                                 double properTime)
    {
        const double u = acceleration * properTime / c;
        const double sech = 1.0 / std::cosh(u);
        const double tanh = std::tanh(u);
        return (acceleration / c) * sech * sech / (1.0 + tanh * tanh);
    }

    double VelocityCrossing::standardEnergy(double theta)
    {
        return lorentzFactor(theta);
    }

    double VelocityCrossing::regularisedEnergy(double theta)
    {
        const double cosine = std::cos(theta);
        return cosine * cosine;
    }

    double VelocityCrossing::momentumAtLightSpeed(double c, double mu, double force)
    {
        return c * std::sqrt(mu + force * kPi / 2.0);
    }

    double VelocityCrossing::luminalParameter(double c, double mu, double force)
    {
        return ContinuousCrossing::sigmaToReach(c, mu, force, kPi / 4.0);
    }

    double VelocityCrossing::speedAtParameter(double c, double mu, double force, double sigma)
    {
        return speedFromAngle(ContinuousCrossing::theta(c, mu, force, sigma));
    }

    double VelocityCrossing::returningSpeedAtParameter(double c, double mu, double force,
                                                       double sigma)
    {
        return speedFromAngle(ContinuousCrossing::thetaReturning(c, mu, force, sigma));
    }

    double VelocityCrossing::returnToSubluminalParameter(double c, double mu, double force)
    {
        return ContinuousCrossing::sigmaToReach(c, mu, force, kPi / 2.0) -
               luminalParameter(c, mu, force);
    }
}
