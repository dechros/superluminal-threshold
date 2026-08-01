#pragma once

// ============================================================================
//  ThresholdSurface — model.md §9 (esik bolgesi, V = c)
// ----------------------------------------------------------------------------
//
//  Makalede hic ele alinmiyor. Iki bolge arasindaki Sigma yuzeyi icin eklem
//  kosullari:
//
//     (a) alan surekli:              psi_I|_Sigma = psi_II|_Sigma
//     (b) konjuge momentum surekli:  pi_I|_Sigma  = pi_II|_Sigma
//
//  Normal yon Bolge I'de zaman-benzeri, Bolge II'de uzay-benzeri. Bu yuzden
//  pi_II = -pi_I.
//
//  (b) ancak  pi|_Sigma = 0  ise saglaniyor. Bu bir DUGUM kosulu: esikte aki
//  sifir.
//
//  SONUC: Sigma gecirgen degil, YANSITICI. Kutleli madde esikten gecemiyor,
//  tam yansiyor.
//
//  ISTISNA: mu = 0 (kutlesiz) durumda kosul kendiliginden saglaniyor — ama
//  kutlesiz alan zaten c'de, gecmesi gerekmiyor.
//
//  Bu sonuc modele elle konmadi; kendi Lagrangian'indan cikti.
//
//  Esik kosulunun dispersiyon tarafindaki karsiligi: v_faz = v_grup = c
//  ancak mu = 0 icin saglanir. Kutleli alan icin v_faz > c ama v_grup < c;
//  esik ASILMIYOR, TEGET geciliyor.
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class ThresholdSurface : public Section
    {
    public:
        // Bolge I'de konjuge momentum pi = (1/c^2) d_t phi.
        static double conjugateMomentumRegionI(double c, double timeDerivative);

        // Bolge II'de normal yon tip degistirdigi icin isaret doner.
        static double conjugateMomentumRegionII(double c, double timeDerivative);

        // Eklem kosulunun artigi: pi_I - pi_II. Yalnizca pi = 0 icin sifir.
        static double junctionResidual(double c, double timeDerivative);

        std::string number() const override { return "§9"; }
        std::string title() const override
        {
            return "Esik bolgesi (V = c): Sigma yansiticidir";
        }
        void run(Report &report) const override;
    };

} // namespace slm
