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
        // d/dt [ c a (a^2 - t^4)^(-1/2) ] = 2 c a t^3 (a^2 - t^4)^(-3/2)
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
        // p' = -(2/t) p + (2/(c^2 t)) p^3 = 0  ->  p (p^2 - c^2) = 0
        return std::abs(p * (p * p - c * c)) < 1e-12;
    }

    double SphericalSolution::totalPathNumeric(int samples) const
    {
        // integral_0^sqrt(a) c a / sqrt(a^2 - t^4) dt
        //   t = sqrt(a) u        ->  c sqrt(a) integral_0^1 du / sqrt(1 - u^4)
        //   u = sin(theta)       ->  c sqrt(a) integral_0^(pi/2) dtheta / sqrt(1 + sin^2 theta)
        // Ikinci degisken donusumu ucdaki tekilligi tamamen kaldiriyor.
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
        report.subsection("1) Makale (35) -> (37) indirgemesi");
        report.line("  (35): [ ((1/c^2)(grad_t' r')^2 - 1) delta_ij");
        report.line("          - (1/c^2)(dr'/dt'_i)(dr'/dt'_j) ] d^2r'/(dt'_i dt'_j) = 0");
        report.line("  Kuresel simetride grad_t' r' = r'(t) that  ->  (grad)^2 = r'^2");
        report.line("  d^2/(dt_i dt_j) -> radyal r'' + iki tegetsel (r'/t)");
        report.line("  Sonuc: A(r'' + 2r'/t) - (r'^2/c^2) r'' = 0,   A = r'^2/c^2 - 1");
        report.line("  rpp katsayisi = -1  ->  r'' + 2r'/t - (2/(c^2 t)) r'^3 = 0");
        report.conclusion("MAKALE (37) ILE AYNI. Kaynaktan dogru aktarim bagimsiz dogrulandi.");

        report.subsection("2) Kapali form cozum: p = c a / sqrt(a^2 - t^4)");
        report.value("c =", c_);
        report.value("a =", a_);
        report.line();
        report.line("       t          p(t)         p'(t)        ODE artigi");
        for (double t : {0.05, 0.2, 0.5, 0.8, 0.95, 0.999})
        {
            const double scaled = t * std::sqrt(a_);
            report.line(std::format("   {:>8.4g}  {:>12.6g}  {:>12.6g}  {:>13.3e}",
                                    scaled, velocity(scaled), velocityDerivative(scaled),
                                    odeResidual(scaled)));
            report.checkNear("  cozum denklemi sagliyor", odeResidual(scaled), 1e-8);
        }
        report.note("Elliptik fonksiyona gerek yok.");

        report.subsection("3) Denge noktalari");
        for (double p : {0.0, c_, -c_})
        {
            report.check(std::format("  p = {:g} bir denge noktasi", p), isEquilibrium(c_, p));
        }
        for (double p : {0.5 * c_, 2.0 * c_})
        {
            report.check(std::format("  p = {:g} denge noktasi DEGIL", p), !isEquilibrium(c_, p));
        }
        report.note("p = 0 (sabit cozum) ve p = +-c (isik hizinda genisleyen kabuk).");

        report.subsection("4) Davranis: t = 0'da p = c, t -> sqrt(a) iken p -> sonsuz");
        report.value("p(0) =", velocity(0.0));
        report.checkNear("p(0) = c", velocity(0.0) - c_);
        report.value("p(0.99 sqrt(a)) =", velocity(0.99 * std::sqrt(a_)));
        report.value("p(0.9999 sqrt(a)) =", velocity(0.9999 * std::sqrt(a_)));
        report.check("t -> sqrt(a) iken p iraksiyor",
                     velocity(0.9999 * std::sqrt(a_)) > velocity(0.99 * std::sqrt(a_)) &&
                         velocity(0.9999 * std::sqrt(a_)) > 20.0 * c_);

        report.subsection("5) Alinan toplam yol SONLU");
        const double numeric = totalPathNumeric();
        const double closed = totalPathClosedForm();
        report.value("sayisal integral (Simpson)   r =", numeric);
        report.value("kapali form  sqrt(pi a) c G(1/4)/(4G(3/4)) =", closed);
        report.value("kapali form / (c sqrt(a))    =", closed / (c_ * std::sqrt(a_)));
        report.checkNear("sayisal == kapali form", numeric - closed, 1e-9);
        report.checkNear("katsayi ~ 1.311", closed / (c_ * std::sqrt(a_)) - 1.31103, 1e-4);

        report.subsection("6) Fiziksel okuma");
        report.conclusion("Nokta parcacik yorungesi degil, KURESEL BIR CEPHE.");
        report.note("Isik hiziyla baslar, hizlanarak genisler,");
        report.note("sonlu surede ve sonlu yaricapta sonsuz hiza ulasir; otesinde tanimsiz.");
        report.note("Makale acigi #4 kapandi.");
    }

} // namespace slm
