#pragma once

// ============================================================================
//  BlackHoleHorizon — model.md §18 ve §23
// ----------------------------------------------------------------------------
//
//  §18 KARA DELIK UFKUYLA ILISKI
//  Schwarzschild metriginde ufkun icinde dt^2 ve dr^2 terimlerinin isaretleri
//  yer degistirir: r zaman-benzeri, t uzay-benzeri olur. Merkeze dusmek
//  kacinilmaz hale gelir — disarida gelecege ilerlemenin kacinilmaz olmasi gibi.
//
//      |             | Kara delik ufku          | Bu model            |
//      | Degisen     | t ve r, iki koordinat    | Dort koordinat      |
//      | Sonuc imza  | 1+3 kalir                | 3+1 olur            |
//      | Mekanizma   | Yerel, surekli, geometrik| Ani, ayrik (D)      |
//      | Sinir       | Ufuk — tek yonlu gecirgen| Sigma — gecirgen degil|
//
//
//  §23 TAM KARSILASTIRMA
//
//  §23.1 KAC KOORDINAT DONUYOR
//    Ufuk (Schwarzschild, f = 1 - r_s/r):
//      r > r_s: dt zaman-benzeri, dr uzay-benzeri
//      r < r_s: dt uzay-benzeri, dr zaman-benzeri
//      Aci koordinatlari degismez
//      Imza: (+,-,-,-) -> (-,+,-,-), yani HALA 1 zaman + 3 uzay
//    Sigma: dort koordinat birden doner, (1,3) -> (3,1).
//
//  §23.2 GECIRGENLIK FARKININ KAYNAGI
//      |                     | Ufuk                  | Sigma               |
//      | Imza sinifi         | (1,3)->(1,3) DEGISMIYOR| (1,3)->(3,1) DEGISIYOR|
//      | Lorentz yapisi      | Korunuyor             | Degisiyor           |
//      | Normal vektor tipi  | Surekli donuyor       | Sicrayarak degisiyor|
//      | Konjuge momentum    | Surekli, sifir olmak  | Isaret cevirmek     |
//      |                     | zorunda degil         | zorunda -> pi = 0   |
//      | Sonuc               | GECIRGEN              | YANSITICI           |
//
//  §23.3 SUREKLI KOPRU KURULABILIR MI?
//    Denendi. (1,3)'ten (3,1)'e surekli bir interpolasyon, ornegin
//        g(lambda) = diag(1, -cos L, -cos L, -cos L),  det g = -cos^3 L
//    lambda = pi/2'de det g = 0 verir: DEJENERE METRIK. Orada metrik tersi
//    yoktur, alan denklemi tanimsizdir.
//    Bu genel bir sonuctur: iki imza sinifi arasinda dejenere olmayan surekli
//    bir yol yoktur.
//
//  §23.4 SONUC
//    > Kara delik ufku bu modelin "kismi" hali degildir; FARKLI SINIFTA BIR
//    > OLAYDIR.
//  Ufuk imza sinifini korur, bu yuzden gecirgendir. Sigma imza sinifini
//  degistirir, bu yuzden yansiticidir. Aralarinda surekli kopru kurmak dejenere
//  bir nokta gerektirir ve orada da gecis saglanmaz — tikanma yalnizca yer
//  degistirir. Bu, §9'daki yansiticilik sonucunun bagimsiz bir dogrulamasidir.
// ============================================================================

#include "core/Matrix4.h"
#include "core/Section.h"

#include <array>

namespace slm
{

    class BlackHoleHorizon : public Section
    {
    public:
        // Schwarzschild f(r) = 1 - r_s/r
        static double lapse(double r, double schwarzschildRadius);

        // Kosegen Schwarzschild metrigi: diag(f, -1/f, -r^2, -r^2 sin^2(theta))
        static Matrix4 schwarzschildMetric(double r, double schwarzschildRadius, double theta);

        // Kosegen bir metrigin imzasi: (arti sayisi, eksi sayisi, sifir sayisi).
        static std::array<int, 3> signature(const Matrix4 &metric);

        // §23.3'teki interpolasyon: diag(1, -cos L, -cos L, -cos L)
        static Matrix4 interpolatedMetric(double lambda);

        std::string number() const override { return "§18 / §23"; }
        std::string title() const override
        {
            return "Kara delik ufkuyla tam karsilastirma";
        }
        void run(Report &report) const override;
    };

} // namespace slm
