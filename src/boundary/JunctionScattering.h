#pragma once

#include "core/Section.h"

#include <complex>

namespace slm
{

    /// Scattering of a single mode off the threshold surface, worked out
    /// separately for each junction condition on offer.
    ///
    /// The normal coordinate is written xi, with region I at xi < 0 and region
    /// II at xi > 0. Region I carries an incident and a reflected amplitude,
    /// region II carries two amplitudes because it supplies no radiation
    /// condition of its own. All amplitudes are relative to a unit incident
    /// wave, so the incident amplitude never appears as a parameter.
    class JunctionScattering : public Section
    {
    public:
        /// Which continuity requirement is imposed on the conjugate momentum
        /// at the surface.
        enum class Matching
        {
            Strong, ///< pi_II = -pi_I, the normal changes causal type
            Weak    ///< pi_II = +pi_I, the momentum simply carries over
        };

        /// Wavenumber along the normal direction. The reduced equation is the
        /// same on both sides, so one value serves for both regions.
        /// \param c Speed of light.
        /// \param mu Mass parameter.
        /// \param transverseSquared Squared wavenumber along the three
        ///        directions tangent to the surface.
        static double normalWavenumber(double c, double mu, double transverseSquared);

        /// Region II amplitude running away from the surface, given a
        /// reflection amplitude.
        static std::complex<double> transmittedAway(Matching matching,
                                                    std::complex<double> reflection);

        /// Region II amplitude running towards the surface.
        static std::complex<double> transmittedTowards(Matching matching,
                                                       std::complex<double> reflection);

        /// Net flux carried in region I, in units of the incident flux.
        static double fluxRegionI(std::complex<double> reflection);

        /// Net flux carried in region II, same units.
        static double fluxRegionII(Matching matching, std::complex<double> reflection);

        /// Mismatch between the two fluxes. A configuration is admissible only
        /// where this vanishes.
        static double fluxMismatch(Matching matching, std::complex<double> reflection);

        /// Whether an outgoing-only solution in region II exists, that is
        /// whether the junction conditions can be met with no wave running
        /// back towards the surface.
        static bool outgoingOnlySolutionExists(Matching matching);

        /// Reflection amplitude of the outgoing-only solution, defined only
        /// when the previous predicate is true.
        static std::complex<double> outgoingOnlyReflection(Matching matching);

        std::string number() const override { return "4.1"; }
        std::string title() const override
        {
            return "Scattering at Sigma: what each junction condition predicts";
        }
        void run(Report &report) const override;
    };

}
