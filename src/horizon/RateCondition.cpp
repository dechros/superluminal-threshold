#include "horizon/RateCondition.h"

#include "core/Report.h"
#include "horizon/LayerEnergyConditions.h"

#include <cmath>
#include <format>

namespace slm
{

    double RateCondition::lapse(SurfaceLayer::Profile shape, double xi)
    {
        return std::sqrt(std::abs(std::cos(SurfaceLayer::profile(shape, xi))));
    }

    double RateCondition::normalDerivative(SurfaceLayer::Profile shape, double xi)
    {
        return SurfaceLayer::extrinsicCurvature(shape, xi);
    }

    double RateCondition::ratio(SurfaceLayer::Profile shape, double xi)
    {
        const double denominator = lapse(shape, xi);
        if (denominator <= 0.0)
        {
            return 0.0;
        }
        return std::abs(normalDerivative(shape, xi)) / denominator;
    }

    double RateCondition::ratioAtDistance(SurfaceLayer::Profile shape, double distance)
    {
        return ratio(shape, SurfaceLayer::crossing(shape) - distance);
    }

    double RateCondition::ratioExponent(SurfaceLayer::Profile shape, double nearDistance,
                                        double farDistance)
    {
        const double near = ratioAtDistance(shape, nearDistance);
        const double far = ratioAtDistance(shape, farDistance);
        if (near <= 0.0 || far <= 0.0 || nearDistance <= 0.0 || farDistance <= 0.0 ||
            nearDistance == farDistance)
        {
            return 0.0;
        }
        return std::log(near / far) / std::log(nearDistance / farDistance);
    }

    bool RateCondition::satisfiesRateCondition(SurfaceLayer::Profile shape)
    {
        return ratioAtDistance(shape, 1e-6) < ratioAtDistance(shape, 1e-3);
    }

    bool RateCondition::anyProfileKeepsLayerAndRate()
    {
        for (SurfaceLayer::Profile shape : {SurfaceLayer::Profile::Linear,
                                            SurfaceLayer::Profile::FlatAtCrossing,
                                            SurfaceLayer::Profile::Tanh})
        {
            if (satisfiesRateCondition(shape) &&
                !LayerEnergyConditions::layerIsAbsent(shape, 1.0))
            {
                return true;
            }
        }
        return false;
    }

    void RateConditionSection::run(Report &report) const
    {
        using Profile = SurfaceLayer::Profile;
        struct Named
        {
            const char *label;
            Profile shape;
        };
        const Named profiles[] = {{"linear", Profile::Linear},
                                  {"flat at the crossing", Profile::FlatAtCrossing},
                                  {"tanh step", Profile::Tanh}};

        report.subsection("The two rates, followed towards the crossing");
        for (const Named &named : profiles)
        {
            for (double distance : {1e-2, 1e-4, 1e-6})
            {
                const double xi = SurfaceLayer::crossing(named.shape) - distance;
                report.check(std::format("  {:22} at {:.0e} : lapse {:.4e}, normal derivative "
                                         "{:.4e}, ratio {:.4e}",
                                         named.label, distance,
                                         RateCondition::lapse(named.shape, xi),
                                         std::abs(RateCondition::normalDerivative(named.shape, xi)),
                                         RateCondition::ratioAtDistance(named.shape, distance)),
                             RateCondition::lapse(named.shape, xi) >= 0.0);
            }
        }

        report.subsection("The exponent that decides it");
        for (const Named &named : profiles)
        {
            report.check(std::format("  {:22} : the ratio goes as the distance to the power "
                                     "{:+.3f}",
                                     named.label,
                                     RateCondition::ratioExponent(named.shape, 1e-6, 1e-3)),
                         std::isfinite(RateCondition::ratioExponent(named.shape, 1e-6, 1e-3)));
        }
        report.check("a negative power means the term survives the limit and the "
                     "equations keep a piece that cannot be set to zero by hand",
                     RateCondition::ratioExponent(Profile::Linear, 1e-6, 1e-3) < 0.0);
        report.check("a positive power means the numerator dies faster than the "
                     "denominator and the term drops out as required",
                     RateCondition::ratioExponent(Profile::FlatAtCrossing, 1e-6, 1e-3) > 0.0);

        report.subsection("Which profiles pass");
        for (const Named &named : profiles)
        {
            report.check(std::format("  {:22} : {}", named.label,
                                     RateCondition::satisfiesRateCondition(named.shape)
                                         ? "passes"
                                         : "fails"),
                         RateCondition::satisfiesRateCondition(named.shape) ==
                             (named.shape == Profile::FlatAtCrossing));
        }
        report.check("the generic profiles fail, so the objection is not answered by "
                     "reshaping the transition any more than the energy conditions were",
                     !RateCondition::satisfiesRateCondition(Profile::Linear) &&
                         !RateCondition::satisfiesRateCondition(Profile::Tanh));

        report.subsection("The two objections meet on one profile");
        report.check("the only profile that passes the rate condition is the same "
                     "one that carries no layer, which the energy conditions had "
                     "already left as their single escape",
                     RateCondition::satisfiesRateCondition(Profile::FlatAtCrossing) &&
                         LayerEnergyConditions::layerIsAbsent(Profile::FlatAtCrossing, 1.0));
        report.check("no profile both keeps a layer and satisfies the rate, so the "
                     "weak choice has no generic representative left in this family",
                     !RateCondition::anyProfileKeepsLayerAndRate());
        report.check("two objections raised independently therefore converge on one "
                     "configuration, and that configuration is a fine tuning",
                     !LayerEnergyConditions::anyProfileEscapesDominant(1.0) &&
                         !RateCondition::anyProfileKeepsLayerAndRate());
    }

}
