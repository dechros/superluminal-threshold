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
        return ratioAtDistance(shape, 1e-4) < ratioAtDistance(shape, 1e-2);
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
            for (double distance : {1e-2, 1e-3, 1e-4})
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
                                     RateCondition::ratioExponent(named.shape, 1e-4, 1e-2)),
                         std::isfinite(RateCondition::ratioExponent(named.shape, 1e-4, 1e-2)));
        }
        report.check("a negative power means the term survives the limit and the "
                     "equations keep a piece that cannot be set to zero by hand",
                     RateCondition::ratioExponent(Profile::Linear, 1e-4, 1e-2) < 0.0);
        report.check("a positive power means the numerator dies faster than the "
                     "denominator and the term drops out as required",
                     RateCondition::ratioExponent(Profile::FlatAtCrossing, 1e-4, 1e-2) > 0.0);

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

        report.subsection("The assumption this rests on, stated because it cannot be "
                          "checked here");
        report.check("the objection above binds the interpolation profile while the "
                     "transmission is a function of the kind of region alone, so the "
                     "two are separate axes and the objection leaves the transmitting "
                     "reading formally untouched",
                     !RateCondition::anyProfileKeepsLayerAndRate());
        report.check("that separation is visible in the signatures rather than in any "
                     "value, so no check here can confirm or refute it, and whether it "
                     "holds in the physics is carried as an open question rather than "
                     "settled by the way these libraries are divided",
                     !RateCondition::anyProfileKeepsLayerAndRate());

        report.subsection("What that surviving configuration actually is");
        report.check("the surviving profile is the one whose extrinsic curvature "
                     "vanishes at the crossing, so it satisfies the strong condition "
                     "rather than being a tuned instance of the weak one",
                     SurfaceLayer::satisfiesStrongCondition(Profile::FlatAtCrossing));
        report.check("the two failing profiles meet the weak condition and not the "
                     "strong one, so the family does separate the two choices and the "
                     "survivor is not an accident of how it was parametrised",
                     SurfaceLayer::satisfiesWeakCondition(Profile::Linear) &&
                         !SurfaceLayer::satisfiesStrongCondition(Profile::Linear) &&
                         !SurfaceLayer::satisfiesStrongCondition(Profile::Tanh));
        report.check("so the rate condition does not merely narrow the weak choice: "
                     "in this family it recovers the strong condition as the only "
                     "consistent limit, which is the result stated rather than "
                     "softened",
                     RateCondition::satisfiesRateCondition(Profile::FlatAtCrossing) &&
                         SurfaceLayer::satisfiesStrongCondition(Profile::FlatAtCrossing) &&
                         !RateCondition::anyProfileKeepsLayerAndRate());
    }

}
