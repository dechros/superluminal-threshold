#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <array>

namespace slm
{

    /// The return event written as a formula in the far-side state, rather than
    /// obtained by scanning.
    ///
    /// Everything the crossing does is already computable state by state, but a
    /// scan is not an answer to the question "where does it come back". A scan
    /// says where these particular states came back. A formula says what the
    /// map is. This class writes it.
    ///
    /// The far-side state is an energy vector in the three far-side times
    /// together with a branch, the sign along the single far-side space axis.
    /// Two identities make the formula short, and both are exact rather than
    /// approximations:
    ///
    /// The outside wavenumber is the FIRST COMPONENT of the energy vector. The
    /// mass shell fixes the frequency from the length, the transverse
    /// wavenumber is the length of the other two components, and the difference
    /// leaves the first component alone. So the quantity that decides how the
    /// mode meets the surface is not some function of the orientation: it is
    /// one of its coordinates.
    ///
    /// The interior decay constant is built from the same three components with
    /// the turned directions as the only other input. Whether the crossing is a
    /// barrier or a passage is then a plain inequality between the components.
    ///
    /// With those, the elapsed time in the barrier regime has a closed form
    /// with no thickness in it at all, which is the saturation stated as an
    /// identity rather than observed in a table. The remaining coordinates
    /// follow: the crossing displacement sees only the branch, and the two
    /// transverse displacements are the transverse components of the
    /// orientation scaled by one common factor.
    class ReturnFormula
    {
    public:
        using Three = std::array<double, 3>;

        /// Length of the energy vector, which the mass shell ties to the
        /// frequency.
        static double length(const Three &energy);

        /// Frequency the mass shell assigns to that length.
        static double frequency(const Three &energy, double c, double mu);

        /// Squared transverse wavenumber, the length of the last two
        /// components.
        static double transverseSquared(const Three &energy);

        /// Outside normal wavenumber, which is the magnitude of the first
        /// component and nothing else.
        static double outsideWavenumber(const Three &energy);

        /// Interior decay constant, real when the crossing is a barrier.
        static double interiorDecay(const Three &energy, IntermediateRegion::Kind kind);

        /// Whether the state meets the surface as a barrier, which is an
        /// inequality between the components alone.
        static bool isBarrier(const Three &energy, IntermediateRegion::Kind kind);

        /// Elapsed time in the barrier regime, in closed form. No thickness
        /// appears, which is the saturation as an identity.
        static double saturatedElapsed(const Three &energy, IntermediateRegion::Kind kind, double c,
                                       double mu);

        /// Elapsed time at finite thickness, which carries the saturating
        /// factor explicitly and reduces to the above as the thickness grows.
        static double elapsedAtThickness(const Three &energy, IntermediateRegion::Kind kind,
                                         double c, double mu, double thickness);

        /// Crossing displacement, which sees the branch and nothing else.
        static double crossingDisplacement(int branch, double thickness);

        /// Common factor multiplying both transverse displacements.
        static double transverseFactor(double thickness, double c, double mu);

        /// The two transverse displacements of the return event.
        static std::array<double, 2> transverseDisplacement(const Three &energy, double thickness,
                                                            double c, double mu);

        /// Whether the closed form for the elapsed time agrees with the
        /// scattering calculation to the given tolerance.
        static bool agreesWithScattering(const Three &energy, IntermediateRegion::Kind kind,
                                         double c, double mu, double thickness, double tolerance);
    };

    /// Section stating the formula and checking it against the calculation it
    /// replaces.
    class ReturnFormulaSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The return event in closed form, and its agreement with the scan";
        }
        void run(Report &report) const override;
    };

}
