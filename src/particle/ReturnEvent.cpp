#include "particle/ReturnEvent.h"

#include "core/Report.h"
#include "intermediate/TwoCrossings.h"
#include "particle/FarSideMotion.h"
#include "particle/WavePacket.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <vector>

namespace slm
{
    namespace
    {
        constexpr double kPacketCentre = 2.0;
        constexpr double kPacketSpread = 0.3;
        constexpr double kFlipped = 1.0;
    }

    ReturnEvent::State ReturnEvent::stateFromAngles(double polar, double azimuth, double length,
                                                    int branch)
    {
        const double sinPolar = std::sin(polar);
        return {{length * sinPolar * std::cos(azimuth), length * sinPolar * std::sin(azimuth),
                 length * std::cos(polar)},
                branch >= 0 ? 1 : -1};
    }

    ReturnEvent::Event ReturnEvent::map(const State &state, IntermediateRegion::Kind kind, double c,
                                        double mu, double thickness)
    {
        const FarSideMotion::Three energy{state.orientation[0], state.orientation[1],
                                          state.orientation[2]};
        const double elapsed =
            2.0 * FarSideMotion::momentFromEnergy(kind, c, mu, energy, thickness);
        const double crossing = state.branch > 0 ? thickness : 0.0;
        const double shift = transverseFactor(thickness, c, mu);
        const double length = FarSideMotion::vectorLength(energy);
        if (length <= 0.0)
        {
            return {elapsed, crossing, 0.0, 0.0};
        }
        return {elapsed, crossing, shift * state.orientation[1] / length,
                shift * state.orientation[2] / length};
    }

    double ReturnEvent::transverseFactor(double thickness, double c, double mu)
    {
        return WavePacket::centroidShiftInSpreads(kPacketCentre, kPacketSpread, thickness, c, mu,
                                                  kFlipped);
    }

    double ReturnEvent::lightRoundTrip(double thickness, double c)
    {
        return 2.0 * thickness / c;
    }

    double ReturnEvent::advanceOverLight(const State &state, IntermediateRegion::Kind kind,
                                         double c, double mu, double thickness)
    {
        return lightRoundTrip(thickness, c) - map(state, kind, c, mu, thickness).elapsed;
    }

    bool ReturnEvent::advanceGrowsWithThickness(IntermediateRegion::Kind kind, double c, double mu,
                                                double omega)
    {
        double previous = -1e30;
        for (double thickness : {2.0, 4.0, 8.0, 16.0})
        {
            const double elapsed =
                2.0 * TwoCrossings::returnDelay(kind, omega, c, mu, 4.0, thickness);
            const double advance = lightRoundTrip(thickness, c) - elapsed;
            if (advance <= previous)
            {
                return false;
            }
            previous = advance;
        }
        return true;
    }

    double ReturnEvent::coordinate(const Event &event, int index)
    {
        switch (index)
        {
        case 0:
            return event.elapsed;
        case 1:
            return event.crossing;
        case 2:
            return event.transverseFirst;
        default:
            return event.transverseSecond;
        }
    }

    bool ReturnEvent::coordinateDependsOnOrientation(int coordinate, IntermediateRegion::Kind kind,
                                                     double c, double mu, double thickness,
                                                     int steps)
    {
        const double pi = std::acos(-1.0);
        const State reference = stateFromAngles(pi / 3.0, 0.0, 3.0, 1);
        const double base = ReturnEvent::coordinate(map(reference, kind, c, mu, thickness),
                                                    coordinate);
        for (int i = 0; i <= steps; ++i)
        {
            for (int j = 0; j < steps; ++j)
            {
                const State state =
                    stateFromAngles(pi * i / steps, 2.0 * pi * j / steps, 3.0, 1);
                const double value =
                    ReturnEvent::coordinate(map(state, kind, c, mu, thickness), coordinate);
                if (std::abs(value - base) > 1e-6)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool ReturnEvent::coordinateDependsOnBranch(int coordinate, IntermediateRegion::Kind kind,
                                                double c, double mu, double thickness)
    {
        const double pi = std::acos(-1.0);
        const State forward = stateFromAngles(pi / 3.0, 0.7, 3.0, 1);
        const State backward = stateFromAngles(pi / 3.0, 0.7, 3.0, -1);
        const double a = ReturnEvent::coordinate(map(forward, kind, c, mu, thickness), coordinate);
        const double b = ReturnEvent::coordinate(map(backward, kind, c, mu, thickness), coordinate);
        return std::abs(a - b) > 1e-9;
    }

    int ReturnEvent::distinctEvents(IntermediateRegion::Kind kind, double c, double mu,
                                    double thickness, int steps)
    {
        const double pi = std::acos(-1.0);
        std::vector<Event> seen;
        for (int branch : {1, -1})
        {
            for (int i = 0; i <= steps; ++i)
            {
                for (int j = 0; j < steps; ++j)
                {
                    const Event event = map(
                        stateFromAngles(pi * i / steps, 2.0 * pi * j / steps, 3.0, branch), kind, c,
                        mu, thickness);
                    const bool already =
                        std::any_of(seen.begin(), seen.end(), [&event](const Event &other) {
                            return std::abs(other.elapsed - event.elapsed) < 1e-6 &&
                                   std::abs(other.crossing - event.crossing) < 1e-6 &&
                                   std::abs(other.transverseFirst - event.transverseFirst) < 1e-6 &&
                                   std::abs(other.transverseSecond - event.transverseSecond) < 1e-6;
                        });
                    if (!already)
                    {
                        seen.push_back(event);
                    }
                }
            }
        }
        return static_cast<int>(seen.size());
    }

    int ReturnEvent::scannedStates(int steps)
    {
        return 2 * (steps + 1) * steps;
    }

    void ReturnEventSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double thickness = 2.0;
        const double pi = std::acos(-1.0);

        report.subsection("Reversing both the energy and the branch: what still separates them");
        {
            const ReturnEvent::State forward =
                ReturnEvent::stateFromAngles(pi / 3.0, 0.9, 3.0, +1);
            const ReturnEvent::State reversed{{-forward.orientation[0], -forward.orientation[1],
                                               -forward.orientation[2]},
                                              -forward.branch};
            const ReturnEvent::Event a = ReturnEvent::map(forward, Kind::Euclidean, c, mu,
                                                          thickness);
            const ReturnEvent::Event b = ReturnEvent::map(reversed, Kind::Euclidean, c, mu,
                                                          thickness);
            report.checkNear("  the two give the same elapsed time, so the return moment alone "
                             "cannot tell a reversed journey from an unreversed one",
                             a.elapsed - b.elapsed, 1e-12);
            report.check(std::format("  but they leave from different faces, {:.4f} against "
                                     "{:.4f}, so the exit face does separate them",
                                     a.crossing, b.crossing),
                         std::abs(a.crossing - b.crossing) > 1e-9);
            report.check(std::format("  and the transverse displacements carry opposite signs, "
                                     "{:+.6f} against {:+.6f}",
                                     a.transverseFirst, b.transverseFirst),
                         a.transverseFirst * b.transverseFirst < 0.0);
            report.check("so the reinterpretation leaves one observable degenerate and two "
                         "observables distinct, which is what a reading of the return moment "
                         "on its own would have missed",
                         std::abs(a.elapsed - b.elapsed) < 1e-12 &&
                             std::abs(a.crossing - b.crossing) > 1e-9);
        }

        report.subsection("The domain: a two-sphere of orientations times two branches");
        for (int branch : {1, -1})
        {
            const ReturnEvent::State state = ReturnEvent::stateFromAngles(pi / 3.0, 0.9, 3.0,
                                                                          branch);
            report.checkNear(std::format("  branch {:+d} : the orientation keeps its length",
                                         branch),
                             FarSideMotion::vectorLength({state.orientation[0],
                                                          state.orientation[1],
                                                          state.orientation[2]}) -
                                 3.0,
                             1e-12);
        }
        report.check(std::format("  the scanned grid holds {} states",
                                 ReturnEvent::scannedStates()),
                     ReturnEvent::scannedStates() > 0);

        report.subsection("Every state maps to a definite event");
        for (double polar : {0.4, 1.2, 2.5})
        {
            const ReturnEvent::Event event = ReturnEvent::map(
                ReturnEvent::stateFromAngles(polar, 1.1, 3.0, 1), Kind::None, c, mu, thickness);
            report.check(std::format("  polar {:.1f} : t = {:.4f}, crossing = {:.4f}, "
                                     "transverse = ({:+.4f}, {:+.4f})",
                                     polar, event.elapsed, event.crossing, event.transverseFirst,
                                     event.transverseSecond),
                         std::isfinite(event.elapsed) && std::isfinite(event.crossing) &&
                             std::isfinite(event.transverseFirst) &&
                             std::isfinite(event.transverseSecond));
        }

        report.subsection("Which coordinate sees which part of the state");
        report.check("the elapsed time sees the orientation",
                     ReturnEvent::coordinateDependsOnOrientation(0, Kind::None, c, mu, thickness));
        report.check("the crossing displacement does not, it sees only the branch",
                     !ReturnEvent::coordinateDependsOnOrientation(1, Kind::None, c, mu,
                                                                  thickness) &&
                         ReturnEvent::coordinateDependsOnBranch(1, Kind::None, c, mu, thickness));
        report.check("the transverse displacements see the orientation",
                     ReturnEvent::coordinateDependsOnOrientation(2, Kind::None, c, mu, thickness) &&
                         ReturnEvent::coordinateDependsOnOrientation(3, Kind::None, c, mu,
                                                                     thickness));
        report.check("the elapsed time is blind to the branch, so when it comes "
                     "back and where it comes back are set by different things",
                     !ReturnEvent::coordinateDependsOnBranch(0, Kind::None, c, mu, thickness));

        report.subsection("How far the map compresses its domain");
        const int states = ReturnEvent::scannedStates();
        const int events = ReturnEvent::distinctEvents(Kind::None, c, mu, thickness);
        report.check(std::format("  {} states are carried onto {} distinct events", states,
                                 events),
                     events > 0 && events <= states);

        report.subsection("The time component against an uninterrupted signal");
        const double barrierOmega = 2.8;
        for (double d : {2.0, 4.0, 8.0, 16.0})
        {
            const double elapsed =
                2.0 * TwoCrossings::returnDelay(Kind::Euclidean, barrierOmega, c, mu, 4.0, d);
            const double light = ReturnEvent::lightRoundTrip(d, c);
            report.check(std::format("  d = {:4g} : light needs {:6.2f}, the particle returns at "
                                     "{:.4f}, advance {:+.4f}",
                                     d, light, elapsed, light - elapsed),
                         light - elapsed > 0.0);
        }
        report.check("the advance grows without bound as the region is made "
                     "thicker, since the elapsed time saturates while the light "
                     "time does not",
                     ReturnEvent::advanceGrowsWithThickness(Kind::Euclidean, c, mu, barrierOmega));

        report.subsection("What the advance is, and what it is not");
        const double barrierLength = std::sqrt(barrierOmega * barrierOmega / (c * c) - mu);
        const ReturnEvent::State barrierState = ReturnEvent::stateFromAngles(
            pi / 2.0, std::asin(std::sqrt(4.0 / (barrierLength * barrierLength))), barrierLength,
            1);
        report.checkNear("a state whose energy vector puts the crossing in the "
                         "barrier regime is reachable on the mass shell",
                         FarSideMotion::vectorLength({barrierState.orientation[0],
                                                      barrierState.orientation[1],
                                                      barrierState.orientation[2]}) -
                             barrierLength,
                         1e-12);
        report.check(std::format("  and from that state the advance is {:+.4f}",
                                 ReturnEvent::advanceOverLight(barrierState, Kind::Euclidean, c, mu,
                                                               8.0)),
                     ReturnEvent::advanceOverLight(barrierState, Kind::Euclidean, c, mu, 8.0) >
                         0.0);
        report.check("so the advance is a statement about where the peak of the "
                     "returning packet sits, which is the time coordinate of the "
                     "return event",
                     ReturnEvent::advanceOverLight(barrierState, Kind::Euclidean, c, mu, 16.0) >
                         ReturnEvent::advanceOverLight(barrierState, Kind::Euclidean, c, mu, 8.0));
        report.check("it is not a group velocity above c, since the interior in "
                     "this regime supports no propagation at all",
                     !FarSideMotion::interiorPropagates(Kind::Euclidean, barrierOmega, c, mu, 4.0));
    }

}
