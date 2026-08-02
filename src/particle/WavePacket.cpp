#include "particle/WavePacket.h"

#include "boundary/SlabTunnelling.h"
#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr int kSamples = 4001;

        struct Moments
        {
            double norm = 0.0;
            double mean = 0.0;
            double spread = 0.0;
        };

        Moments moments(double centre, double spread, bool throughSlab, double thickness, double c,
                        double mu, double flipped)
        {
            const double lower = std::max(0.0, centre - 8.0 * spread);
            const double upper = centre + 8.0 * spread;
            const double step = (upper - lower) / (kSamples - 1);

            double sum = 0.0;
            double sumK = 0.0;
            double sumKK = 0.0;
            for (int i = 0; i < kSamples; ++i)
            {
                const double k = lower + i * step;
                const double w = WavePacket::weight(k, centre, spread);
                double density = w * w;
                if (throughSlab)
                {
                    density *= SlabTunnelling::transmission(c, mu, k * k, flipped, thickness);
                }
                const double trapezoid = (i == 0 || i == kSamples - 1) ? 0.5 : 1.0;
                sum += trapezoid * density;
                sumK += trapezoid * density * k;
                sumKK += trapezoid * density * k * k;
            }

            Moments result;
            result.norm = sum * step;
            if (sum > 0.0)
            {
                result.mean = sumK / sum;
                const double variance = sumKK / sum - result.mean * result.mean;
                result.spread = variance > 0.0 ? std::sqrt(variance) : 0.0;
            }
            return result;
        }
    }

    double WavePacket::weight(double k, double centre, double spread)
    {
        const double z = (k - centre) / spread;
        return std::exp(-0.5 * z * z);
    }

    double WavePacket::incomingNorm(double centre, double spread)
    {
        return moments(centre, spread, false, 0.0, 1.0, 1.0, 0.0).norm;
    }

    double WavePacket::transmittedFraction(double centre, double spread, double thickness, double c,
                                           double mu, double flipped)
    {
        const double in = moments(centre, spread, false, thickness, c, mu, flipped).norm;
        const double out = moments(centre, spread, true, thickness, c, mu, flipped).norm;
        return in > 0.0 ? out / in : 0.0;
    }

    double WavePacket::incomingMean(double centre, double spread)
    {
        return moments(centre, spread, false, 0.0, 1.0, 1.0, 0.0).mean;
    }

    double WavePacket::transmittedMean(double centre, double spread, double thickness, double c,
                                       double mu, double flipped)
    {
        return moments(centre, spread, true, thickness, c, mu, flipped).mean;
    }

    double WavePacket::incomingSpread(double centre, double spread)
    {
        return moments(centre, spread, false, 0.0, 1.0, 1.0, 0.0).spread;
    }

    double WavePacket::transmittedSpread(double centre, double spread, double thickness, double c,
                                         double mu, double flipped)
    {
        return moments(centre, spread, true, thickness, c, mu, flipped).spread;
    }

    double WavePacket::centroidShiftInSpreads(double centre, double spread, double thickness,
                                              double c, double mu, double flipped)
    {
        const Moments in = moments(centre, spread, false, thickness, c, mu, flipped);
        const Moments out = moments(centre, spread, true, thickness, c, mu, flipped);
        return in.spread > 0.0 ? (out.mean - in.mean) / in.spread : 0.0;
    }

    double WavePacket::spreadChange(double centre, double spread, double thickness, double c,
                                    double mu, double flipped)
    {
        const Moments in = moments(centre, spread, false, thickness, c, mu, flipped);
        const Moments out = moments(centre, spread, true, thickness, c, mu, flipped);
        return in.spread > 0.0 ? (out.spread - in.spread) / in.spread : 0.0;
    }

    void WavePacketSection::run(Report &report) const
    {
        const double c = 1.0;
        const double mu = 1.0;
        const double flipped = 2.0;
        const double thickness = 1.0;
        const double centre = 2.0;

        report.subsection("3.1  The packet is a genuine distribution over modes");
        report.check("the incoming packet carries non-zero weight",
                     WavePacket::incomingNorm(centre, 0.4) > 0.0);
        report.checkNear("its mean sits at the centre it was given",
                         WavePacket::incomingMean(centre, 0.4) - centre, 1e-6);
        report.checkNear("its density is narrower than its amplitude by root two",
                         WavePacket::incomingSpread(centre, 0.4) - 0.4 / std::sqrt(2.0), 1e-6);

        report.subsection("3.2  The slab lets only part of the packet through");
        for (double width : {0.1, 0.4, 1.0})
        {
            const double fraction =
                WavePacket::transmittedFraction(centre, width, thickness, c, mu, flipped);
            report.check(std::format("  width {:g} : transmitted fraction {:.4f}, strictly "
                                     "between nothing and everything",
                                     width, fraction),
                         fraction > 0.0 && fraction < 1.0);
        }

        report.subsection("3.3  Transmission is mode selective, so the packet is reweighted");
        const double shiftWide =
            WavePacket::centroidShiftInSpreads(centre, 1.0, thickness, c, mu, flipped);
        report.check(std::format("  a wide packet has its centroid displaced by {:.3f} spreads",
                                 shiftWide),
                     std::abs(shiftWide) > 0.05);
        report.check("the displacement is towards larger wavenumber, which is "
                     "where the slab transmits better",
                     shiftWide > 0.0);

        report.subsection("3.4  The point-body reading survives only for a narrow packet");
        double previousShift = 1e9;
        for (double width : {1.0, 0.5, 0.25, 0.125})
        {
            const double shift = std::abs(
                WavePacket::centroidShiftInSpreads(centre, width, thickness, c, mu, flipped));
            report.check(std::format("  width {:g} : centroid shift {:.4f} spreads, smaller "
                                     "than at the previous width",
                                     width, shift),
                         shift < previousShift);
            previousShift = shift;
        }
        const double shiftAtEighth =
            std::abs(WavePacket::centroidShiftInSpreads(centre, 0.125, thickness, c, mu, flipped));
        const double shiftAtSixteenth =
            std::abs(WavePacket::centroidShiftInSpreads(centre, 0.0625, thickness, c, mu, flipped));
        report.checkNear("the shift is proportional to the width, halving with it",
                         shiftAtEighth / shiftAtSixteenth - 2.0, 0.05);
        report.check("so in the narrow-packet limit the crossing leaves the body "
                     "where it was, and the point-body layer is legitimate",
                     std::abs(WavePacket::centroidShiftInSpreads(centre, 0.02, thickness, c, mu,
                                                                 flipped)) < 0.02);

        report.subsection("3.5  What the crossing costs even so");
        report.check("a narrow packet still loses weight, so the body that "
                     "returns is fainter than the one that left",
                     WavePacket::transmittedFraction(centre, 0.05, thickness, c, mu, flipped) <
                         1.0);
        const double narrowSpreadChange =
            WavePacket::spreadChange(centre, 0.05, thickness, c, mu, flipped);
        report.check(std::format("  and its width is changed by {:+.4f} of itself",
                                 narrowSpreadChange),
                     std::abs(narrowSpreadChange) < 0.05);
    }

}
