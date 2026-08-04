#include "spherical/SphericalSolution.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{
    SphericalSolution::SphericalSolution(double c, double a) : c_(c), a_(a) {}

    double SphericalSolution::velocity(double t) const
    {
        return c_ * a_ / std::sqrt(a_ * a_ - std::pow(t, 4));
    }

    double SphericalSolution::velocityDerivative(double t) const
    {
        const double base = a_ * a_ - std::pow(t, 4);
        return 2.0 * c_ * a_ * std::pow(t, 3) / std::pow(base, 1.5);
    }

    double SphericalSolution::odeResidual(double t) const
    {
        const double p = velocity(t);
        return velocityDerivative(t) + (2.0 / t) * p - (2.0 / (c_ * c_ * t)) * std::pow(p, 3);
    }

    bool SphericalSolution::isEquilibrium(double c, double p)
    {
        return std::abs(p * (p * p - c * c)) < 1e-12;
    }

    double SphericalSolution::totalPathNumeric(int samples) const
    {
        if (samples % 2 != 0)
        {
            ++samples;
        }
        const double upper = std::numbers::pi / 2.0;
        const double step = upper / samples;

        auto integrand = [](double theta)
        {
            const double s = std::sin(theta);
            return 1.0 / std::sqrt(1.0 + s * s);
        };

        double sum = integrand(0.0) + integrand(upper);
        for (int i = 1; i < samples; ++i)
        {
            sum += integrand(i * step) * (i % 2 == 0 ? 2.0 : 4.0);
        }
        return c_ * std::sqrt(a_) * sum * step / 3.0;
    }

    double SphericalSolution::totalPathClosedForm() const
    {
        return std::sqrt(std::numbers::pi) * std::sqrt(a_) * c_ * std::tgamma(0.25) /
               (4.0 * std::tgamma(0.75));
    }

    void SphericalSolution::run(Report &report) const
    {
        report.subsection("Closed form solution: p = c a / sqrt(a^2 - t^4)");
        for (double t : {0.05, 0.2, 0.5, 0.8, 0.95, 0.999})
        {
            const double scaled = t * std::sqrt(a_);
            report.checkNear("  the solution satisfies the equation", odeResidual(scaled), 1e-8);
        }

        report.subsection("Equilibrium points");
        for (double p : {0.0, c_, -c_})
        {
            report.check(std::format("  p = {:g} is an equilibrium "
                                     "point", p), isEquilibrium(c_, p));
        }
        for (double p : {0.5 * c_, 2.0 * c_})
        {
            report.check(std::format("  p = {:g} is NOT an equilibrium "
                                     "point", p), !isEquilibrium(c_, p));
        }

        report.subsection("Behaviour: p = c at t = 0, p -> infinity as t -> sqrt(a)");
        report.checkNear("p(0) = c", velocity(0.0) - c_);
        report.check("p diverges as t -> sqrt(a)",
                     velocity(0.9999 * std::sqrt(a_)) > velocity(0.99 * std::sqrt(a_)) &&
                         velocity(0.9999 * std::sqrt(a_)) > 20.0 * c_);

        report.subsection("The total path length is finite");
        const double numeric = totalPathNumeric();
        const double closed = totalPathClosedForm();
        report.checkNear("numerical equals closed form", numeric - closed, 1e-9);
        report.checkNear("coefficient ~ 1.311", closed / (c_ * std::sqrt(a_)) - 1.31103, 1e-4);
    }
}
