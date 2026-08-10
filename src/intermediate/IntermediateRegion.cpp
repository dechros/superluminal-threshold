#include "intermediate/IntermediateRegion.h"

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

    void IntermediateRegionSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const Kind kinds[] = {Kind::None, Kind::SplitSignature, Kind::Euclidean, Kind::Degenerate};

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
    }

}
