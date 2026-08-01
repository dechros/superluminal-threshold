#pragma once

// ============================================================================
//  PathIntegral — model.md §21 (yol integrali ve Oklid yapisi)
// ----------------------------------------------------------------------------
//
//  §21.1 WICK DONUSU ZORUNLU BIR SECIM VERIYOR
//
//    Secenek                        Oklid cekirdegi                  Sonuc
//    (a) Uc zamani birden dondur    mu - k1^2 - k2^2 - k3^2 - q^2/c^2 IRAKSAR
//    (b) Tek uzay eksenini dondur   mu + k1^2 + k2^2 + k3^2 + q^2/c^2 YAKINSAR
//    (c) Bileske yon                —                                TANIMSIZ
//
//  Yalnizca (b) calisiyor. Secim keyfi degil, ZORUNLU.
//  ((c) O(3)-degismez olmadigi icin tanimsiz.)
//
//  §21.2 YORUM: "TEK OLAN EKSENI DONDUR"
//    Bolge I'de zaman tek boyutludur, Wick donusu ZAMANI dondurur.
//    Bolge II'de uzay tek boyutludur, Wick donusu UZAYI dondurur.
//  Bu, D'nin zaman eksenini uzay eksenine gondermesiyle tam tutarlidir (§3).
//
//  §21.3 OKLID PROPAGATORU — §20.1(b) ENGELININ KALKMASI
//
//      G_E(k,q) = 1 / (k1^2 + k2^2 + k3^2 + q^2/c^2 + mu)
//
//  Payda reel argumanlar icin daima >= mu > 0 -> KUTUP YOK. Tekillik olmadigi
//  icin i-epsilon recetesine ihtiyac yoktur; zaman siralamasi gerektirmez.
//  Yani kanonik yapida cozulemeyen siralama problemi (§20.1b) yol integralinde
//  ortadan kalkar.
//
//  Konum uzayinda:  G_E(x) ~ (m / (4 pi^2 x)) K_1(m x)
//  Bolge I'inkiyle AYNI fonksiyon.
//
//  m = 0 durumu: payda yalnizca k = q = 0'da sifirlanir — Bolge I'dekiyle ayni
//  tip IR tekilligi, yeni bir sorun degil.
//
//  §21.4 ANA BULGU: IKI BOLGE ORTAK BIR OKLID TEORISININ ANALITIK DEVAMLARI
//  Oklid'e gecildiginde her iki bolgenin imzasi (+,+,+,+) olur ve propagatorler
//  aynidir. OKLID BOLGESINDE IKI TARAF AYIRT EDILEMEZ. Fark yalnizca Lorentz
//  bolgesine geri donerken hangi eksenin donduruldugunde ortaya cikar.
//
//    > D, imzayi degistiren bir donusum degil; ortak Oklid teorisinden HANGI
//    > EKSENDE CIKILACAGINI SECEN operatordur.
//
//  Iki bolge ayri yapilar degil, tek bir yapinin iki dalidir.
//
//  §21.5 KALAN ACIK
//  Vakum problemi (§20.1c) Oklid bolgesinde cozulur — pozitif tanimli cekirdek
//  iyi tanimli bir olcum verir. Ancak Lorentz bolgesine analitik devam
//  yapildiginda Hamiltonyenin vektor olmasi sorunu geri gelir. Yani Bolge II'de
//  HESAP YAPILABILIR, AMA SONUCLARIN PARCACIK YORUMU TANIMSIZDIR. Korelasyon
//  fonksiyonlari hesaplanabilir; "kac parcacik var" sorusu cevaplanamaz.
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class PathIntegral : public Section
    {
    public:
        enum class WickChoice
        {
            AllThreeTimes, // (a) uc zamani birden dondur
            SingleSpace,   // (b) tek uzay eksenini dondur
            Composite      // (c) bileske yon
        };

        // Secilen Wick donusunun urettigi Oklid cekirdegi.
        static double euclideanKernel(WickChoice choice, double c, double mu,
                                      double kSquared, double q);

        // Cekirdek pozitif tanimli mi? (Gauss integrali yakinsar mi?)
        static bool isPositiveDefinite(WickChoice choice, double c, double mu);

        // Oklid propagatoru: 1 / cekirdek — (b) secimi icin.
        static double euclideanPropagator(double c, double mu, double kSquared, double q);

        std::string number() const override { return "§21"; }
        std::string title() const override
        {
            return "Yol integrali, Wick donusu ve ortak Oklid teorisi";
        }
        void run(Report &report) const override;
    };

} // namespace slm
