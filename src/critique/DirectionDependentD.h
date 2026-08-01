#pragma once

// ============================================================================
//  DirectionDependentD — model.md §26.2 (yon-bagimlilik denemesi ve sonucu)
// ----------------------------------------------------------------------------
//
//  Lake'in (4) numarali itirazini karsilamak icin D'nin yon-bagimli hale
//  getirilmesi denendi (Householder tipi ve Zaopo tipi formlar). Sonuc:
//
//    Aday                                M^2 = I            det   eta-cevirme
//    [[0,-n^T],[-n, I-P]]  (Zaopo)       belirli yonlerde    -1    HAYIR
//    [[0, n^T],[ n, I-P]]                hayir               -1    hayir
//    [[0, n^T],[ n, P-I]]                evet                -1    hayir
//
//  Burada n boost yonu birim vektoru, P = n n^T (n yonu projektoru).
//
//  Zaopo'nun Lambda_inf'i araligi YALNIZCA t ve n'nin gerdigi 2B alt uzayda
//  cevirir; dik yonlerde cevirmez. Lake'in "(1+1) sektorunde gercek cevirme
//  olur, (1+3)'te olmaz" tespiti dogrulanmis oldu.
//
//  Zaopo'nun Lambda_inf'i araligi KORUYOR (s'^2 = s^2), isaret CEVIRMIYOR.
//  Isaret cevirme onun (8) numarali KONJUGASYON kosuludur:
//      A mu A^-1 = -mu
//  Bu, metrik BILESENLERININ yeniden siralanmasidir — Lake'in itiraz ettigi sey.
// ============================================================================

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    class DirectionDependentD : public Section
    {
    public:
        enum class Form
        {
            Zaopo,        // [[0,-n^T],[-n, I - P]]
            PlusIdentity, // [[0, n^T],[ n, I - P]]
            MinusIdentity // [[0, n^T],[ n, P - I]]
        };

        // Kuresel acilarla verilen yon n icin aday matris.
        static Matrix4 candidate(Form form, double theta, double phi);

        // Householder tipi: [[0, n^T],[n, I - 2P]]
        static Matrix4 householder(double theta, double phi);

        std::string number() const override { return "§26.2"; }
        std::string title() const override
        {
            return "Yon-bagimli D denemesi: Lake itirazina cevap araniyor";
        }
        void run(Report &report) const override;
    };

} // namespace slm
