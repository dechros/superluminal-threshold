#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm

{

    /// The round trip run as a numerical experiment rather than read off a
    /// formula.
    ///
    /// Everything else in these libraries computes the arrival moment from the
    /// phase: the delay is a frequency derivative, and the closed form is that
    /// derivative evaluated. That is exact, but it is also a single route, and
    /// a single route cannot check itself. This class takes the other route. It
    /// builds a wave packet as a sum over frequencies, multiplies each
    /// frequency by the amplitude the region imposes on it, and propagates the
    /// result forward in time on the far side of the region. Then it looks for
    /// the moment at which the transmitted packet is largest, and calls that
    /// the arrival.
    ///
    /// No delay formula is used anywhere in that procedure. The stationary
    /// phase condition is not imposed; it is allowed to emerge or to fail. If
    /// the peak of the simulated packet lands where the derivative of the phase
    /// says it should, the two routes agree and the delay is not an artefact of
    /// differentiating a phase. If it lands somewhere else, the closed form is
    /// describing something other than where the particle is found, and that
    /// would be the more important result.
    ///
    /// Running it settles the question and also finds something the phase
    /// route hides. The transmission MODULUS rises steeply with frequency in
    /// the opaque regime, so the region does not merely delay the packet, it
    /// REWEIGHTS it towards its high-frequency side. The peak that a detector
    /// sees is therefore displaced by two separate effects: the phase, which
    /// is the delay the closed form computes, and the reweighting, which the
    /// closed form knows nothing about. Both are measured here, separately,
    /// because reporting only their sum would misattribute one to the other.
    ///
    /// Three limitations are structural and are checked rather than hidden.
    /// The packet has finite width, so the peak is located to a resolution set
    /// by the time step and the bandwidth. The sum over frequencies is
    /// truncated, and is refined until the answer stops moving. And the
    /// spectrum must not reach below the frequency at which the outside
    /// wavenumber turns imaginary, since those components do not propagate to
    /// the detector at all; the band is clipped there rather than allowed to
    /// contribute nonsense.
    class PacketSimulation
    {
    public:
        /// Gaussian weight the incoming packet gives a frequency.
        static double spectrum(double omega, double centre, double spread);

        /// Real part of the transmitted packet at a point past the region, at a
        /// given time, obtained by summing the transmitted amplitude over
        /// frequencies. The sum is the whole of the method: each frequency is
        /// multiplied by the amplitude the two crossings impose on it, and by
        /// the free propagation phase to the observation point.
        static double transmittedField(double time, double observationPoint,
                                       IntermediateRegion::Kind kind, double c, double mu,
                                       double transverseSquared, double thickness, double centre,
                                       double spread, int samples);

        /// Lowest frequency that propagates outside, below which a component
        /// never reaches the detector and must be excluded from the band.
        static double lowestPropagatingFrequency(double c, double mu, double transverseSquared);

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

        /// Time at which the transmitted envelope peaks, found by scanning and
        /// then refining. This is the measured arrival and it is the point of
        /// the class.
        static double measuredArrival(double observationPoint, IntermediateRegion::Kind kind,
                                      double c, double mu, double transverseSquared,
                                      double thickness, double centre, double spread,
                                      int samples, bool phaseOnly);

        /// Time at which a free packet peaks at the same point.
        static double measuredFreeArrival(double observationPoint, double c, double mu,
                                          double transverseSquared, double centre, double spread,
                                          int samples);

        /// Delay the simulation measures, which is the difference of the two
        /// arrivals above and which uses no delay formula.
        static double measuredDelay(double observationPoint, IntermediateRegion::Kind kind,
                                    double c, double mu, double transverseSquared,
                                    double thickness, double centre, double spread, int samples,
                                    bool phaseOnly);

        /// Displacement of the peak caused by the reweighting alone, which is
        /// the difference between the full measurement and the phase-only one.
        static double reweightingShift(double observationPoint, IntermediateRegion::Kind kind,
                                       double c, double mu, double transverseSquared,
                                       double thickness, double centre, double spread,
                                       int samples);

        /// Delay the closed form predicts, for comparison only. This is the
        /// only place a formula enters, and it enters as the thing being
        /// tested.
        static double predictedDelay(IntermediateRegion::Kind kind, double c, double mu,
                                     double transverseSquared, double thickness, double centre);

        /// Whether the measured and predicted delays agree to the given
        /// relative tolerance.
        static bool routesAgree(double observationPoint, IntermediateRegion::Kind kind, double c,
                                double mu, double transverseSquared, double thickness,
                                double centre, double spread, int samples, double tolerance);

        /// Whether the measured delay stops moving as the frequency sum is
        /// refined, which is what makes the number a result rather than a
        /// property of the truncation.
        static bool measurementConverges(double observationPoint, IntermediateRegion::Kind kind,
                                         double c, double mu, double transverseSquared,
                                         double thickness, double centre, double spread,
                                         double tolerance);

        /// Whether the measured delay stops growing with thickness, which is
        /// saturation observed rather than derived. This is the one qualitative
        /// claim of the whole work that a simulation can confirm or destroy.
        static bool saturationIsObserved(double observationPoint, IntermediateRegion::Kind kind,
                                         double c, double mu, double transverseSquared,
                                         double centre, double spread, int samples,
                                         double tolerance);
    };

    /// Section running the round trip numerically and comparing it against the
    /// formula it is meant to test.
    class PacketSimulationSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The crossing run as a numerical experiment, against the formula";
        }
        void run(Report &report) const override;
    };

}
