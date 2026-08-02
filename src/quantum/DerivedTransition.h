#pragma once

#include "core/Section.h"

namespace slm
{

    /// Signature change as a derived consequence rather than a posited one.
    ///
    /// In this model the transition is put in by hand at the speed of light and
    /// is abrupt. Effective loop quantum cosmology gives a transition that is
    /// derived instead: holonomy corrections deform the constraint algebra by a
    /// factor that changes sign with density, so the signature follows from the
    /// dynamics and the transition sits at a definite density rather than at a
    /// definite speed.
    ///
    /// The deformation used here is the standard one,
    /// Omega(rho) = 1 - 2 rho / rho_c, quoted from that literature and analysed,
    /// not derived again.
    class DerivedTransition
    {
    public:
        /// Deformation factor of the effective constraint algebra.
        /// \param density Matter density.
        /// \param criticalDensity Density at which the bounce occurs.
        static double deformation(double density, double criticalDensity);

        /// True while the deformation is positive, which is the Lorentzian
        /// regime.
        static bool isLorentzian(double density, double criticalDensity);

        /// Density at which the deformation vanishes and the signature turns
        /// over, which is half the critical density.
        static double transitionDensity(double criticalDensity);

        /// Slope of the deformation in the density, showing that the change is
        /// gradual rather than abrupt.
        static double deformationSlope(double criticalDensity);

        /// Number of coordinates whose causal character changes at the
        /// transition, one for the Lorentzian to Euclidean case handled by that
        /// literature, four for the transition assumed in this model.
        static int changingCoordinates(bool euclideanTarget);
    };

    /// Section comparing the posited transition of this model with the derived
    /// one.
    class DerivedTransitionSection : public Section
    {
    public:
        std::string number() const override { return "10.10"; }
        std::string title() const override
        {
            return "A derived transition compared with the one assumed here";
        }
        void run(Report &report) const override;
    };

}
