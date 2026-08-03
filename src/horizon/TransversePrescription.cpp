#include "horizon/TransversePrescription.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        double signedPower(double xi, int order)
        {
            const double magnitude = std::pow(std::abs(xi), static_cast<double>(order));
            return xi < 0.0 ? -magnitude : magnitude;
        }
    }

    double TransversePrescription::degenerateComponent(double xi, int degenerateOrder)
    {
        if (degenerateOrder < 1)
        {
            return 0.0;
        }
        return signedPower(xi, degenerateOrder);
    }

    double TransversePrescription::degenerateSlope(double xi, int degenerateOrder)
    {
        if (degenerateOrder < 1)
        {
            return 0.0;
        }
        return degenerateOrder * std::pow(std::abs(xi), static_cast<double>(degenerateOrder - 1));
    }

    bool TransversePrescription::isTransverse(int degenerateOrder)
    {
        return degenerateOrder == 1;
    }

    double TransversePrescription::lapse(double xi, int degenerateOrder)
    {
        return std::sqrt(std::abs(degenerateComponent(xi, degenerateOrder)));
    }

    double TransversePrescription::tangentialSlope(double xi, int tangentialOrder)
    {
        if (tangentialOrder < 0)
        {
            return 0.0;
        }
        return std::pow(std::abs(xi), static_cast<double>(tangentialOrder));
    }

    double TransversePrescription::extrinsicCurvature(double xi, int degenerateOrder,
                                                      int tangentialOrder)
    {
        const double denominator = lapse(xi, degenerateOrder);
        if (denominator <= 0.0)
        {
            return 0.0;
        }
        return tangentialSlope(xi, tangentialOrder) / (2.0 * denominator);
    }

    bool TransversePrescription::isTotallyGeodesic(int tangentialOrder)
    {
        return tangentialOrder >= 1;
    }

    bool TransversePrescription::bothConditionsHold(int degenerateOrder, int tangentialOrder)
    {
        return isTransverse(degenerateOrder) && isTotallyGeodesic(tangentialOrder);
    }

    double TransversePrescription::ratio(double distance, int degenerateOrder, int tangentialOrder)
    {
        const double denominator = lapse(distance, degenerateOrder);
        if (denominator <= 0.0)
        {
            return 0.0;
        }
        return tangentialSlope(distance, tangentialOrder) / denominator;
    }

    double TransversePrescription::ratioExponent(int degenerateOrder, int tangentialOrder,
                                                 double nearDistance, double farDistance)
    {
        const double near = ratio(nearDistance, degenerateOrder, tangentialOrder);
        const double far = ratio(farDistance, degenerateOrder, tangentialOrder);
        if (near <= 0.0 || far <= 0.0 || nearDistance <= 0.0 || farDistance <= 0.0 ||
            nearDistance == farDistance)
        {
            return 0.0;
        }
        return std::log(near / far) / std::log(nearDistance / farDistance);
    }

    double TransversePrescription::predictedExponent(int degenerateOrder, int tangentialOrder)
    {
        return tangentialOrder - degenerateOrder / 2.0;
    }

    bool TransversePrescription::satisfiesRateCondition(int degenerateOrder, int tangentialOrder)
    {
        return ratio(1e-4, degenerateOrder, tangentialOrder) <
               ratio(1e-2, degenerateOrder, tangentialOrder);
    }

    double TransversePrescription::conflatedRatio(double distance, int degenerateOrder)
    {
        const double denominator = lapse(distance, degenerateOrder);
        if (denominator <= 0.0)
        {
            return 0.0;
        }
        return 0.5 * std::abs(degenerateSlope(distance, degenerateOrder)) / denominator;
    }

    double TransversePrescription::conflatedExponent(int degenerateOrder, double nearDistance,
                                                     double farDistance)
    {
        const double near = conflatedRatio(nearDistance, degenerateOrder);
        const double far = conflatedRatio(farDistance, degenerateOrder);
        if (near <= 0.0 || far <= 0.0 || nearDistance <= 0.0 || farDistance <= 0.0 ||
            nearDistance == farDistance)
        {
            return 0.0;
        }
        return std::log(near / far) / std::log(nearDistance / farDistance);
    }

    double TransversePrescription::predictedConflatedExponent(int degenerateOrder)
    {
        return degenerateOrder / 2.0 - 1.0;
    }

    bool TransversePrescription::conflatedAllowsBoth(int highestOrder)
    {
        for (int q = 1; q <= highestOrder; ++q)
        {
            if (isTransverse(q) && predictedConflatedExponent(q) > 0.0)
            {
                return true;
            }
        }
        return false;
    }

    bool TransversePrescription::generalAllowsBoth()
    {
        return bothConditionsHold(1, 1) && satisfiesRateCondition(1, 1);
    }

    bool TransversePrescription::anyOrderKeepsLayerAndRate(int highestOrder)
    {
        for (int q = 1; q <= highestOrder; ++q)
        {
            for (int p = 0; p <= highestOrder; ++p)
            {
                if (!isTotallyGeodesic(p) && satisfiesRateCondition(q, p))
                {
                    return true;
                }
            }
        }
        return false;
    }

    void TransversePrescriptionSection::run(Report &report) const
    {
        report.subsection("The two conditions constrain different components");
        report.check(std::format("  transversality binds the degenerating component, whose "
                                 "slope at unit distance is {:.4f} at first order",
                                 TransversePrescription::degenerateSlope(1.0, 1)),
                     TransversePrescription::isTransverse(1) &&
                         !TransversePrescription::isTransverse(3));
        report.check(std::format("  the extrinsic curvature is built from the tangential slope "
                                 "instead, giving {:.4e} at first order in each",
                                 TransversePrescription::extrinsicCurvature(1e-2, 1, 1)),
                     TransversePrescription::extrinsicCurvature(1e-2, 1, 1) > 0.0);
        report.check("so the two are independent knobs and can be turned at once, which "
                     "is why the surrounding literature imposes them together without "
                     "remarking on any tension",
                     TransversePrescription::bothConditionsHold(1, 1) &&
                         TransversePrescription::bothConditionsHold(1, 2));

        report.subsection("The exponent in closed form, against the measurement");
        for (int q : {1, 2, 3})
        {
            for (int p : {0, 1, 2})
            {
                const double measured =
                    TransversePrescription::ratioExponent(q, p, 1e-4, 1e-2);
                const double predicted = TransversePrescription::predictedExponent(q, p);
                report.check(std::format("  degenerate order {}, tangential order {} : measured "
                                         "{:+.4f}, closed form {:+.4f}",
                                         q, p, measured, predicted),
                             std::abs(measured - predicted) < 1e-9);
            }
        }
        report.check("the ratio therefore goes as the distance to the tangential order "
                     "less half the degenerate order, exactly, so the rate condition is "
                     "a formula and not a numerical observation",
                     std::abs(TransversePrescription::ratioExponent(1, 1, 1e-4, 1e-2) -
                              TransversePrescription::predictedExponent(1, 1)) < 1e-9);

        report.subsection("The conflated reading is that formula one order down");
        for (int q : {1, 2, 3})
        {
            const double measured = TransversePrescription::conflatedExponent(q, 1e-4, 1e-2);
            report.check(std::format("  degenerate order {} : conflated exponent {:+.4f}, which "
                                     "is the general formula at tangential order {}",
                                     q, measured, q - 1),
                         std::abs(measured - TransversePrescription::predictedExponent(q, q - 1)) <
                             1e-9);
        }
        report.check("the earlier family took the curvature from the component that was "
                     "changing sign, which is the general formula at a tangential order "
                     "one below the degenerate one",
                     std::abs(TransversePrescription::predictedConflatedExponent(3) -
                              TransversePrescription::predictedExponent(3, 2)) < 1e-12);

        report.subsection("What that costs the conflated reading");
        report.check(std::format("  at the transverse order the conflated exponent is {:+.4f}, "
                                 "so the ratio grows towards the crossing",
                                 TransversePrescription::predictedConflatedExponent(1)),
                     TransversePrescription::predictedConflatedExponent(1) < 0.0);
        report.check("passing needs a degenerate order above two, which is not "
                     "transverse, so in that reading the two conditions really are "
                     "incompatible",
                     !TransversePrescription::conflatedAllowsBoth(8));
        report.check("this reproduces the three exponents the earlier family measured, "
                     "minus one half at first order and plus one half at third",
                     std::abs(TransversePrescription::predictedConflatedExponent(1) + 0.5) < 1e-12 &&
                         std::abs(TransversePrescription::predictedConflatedExponent(3) - 0.5) <
                             1e-12);

        report.subsection("The general prescription passes");
        report.check(std::format("  transverse and totally geodesic gives exponent {:+.4f}",
                                 TransversePrescription::predictedExponent(1, 1)),
                     TransversePrescription::satisfiesRateCondition(1, 1));
        report.check("so a configuration that is transverse, totally geodesic and meets "
                     "the rate condition exists, and the earlier obstruction was a "
                     "property of how that family was written rather than of signature "
                     "change",
                     TransversePrescription::generalAllowsBoth());
        report.check("the rate condition is met exactly when the tangential slope "
                     "vanishes at the crossing, so it does not add a requirement to the "
                     "totally geodesic condition but restates it as a rate",
                     TransversePrescription::satisfiesRateCondition(1, 1) &&
                         !TransversePrescription::satisfiesRateCondition(1, 0));

        report.subsection("The obstruction that does survive");
        report.check("a surface layer needs the extrinsic curvature nonvanishing at the "
                     "crossing, which is tangential order zero",
                     !TransversePrescription::isTotallyGeodesic(0));
        report.check("no order both carries a layer and meets the rate, at any "
                     "degenerate order, so the incompatibility is between the layer and "
                     "the rate and not between the two geometric conditions",
                     !TransversePrescription::anyOrderKeepsLayerAndRate(8));
        report.check("that is the strong against weak dichotomy the literature already "
                     "carries, reached from the side of a rate rather than from a "
                     "well defined curvature, so no new obstruction is claimed here",
                     !TransversePrescription::anyOrderKeepsLayerAndRate(8) &&
                         TransversePrescription::generalAllowsBoth());
    }

}
