#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the spherically symmetric solution and its finite path
    /// length.
    ///
    /// Unlike the other sections this one carries state, the two constants
    /// fixing the solution branch.
    class SphericalSolution : public Section
    {
    public:
        /// \param c Speed of light.
        /// \param a Scale constant of the closed form solution.
        SphericalSolution(double c = 1.0, double a = 1.0);

        /// Closed form velocity p(t) = c a / sqrt(a^2 - t^4).
        double velocity(double t) const;
        /// Analytic derivative dp/dt.
        double velocityDerivative(double t) const;

        /// Residual of the reduced equation of motion, zero for the solution.
        double odeResidual(double t) const;

        /// True for the equilibria p = 0, +c and -c.
        static bool isEquilibrium(double c, double p);

        /// Total path length by quadrature, with the endpoint singularity
        /// removed by two substitutions.
        /// \param samples Number of quadrature samples.
        double totalPathNumeric(int samples = 2000000) const;

        /// Total path length in closed form.
        double totalPathClosedForm() const;

        std::string number() const override { return "10"; }
        std::string title() const override
        {
            return "Spherically symmetric solution in closed form";
        }
        void run(Report &report) const override;

    private:
        double c_;
        double a_;
    };

}
