#ifndef SLM_JOURNEY_JOURNEYSTATE_H
#define SLM_JOURNEY_JOURNEYSTATE_H

#include "journey/RoundTrip.h"
#include "journey/Traveller.h"

#include <array>
#include <string>
#include <vector>

namespace slm
{

    /// The round trip sampled at any point between departure and return, so
    /// that a viewer can draw what the library computes and nothing else.
    ///
    /// A trip is a sequence of phases, each covered by the trajectory parameter
    /// of one of RoundTrip's legs: the outward leg below light speed, the
    /// outward leg above it, the drive along the far side's space axis, the
    /// return above light speed and the return below it. A massless traveller
    /// starts and ends at light speed, so for it the two phases below light
    /// speed have no extent and are left out. The phases that remain share the
    /// progress interval equally, since the trajectory parameter is not a clock
    /// and differs between travellers by orders of magnitude.
    ///
    /// Every number in a sample is read from a library the suite already
    /// checks: the angle and momentum from RoundTrip, the metric's four
    /// diagonal entries from ThresholdField at that angle, the clock rate from
    /// RoundTrip, the far-side position from the signed drive, the clock shift
    /// from the involution applied to that position, and the atoms' far-side
    /// coordinates from RoundTrip::farSideImage with the drive added along the
    /// space slot. The momentum conjugate to the angle is held through the
    /// far-side leg and reflected at the start of the return, as RoundTrip
    /// states; the far-side drive's own conjugate momentum is reported
    /// separately.
    class JourneyState
    {
    public:
        using Three = std::array<double, 3>;
        using Four = std::array<double, 4>;

        /// The legs of the trip, in order.
        enum class Phase
        {
            BelowLightOut,
            AboveLightOut,
            FarSide,
            AboveLightBack,
            BelowLightBack
        };

        /// One instant of the trip.
        struct Sample
        {
            Phase phase = Phase::BelowLightOut;
            double phaseProgress = 0.0;
            double sigma = 0.0;
            double theta = 0.0;
            double beta = 0.0;
            double metricScale = 1.0;
            double clockRate = 1.0;
            double momentum = 0.0;
            double farMomentum = 0.0;
            Four metric{};
            double r = 0.0;
            double nearClockShift = 0.0;
            std::vector<Three> nearAtoms;
            std::vector<Four> farAtoms;
        };

        /// A readable name for the phase.
        static std::string name(Phase phase);

        /// The phases the traveller's trip has, in order.
        static std::vector<Phase> phases(const Traveller &traveller);

        /// The trip at @p progress in @f$ [0, 1] @f$.
        static Sample at(const Traveller &traveller, RoundTrip::Sense sense,
                         const RoundTrip::Settings &settings, double progress);
    };

}

#endif
