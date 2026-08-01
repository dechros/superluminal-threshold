#pragma once

// ============================================================================
//  Dispersion — model.md §6 ve §16 (dispersiyon / grup hizi kismi)
// ----------------------------------------------------------------------------
//
//  §6 HIZ KAVRAMI
//  --------------
//  D'de V gecmiyor. Bu bir eksiklik degil — turetildi:
//
//  Bizim tarafta hiz zaten temel degil, dispersiyondan cikiyor:
//
//      omega(k) = c*sqrt(k^2 + mu),   mu = (mc/hbar)^2
//      v_faz    = omega/k
//      v_grup   = d(omega)/dk
//      v_faz * v_grup = c^2
//
//  Oteki tarafta ayni turev aliniyor ama payda vektor (zaman uc boyutlu):
//
//      dq/dkappa  ->  skaler/vektor = gradyan = VEKTOR
//
//  SONUC: Hiz skaler olmaktan cikip yonelime donusuyor. "Ne kadar hizli"
//  sorusu "hangi yonelimde" sorusuna donusuyor. V bilgisi B boostunda, yani
//  uc-zaman uzayindaki yonelimde yasiyor.
//
//  Sinir davranisi her iki tarafta ayni: kappa->0'da 0, kappa->sonsuz'da c.
//
//  Hiz donusumu: v' = c^2/v. Isik hizi sabit nokta.
//
//
//  §16 KARSI TARAFTA DISPERSIYON VE GRUP HIZI
//  ------------------------------------------
//  Duzlem dalga:
//      k1^2 + k2^2 + k3^2 - q^2/c^2 + mu = 0   ->   q = +- c*sqrt(k^2 + mu)
//
//  q her zaman reel: r ekseninde salinim var, sonumlenme yok.
//
//  Durgun cisim (k = 0): q = mc^2/hbar != 0. Yani orada duran cisim bile r
//  ekseninde ilerler — bizim taraftaki "duran cisim zamanda ilerler"
//  ifadesinin tam aynasi.
//
//  Grup hizi:
//      dq/dk = c*hbar*k / sqrt(c^2m^2 + hbar^2k^2)   (vektor, k dogrultusunda)
//      |dq/dk| < c,  k->sonsuz limitinde -> c
//
//  Karsi tarafta da hiz siniri var; yalnizca hangi eksende oldugu degismis.
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class Dispersion
    {
    public:
        Dispersion(double c, double mass, double hbar);

        // mu = (m c / hbar)^2
        double mu() const;

        // Bolge I: omega(k) = c sqrt(k^2 + mu)
        double angularFrequency(double k) const;
        double phaseVelocity(double k) const;
        double groupVelocity(double k) const;

        // Bolge II: q(kappa) = c sqrt(kappa^2 + mu) — ayni fonksiyon,
        // ama kappa uc bilesenli oldugu icin turev bir VEKTOR.
        double spatialFrequency(double kappa) const;
        // |dq/dkappa| — gradyanin buyuklugu.
        double gradientMagnitude(double kappa) const;

    private:
        double c_;
        double mass_;
        double hbar_;
    };

    class DispersionSection : public Section
    {
    public:
        std::string number() const override { return "§6"; }
        std::string title() const override
        {
            return "Hiz kavrami: skalerden yonelime";
        }
        void run(Report &report) const override;
    };

} // namespace slm
