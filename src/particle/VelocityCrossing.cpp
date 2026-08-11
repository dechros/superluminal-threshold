#include "particle/VelocityCrossing.h"

#include "core/Report.h"
#include "dynamics/ThresholdField.h"
#include "particle/ContinuousCrossing.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kPi = 3.14159265358979323846;
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
        return luminalParameter(c, mu, force);
    }

    void VelocityCrossingSection::run(Report &report) const
    {
        const double c = 1.0;

        report.subsection("The dictionary between speed and angle");
        report.checkNear("  rest is the angle zero", VelocityCrossing::angleFromSpeed(0.0), 1e-15);
        report.checkNear("  light speed is the angle pi/4, which is where the metric family "
                         "degenerates",
                         VelocityCrossing::angleFromSpeed(1.0) - kPi / 4.0, 1e-15);
        report.check("  and the metric family does degenerate there, which fixes the threshold "
                     "without either side being arranged to meet the other",
                     ThresholdField::isDegenerate(VelocityCrossing::angleFromSpeed(1.0), 1e-9));
        for (double beta : {0.0, 0.25, 0.5, 0.9, 0.99, 1.0, 1.5, 3.0, 100.0})
        {
            const double theta = VelocityCrossing::angleFromSpeed(beta);
            report.checkNear(std::format("  beta = {:g} : the scale factor from the speed and "
                                         "the cosine of twice the angle agree",
                                         beta),
                             VelocityCrossing::metricScale(beta) - std::cos(2.0 * theta), 1e-14);
            report.checkNear("    and the angle carries back to the speed it came from, to a "
                             "tolerance scaled by the speed itself",
                             (VelocityCrossing::speedFromAngle(theta) - beta) / (1.0 + beta),
                             1e-14);
        }
        report.check("  the scale factor is positive below light speed, zero at it and negative "
                     "above, so the sign of the metric is the sign of one minus the speed "
                     "squared",
                     VelocityCrossing::metricScale(0.5) > 0.0 &&
                         std::abs(VelocityCrossing::metricScale(1.0)) < 1e-15 &&
                         VelocityCrossing::metricScale(2.0) < 0.0);

        report.subsection("The Lorentz factor in the same variable");
        for (double beta : {0.1, 0.5, 0.9, 0.99, 0.999})
        {
            const double theta = VelocityCrossing::angleFromSpeed(beta);
            report.checkNear(std::format("  beta = {:g} : the angle form of the Lorentz factor "
                                         "matches the usual one",
                                         beta),
                             VelocityCrossing::lorentzFactor(theta) -
                                 1.0 / std::sqrt(1.0 - beta * beta),
                             1e-9);
        }

        report.subsection("Under the standard shell the accelerated particle does not arrive");
        const double acceleration = 1.0;
        double previousRate = 1e300;
        for (double properTime : {0.5, 1.0, 2.0, 4.0, 8.0, 16.0})
        {
            const double theta = VelocityCrossing::standardAngle(c, acceleration, properTime);
            const double rate = VelocityCrossing::standardAngularRate(c, acceleration,
                                                                      properTime);
            report.check(std::format("  proper time {:>4.1f} : the angle stands at {:.15f}, "
                                     "short of pi/4",
                                     properTime, theta),
                         theta < kPi / 4.0);
            report.check(std::format("    and the angle advances at {:.6e}, slower than before",
                                     rate),
                         rate < previousRate && rate > 0.0);
            previousRate = rate;
        }
        report.check("the angle stalls rather than the force failing, since the rate falls off "
                     "like the square of a hyperbolic secant and the accelerating force is "
                     "never withdrawn",
                     VelocityCrossing::standardAngularRate(c, acceleration, 16.0) <
                         1e-10 * VelocityCrossing::standardAngularRate(c, acceleration, 0.5));
        double previousEnergy = 0.0;
        for (double beta : {0.9, 0.99, 0.9999, 0.999999999999})
        {
            const double energy =
                VelocityCrossing::standardEnergy(VelocityCrossing::angleFromSpeed(beta));
            report.check(std::format("  reaching beta = {:.8f} costs {:.6e} rest energies, more "
                                     "than the step before",
                                     beta, energy),
                         energy > previousEnergy && std::isfinite(energy));
            previousEnergy = energy;
        }
        report.check(std::format("the demand grows without bound as the speed approaches light "
                                 "speed, standing at {:.6e} rest energies a part in a million "
                                 "million short of it, so acceleration under the standard shell "
                                 "reaches the threshold at no finite energy",
                                 previousEnergy),
                     previousEnergy > 1e5);

        report.subsection("Where the obstruction sits");
        for (double theta : {0.1, 0.5, kPi / 4.0 - 1e-6, kPi / 4.0})
        {
            report.checkNear(std::format("  theta = {:.6f} : the energy weighed against the "
                                         "degenerating metric is the squared cosine of the "
                                         "angle",
                                         theta),
                             VelocityCrossing::regularisedEnergy(theta) -
                                 std::cos(theta) * std::cos(theta),
                             1e-15);
        }
        report.checkNear("at light speed that quantity is exactly one half, so what diverges is "
                         "the energy measured with the near-side metric and not the energy "
                         "itself",
                         VelocityCrossing::regularisedEnergy(kPi / 4.0) - 0.5, 1e-15);
        report.checkNear("  and the divergent factor is the very one that degenerates the "
                         "metric, since the standard energy squared times the scale factor is "
                         "that same finite quantity",
                         VelocityCrossing::standardEnergy(0.6) *
                                 VelocityCrossing::standardEnergy(0.6) * std::cos(1.2) -
                             VelocityCrossing::regularisedEnergy(0.6),
                         1e-12);

        report.subsection("Under the extended shell the accelerated particle arrives");
        const double mu = 1.0;
        int arrivals = 0;
        for (double testMu : {0.25, 1.0, 4.0})
        {
            for (double force : {0.05, 0.4, 3.0})
            {
                const double luminal = VelocityCrossing::luminalParameter(c, testMu, force);
                const double atLuminal =
                    VelocityCrossing::speedAtParameter(c, testMu, force, luminal);
                report.checkNear(std::format("  mu = {:g}, accelerating force = {:g} : light "
                                             "speed is reached at parameter {:.6f}",
                                             testMu, force, luminal),
                                 atLuminal - 1.0, 1e-6);
                report.check("    the parameter is finite and positive",
                             std::isfinite(luminal) && luminal > 0.0);
                report.check("    just before it the particle is slower than light",
                             VelocityCrossing::speedAtParameter(c, testMu, force,
                                                               0.99 * luminal) < 1.0);
                report.check("    just after it the particle is faster than light",
                             VelocityCrossing::speedAtParameter(c, testMu, force,
                                                               1.01 * luminal) > 1.0);
                report.check(std::format("    and the momentum the accelerator had to supply is "
                                         "{:.6f}, a finite number",
                                         VelocityCrossing::momentumAtLightSpeed(c, testMu,
                                                                                force)),
                             std::isfinite(VelocityCrossing::momentumAtLightSpeed(c, testMu,
                                                                                  force)));
                ++arrivals;
            }
        }
        report.check(std::format("  {} combinations of mass and accelerating force were tried, "
                                 "and every one reached light speed at a finite parameter",
                                 arrivals),
                     arrivals == 9);
        report.checkNear("the momentum demanded at light speed is the square root of the mass "
                         "parameter plus a quarter turn of work, which is where the standard "
                         "shell demanded a divergence",
                         VelocityCrossing::momentumAtLightSpeed(c, mu, 0.4) -
                             c * std::sqrt(mu + 0.4 * kPi / 2.0),
                         1e-12);

        report.subsection("Beyond light speed the particle is in the far region");
        const double force = 0.4;
        const double luminal = VelocityCrossing::luminalParameter(c, mu, force);
        const double crossing = ContinuousCrossing::sigmaToReach(c, mu, force, kPi / 2.0);
        for (double fraction : {1.1, 1.5, 2.0})
        {
            const double sigma = std::min(fraction * luminal, 0.999 * crossing);
            const double speed = VelocityCrossing::speedAtParameter(c, mu, force, sigma);
            const double theta = ContinuousCrossing::theta(c, mu, force, sigma);
            report.check(std::format("  parameter {:.6f} : the speed is {:.6f}, above light "
                                     "speed",
                                     sigma, speed),
                         speed > 1.0);
            report.check("    and the metric's scale factor has turned negative there",
                         VelocityCrossing::metricScale(speed) < 0.0 && theta > kPi / 4.0);
        }

        report.subsection("The involution is the reflection of the angle about light speed");
        for (double beta : {0.25, 0.5, 0.9, 2.0, 4.0})
        {
            const double theta = VelocityCrossing::angleFromSpeed(beta);
            const double reflected = VelocityCrossing::speedFromAngle(kPi / 2.0 - theta);
            report.checkNear(std::format("  beta = {:g} : reflecting the angle about pi/4 "
                                         "inverts the speed",
                                         beta),
                             reflected - 1.0 / beta, 1e-12);
            report.checkNear("    which is the relation the involution section established by "
                             "another route",
                             reflected - SignatureInvolution::transformVelocity(c, beta), 1e-12);
        }

        report.subsection("Reversing the force returns the same particle below light speed");
        const double returnPoint = VelocityCrossing::returnToSubluminalParameter(c, mu, force);
        report.checkNear("  the decelerating particle starts beyond the far end, where the "
                         "angle is pi/2",
                         ContinuousCrossing::thetaReturning(c, mu, force, 0.0) - kPi / 2.0,
                         1e-9);
        report.checkNear(std::format("  it falls back to light speed at parameter {:.6f}, which "
                                     "is the very parameter the outward flight reached light "
                                     "speed at, since reflecting the angle about pi/4 leaves "
                                     "that angle where it was",
                                     returnPoint),
                         VelocityCrossing::returningSpeedAtParameter(c, mu, force, returnPoint) -
                             1.0,
                         1e-6);
        report.check("  before that parameter it is still faster than light",
                     VelocityCrossing::returningSpeedAtParameter(c, mu, force,
                                                                 0.99 * returnPoint) > 1.0);
        report.checkNear("    and the two parameters agree exactly",
                         returnPoint - luminal, 1e-15);
        report.check("  after it the particle is slower than light, which is the near region",
                     VelocityCrossing::returningSpeedAtParameter(c, mu, force,
                                                                 1.01 * returnPoint) < 1.0 &&
                         VelocityCrossing::returningSpeedAtParameter(c, mu, force,
                                                                     1.01 * returnPoint) > 0.0);
        report.checkNear("  and it comes to rest at the parameter the outward crossing took, so "
                         "deceleration undoes acceleration exactly",
                         VelocityCrossing::returningSpeedAtParameter(c, mu, force, crossing),
                         1e-6);
        report.checkNear("  the mass parameter it arrives with is the one it left with, since "
                         "the shell at angle zero carries no work term",
                         ContinuousCrossing::constraintResidual(c, mu, force, 0.0), 1e-12);
        int returns = 0;
        for (double testMu : {0.25, 1.0, 4.0})
        {
            for (double testForce : {0.05, 0.4, 3.0})
            {
                const double point =
                    VelocityCrossing::returnToSubluminalParameter(c, testMu, testForce);
                const bool below = VelocityCrossing::returningSpeedAtParameter(
                                       c, testMu, testForce, 1.01 * point) < 1.0;
                const bool above = VelocityCrossing::returningSpeedAtParameter(
                                       c, testMu, testForce, 0.99 * point) > 1.0;
                report.check(std::format("  mu = {:g}, force = {:g} : the return crosses light "
                                         "speed downward at {:.6f}",
                                         testMu, testForce, point),
                             below && above && std::isfinite(point) && point > 0.0);
                if (below && above)
                {
                    ++returns;
                }
            }
        }
        report.check(std::format("  all {} combinations returned below light speed, so the "
                                 "return follows from the same mechanism run backwards and "
                                 "needs nothing of its own",
                                 returns),
                     returns == 9);
    }

}
