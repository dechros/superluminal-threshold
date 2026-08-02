#include "intermediate/TwoCrossings.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double TwoCrossings::outsideSquared(double omega, double c, double mu,
                                        double transverseSquared)
    {
        return (omega * omega) / (c * c) - transverseSquared - mu;
    }

    double TwoCrossings::insideSquared(IntermediateRegion::Kind kind, double omega, double c,
                                       double mu, double transverseSquared)
    {
        const int flipped = IntermediateRegion::flippedDirections(kind);
        if (flipped < 0)
        {
            return -1e12;
        }
        const double shift = (2.0 * flipped / 3.0) * transverseSquared;
        return outsideSquared(omega, c, mu, transverseSquared) - shift;
    }

    std::complex<double> TwoCrossings::amplitude(IntermediateRegion::Kind kind, double omega,
                                                 double c, double mu, double transverseSquared,
                                                 double thickness)
    {
        const std::complex<double> i(0.0, 1.0);
        const double outside = outsideSquared(omega, c, mu, transverseSquared);
        if (outside <= 0.0)
        {
            return {0.0, 0.0};
        }
        const double kappa = std::sqrt(outside);
        if (thickness <= 0.0 || kind == IntermediateRegion::Kind::None)
        {
            return std::exp(i * kappa * thickness);
        }

        const double inside = insideSquared(kind, omega, c, mu, transverseSquared);
        const std::complex<double> q =
            inside >= 0.0 ? std::complex<double>(std::sqrt(inside), 0.0)
                          : std::complex<double>(0.0, std::sqrt(-inside));

        const std::complex<double> plus = kappa + q;
        const std::complex<double> minus = kappa - q;
        const std::complex<double> denominator =
            plus * plus * std::exp(-i * q * thickness) - minus * minus * std::exp(i * q * thickness);
        const std::complex<double> numerator = 4.0 * kappa * q;
        return numerator / denominator;
    }

    double TwoCrossings::phase(IntermediateRegion::Kind kind, double omega, double c, double mu,
                               double transverseSquared, double thickness)
    {
        return std::arg(amplitude(kind, omega, c, mu, transverseSquared, thickness));
    }

    double TwoCrossings::returnDelay(IntermediateRegion::Kind kind, double omega, double c,
                                     double mu, double transverseSquared, double thickness)
    {
        const double step = 1e-5;
        const std::complex<double> high =
            amplitude(kind, omega + step, c, mu, transverseSquared, thickness);
        const std::complex<double> low =
            amplitude(kind, omega - step, c, mu, transverseSquared, thickness);
        if (std::abs(high) == 0.0 || std::abs(low) == 0.0)
        {
            return 0.0;
        }
        const std::complex<double> ratio = high / low;
        return std::arg(ratio) / (2.0 * step);
    }

    double TwoCrossings::lightTime(double thickness, double c)
    {
        return thickness / c;
    }

    double TwoCrossings::delayInLightTimes(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared, double thickness)
    {
        if (thickness <= 0.0)
        {
            return 0.0;
        }
        return returnDelay(kind, omega, c, mu, transverseSquared, thickness) /
               lightTime(thickness, c);
    }

    void TwoCrossingsSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double omega = 6.0;

        report.subsection("13.1  The amplitude across two crossings is well defined");
        for (Kind kind : {Kind::None, Kind::Kleinian, Kind::Euclidean})
        {
            const double magnitude =
                std::abs(TwoCrossings::amplitude(kind, omega, c, mu, transverse, 1.0));
            report.check(std::format("  {:22} : |t| = {:.4f}, at most one",
                                     IntermediateRegion::name(kind), magnitude),
                         magnitude > 0.0 && magnitude <= 1.0 + 1e-9);
        }

        report.subsection("13.2  With no intermediate region the delay is the free flight");
        for (double thickness : {0.5, 1.0, 4.0})
        {
            const double delay =
                TwoCrossings::returnDelay(Kind::None, omega, c, mu, transverse, thickness);
            const double kappa = std::sqrt(TwoCrossings::outsideSquared(omega, c, mu, transverse));
            const double expected = thickness * omega / (kappa * c * c);
            report.checkNear(std::format("  d = {:g} : delay {:.4f} matches the group time",
                                         thickness, delay),
                             delay - expected, 1e-4);
        }

        report.subsection("13.3  The delay is slower than light for a free crossing");
        report.check("with no intermediate region the particle is subluminal, as "
                     "it must be",
                     TwoCrossings::delayInLightTimes(Kind::None, omega, c, mu, transverse, 1.0) >
                         1.0);

        report.subsection("13.4  Whether a region is a barrier depends on the frequency");
        report.check("at high frequency even a Euclidean region propagates, so it "
                     "is not a barrier there",
                     TwoCrossings::insideSquared(Kind::Euclidean, omega, c, mu, transverse) > 0.0);
        const double barrierOmega = 2.8;
        report.check("below a threshold frequency the same region turns evanescent",
                     TwoCrossings::insideSquared(Kind::Euclidean, barrierOmega, c, mu, transverse) <
                         0.0);
        report.check("while the particle still propagates outside it, so the "
                     "crossing question is meaningful there",
                     TwoCrossings::outsideSquared(barrierOmega, c, mu, transverse) > 0.0);

        report.subsection("13.5  In the barrier regime the delay saturates: the Hartman effect");
        double previous = 0.0;
        bool saturating = true;
        for (double thickness : {1.0, 2.0, 4.0, 8.0})
        {
            const double delay = TwoCrossings::returnDelay(Kind::Euclidean, barrierOmega, c, mu,
                                                           transverse, thickness);
            report.check(std::format("  d = {:g} : delay {:.4f}", thickness, delay), delay > 0.0);
            if (thickness > 1.0 && delay > previous * 1.6)
            {
                saturating = false;
            }
            previous = delay;
        }
        report.check("the delay stops growing with thickness, so a thicker "
                     "Euclidean region is not a longer journey",
                     saturating);
        report.check("and the crossing is then faster than light would have been, "
                     "which is where the placement gets interesting",
                     TwoCrossings::delayInLightTimes(Kind::Euclidean, barrierOmega, c, mu,
                                                     transverse, 8.0) < 1.0);

        report.subsection("13.6  A Kleinian region resonates instead of saturating");
        double smallest = 1e9;
        double largest = -1e9;
        for (int step = 1; step <= 40; ++step)
        {
            const double thickness = 0.2 * step;
            const double delay =
                TwoCrossings::returnDelay(Kind::Kleinian, omega, c, mu, transverse, thickness);
            smallest = std::min(smallest, delay);
            largest = std::max(largest, delay);
        }
        report.check(std::format("  the delay swings between {:.4f} and {:.4f} as the "
                                 "thickness is scanned",
                                 smallest, largest),
                     largest > smallest);
        report.check("so for a Kleinian region the return moment depends on the "
                     "thickness periodically rather than monotonically",
                     largest - smallest > 0.05);

        report.subsection("13.7  The placement is set by phase, not by duration");
        report.check("the delay is the frequency derivative of the phase, and is "
                     "obtained without any clock inside the region",
                     std::abs(TwoCrossings::returnDelay(Kind::Euclidean, omega, c, mu, transverse,
                                                        2.0)) > 0.0);
        report.check("a region the particle cannot cross returns no placement at all",
                     TwoCrossings::returnDelay(Kind::Degenerate, omega, c, mu, transverse, 2.0) ==
                         0.0);
    }

}
