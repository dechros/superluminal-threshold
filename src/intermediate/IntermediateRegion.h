#pragma once

#include "core/Section.h"

#include <string>

namespace slm
{

    /// The region between the near side and the far side, treated as an object in
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
            SplitSignature,
            Euclidean,
            Degenerate
        };

        /// How many transverse directions have flipped inside this kind.
        static int flippedDirections(Kind kind);

        static std::string name(Kind kind);

        /// Squared normal wavenumber outside the region, always positive.
        ///
        /// THIS FIXES A FREQUENCY. In general the outside wavenumber is
        /// omega squared over c squared, less the transverse part and the
        /// mass; here it is set to c squared times the transverse part plus
        /// the mass, which is the same thing only on the surface where omega
        /// squared equals twice c squared times that sum. Every quantity in
        /// this class therefore describes one frequency rather than a family,
        /// and the class is not the place to ask how a region behaves as the
        /// frequency moves: the crossing amplitude is, since it carries omega
        /// explicitly. The choice is checked against the general form below
        /// rather than left to be rediscovered.
        static double outsideNormalSquared(double c, double mu, double transverseSquared);

        /// Squared normal wavenumber inside the region. Negative means the
        /// interior mode decays instead of propagating. Carries the same
        /// fixed frequency as the outside value, and is the general
        /// expression evaluated there: each turned direction subtracts two
        /// thirds of the transverse part.
        static double insideNormalSquared(Kind kind, double c, double mu,
                                          double transverseSquared);

        /// The frequency the two wavenumbers above are evaluated at, so that
        /// the choice can be stated and tested instead of being implicit.
        static double fixedFrequency(double c, double mu, double transverseSquared);

        /// The inside wavenumber written the general way, from a frequency.
        /// Agrees with insideNormalSquared exactly at fixedFrequency, and
        /// departs from it everywhere else, which is what makes the choice
        /// visible.
        static double insideFromFrequency(int turned, double c, double mu,
                                          double transverseSquared, double frequency);

        /// Whether the interior blocks propagation.
        static bool blocks(Kind kind, double c, double mu, double transverseSquared);

        /// Fraction of the transverse squared wavenumber that a region with
        /// the given number of turned directions subtracts from the interior.
        /// Each turned direction is worth two thirds of one, and this is the
        /// one home of that weight: every library needing it calls here rather
        /// than writing the fraction again.
        static double turnedWeight(int turned);
    };

    /// Section computing the crossing for every kind and thickness.
    class IntermediateRegionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The intermediate region: four kinds against five thicknesses";
        }
        void run(Report &report) const override;
    };

}
