#include "intermediate/ThresholdOptimum.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"

#include <cmath>
#include <format>

namespace slm
{

    double ThresholdOptimum::decaySquared(double normalPart, double transversePart, int turned)
    {
        if (turned < 0)
        {
            return 0.0;
        }
        return IntermediateRegion::turnedWeight(turned) * transversePart - normalPart;
    }

    bool ThresholdOptimum::isBarrier(double normalPart, double transversePart, int turned)
    {
        return decaySquared(normalPart, transversePart, turned) > 0.0;
    }

    double ThresholdOptimum::frequency(double normalPart, double transversePart, double mu,
                                       double c)
    {
        return c * std::sqrt(normalPart + transversePart + mu);
    }

    double ThresholdOptimum::saturatedDelay(double normalPart, double transversePart, double mu,
                                            double c, int turned)
    {
        const double decay = decaySquared(normalPart, transversePart, turned);
        if (decay <= 0.0 || normalPart <= 0.0 || c <= 0.0)
        {
            return 0.0;
        }
        return 2.0 * frequency(normalPart, transversePart, mu, c) /
               (c * c * std::sqrt(normalPart) * std::sqrt(decay));
    }

    double ThresholdOptimum::thresholdDistance(double normalPart, double transversePart, double mu,
                                                double c, int turned)
    {
        return 2.0 * saturatedDelay(normalPart, transversePart, mu, c, turned);
    }

    bool ThresholdOptimum::delayHasSaturatedAtDepth(double normalPart, double transversePart,
                                                    double mu, double c, int turned, double depth,
                                                    double tolerance)
    {
        const double decay = decaySquared(normalPart, transversePart, turned);
        if (decay <= 0.0 || normalPart <= 0.0)
        {
            return false;
        }
        const double kappa = std::sqrt(normalPart);
        const double beta = std::sqrt(decay);
        const double thickness = depth / beta;
        const double omega = frequency(normalPart, transversePart, mu, c);
        const double difference = kappa * kappa - beta * beta;
        const double t = std::tanh(beta * thickness);
        const double u = 2.0 * kappa * beta / (difference * t);
        const double dKappa = omega / (c * c * kappa);
        const double dBeta = -omega / (c * c * beta);
        const double dT = (1.0 - t * t) * thickness * dBeta;
        const double dDifference = 2.0 * (kappa * dKappa - beta * dBeta);
        const double du = (2.0 * (dKappa * beta + kappa * dBeta) * difference * t -
                           2.0 * kappa * beta * (dDifference * t + difference * dT)) /
                          (difference * difference * t * t);
        const double finite = -du / (1.0 + u * u);
        const double saturated = saturatedDelay(normalPart, transversePart, mu, c, turned);
        return std::abs(finite - saturated) <= tolerance * std::abs(saturated);
    }

    double ThresholdOptimum::smallestThresholdAtTotal(double total, double mu, double c, int turned)
    {
        return 2.0 * smallestDelayAtTotal(total, mu, c, turned);
    }

    double ThresholdOptimum::optimalNormalPart(double total, int turned)
    {
        if (turned <= 0 || total <= 0.0)
        {
            return 0.0;
        }
        const double weight = IntermediateRegion::turnedWeight(turned);
        return weight * total / (2.0 * (weight + 1.0));
    }

    double ThresholdOptimum::smallestDelayAtTotal(double total, double mu, double c, int turned)
    {
        const double normal = optimalNormalPart(total, turned);
        return saturatedDelay(normal, total - normal, mu, c, turned);
    }

    double ThresholdOptimum::thicknessForDepth(double normalPart, double transversePart, int turned,
                                               double depth)
    {
        const double decay = decaySquared(normalPart, transversePart, turned);
        if (decay <= 0.0 || depth <= 0.0)
        {
            return 0.0;
        }
        return depth / std::sqrt(decay);
    }

    double ThresholdOptimum::amplitudeAtDepth(double normalPart, double transversePart, double mu,
                                              double c, int turned, double depth)
    {
        const double decay = decaySquared(normalPart, transversePart, turned);
        if (decay <= 0.0 || normalPart <= 0.0)
        {
            return 0.0;
        }
        const double kappa = std::sqrt(normalPart);
        const double beta = std::sqrt(decay);
        const double thickness = thicknessForDepth(normalPart, transversePart, turned, depth);
        (void)mu;
        (void)c;
        const double difference = kappa * kappa - beta * beta;
        const double product = 2.0 * kappa * beta;
        const double real = difference * std::sinh(beta * thickness);
        const double imaginary = product * std::cosh(beta * thickness);
        return product / std::hypot(real, imaginary);
    }

    bool ThresholdOptimum::delayFallsWithoutBound(double mu, double c, int turned)
    {
        double previous = 1e30;
        for (double total : {5.0, 50.0, 500.0, 5000.0})
        {
            const double delay = smallestDelayAtTotal(total, mu, c, turned);
            if (delay <= 0.0 || delay >= previous)
            {
                return false;
            }
            previous = delay;
        }
        return previous < 0.05 * smallestDelayAtTotal(5.0, mu, c, turned);
    }

    bool ThresholdOptimum::amplitudeHoldsAtFixedDepth(double mu, double c, int turned,
                                                      double tolerance)
    {
        const double depth = 6.0;
        double first = -1.0;
        for (double total : {5.0, 50.0, 500.0, 5000.0})
        {
            const double normal = optimalNormalPart(total, turned);
            const double value =
                amplitudeAtDepth(normal, total - normal, mu, c, turned, depth);
            if (first < 0.0)
            {
                first = value;
                continue;
            }
            if (std::abs(value - first) > tolerance * first)
            {
                return false;
            }
        }
        return first > 0.0;
    }

    void ThresholdOptimumSection::run(Report &report) const
    {
        const double mu = 1.0;
        const double c = 1.0;
        const int turned = 3;

        report.subsection("The reference configuration, recovered");
        report.check(std::format("  normal 2.84, transverse 4 : delay {:.6f}",
                                 ThresholdOptimum::saturatedDelay(2.84, 4.0, mu, c, turned)),
                     std::abs(ThresholdOptimum::saturatedDelay(2.84, 4.0, mu, c, turned) -
                              1.462864) < 1e-5);

        report.subsection("At fixed total energy there is an interior optimum, and it is mild");
        const double total = 6.84;
        for (double normal : {1.0, 2.28, 2.84, 4.0})
        {
            report.check(std::format("  normal {:5g} of {:g} : delay {:.6f}", normal, total,
                                     ThresholdOptimum::saturatedDelay(normal, total - normal, mu, c,
                                                                       turned)),
                         ThresholdOptimum::isBarrier(normal, total - normal, turned));
        }
        report.check(std::format("  the smallest at this total is {:.6f}, at a normal part of "
                                 "{:.4f}",
                                 ThresholdOptimum::smallestDelayAtTotal(total, mu, c, turned),
                                 ThresholdOptimum::optimalNormalPart(total, turned)),
                     ThresholdOptimum::smallestDelayAtTotal(total, mu, c, turned) <=
                         ThresholdOptimum::saturatedDelay(2.84, total - 2.84, mu, c, turned));
        report.check("the configuration already in use is within a few per cent of the "
                     "best split, so nothing much is available from rebalancing alone",
                     ThresholdOptimum::saturatedDelay(2.84, 4.0, mu, c, turned) <
                         1.05 * ThresholdOptimum::smallestDelayAtTotal(total, mu, c, turned));

        report.subsection("Raising the total energy is not mild");
        for (double each : {6.84, 50.0, 500.0, 5000.0})
        {
            report.check(std::format("  total {:8g} : smallest delay {:.6f}", each,
                                     ThresholdOptimum::smallestDelayAtTotal(each, mu, c, turned)),
                         ThresholdOptimum::smallestDelayAtTotal(each, mu, c, turned) > 0.0);
        }
        report.check("the delay falls without bound as the total energy rises, so the "
                     "distance that has to be covered on the far side is not a fixed "
                     "price but a chosen one",
                     ThresholdOptimum::delayFallsWithoutBound(mu, c, turned));

        report.subsection("What it costs, at a fixed depth of saturation");
        for (double each : {6.84, 50.0, 500.0, 5000.0})
        {
            const double normal = ThresholdOptimum::optimalNormalPart(each, turned);
            report.check(std::format("  total {:8g} : thickness {:.6f}, amplitude {:.6e}", each,
                                     ThresholdOptimum::thicknessForDepth(normal, each - normal,
                                                                         turned, 6.0),
                                     ThresholdOptimum::amplitudeAtDepth(normal, each - normal, mu,
                                                                         c, turned, 6.0)),
                         ThresholdOptimum::amplitudeAtDepth(normal, each - normal, mu, c, turned,
                                                             6.0) > 0.0);
        }
        report.check("the amplitude does not move as the energy rises, because "
                     "saturation depends on the decay constant times the thickness and "
                     "that product is being held fixed",
                     ThresholdOptimum::amplitudeHoldsAtFixedDepth(mu, c, turned, 1e-3));
        report.check("so the falling distance is not paid for out of the amplitude, "
                     "which is what makes it a gain rather than a trade",
                     ThresholdOptimum::delayFallsWithoutBound(mu, c, turned) &&
                         ThresholdOptimum::amplitudeHoldsAtFixedDepth(mu, c, turned, 1e-3));

        report.subsection("The saturation the whole comparison assumes, checked");
        for (double each : {6.84, 50.0, 500.0, 5000.0})
        {
            const double normal = ThresholdOptimum::optimalNormalPart(each, turned);
            report.check(std::format("  total {:8g} : at depth 6 the finite-thickness delay is "
                                     "within a per cent of the saturated one",
                                     each),
                         ThresholdOptimum::delayHasSaturatedAtDepth(normal, each - normal, mu, c,
                                                                     turned, 6.0, 1e-2));
        }
        report.check("so the depth held fixed above is deep enough for the saturated "
                     "form to be the right one, which the comparison assumed and now "
                     "does not have to",
                     ThresholdOptimum::delayHasSaturatedAtDepth(
                         ThresholdOptimum::optimalNormalPart(500.0, turned),
                         500.0 - ThresholdOptimum::optimalNormalPart(500.0, turned), mu, c, turned,
                         6.0, 1e-2));

        report.subsection("Against the reference distance, which is a round trip");
        report.check(std::format("  the reference configuration gives a threshold distance of "
                                 "{:.6f}",
                                 ThresholdOptimum::thresholdDistance(3.947853, 5.051327, mu, c,
                                                                      turned)),
                     std::abs(ThresholdOptimum::thresholdDistance(3.947853, 5.051327, mu, c,
                                                                   turned) -
                              2.565988) < 1e-4);
        for (double each : {9.0, 50.0, 500.0, 5000.0})
        {
            report.check(std::format("  total {:8g} : smallest far-side distance {:.6f}", each,
                                     ThresholdOptimum::smallestThresholdAtTotal(each, mu, c,
                                                                                 turned)),
                         ThresholdOptimum::smallestThresholdAtTotal(each, mu, c, turned) > 0.0);
        }

        report.subsection("What is paid instead");
        for (double each : {6.84, 500.0})
        {
            const double normal = ThresholdOptimum::optimalNormalPart(each, turned);
            report.check(std::format("  total {:8g} : frequency {:.4f}, thickness {:.6f}", each,
                                     ThresholdOptimum::frequency(normal, each - normal, mu, c),
                                     ThresholdOptimum::thicknessForDepth(normal, each - normal,
                                                                         turned, 6.0)),
                         ThresholdOptimum::frequency(normal, each - normal, mu, c) > 0.0);
        }
        report.check("the price is energy and a thinner region, both of which rise and "
                     "fall together, and neither of which is the amplitude",
                     ThresholdOptimum::frequency(ThresholdOptimum::optimalNormalPart(500.0, turned),
                                                  500.0 - ThresholdOptimum::optimalNormalPart(500.0,
                                                                                              turned),
                                                  mu, c) >
                         ThresholdOptimum::frequency(
                             ThresholdOptimum::optimalNormalPart(6.84, turned),
                             6.84 - ThresholdOptimum::optimalNormalPart(6.84, turned), mu, c));
    }

}
