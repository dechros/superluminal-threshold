#pragma once

#include "core/Section.h"

namespace slm
{

    /// The one place where the model makes a discriminating prediction.
    ///
    /// Section 19.5 showed that every self-adjoint condition at a single wall
    /// reflects completely, so a single surface tells nothing apart. Two
    /// surfaces do: the Casimir energy between them depends on whether the two
    /// walls carry the same condition or opposite ones, and the two cases
    /// differ in sign. This model puts the same condition on both walls and so
    /// predicts attraction.
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
        std::string number() const override { return "16.4"; }
        std::string title() const override
        {
            return "What two threshold surfaces would discriminate";
        }
        void run(Report &report) const override;
    };

}
