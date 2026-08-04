#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <complex>
#include <vector>

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
        /// The frequency side of the sum, evaluated once.
        ///
        /// Only one factor in the sum depends on the observation time, and it is
        /// exp(-i omega t). Everything else, the spectral weight, the crossing
        /// amplitude and the propagation phase, depends on the frequency alone.
        /// A peak search asks for the envelope at thousands of times, and
        /// rebuilding those factors at each of them was where the running time
        /// went: the search cost three thousand amplitude evaluations per time
        /// step, and the whole simulation took two minutes out of a run that
        /// takes under two seconds without it.
        ///
        /// Held this way the search reduces to multiplying stored coefficients
        /// by a phase. No result changes, because nothing is approximated; the
        /// same terms are summed in the same order.
        struct Harmonics
        {
            std::vector<double> frequency;
            std::vector<std::complex<double>> coefficient;
        };

        /// Build the frequency side for a single crossing observed at a point.
        static Harmonics harmonics(double observationPoint, IntermediateRegion::Kind kind,
                                   double c, double mu, double transverseSquared,
                                   double thickness, double centre, double spread, int samples,
                                   bool phaseOnly);

        /// Build the frequency side for the round trip, which is observed where
        /// it started and so carries no propagation phase.
        static Harmonics roundTripHarmonics(IntermediateRegion::Kind kind, double c, double mu,
                                            double transverseSquared, double thickness,
                                            double centre, double spread, int samples,
                                            bool phaseOnly);

        /// Envelope at the given time, from a frequency side already built.
        static double envelopeOf(const Harmonics &harmonics, double time);

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

        /// Envelope of the packet after the WHOLE round trip, back at the point
        /// it started from. Two crossings and a far-side displacement, with the
        /// displacement entering the phase as the dictionary says it must: the
        /// far-side coordinate is the near-side time slot, so travelling a distance there
        /// multiplies each frequency by exp(i omega s) rather than by a spatial
        /// phase. Nothing else in the sum knows about that; it is the crossing
        /// dictionary applied once, and the peak is then found the same way as
        /// everywhere else.
        static double roundTripEnvelope(double time, IntermediateRegion::Kind kind, double c,
                                        double mu, double transverseSquared, double thickness,
                                        double farSideDistance, int branch, double centre,
                                        double spread, int samples, bool phaseOnly);

        /// Whether the far-side displacement moves the envelope rigidly.
        ///
        /// It has to, and the reason is one line of algebra rather than a
        /// numerical accident. The displacement enters as exp(i sign omega s)
        /// and the observation as exp(-i omega t), and those two multiply to
        /// exp(-i omega (t - sign s)). Every frequency in the sum therefore sees
        /// the same combination, so the envelope is a function of that
        /// combination alone and the whole shape translates without deforming.
        ///
        /// This is checked and not assumed, by evaluating the envelope at a
        /// displaced time and at the shifted argument with no displacement and
        /// requiring them equal.
        static bool shiftIsRigid(IntermediateRegion::Kind kind, double c, double mu,
                                 double transverseSquared, double thickness,
                                 double farSideDistance, int branch, double centre,
                                 double spread, int samples, double tolerance = 1e-12);

        /// Moment at which the packet peaks with no far-side displacement. This
        /// is the only peak that has to be searched for.
        static double peakAtRest(IntermediateRegion::Kind kind, double c, double mu,
                                 double transverseSquared, double thickness, double centre,
                                 double spread, int samples, bool phaseOnly);

        /// Moment at which the returned packet peaks, measured from the moment
        /// it set out. Negative means the simulation found the particle back
        /// before it left.
        ///
        /// Obtained from the rigid shift rather than by searching again at every
        /// distance: the peak at rest plus the signed displacement, exactly. The
        /// earlier version searched the whole time axis for each distance and
        /// then bisected over distances on top of that, which cost minutes and
        /// bought nothing, since the identity above makes the answer available
        /// in closed form from a single search.
        static double measuredReturnMoment(IntermediateRegion::Kind kind, double c, double mu,
                                           double transverseSquared, double thickness,
                                           double farSideDistance, int branch, double centre,
                                           double spread, int samples, bool phaseOnly);

        /// The same moment obtained by searching the time axis directly at the
        /// given displacement, kept so the fast route can be compared against a
        /// route that knows nothing about the identity.
        static double searchedReturnMoment(IntermediateRegion::Kind kind, double c, double mu,
                                           double transverseSquared, double thickness,
                                           double farSideDistance, int branch, double centre,
                                           double spread, int samples, bool phaseOnly);

        /// Whether the simulated round trip returns before it departed.
        static bool returnsBeforeDeparture(IntermediateRegion::Kind kind, double c, double mu,
                                           double transverseSquared, double thickness,
                                           double farSideDistance, int branch, double centre,
                                           double spread, int samples);

        /// Far-side distance at which the simulated return lands exactly on the
        /// departure. This is the threshold as an experiment sees it, and it
        /// still comes out of the simulation rather than out of a formula: the
        /// rigid shift makes it the peak measured at rest, since the moment
        /// vanishes exactly when the signed displacement cancels that peak. The
        /// bisection it replaces returned the same number twenty times slower.
        static double measuredThreshold(IntermediateRegion::Kind kind, double c, double mu,
                                        double transverseSquared, double thickness, int branch,
                                        double centre, double spread, int samples);

        /// Whether that measured threshold agrees with the phase delay the
        /// closed form gives. Note that the amplitude already describes TWO
        /// crossings, so the delay it carries is the round trip's; multiplying
        /// it by two again is the factor-of-two error this work has made twice
        /// before, and the check is written this way to keep it made once.
        static bool thresholdAgreesWithFormula(IntermediateRegion::Kind kind, double c, double mu,
                                               double transverseSquared, double thickness,
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
