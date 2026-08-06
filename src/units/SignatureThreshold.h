#pragma once

#include "core/Section.h"

namespace slm
{

    /// The energy density at which spacetime itself is expected to change
    /// signature, and what reaching it would cost.
    ///
    /// Everything else in this work takes the far region as given and computes
    /// the journey through it. The question left open is what would produce
    /// such a region, and one branch of the literature answers it with a
    /// number rather than a hope. In the effective dynamics of loop quantum
    /// cosmology the hypersurface deformation algebra acquires a
    /// density-dependent factor, and that factor changes sign once the energy
    /// density passes half the critical density. Below the turn the mode
    /// equation is hyperbolic and the geometry is Lorentzian; above it the
    /// equation is elliptic and the geometry is Euclidean. That is the region
    /// this work needs, arrived at by a condition on a density.
    ///
    /// Stating the condition is the easy half. This class exists for the other
    /// half, which is what the condition costs, and the answer separates into
    /// two parts that are usually run together.
    ///
    /// The energy required is not large. Concentrated into the smallest volume
    /// the same theory admits, it is a few gigajoules, which is an ordinary
    /// laboratory quantity.
    ///
    /// The concentration required is the obstacle, and it is not close. The
    /// densest matter produced deliberately falls short by dozens of orders of
    /// magnitude, and the shortfall is reported here as a count of decades
    /// rather than as a qualitative remark, so that the size of the gap is on
    /// the record.
    class SignatureThreshold
    {
    public:
        static double gravitationalConstant();

        /// Planck density, the natural scale of the condition.
        static double planckDensity();

        /// Planck length and the volume built from it.
        static double planckLength();
        static double planckVolume();

        /// Planck mass.
        static double planckMass();

        /// Critical density of the effective dynamics, as a fraction of the
        /// Planck density.
        static double criticalDensityFraction();
        static double criticalDensity();

        /// Density above which the signature is expected to turn, which is half
        /// the critical density.
        static double turningDensity();

        /// Whether a given density reaches the turn.
        static bool reachesTurn(double densityKilogramsPerCubicMetre);

        /// Mass needed to bring the given volume to the turning density.
        static double massForVolume(double cubicMetres);

        /// Energy that mass corresponds to, in joules.
        static double energyForVolume(double cubicMetres);

        /// Density reached by depositing the given energy in the given volume.
        static double densityFromEnergy(double joules, double cubicMetres);

        /// How many orders of magnitude a given density falls short of the
        /// turn. Positive means short.
        static double shortfallInDecades(double densityKilogramsPerCubicMetre);

        /// Density reached in a collision depositing the given energy inside a
        /// sphere of the given radius, which is the form the accelerator
        /// numbers come in.
        static double densityInSphere(double joules, double radiusMetres);

        /// Density reached in the same collision when the overlap is taken as
        /// the Lorentz contracted pancake rather than a sphere at rest.
        ///
        /// THE VOLUME IS A CONVENTION, NOT A MEASUREMENT. A collision does not
        /// come with a well defined volume: the sphere at rest ignores that
        /// the projectiles are flattened, the contracted overlap takes the
        /// geometric extreme and credits energy that has not yet formed into
        /// matter, and a formation time puts a slab of about one femtometre
        /// between the two. The three answers to one question differ by
        /// several orders, so a density quoted for a collision carries its
        /// convention or it carries nothing.
        static double densityInContractedOverlap(double centreOfMassJoules,
                                                  double radiusMetres);

        /// The same collision read with a formation time instead, which is the
        /// convention the heavy ion literature reports.
        static double densityAtFormationTime(double centreOfMassJoules, double radiusMetres,
                                             double formationSeconds);

        /// How many orders separate the widest and the narrowest convention
        /// for one collision, which is the width the quoted figure hides.
        static double conventionSpreadInDecades(double centreOfMassJoules, double radiusMetres,
                                                double formationSeconds);
    };

    /// Section reporting the density condition and its cost.
    class SignatureThresholdSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The density at which the signature is expected to turn";
        }
        void run(Report &report) const override;
    };

}
