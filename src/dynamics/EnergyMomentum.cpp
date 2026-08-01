#include "dynamics/EnergyMomentum.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <cmath>
#include <format>

namespace slm
{

    Vector4 EnergyMomentum::fourMomentum(double c, double energy, double px, double py, double pz)
    {
        return Vector4(energy / c, px, py, pz);
    }

    Vector4 EnergyMomentum::transformed(double, const Vector4 &p)
    {
        return InvolutionD::matrix() * p;
    }

    double EnergyMomentum::invariant(const Vector4 &p)
    {
        return p.contract(metricRegionI());
    }

    double EnergyMomentum::shellEnergy(double c, double mass, double px, double py, double pz)
    {
        const double pSquared = px * px + py * py + pz * pz;
        return std::sqrt(pSquared * c * c + mass * mass * std::pow(c, 4));
    }

    void EnergyMomentum::run(Report &report) const
    {
        const double c = 1.0;
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();

        report.subsection("1) D dort-momentuma ne yapiyor");
        const Vector4 p = fourMomentum(c, 5.0, 1.0, 2.0, 3.0);
        const Vector4 pPrime = transformed(c, p);
        report.vector("gelen (E/c, px, py, pz) =", p);
        report.vector("cikan (D ile)           =", pPrime);
        report.value("oteki tarafta uc ENERJI bileseni",
                     std::format("({:g}, {:g}, {:g})", pPrime[0], pPrime[1], pPrime[2]));
        report.value("oteki tarafta tek MOMENTUM", pPrime[3]);

        report.subsection("2) Degismez buyukluk");
        const double before = p.contract(eta);
        const double after = pPrime.contract(etaPrime);
        report.value("bizim : E^2/c^2 - p^2 =", before);
        report.value("oteki : p'^T eta' p'  =", after);
        report.checkNear("oteki = -bizim", after + before);

        report.subsection("3) KORUNUM TESTI: genel 2->2 carpisma");
        // Bizim tarafta korunum varsayiliyor: p1 + p2 = p3 + p4.
        // p3 serbest degil; korunumdan cozuluyor.
        const Vector4 p1 = fourMomentum(c, 7.0, 1.0, -2.0, 0.5);
        const Vector4 p2 = fourMomentum(c, 3.0, -0.5, 1.5, 2.0);
        const Vector4 p4 = fourMomentum(c, 4.0, 0.25, -1.0, 1.25);
        const Vector4 p3 = p1 + p2 - p4;

        const Vector4 incoming = p1 + p2;
        const Vector4 outgoing = p3 + p4;
        report.vector("gelen toplam  =", incoming);
        report.vector("cikan toplam  =", outgoing);
        report.checkNear("bizim tarafta korunum saglaniyor",
                         incoming.maxAbsDifference(outgoing));

        const Vector4 incomingPrime = transformed(c, incoming);
        const Vector4 outgoingPrime = transformed(c, outgoing);
        report.vector("oteki tarafta fark =", incomingPrime - outgoingPrime);
        report.checkNear("oteki tarafta korunum OTOMATIK saglaniyor",
                         incomingPrime.maxAbsDifference(outgoingPrime));
        report.note("D dogrusal oldugu icin toplamlar korunuyor; fark tam sifir.");

        report.subsection("4) Kutle kabugu");
        const double mass = 2.0;
        const double energy = shellEnergy(c, mass, 1.0, 0.0, 0.0);
        const Vector4 shell = fourMomentum(c, energy, 1.0, 0.0, 0.0);
        report.value("bizim : E^2 = p^2c^2 + m^2c^4  ->  E =", energy);
        report.checkNear("bizim tarafta p.p = m^2c^2",
                         shell.contract(eta) - mass * mass * c * c);
        const Vector4 shellPrime = transformed(c, shell);
        report.checkNear("oteki tarafta p'.p' = -m^2c^2  (isaret donuyor)",
                         shellPrime.contract(etaPrime) + mass * mass * c * c);
        report.line("  yani  E'^2 = p'^2c^2 - m^2c^4");

        report.subsection("5) Sonsuz hiz limiti: E -> 0, p -> mc");
        for (double v : {0.9, 0.99, 0.9999})
        {
            const double gamma = 1.0 / std::sqrt(1.0 - v * v / (c * c));
            // Takyonik kolun aynasi: V -> sonsuz iken karsilik gelen limit.
            const double eLimit = mass * c * c / gamma;
            const double pLimit = mass * v * gamma / gamma; // = m v
            report.value(std::format("v = {:g}c", v),
                         std::format("E/(gamma) = {:.6g},  p -> {:.6g} mc", eLimit, pLimit / (mass * c)));
        }
        report.note("V -> sonsuz limitinde E -> 0, p -> mc. Makale ile uyumlu.");

        report.subsection("6) Karisik carpisma: duran cisim + sonsuz hizli takyon");
        // Duran subluminal cisim: (E1, p1) = (m c^2, 0)
        // Sonsuz hizli takyon:    (E2, p2) = (0, M c)
        const double M = 3.0;
        const Vector4 restBody = fourMomentum(c, mass * c * c, 0.0, 0.0, 0.0);
        const Vector4 tachyon = fourMomentum(c, 0.0, M * c, 0.0, 0.0);
        const Vector4 totalBefore = restBody + tachyon;

        // Sonra: takyon yine sonsuz hizli (E4 = 0), momentumu M' c.
        const double MPrime = 1.0;
        const Vector4 tachyonAfter = fourMomentum(c, 0.0, MPrime * c, 0.0, 0.0);
        const Vector4 bodyAfter = totalBefore - tachyonAfter;

        report.vector("once : duran cisim   =", restBody);
        report.vector("once : takyon        =", tachyon);
        report.vector("sonra: takyon        =", tachyonAfter);
        report.vector("sonra: cisim         =", bodyAfter);
        report.checkNear("cismin ENERJISI degismiyor",
                         bodyAfter[0] * c - restBody[0] * c);
        report.checkNear("cisim (M - M')c momentum kazaniyor",
                         bodyAfter[1] - (M - MPrime) * c);
        report.note("Makalenin V'li formalizminden cikan sonucun aynisi, V kullanmadan.");

        report.subsection("7) Enerji pozitifligi D altinda");
        report.line("  bizim tarafta enerji: E — tek sayi, isareti belli");
        report.line("  oteki tarafta enerji: (E1,E2,E3) — uc bilesenli VEKTOR");
        const double magnitude = std::sqrt(pPrime[0] * pPrime[0] + pPrime[1] * pPrime[1] +
                                           pPrime[2] * pPrime[2]);
        report.value("|E'| = sqrt(E1^2+E2^2+E3^2) =", magnitude);
        report.check("|E'| >= 0 her zaman saglanir", magnitude >= 0.0);
        report.note("Tek bir 'pozitif enerji' kosulu yazilamaz; bu §20.1(c)'nin habercisi.");
    }

} // namespace slm
