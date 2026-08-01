#pragma once

// ============================================================================
//  InvolutionD — model.md §2, §3, §4, §6
// ----------------------------------------------------------------------------
//
//  §1 MOTIVASYON
//  -------------
//  Dragan ve ark. (Class. Quantum Grav. 40 (2023) 025013) ozel goreliligi 1+3
//  boyutta superluminal gozlemcilere genisletiyor. Sonuc: superluminal
//  cercevede uzay-zaman metrigi 3+1 boyutlu hale geliyor (uc zaman, bir uzay).
//
//  Makalenin acik biraktigi noktalar:
//    #1 Uc zamanda zamanin oku    -> "yorumsal zorluklar" deyip geciyor
//    #2 Donusumdeki +- isareti    -> "belirlenemez", konvansiyonla eksi
//    #3 Grup yapisi               -> en kucuk iceren grup SL(4,R), simetri
//                                    grubu olamiyor
//    #4 Kuresel simetrik cozum    -> "bilinen hicbir gosterime karsilik
//                                    gelmiyor"
//    #5 Superluminal durgunluk    -> sonsuz dunya cizgisi demeti, "ilginc
//                                    muamma"
//    #6 Takyonlar var mi          -> acik soru
//
//  Bu calisma, makalenin superboost'unu carpanlarina ayirarak 3 ve 5'i
//  kapatiyor, 2'yi kismen indirgiyor, ve esik bolgesi icin bir sonuc
//  turetiyor.
//
//
//  §2 TEMEL IDDIA: CARPANLAMA
//  --------------------------
//  Makalenin superboost'u iki bagimsiz parcanin carpimi:
//
//        M(V) = D * B(c^2/V)
//
//    D          — sabit, parametresiz involusyon. Imza degisimini tek basina
//                 yapiyor.
//    B(c^2/V)   — siradan subluminal Lorentz boostu. V bilgisini tasiyor.
//
//  Bu ayrim makalede yok ve sonuclari belirleyici.
//
//
//  §3 D MATRISI
//  ------------
//  Koordinat sirasi (ct, x, y, z) -> (t1, t2, t3, r):
//
//        D = [0 0 0 1]
//            [0 0 1 0]
//            [0 1 0 0]
//            [1 0 0 0]
//
//  Yani (ct, x, y, z) -> (z, y, x, ct).
//
//  Dogrulanan ozellikler:
//    Imza donusumu   D^T eta' D = -eta, yani s'^2 = -s^2
//    Isik konisi     s^2 = 0 -> s'^2 = 0, dort farkli yonde dogrulandi
//    Involusyon      D^2 = I — iki gecis basa donduruyor
//    Determinant     +1 — parite bozulmuyor
//    Grup            Z_2
//    V bagimliligi   Yok
//
//  Burada eta = diag(1,-1,-1,-1), eta' = diag(1,1,1,-1).
//
//
//  §4 GRUP KAPANMA SORUNU (makale acigi #3)
//  ----------------------------------------
//  Dogrulanan:
//    D^2 = I         -> <D> = Z_2, kapali
//    M(V)^2 != I     -> makalenin donusumu kapali degil
//
//  SONUC: SL(4,R) sorunu D'den degil, B katmanindan kaynaklaniyor. D*B'yi tek
//  bir "superboost" olarak ele almak kapanmayi bozuyor. Ayristirildiginda iki
//  parca da duzgun: D bir Z_2 ayrik simetrisi, B ise SO(1,3) icinde.
//
//  Yapi: <D> |x SO(1,3) benzeri bir yari-dogrudan carpim. Kapanma sorunu,
//  D B D^-1 konjugasyonunun boost tipini korumamasindan cikiyor — makalenin
//  sikayet ettigi yon-bagimli genlesmeler bu konjugasyonun urunu.
//
//
//  §6 HIZ KAVRAMI (kismi — hiz donusumu)
//  -------------------------------------
//  Hiz donusumu: v' = c^2 / v. Isik hizi sabit nokta; subluminal <-> superluminal.
//  (Dispersiyon tarafi Dispersion sinifinda ele aliniyor.)
// ============================================================================

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    class InvolutionD : public Section
    {
    public:
        // Ayrik involusyon D: (ct, x, y, z) -> (z, y, x, ct).
        static Matrix4 matrix();

        // x yonunde hiz u ile subluminal Lorentz boostu.
        static Matrix4 lorentzBoost(double c, double u);

        // Makalenin superboostu: M(V) = D * B(c^2/V),  V > c.
        static Matrix4 superboost(double c, double V);

        // v hiziyla x yonunde giden bir cismin oteki taraftaki hizi: v' = c^2/v.
        static double transformVelocity(double c, double v);

        std::string number() const override { return "§2-4"; }
        std::string title() const override
        {
            return "Carpanlama, D matrisi ve grup kapanma sorunu";
        }
        void run(Report &report) const override;
    };

} // namespace slm
