#pragma once

// ============================================================================
//  KleinGordonField — model.md §7 ve §16
// ----------------------------------------------------------------------------
//
//  §7 LAGRANGIAN VE ALAN DENKLEMI
//  ------------------------------
//  Bizim taraf (Klein-Gordon):
//
//      L = 1/2 [ (d_t phi)^2/c^2 - (grad phi)^2 - mu phi^2 ]
//
//  Euler-Lagrange -> (1/c^2) d_t^2 phi - laplace(phi) + mu phi = 0
//
//  D uygulanmis hali:
//
//      L' = 1/2 [ (d_t1 psi)^2 + (d_t2 psi)^2 + (d_t3 psi)^2
//                 - (d_r psi)^2/c^2 + mu psi^2 ]
//
//  Euler-Lagrange -> (d^2_t1 + d^2_t2 + d^2_t3) psi - (1/c^2) d^2_r psi
//                    - mu psi = 0
//
//  Iki denklem D ile birbirine geciyor; KG operatoru isaret cevirerek
//  donusuyor:  box -> -box'.
//
//  DETERMINIZM KAYBI TURETILDI:
//    Bolge I : 1 zaman + 3 uzay -> baslangic deger problemi iyi konumlanmis
//              -> DETERMINIST
//    Bolge II: 3 zaman + 1 uzay -> Cauchy problemi Hadamard anlaminda kotu
//              konumlanmis -> ONGORU COKUYOR
//
//  Makale bunu argumanla one suruyor; burada dogrudan denklem tipinden cikiyor.
//
//  Sayisal gosterim (bu sinifta yapilan): bir modu
//      Bolge I'de  exp(i(k.x)) x f(t)  seklinde alip d_t^2 f = -c^2(k^2+mu) f
//      Bolge II'de exp(i(k2 t2 + k3 t3 + q r)) x f(t1) seklinde alip
//                  d_t1^2 f = (k2^2 + k3^2 - q^2/c^2 + mu) f
//  yazariz. Bolge I'de katsayi her zaman NEGATIF -> salinim, sinirli buyume.
//  Bolge II'de katsayi POZITIF olabilir ve k2,k3 -> sonsuz iken sinirsiz
//  buyur -> exp(sqrt(katsayi) t1) tipi patlama. Baslangic verisindeki keyfi
//  kucuk bir bozulma, keyfi buyuk bir cozum degisimi verir: Hadamard anlaminda
//  KOTU KONUMLANMIS.
//
//
//  §16 KARSI TARAFTA DINAMIK (makale acigi #1) — kapandi
//  -----------------------------------------------------
//  NOETHER YUKLERI
//    L' dort koordinattan da acikca bagimsiz -> dort oteleme simetrisi:
//      - uc "enerji" bileseni (t1,t2,t3 otelemeleri)
//      - tek "momentum" (r otelemesi)
//    L' uc zamanda O(3) altinda degismez -> uc korunan "zamansal aci
//    momentumu", bizim uzaysal aci momentumumuzun aynasi.
//
//  ANA SONUC: ROLLER TAM TERSINE DONMUS
//
//      |                        | Bolge I (bizim)  | Bolge II            |
//      | Serbest hareket        | Uzayda, uc yonde | Uc zamanda serbestce|
//      | Tek yonlu zorunluluk   | Zamanda          | Tek uzay ekseninde  |
//      | O(3) donme simetrisi   | Uzaysal          | Zamansal            |
//      | Nesne                  | Yorunge (egri)   | Cephe (3B hiperyuzey)|
//
//  ZAMANIN OKU SORUSU CEVAPLANDI: Bolge II'de zamanin oku YOKTUR. Ok, ilgili
//  boyutun TEK olmasinin sonucudur. Uc boyutlu olan eksen kumesi uzay gibi
//  davranir, yon ayrimi kalkar. Buna karsilik Bolge II'de bir UZAY OKU vardir
//  — r tek eksen oldugu icin.
//
//  Ok, entropiden degil, BOYUT SAYISINDAN cikar. Bu makale acigi #1'in
//  dogrudan cevabidir.
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class KleinGordonField : public Section
    {
    public:
        // Bolge I: (1/c^2) d_t^2 phi - laplace(phi) + mu phi = 0
        // Duzlem dalga modu icin d_t^2 f = coefficient * f  katsayisi.
        static double regionIGrowthCoefficient(double c, double mu, double kSquared);

        // Bolge II: (d^2_t1+d^2_t2+d^2_t3) psi - (1/c^2) d^2_r psi - mu psi = 0
        // t1'i evrim parametresi alarak d_t1^2 f = coefficient * f  katsayisi.
        static double regionIIGrowthCoefficient(double c, double mu, double kTransverseSquared,
                                                double q);

        // Bolge I alan denkleminin duzlem dalga artigini dondurur (0 olmali).
        static double regionIResidual(double c, double mu, double omega, double kSquared);

        // Bolge II alan denkleminin duzlem dalga artigi (0 olmali).
        static double regionIIResidual(double c, double mu, double kSquared, double q);

        std::string number() const override { return "§7 / §16"; }
        std::string title() const override
        {
            return "Lagrangian, alan denklemi, determinizm kaybi ve zamanin oku";
        }
        void run(Report &report) const override;
    };

} // namespace slm
