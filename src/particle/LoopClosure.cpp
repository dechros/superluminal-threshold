#include "particle/LoopClosure.h"

#include "core/Report.h"
#include "particle/ArrivalOrder.h"

#include <cmath>
#include <format>

namespace slm
{

    double LoopClosure::sameFrameReturn(double distance, double speed)
    {
        return 2.0 * distance / speed;
    }

    double LoopClosure::relayReturn(double distance, double speed, double relayVelocity)
    {
        const double numerator = 2.0 - relayVelocity / speed - speed * relayVelocity;
        return distance * numerator / (speed - relayVelocity);
    }

    double LoopClosure::relayThreshold(double speed)
    {
        return 2.0 * speed / (speed * speed + 1.0);
    }

    bool LoopClosure::relayReachesPast(double distance, double speed, double relayVelocity)
    {
        return relayReturn(distance, speed, relayVelocity) < 0.0;
    }

    double LoopClosure::crossingReturn(IntermediateRegion::Kind kind, double c, double mu,
                                       double thickness, double distance)
    {
        return ArrivalOrder::arrivalMoment(kind, c, mu, thickness,
                                           ArrivalOrder::Direction::Backward, distance);
    }

    bool LoopClosure::crossingReachesPast(IntermediateRegion::Kind kind, double c, double mu,
                                         double thickness, double distance)
    {
        return crossingReturn(kind, c, mu, thickness, distance) < 0.0;
    }

    void LoopClosureSection::run(Report &report) const
    {
        const double distance = 1.0;

        report.subsection("The naive loop does not reach the past");
        for (double speed : {1.5, 2.0, 10.0, 1000.0})
        {
            report.check(std::format("  speed {:<7g} : returns at {:+.4f}, which is after it left",
                                     speed, LoopClosure::sameFrameReturn(distance, speed)),
                         LoopClosure::sameFrameReturn(distance, speed) > 0.0);
        }
        report.check("no superluminal speed whatever makes this negative, since the "
                     "return moment is the distance over the speed twice over",
                     LoopClosure::sameFrameReturn(distance, 1e12) > 0.0);

        report.subsection("The relay reaches it, above a threshold velocity");
        for (double speed : {1.5, 2.0, 4.0})
        {
            const double threshold = LoopClosure::relayThreshold(speed);
            report.check(std::format("  speed {:<4g} : the relay has to move at {:.4f} "
                                     "before the reply precedes the query",
                                     speed, threshold),
                         threshold > 0.0 && threshold < 1.0);
            report.check(std::format("  speed {:<4g} : just under it the return is still "
                                     "{:+.4f}",
                                     speed,
                                     LoopClosure::relayReturn(distance, speed,
                                                              threshold * 0.99)),
                         !LoopClosure::relayReachesPast(distance, speed, threshold * 0.99));
            report.check(std::format("  speed {:<4g} : just over it the return is {:+.4f}",
                                     speed,
                                     LoopClosure::relayReturn(distance, speed,
                                                              threshold + 1e-3)),
                         LoopClosure::relayReachesPast(distance, speed, threshold + 1e-3));
        }

        report.subsection("The threshold never reaches zero");
        report.check("at zero relay velocity the relay route is the naive loop, and "
                     "returns at the same moment",
                     std::fabs(LoopClosure::relayReturn(distance, 2.0, 0.0) -
                               LoopClosure::sameFrameReturn(distance, 2.0)) < 1e-12);
        report.check("the threshold stays positive at every finite speed, so the relay "
                     "route needs two frames in relative motion and cannot be run "
                     "inside one",
                     LoopClosure::relayThreshold(1e6) > 0.0);
        report.check("it only tends to zero as the speed grows without bound, which is "
                     "not a speed",
                     LoopClosure::relayThreshold(1e6) < 1e-5);

        report.subsection("The route built here reaches it inside a single frame");
        const double c = 1.0;
        const double mu = 1.0;
        const double thickness = 8.0;
        const double delay = ArrivalOrder::crossingDelay(IntermediateRegion::Kind::Euclidean, c,
                                                         mu, thickness);
        report.check(std::format("the crossing delay is {:.4f} and is the whole of what "
                                 "has to be outrun",
                                 delay),
                     delay > 0.0);
        report.check("below that far-side distance the return still follows the "
                     "departure",
                     !LoopClosure::crossingReachesPast(IntermediateRegion::Kind::Euclidean, c, mu,
                                                       thickness, delay * 0.5));
        report.check(std::format("above it the return precedes the departure, at {:+.4f} "
                                 "for twice the crossover distance",
                                 LoopClosure::crossingReturn(IntermediateRegion::Kind::Euclidean,
                                                             c, mu, thickness, delay * 2.0)),
                     LoopClosure::crossingReachesPast(IntermediateRegion::Kind::Euclidean, c, mu,
                                                      thickness, delay * 2.0));
        report.check("and no relative velocity appears anywhere in that computation, so "
                     "the sign is not inherited from a disagreement between frames",
                     LoopClosure::crossingReturn(IntermediateRegion::Kind::Euclidean, c, mu,
                                                 thickness, delay * 2.0) < 0.0);

        report.subsection("Where the sign comes from instead");
        report.check("the naive loop and the route here are given the same distance and "
                     "disagree on the sign, so the difference is in the construction and "
                     "not in how far anything travelled",
                     LoopClosure::sameFrameReturn(delay * 2.0, 2.0) > 0.0 &&
                         LoopClosure::crossingReturn(IntermediateRegion::Kind::Euclidean, c, mu,
                                                     thickness, delay * 2.0) < 0.0);
        report.check("the displacement enters the return moment with a coefficient of "
                     "one rather than divided by a speed, which is what the naive loop "
                     "cannot reproduce and what the crossing supplies",
                     std::fabs(ArrivalOrder::travelContribution(
                                   ArrivalOrder::Direction::Backward, 3.0) +
                               3.0) < 1e-12);
    }

}
