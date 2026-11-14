#include "particle/ConstantForce.h"

#include <cmath>

namespace slm
{
    double ConstantForce::entryMomentum(double c, double shellAtStart)
    {
        return -c * std::sqrt(shellAtStart);
    }

    double ConstantForce::coordinate(double c, double shellAtStart, double force, double start,
                                     double sigma)
    {
        const double p0 = entryMomentum(c, shellAtStart);
        return start + force * sigma * sigma / (2.0 * c * c) - p0 * sigma / (c * c);
    }

    double ConstantForce::momentum(double c, double shellAtStart, double force, double sigma)
    {
        return entryMomentum(c, shellAtStart) - force * sigma;
    }

    double ConstantForce::residual(double c, double shellAtStart, double force, double start,
                                   double coordinate, double momentum)
    {
        return shellAtStart + 2.0 * force * (coordinate - start) - momentum * momentum / (c * c);
    }

    double ConstantForce::parameterToReach(double c, double shellAtStart, double force,
                                           double start, double target)
    {
        const double a = force / (2.0 * c * c);
        const double b = -entryMomentum(c, shellAtStart) / (c * c);
        const double rise = target - start;
        const double disc = b * b + 4.0 * a * rise;
        return 2.0 * rise / (b + std::sqrt(disc));
    }
}
