#include "journey/CrossingMethodsSection.h"
#include "journey/CrossingMethods.h"

#include "core/Report.h"
#include "physics/dynamics/Dispersion.h"
#include "physics/dynamics/ThresholdField.h"
#include "physics/intermediate/DegenerateWindow.h"
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
        constexpr double kQuarterPi = std::numbers::pi / 4.0;
        constexpr double kFarAngle = 3.0 * std::numbers::pi / 8.0;
    }

    void CrossingMethodsSection::run(Report &report) const
    {
        const RoundTrip::Settings settings = RoundTrip::referenceSettings();
        const double c = settings.c;
        const double force = settings.force;
        const std::vector<Traveller> travellers = Traveller::reference();

        report.subsection("What each mechanics supplies and what completes it");
        report.checkNear("  Newtonian mechanics passes c but moves no clock: its clock shift is zero",
                         CrossingMethods::galileanClockShift(), 0.0);
        report.check(std::format("  the standard shell reaches angle {:.6f} after a proper time of 5 c/a, "
                                 "below the threshold {:.6f} as it is for every proper time",
                                 CrossingMethods::standardAngleReached(1.0, 1.0, 5.0), kQuarterPi),
                     CrossingMethods::standardAngleReached(1.0, 1.0, 5.0) < kQuarterPi);
        for (const Traveller &traveller : travellers)
        {
            report.check(std::format("  bending the metric alone leaves the {} without a real far-side "
                                     "momentum, and with the shell reversed along with it there is one",
                                     traveller.name),
                         !CrossingMethods::hasRealFarSideMomentum(traveller, kFarAngle, 2.0 * traveller.mu() + 1.0) &&
                             CrossingMethods::hasRealFarSideMomentumWithReversedShell(
                                 traveller, kFarAngle, 2.0 * traveller.mu() + 1.0));
        }
        report.check(std::format("  tunnelling is lossless for the massless particle at any width, "
                                 "transmission {:g}, and halves for the atom at {:.3e} m, for the molecule at {:.3e} m",
                                 CrossingMethods::tunnellingTransmission(travellers[0], 1.0),
                                 CrossingMethods::tunnellingHalvingWidth(travellers[1]),
                                 CrossingMethods::tunnellingHalvingWidth(travellers[2])),
                     CrossingMethods::tunnellingTransmission(travellers[0], 1.0) == 1.0 &&
                         CrossingMethods::tunnellingHalvingWidth(travellers[2]) <
                             CrossingMethods::tunnellingHalvingWidth(travellers[1]));
        for (const Traveller &traveller : travellers | std::views::drop(1))
        {
            const double k = 1e10;
            report.checkNear(std::format("  the {}'s wave has group times phase velocity equal to c^2, "
                                         "so its phase already runs on the far side of c",
                                         traveller.name),
                             CrossingMethods::groupTimesPhase(traveller, k) / (c * c) - 1.0, 1e-9);
        }

        report.subsection("The way chosen for each traveller");
        for (const Traveller &traveller : travellers)
        {
            const std::vector<CrossingMethods::Verdict> all = CrossingMethods::evaluate(traveller, force);
            const auto completeCount =
                std::ranges::count_if(all, [](const auto &v) { return v.completeAsIs; });
            report.check(std::format("  {}: {} of {} ways are complete as they stand", traveller.name,
                                     completeCount, all.size()),
                         completeCount >= 1);
            const CrossingMethods::Verdict chosen = CrossingMethods::best(traveller, force);
            report.check(std::format("  chosen: {} ({}), costing {:.3e} {}", chosen.method,
                                     chosen.mechanics, chosen.cost, chosen.costMeaning),
                         chosen.completeAsIs && std::isfinite(chosen.cost));
            report.check(std::format("  it {} light speed on the way", chosen.passesLightSpeed
                                                                            ? "passes through"
                                                                            : "starts at, and never needs to reach"),
                         chosen.passesLightSpeed == (traveller.mass > 0.0));
        }
        const CrossingMethods::Verdict light = CrossingMethods::best(travellers[0], force);
        report.checkNear("  the massless particle pays nothing before the threshold, since it starts there",
                         light.cost, 1e-6);
        report.check("  the momentum the accelerator adds before the threshold shrinks with mass, "
                     "since the heavier traveller already carries more of what the threshold demands",
                     CrossingMethods::best(travellers[1], force).cost >
                         CrossingMethods::best(travellers[2], force).cost);
        for (const Traveller &traveller : travellers | std::views::drop(1))
        {
            const auto all = CrossingMethods::evaluate(traveller, force);
            report.check(std::format("  for the {} a second complete way exists, bending the metric with the "
                                     "shell reversed, at a wall tension of {:.3f}, left unchosen because it is external to the traveller",
                                     traveller.name, CrossingMethods::bendTension()),
                         std::ranges::count_if(all, [](const auto &v) { return v.completeAsIs; }) == 2);
        }
    }
}
