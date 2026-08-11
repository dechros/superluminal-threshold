#include "mechanism/ThresholdWall.h"

#include "core/Report.h"
#include "dynamics/ThresholdField.h"
#include "particle/ContinuousCrossing.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kPi = 3.14159265358979323846;
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

    void ThresholdWallSection::run(Report &report) const
    {
        const double stiffness = 2.0;
        const double lambdaScale = 0.7;
        const double width = ThresholdWall::widthFromCouplings(stiffness, lambdaScale);

        report.subsection("The potential degenerates where the metric does");
        report.checkNear("  the potential vanishes at theta = 0, one of the two regions",
                         ThresholdWall::potential(lambdaScale, 0.0));
        report.checkNear("  and at theta = pi/2, the other",
                         ThresholdWall::potential(lambdaScale, kPi / 2.0));
        report.check("  the single maximum between them stands at theta = pi/4",
                     ThresholdWall::potential(lambdaScale, kPi / 4.0) >
                             ThresholdWall::potential(lambdaScale, kPi / 4.0 - 0.05) &&
                         ThresholdWall::potential(lambdaScale, kPi / 4.0) >
                             ThresholdWall::potential(lambdaScale, kPi / 4.0 + 0.05));
        report.checkNear("  the potential's slope vanishes there, so it is a genuine maximum",
                         ThresholdWall::potentialSlope(lambdaScale, kPi / 4.0), 1e-12);
        report.check("  and the metric family degenerates at that same angle, which neither "
                     "the potential nor the family was arranged to arrange",
                     ThresholdField::isDegenerate(kPi / 4.0, 1e-9));

        report.subsection("The kink solves the static field equation");
        const double step = 1e-4;
        double worstResidual = 0.0;
        for (double x : {-3.0, -1.0, -0.2, 0.0, 0.2, 1.0, 3.0})
        {
            const double scaled = x * width;
            const double second =
                (ThresholdWall::profile(scaled + step, width) -
                 2.0 * ThresholdWall::profile(scaled, width) +
                 ThresholdWall::profile(scaled - step, width)) /
                (step * step);
            const double demanded =
                ThresholdWall::potentialSlope(lambdaScale,
                                              ThresholdWall::profile(scaled, width)) /
                stiffness;
            const double residual = second - demanded;
            worstResidual = std::max(worstResidual, std::abs(residual));
            report.checkNear(std::format("  x = {:>5.1f} L : stiffness * theta'' equals the "
                                         "potential's slope",
                                         x),
                             residual, 1e-6);
        }
        report.check(std::format("  the worst residual over the sampled wall is {:.3e}",
                                 worstResidual),
                     worstResidual < 1e-6);

        report.subsection("The kink's closed-form slope, and the first integral behind it");
        for (double x : {-2.0, -0.5, 0.0, 0.5, 2.0})
        {
            const double scaled = x * width;
            const double numeric = (ThresholdWall::profile(scaled + step, width) -
                                    ThresholdWall::profile(scaled - step, width)) /
                                   (2.0 * step);
            report.checkNear(std::format("  x = {:>5.1f} L : the closed form matches the "
                                         "derivative of the profile",
                                         x),
                             numeric - ThresholdWall::slope(scaled, width), 1e-8);
            const double theta = ThresholdWall::profile(scaled, width);
            const double slope = ThresholdWall::slope(scaled, width);
            report.checkNear("    and the first integral holds: half the stiffness times the "
                             "slope squared is the potential",
                             0.5 * stiffness * slope * slope -
                                 ThresholdWall::potential(lambdaScale, theta),
                             1e-9);
        }

        report.subsection("The two endpoints, and the centre");
        report.checkNear("  far behind the wall the field sits in the near-side minimum",
                         ThresholdWall::profile(-40.0 * width, width), 1e-12);
        report.checkNear("  at the centre it stands at pi/4, the degenerate angle",
                         ThresholdWall::profile(0.0, width) - kPi / 4.0, 1e-12);
        report.checkNear("  far beyond it the field sits in the far-side minimum",
                         ThresholdWall::profile(40.0 * width, width) - kPi / 2.0, 1e-12);

        report.subsection("The degenerate point is crossed at the greatest speed the wall offers");
        const double centreSlope = ThresholdWall::slope(0.0, width);
        bool centreIsFastest = true;
        for (double x : {-4.0, -2.0, -1.0, -0.3, 0.3, 1.0, 2.0, 4.0})
        {
            if (ThresholdWall::slope(x * width, width) >= centreSlope)
            {
                centreIsFastest = false;
            }
        }
        report.check(std::format("  the slope at the centre is {:.6f}, and no sampled point "
                                 "away from it is as steep",
                                 centreSlope),
                     centreIsFastest);
        report.checkNear("  the centre slope is exactly one over twice the width",
                         centreSlope - 1.0 / (2.0 * width), 1e-12);
        report.check("so the worst angle is the one the field spends the least distance near, "
                     "which is the reverse of what a barrier does",
                     centreIsFastest);

        report.subsection("What the wall costs and how far it reaches");
        report.checkNear("  the tension is the stiffness over twice the width",
                         ThresholdWall::tension(stiffness, width) - stiffness / (2.0 * width),
                         1e-12);
        double integrated = 0.0;
        const double span = 60.0 * width;
        const int samples = 200000;
        const double dx = 2.0 * span / samples;
        for (int i = 0; i < samples; ++i)
        {
            const double x = -span + (i + 0.5) * dx;
            const double s = ThresholdWall::slope(x, width);
            integrated += stiffness * s * s * dx;
        }
        report.checkNear(std::format("  and integrating the energy density gives the same "
                                     "number, {:.6f}",
                                     integrated),
                         integrated - ThresholdWall::tension(stiffness, width), 1e-6);
        for (double tolerance : {1e-2, 1e-4, 1e-8})
        {
            const double distance = ThresholdWall::distanceToReach(width, tolerance);
            const double reached = ThresholdWall::profile(distance, width);
            report.checkNear(std::format("  reaching within {:.0e} of pi/2 takes {:.4f} in "
                                         "units of the width",
                                         tolerance, distance / width),
                             kPi / 2.0 - reached - tolerance, 1e-9);
        }
        report.check("the distance grows only as the logarithm of the tolerance, so the far "
                     "side is reached at a finite crossing rather than an infinite one",
                     ThresholdWall::distanceToReach(width, 1e-8) <
                         3.0 * ThresholdWall::distanceToReach(width, 1e-3));

        report.subsection("Under this reading the constant would be a mass that depends on the angle");
        const double mu = 1.0;
        const double force = 0.4;
        for (double theta : {0.0, 0.3, kPi / 4.0, 1.2, kPi / 2.0})
        {
            const double numericSlope =
                (ThresholdWall::massParameter(mu, force, theta + step) -
                 ThresholdWall::massParameter(mu, force, theta - step)) /
                (2.0 * step);
            report.checkNear(std::format("  theta = {:.4f} : half the slope of the mass "
                                         "parameter is the constant applied earlier",
                                         theta),
                             0.5 * numericSlope - force, 1e-9);
        }
        const double c = 1.0;
        for (double sigma : {0.0, 0.5, 1.5, 3.0, 7.0})
        {
            const double theta = ContinuousCrossing::theta(c, mu, force, sigma);
            const double momentum = ContinuousCrossing::conjugateMomentum(c, mu, force, sigma);
            const double shell =
                ThresholdWall::massParameter(mu, force, theta) - momentum * momentum / (c * c);
            report.checkNear(std::format("  sigma = {:.1f} : the trajectory sits on the free "
                                         "shell of that angle-dependent mass",
                                         sigma),
                             shell, 1e-9);
            report.checkNear("    which is the same statement the earlier section made as a "
                             "constraint residual",
                             shell - ContinuousCrossing::constraintResidual(c, mu, force, sigma),
                             1e-12);
        }

        report.subsection("What the crossing costs the particle");
        for (double testForce : {0.05, 0.4, 3.0})
        {
            const double ratio = ThresholdWall::restEnergyRatio(mu, testForce);
            report.check(std::format("  a coupling of {:g} raises the rest energy by a factor "
                                     "{:.6f} between the two minima",
                                     testForce, ratio),
                         ratio > 1.0 && std::isfinite(ratio));
        }
        report.check("the cost is finite for every coupling tried, so the wall is a price "
                     "rather than a wall in the other sense",
                     std::isfinite(ThresholdWall::restEnergyRatio(mu, 1e6)));
        report.checkNear("  the coupling may not fall below minus the mass over pi, where the "
                         "far minimum would sit off the real shell",
                         ThresholdWall::massParameter(mu, ThresholdWall::smallestAdmissibleForce(mu),
                                                      kPi / 2.0),
                         1e-12);
        report.check("  and just inside that bound the mass parameter is still real all the "
                     "way across",
                     ThresholdWall::massParameter(mu, 0.99 * ThresholdWall::smallestAdmissibleForce(mu),
                                                  kPi / 2.0) > 0.0);
    }

}
