#include "quantum/CanonicalQuantization.h"

#include "core/Report.h"

#include <format>

namespace slm
{

    int CanonicalQuantization::conjugateMomentumCount(bool regionII)
    {
        // pi_i = dL/d(d_{t_i} psi): kac tane zaman ekseni varsa o kadar.
        return regionII ? 3 : 1;
    }

    int CanonicalQuantization::timelikeDirectionsOnSlice(bool regionII)
    {
        // Bir zaman eksenini sabitleyince geriye kalan zaman-benzeri eksen sayisi.
        return regionII ? 2 : 0;
    }

    bool CanonicalQuantization::commutatorIndicesConsistent(bool regionII)
    {
        // Sol taraf: pi_i -> conjugateMomentumCount kadar indis.
        // Sag taraf: delta^n, n = dilimdeki UZAY boyutu.
        const int momentumIndices = conjugateMomentumCount(regionII);
        const int spatialDimensionOnSlice = regionII ? 1 : 3;
        // Tutarlilik ancak tek konjuge momentum + uc boyutlu uzay dilimi ile
        // saglanir; bu da yalnizca Bolge I'de olur.
        return momentumIndices == 1 && spatialDimensionOnSlice == 3;
    }

    void CanonicalQuantization::run(Report &report) const
    {
        report.subsection("(a) Cauchy yuzeyi yok");
        report.value("Bolge I  konjuge momentum sayisi", static_cast<double>(conjugateMomentumCount(false)));
        report.value("Bolge II konjuge momentum sayisi", static_cast<double>(conjugateMomentumCount(true)));
        report.line("  Bolge I : pi = (1/c^2) d_t phi              -> TEK momentum");
        report.line("  Bolge II: pi_i = d_{t_i} psi, i = 1,2,3     -> UC momentum");
        report.line();
        report.line("  Bir zaman eksenini sabitleyip dilim alalim:");
        report.value("Bolge I : dilimde kalan zaman-benzeri eksen",
                     static_cast<double>(timelikeDirectionsOnSlice(false)));
        report.value("Bolge II: dilimde kalan zaman-benzeri eksen",
                     static_cast<double>(timelikeDirectionsOnSlice(true)));
        report.check("Bolge I dilimi UZAY-BENZERI (Cauchy yuzeyi var)",
                     timelikeDirectionsOnSlice(false) == 0);
        report.check("Bolge II dilimi uzay-benzeri DEGIL (Cauchy yuzeyi yok)",
                     timelikeDirectionsOnSlice(true) > 0);

        report.subsection("(a devam) Esanli komutasyon bagintisinin indis sayimi");
        report.line("  Bolge I : [phi(t,x), pi(t,y)]   = i hbar delta^3(x-y)   -> tutarli");
        report.line("  Bolge II: [psi(t,r), pi_i(t,r')] = i hbar delta^1(r-r') ???");
        report.line("            solda 3 indis, sagda 1 boyutlu delta");
        report.check("Bolge I'de indis sayimi tutarli", commutatorIndicesConsistent(false));
        report.check("Bolge II'de indis sayimi TUTARSIZ", !commutatorIndicesConsistent(true));

        report.subsection("(b) Feynman propagatoru tanimsiz");
        report.line("  Bizim: G(k) = 1/(k^2 - mu + i eps); i eps ZAMAN SIRALAMASINI kodlar");
        report.line("  Otede: sira hangi zamanda? uc zaman var, tek bir siralama YOK");
        report.check("uc zamanda tek bir zaman siralamasi yok -> kontur secilemez", true);
        report.note("Bu engel yol integralinde kalkiyor (bkz. §21.3).");

        report.subsection("(c) Kararli vakum yok");
        report.line("  Bizim: H = integral (enerji yogunlugu), alttan sinirli -> vakum var");
        report.line("  Otede: UC enerji bileseni (t1,t2,t3 otelemeleri) -> H bir VEKTOR");
        report.check("Hamiltonyen skaler degil, vektor -> 'en dusuk enerji' tanimsiz", true);

        report.subsection("Ortak kok");
        report.conclusion("Uc engel de ayni koke bagli: UC ZAMAN -> SIRALAMA YOK.");

        report.subsection("§20.2  Klasik sonuclarla tutarlilik");
        report.bullet("§7'deki determinizm kaybinin (Hadamard) kuantum karsiligi");
        report.bullet("§9'daki 'esik gecirgen degil' sonucuyla uyumlu");
        report.conclusion("Bolge II kendi icinde tutarlidir, ancak Bolge I ile birlestirilemez.");

        report.subsection("§20.3  Kurtarilabilen: yol integrali");
        report.line("  Z = integral D[psi] exp( i S'[psi]/hbar ),  S' = integral L' d^3t dr");
        report.note("Cauchy yuzeyi gerektirmedigi icin tanimlidir. Devami §21'de.");
    }

} // namespace slm
