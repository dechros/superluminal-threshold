#include "particle/ContinuousCrossingSection.h"
#include "particle/ContinuousCrossing.h"

#include "core/Report.h"
#include "particle/ConstantForce.h"

#include <cmath>
#include <numbers>
#include <format>

namespace slm
{

    void ContinuousCrossingSection::run(Report &report) const
    {
        const double c = 1.0;
        constexpr double halfPi = std::numbers::pi / 2.0;

        report.subsection("The entry root and its magnitude");
        const double mu = 1.0;
        const double p0 = ContinuousCrossing::entryMomentum(c, mu);
        report.check(std::format("  the entry root is negative, {:.6f}, the branch that carries "
                                 "theta upward from zero",
                                 p0),
                     p0 < 0.0);
        report.checkNear("  its magnitude matches the shell at theta = 0",
                         p0 * p0 - mu * c * c, 1e-9);

        report.subsection("The constraint holds along the whole trajectory");
        const double force = 0.4;
        for (double sigma : {0.0, 0.5, 1.5, 3.0, 7.0})
        {
            const double residual = ContinuousCrossing::constraintResidual(c, mu, force, sigma);
            report.checkNear(std::format("  sigma = {:.1f} : extended shell residual", sigma),
                             residual, 1e-9);
        }

        report.subsection("Theta grows without a turning point, straight through pi/4");
        double previous = -1e300;
        bool passedQuarterPi = false;
        for (double sigma : {0.0, 1.0, 2.0, 3.0, 4.0, 6.0})
        {
            const double th = ContinuousCrossing::theta(c, mu, force, sigma);
            report.check(std::format("  sigma = {:>4.1f} : theta = {:.6f}, larger than the "
                                     "previous value",
                                     sigma, th),
                         th > previous);
            previous = th;
            if (th > halfPi / 2.0)
            {
                passedQuarterPi = true;
            }
        }
        report.check("  the trajectory passes theta = pi/4 without stopping there",
                     passedQuarterPi);

        report.subsection("Every target angle is reached, for every mass and every force tried");
        int triedCombinations = 0;
        for (double testMu : {0.25, 1.0, 4.0})
        {
            for (double testForce : {0.05, 0.4, 3.0})
            {
                for (double target : {halfPi / 4.0, halfPi, 3.0 * halfPi})
                {
                    const double sigmaAt =
                        ContinuousCrossing::sigmaToReach(c, testMu, testForce, target);
                    const double reached = ContinuousCrossing::theta(c, testMu, testForce, sigmaAt);
                    report.checkNear(
                        std::format("  mu = {:g}, force = {:g}, target = {:.4f} : reached at "
                                   "sigma = {:.6f}",
                                   testMu, testForce, target, sigmaAt),
                        reached - target, 1e-6);
                    report.check("  the parameter reached is finite and positive",
                                 std::isfinite(sigmaAt) && sigmaAt > 0.0);
                    ++triedCombinations;
                }
            }
        }
        report.check(std::format("  {} combinations tried, none failed to reach its target angle",
                                 triedCombinations),
                     triedCombinations == 27);

        report.subsection("The time reverse of the same trajectory is the return to theta = 0");
        const double sigmaForward = ContinuousCrossing::sigmaToReach(c, mu, force, halfPi);
        report.checkNear("  theta returning starts at pi/2 when sigma = 0",
                         ContinuousCrossing::thetaReturning(c, mu, force, 0.0) - halfPi, 1e-9);
        report.checkNear("  theta returning reaches zero at the same sigma the forward "
                         "trajectory reaches pi/2",
                         ContinuousCrossing::thetaReturning(c, mu, force, sigmaForward), 1e-6);
        double previousReturning = 1e300;
        bool monotonic = true;
        for (double sigma : {0.0, sigmaForward * 0.25, sigmaForward * 0.5, sigmaForward * 0.75,
                             sigmaForward})
        {
            const double thBack = ContinuousCrossing::thetaReturning(c, mu, force, sigma);
            if (thBack > previousReturning + 1e-9)
            {
                monotonic = false;
            }
            previousReturning = thBack;
        }
        report.check("  theta returning falls monotonically from pi/2 to zero",
                     monotonic);
    }
}
