#include "particle/WorkedRoundTrip.h"

#include "boundary/SlabTunnelling.h"
#include "core/Report.h"
#include "intermediate/ThresholdOptimum.h"
#include "particle/ReturnEvent.h"
#include "particle/ReturnFormula.h"

#include <cmath>
#include <format>

namespace slm
{

    WorkedRoundTrip::Three WorkedRoundTrip::energyAtTotal(double total)
    {
        const double normal = ThresholdOptimum::optimalNormalPart(total, 3);
        const double transverse = total - normal;
        return {std::sqrt(normal), std::sqrt(transverse / 2.0), std::sqrt(transverse / 2.0)};
    }

    double WorkedRoundTrip::frequency(const Three &energy, double c, double mu)
    {
        return ReturnFormula::frequency(energy, c, mu);
    }

    double WorkedRoundTrip::roundTripDelay(const Three &energy, IntermediateRegion::Kind kind,
                                           double c, double mu, double thickness)
    {
        return 2.0 * ReturnFormula::elapsedAtThickness(energy, kind, c, mu, thickness);
    }

    double WorkedRoundTrip::thresholdDistance(const Three &energy, IntermediateRegion::Kind kind,
                                              double c, double mu, double thickness)
    {
        return roundTripDelay(energy, kind, c, mu, thickness);
    }

    double WorkedRoundTrip::returnMoment(const Three &energy, IntermediateRegion::Kind kind,
                                         double c, double mu, double thickness,
                                         double farSideDistance, int branch)
    {
        const double sign = branch > 0 ? 1.0 : -1.0;
        return roundTripDelay(energy, kind, c, mu, thickness) + sign * farSideDistance;
    }

    bool WorkedRoundTrip::returnsBeforeDeparture(const Three &energy, IntermediateRegion::Kind kind,
                                                 double c, double mu, double thickness,
                                                 double farSideDistance, int branch)
    {
        return returnMoment(energy, kind, c, mu, thickness, farSideDistance, branch) < 0.0;
    }

    double WorkedRoundTrip::returnedWeight(const Three &energy, IntermediateRegion::Kind kind,
                                           double thickness)
    {
        const double kappa = ReturnFormula::outsideWavenumber(energy);
        const double beta = ReturnFormula::interiorDecay(energy, kind);
        if (beta <= 0.0 || kappa <= 0.0)
        {
            return 0.0;
        }
        const double single = SlabTunnelling::transmissionFromSquares(
            kappa * kappa, -beta * beta, thickness);
        return single * single;
    }

    bool WorkedRoundTrip::agreesWithClosedFormula(const Three &energy,
                                                  IntermediateRegion::Kind kind, double c,
                                                  double mu, double thickness)
    {
        return ReturnFormula::agreesWithScattering(energy, kind, c, mu, thickness, 1e-6);
    }

    bool WorkedRoundTrip::agreesWithThresholdOptimum(double total, IntermediateRegion::Kind kind,
                                                     double c, double mu, double thickness,
                                                     double tolerance)
    {
        const Three energy = energyAtTotal(total);
        const double here = thresholdDistance(energy, kind, c, mu, thickness);
        const double there = ThresholdOptimum::smallestThresholdAtTotal(total, mu, c, 3);
        return std::abs(here - there) <= tolerance * std::abs(there);
    }

    bool WorkedRoundTrip::higherEnergyBuysDistance(IntermediateRegion::Kind kind, double c,
                                                   double mu, double depth, double tolerance)
    {
        double previousDistance = 1e30;
        double firstWeight = -1.0;
        for (double total : {9.0, 50.0, 500.0, 5000.0})
        {
            const Three energy = energyAtTotal(total);
            const double beta = ReturnFormula::interiorDecay(energy, kind);
            if (beta <= 0.0)
            {
                return false;
            }
            const double thickness = depth / beta;
            const double distance = thresholdDistance(energy, kind, c, mu, thickness);
            const double weight = returnedWeight(energy, kind, thickness);
            if (distance <= 0.0 || distance >= previousDistance)
            {
                return false;
            }
            previousDistance = distance;
            if (firstWeight < 0.0)
            {
                firstWeight = weight;
            }
            else if (std::abs(weight - firstWeight) > tolerance * firstWeight)
            {
                return false;
            }
        }
        return firstWeight > 0.0;
    }

    WorkedRoundTrip::Journey WorkedRoundTrip::journey(double total,
                                                      IntermediateRegion::Kind kind, double c,
                                                      double mu, double thickness,
                                                      double farSideDistance, int branch)
    {
        const Three energy = energyAtTotal(total);
        const double normal = ThresholdOptimum::optimalNormalPart(total, 3);
        const double beta = ReturnFormula::interiorDecay(energy, kind);
        const ReturnEvent::State state{energy, branch};
        const ReturnEvent::Event event = ReturnEvent::map(state, kind, c, mu, thickness);
        const double sign = branch > 0 ? 1.0 : -1.0;
        const double light = ReturnEvent::lightRoundTrip(thickness, c);
        const double elapsed = event.elapsed + sign * farSideDistance;

        Journey record{};
        record.total = total;
        record.normalPart = normal;
        record.transversePart = total - normal;
        record.frequency = frequency(energy, c, mu);
        record.outsideWavenumber = ReturnFormula::outsideWavenumber(energy);
        record.interiorDecay = beta;
        record.depth = beta * thickness;
        record.singleDelay = 0.5 * event.elapsed;
        record.roundTripDelay = event.elapsed;
        record.thresholdDistance = event.elapsed;
        record.farSideDistance = farSideDistance;
        record.returnElapsed = elapsed;
        record.returnCrossing = event.crossing;
        record.returnTransverseFirst = event.transverseFirst;
        record.returnTransverseSecond = event.transverseSecond;
        record.returnedWeight = returnedWeight(energy, kind, thickness);
        record.lightRoundTrip = light;
        record.advanceOverLight = light - elapsed;
        record.branch = branch;
        return record;
    }

    bool WorkedRoundTrip::journeyAgreesWithReturnEvent(const Journey &record,
                                                       IntermediateRegion::Kind kind, double c,
                                                       double mu, double thickness)
    {
        const Three energy = energyAtTotal(record.total);
        const ReturnEvent::State state{energy, record.branch};
        const ReturnEvent::Event event = ReturnEvent::map(state, kind, c, mu, thickness);
        const double sign = record.branch > 0 ? 1.0 : -1.0;
        return std::abs(record.returnElapsed -
                        (event.elapsed + sign * record.farSideDistance)) < 1e-9 &&
               std::abs(record.returnCrossing - event.crossing) < 1e-9 &&
               std::abs(record.roundTripDelay - event.elapsed) < 1e-9;
    }

    bool WorkedRoundTrip::beatsLight(const Journey &record)
    {
        return record.returnElapsed < record.lightRoundTrip;
    }

    void WorkedRoundTripSection::run(Report &report) const
    {
        const auto kind = IntermediateRegion::Kind::Euclidean;
        const double c = 1.0;
        const double mu = 1.0;
        const double thickness = 8.0;
        const double total = 9.0;
        const auto energy = WorkedRoundTrip::energyAtTotal(total);

        report.subsection("The particle, and the region it is sent into");
        report.check(std::format("  energy vector ({:.4f}, {:.4f}, {:.4f}), total {:g}", energy[0],
                                 energy[1], energy[2], total),
                     ReturnFormula::isBarrier(energy, kind));
        report.check(std::format("  frequency {:.6f}, outside wavenumber {:.6f}, interior decay "
                                 "{:.6f}",
                                 WorkedRoundTrip::frequency(energy, c, mu),
                                 ReturnFormula::outsideWavenumber(energy),
                                 ReturnFormula::interiorDecay(energy, kind)),
                     ReturnFormula::interiorDecay(energy, kind) > 0.0);
        report.check(std::format("  region thickness {:g}, so the particle meets it as a barrier "
                                 "and the delay has saturated",
                                 thickness),
                     ReturnFormula::isBarrier(energy, kind));

        report.subsection("Crossing, twice");
        report.check(std::format("  the round trip spends {:.6f} inside, which is twice a single "
                                 "traversal",
                                 WorkedRoundTrip::roundTripDelay(energy, kind, c, mu, thickness)),
                     WorkedRoundTrip::roundTripDelay(energy, kind, c, mu, thickness) > 0.0);
        report.check(std::format("  so the far-side distance that brings it home exactly when it "
                                 "left is {:.6f}",
                                 WorkedRoundTrip::thresholdDistance(energy, kind, c, mu,
                                                                     thickness)),
                     std::abs(WorkedRoundTrip::thresholdDistance(energy, kind, c, mu, thickness) -
                              ThresholdOptimum::smallestThresholdAtTotal(total, mu, c, 3)) < 1e-4);
        report.check("that distance is the one the threshold optimum reaches by its own "
                     "route, so the example is the chain and not a retelling of it",
                     WorkedRoundTrip::agreesWithThresholdOptimum(total, kind, c, mu, thickness,
                                                                  1e-3));
        report.check("and the elapsed time is the one the closed formula gives, checked "
                     "against the scattering calculation it replaces",
                     WorkedRoundTrip::agreesWithClosedFormula(energy, kind, c, mu, thickness));

        report.subsection("Three journeys, differing only in how far it goes over there");
        struct Leg
        {
            const char *label;
            double distance;
        };
        const double threshold =
            WorkedRoundTrip::thresholdDistance(energy, kind, c, mu, thickness);
        const Leg legs[] = {{"short of the threshold", 1.0},
                            {"exactly at it       ", threshold},
                            {"past it             ", 6.0}};
        for (const Leg &leg : legs)
        {
            const double moment =
                WorkedRoundTrip::returnMoment(energy, kind, c, mu, thickness, leg.distance, -1);
            report.check(std::format("  {} : goes {:.6f}, returns at {:+.6f}", leg.label,
                                     leg.distance, moment),
                         std::isfinite(moment));
        }
        report.check("the first returns after it left",
                     !WorkedRoundTrip::returnsBeforeDeparture(energy, kind, c, mu, thickness, 1.0,
                                                               -1));
        report.check("the third returns before it left, which is the whole claim carried "
                     "by one particle rather than by an argument",
                     WorkedRoundTrip::returnsBeforeDeparture(energy, kind, c, mu, thickness, 6.0,
                                                              -1));
        report.check("and on the other family the same journey lands later instead, so "
                     "the sign is a choice of crossing and not a property of the trip",
                     !WorkedRoundTrip::returnsBeforeDeparture(energy, kind, c, mu, thickness, 6.0,
                                                               1));

        report.subsection("What the journey weighs");
        report.check(std::format("  the particle comes back with a weight of {:.6e}",
                                 WorkedRoundTrip::returnedWeight(energy, kind, thickness)),
                     WorkedRoundTrip::returnedWeight(energy, kind, thickness) > 0.0);
        report.check("that weight is the price, and it is stated in the same breath as "
                     "the timing rather than in a separate section",
                     WorkedRoundTrip::returnedWeight(energy, kind, thickness) < 1e-6);

        report.subsection("The whole journey as one record, step by step");
        {
            const auto record = WorkedRoundTrip::journey(total, kind, c, mu, thickness, 6.0, -1);
            report.check(std::format("   1. energy split      : normal {:.6f}, transverse {:.6f}, "
                                     "total {:g}",
                                     record.normalPart, record.transversePart, record.total),
                         std::abs(record.normalPart + record.transversePart - record.total) < 1e-9);
            report.check(std::format("   2. mass shell        : frequency {:.6f}",
                                     record.frequency),
                         record.frequency > 0.0);
            report.check(std::format("   3. meeting the face  : outside wavenumber {:.6f}, "
                                     "interior decay {:.6f}",
                                     record.outsideWavenumber, record.interiorDecay),
                         record.interiorDecay > 0.0);
            report.check(std::format("   4. opacity           : decay times thickness is {:.4f}, "
                                     "so the delay has saturated",
                                     record.depth),
                         record.depth > 6.0);
            report.check(std::format("   5. one crossing      : phase delay {:.6f}",
                                     record.singleDelay),
                         record.singleDelay > 0.0);
            report.check(std::format("   6. two crossings     : round trip delay {:.6f}",
                                     record.roundTripDelay),
                         std::abs(record.roundTripDelay - 2.0 * record.singleDelay) < 1e-9);
            report.check(std::format("   7. the price         : far-side distance needed is "
                                     "{:.6f}",
                                     record.thresholdDistance),
                         std::abs(record.thresholdDistance - record.roundTripDelay) < 1e-9);
            report.check(std::format("   8. the journey       : {:.6f} covered on the far side, "
                                     "on branch {:+d}",
                                     record.farSideDistance, record.branch),
                         record.farSideDistance > record.thresholdDistance);
            report.check(std::format("   9. return event      : elapsed {:+.6f}, crossing {:.6f}, "
                                     "transverse ({:+.6f}, {:+.6f})",
                                     record.returnElapsed, record.returnCrossing,
                                     record.returnTransverseFirst,
                                     record.returnTransverseSecond),
                         record.returnElapsed < 0.0);
            report.check(std::format("  10. weight            : {:.6e}", record.returnedWeight),
                         record.returnedWeight > 0.0);
            report.check(std::format("  11. against light     : a light round trip takes {:.6f}, "
                                     "so the particle is {:.6f} ahead",
                                     record.lightRoundTrip, record.advanceOverLight),
                         WorkedRoundTrip::beatsLight(record));
            report.check("every coordinate of the return event above comes from the closed "
                         "formula rather than from this record, so the walk through cannot "
                         "drift from the chain it is illustrating",
                         WorkedRoundTrip::journeyAgreesWithReturnEvent(record, kind, c, mu,
                                                                        thickness));
            report.check("both sides of the comparison with light are round trips, which is "
                         "the mistake this work has made twice and now checks rather than "
                         "assumes",
                         std::abs(record.lightRoundTrip - 2.0 * thickness / c) < 1e-9);
        }

        report.subsection("The price is chosen, not fixed");
        for (double each : {9.0, 50.0, 500.0, 5000.0})
        {
            const auto raised = WorkedRoundTrip::energyAtTotal(each);
            const double beta = ReturnFormula::interiorDecay(raised, kind);
            const double thin = 6.0 / beta;
            report.check(std::format("  total {:8g} : distance needed {:.6f}, thickness {:.6f}, "
                                     "weight {:.6e}",
                                     each,
                                     WorkedRoundTrip::thresholdDistance(raised, kind, c, mu, thin),
                                     thin, WorkedRoundTrip::returnedWeight(raised, kind, thin)),
                         WorkedRoundTrip::thresholdDistance(raised, kind, c, mu, thin) > 0.0);
        }
        report.check("raising the energy shortens the journey the particle has to make "
                     "over there without costing it any of the weight it comes back "
                     "with, so the figure above is a working point and not a bound",
                     WorkedRoundTrip::higherEnergyBuysDistance(kind, c, mu, 6.0, 1e-3));
    }

}
