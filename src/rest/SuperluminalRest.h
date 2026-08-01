#pragma once

// ============================================================================
//  SuperluminalRest — model.md §8 (makale acigi #5) — kapandi
// ----------------------------------------------------------------------------
//
//  Makale: durgun dort-momentum p' = (mcs, 0), her s icin ayri dunya cizgisi
//  demeti. "Ilginc muamma."
//
//  Hesap:
//    - Kutle kabugu kosulu -> s1^2 + s2^2 + s3^2 = 1, yani s in S^2
//    - eta' = diag(+1,+1,+1,-1) icinde ilk uc slot AYNI isaretli -> onlari
//      koruyan grup O(3)
//    - O(3) hem metrigi koruyor hem durgunlugu bozmuyor (dogrulandi)
//    - O(3), S^2 uzerinde GECISLI (transitif) etki ediyor
//
//  SONUC: Tum s secimleri ayni yorungede. Sonsuz sayida fiziksel durum yok;
//  TEK BIR DURUMU YAZMANIN SONSUZ YOLU VAR. Ayar (gauge) fazlaligi.
//
//    Stabilizator : O(2)
//    Yorunge uzayi: O(3)/O(2) = S^2
//
//  Makale acigi #5 kapandi.
// ============================================================================

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    class SuperluminalRest : public Section
    {
    public:
        // Durgun superluminal dort-momentum: p' = (m c s1, m c s2, m c s3, 0).
        static Vector4 restFourMomentum(double c, double mass, double s1, double s2, double s3);

        // Uc zaman ekseninde donme; dorduncu (uzay) slot sabit.
        // blok-diag(R, 1) seklinde bir O(3) elemani.
        static Matrix4 timeRotation(double alpha, double beta, double gamma);

        // Uc zamanda yansima (det = -1): O(3)\SO(3) elemani.
        static Matrix4 timeReflection(int axis);

        std::string number() const override { return "§8"; }
        std::string title() const override
        {
            return "Superluminal durgunluk (makale acigi #5): gauge fazlaligi";
        }
        void run(Report &report) const override;
    };

} // namespace slm
