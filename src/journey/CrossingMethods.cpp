#include "journey/CrossingMethods.h"

#include "core/Report.h"
#include "physics/dynamics/Dispersion.h"
#include "physics/dynamics/ThresholdField.h"
#include "physics/intermediate/DegenerateWindow.h"
#include "physics/mechanism/ThresholdWall.h"
#include "journey/RoundTrip.h"
#include "particle/VelocityCrossing.h"
#include "physics/units/PhysicalScales.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <limits>
#include <numbers>
#include <ranges>

namespace slm
{
    namespace
    {
        constexpr double kHalfPi = std::numbers::pi / 2.0;
        constexpr double kFarAngle = 3.0 * std::numbers::pi / 8.0;
        constexpr double kProbeThickness = 1e-16;
    }

    double CrossingMethods::newtonianTimeToSpeed(double c, double acceleration, double beta)
    {
        return beta * c / acceleration;
    }

    double CrossingMethods::galileanClockShift()
    {
        return 0.0;
    }

    double CrossingMethods::standardAngleReached(double c, double acceleration, double properTime)
    {
        return VelocityCrossing::standardAngle(c, acceleration, properTime);
    }

    double CrossingMethods::tunnellingTransmission(const Traveller &traveller, double thickness)
    {
        return DegenerateWindow::slabTransmission(traveller.mu(), thickness);
    }

    double CrossingMethods::tunnellingHalvingWidth(const Traveller &traveller)
    {
        if (traveller.mu() == 0.0)
        {
            return std::numeric_limits<double>::infinity();
        }
        return DegenerateWindow::halvingThickness(traveller.mu());
    }

    bool CrossingMethods::hasRealFarSideMomentum(const Traveller &traveller, double angle,
                                                 double energySquared)
    {
        return ThresholdField::requiredMomentumSquared(angle, traveller.mu(), energySquared) >= 0.0;
    }

    bool CrossingMethods::hasRealFarSideMomentumWithReversedShell(const Traveller &traveller,
                                                                  double angle, double energySquared)
    {
        return ThresholdField::requiredMomentumSquared(angle, -traveller.mu(), -energySquared) >= 0.0;
    }

    double CrossingMethods::bendTension()
    {
        constexpr double stiffness = 2.0;
        constexpr double lambdaScale = 0.7;
        return ThresholdWall::tension(stiffness, ThresholdWall::widthFromCouplings(stiffness, lambdaScale));
    }

    double CrossingMethods::groupTimesPhase(const Traveller &traveller, double k)
    {
        const Dispersion dispersion(PhysicalScales::lightSpeed(), traveller.mass,
                                    PhysicalScales::reducedPlanck());
        return dispersion.groupVelocity(k) * dispersion.phaseVelocity(k);
    }

    std::vector<CrossingMethods::Verdict> CrossingMethods::evaluate(const Traveller &traveller,
                                                                    double force)
    {
        const double c = PhysicalScales::lightSpeed();
        const double mu = traveller.mu();
        const bool massless = mu == 0.0;
        const double startAngle = traveller.startAngle();
        const double thresholdMomentum = c * std::sqrt(mu + force * kHalfPi);
        const double entry = std::abs(RoundTrip::entryMomentum(c, mu, force, startAngle));

        std::vector<Verdict> verdicts;
        verdicts.push_back({.method = "push past c with no speed limit",
                            .mechanics = "Newtonian",
                            .supplies = "passage through c at finite time under any force",
                            .completedBy = "the signature change, since the Galilean clock does not react",
                            .completeAsIs = false,
                            .passesLightSpeed = true,
                            .cost = newtonianTimeToSpeed(c, 1.0, 2.0),
                            .costMeaning = "seconds to reach 2c at 1 m/s^2"});
        verdicts.push_back({.method = "accelerate under the standard shell",
                            .mechanics = "special relativity",
                            .supplies = massless ? "a traveller already at the threshold"
                                                 : "a clock that slows and stops at the threshold",
                            .completedBy = "the linear energy scaling of the extended shell",
                            .completeAsIs = false,
                            .passesLightSpeed = false,
                            .cost = massless ? std::numeric_limits<double>::infinity()
                                             : VelocityCrossing::standardEnergy(
                                                   std::atan(0.999999999999)),
                            .costMeaning = "rest energies demanded a part in a million million short of c"});
        verdicts.push_back({.method = massless ? "drive from the threshold under the extended shell"
                                               : "accelerate through the threshold under the extended shell",
                            .mechanics = "extended mass shell",
                            .supplies = "a real far-side state at finite momentum",
                            .completedBy = "nothing",
                            .completeAsIs = true,
                            .passesLightSpeed = !massless,
                            .cost = thresholdMomentum - entry,
                            .costMeaning = "momentum the accelerator adds before the threshold, kg m/s per hbar"});
        verdicts.push_back({.method = "bend the metric through its degenerate point",
                            .mechanics = "metric family",
                            .supplies = "a far side reached with no push on the traveller",
                            .completedBy = "the shell reversed along with the metric, mu -> -mu and the energy's square with it",
                            .completeAsIs = false,
                            .needsExternalField = true,
                            .passesLightSpeed = true,
                            .cost = 0.0,
                            .costMeaning = "no momentum added to the traveller"});
        verdicts.push_back({.method = "bend the metric and reverse the shell with it",
                            .mechanics = "metric family with the shell reversed",
                            .supplies = "a real far-side state with no push on the traveller",
                            .completedBy = "nothing",
                            .completeAsIs = hasRealFarSideMomentumWithReversedShell(traveller, kFarAngle, 2.0 * mu + 1.0),
                            .needsExternalField = true,
                            .passesLightSpeed = true,
                            .cost = bendTension(),
                            .costMeaning = "wall tension in the model's units, an external cost not laid on the traveller"});
        verdicts.push_back({.method = "tunnel through a degenerate layer",
                            .mechanics = "quantum mechanics",
                            .supplies = "transmission across the layer with no acceleration",
                            .completedBy = "a far-side state to land in, from the extended shell",
                            .completeAsIs = false,
                            .passesLightSpeed = false,
                            .cost = 1.0 - tunnellingTransmission(traveller, kProbeThickness),
                            .costMeaning = "fraction lost across a 1e-16 m layer"});
        return verdicts;
    }

    CrossingMethods::Verdict CrossingMethods::best(const Traveller &traveller, double force)
    {
        const std::vector<Verdict> all = evaluate(traveller, force);
        auto complete = all | std::views::filter([](const Verdict &v) {
                            return v.completeAsIs && !v.needsExternalField;
                        });
        return *std::ranges::min_element(complete, {}, &Verdict::cost);
    }
}
