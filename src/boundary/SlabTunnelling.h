#pragma once

#include "core/Section.h"

namespace slm
{

    /// Transmission through a region of changed signature of finite thickness.
    ///
    /// An unbounded far side reflects totally. A slab of finite thickness is a
    /// different problem: the interior mode can be evanescent rather than
    /// propagating, and an evanescent interior does not forbid transmission, it
    /// suppresses it exponentially. Total reflection is the thick-slab limit of
    /// this calculation rather than a separate result.
    ///
    /// The geometry is region I, then a slab of the intermediate signature of
    /// thickness d, then region I again.
    class SlabTunnelling
    {
    public:
        /// Squared normal wavenumber outside the slab, always positive.
        static double outsideWavenumberSquared(double c, double mu, double transverseSquared);

        /// Squared normal wavenumber inside the slab. One transverse direction
        /// has changed causal character, so this can be negative, which is the
        /// evanescent case.
        /// \param flipped Squared wavenumber along the direction that flipped.
        static double insideWavenumberSquared(double c, double mu, double transverseSquared,
                                              double flipped);

        /// Whether the interior mode is evanescent.
        static bool isEvanescent(double c, double mu, double transverseSquared, double flipped);

        /// Transmission probability through a slab, given the squared
        /// wavenumbers on either side directly. This is the one home of the
        /// closed form; IntermediateRegion::transmission is the same formula
        /// reached through a region kind, and calls this rather than repeating
        /// the algebra.
        static double transmissionFromSquares(double outsideSquared, double insideSquared,
                                              double thickness);

        /// Transmission probability through the slab.
        /// \param thickness Slab thickness d.
        static double transmission(double c, double mu, double transverseSquared,
                                   double flipped, double thickness);

        /// Decay constant of the evanescent interior, the q in exp(-q d).
        static double decayConstant(double c, double mu, double transverseSquared, double flipped);
    };

    /// Section reconciling total reflection with tunnelling through a slab.
    class SlabTunnellingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A slab of finite thickness does let something through";
        }
        void run(Report &report) const override;
    };

}
