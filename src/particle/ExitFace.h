#pragma once

#include "core/Section.h"

#include <array>

namespace slm
{

    /// Which face the particle leaves by, and what fixes it.
    ///
    /// The conjecture this section tests is that the exit face is set by the
    /// particle's orientation in the far-side times: it orients itself in time
    /// over there, and coming back that same orientation reads as an
    /// orientation in space here, so which way it comes out may not be
    /// determined from our side at all.
    ///
    /// The calculation supports the conjecture and sharpens it into something
    /// less comfortable. Motion across the region is along the far side's one
    /// spatial direction, so the exit face is decided by the sign of the
    /// wavenumber along it. The mass shell fixes that wavenumber's magnitude
    /// and leaves its sign free, and the far side carries no time orientation
    /// with which to prefer one sign over the other. Meanwhile that same slot
    /// is our own energy under the crossing. So the question of which face the
    /// particle leaves by is the question of the sign of its energy here.
    class ExitFace
    {
        public:
        using Four = std::array<double, 4>;

        /// Squared wavenumber along the far side's spatial direction, fixed by
        /// the mass shell from the three time wavenumbers.
        static double crossingWavenumberSquared(double c, double mu, double k1, double k2,
                                                double k3);

        /// Residual of the far-side dispersion relation, which both signs of
        /// the crossing wavenumber satisfy equally.
        static double dispersionResidual(double c, double mu, double k1, double k2, double k3,
                                         double q);

        /// Whether the magnitude of the crossing wavenumber depends on the
        /// direction of the far-side energy vector rather than only its length.
        static bool crossingDependsOnOrientationDirection(double c, double mu, double length);

        /// Our energy after returning, given the sign of the crossing
        /// wavenumber the particle carried.
        static double ourEnergyFromBranch(double crossingWavenumber);

        /// Whether the far side supplies anything that selects a branch. It
        /// does not, and the reason is that a branch is selected by an
        /// outgoing-wave condition, which needs a time orientation.
        static bool farSideSelectsBranch();
    };

    /// Section testing the conjecture about the exit face.
    class ExitFaceSection : public Section
    {
    public:
        std::string number() const override { return "18.6"; }
        std::string title() const override
        {
            return "Which face it leaves by, and why the far side cannot say";
        }
        void run(Report &report) const override;
    };

}
