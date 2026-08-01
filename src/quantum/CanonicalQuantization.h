#pragma once

// ============================================================================
//  CanonicalQuantization — model.md §20
// ----------------------------------------------------------------------------
//
//  §20.1 KANONIK YAPI CALISMIYOR — UC BAGIMSIZ ENGEL
//
//  (a) CAUCHY YUZEYI YOK. Bolge II'de konjuge momentum uc bilesenli:
//
//        pi_i = dL'/d(d_{t_i} psi) = d_{t_i} psi,   i = 1,2,3
//
//      Esanli komutasyon icin uzay-benzeri bir baslangic yuzeyi gerekir.
//      t1 = sabit alindiginda geriye (t2, t3, r) kalir; t2 ve t3 zaman-benzeri
//      oldugu icin bu yuzey uzay-benzeri DEGILDIR. Standart baginti
//
//        [psi(r), pi_i(r')] = i hbar delta(r - r')
//
//      indis sayisi bakimindan tutarsizdir: solda uc indis, sagda tek boyutlu
//      delta.
//
//  (b) FEYNMAN PROPAGATORU TANIMSIZ. Propagatordeki i-epsilon recetesi zaman
//      siralamasini kodlar. Uc zamanda tek bir siralama olmadigi icin kontur
//      secilemez.
//
//  (c) KARARLI VAKUM YOK. Oteleme simetrilerinden uc enerji bileseni cikar
//      (§16), dolayisiyla Hamiltonyen bir VEKTORDUR. "Alttan sinirli" ve
//      "en dusuk enerji" kavramlari tanimsizdir.
//
//  Uc engel de ayni koke baglidir: UC ZAMAN -> SIRALAMA YOK.
//
//  §20.2 KLASIK SONUCLARLA TUTARLILIK
//  Bu, §7'deki determinizm kaybinin (Cauchy probleminin kotu
//  konumlanmisliginin) kuantum duzeyindeki karsiligidir. Ayrica §9'daki "esik
//  gecirgen degil" sonucuyla uyumludur: iki bolge kuantum duzeyinde de
//  birlestirilemez.
//
//  Model boylece uc bagimsiz yoldan ayni sonuca varir: BOLGE II KENDI ICINDE
//  TUTARLIDIR, ANCAK BOLGE I ILE BIRLESTIRILEMEZ.
//
//  §20.3 KURTARILABILEN: YOL INTEGRALI
//      Z = integral D[psi] exp( i S'[psi] / hbar ),   S' = integral L' d^3t dr
//  Cauchy yuzeyi gerektirmedigi icin tanimlidir. (Bkz. PathIntegral.)
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class CanonicalQuantization : public Section
    {
    public:
        // Bolge I'de konjuge momentum sayisi (1), Bolge II'de (3).
        static int conjugateMomentumCount(bool regionII);

        // t_1 = sabit yuzeyinde kalan koordinatlardan kac tanesi zaman-benzeri?
        // Bolge I'de 0 (yuzey uzay-benzeri), Bolge II'de 2 (yuzey uzay-benzeri degil).
        static int timelikeDirectionsOnSlice(bool regionII);

        // Esanli komutasyon bagintisinin indis sayimi tutarli mi?
        // Sol tarafta konjuge momentum indisi, sagda delta fonksiyonunun boyutu.
        static bool commutatorIndicesConsistent(bool regionII);

        std::string number() const override { return "§20"; }
        std::string title() const override
        {
            return "Kuantumlama: kanonik yapinin uc bagimsiz engeli";
        }
        void run(Report &report) const override;
    };

} // namespace slm
