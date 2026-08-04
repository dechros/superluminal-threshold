#include "intermediate/ChannelEntropy.h"

#include "core/Report.h"
#include "particle/RoundTrip.h"

#include <cmath>
#include <format>

namespace slm
{

    double ChannelEntropy::binaryEntropy(double probability)
    {
        if (probability <= 0.0 || probability >= 1.0)
        {
            return 0.0;
        }
        const double complement = 1.0 - probability;
        return -(probability * std::log(probability) + complement * std::log(complement));
    }

    double ChannelEntropy::outcomeEntropy(IntermediateRegion::Kind kind, double c, double mu,
                                          double transverseSquared, double thickness)
    {
        return binaryEntropy(
            IntermediateRegion::transmission(kind, c, mu, transverseSquared, thickness));
    }

    double ChannelEntropy::incomingEntropy()
    {
        return 0.0;
    }

    double ChannelEntropy::entropyGain(IntermediateRegion::Kind kind, double c, double mu,
                                       double transverseSquared, double thickness)
    {
        return outcomeEntropy(kind, c, mu, transverseSquared, thickness) - incomingEntropy();
    }

    double ChannelEntropy::maximalEntropy()
    {
        return std::log(2.0);
    }

    bool ChannelEntropy::outcomeIsDecided(IntermediateRegion::Kind kind, double c, double mu,
                                          double transverseSquared, double thickness,
                                          double tolerance)
    {
        return outcomeEntropy(kind, c, mu, transverseSquared, thickness) <= tolerance;
    }

    double ChannelEntropy::maximalEntropyOverThickness(IntermediateRegion::Kind kind, double c,
                                                       double mu, double transverseSquared,
                                                       double maximumThickness, int samples)
    {
        double best = 0.0;
        for (int n = 0; n <= samples; ++n)
        {
            const double thickness = maximumThickness * n / static_cast<double>(samples);
            best = std::max(best, outcomeEntropy(kind, c, mu, transverseSquared, thickness));
        }
        return best;
    }

    double ChannelEntropy::thicknessOfMaximalEntropy(IntermediateRegion::Kind kind, double c,
                                                     double mu, double transverseSquared,
                                                     double maximumThickness, int samples)
    {
        double best = -1.0;
        double bestThickness = 0.0;
        for (int n = 0; n <= samples; ++n)
        {
            const double thickness = maximumThickness * n / static_cast<double>(samples);
            const double value = outcomeEntropy(kind, c, mu, transverseSquared, thickness);
            if (value > best)
            {
                best = value;
                bestThickness = thickness;
            }
        }
        return bestThickness;
    }

    bool ChannelEntropy::reachesEvenSplit(IntermediateRegion::Kind kind, double c, double mu,
                                          double transverseSquared, double maximumThickness,
                                          int samples, double tolerance)
    {
        const double best =
            maximalEntropyOverThickness(kind, c, mu, transverseSquared, maximumThickness, samples);
        return maximalEntropy() - best <= tolerance;
    }

    void ChannelEntropySection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double thickness = 1.0;

        report.subsection("The measure itself");
        report.checkNear("a decided outcome carries no entropy, H(0) = 0",
                         ChannelEntropy::binaryEntropy(0.0));
        report.checkNear("nor does the other decided outcome, H(1) = 0",
                         ChannelEntropy::binaryEntropy(1.0));
        report.checkNear("an even split carries ln 2",
                         ChannelEntropy::binaryEntropy(0.5) - ChannelEntropy::maximalEntropy());
        report.check("and nothing carries more, over a scan of the unit interval",
                     [] {
                         for (int n = 0; n <= 10000; ++n)
                         {
                             const double p = n / 10000.0;
                             if (ChannelEntropy::binaryEntropy(p) >
                                 ChannelEntropy::maximalEntropy() + 1e-12)
                             {
                                 return false;
                             }
                         }
                         return true;
                     }());
        report.checkNear("the incoming state occupies one channel, so it carries none",
                         ChannelEntropy::incomingEntropy());

        report.subsection("What each region type produces at unit thickness");
        for (Kind kind : {Kind::SplitSignature, Kind::Euclidean, Kind::Degenerate})
        {
            const double transmitted =
                IntermediateRegion::transmission(kind, c, mu, transverse, thickness);
            const double produced =
                ChannelEntropy::entropyGain(kind, c, mu, transverse, thickness);
            report.check(std::format("  {:<10} transmits {:.6f}, produces {:.6f} nats",
                                     IntermediateRegion::name(kind), transmitted, produced),
                         produced >= 0.0);
        }

        report.subsection("The degenerate region produces none, at any thickness");
        bool degenerateAlwaysDecided = true;
        for (double d : {0.1, 0.5, 1.0, 2.0, 4.0, 8.0, 16.0})
        {
            degenerateAlwaysDecided =
                degenerateAlwaysDecided &&
                ChannelEntropy::outcomeIsDecided(Kind::Degenerate, c, mu, transverse, d);
        }
        report.check("it reflects everything, so its outcome is decided before it starts",
                     degenerateAlwaysDecided);
        report.checkNear("and its largest entropy over the whole thickness range is zero",
                         ChannelEntropy::maximalEntropyOverThickness(Kind::Degenerate, c, mu,
                                                                     transverse));

        report.subsection("Only one type reaches an even split");
        const double euclideanBest =
            ChannelEntropy::maximalEntropyOverThickness(Kind::Euclidean, c, mu, transverse);
        const double euclideanAt =
            ChannelEntropy::thicknessOfMaximalEntropy(Kind::Euclidean, c, mu, transverse);
        report.checkNear(std::format("Euclidean attains the bound ln 2 at d = {:.3f}", euclideanAt),
                         euclideanBest - ChannelEntropy::maximalEntropy(), 1e-6);
        report.check("so there is a thickness at which the crossing is maximally undecided",
                     ChannelEntropy::reachesEvenSplit(Kind::Euclidean, c, mu, transverse));

        const double splitSignatureBest =
            ChannelEntropy::maximalEntropyOverThickness(Kind::SplitSignature, c, mu, transverse);
        report.check(std::format("The split signature never does: its largest is {:.6f}, short "
                                 "of ln 2",
                                 splitSignatureBest),
                     splitSignatureBest < ChannelEntropy::maximalEntropy() - 0.1);
        report.check("because its interior propagates, so transmission stays near one",
                     IntermediateRegion::transmission(Kind::SplitSignature, c, mu, transverse, 0.1) > 0.9);

        report.subsection("The thick limit produces none either");
        report.check("Euclidean transmission falls to zero with thickness",
                     IntermediateRegion::transmission(Kind::Euclidean, c, mu, transverse, 8.0) <
                         1e-6);
        report.check("so its entropy returns to zero once the region is thick",
                     ChannelEntropy::outcomeIsDecided(Kind::Euclidean, c, mu, transverse, 8.0,
                                                      1e-4));
        report.check("entropy production is therefore not monotone in thickness: it is zero "
                     "at both ends and largest in between",
                     ChannelEntropy::outcomeIsDecided(Kind::Euclidean, c, mu, transverse, 0.0) &&
                         euclideanBest > 0.5 &&
                         ChannelEntropy::outcomeIsDecided(Kind::Euclidean, c, mu, transverse, 8.0,
                                                          1e-4));

        report.subsection("Against the mode-distribution entropy, which is the other candidate");
        const double centre = 2.0;
        const double spread = 0.3;
        const double incomingShape = RoundTrip::incomingEntropy(centre, spread);
        const double splitSignatureShape =
            RoundTrip::returnedEntropy(centre, spread, Kind::SplitSignature, c, mu, thickness);
        const double euclideanShape =
            RoundTrip::returnedEntropy(centre, spread, Kind::Euclidean, c, mu, thickness);
        report.check(std::format("the packet's own entropy rises for split signature, {:+.6f}",
                                 splitSignatureShape - incomingShape),
                     splitSignatureShape > incomingShape);
        report.check(std::format("and falls for Euclidean, {:+.6f}",
                                 euclideanShape - incomingShape),
                     euclideanShape < incomingShape);
        report.check("so the mode-distribution entropy has no fixed sign and cannot carry a "
                     "direction, while the channel entropy is non-negative by construction",
                     (splitSignatureShape - incomingShape) * (euclideanShape - incomingShape) < 0.0 &&
                         ChannelEntropy::entropyGain(Kind::SplitSignature, c, mu, transverse,
                                                     thickness) >= 0.0 &&
                         ChannelEntropy::entropyGain(Kind::Euclidean, c, mu, transverse,
                                                     thickness) >= 0.0);
    }

}
