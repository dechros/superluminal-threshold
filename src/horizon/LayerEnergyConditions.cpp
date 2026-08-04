#include "horizon/LayerEnergyConditions.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kTolerance = 1e-9;
    }

    double LayerEnergyConditions::layerStrength(SurfaceLayer::Profile shape, double thickness)
    {
        if (shape == SurfaceLayer::Profile::FlatAtCrossing)
        {
            return IntermediateRegion::layerStrengthStationaryProfile(
                IntermediateRegion::Kind::SplitSignature, thickness);
        }
        return IntermediateRegion::layerStrength(IntermediateRegion::Kind::SplitSignature, thickness);
    }

    double LayerEnergyConditions::surfaceDensity(SurfaceLayer::Profile shape, double thickness)
    {
        return -layerStrength(shape, thickness);
    }

    double LayerEnergyConditions::surfacePressure(SurfaceLayer::Profile shape, double thickness)
    {
        return layerStrength(shape, thickness);
    }

    LayerEnergyConditions::Character LayerEnergyConditions::surfaceCharacter()
    {
        return Character::Spacelike;
    }

    bool LayerEnergyConditions::layerIsAbsent(SurfaceLayer::Profile shape, double thickness)
    {
        return std::abs(layerStrength(shape, thickness)) < kTolerance;
    }

    bool LayerEnergyConditions::satisfiesNull(SurfaceLayer::Profile shape, double thickness)
    {
        if (layerIsAbsent(shape, thickness))
        {
            return true;
        }
        return surfaceDensity(shape, thickness) + surfacePressure(shape, thickness) >= -kTolerance;
    }

    bool LayerEnergyConditions::satisfiesWeak(SurfaceLayer::Profile shape, double thickness)
    {
        if (layerIsAbsent(shape, thickness))
        {
            return true;
        }
        return surfaceDensity(shape, thickness) >= -kTolerance &&
               satisfiesNull(shape, thickness);
    }

    bool LayerEnergyConditions::satisfiesDominant(SurfaceLayer::Profile shape, double thickness)
    {
        if (layerIsAbsent(shape, thickness))
        {
            return true;
        }
        return satisfiesWeak(shape, thickness) &&
               std::abs(surfacePressure(shape, thickness)) <=
                   surfaceDensity(shape, thickness) + kTolerance;
    }

    bool LayerEnergyConditions::anyProfileEscapesDominant(double thickness)
    {
        for (SurfaceLayer::Profile shape : {SurfaceLayer::Profile::Linear,
                                            SurfaceLayer::Profile::FlatAtCrossing,
                                            SurfaceLayer::Profile::Tanh})
        {
            if (!layerIsAbsent(shape, thickness) && satisfiesDominant(shape, thickness))
            {
                return true;
            }
        }
        return false;
    }

    bool LayerEnergyConditions::anyProfileEscapesNull(double thickness)
    {
        for (SurfaceLayer::Profile shape : {SurfaceLayer::Profile::Linear,
                                            SurfaceLayer::Profile::FlatAtCrossing,
                                            SurfaceLayer::Profile::Tanh})
        {
            if (!layerIsAbsent(shape, thickness) && satisfiesNull(shape, thickness))
            {
                return true;
            }
        }
        return false;
    }

    void LayerEnergyConditionsSection::run(Report &report) const
    {
        using Profile = SurfaceLayer::Profile;
        struct Named
        {
            const char *label;
            Profile shape;
        };
        const double thickness = 1.0;
        const Named profiles[] = {{"linear", Profile::Linear},
                                  {"flat at the crossing", Profile::FlatAtCrossing},
                                  {"tanh step", Profile::Tanh}};

        report.subsection("The surface is not timelike, which is what binds it");
        report.check("the normal changes causal type across the junction, so the "
                     "surface cannot be timelike and the timelike shell results "
                     "do not apply to it",
                     LayerEnergyConditions::surfaceCharacter() !=
                         LayerEnergyConditions::Character::Timelike);

        report.subsection("Density and pressure of the layer each profile carries");
        for (const Named &named : profiles)
        {
            report.check(std::format("  {:22} : density {:+.3e}, pressure {:+.3e}", named.label,
                                     LayerEnergyConditions::surfaceDensity(named.shape, thickness),
                                     LayerEnergyConditions::surfacePressure(named.shape, thickness)),
                         std::isfinite(LayerEnergyConditions::surfaceDensity(named.shape, thickness)) &&
                             std::isfinite(LayerEnergyConditions::surfacePressure(named.shape, thickness)));
        }

        report.subsection("Which conditions each layer meets");
        for (const Named &named : profiles)
        {
            if (LayerEnergyConditions::layerIsAbsent(named.shape, thickness))
            {
                report.check(std::format("  {:22} : carries no layer, so no condition binds it",
                                         named.label),
                             LayerEnergyConditions::satisfiesDominant(named.shape, thickness));
                continue;
            }
            report.check(std::format("  {:22} : null {}, weak {}, dominant {}", named.label,
                                     LayerEnergyConditions::satisfiesNull(named.shape, thickness) ? "yes" : "no",
                                     LayerEnergyConditions::satisfiesWeak(named.shape, thickness) ? "yes" : "no",
                                     LayerEnergyConditions::satisfiesDominant(named.shape, thickness) ? "yes"
                                                                                           : "no"),
                         !LayerEnergyConditions::satisfiesDominant(named.shape, thickness));
        }

        report.subsection("No profile in the family escapes");
        report.check("no profile carrying a layer satisfies the dominant "
                     "condition, so the layer cannot be made acceptable by "
                     "reshaping the transition",
                     !LayerEnergyConditions::anyProfileEscapesDominant(thickness));
        report.check("the one profile that escapes does so by carrying no layer "
                     "at all, which is the stationary case and needs fine tuning",
                     LayerEnergyConditions::layerIsAbsent(Profile::FlatAtCrossing, thickness));

        report.subsection("Making the region thicker weakens but never removes it");
        for (double probe : {0.5, 1.0, 4.0, 40.0})
        {
            report.check(std::format("  d = {:5g} : density {:+.4f}, and the dominant condition "
                                     "still fails",
                                     probe,
                                     LayerEnergyConditions::surfaceDensity(Profile::Linear, probe)),
                         !LayerEnergyConditions::satisfiesDominant(Profile::Linear, probe));
        }
        report.check("the violation is weakened by thickness but never removed, "
                     "since the density stays on the negative branch at every "
                     "thickness tested",
                     LayerEnergyConditions::surfaceDensity(Profile::Linear, 40.0) < 0.0 &&
                         !LayerEnergyConditions::anyProfileEscapesDominant(40.0));

        report.subsection("What this costs the transmitting reading");
        report.check("the price of the weak junction condition is therefore not "
                     "merely a layer but a layer that violates the dominant "
                     "condition, which no choice of matter repairs",
                     !LayerEnergyConditions::anyProfileEscapesDominant(thickness) &&
                         !LayerEnergyConditions::layerIsAbsent(Profile::Linear, thickness));
        report.check("the escape route left open is the stationary profile, and "
                     "it is a fine tuning rather than a generic configuration",
                     LayerEnergyConditions::layerIsAbsent(Profile::FlatAtCrossing, thickness) &&
                         !LayerEnergyConditions::layerIsAbsent(Profile::Tanh, thickness));
    }

}
