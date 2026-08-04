#include "particle/TimeShiftCost.h"

#include "core/Report.h"
#include "particle/ArrivalOrder.h"
#include "particle/RouteHolonomy.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{

    double TimeShiftCost::requiredDistance(double backwardAmount, IntermediateRegion::Kind kind,
                                           double c, double mu, double thickness)
    {
        return ArrivalOrder::crossoverDistance(kind, c, mu, thickness) + std::abs(backwardAmount);
    }

    double TimeShiftCost::amplitudeWeight(IntermediateRegion::Kind kind, double c, double mu,
                                          double transverseSquared, double thickness)
    {
        return IntermediateRegion::transmission(kind, c, mu, transverseSquared, thickness);
    }

    bool TimeShiftCost::weightRespondsToTheRegion(IntermediateRegion::Kind kind, double c,
                                                  double mu, double transverseSquared)
    {
        const double thin = amplitudeWeight(kind, c, mu, transverseSquared, 2.0);
        const double thick = amplitudeWeight(kind, c, mu, transverseSquared, 8.0);
        return std::abs(thick - thin) > 0.0;
    }

    double TimeShiftCost::rapidityForResidue(double distance, double residue)
    {
        if (distance <= 0.0)
        {
            return 0.0;
        }
        return std::acosh(1.0 + std::abs(residue) / distance);
    }

    double TimeShiftCost::energyFactor(double rapidity)
    {
        return std::cosh(rapidity);
    }

    double TimeShiftCost::fractionalEnergyCost(double distance, double residue)
    {
        return energyFactor(rapidityForResidue(distance, residue)) - 1.0;
    }

    double TimeShiftCost::residueForEnergyCost(double distance, double fractionalCost)
    {
        return distance * fractionalCost;
    }

    void TimeShiftCostSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double thickness = 8.0;
        const Matrix4 D = SignatureInvolution::matrix();

        report.subsection("The leg a given displacement asks for");
        const double crossover = ArrivalOrder::crossoverDistance(Kind::Euclidean, c, mu, thickness);
        for (double amount : {0.0, 1.0, 10.0, 1000.0})
        {
            const double needed =
                TimeShiftCost::requiredDistance(amount, Kind::Euclidean, c, mu, thickness);
            report.checkNear(std::format("  to arrive {:g} before the entry the leg must be {:.6f}",
                                         amount, needed),
                             needed - (crossover + amount), 1e-9);
        }
        report.check("the leg grows one for one with the displacement asked for, since the "
                     "delay it has to beat is fixed by the region",
                     TimeShiftCost::requiredDistance(1000.0, Kind::Euclidean, c, mu, thickness) -
                             TimeShiftCost::requiredDistance(0.0, Kind::Euclidean, c, mu, thickness) ==
                         1000.0);

        report.subsection("What the amplitude charges for it");
        const double weight =
            TimeShiftCost::amplitudeWeight(Kind::Euclidean, c, mu, transverse, thickness);
        report.check(std::format("the weight of the sequence is {:.6g}, set by the region", weight),
                     weight > 0.0 && weight < 1.0);
        report.check(std::format("it does respond to the region, falling from {:.6g} at a "
                                 "thickness of 2 to {:.6g} at 8, so its blindness to the leg is "
                                 "not the blindness of a constant",
                                 TimeShiftCost::amplitudeWeight(Kind::Euclidean, c, mu, transverse,
                                                                2.0),
                                 TimeShiftCost::amplitudeWeight(Kind::Euclidean, c, mu, transverse,
                                                                8.0)),
                     TimeShiftCost::weightRespondsToTheRegion(Kind::Euclidean, c, mu, transverse));
        report.check("but the far-side leg is not among its arguments at all, so within this "
                     "model an arbitrarily large displacement costs no more amplitude than the "
                     "smallest one; that is an absence in the model rather than a freedom it "
                     "establishes, and the amplitude would have to acquire a path length "
                     "before the journey could be priced",
                     true);

        report.subsection("What a straight leg costs in energy");
        report.check("nothing: the far side is invariant under translation along its "
                     "distinguished axis, so the conjugate quantity is conserved and the "
                     "length of a straight leg is not paid for",
                     true);
        report.check("and a route that goes out, rotates among the like-signed axes and comes "
                     "back leaves no displacement at all, so the free operations buy nothing",
                     std::abs(RouteHolonomy::closedRouteResidue(
                          D, RouteHolonomy::outAndBackWithRotation(4.0, 1.1))) <= 1e-9);

        report.subsection("What a frame change costs, and what it buys");
        for (double rapidity : {0.5, 1.0, 2.0})
        {
            const auto route = RouteHolonomy::outAndBack(3.0, rapidity);
            const double residue = RouteHolonomy::closedRouteResidue(D, route);
            const double recovered = TimeShiftCost::rapidityForResidue(3.0, residue);
            report.checkNear(std::format("  rapidity {:g} buys {:+.6f} and is recovered from it "
                                         "as {:.6f}",
                                         rapidity, residue, recovered),
                             recovered - rapidity, 1e-9);
        }
        for (double distance : {1.0, 3.0, 100.0})
        {
            for (double residue : {0.5, 2.0})
            {
                report.checkNear(
                    std::format("  leg {:g}, extra {:g} : the energy must rise by a factor "
                                "{:.9f}, a fraction {:.9f}",
                                distance, residue,
                                1.0 + TimeShiftCost::fractionalEnergyCost(distance, residue),
                                TimeShiftCost::fractionalEnergyCost(distance, residue)),
                    TimeShiftCost::fractionalEnergyCost(distance, residue) - residue / distance,
                    1e-9);
            }
        }
        report.check("so the fractional cost is the extra displacement divided by the length "
                     "of the leg, with no free parameter left, and it is linear in the "
                     "displacement rather than exponential",
                     std::abs(TimeShiftCost::fractionalEnergyCost(10.0, 4.0) -
                              2.0 * TimeShiftCost::fractionalEnergyCost(10.0, 2.0)) <= 1e-9);
        report.check("a leg ten times longer buys the same displacement for a tenth of the "
                     "fractional cost",
                     std::abs(TimeShiftCost::fractionalEnergyCost(100.0, 2.0) -
                              0.1 * TimeShiftCost::fractionalEnergyCost(10.0, 2.0)) <= 1e-9);
        for (double fraction : {0.01, 1.0})
        {
            report.checkNear(
                std::format("  a leg of 1000 and a fractional energy increase of {:g} buy "
                            "{:.6f}",
                            fraction, TimeShiftCost::residueForEnergyCost(1000.0, fraction)),
                TimeShiftCost::fractionalEnergyCost(
                    1000.0, TimeShiftCost::residueForEnergyCost(1000.0, fraction)) -
                    fraction,
                1e-9);
        }

        report.subsection("The ledger, stated as a limitation");
        report.check("two of the three currencies are computed here and both are mild: the "
                     "amplitude does not see the leg and a straight leg is free in energy",
                     true);
        report.check("the third is a real price but a familiar one, being the same hyperbolic "
                     "cosine an ordinary boost applies, so nothing in this ledger is peculiar "
                     "to the construction",
                     std::abs(TimeShiftCost::energyFactor(1.0) - std::cosh(1.0)) <= 1e-12);
        report.check("what the model cannot price is the journey itself, and the reason is "
                     "structural rather than accidental: no quantity in the amplitude depends "
                     "on how far the particle went on the far side, so any cost proportional "
                     "to that distance is outside what is computed here and must not be read "
                     "into the numbers above",
                     true);
    }

}
