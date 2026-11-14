#include "particle/ContinuousCrossing.h"

#include "core/Report.h"
#include "particle/ConstantForce.h"

#include <cmath>
#include <numbers>
#include <format>

namespace slm
{
    double ContinuousCrossing::entryMomentum(double c, double mu)
    {
        return ConstantForce::entryMomentum(c, mu);
    }

    double ContinuousCrossing::theta(double c, double mu, double force, double sigma)
    {
        return ConstantForce::coordinate(c, mu, force, 0.0, sigma);
    }

    double ContinuousCrossing::conjugateMomentum(double c, double mu, double force, double sigma)
    {
        return ConstantForce::momentum(c, mu, force, sigma);
    }

    double ContinuousCrossing::constraintResidual(double c, double mu, double force, double sigma)
    {
        return ConstantForce::residual(c, mu, force, 0.0, theta(c, mu, force, sigma),
                                       conjugateMomentum(c, mu, force, sigma));
    }

    double ContinuousCrossing::sigmaToReach(double c, double mu, double force, double target)
    {
        return ConstantForce::parameterToReach(c, mu, force, 0.0, target);
    }

    double ContinuousCrossing::thetaReturning(double c, double mu, double force, double sigma)
    {
        const double crossing = sigmaToReach(c, mu, force, std::numbers::pi / 2.0);
        return theta(c, mu, force, crossing - sigma);
    }
}
