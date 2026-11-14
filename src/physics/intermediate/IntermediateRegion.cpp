#include "physics/intermediate/IntermediateRegion.h"

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
}
