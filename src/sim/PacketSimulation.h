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
    /// a single route cannot check itself. This class builds a packet with
    /// WavePacketField and looks for the moment at which the transmitted
    /// packet is largest, and calls that the arrival.
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

        /// Time at which the returned packet peaks with no far-side
        /// displacement, obtained by searching the time axis directly. This is
        /// the only peak that has to be searched for.
        static double peakAtRest(IntermediateRegion::Kind kind, double c, double mu,
                                 double transverseSquared, double thickness, double centre,
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

        /// Moment at which the returned packet peaks, measured from the moment
        /// it set out. Negative means the simulation found the particle back
        /// before it left.
        ///
        /// Obtained from the rigid shift rather than by searching again at every
        /// distance: the peak at rest plus the signed displacement, exactly.
        /// Searching the whole time axis per distance, and bisecting over
        /// distances on top of that, costs minutes and buys nothing, since the
        /// identity above gives the answer in closed form from a single search.
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
        /// it by two again is a factor-of-two error, and the check is written
        /// this way to keep that mistake from being made twice.
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
