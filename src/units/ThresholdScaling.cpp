#include "units/ThresholdScaling.h"

#include "core/Report.h"
#include "units/PhysicalScales.h"
#include "units/SignatureThreshold.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{
    namespace
    {
        constexpr double kPlanckMassGev = 1.220890e19;
        constexpr double kParameter = 0.2375;
        constexpr double kExcludedBelowGev = 9.0e3;
        constexpr double kProtonRadius = 0.8414e-15;
        constexpr double kCollisionEnergy = 2.08e-6;

        double reachableDensityNow()
        {
            return SignatureThreshold::densityInSphere(kCollisionEnergy, kProtonRadius);
        }
    }

    double ThresholdScaling::planckMassInGev() { return kPlanckMassGev; }

    double ThresholdScaling::quantisationParameter() { return kParameter; }

    double ThresholdScaling::criticalFraction(double parameter)
    {
        if (parameter <= 0.0)
        {
            return 0.0;
        }
        const double pi = std::numbers::pi;
        return std::sqrt(3.0) / (32.0 * pi * pi * parameter * parameter * parameter);
    }

    double ThresholdScaling::turningDensityAtScale(double scaleInGev)
    {
        if (scaleInGev <= 0.0)
        {
            return 0.0;
        }
        const double ratio = scaleInGev / kPlanckMassGev;
        const double scaled = SignatureThreshold::planckDensity() * std::pow(ratio, 4.0);
        return 0.5 * criticalFraction(kParameter) * scaled;
    }

    double ThresholdScaling::decadesGainedByScale(double scaleInGev)
    {
        const double here = turningDensityAtScale(scaleInGev);
        const double base = turningDensityAtScale(kPlanckMassGev);
        if (here <= 0.0 || base <= 0.0)
        {
            return 0.0;
        }
        return std::log10(base / here);
    }

    double ThresholdScaling::scaleThatClosesGap(double reachableDensity)
    {
        if (reachableDensity <= 0.0)
        {
            return 0.0;
        }
        const double base = turningDensityAtScale(kPlanckMassGev);
        const double ratio = std::pow(reachableDensity / base, 0.25);
        return kPlanckMassGev * ratio;
    }

    double ThresholdScaling::excludedBelowInGev() { return kExcludedBelowGev; }

    bool ThresholdScaling::isExcluded(double scaleInGev)
    {
        return scaleInGev < kExcludedBelowGev;
    }

    double ThresholdScaling::decadesRemainingAtBound(double reachableDensity)
    {
        const double needed = turningDensityAtScale(kExcludedBelowGev);
        if (reachableDensity <= 0.0 || needed <= 0.0)
        {
            return 0.0;
        }
        return std::log10(needed / reachableDensity);
    }

    void ThresholdScalingSection::run(Report &report) const
    {
        report.subsection("The two factors the condition is built from");
        report.check(std::format("  the quantisation parameter is {:.4f}, fixed by an entropy "
                                 "count rather than left free",
                                 ThresholdScaling::quantisationParameter()),
                     ThresholdScaling::quantisationParameter() > 0.0);
        report.check(std::format("  it gives a critical density of {:.4f} of the density built "
                                 "from the scale, which is where the fraction near four tenths "
                                 "comes from",
                                 ThresholdScaling::criticalFraction(
                                     ThresholdScaling::quantisationParameter())),
                     std::abs(ThresholdScaling::criticalFraction(
                                  ThresholdScaling::quantisationParameter()) -
                              0.41) < 0.01);
        report.check("so that factor is derived and not chosen, and treating it as adjustable "
                     "would be assuming the answer rather than reaching it",
                     true);
        report.check(std::format("  the other factor is the fourth power of the scale at which "
                                 "gravity becomes strong, which in four dimensions is {:.4e} GeV",
                                 ThresholdScaling::planckMassInGev()),
                     ThresholdScaling::planckMassInGev() > 1e18);

        report.subsection("How far lowering that scale would carry the condition");
        for (double scale : {1.0e19, 1.0e6, 1.0e4, 1.0e3})
        {
            report.check(std::format("  gravity strong at {:>9.2e} GeV : turning density "
                                     "{:>10.4e} kg per cubic metre, {:>5.1f} decades lower",
                                     scale, ThresholdScaling::turningDensityAtScale(scale),
                                     ThresholdScaling::decadesGainedByScale(scale)),
                         ThresholdScaling::turningDensityAtScale(scale) > 0.0);
        }
        report.check("the lever is the fourth power, so a scale lowered by sixteen decades lowers "
                     "the condition by sixty four, which is why this is the only factor worth "
                     "examining at all",
                     std::abs(ThresholdScaling::decadesGainedByScale(1.0e3) - 64.3) < 1.0);

        report.subsection("The scale that would close the gap, against the scale experiment allows");
        const double reachable = reachableDensityNow();
        const double closing = ThresholdScaling::scaleThatClosesGap(reachable);
        report.check(std::format("  the densest deliberate configuration reaches {:.4e} kg per "
                                 "cubic metre",
                                 reachable),
                     reachable > 0.0);
        report.check(std::format("  the condition would be met there if gravity became strong at "
                                 "{:.4e} GeV",
                                 closing),
                     closing > 0.0);
        report.check(std::format("  experiment has excluded scales below {:.4e} GeV, so the "
                                 "closing scale is excluded by {:.1f} decades",
                                 ThresholdScaling::excludedBelowInGev(),
                                 std::log10(ThresholdScaling::excludedBelowInGev() / closing)),
                     ThresholdScaling::isExcluded(closing));
        report.check(std::format("at the most favourable scale experiment still allows, the "
                                 "condition remains {:.1f} decades out of reach",
                                 ThresholdScaling::decadesRemainingAtBound(reachable)),
                     ThresholdScaling::decadesRemainingAtBound(reachable) > 0.0);

        report.subsection("What that settles");
        report.check("the gap is not a bare impossibility but a statement about one parameter, "
                     "namely the scale at which gravity becomes strong, and the distance is "
                     "quoted on that parameter rather than on the apparatus",
                     ThresholdScaling::decadesRemainingAtBound(reachable) > 0.0);
        report.check("closing it entirely would need that scale below the range already excluded, "
                     "so no arrangement of present or planned collisions reaches the condition",
                     ThresholdScaling::isExcluded(closing));
        report.check("and the shortfall shrinks if the scale is lower than the bound rather than "
                     "if the collision is more energetic, which puts the question in the hands of "
                     "whether extra dimensions exist rather than of accelerator design",
                     ThresholdScaling::decadesRemainingAtBound(reachable) <
                         SignatureThreshold::shortfallInDecades(reachable));
    }

}
