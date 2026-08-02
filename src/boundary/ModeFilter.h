#pragma once

#include "core/Section.h"

namespace slm
{

    /// Which far-side modes grow, and which of them the threshold can inject.
    ///
    /// Section 6.1 takes a mode on the far side, holds the data on a surface of
    /// constant t1, and finds the coefficient of the second t1 derivative can be
    /// positive, so that the solution grows exponentially and the initial value
    /// problem is ill posed. That argument fixes k2, k3 and q independently of
    /// one another.
    ///
    /// A mode that arrives by crossing the threshold does not have that freedom.
    /// Matching at the surface produces a transmitted wave that solves the far
    /// side equation, so its four wavenumbers satisfy the far side dispersion
    /// relation. The question this section settles is whether the growing modes
    /// and the modes the threshold can inject overlap at all.
    class ModeFilter
    {
    public:
        /// Coefficient of f in the t1 equation, growing when positive.
        /// The mode is exp(i(k2 t2 + k3 t3 + q r)) f(t1).
        static double growthCoefficient(double c, double mu, double k2, double k3, double q);

        /// Whether that mode grows exponentially in t1.
        static bool isGrowing(double c, double mu, double k2, double k3, double q);

        /// Squared normal wavenumber a mode must carry to satisfy the far side
        /// dispersion relation, given the three wavenumbers along the times.
        static double onShellNormalSquared(double c, double mu, double k1, double k2, double k3);

        /// Residual of the far side dispersion relation, zero when on shell.
        static double dispersionResidual(double c, double mu, double k1, double k2, double k3,
                                         double q);

        /// Growth coefficient of an on-shell mode, which the identity below
        /// shows to equal -k1 squared.
        static double onShellGrowthCoefficient(double c, double mu, double k1, double k2,
                                               double k3);
    };

    /// Section asking whether the threshold can inject a growing mode.
    class ModeFilterSection : public Section
    {
    public:
        std::string number() const override { return "6.2"; }
        std::string title() const override
        {
            return "The threshold as a mode filter: which far-side modes can be reached";
        }
        void run(Report &report) const override;
    };

}
