#include "journey/JourneyState.h"

#include "physics/dynamics/ThresholdField.h"
#include "particle/TimeProjection.h"

#include <algorithm>
#include <cmath>
#include <numbers>

namespace slm
{
    namespace
    {
        constexpr double kQuarterPi = std::numbers::pi / 4.0;
        constexpr double kHalfPi = std::numbers::pi / 2.0;
    }

    std::string JourneyState::name(Phase phase)
    {
        switch (phase)
        {
        case Phase::BelowLightOut:
            return "accelerating below light speed";
        case Phase::AboveLightOut:
            return "crossing, above light speed";
        case Phase::FarSide:
            return "driving along the far side's space axis";
        case Phase::AboveLightBack:
            return "returning, above light speed";
        default:
            return "decelerating below light speed";
        }
    }

    std::vector<JourneyState::Phase> JourneyState::phases(const Traveller &traveller)
    {
        if (traveller.mass > 0.0)
        {
            return {Phase::BelowLightOut, Phase::AboveLightOut, Phase::FarSide, Phase::AboveLightBack,
                    Phase::BelowLightBack};
        }
        return {Phase::AboveLightOut, Phase::FarSide, Phase::AboveLightBack};
    }

    JourneyState::Sample JourneyState::at(const Traveller &traveller, RoundTrip::Sense sense,
                                          const RoundTrip::Settings &settings, double progress)
    {
        const double c = settings.c;
        const double force = settings.force;
        const double mu = traveller.mu();
        const double theta0 = traveller.startAngle();
        const double luminal =
            theta0 < kQuarterPi ? RoundTrip::parameterToAngle(c, mu, force, theta0, kQuarterPi) : 0.0;
        const double outward = RoundTrip::parameterToAngle(c, mu, force, theta0, kHalfPi);
        const double farSide = RoundTrip::farSideParameter(c, mu, force, settings.farDistance);
        const double heldMomentum = RoundTrip::momentum(c, mu, force, theta0, outward);

        const std::vector<Phase> list = phases(traveller);
        const double clamped = std::clamp(progress, 0.0, 1.0);
        const double scaled = clamped * static_cast<double>(list.size());
        const auto index = static_cast<std::size_t>(
            std::min(static_cast<double>(list.size() - 1), std::floor(scaled)));
        const double u = clamped >= 1.0 ? 1.0 : scaled - static_cast<double>(index);

        Sample sample;
        sample.phase = list[index];
        sample.phaseProgress = u;

        const double finalR = RoundTrip::farSidePosition(c, mu, force, sense, farSide);
        switch (sample.phase)
        {
        case Phase::BelowLightOut:
            sample.sigma = u * luminal;
            sample.theta = RoundTrip::angle(c, mu, force, theta0, sample.sigma);
            sample.momentum = RoundTrip::momentum(c, mu, force, theta0, sample.sigma);
            break;
        case Phase::AboveLightOut:
            sample.sigma = luminal + u * (outward - luminal);
            sample.theta = RoundTrip::angle(c, mu, force, theta0, sample.sigma);
            sample.momentum = RoundTrip::momentum(c, mu, force, theta0, sample.sigma);
            break;
        case Phase::FarSide:
            sample.sigma = u * farSide;
            sample.theta = kHalfPi;
            sample.momentum = heldMomentum;
            sample.farMomentum = RoundTrip::farSideMomentum(c, mu, force, sense, sample.sigma);
            sample.r = RoundTrip::farSidePosition(c, mu, force, sense, sample.sigma);
            break;
        case Phase::AboveLightBack:
            sample.sigma = u * (outward - luminal);
            sample.theta = RoundTrip::returningAngle(c, mu, force, theta0, outward, sample.sigma);
            sample.momentum = RoundTrip::returningMomentum(c, mu, force, theta0, outward, sample.sigma);
            sample.r = finalR;
            break;
        default:
            sample.sigma = (outward - luminal) + u * luminal;
            sample.theta = RoundTrip::returningAngle(c, mu, force, theta0, outward, sample.sigma);
            sample.momentum = RoundTrip::returningMomentum(c, mu, force, theta0, outward, sample.sigma);
            sample.r = finalR;
            break;
        }

        sample.beta = std::tan(std::min(sample.theta, kHalfPi - 1e-12));
        sample.metricScale = std::cos(2.0 * sample.theta);
        sample.clockRate = RoundTrip::clockRate(sample.theta);
        sample.metric = ThresholdField::metric(sample.theta);
        const auto space = static_cast<std::size_t>(TimeProjection::farSideSpaceSlot());
        Four drive{};
        drive[space] = sample.r;
        sample.nearClockShift = TimeProjection::toNearCoordinates(drive)[0] / c;

        for (const Three &offset : traveller.atoms)
        {
            sample.nearAtoms.push_back(offset);
            Four far = RoundTrip::farSideImage(offset);
            far[space] += sample.r;
            sample.farAtoms.push_back(far);
        }
        return sample;
    }
}
