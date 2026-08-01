#pragma once

// ============================================================================
//  MaxwellField — model.md §15 (makale acigi: elektromanyetizma) — kapandi
// ----------------------------------------------------------------------------
//
//  D, Maxwell teorisine uygulandi. Sonuclar makalenin §5'iyle tam uyumlu,
//  ancak tek matris carpimindan cikiyor.
//
//  POTANSIYEL VE AKIM
//      A^mu = (phi/c, A)   ->   A'^mu = (A_z, A_y, A_x, phi/c)
//      j^mu = (rho c, j)   ->   j'^mu = (j_z, j_y, j_x, rho c)
//
//  Elektrik potansiyeli oteki tarafta uzaysal bilesen; yuk yogunlugu ile akim
//  yogunlugu takas. Makale (44) ile ayni.
//
//  ETKILESIM TERIMI
//      A'.j' = -A.j        (sembolik dogrulandi)
//  Makale (45)'te bu isaret degisimini elle not dusuyor; burada D'den turuyor.
//
//  ALAN TENSORU
//      F' = D^T F D altinda elektrik ve manyetik bilesenler yer degistiriyor.
//
//  DEGISMEZ — KRITIK SONUC
//      F_munu F^munu  =  F'_munu F'^munu
//  Tam esitlik. Maxwell Lagrangian'inin kinetik terimi D altinda DEGISMEZ.
//  Yalnizca kaynak terimi isaret ceviriyor:
//
//      L  = -(1/4mu0) F_munu F^munu - A_mu j^mu
//      L' = -(1/4mu0) F'_munu F'^munu + A'_mu j'^mu
//
//  DALGA DENKLEMI VE KORUNUM
//      box A^nu = mu0 j^nu   ->   -box' A'^nu = mu0 j'^nu
//      d_mu j^mu = 0         ->   d'_mu j'^mu = 0   (otomatik)
//
//  DEGERLENDIRME: Model elektromanyetizmayi bozmadan tasiyor ve makalenin
//  sonuclarini bagimsiz bir yoldan yeniden uretiyor. Modelin en guclu
//  dogrulamasi.
// ============================================================================

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    class MaxwellField
    {
    public:
        // F_munu, (ct,x,y,z) sirasinda; python tarafindaki ayni konvansiyon.
        static Matrix4 fieldTensor(double c, double ex, double ey, double ez,
                                   double bx, double by, double bz);

        // F' = D^T F D
        static Matrix4 transformedFieldTensor(const Matrix4 &f);

        // F_munu F^munu ~ trace(F G F G)
        static double invariant(const Matrix4 &f, const Matrix4 &metric);

        // Dort-potansiyel A^mu = (phi/c, Ax, Ay, Az)
        static Vector4 fourPotential(double c, double phi, double ax, double ay, double az);

        // Dort-akim j^mu = (rho c, jx, jy, jz)
        static Vector4 fourCurrent(double c, double rho, double jx, double jy, double jz);
    };

    class MaxwellSection : public Section
    {
    public:
        std::string number() const override { return "§15"; }
        std::string title() const override
        {
            return "Elektromanyetizma D altinda (makale acigi C) — kapandi";
        }
        void run(Report &report) const override;
    };

} // namespace slm
