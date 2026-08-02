#pragma once

#include "core/Section.h"

namespace slm
{

    /// Gaussian wave packet carried through a slab of mode-dependent
    /// transmission.
    ///
    /// The packet is Gaussian in the transverse wavenumber. Because
    /// transmission depends on the mode, the slab reweights it, so the outgoing
    /// packet is not built from the same modes as the incoming one. These
    /// functions compare the two distributions: transmitted weight, shift of
    /// the centroid, and change of spread.
    ///
    /// Describing such a packet as a point body is exact only in the narrow
    /// limit, where the centroid shift and the change of spread are small
    /// against the spread itself. The weight supplied is an amplitude, so the
    /// density is its square and the density spread is the amplitude spread
    /// divided by the square root of two.
    class WavePacket
    {
    public:
        /// Gaussian weight of the mode at wavenumber k.
        static double weight(double k, double centre, double spread);

        /// Total probability of the incoming packet, the normalisation.
        static double incomingNorm(double centre, double spread);

        /// Fraction of the packet that gets through the slab.
        static double transmittedFraction(double centre, double spread, double thickness,
                                          double c, double mu, double flipped);

        /// Mean wavenumber of the packet before the crossing.
        static double incomingMean(double centre, double spread);

        /// Mean wavenumber of the part that got through, which is displaced
        /// because the slab prefers some modes to others.
        static double transmittedMean(double centre, double spread, double thickness, double c,
                                      double mu, double flipped);

        /// Standard deviation of the packet before the crossing.
        static double incomingSpread(double centre, double spread);

        /// Standard deviation of the part that got through.
        static double transmittedSpread(double centre, double spread, double thickness, double c,
                                        double mu, double flipped);

        /// Centroid displacement in units of the incoming spread. Small means
        /// the point-body reading survives the crossing.
        static double centroidShiftInSpreads(double centre, double spread, double thickness,
                                             double c, double mu, double flipped);

        /// Relative change of the spread, positive when the packet widens.
        static double spreadChange(double centre, double spread, double thickness, double c,
                                   double mu, double flipped);
    };

    /// Section defining the particle and testing when the point-body layer holds.
    class WavePacketSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What the particle is: wave packet computed, point body spoken";
        }
        void run(Report &report) const override;
    };

}
