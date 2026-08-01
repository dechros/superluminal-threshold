#pragma once

// ============================================================================
//  SphericalSolution — model.md §14 (makale acigi #4) — kapandi
// ----------------------------------------------------------------------------
//
//  Makalenin genel hareket denklemi (35) kuresel simetriye indirgendi ve (37)
//  ile birebir ayni cikti:
//
//      r'' + (2/t) r' - (2/(c^2 t)) (r')^3 = 0
//
//  Denklemin kaynaktan dogru aktarildigi boylece bagimsiz dogrulandi.
//
//  Indirgeme adimlari (makale (35) -> (37)):
//    (35):  [ ((1/c^2)(grad_t' r')^2 - 1) delta_ij
//             - (1/c^2)(dr'/dt'_i)(dr'/dt'_j) ] d^2r'/(dt'_i dt'_j) = 0
//    Kuresel simetride grad_t' r' = r'(t) * that  =>  (grad)^2 = r'^2
//    d^2/(dt_i dt_j) -> radyal r'' + iki tegetsel (r'/t)
//    Sonuc: A*(r'' + 2r'/t) - (r'^2/c^2) r'' = 0,  A = (r'^2/c^2 - 1)
//    rpp katsayisi = -1 oldugu icin: r'' + 2r'/t - (2/(c^2 t)) r'^3 = 0
//
//  KAPALI FORM COZUM
//
//      p = dr/dt = +- c*a / sqrt(a^2 - t^4)
//
//  Sembolik olarak denklemi sagladigi dogrulandi. Elliptik fonksiyona gerek yok.
//
//  DENGE NOKTALARI: p = 0, +c, -c (makalenin bahsettigi sabit cozum ve isik
//  hizinda genisleyen kabuk).
//
//  DAVRANIS: t = 0'da p = c; t -> sqrt(a) iken p -> sonsuz.
//
//  ALINAN TOPLAM YOL (SONLU):
//
//      r = sqrt(pi) * sqrt(a) * c * Gamma(1/4) / (4 Gamma(3/4)) ~ 1,311 c sqrt(a)
//
//  FIZIKSEL OKUMA: Nokta parcacik yorungesi degil, KURESEL BIR CEPHE. Isik
//  hiziyla baslar, hizlanarak genisler, sonlu surede ve sonlu yaricapta sonsuz
//  hiza ulasir; otesinde tanimsiz.
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class SphericalSolution : public Section
    {
    public:
        SphericalSolution(double c = 1.0, double a = 1.0);

        // p(t) = c a / sqrt(a^2 - t^4)
        double velocity(double t) const;
        double velocityDerivative(double t) const;

        // Denklemin artigi: p' + (2/t) p - (2/(c^2 t)) p^3.  Cozum icin 0.
        double odeResidual(double t) const;

        // Denge noktalari: p' = 0 -> p in {0, +c, -c}.
        static bool isEquilibrium(double c, double p);

        // r = integral_0^sqrt(a) p dt  — sayisal (Gauss-Legendre benzeri,
        // t = sqrt(a) tekilligi degisken donusumuyle yumusatiliyor).
        double totalPathNumeric(int samples = 2000000) const;

        // Kapali form: sqrt(pi) sqrt(a) c Gamma(1/4) / (4 Gamma(3/4))
        double totalPathClosedForm() const;

        std::string number() const override { return "§14"; }
        std::string title() const override
        {
            return "Kuresel simetrik cozum (makale acigi #4) — kapandi";
        }
        void run(Report &report) const override;

    private:
        double c_;
        double a_;
    };

} // namespace slm
