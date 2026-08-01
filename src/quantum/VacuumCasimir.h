#pragma once

// ============================================================================
//  VacuumCasimir — model.md §22 (vakum yorumu ve Casimir imzasi)
// ----------------------------------------------------------------------------
//
//  §22.1 PARCACIK KAVRAMI NEDEN TANIMSIZ
//  Parcacik kavrami uc yapiya dayanir:
//    1. Pozitif/negatif frekans ayrimi     -> tek zaman ekseni gerekir
//    2. Hamiltonyenin alttan sinirli olmasi -> siralama gerekir
//    3. Poincare grubunun uniter temsili   -> tek zamanli grup yapisi gerekir
//  Bolge II'de UCU DE YOKTUR.
//
//  §22.2 AMA TEORI BOS DEGIL
//  Korelasyon fonksiyonlari <psi(x) psi(y)> Oklid bolgesinde tanimlidir (§21.3)
//  ve analitik devamla Lorentz bolgesine tasinabilir.
//
//    > BOLGE II BIR PARCACIK TEORISI DEGIL, BIR KORELASYON TEORISIDIR.
//    > "Kac parcacik var" sorusu cevapsizdir; "ne kadar korelasyon var" sorusu
//    > cevaplanabilir.
//
//  Bu, §16'daki "yorunge yok, cephe var" sonucunun kuantum karsiligidir.
//
//  §22.3 CASIMIR ETKISI
//  Sigma'daki pi = 0 kosulu (§9) kuantumda NEUMANN sinir kosuluna karsilik gelir.
//
//    TEK YUZEY: Casimir etkisi dogmaz — ikinci duvar yoktur. Yalnizca yuzey
//      yakininda vakum enerji yogunlugunda <T_00(z)> ~ hbar c / z^4 tipi bir
//      kayma olur, renormalizasyon gerektirir.
//
//    IKI YUZEY ARASINDA: L arali kli iki Sigma yuzeyi arasinda standart
//      Neumann-Neumann sonucu gecerlidir:
//
//          E/A = -pi^2 hbar c / (720 L^3)
//
//  DEGERLENDIRME: Sigma, v = c yuzeyidir; laboratuvarda erisilebilir degildir.
//  Dolayisiyla bu, prensipte var olan ama pratikte olculemeyen bir imzadir.
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class VacuumCasimir : public Section
    {
    public:
        // Iki Neumann yuzeyi arasinda birim alan basina Casimir enerjisi:
        //   E/A = -pi^2 hbar c / (720 L^3)
        static double casimirEnergyPerArea(double hbar, double c, double separation);

        // Tek yansitici yuzeyin yakininda vakum enerji yogunlugunun olcek
        // davranisi: <T_00(z)> ~ hbar c / z^4  (renormalizasyon gerektirir).
        static double singleSurfaceEnergyDensityScale(double hbar, double c, double distance);

        std::string number() const override { return "§22"; }
        std::string title() const override
        {
            return "Vakum yorumu: korelasyon teorisi ve Casimir imzasi";
        }
        void run(Report &report) const override;
    };

} // namespace slm
