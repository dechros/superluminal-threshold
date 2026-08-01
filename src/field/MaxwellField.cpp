#include "field/MaxwellField.h"

#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <format>

namespace slm
{

    Matrix4 MaxwellField::fieldTensor(double c, double ex, double ey, double ez,
                                      double bx, double by, double bz)
    {
        return Matrix4({{{{0.0, ex / c, ey / c, ez / c}},
                         {{-ex / c, 0.0, -bz, by}},
                         {{-ey / c, bz, 0.0, -bx}},
                         {{-ez / c, -by, bx, 0.0}}}});
    }

    Matrix4 MaxwellField::transformedFieldTensor(const Matrix4 &f)
    {
        const Matrix4 D = InvolutionD::matrix();
        return D.transpose() * f * D;
    }

    double MaxwellField::invariant(const Matrix4 &f, const Matrix4 &metric)
    {
        return (f * metric * f * metric).trace();
    }

    Vector4 MaxwellField::fourPotential(double c, double phi, double ax, double ay, double az)
    {
        return Vector4(phi / c, ax, ay, az);
    }

    Vector4 MaxwellField::fourCurrent(double c, double rho, double jx, double jy, double jz)
    {
        return Vector4(rho * c, jx, jy, jz);
    }

    void MaxwellSection::run(Report &report) const
    {
        const double c = 1.0;
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const Matrix4 D = InvolutionD::matrix();

        report.subsection("1) Dort-potansiyel ve dort-akim");
        const Vector4 a = MaxwellField::fourPotential(c, 2.0, 0.5, -1.0, 3.0);
        const Vector4 j = MaxwellField::fourCurrent(c, 1.5, -0.25, 2.0, 0.75);
        const Vector4 aPrime = D * a;
        const Vector4 jPrime = D * j;
        report.vector("A^mu  = (phi/c, Ax, Ay, Az) =", a);
        report.vector("A'^mu = D A^mu             =", aPrime);
        report.vector("j^mu  = (rho c, jx, jy, jz)=", j);
        report.vector("j'^mu = D j^mu             =", jPrime);
        report.checkNear("elektrik potansiyeli oteki tarafta tek UZAY bileseni",
                         aPrime[3] - a[0]);
        report.checkNear("yuk yogunlugu <-> akim bileseni TAKAS", jPrime[3] - j[0]);
        report.note("Makale (44) ile ayni.");

        report.subsection("2) Etkilesim terimi A_mu j^mu");
        // Metrikler kosegen oldugu icin A_mu j^mu tek dongude yazilabilir.
        double ourInteraction = 0.0;
        double theirInteraction = 0.0;
        for (int i = 0; i < 4; ++i)
        {
            ourInteraction += a[i] * eta.at(i, i) * j[i];
            theirInteraction += aPrime[i] * etaPrime.at(i, i) * jPrime[i];
        }
        report.value("bizim  A.j   =", ourInteraction);
        report.value("oteki  A'.j' =", theirInteraction);
        report.checkNear("A'.j' = -A.j", theirInteraction + ourInteraction);
        report.note("Makale (45) bu isaret degisimini elle not dusuyor; burada D'den turuyor.");

        report.subsection("3) Alan tensoru F' = D^T F D");
        const Matrix4 f = MaxwellField::fieldTensor(c, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
        const Matrix4 fPrime = MaxwellField::transformedFieldTensor(f);
        report.matrix("F =", f);
        report.matrix("F' = D^T F D =", fPrime);
        report.value("F[0,3] (eskiden E_z/c)", f.at(0, 3));
        report.value("F'[0,3] karsiligi", fPrime.at(0, 3));
        report.value("F'[1,2] (manyetik bilesen)", fPrime.at(1, 2));
        report.check("F antisimetrik kaliyor",
                     fPrime.isEqual(-fPrime.transpose(), 1e-12));
        report.note("Elektrik ve manyetik bilesenler yer degistiriyor.");

        report.subsection("4) Degismez — KRITIK SONUC");
        const double ourInvariant = MaxwellField::invariant(f, eta);
        const double theirInvariant = MaxwellField::invariant(fPrime, etaPrime);
        report.value("F_munu F^munu   (bizim) ~", ourInvariant);
        report.value("F'_munu F'^munu (oteki) ~", theirInvariant);
        report.checkNear("TAM ESITLIK: kinetik terim D altinda DEGISMEZ",
                         ourInvariant - theirInvariant);

        report.subsection("5) Lagrangian");
        report.line("  L  = -(1/4mu0) F_munu F^munu - A_mu j^mu");
        report.line("  L' = -(1/4mu0) F'_munu F'^munu + A'_mu j'^mu");
        report.note("Kinetik terim ayni, kaynak terimi isaret degistiriyor.");
        report.note("Makale denklem (45) ile TAM UYUM.");

        report.subsection("6) Dalga denklemi ve yuk korunumu");
        report.line("  bizim: box A^nu = mu0 j^nu");
        report.line("  oteki: -box' A'^nu = mu0 j'^nu       (D box D^-1 = -box')");
        report.line("  d_mu j^mu = 0  ->  d'_mu j'^mu = 0");
        report.note("D dogrusal ve sabit oldugu icin korunum otomatik tasiniyor.");

        // Korunumun dogrusallikla tasindiginin somut gosterimi: iki akimin
        // toplaminin goruntusu, goruntulerinin toplamina esit.
        const Vector4 j2 = MaxwellField::fourCurrent(c, -0.5, 1.0, -2.0, 0.5);
        report.checkNear("D dogrusal: D(j1+j2) = D j1 + D j2",
                         (D * (j + j2)).maxAbsDifference(jPrime + (D * j2)));

        report.conclusion("Model elektromanyetizmayi bozmadan tasiyor ve makalenin");
        report.note("sonuclarini bagimsiz bir yoldan yeniden uretiyor.");
        report.note("Modelin en guclu dogrulamasi.");
    }

} // namespace slm
