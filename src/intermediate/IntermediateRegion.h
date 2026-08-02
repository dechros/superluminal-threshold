#pragma once

#include "core/Section.h"

#include <string>

namespace slm
{

    /// The region between our own and the far side, treated as an object in
    /// its own right rather than as a surface.
    ///
    /// Two independent questions decide what the crossing looks like. The first
    /// is what the intermediate region is made of, that is, which signature it
    /// carries. The second is how thick it is. Neither answers the other, so
    /// the model computes the whole grid: four kinds against five thicknesses.
    ///
    /// The kinds differ in how many of the transverse directions have changed
    /// causal character inside the region, which is what decides whether the
    /// normal mode there propagates or decays.
    class IntermediateRegion
    {
    public:
        enum class Kind
        {
            None,
            Kleinian,
            Euclidean,
            Degenerate
        };

        /// How many transverse directions have flipped inside this kind.
        static int flippedDirections(Kind kind);

        static std::string name(Kind kind);

        /// Squared normal wavenumber outside the region, always positive.
        static double outsideNormalSquared(double c, double mu, double transverseSquared);

        /// Squared normal wavenumber inside the region. Negative means the
        /// interior mode decays instead of propagating.
        static double insideNormalSquared(Kind kind, double c, double mu,
                                          double transverseSquared);

        /// Whether the interior blocks propagation.
        static bool blocks(Kind kind, double c, double mu, double transverseSquared);

        /// Transmission through a region of the given kind and thickness.
        static double transmission(Kind kind, double c, double mu, double transverseSquared,
                                   double thickness);

        /// Strength of the matter layer the junction carries, measured by the
        /// jump in the normal derivative of the metric component that turns
        /// over. Zero means no layer.
        static double layerStrength(Kind kind, double thickness);

        /// Layer strength for a transition profile that is stationary at the
        /// crossing, which is the only shape that can make it vanish.
        static double layerStrengthStationaryProfile(Kind kind, double thickness);
    };

    /// Section computing the crossing for every kind and thickness.
    class IntermediateRegionSection : public Section
    {
    public:
        std::string number() const override { return "2"; }
        std::string title() const override
        {
            return "The intermediate region: four kinds against five thicknesses";
        }
        void run(Report &report) const override;
    };

}
