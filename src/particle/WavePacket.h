#pragma once

#include "core/Section.h"

namespace slm
{

    /// The two-layer definition of the massive particle.
    ///
    /// The model computes with a wave packet, a narrow bundle of modes of the
    /// massive field, and speaks in the language of a point body. The two are
    /// not interchangeable, and the threshold is where they come apart: since
    /// transmission depends on the mode, the slab reweights the packet, and the
    /// body that leaves is not built from the same modes as the body that
    /// arrived.
    ///
    /// This class makes that statement quantitative. It carries a Gaussian
    /// packet in the transverse wavenumber, pushes it through the slab of
    /// section 9.4, and compares the outgoing distribution with the incoming
    /// one. The point-body reading survives exactly when the centroid shift and
    /// the change of spread are small against the spread itself.
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
        std::string number() const override { return "11"; }
        std::string title() const override
        {
            return "What the particle is: wave packet computed, point body spoken";
        }
        void run(Report &report) const override;
    };

}
