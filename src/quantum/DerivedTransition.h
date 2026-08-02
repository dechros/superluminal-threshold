#pragma once

#include "core/Section.h"

namespace slm
{

    /// Signature change as a derived consequence rather than a posited one.
    ///
    /// A transition can be posited, abrupt and at a fixed speed, or derived
    /// from dynamics. Effective loop quantum cosmology gives the derived case:
    /// holonomy corrections deform the constraint algebra by a factor that
    /// changes sign with density, so the signature follows from the dynamics
    /// and the transition sits at a definite density.
    ///
    /// The deformation implemented is the standard Omega(rho) = 1 - 2 rho /
    /// rho_c. It is analysed here, not derived.
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
        /// transition: one for a Lorentzian to Euclidean change, four when
        /// every coordinate changes character.
        static int changingCoordinates(bool euclideanTarget);
    };

    /// Section comparing a posited transition with a derived one.
    class DerivedTransitionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A derived transition compared with the one assumed here";
        }
        void run(Report &report) const override;
    };

}
