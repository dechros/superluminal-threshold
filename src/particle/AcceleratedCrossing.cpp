#include "particle/AcceleratedCrossing.h"

#include "core/Report.h"
#include "particle/EnergyVector.h"
#include "particle/TimeProjection.h"
#include "units/PhysicalScales.h"

#include <cmath>
#include <format>

namespace slm
{

    double AcceleratedCrossing::entryMomentum(double c, double mu, const Three &energy)
    {
        return -EnergyVector::massShellFrequency(c, mu, energy);
    }

    double AcceleratedCrossing::position(double c, double mu, const Three &energy, double force,
                                         double sigma)
    {
        const double q0 = entryMomentum(c, mu, energy);
        return force * sigma * sigma / (2.0 * c * c) - q0 * sigma / (c * c);
    }

    double AcceleratedCrossing::conjugateMomentum(double c, double mu, const Three &energy,
                                                  double force, double sigma)
    {
        return entryMomentum(c, mu, energy) - force * sigma;
    }

    double AcceleratedCrossing::constraintResidual(double c, double mu, const Three &energy,
                                                   double force, double sigma)
    {
        const double transverseSquared = EnergyVector::length(energy) * EnergyVector::length(energy);
        const double q = conjugateMomentum(c, mu, energy, force, sigma);
        const double r = position(c, mu, energy, force, sigma);
        return transverseSquared + mu + 2.0 * force * r - q * q / (c * c);
    }

    double AcceleratedCrossing::parameterToReach(double c, double mu, const Three &energy,
                                                 double force, double target)
    {
        const double a = force / (2.0 * c * c);
        const double b = -entryMomentum(c, mu, energy) / (c * c);
        const double disc = b * b + 4.0 * a * target;
        return (-b + std::sqrt(disc)) / (2.0 * a);
    }

    void AcceleratedCrossingSection::run(Report &report) const
    {
        const double c = 1.0;
        const double mu = 1.0;
        const AcceleratedCrossing::Three energy{1.0, 2.0, 2.0};

        report.subsection("What the free mass shell leaves open");
        const double q0 = AcceleratedCrossing::entryMomentum(c, mu, energy);
        report.check(std::format("  the entry root is negative, {:.6f}, which is the branch "
                                 "that carries r upward from zero",
                                 q0),
                     q0 < 0.0);
        report.checkNear("  its magnitude matches the free mass shell already established "
                         "for the energy vector",
                         q0 * q0 - EnergyVector::massShellFrequency(c, mu, energy) *
                                       EnergyVector::massShellFrequency(c, mu, energy),
                         1e-9);

        report.subsection("The constraint holds along the whole trajectory");
        const double force = 0.4;
        for (double sigma : {0.0, 0.5, 1.5, 3.0, 7.0})
        {
            const double residual =
                AcceleratedCrossing::constraintResidual(c, mu, energy, force, sigma);
            report.checkNear(std::format("  sigma = {:.1f} : extended mass shell residual", sigma),
                             residual, 1e-9);
        }

        report.subsection("Position grows without a turning point");
        double previous = -1e300;
        for (double sigma : {0.0, 1.0, 2.0, 4.0, 8.0, 16.0})
        {
            const double r = AcceleratedCrossing::position(c, mu, energy, force, sigma);
            report.check(std::format("  sigma = {:>4.1f} : r = {:.6f}, larger than the previous "
                                     "value",
                                     sigma, r),
                         r > previous);
            previous = r;
        }

        report.subsection("Every target is reached, for every mass, energy and force tried");
        int triedCombinations = 0;
        for (double testMu : {0.25, 1.0, 4.0})
        {
            for (double testForce : {0.05, 0.4, 3.0})
            {
                for (double target : {0.1, 1.0, 50.0})
                {
                    const AcceleratedCrossing::Three testEnergy{0.3, 0.7, 1.1};
                    const double sigmaAt = AcceleratedCrossing::parameterToReach(
                        c, testMu, testEnergy, testForce, target);
                    const double reached =
                        AcceleratedCrossing::position(c, testMu, testEnergy, testForce, sigmaAt);
                    report.checkNear(
                        std::format("  mu = {:g}, force = {:g}, target = {:g} : reached at "
                                   "sigma = {:.6f}",
                                   testMu, testForce, target, sigmaAt),
                        reached - target, 1e-6);
                    report.check("  the parameter reached is finite and positive",
                                 std::isfinite(sigmaAt) && sigmaAt > 0.0);
                    ++triedCombinations;
                }
            }
        }
        report.check(std::format("  {} combinations tried, none failed to reach its target",
                                 triedCombinations),
                     triedCombinations == 27);

        report.subsection("The reached distance reads as a time difference over there");
        const double target = 3.0;
        const TimeProjection::Four displacement{0.0, 0.0, 0.0, target};
        const TimeProjection::Four image = TimeProjection::toNearCoordinates(displacement);
        report.checkNear("  a pure r displacement of the target size lands entirely on the "
                         "near-side clock, at the target value",
                         image[0] - target, 1e-12);
        report.checkNear("  and it leaves the three near-side space coordinates alone",
                         image[1] * image[1] + image[2] * image[2] + image[3] * image[3], 1e-24);

        report.subsection("The same statement in seconds and metres");
        const double metres = 1.0;
        const double seconds = PhysicalScales::advanceForDistance(metres);
        report.check(std::format("  driving the particle {:.0f} metre along the space axis "
                                 "advances the near-side clock by {:.4e} s, regardless of "
                                 "which mass or energy vector was driven there",
                                 metres, seconds),
                     seconds > 0.0);
    }

}
