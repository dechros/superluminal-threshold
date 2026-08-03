#include "particle/ArrivalOrder.h"

#include "core/Report.h"
#include "particle/FlowAssumption.h"
#include "particle/ReturnEvent.h"
#include "scan/CrossingBranches.h"

#include <cmath>
#include <format>

namespace slm
{

    namespace
    {
        constexpr double kPolar = 1.0471975511965976;
        constexpr double kAzimuth = 0.7;
        constexpr double kLength = 3.0;
    }

    double ArrivalOrder::crossingDelay(IntermediateRegion::Kind kind, double c, double mu,
                                       double thickness)
    {
        const ReturnEvent::State state =
            ReturnEvent::stateFromAngles(kPolar, kAzimuth, kLength, 1);
        return ReturnEvent::map(state, kind, c, mu, thickness).elapsed;
    }

    double ArrivalOrder::travelContribution(Direction direction, double distance)
    {
        const double magnitude = FlowAssumption::ourTimeFromTheirSpace(distance);
        return direction == Direction::Forward ? magnitude : -magnitude;
    }

    double ArrivalOrder::arrivalMoment(IntermediateRegion::Kind kind, double c, double mu,
                                       double thickness, Direction direction, double distance)
    {
        return crossingDelay(kind, c, mu, thickness) + travelContribution(direction, distance);
    }

    bool ArrivalOrder::arrivesBeforeEntry(IntermediateRegion::Kind kind, double c, double mu,
                                          double thickness, Direction direction, double distance)
    {
        return arrivalMoment(kind, c, mu, thickness, direction, distance) < 0.0;
    }

    double ArrivalOrder::crossoverDistance(IntermediateRegion::Kind kind, double c, double mu,
                                           double thickness)
    {
        return crossingDelay(kind, c, mu, thickness);
    }

    bool ArrivalOrder::delaySaturates(IntermediateRegion::Kind kind, double c, double mu,
                                      double firstThickness, double secondThickness,
                                      double tolerance)
    {
        const double first = crossingDelay(kind, c, mu, firstThickness);
        const double second = crossingDelay(kind, c, mu, secondThickness);
        return std::abs(second - first) <= tolerance;
    }

    double ArrivalOrder::weight(IntermediateRegion::Kind kind, double c, double mu,
                                double transverseSquared, double thickness)
    {
        return IntermediateRegion::transmission(kind, c, mu, transverseSquared, thickness);
    }

    void ArrivalOrderSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        using Direction = ArrivalOrder::Direction;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;

        report.subsection("The backward branch has to exist for any of this to apply");
        const auto eight = CrossingBranches::orientationPreserving();
        report.check("it does: four of the eight admissible crossings carry the displacement "
                     "backwards",
                     CrossingBranches::countWithSign(eight, -1) == 4);

        report.subsection("One contribution saturates with thickness and the other does not");
        report.check("in the barrier regime the crossing delay stops growing",
                     ArrivalOrder::delaySaturates(Kind::Euclidean, c, mu));
        report.check("  and it does not in the propagating one",
                     !ArrivalOrder::delaySaturates(Kind::Kleinian, c, mu));
        for (double distance : {1.0, 2.0, 4.0, 8.0})
        {
            report.checkNear(
                std::format("  travelling {:g} contributes {:+.4f} forwards and {:+.4f} backwards",
                            distance,
                            ArrivalOrder::travelContribution(Direction::Forward, distance),
                            ArrivalOrder::travelContribution(Direction::Backward, distance)),
                ArrivalOrder::travelContribution(Direction::Forward, distance) +
                    ArrivalOrder::travelContribution(Direction::Backward, distance));
        }

        report.subsection("The saturated delay fixes a crossover distance");
        const double saturated = ArrivalOrder::crossoverDistance(Kind::Euclidean, c, mu, 8.0);
        report.check(std::format("Euclidean, d = 8: the delay is {:.6f}, so the crossover sits "
                                 "at that far-side distance",
                                 saturated),
                     saturated > 0.0);
        report.checkNear("and the crossover is where the arrival moment vanishes",
                         ArrivalOrder::arrivalMoment(Kind::Euclidean, c, mu, 8.0,
                                                     Direction::Backward, saturated),
                         1e-9);

        report.subsection("Beyond it the arrival precedes the entry");
        for (double distance : {2.0, 4.0, 8.0})
        {
            const double moment = ArrivalOrder::arrivalMoment(Kind::Euclidean, c, mu, 8.0,
                                                              Direction::Backward, distance);
            const bool before = ArrivalOrder::arrivesBeforeEntry(Kind::Euclidean, c, mu, 8.0,
                                                                 Direction::Backward, distance);
            report.check(std::format("  distance {:g} : arrival at {:+.4f}{}", distance, moment,
                                     before ? ", before the entry" : ", after the entry"),
                         before == (distance > saturated));
        }
        report.check("the forward branch never does, at any of those distances",
                     !ArrivalOrder::arrivesBeforeEntry(Kind::Euclidean, c, mu, 8.0,
                                                       Direction::Forward, 8.0) &&
                         !ArrivalOrder::arrivesBeforeEntry(Kind::Kleinian, c, mu, 8.0,
                                                           Direction::Forward, 8.0));

        report.subsection("The propagating region does not reach the crossover");
        report.check(std::format("Kleinian, d = 8: the delay is {:.4f}, far beyond the distances "
                                 "examined",
                                 ArrivalOrder::crossingDelay(Kind::Kleinian, c, mu, 8.0)),
                     ArrivalOrder::crossingDelay(Kind::Kleinian, c, mu, 8.0) > 8.0);
        report.check("  so no arrival before entry occurs there for a distance of 8",
                     !ArrivalOrder::arrivesBeforeEntry(Kind::Kleinian, c, mu, 8.0,
                                                       Direction::Backward, 8.0));

        report.subsection("What it weighs");
        for (double thickness : {2.0, 4.0, 8.0})
        {
            const double w = ArrivalOrder::weight(Kind::Euclidean, c, mu, transverse, thickness);
            report.check(std::format("  Euclidean, d = {:g} : transmission {:.6g}", thickness, w),
                         w >= 0.0 && w <= 1.0);
        }
        report.check("the configurations that reach the crossover are the thick barriers, and a "
                     "thick barrier transmits almost nothing, so the sequence is admissible and "
                     "strongly suppressed at once",
                     ArrivalOrder::weight(Kind::Euclidean, c, mu, transverse, 8.0) <
                         ArrivalOrder::weight(Kind::Euclidean, c, mu, transverse, 2.0));
    }

}
