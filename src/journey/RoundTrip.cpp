#include "journey/RoundTrip.h"

#include "core/Report.h"
#include "particle/AcceleratedCrossing.h"
#include "particle/ConstantForce.h"
#include "particle/PairedExcursion.h"
#include "particle/TimeProjection.h"
#include "physics/units/PhysicalScales.h"
#include "physics/units/PhysicalScales.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <numbers>
#include <ranges>
#include <string_view>

namespace slm
{
    namespace
    {
        constexpr double kQuarterPi = std::numbers::pi / 4.0;
        constexpr double kHalfPi = std::numbers::pi / 2.0;
        constexpr int kSamples = 64;

        double signOf(RoundTrip::Sense sense)
        {
            return sense == RoundTrip::Sense::PlusR ? 1.0 : -1.0;
        }

        PairedExcursion::Sense pairedSense(RoundTrip::Sense sense)
        {
            return sense == RoundTrip::Sense::PlusR ? PairedExcursion::Sense::PlusR
                                                    : PairedExcursion::Sense::MinusR;
        }

    }

    double RoundTrip::entryMomentum(double c, double mu, double force, double startAngle)
    {
        return ConstantForce::entryMomentum(c, mu + 2.0 * force * startAngle);
    }

    double RoundTrip::angle(double c, double mu, double force, double startAngle, double sigma)
    {
        return ConstantForce::coordinate(c, mu + 2.0 * force * startAngle, force, startAngle, sigma);
    }

    double RoundTrip::momentum(double c, double mu, double force, double startAngle, double sigma)
    {
        return ConstantForce::momentum(c, mu + 2.0 * force * startAngle, force, sigma);
    }

    double RoundTrip::parameterToAngle(double c, double mu, double force, double startAngle,
                                       double target)
    {
        return ConstantForce::parameterToReach(c, mu + 2.0 * force * startAngle, force, startAngle,
                                               target);
    }

    double RoundTrip::relativeResidual(double c, double mu, double force, double angle,
                                       double momentum)
    {
        const double residual = mu + 2.0 * force * angle - momentum * momentum / (c * c);
        const double scale = std::max(mu + 2.0 * force * kHalfPi, 1.0);
        return residual / scale;
    }

    double RoundTrip::returningAngle(double c, double mu, double force, double startAngle,
                                     double outward, double sigma)
    {
        return angle(c, mu, force, startAngle, outward - sigma);
    }

    double RoundTrip::returningMomentum(double c, double mu, double force, double startAngle,
                                        double outward, double sigma)
    {
        return -momentum(c, mu, force, startAngle, outward - sigma);
    }

    double RoundTrip::hamiltonResidual(double c, double mu, double force, double startAngle,
                                       double outward, double sigma, double step)
    {
        const double thetaRate = (returningAngle(c, mu, force, startAngle, outward, sigma + step) -
                                  returningAngle(c, mu, force, startAngle, outward, sigma - step)) /
                                 (2.0 * step);
        const double momentumRate =
            (returningMomentum(c, mu, force, startAngle, outward, sigma + step) -
             returningMomentum(c, mu, force, startAngle, outward, sigma - step)) /
            (2.0 * step);
        const double p = returningMomentum(c, mu, force, startAngle, outward, sigma);
        const double first = (thetaRate + p / (c * c)) / std::max(std::abs(p) / (c * c), 1e-300);
        const double second = (momentumRate + force) / force;
        return std::max(std::abs(first), std::abs(second));
    }

    RoundTrip::Settings RoundTrip::referenceSettings()
    {
        const double c = PhysicalScales::lightSpeed();
        const double electronScale = PhysicalScales::electronMass() * c / PhysicalScales::reducedPlanck();
        return Settings{.c = c,
                        .force = electronScale * electronScale,
                        .farDistance = 1.0,
                        .wallWidth = 1e-15,
                        .wallTolerance = 1e-8};
    }

    double RoundTrip::farSideParameter(double c, double mu, double force, double farDistance)
    {
        const AcceleratedCrossing::Three rest{0.0, 0.0, 0.0};
        return AcceleratedCrossing::parameterToReach(c, mu, rest, force, farDistance);
    }

    double RoundTrip::farSidePosition(double c, double mu, double force, Sense sense, double sigma)
    {
        const AcceleratedCrossing::Three rest{0.0, 0.0, 0.0};
        return signOf(sense) * AcceleratedCrossing::position(c, mu, rest, force, sigma);
    }

    double RoundTrip::farSideMomentum(double c, double mu, double force, Sense sense, double sigma)
    {
        const AcceleratedCrossing::Three rest{0.0, 0.0, 0.0};
        return signOf(sense) * AcceleratedCrossing::conjugateMomentum(c, mu, rest, force, sigma);
    }

    double RoundTrip::farSideResidual(double c, double mu, double force, Sense sense, double sigma,
                                      double farDistance)
    {
        const double r = farSidePosition(c, mu, force, sense, sigma);
        const double q = farSideMomentum(c, mu, force, sense, sigma);
        const double residual = mu + 2.0 * force * signOf(sense) * r - q * q / (c * c);
        return residual / (mu + 2.0 * force * farDistance);
    }

    double RoundTrip::clockRate(double angle)
    {
        return std::sqrt(std::max(std::cos(2.0 * angle), 0.0)) / std::cos(angle);
    }

    RoundTrip::Four RoundTrip::farSideImage(const Three &offset)
    {
        return TimeProjection::toFarCoordinates({0.0, offset[0], offset[1], offset[2]});
    }

    double RoundTrip::signedVolume(const std::vector<Three> &atoms)
    {
        if (atoms.size() < 4)
        {
            return 0.0;
        }
        Three u{};
        Three v{};
        Three w{};
        for (std::size_t i = 0; i < 3; ++i)
        {
            u[i] = atoms[1][i] - atoms[0][i];
            v[i] = atoms[2][i] - atoms[0][i];
            w[i] = atoms[3][i] - atoms[0][i];
        }
        return u[0] * (v[1] * w[2] - v[2] * w[1]) - u[1] * (v[0] * w[2] - v[2] * w[0]) +
               u[2] * (v[0] * w[1] - v[1] * w[0]);
    }

    RoundTrip::Outcome RoundTrip::run(const Traveller &traveller, Sense sense,
                                      const Settings &settings)
    {
        const double c = settings.c;
        const double force = settings.force;
        Outcome out;
        out.mu = traveller.mu();
        out.startAngle = traveller.startAngle();
        out.entryMomentum = entryMomentum(c, out.mu, force, out.startAngle);
        out.thresholdMomentum = c * std::sqrt(out.mu + force * kHalfPi);
        out.thresholdParameter =
            out.startAngle < kQuarterPi
                ? parameterToAngle(c, out.mu, force, out.startAngle, kQuarterPi)
                : 0.0;
        out.outwardParameter = parameterToAngle(c, out.mu, force, out.startAngle, kHalfPi);

        out.farSideParameter = farSideParameter(c, out.mu, force, settings.farDistance);
        out.returnParameter = out.outwardParameter;
        const double step = 0.25 * out.outwardParameter;

        for (int i : std::views::iota(0, kSamples + 1))
        {
            const double sigma = out.outwardParameter * i / kSamples;
            const double th = angle(c, out.mu, force, out.startAngle, sigma);
            const double p = momentum(c, out.mu, force, out.startAngle, sigma);
            out.maxOutwardResidual = std::max(
                out.maxOutwardResidual, std::abs(relativeResidual(c, out.mu, force, th, p)));
            const double thBack = returningAngle(c, out.mu, force, out.startAngle,
                                                 out.outwardParameter, sigma);
            const double pBack = returningMomentum(c, out.mu, force, out.startAngle,
                                                   out.outwardParameter, sigma);
            out.maxReturnResidual =
                std::max(out.maxReturnResidual,
                         std::abs(relativeResidual(c, out.mu, force, thBack, pBack)));
            out.maxHamiltonResidual =
                std::max(out.maxHamiltonResidual,
                         hamiltonResidual(c, out.mu, force, out.startAngle, out.outwardParameter,
                                          sigma, step));
            out.maxFarSideResidual = std::max(
                out.maxFarSideResidual,
                std::abs(farSideResidual(c, out.mu, force, sense,
                                         out.farSideParameter * i / kSamples, settings.farDistance)));
        }

        out.joinAngleResidual =
            returningAngle(c, out.mu, force, out.startAngle, out.outwardParameter, 0.0) - kHalfPi;
        out.joinMomentumResidual =
            std::abs(returningMomentum(c, out.mu, force, out.startAngle, out.outwardParameter, 0.0)) /
                std::abs(momentum(c, out.mu, force, out.startAngle, out.outwardParameter)) -
            1.0;

        const double sigmaEnd = out.outwardParameter;
        out.speedAtReturn =
            std::tan(returningAngle(c, out.mu, force, out.startAngle, out.outwardParameter, sigmaEnd));
        out.momentumAtReturn =
            std::abs(returningMomentum(c, out.mu, force, out.startAngle, out.outwardParameter, sigmaEnd));
        out.massAtReturn =
            out.momentumAtReturn * out.momentumAtReturn / (c * c) - 2.0 * force * out.startAngle;

        out.mapShift = PairedExcursion::mapContribution(settings.farDistance, pairedSense(sense));
        out.wallDelay =
            PairedExcursion::roundTripDelay(settings.wallWidth, settings.wallTolerance, 1.0);
        out.netShiftFieldWall = out.mapShift + out.wallDelay;
        out.netShiftVelocity = out.mapShift;

        const auto space = static_cast<std::size_t>(TimeProjection::farSideSpaceSlot());
        for (const Three &offset : traveller.atoms)
        {
            Four far = farSideImage(offset);
            out.farSideAtoms.push_back(far);
            far[space] += signOf(sense) * settings.farDistance;
            const Four near = TimeProjection::toNearCoordinates(far);
            out.atomClockShifts.push_back(near[0] / c);
            out.returnedAtoms.push_back({near[1], near[2], near[3]});
        }
        return out;
    }
}
