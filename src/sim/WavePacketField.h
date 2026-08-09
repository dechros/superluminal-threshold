#pragma once

#include "intermediate/IntermediateRegion.h"

#include <complex>
#include <vector>

namespace slm

{

    /// A wave packet built as a sum over frequencies and evaluated at a time.
    ///
    /// Every frequency in the sum is weighted by the incoming spectrum,
    /// multiplied by the amplitude the crossing imposes on it, and carried by
    /// the propagation phase appropriate to what is being observed: free
    /// travel to a point past the region, the round trip back to the point of
    /// departure, or a round trip displaced by a stated distance on the far
    /// side. Only one factor in each sum depends on the observation time, and
    /// it is the same complex exponential regardless of which of these is
    /// being built, so the frequency-dependent factors are held once as
    /// Harmonics and the time dependence is applied afterwards.
    ///
    /// The band is clipped below the frequency at which the outside
    /// wavenumber turns imaginary, since those components do not propagate to
    /// a detector at all and must not be allowed to contribute nonsense.
    class WavePacketField
    {
    public:
        /// Frequency side of a packet sum, evaluated once and reused at every
        /// time the envelope is asked for.
        struct Harmonics
        {
            std::vector<double> frequency;
            std::vector<std::complex<double>> coefficient;
        };

        /// Gaussian weight the incoming packet gives a frequency.
        static double spectrum(double omega, double centre, double spread);

        /// Lowest frequency that propagates outside, below which a component
        /// never reaches the detector and must be excluded from the band.
        static double lowestPropagatingFrequency(double c, double mu, double transverseSquared);

        /// Frequency side for a single crossing observed at a point.
        static Harmonics harmonics(double observationPoint, IntermediateRegion::Kind kind,
                                   double c, double mu, double transverseSquared,
                                   double thickness, double centre, double spread, int samples,
                                   bool phaseOnly);

        /// Frequency side for the round trip, observed where it started and so
        /// carrying no propagation phase.
        static Harmonics roundTripHarmonics(IntermediateRegion::Kind kind, double c, double mu,
                                            double transverseSquared, double thickness,
                                            double centre, double spread, int samples,
                                            bool phaseOnly);

        /// Envelope at the given time, from a frequency side already built.
        static double envelopeOf(const Harmonics &harmonics, double time);

        /// Real part of the transmitted packet at a point past the region, at
        /// a given time, obtained by summing the transmitted amplitude over
        /// frequencies.
        static double transmittedField(double time, double observationPoint,
                                       IntermediateRegion::Kind kind, double c, double mu,
                                       double transverseSquared, double thickness, double centre,
                                       double spread, int samples);

        /// Envelope of the transmitted packet, which is what a detector
        /// integrating over a cycle would register. When phaseOnly is set the
        /// transmitted amplitude is stripped of its modulus and kept only as a
        /// phase, which isolates the delay from the reweighting.
        static double transmittedEnvelope(double time, double observationPoint,
                                          IntermediateRegion::Kind kind, double c, double mu,
                                          double transverseSquared, double thickness,
                                          double centre, double spread, int samples,
                                          bool phaseOnly);

        /// The same for a packet that never met the region, which is the
        /// reference the delay is measured against.
        static double freeEnvelope(double time, double observationPoint, double c, double mu,
                                   double transverseSquared, double centre, double spread,
                                   int samples);

        /// Envelope of the packet after the whole round trip, back at the
        /// point it started from. The far-side displacement enters the phase
        /// as the dictionary says it must: the far-side coordinate is the
        /// near-side time slot, so travelling a distance there multiplies
        /// each frequency by exp(i omega s) rather than by a spatial phase.
        static double roundTripEnvelope(double time, IntermediateRegion::Kind kind, double c,
                                        double mu, double transverseSquared, double thickness,
                                        double farSideDistance, int branch, double centre,
                                        double spread, int samples, bool phaseOnly);
    };

}
