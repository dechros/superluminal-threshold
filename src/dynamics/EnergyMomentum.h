#pragma once

// ============================================================================
//  EnergyMomentum — model.md §5
// ----------------------------------------------------------------------------
//
//  §5 ENERJI VE MOMENTUM
//  ---------------------
//  D dort-momentuma uygulandiginda:
//
//      (E/c, px, py, pz)  ->  (pz, py, px, E/c)
//
//  Oteki tarafta enerji uc bilesenli, momentum tek bilesenli.
//
//  DEGISMEZ:     E^2/c^2 - p^2  ->  -(E^2/c^2 - p^2)
//                Koordinatlardaki davranisla tutarli.
//
//  KUTLE KABUGU: E^2 = p^2c^2 + m^2c^4   ->   E'^2 = p'^2c^2 - m^2c^4
//
//  KORUNUM:      Genel 2->2 carpismada bizim tarafta korunum saglaniyorsa
//                oteki tarafta da otomatik saglaniyor (fark tam sifir).
//                D dogrusal oldugu icin toplamlar korunuyor.
//
//  KARISIK CARPISMA: Duran subluminal cisim + sonsuz hizli takyon -> cisim
//                momentum kazaniyor, enerjisi degismiyor. Makalenin V'li
//                formalizminden cikan sonucun aynisi, V kullanmadan.
//
//  SONSUZ HIZ LIMITI: E -> 0, p -> mc. Makale ile uyumlu.
//
//  Ek not (enerji pozitifligi): bizim tarafta enerji tek sayidir, isareti
//  bellidir. Oteki tarafta "enerji" uc bilesenli bir vektordur; tek bir
//  "pozitif enerji" kosulu yazilamaz, buyuklugu |E'| = sqrt(E1^2+E2^2+E3^2)
//  kullanilmalidir ve bu her zaman >= 0'dir. Bu gozlem §20.1(c)'deki
//  "kararli vakum yok" sonucunun klasik habercisidir.
// ============================================================================

#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    class EnergyMomentum : public Section
    {
    public:
        // Bolge I dort-momentumu: (E/c, px, py, pz).
        static Vector4 fourMomentum(double c, double energy, double px, double py, double pz);

        // Bolge II karsiligi: D uygulanmis dort-momentum.
        static Vector4 transformed(double c, const Vector4 &p);

        // E^2/c^2 - p^2 (Bolge I metrigi ile).
        static double invariant(const Vector4 &p);

        // Kutle kabugundan enerji: E = sqrt(p^2c^2 + m^2c^4).
        static double shellEnergy(double c, double mass, double px, double py, double pz);

        std::string number() const override { return "§5"; }
        std::string title() const override { return "Enerji ve momentum takasi"; }
        void run(Report &report) const override;
    };

} // namespace slm
