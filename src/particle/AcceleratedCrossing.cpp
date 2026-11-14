#include "particle/AcceleratedCrossing.h"

#include "core/Report.h"
#include "particle/ConstantForce.h"
#include "particle/EnergyVector.h"
#include "particle/TimeProjection.h"
#include "physics/units/PhysicalScales.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        double shellAtEntry(double mu, const AcceleratedCrossing::Three &energy)
        {
            const double magnitude = EnergyVector::length(energy);
            return magnitude * magnitude + mu;
        }
    }

    double AcceleratedCrossing::entryMomentum(double c, double mu, const Three &energy)
    {
        return ConstantForce::entryMomentum(c, shellAtEntry(mu, energy));
    }

    double AcceleratedCrossing::position(double c, double mu, const Three &energy, double force,
                                         double sigma)
    {
        return ConstantForce::coordinate(c, shellAtEntry(mu, energy), force, 0.0, sigma);
    }

    double AcceleratedCrossing::conjugateMomentum(double c, double mu, const Three &energy,
                                                  double force, double sigma)
    {
        return ConstantForce::momentum(c, shellAtEntry(mu, energy), force, sigma);
    }

    double AcceleratedCrossing::constraintResidual(double c, double mu, const Three &energy,
                                                   double force, double sigma)
    {
        return ConstantForce::residual(c, shellAtEntry(mu, energy), force, 0.0,
                                       position(c, mu, energy, force, sigma),
                                       conjugateMomentum(c, mu, energy, force, sigma));
    }

    double AcceleratedCrossing::parameterToReach(double c, double mu, const Three &energy,
                                                 double force, double target)
    {
        return ConstantForce::parameterToReach(c, shellAtEntry(mu, energy), force, 0.0, target);
    }
}
