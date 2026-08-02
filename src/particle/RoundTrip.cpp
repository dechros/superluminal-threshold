#include "particle/RoundTrip.h"

#include "core/Report.h"
#include "intermediate/TwoCrossings.h"
#include "particle/WavePacket.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr int kSamples = 3001;

        struct Grid
        {
            double lower = 0.0;
            double step = 0.0;
        };

        Grid gridFor(double centre, double spread)
        {
            Grid grid;
            grid.lower = std::max(0.0, centre - 8.0 * spread);
            const double upper = centre + 8.0 * spread;
            grid.step = (upper - grid.lower) / (kSamples - 1);
            return grid;
        }

        double weightAt(int index, double centre, double spread)
        {
            const Grid grid = gridFor(centre, spread);
            const double k = grid.lower + index * grid.step;
            const double amplitude = WavePacket::weight(k, centre, spread);
            return amplitude * amplitude;
        }

        double returnedAt(int index, double centre, double spread, IntermediateRegion::Kind kind,
                          double c, double mu, double thickness)
        {
            const Grid grid = gridFor(centre, spread);
            const double k = grid.lower + index * grid.step;
            const double single = IntermediateRegion::transmission(kind, c, mu, k * k, thickness);
            return weightAt(index, centre, spread) * single * single;
        }

        double normalise(double centre, double spread, IntermediateRegion::Kind kind, double c,
                         double mu, double thickness, bool returned)
        {
            double sum = 0.0;
            for (int i = 0; i < kSamples; ++i)
            {
                sum += returned ? returnedAt(i, centre, spread, kind, c, mu, thickness)
                                : weightAt(i, centre, spread);
            }
            return sum;
        }
    }

    double RoundTrip::returnedWeight(double k, double centre, double spread,
                                     IntermediateRegion::Kind kind, double c, double mu,
                                     double thickness)
    {
        const double amplitude = WavePacket::weight(k, centre, spread);
        const double single = IntermediateRegion::transmission(kind, c, mu, k * k, thickness);
        return amplitude * amplitude * single * single;
    }

    double RoundTrip::oneWayFraction(double centre, double spread, IntermediateRegion::Kind kind,
                                     double c, double mu, double thickness)
    {
        const Grid grid = gridFor(centre, spread);
        double in = 0.0;
        double out = 0.0;
        for (int i = 0; i < kSamples; ++i)
        {
            const double k = grid.lower + i * grid.step;
            const double density = weightAt(i, centre, spread);
            in += density;
            out += density * IntermediateRegion::transmission(kind, c, mu, k * k, thickness);
        }
        return in > 0.0 ? out / in : 0.0;
    }

    double RoundTrip::survivingFraction(double centre, double spread,
                                        IntermediateRegion::Kind kind, double c, double mu,
                                        double thickness)
    {
        const double in = normalise(centre, spread, kind, c, mu, thickness, false);
        const double out = normalise(centre, spread, kind, c, mu, thickness, true);
        return in > 0.0 ? out / in : 0.0;
    }

    double RoundTrip::returnedMean(double centre, double spread, IntermediateRegion::Kind kind,
                                   double c, double mu, double thickness)
    {
        const Grid grid = gridFor(centre, spread);
        double sum = 0.0;
        double sumK = 0.0;
        for (int i = 0; i < kSamples; ++i)
        {
            const double density = returnedAt(i, centre, spread, kind, c, mu, thickness);
            sum += density;
            sumK += density * (grid.lower + i * grid.step);
        }
        return sum > 0.0 ? sumK / sum : 0.0;
    }

    double RoundTrip::centroidShiftInSpreads(double centre, double spread,
                                             IntermediateRegion::Kind kind, double c, double mu,
                                             double thickness)
    {
        const double before = WavePacket::incomingMean(centre, spread);
        const double after = returnedMean(centre, spread, kind, c, mu, thickness);
        const double width = WavePacket::incomingSpread(centre, spread);
        return width > 0.0 ? (after - before) / width : 0.0;
    }

    double RoundTrip::relativeEntropy(double centre, double spread, IntermediateRegion::Kind kind,
                                      double c, double mu, double thickness)
    {
        const double inNorm = normalise(centre, spread, kind, c, mu, thickness, false);
        const double outNorm = normalise(centre, spread, kind, c, mu, thickness, true);
        if (inNorm <= 0.0 || outNorm <= 0.0)
        {
            return 0.0;
        }
        double total = 0.0;
        for (int i = 0; i < kSamples; ++i)
        {
            const double p = returnedAt(i, centre, spread, kind, c, mu, thickness) / outNorm;
            const double q = weightAt(i, centre, spread) / inNorm;
            if (p > 1e-300 && q > 1e-300)
            {
                total += p * std::log(p / q);
            }
        }
        return total;
    }

    double RoundTrip::incomingEntropy(double centre, double spread)
    {
        const double norm = normalise(centre, spread, IntermediateRegion::Kind::None, 1.0, 1.0,
                                      0.0, false);
        double total = 0.0;
        for (int i = 0; i < kSamples; ++i)
        {
            const double p = weightAt(i, centre, spread) / norm;
            if (p > 1e-300)
            {
                total -= p * std::log(p);
            }
        }
        return total;
    }

    double RoundTrip::returnedEntropy(double centre, double spread, IntermediateRegion::Kind kind,
                                      double c, double mu, double thickness)
    {
        const double norm = normalise(centre, spread, kind, c, mu, thickness, true);
        if (norm <= 0.0)
        {
            return 0.0;
        }
        double total = 0.0;
        for (int i = 0; i < kSamples; ++i)
        {
            const double p = returnedAt(i, centre, spread, kind, c, mu, thickness) / norm;
            if (p > 1e-300)
            {
                total -= p * std::log(p);
            }
        }
        return total;
    }

    void RoundTripSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double thickness = 1.0;
        const double centre = 2.0;

        report.subsection("15.1  What the crossing cannot touch");
        for (double testOmega : {2.5, 6.0, 15.0})
        {
            const double gap =
                TwoCrossings::outsideSquared(testOmega, c, mu, 4.0) -
                TwoCrossings::insideSquared(Kind::Euclidean, testOmega, c, mu, 4.0);
            report.checkNear(std::format("  omega = {:g} : the step the region imposes is the "
                                         "same, so the frequency passes through untouched",
                                         testOmega),
                             gap - 8.0, 1e-12);
        }
        for (double testTransverse : {1.0, 4.0, 9.0})
        {
            const double gap =
                TwoCrossings::outsideSquared(20.0, c, mu, testTransverse) -
                TwoCrossings::insideSquared(Kind::Euclidean, 20.0, c, mu, testTransverse);
            report.checkNear(std::format("  kT^2 = {:g} : the step is set by the transverse "
                                         "wavenumber alone, which the surface conserves",
                                         testTransverse),
                             gap - 2.0 * testTransverse, 1e-12);
        }
        report.checkNear("and the mass enters both sides by the same amount, so the "
                         "crossing acts on the operator and not on mu",
                         (TwoCrossings::outsideSquared(20.0, c, 1.0, 4.0) -
                          TwoCrossings::outsideSquared(20.0, c, 3.0, 4.0)) -
                             (TwoCrossings::insideSquared(Kind::Euclidean, 20.0, c, 1.0, 4.0) -
                              TwoCrossings::insideSquared(Kind::Euclidean, 20.0, c, 3.0, 4.0)),
                         1e-12);

        report.subsection("15.2  The ledger of what came back");
        for (Kind kind : {Kind::Kleinian, Kind::Euclidean})
        {
            const double fraction =
                RoundTrip::survivingFraction(centre, 0.3, kind, c, mu, thickness);
            report.check(std::format("  {:22} : {:.4f} of the packet survives both crossings",
                                     IntermediateRegion::name(kind), fraction),
                         fraction > 0.0 && fraction < 1.0);
        }
        for (Kind kind : {Kind::Kleinian, Kind::Euclidean})
        {
            report.check(std::format("  {:22} : the return leg costs again, {:.4f} against {:.4f}",
                                     IntermediateRegion::name(kind),
                                     RoundTrip::survivingFraction(centre, 0.3, kind, c, mu,
                                                                  thickness),
                                     RoundTrip::oneWayFraction(centre, 0.3, kind, c, mu,
                                                               thickness)),
                         RoundTrip::survivingFraction(centre, 0.3, kind, c, mu, thickness) <
                             RoundTrip::oneWayFraction(centre, 0.3, kind, c, mu, thickness));
        }
        report.check("nothing at all comes back through a degenerate layer",
                     RoundTrip::survivingFraction(centre, 0.3, Kind::Degenerate, c, mu,
                                                  thickness) == 0.0);

        report.subsection("15.3  The body returns displaced, and twice as much");
        const double singleShift = std::abs(
            WavePacket::centroidShiftInSpreads(centre, 0.5, thickness, c, mu, 2.0));
        const double roundShift =
            std::abs(RoundTrip::centroidShiftInSpreads(centre, 0.5, Kind::Euclidean, c, mu,
                                                       thickness));
        report.check(std::format("  one crossing shifts by {:.4f}, the round trip by {:.4f}",
                                 singleShift, roundShift),
                     roundShift > singleShift);

        report.subsection("15.4  The displacement still vanishes for a narrow packet");
        double previous = 1e9;
        for (double width : {0.4, 0.2, 0.1, 0.05})
        {
            const double shift = std::abs(RoundTrip::centroidShiftInSpreads(
                centre, width, Kind::Euclidean, c, mu, thickness));
            report.check(std::format("  width {:g} : round-trip shift {:.4f}", width, shift),
                         shift < previous);
            previous = shift;
        }
        const double shiftAtTenth = std::abs(
            RoundTrip::centroidShiftInSpreads(centre, 0.1, Kind::Euclidean, c, mu, thickness));
        const double shiftAtTwentieth = std::abs(
            RoundTrip::centroidShiftInSpreads(centre, 0.05, Kind::Euclidean, c, mu, thickness));
        report.checkNear("the shift halves with the width, so it has no floor",
                         shiftAtTenth / shiftAtTwentieth - 2.0, 0.05);
        report.check("so a narrow enough particle comes back as itself, which is "
                     "what makes the journey a journey and not a replacement",
                     std::abs(RoundTrip::centroidShiftInSpreads(centre, 0.01, Kind::Euclidean, c,
                                                                mu, thickness)) < 0.05);

        report.subsection("15.5  The information ledger");
        for (double width : {0.1, 0.5, 1.0})
        {
            const double divergence =
                RoundTrip::relativeEntropy(centre, width, Kind::Euclidean, c, mu, thickness);
            report.check(std::format("  width {:g} : relative entropy {:.5f} nats", width,
                                     divergence),
                         divergence >= 0.0);
        }
        report.check("a wider packet is changed more by the journey than a narrow one",
                     RoundTrip::relativeEntropy(centre, 1.0, Kind::Euclidean, c, mu, thickness) >
                         RoundTrip::relativeEntropy(centre, 0.1, Kind::Euclidean, c, mu,
                                                    thickness));
        report.checkNear("and a journey through no region at all costs nothing",
                         RoundTrip::relativeEntropy(centre, 0.5, Kind::None, c, mu, thickness),
                         1e-12);

        report.subsection("15.6  The journey sharpens rather than blurs");
        const double before = RoundTrip::incomingEntropy(centre, 0.8);
        const double after =
            RoundTrip::returnedEntropy(centre, 0.8, Kind::Euclidean, c, mu, thickness);
        report.check(std::format("  entropy {:.4f} before, {:.4f} after", before, after),
                     after < before);
        report.check("the filter removes modes rather than adding any, so what "
                     "returns is a narrower description than what set out",
                     RoundTrip::returnedEntropy(centre, 0.8, Kind::Euclidean, c, mu, thickness) <
                         RoundTrip::incomingEntropy(centre, 0.8));
    }

}
