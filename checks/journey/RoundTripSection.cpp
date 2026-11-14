#include "journey/RoundTripSection.h"
#include "journey/RoundTrip.h"

#include "core/Report.h"
#include "particle/AcceleratedCrossing.h"
#include "particle/ConstantForce.h"
#include "particle/PairedExcursion.h"
#include "particle/TimeProjection.h"
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

        double distance(const RoundTrip::Three &a, const RoundTrip::Three &b)
        {
            return std::hypot(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
        }
    }

    void RoundTripSection::run(Report &report) const
    {
        using Sense = RoundTrip::Sense;
        const RoundTrip::Settings settings = RoundTrip::referenceSettings();
        const double c = settings.c;
        const double lightTime = PhysicalScales::advanceForDistance(settings.farDistance);
        const std::vector<Traveller> travellers = Traveller::reference();
        const std::array senses{Sense::PlusR, Sense::MinusR};

        std::vector<RoundTrip::Outcome> outcomes;
        for (const Traveller &traveller : travellers)
        {
            for (Sense sense : senses)
            {
                const std::string_view way = sense == Sense::PlusR ? "+r, backward in time" : "-r, forward in time";
                report.subsection(std::format("{} along {}", traveller.name, way));
                const RoundTrip::Outcome out = RoundTrip::run(traveller, sense, settings);
                outcomes.push_back(out);

                report.check(std::format("  mass parameter mu = {:.3e} 1/m^2, start speed {:g}c",
                                         out.mu, traveller.startSpeed()),
                             std::isfinite(out.mu));
                if (traveller.mass > 0.0)
                {
                    const double restRate = RoundTrip::clockRate(0.0);
                    const double halfRate = RoundTrip::clockRate(std::atan(0.5));
                    const double nearRate = RoundTrip::clockRate(std::atan(0.99));
                    report.check(std::format("  its clock runs at {:.3f} at rest, {:.3f} at 0.5c "
                                             "and {:.3f} at 0.99c: time slows",
                                             restRate, halfRate, nearRate),
                                 restRate == 1.0 && halfRate < restRate && nearRate < halfRate);
                    report.check(std::format("  light speed is reached at parameter {:.3e}, "
                                             "where the clock rate is {:g}: time stops",
                                             out.thresholdParameter,
                                             RoundTrip::clockRate(kQuarterPi)),
                                 out.thresholdParameter > 0.0 &&
                                     RoundTrip::clockRate(kQuarterPi) < 1e-7);
                }
                else
                {
                    report.check("  it is born at light speed, so its clock never ran and the "
                                 "threshold is reached at parameter zero",
                                 out.thresholdParameter == 0.0 &&
                                     RoundTrip::clockRate(out.startAngle) < 1e-7);
                    report.checkNear("  its entry momentum is exactly the momentum a massive "
                                     "crossing demands at light speed",
                                     std::abs(out.entryMomentum) / out.thresholdMomentum - 1.0,
                                     1e-12);
                }
                report.check(std::format("  the momentum demanded at light speed is finite, "
                                         "{:.3e} 1/s as momentum per hbar",
                                         out.thresholdMomentum),
                             std::isfinite(out.thresholdMomentum) && out.thresholdMomentum > 0.0);
                report.check(std::format("  the far side is reached at parameter {:.3e}",
                                         out.outwardParameter),
                             std::isfinite(out.outwardParameter) &&
                                 out.outwardParameter > out.thresholdParameter);
                report.checkNear("  the shell holds along the whole outward leg",
                                 out.maxOutwardResidual, 1e-9);
                report.check(std::format("  {:g} m along the far side's space axis takes "
                                         "parameter {:.3e}, and the signed branch ends at r = {:+.3f} m",
                                         settings.farDistance, out.farSideParameter,
                                         RoundTrip::farSidePosition(c, out.mu, settings.force, sense,
                                                                    out.farSideParameter)),
                             std::isfinite(out.farSideParameter) && out.farSideParameter > 0.0 &&
                                 std::abs(RoundTrip::farSidePosition(c, out.mu, settings.force, sense,
                                                                     out.farSideParameter) -
                                          (sense == Sense::PlusR ? 1.0 : -1.0) * settings.farDistance) <
                                     1e-9);
                {
                    const RoundTrip::Four drift = RoundTrip::farSideImage({0.0, 0.0, 0.0});
                    report.check("  the drive starts from the far side's rest state, with no energy along "
                                 "the three time axes, so it returns to the place it left",
                                 std::abs(drift[0]) + std::abs(drift[1]) + std::abs(drift[2]) == 0.0);
                }
                report.checkNear("  the far-side shell holds along that signed branch",
                                 out.maxFarSideResidual, 1e-9);
                report.checkNear("  the return leg starts where the outward leg ended, at pi/2",
                                 out.joinAngleResidual, 1e-9);
                report.checkNear("  with the outward momentum reflected, its magnitude unchanged",
                                 out.joinMomentumResidual, 1e-12);
                report.checkNear("  both Hamilton equations hold along the return leg, by central "
                                 "difference",
                                 out.maxHamiltonResidual, 1e-6);
                report.checkNear("  and the shell holds along it with the same mass parameter",
                                 out.maxReturnResidual, 1e-9);
                report.checkNear(std::format("  it returns at speed {:g}c, the speed it left with",
                                             out.speedAtReturn),
                                 out.speedAtReturn - traveller.startSpeed(), 1e-12);
                report.checkNear("  with the momentum magnitude it left with",
                                 out.momentumAtReturn / std::abs(out.entryMomentum) - 1.0, 1e-12);
                report.checkNear("  and with the mass parameter it left with",
                                 (out.massAtReturn - out.mu) /
                                     std::max(out.mu, out.thresholdMomentum * out.thresholdMomentum / (c * c)),
                                 1e-12);
                const double expectedSign = sense == Sense::PlusR ? -1.0 : 1.0;
                report.check(std::format("  the near-side clock moves by {:+.6e} s under the "
                                         "velocity reading",
                                         out.netShiftVelocity),
                             out.netShiftVelocity * expectedSign > 0.0 &&
                                 std::abs(std::abs(out.netShiftVelocity) - lightTime) < 1e-24);
                report.check(std::format("  and by {:+.6e} s under the field-wall reading, "
                                         "whose round-trip delay is {:.3e} s",
                                         out.netShiftFieldWall, out.wallDelay),
                             out.netShiftFieldWall * expectedSign > 0.0 && out.wallDelay > 0.0);

                if (traveller.hasShape())
                {
                    const auto space = static_cast<std::size_t>(TimeProjection::farSideSpaceSlot());
                    double maxR = 0.0;
                    double maxTime = 0.0;
                    for (const RoundTrip::Four &far : out.farSideAtoms)
                    {
                        maxR = std::max(maxR, std::abs(far[space]));
                        for (int slot : TimeProjection::farSideTimeSlots())
                        {
                            maxTime = std::max(maxTime,
                                               std::abs(far[static_cast<std::size_t>(slot)]));
                        }
                    }
                    report.check(std::format("  on the far side all {} atoms sit at the same r, "
                                             "spread {:.1e} m: the molecule is a point in space there",
                                             out.farSideAtoms.size(), maxR),
                                 maxR < 1e-30);
                    report.check(std::format("  and they are spread over the three times by up "
                                             "to {:.3e} s: its shape is a pattern in time there",
                                             maxTime / c),
                                 maxTime > 0.0);
                    const auto [lo, hi] = std::ranges::minmax(out.atomClockShifts);
                    report.checkNear("  every atom receives the same clock shift", hi - lo, 1e-24);
                    double maxBondError = 0.0;
                    for (std::size_t i = 1; i < traveller.atoms.size(); ++i)
                    {
                        maxBondError = std::max(
                            maxBondError,
                            std::abs(distance(out.returnedAtoms[i], out.returnedAtoms[0]) -
                                     distance(traveller.atoms[i], traveller.atoms[0])));
                    }
                    report.checkNear("  every bond length comes back unchanged", maxBondError, 1e-25);
                    const double before = RoundTrip::signedVolume(traveller.atoms);
                    const double after = RoundTrip::signedVolume(out.returnedAtoms);
                    report.check(std::format("  the signed volume of the labelled bonds is "
                                             "{:+.3e} before and {:+.3e} after: handedness kept",
                                             before, after),
                                 before != 0.0 && std::abs(after - before) < 1e-12 * std::abs(before));
                }
            }
        }

        report.subsection("The other molecules keep their shape too");
        for (const Traveller &molecule : {Traveller::water(), Traveller::ammonia(),
                                          Traveller::bromochlorofluoromethane()})
        {
            const RoundTrip::Outcome out = RoundTrip::run(molecule, Sense::PlusR, settings);
            double maxBondError = 0.0;
            for (std::size_t i = 1; i < molecule.atoms.size(); ++i)
            {
                maxBondError = std::max(maxBondError,
                                        std::abs(distance(out.returnedAtoms[i], out.returnedAtoms[0]) -
                                                 distance(molecule.atoms[i], molecule.atoms[0])));
            }
            report.checkNear(std::format("  {}: every bond length returns unchanged", molecule.name),
                             maxBondError, 1e-25);
            const double before = RoundTrip::signedVolume(molecule.atoms);
            const double after = RoundTrip::signedVolume(out.returnedAtoms);
            if (molecule.atoms.size() >= 4)
            {
                report.check(std::format("  {}: signed volume {:+.3e} before, {:+.3e} after, handedness kept",
                                         molecule.name, before, after),
                             before != 0.0 && std::abs(after - before) < 1e-12 * std::abs(before));
            }
            const auto [lo, hi] = std::ranges::minmax(out.atomClockShifts);
            report.checkNear(std::format("  {}: every atom receives the same clock shift", molecule.name),
                             hi - lo, 1e-24);
        }

        report.subsection("What the six trips share");
        for (std::size_t i = 0; i < travellers.size(); ++i)
        {
            const double gap = outcomes[2 * i + 1].netShiftFieldWall - outcomes[2 * i].netShiftFieldWall;
            report.checkNear(std::format("  {}: the gap between its forward and backward trip is "
                                         "twice the light time of {:g} m, and the wall drops out of it",
                                         travellers[i].name, settings.farDistance),
                             gap - PairedExcursion::separation(settings.farDistance), 1e-24);
        }
        report.checkNear("  the massless particle and the molecule shift the clock by the same "
                         "amount: the shift is set by the distance, not by what travelled",
                         outcomes[0].netShiftVelocity - outcomes[4].netShiftVelocity, 1e-30);
        report.check(std::format("  the momentum demanded at light speed grows with mass: {:.3e} "
                                 "for the massless particle, {:.3e} for the atom, {:.3e} for the molecule",
                                 outcomes[0].thresholdMomentum, outcomes[2].thresholdMomentum,
                                 outcomes[4].thresholdMomentum),
                     outcomes[0].thresholdMomentum < outcomes[2].thresholdMomentum &&
                         outcomes[2].thresholdMomentum < outcomes[4].thresholdMomentum);
        const double breakEven =
            PairedExcursion::breakEvenDistance(settings.wallWidth, settings.wallTolerance, 1.0);
        report.check(std::format("  under the field-wall reading the backward trips beat the wall "
                                 "because {:g} m exceeds the break-even distance of {:.3e} m",
                                 settings.farDistance, breakEven),
                     settings.farDistance > breakEven &&
                         outcomes[0].netShiftFieldWall < 0.0 && outcomes[2].netShiftFieldWall < 0.0 &&
                         outcomes[4].netShiftFieldWall < 0.0);
    }
}
