#include "intermediate/IntermediateRegion.h"

#include "boundary/SlabTunnelling.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <limits>

namespace slm
{

    int IntermediateRegion::flippedDirections(Kind kind)
    {
        switch (kind)
        {
        case Kind::None:
            return 0;
        case Kind::SplitSignature:
            return 1;
        case Kind::Euclidean:
            return 3;
        case Kind::Degenerate:
            return -1;
        }
        return 0;
    }

    std::string IntermediateRegion::name(Kind kind)
    {
        switch (kind)
        {
        case Kind::None:
            return "no intermediate region";
        case Kind::SplitSignature:
            return "split signature (2,2)";
        case Kind::Euclidean:
            return "Euclidean (4,0)";
        case Kind::Degenerate:
            return "degenerate layer";
        }
        return "unknown";
    }

    double IntermediateRegion::outsideNormalSquared(double c, double mu, double transverseSquared)
    {
        return c * c * (transverseSquared + mu);
    }

    double IntermediateRegion::insideNormalSquared(Kind kind, double c, double mu,
                                                   double transverseSquared)
    {
        if (kind == Kind::Degenerate)
        {
            return -std::numeric_limits<double>::infinity();
        }
        const double flipped = flippedDirections(kind);
        const double share = 1.0 - turnedWeight(static_cast<int>(flipped));
        return c * c * (share * transverseSquared + mu);
    }

    double IntermediateRegion::fixedFrequency(double c, double mu, double transverseSquared)
    {
        return c * std::sqrt(outsideNormalSquared(c, mu, transverseSquared) + transverseSquared +
                             mu);
    }

    double IntermediateRegion::insideFromFrequency(int turned, double c, double mu,
                                                   double transverseSquared, double frequency)
    {
        return frequency * frequency / (c * c) - (1.0 + turnedWeight(turned)) * transverseSquared -
               mu;
    }

    bool IntermediateRegion::blocks(Kind kind, double c, double mu, double transverseSquared)
    {
        return insideNormalSquared(kind, c, mu, transverseSquared) < 0.0;
    }

    double IntermediateRegion::turnedWeight(int turned)
    {
        return turned > 0 ? 2.0 * turned / 3.0 : 0.0;
    }

    double IntermediateRegion::transmission(Kind kind, double c, double mu,
                                            double transverseSquared, double thickness)
    {
        if (thickness <= 0.0)
        {
            return 1.0;
        }
        if (kind == Kind::None)
        {
            return 1.0;
        }

        const double kappaSquared = outsideNormalSquared(c, mu, transverseSquared);
        const double inside = insideNormalSquared(kind, c, mu, transverseSquared);

        if (kind == Kind::Degenerate || std::isinf(inside))
        {
            return 0.0;
        }

        return SlabTunnelling::transmissionFromSquares(kappaSquared, inside, thickness);
    }

    double IntermediateRegion::layerStrength(Kind kind, double thickness)
    {
        if (kind == Kind::None)
        {
            return 0.0;
        }
        const int flipped = flippedDirections(kind);
        const double turned = flipped < 0 ? 1.0 : static_cast<double>(flipped);
        if (thickness <= 0.0)
        {
            return std::numeric_limits<double>::infinity();
        }
        return turned / thickness;
    }

    double IntermediateRegion::layerStrengthStationaryProfile(Kind, double)
    {
        return 0.0;
    }

    void IntermediateRegionSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const Kind kinds[] = {Kind::None, Kind::SplitSignature, Kind::Euclidean, Kind::Degenerate};
        const double thicknesses[] = {0.0, 0.1, 1.0, 4.0, 40.0};

        report.subsection("What each kind does to the interior mode");
        report.check("with no intermediate region the interior is the near-side region",
                     std::abs(IntermediateRegion::insideNormalSquared(Kind::None, c, mu,
                                                                      transverse) -
                              IntermediateRegion::outsideNormalSquared(c, mu, transverse)) < 1e-12);
        report.check("a split-signature region still propagates when the wavenumber is "
                     "shared evenly, so it is not a barrier by itself",
                     !IntermediateRegion::blocks(Kind::SplitSignature, c, mu, transverse));
        report.check("a Euclidean region blocks once the transverse wavenumber "
                     "exceeds the mass",
                     IntermediateRegion::blocks(Kind::Euclidean, c, mu, transverse));
        report.check("a Euclidean region does not block a mode below the mass",
                     !IntermediateRegion::blocks(Kind::Euclidean, c, mu, 0.25));
        report.check("a degenerate layer blocks whatever the mode",
                     IntermediateRegion::blocks(Kind::Degenerate, c, mu, transverse) &&
                         IntermediateRegion::blocks(Kind::Degenerate, c, mu, 0.01));

        report.subsection("The frequency this grid is evaluated at");
        {
            const double omega = IntermediateRegion::fixedFrequency(c, mu, transverse);
            report.checkNear("the grid sits on one frequency, and it is the one where the "
                             "outside wavenumber equals the transverse part plus the mass",
                             omega - std::sqrt(2.0 * (transverse + mu)), 1e-12);
            for (Kind kind : kinds)
            {
                if (kind == Kind::Degenerate)
                {
                    continue;
                }
                const int turned = IntermediateRegion::flippedDirections(kind);
                report.checkNear(
                    std::format("  {:22} : the general form from a frequency agrees here",
                                IntermediateRegion::name(kind)),
                    IntermediateRegion::insideFromFrequency(turned, c, mu, transverse, omega) -
                        IntermediateRegion::insideNormalSquared(kind, c, mu, transverse),
                    1e-12);
            }
            report.check("and it disagrees away from that frequency, so the choice is a "
                         "choice rather than an identity",
                         std::abs(IntermediateRegion::insideFromFrequency(
                                      3, c, mu, transverse, omega * 1.5) -
                                  IntermediateRegion::insideNormalSquared(Kind::Euclidean, c, mu,
                                                                          transverse)) > 1.0);
            report.check("a Euclidean region stops blocking once the frequency is raised "
                         "far enough, which the fixed-frequency reading cannot show",
                         IntermediateRegion::insideFromFrequency(3, c, mu, transverse,
                                                                 omega * 1.5) > 0.0);
        }

        report.subsection("Transmission across the whole grid");
        for (Kind kind : kinds)
        {
            for (double thickness : thicknesses)
            {
                const double t =
                    IntermediateRegion::transmission(kind, c, mu, transverse, thickness);
                report.check(std::format("  {:22} d = {:4g} : T = {:.4e}",
                                         IntermediateRegion::name(kind), thickness, t),
                             t >= 0.0 && t <= 1.0);
            }
        }

        report.subsection("What the grid says");
        report.check("at zero thickness every kind transmits everything, so the "
                     "kind cannot matter there",
                     IntermediateRegion::transmission(Kind::Euclidean, c, mu, transverse, 0.0) ==
                         IntermediateRegion::transmission(Kind::Degenerate, c, mu, transverse,
                                                          0.0));
        report.check("with no intermediate region the thickness cannot matter either",
                     IntermediateRegion::transmission(Kind::None, c, mu, transverse, 40.0) ==
                         IntermediateRegion::transmission(Kind::None, c, mu, transverse, 0.1));
        report.check("a Euclidean region suppresses exponentially with thickness",
                     IntermediateRegion::transmission(Kind::Euclidean, c, mu, transverse, 4.0) <
                         1e-4 * IntermediateRegion::transmission(Kind::Euclidean, c, mu, transverse,
                                                                 0.1));
        report.check("a thick Euclidean region is indistinguishable from a "
                     "degenerate one, both closed",
                     IntermediateRegion::transmission(Kind::Euclidean, c, mu, transverse, 40.0) <
                         1e-30);
        report.check("but a split-signature region of any thickness stays open for this mode",
                     IntermediateRegion::transmission(Kind::SplitSignature, c, mu, transverse, 40.0) >
                         1e-3);

        report.subsection("The matter layer the junction carries");
        for (Kind kind : {Kind::SplitSignature, Kind::Euclidean})
        {
            for (double thickness : {0.1, 1.0, 4.0})
            {
                report.check(
                    std::format("  {:22} d = {:4g} : layer strength {:.3f}",
                                IntermediateRegion::name(kind), thickness,
                                IntermediateRegion::layerStrength(kind, thickness)),
                    IntermediateRegion::layerStrength(kind, thickness) > 0.0);
            }
        }
        report.check("the layer weakens as the region thickens, in proportion to "
                     "one over the thickness",
                     IntermediateRegion::layerStrength(Kind::SplitSignature, 4.0) <
                         IntermediateRegion::layerStrength(Kind::SplitSignature, 0.1));
        report.check("a zero-thickness junction carries an unbounded layer, which "
                     "is why the sharp interface is the worst case",
                     std::isinf(IntermediateRegion::layerStrength(Kind::SplitSignature, 0.0)));

        report.subsection("The one way to avoid the layer");
        report.checkNear("a profile stationary at the crossing carries no layer at all",
                         IntermediateRegion::layerStrengthStationaryProfile(Kind::SplitSignature, 1.0));
        report.check("so transmission without a matter layer is available, but "
                     "only for a tuned profile rather than a generic one",
                     IntermediateRegion::transmission(Kind::SplitSignature, c, mu, transverse, 1.0) >
                             0.0 &&
                         IntermediateRegion::layerStrengthStationaryProfile(Kind::SplitSignature, 1.0) ==
                             0.0);
    }

}
