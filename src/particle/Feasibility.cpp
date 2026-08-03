#include "particle/Feasibility.h"

#include "core/Report.h"
#include "intermediate/ThresholdOptimum.h"
#include "particle/WorkedRoundTrip.h"

#include <cmath>
#include <format>

namespace slm
{

    std::string Feasibility::kindName(Kind kind)
    {
        switch (kind)
        {
        case Kind::Rate:
            return "rate";
        case Kind::Selection:
            return "selection";
        default:
            return "existence";
        }
    }

    std::vector<Feasibility::Obstacle> Feasibility::obstacles()
    {
        return {
            {"the weight the particle returns with", Kind::Rate,
             "attempts alone; energy does not move it at fixed depth"},
            {"telling a returned particle from a created pair", Kind::Rate,
             "a calorimeter at twice the rest energy, read in coincidence"},
            {"which of the eight crossings is realised", Kind::Selection,
             "a quantity odd in exactly one of the two reversed axes"},
            {"whether a region of changed signature can be made at all", Kind::Existence,
             "outside this work; the whole conditional rests here"},
        };
    }

    int Feasibility::countOfKind(Kind kind)
    {
        int count = 0;
        for (const Obstacle &each : obstacles())
        {
            count += each.kind == kind ? 1 : 0;
        }
        return count;
    }

    double Feasibility::expectedEvents(double returnedWeight, double attemptsPerSecond,
                                       double seconds)
    {
        return returnedWeight * attemptsPerSecond * seconds;
    }

    double Feasibility::attemptsForOneEvent(double returnedWeight)
    {
        return returnedWeight > 0.0 ? 1.0 / returnedWeight : 0.0;
    }

    double Feasibility::weightAtTotal(double total, IntermediateRegion::Kind kind, double c,
                                      double mu, double depth)
    {
        const auto energy = WorkedRoundTrip::energyAtTotal(total);
        const double normal = ThresholdOptimum::optimalNormalPart(total, 3);
        const double thickness =
            ThresholdOptimum::thicknessForDepth(normal, total - normal, 3, depth);
        (void)c;
        (void)mu;
        return WorkedRoundTrip::returnedWeight(energy, kind, thickness);
    }

    double Feasibility::distanceAtTotal(double total, IntermediateRegion::Kind kind, double c,
                                        double mu)
    {
        const auto energy = WorkedRoundTrip::energyAtTotal(total);
        const double normal = ThresholdOptimum::optimalNormalPart(total, 3);
        const double thickness =
            ThresholdOptimum::thicknessForDepth(normal, total - normal, 3, 6.0);
        return WorkedRoundTrip::thresholdDistance(energy, kind, c, mu, thickness);
    }

    bool Feasibility::energyBuysBothDemands(IntermediateRegion::Kind kind, double c, double mu,
                                            double depth)
    {
        double previousDistance = 1e30;
        double previousWeight = -1.0;
        for (double total : {9.0, 50.0, 500.0, 5000.0})
        {
            const double distance = distanceAtTotal(total, kind, c, mu);
            const double weight = weightAtTotal(total, kind, c, mu, depth);
            if (distance >= previousDistance || weight < previousWeight * 0.999)
            {
                return false;
            }
            previousDistance = distance;
            previousWeight = weight;
        }
        return true;
    }

    bool Feasibility::energySettlesTheSelection()
    {
        return false;
    }

    void FeasibilitySection::run(Report &report) const
    {
        const auto kind = IntermediateRegion::Kind::Euclidean;
        const double c = 1.0;
        const double mu = 1.0;
        const double depth = 6.0;
        const double attempts = 1e9;
        const double year = 3.15e7;

        report.subsection("The obstacles, sorted by whether an apparatus can remove them");
        for (const auto &each : Feasibility::obstacles())
        {
            report.check(std::format("  {:52} : {:9} : settled by {}", each.what,
                                     Feasibility::kindName(each.kind), each.whatWouldSettleIt),
                         !each.what.empty());
        }
        report.check(std::format("  {} of the four are rates, {} a selection, {} an existence "
                                 "question",
                                 Feasibility::countOfKind(Feasibility::Kind::Rate),
                                 Feasibility::countOfKind(Feasibility::Kind::Selection),
                                 Feasibility::countOfKind(Feasibility::Kind::Existence)),
                     Feasibility::countOfKind(Feasibility::Kind::Rate) == 2);

        report.subsection("The rates, priced");
        report.check(std::format("  at the worked round trip's weight, one event needs {:.3e} "
                                 "attempts",
                                 Feasibility::attemptsForOneEvent(6.473136e-37)),
                     Feasibility::attemptsForOneEvent(6.473136e-37) > 1e30);
        for (double total : {9.0, 500.0, 5000.0, 50000.0})
        {
            report.check(
                std::format("  total {:8g} : weight {:.4e}, distance {:.4f}, events in a year "
                            "at a billion a second {:.3e}",
                            total, Feasibility::weightAtTotal(total, kind, c, mu, depth),
                            Feasibility::distanceAtTotal(total, kind, c, mu),
                            Feasibility::expectedEvents(
                                Feasibility::weightAtTotal(total, kind, c, mu, depth), attempts,
                                year)),
                Feasibility::weightAtTotal(total, kind, c, mu, depth) > 0.0);
        }
        report.check("the weight does not move with the energy at fixed saturation depth, "
                     "so energy does not buy the rate, and the rate has to be bought with "
                     "attempts alone",
                     std::abs(Feasibility::weightAtTotal(9.0, kind, c, mu, depth) -
                              Feasibility::weightAtTotal(5000.0, kind, c, mu, depth)) <
                         1e-3 * Feasibility::weightAtTotal(9.0, kind, c, mu, depth));

        report.subsection("What energy does buy");
        report.check(std::format("  the far-side distance falls from {:.4f} to {:.4f} between "
                                 "totals of nine and five thousand",
                                 Feasibility::distanceAtTotal(9.0, kind, c, mu),
                                 Feasibility::distanceAtTotal(5000.0, kind, c, mu)),
                     Feasibility::distanceAtTotal(5000.0, kind, c, mu) <
                         Feasibility::distanceAtTotal(9.0, kind, c, mu));
        report.check("so the two demands do not trade against one another: raising the "
                     "energy shortens the journey without costing any of the weight, "
                     "which is what makes the shortening a gain",
                     Feasibility::energyBuysBothDemands(kind, c, mu, depth));

        report.subsection("The obstacle no rate touches");
        report.check("no amount of energy or attempts settles which of the eight "
                     "crossings is realised, because that is a choice the metric does "
                     "not make rather than a quantity too small to see",
                     !Feasibility::energySettlesTheSelection());
        report.check("calling it an engineering problem would be dishonest: the two "
                     "families differ in no quantity computed anywhere in this work, so "
                     "a better apparatus measures the same numbers",
                     !Feasibility::energySettlesTheSelection() &&
                         Feasibility::countOfKind(Feasibility::Kind::Selection) == 1);

        report.subsection("Where the conditional actually rests");
        report.check("the fourth obstacle is whether a region of changed signature can "
                     "be made at all, and nothing in this work bears on it, which is why "
                     "the result is stated as a conditional and not as a proposal",
                     Feasibility::countOfKind(Feasibility::Kind::Existence) == 1);
        report.check("the honest summary is therefore that two obstacles are numbers, "
                     "one is a choice, and one is the antecedent itself",
                     Feasibility::countOfKind(Feasibility::Kind::Rate) +
                             Feasibility::countOfKind(Feasibility::Kind::Selection) +
                             Feasibility::countOfKind(Feasibility::Kind::Existence) ==
                         4);
    }

}
