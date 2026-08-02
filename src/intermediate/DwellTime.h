#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <complex>

namespace slm
{

    /// The stored-field reading of a delay, computed independently of the
    /// transmission phase so that the two can be compared.
    ///
    /// A phase delay read off the derivative of arg(t) with respect to
    /// frequency is often taken as a time of flight. There is a competing
    /// reading on which it is instead a dwell time: the lifetime of the
    /// probability stored inside the region, obtained as the stored norm
    /// divided by the incident flux, and describing how long the field lingers
    /// before leaking out of both faces rather than how long anything took to
    /// cross.
    ///
    /// The two readings are not distinguished by inspection, since both are
    /// derived from the same scattering solution. They are distinguished by
    /// computing the stored norm directly from the interior field and checking
    /// whether it reproduces the phase delay. Where it does, the delay carries
    /// no transit interpretation and any saturation of it with thickness is a
    /// property of the stored field. Where it does not, the two are separate
    /// observables and the transit reading survives that test.
    ///
    /// The interior field is the two-interface solution, so the same complex
    /// wavenumber serves the propagating and the evanescent case.
    class DwellTime
    {
    public:
        /// Interior wavenumber, real when the mode propagates and imaginary
        /// when it decays.
        static std::complex<double> interiorWavenumber(IntermediateRegion::Kind kind, double omega,
                                                       double c, double mu,
                                                       double transverseSquared);

        /// Amplitude of the interior wave running away from the entry face,
        /// relative to a unit incident amplitude.
        static std::complex<double> interiorForward(IntermediateRegion::Kind kind, double omega,
                                                    double c, double mu, double transverseSquared,
                                                    double thickness);

        /// Amplitude of the interior wave running back towards it.
        static std::complex<double> interiorBackward(IntermediateRegion::Kind kind, double omega,
                                                     double c, double mu, double transverseSquared,
                                                     double thickness);

        /// Probability stored inside the region, the integral of the squared
        /// interior field across the thickness.
        static double storedNorm(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                 double transverseSquared, double thickness, int samples = 20000);

        /// Incident flux, which is the group velocity outside times a unit
        /// density.
        static double incidentFlux(double omega, double c, double mu, double transverseSquared);

        /// Dwell time, the stored norm over the incident flux.
        static double dwellTime(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                double transverseSquared, double thickness);

        /// Phase delay of the same configuration, for comparison.
        static double phaseDelay(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                 double transverseSquared, double thickness);

        /// Relative difference between the two, zero when the phase delay is
        /// nothing but the dwell time.
        static double relativeGap(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                  double transverseSquared, double thickness);

        /// Whether the stored norm saturates with thickness, which is the
        /// stored-field explanation of a saturating delay.
        static bool storedNormSaturates(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared);
    };

    /// Section comparing the stored-field reading of the delay with the phase.
    class DwellTimeSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Is the delay a transit time or the lifetime of a stored field";
        }
        void run(Report &report) const override;
    };

}
