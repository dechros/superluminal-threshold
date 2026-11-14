#include "journey/JourneyStateSection.h"
#include "journey/JourneyState.h"

#include "core/Report.h"
#include "physics/units/PhysicalScales.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <format>
#include <ranges>

namespace slm
{
    void JourneyStateSection::run(Report &report) const
    {
        using Sense = RoundTrip::Sense;
        const RoundTrip::Settings settings = RoundTrip::referenceSettings();
        const double c = settings.c;
        const std::vector<Traveller> travellers = Traveller::reference();

        for (const Traveller &traveller : travellers)
        {
            for (Sense sense : {Sense::PlusR, Sense::MinusR})
            {
                report.subsection(std::format("{} along {}", traveller.name,
                                              sense == Sense::PlusR ? "+r" : "-r"));
                const std::vector<JourneyState::Phase> phases = JourneyState::phases(traveller);
                const auto count = static_cast<double>(phases.size());
                report.check(std::format("  the trip has {} phases", phases.size()),
                             phases.size() == (traveller.mass > 0.0 ? 5U : 3U));

                const JourneyState::Sample first = JourneyState::at(traveller, sense, settings, 0.0);
                const JourneyState::Sample last = JourneyState::at(traveller, sense, settings, 1.0);
                report.checkNear("  it starts at the traveller's own angle",
                                 first.theta - traveller.startAngle(), 1e-12);
                report.checkNear("  and ends there", last.theta - traveller.startAngle(), 1e-9);
                report.checkNear("  the far-side position is zero at the start", first.r, 0.0);
                report.checkNear(std::format("  and {:+.3f} m at the end", last.r),
                                 last.r - (sense == Sense::PlusR ? 1.0 : -1.0) * settings.farDistance,
                                 1e-9);
                const RoundTrip::Outcome outcome = RoundTrip::run(traveller, sense, settings);
                report.checkNear("  the final clock shift is the round trip's map shift",
                                 last.nearClockShift - outcome.mapShift, 1e-24);

                double maxJump = 0.0;
                double maxMomentumJump = 0.0;
                for (std::size_t k = 1; k < phases.size(); ++k)
                {
                    const double join = static_cast<double>(k) / count;
                    const JourneyState::Sample before =
                        JourneyState::at(traveller, sense, settings, join - 1e-9);
                    const JourneyState::Sample after =
                        JourneyState::at(traveller, sense, settings, join + 1e-9);
                    maxJump = std::max({maxJump, std::abs(after.theta - before.theta),
                                        std::abs(after.r - before.r),
                                        std::abs(after.nearClockShift - before.nearClockShift) * c});
                    maxMomentumJump = std::max(
                        maxMomentumJump,
                        std::abs(std::abs(after.momentum) - std::abs(before.momentum)) /
                            std::abs(before.momentum));
                }
                report.checkNear("  angle, far-side position and clock are continuous across every "
                                 "phase join",
                                 maxJump, 1e-6);
                report.checkNear("  and the magnitude of the angle's momentum is continuous too, held "
                                 "through the far side and reflected at the return",
                                 maxMomentumJump, 1e-9);
                const JourneyState::Sample onFar = JourneyState::at(traveller, sense, settings, 0.5);
                report.check(std::format("  halfway along the far side the drive's own momentum is {:.3e}, "
                                         "built up by the force from the rest state it started in",
                                         onFar.farMomentum),
                             std::abs(onFar.farMomentum) > 0.0);

                bool monotone = true;
                double previous = -1.0;
                for (int i : std::views::iota(0, 101))
                {
                    const double progress = i / 100.0;
                    const JourneyState::Sample s = JourneyState::at(traveller, sense, settings, progress);
                    const bool outwardHalf = s.phase == JourneyState::Phase::BelowLightOut ||
                                             s.phase == JourneyState::Phase::AboveLightOut;
                    if (outwardHalf && s.theta < previous - 1e-12)
                    {
                        monotone = false;
                    }
                    if (outwardHalf)
                    {
                        previous = s.theta;
                    }
                }
                report.check("  the angle rises monotonically on the way out", monotone);

                const JourneyState::Sample threshold = JourneyState::at(
                    traveller, sense, settings,
                    traveller.mass > 0.0 ? 1.0 / count : 0.0);
                report.checkNear("  at the first phase join the metric's four entries vanish together",
                                 std::ranges::max(threshold.metric | std::views::transform(
                                                                        [](double v) { return std::abs(v); })),
                                 1e-6);
                report.check("  beyond it the metric's entries have the opposite signs to the start",
                             JourneyState::at(traveller, sense, settings, 0.5).metric[0] * first.metric[0] <
                                 0.0 || traveller.mass == 0.0);
                if (traveller.hasShape())
                {
                    const JourneyState::Sample mid = JourneyState::at(traveller, sense, settings, 0.5);
                    report.check(std::format("  on the far side the {} atoms share one r and differ in the "
                                             "three times",
                                             mid.farAtoms.size()),
                                 std::ranges::all_of(mid.farAtoms, [&](const auto &a) {
                                     return std::abs(a[3] - mid.r) < 1e-30;
                                 }));
                }
            }
        }
    }
}
