#include "particle/RigidMolecule.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "particle/ReturnEvent.h"
#include "units/PhysicalScales.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        using Three = std::array<double, 3>;

        constexpr double kOmega = 4.0;
        constexpr double kThickness = 8.0;

        double norm(const Three &v)
        {
            return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        }

        double angleBetween(const Three &a, const Three &b)
        {
            const double dot = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
            const double cosine = dot / (norm(a) * norm(b));
            return std::acos(std::clamp(cosine, -1.0, 1.0));
        }

        Three effectiveVector(const ReturnEvent::Event &event)
        {
            return {event.elapsed, event.transverseFirst, event.transverseSecond};
        }
    }

    void RigidMoleculeSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double pi = std::acos(-1.0);
        const double s = 1.0 / std::sqrt(3.0);
        const std::array<Three, 4> directions{{{s, s, s}, {s, -s, -s}, {-s, s, -s}, {-s, -s, s}}};

        report.subsection("The tetrahedral angle, among the launch directions alone");
        const double referenceAngle = angleBetween(directions[0], directions[1]);
        double worstAngleSpread = 0.0;
        for (std::size_t i = 0; i < directions.size(); ++i)
        {
            for (std::size_t j = i + 1; j < directions.size(); ++j)
            {
                worstAngleSpread = std::max(worstAngleSpread,
                                            std::abs(angleBetween(directions[i], directions[j]) -
                                                     referenceAngle));
            }
        }
        report.checkNear("  all six pairs of launch directions carry the same angle", worstAngleSpread);
        report.check(std::format("  the shared angle is {:.4f} rad, {:.2f} degrees, the standard "
                                 "tetrahedral value",
                                 referenceAngle, referenceAngle * 180.0 / pi),
                    std::abs(referenceAngle * 180.0 / pi - 109.4712) < 0.01);

        report.subsection("Masses against the ceiling of one shared drive");
        const double muH = PhysicalScales::hydrogenAtomMass() / PhysicalScales::protonMass();
        const double muC = PhysicalScales::carbonMass() / PhysicalScales::protonMass();
        report.check(std::format("  mu(H) = {:.6f}, mu(C) = {:.6f}, against the ceiling omega^2 = "
                                 "{:.4f}",
                                 muH, muC, kOmega * kOmega),
                    muH < kOmega * kOmega && muC < kOmega * kOmega);
        report.check("  a drive of 2.8, the value used throughout the rest of this project, would "
                    "fail this ceiling for carbon alone, since 2.8^2 = 7.84 is below mu(C); the "
                    "drive is raised here for that reason and stated as raised",
                    muC > 2.8 * 2.8);

        const double lengthH = std::sqrt(kOmega * kOmega / (c * c) - muH);
        const double lengthC = std::sqrt(kOmega * kOmega / (c * c) - muC);
        report.check(std::format("  mass-shell length: hydrogen {:.6f}, carbon {:.6f}", lengthH,
                                 lengthC),
                    std::isfinite(lengthH) && std::isfinite(lengthC));

        report.subsection("Five states, four tetrahedral satellites and one central reference");
        std::array<ReturnEvent::Event, 4> satelliteEvents{};
        for (std::size_t i = 0; i < directions.size(); ++i)
        {
            const ReturnEvent::State state{
                {lengthH * directions[i][0], lengthH * directions[i][1], lengthH * directions[i][2]},
                1};
            satelliteEvents[i] = ReturnEvent::map(state, Kind::Euclidean, c, muH, kThickness);
        }
        const ReturnEvent::State centralState{{lengthC, 0.0, 0.0}, 1};
        const ReturnEvent::Event centralEvent =
            ReturnEvent::map(centralState, Kind::Euclidean, c, muC, kThickness);
        for (std::size_t i = 0; i < satelliteEvents.size(); ++i)
        {
            report.check(std::format("  satellite {} : t = {:.6f}, transverse ({:+.6f}, {:+.6f})",
                                     i, satelliteEvents[i].elapsed, satelliteEvents[i].transverseFirst,
                                     satelliteEvents[i].transverseSecond),
                        std::isfinite(satelliteEvents[i].elapsed));
        }
        report.check(std::format("  central mass : t = {:.6f}, transverse ({:+.6f}, {:+.6f})",
                                 centralEvent.elapsed, centralEvent.transverseFirst,
                                 centralEvent.transverseSecond),
                    std::isfinite(centralEvent.elapsed));

        report.subsection("Whether the four satellites still agree on when they return");
        double worstElapsedSpread = 0.0;
        for (const auto &event : satelliteEvents)
        {
            worstElapsedSpread = std::max(worstElapsedSpread,
                                          std::abs(event.elapsed - satelliteEvents[0].elapsed));
        }
        report.checkNear("  the four returned elapsed times agree with each other", worstElapsedSpread,
                        1e-9);
        report.check(std::format("  the central mass returns at a different time, {:.6f} against "
                                 "the satellites' {:.6f}",
                                 centralEvent.elapsed, satelliteEvents[0].elapsed),
                    std::abs(centralEvent.elapsed - satelliteEvents[0].elapsed) > 1e-6);

        report.subsection("Whether the four satellites still agree on the tetrahedral angle");
        const std::array<Three, 4> returned{
            effectiveVector(satelliteEvents[0]), effectiveVector(satelliteEvents[1]),
            effectiveVector(satelliteEvents[2]), effectiveVector(satelliteEvents[3])};
        std::array<double, 6> returnedAngles{};
        std::size_t pairIndex = 0;
        double smallestReturnedAngle = 1e30;
        double largestReturnedAngle = 0.0;
        for (std::size_t i = 0; i < returned.size(); ++i)
        {
            for (std::size_t j = i + 1; j < returned.size(); ++j)
            {
                const double angle = angleBetween(returned[i], returned[j]);
                returnedAngles[pairIndex] = angle;
                ++pairIndex;
                smallestReturnedAngle = std::min(smallestReturnedAngle, angle);
                largestReturnedAngle = std::max(largestReturnedAngle, angle);
            }
        }
        report.check(std::format("  the six returned angles range from {:.4f} to {:.4f} rad, "
                                 "{:.2f} to {:.2f} degrees, against a uniform {:.2f} degrees at "
                                 "launch",
                                 smallestReturnedAngle, largestReturnedAngle,
                                 smallestReturnedAngle * 180.0 / pi,
                                 largestReturnedAngle * 180.0 / pi, referenceAngle * 180.0 / pi),
                    std::isfinite(smallestReturnedAngle) && std::isfinite(largestReturnedAngle));
        report.check(std::format("  the six angles are not equal to each other, spread {:.2e} rad "
                                 "against launch's {:.2e}",
                                 largestReturnedAngle - smallestReturnedAngle, worstAngleSpread),
                    largestReturnedAngle - smallestReturnedAngle > 1e-6);
        report.check(std::format("  every one of the six is far smaller than the launch angle: "
                                 "the largest returned angle is {:.4f} of the launch angle",
                                 largestReturnedAngle / referenceAngle),
                    largestReturnedAngle / referenceAngle < 0.1);

        report.subsection("Why the angle collapses: elapsed time dominates the effective vector");
        report.check(std::format("  the shared elapsed time, {:.4f}, is roughly {:.0f} times "
                                 "larger than either transverse component, {:.6f}",
                                 satelliteEvents[0].elapsed,
                                 std::abs(satelliteEvents[0].elapsed /
                                         satelliteEvents[0].transverseFirst),
                                 satelliteEvents[0].transverseFirst),
                    std::abs(satelliteEvents[0].elapsed) >
                        10.0 * std::abs(satelliteEvents[0].transverseFirst));
        report.check("  a launch direction spread uniformly over a sphere returns with one "
                    "coordinate, the elapsed time, pinned to a single shared value while the "
                    "other two vary; since that shared value dominates the size of the returned "
                    "vector, every pair of returned events is nearly parallel regardless of how "
                    "far apart the launch directions were, and the tetrahedron's angular shape is "
                    "not carried across at any uniform scale, compressed or otherwise",
                    largestReturnedAngle < referenceAngle && largestReturnedAngle - smallestReturnedAngle > 1e-6);

        report.subsection("What this section does and does not show");
        report.check("  the four launch directions were the literal unit vectors of a regular "
                    "tetrahedron, carrying no length of any kind; the physical bond length of a "
                    "real methane molecule is not represented anywhere in this calculation, "
                    "because no rule turning a bond length into an orientation angle is "
                    "established in this project or the literature it draws on",
                    true);
        report.check("  the central mass was given a reference direction rather than a bond "
                    "direction, since its own displacement from the configuration's centre of "
                    "mass is zero by the tetrahedron's symmetry; this section reads the central "
                    "mass's own return event but does not compare it to the satellites' shape",
                    true);
        report.check("  no force, potential or bond dynamics is represented anywhere in this "
                    "project, so the flattening found here is a property of this project's own "
                    "single-particle map applied five times, not a solved five-body trajectory",
                    true);
    }

}
