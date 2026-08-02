#pragma once

#include "core/Section.h"

namespace slm
{

    /// Casimir energy between two threshold surfaces, and what it
    /// discriminates.
    ///
    /// Every self-adjoint condition at a single wall reflects completely, so
    /// one surface distinguishes nothing. Two surfaces do: the Casimir energy
    /// between them depends on whether the walls carry the same condition or
    /// opposite ones, and the two cases differ in sign. Equal conditions give
    /// attraction.
    ///
    /// The mode sums are regularised through the identity
    /// sum (n + 1/2)^{-s} = (2^s - 1) zeta(s), verified numerically where it
    /// converges and then continued to s = -3, which is the exponent the
    /// Casimir energy needs.
    class CasimirDiscriminant
    {
    public:
        /// Sum of n^{-s} over n from 1, truncated.
        static double integerPowerSum(double s, int terms = 2000000);

        /// Sum of (n + 1/2)^{-s} over n from 0, truncated.
        static double halfIntegerPowerSum(double s, int terms = 2000000);

        /// The ratio the two sums are claimed to have, 2^s - 1.
        static double expectedRatio(double s);

        /// Casimir energy per unit area for two walls carrying the same
        /// condition, either both Dirichlet or both Neumann.
        static double energySameCondition(double hbar, double c, double separation);

        /// Casimir energy per unit area for walls carrying opposite
        /// conditions, which is -7/8 of the previous value and therefore
        /// repulsive.
        static double energyOppositeConditions(double hbar, double c, double separation);

        /// Ratio of the two energies, which the mode sums fix at -7/8.
        static double energyRatio();
    };

    /// Section deriving what an experiment at the threshold would have to see.
    class CasimirDiscriminantSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What two threshold surfaces would discriminate";
        }
        void run(Report &report) const override;
    };

}
