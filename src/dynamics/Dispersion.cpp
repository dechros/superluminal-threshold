#include "dynamics/Dispersion.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    Dispersion::Dispersion(double c, double mass, double hbar)
        : c_(c), mass_(mass), hbar_(hbar) {}

    double Dispersion::mu() const
    {
        const double value = mass_ * c_ / hbar_;
        return value * value;
    }

    double Dispersion::angularFrequency(double k) const
    {
        return c_ * std::sqrt(k * k + mu());
    }

    double Dispersion::phaseVelocity(double k) const
    {
        return angularFrequency(k) / k;
    }

    double Dispersion::groupVelocity(double k) const
    {
        // d/dk [ c sqrt(k^2 + mu) ] = c k / sqrt(k^2 + mu)
        return c_ * k / std::sqrt(k * k + mu());
    }

    double Dispersion::spatialFrequency(double kappa) const
    {
        return c_ * std::sqrt(kappa * kappa + mu());
    }

    double Dispersion::gradientMagnitude(double kappa) const
    {
        return c_ * kappa / std::sqrt(kappa * kappa + mu());
    }

    void DispersionSection::run(Report &report) const
    {
        const double c = 1.0;
        const double hbar = 1.0;
        const double mass = 1.0;
        const Dispersion massive(c, mass, hbar);
        const Dispersion massless(c, 0.0, hbar);

        report.subsection("1) Bizim tarafta hiz nereden geliyor");
        report.line("  omega(k) = c*sqrt(k^2 + mu),  mu = (mc/hbar)^2");
        report.value("mu =", massive.mu());
        report.line();
        report.line("      k        omega(k)      v_faz       v_grup     v_faz*v_grup");
        for (double k : {0.1, 0.5, 1.0, 2.0, 10.0, 100.0})
        {
            const double vPhase = massive.phaseVelocity(k);
            const double vGroup = massive.groupVelocity(k);
            report.line(std::format("   {:>7.4g}  {:>11.6g}  {:>10.6g}  {:>10.6g}  {:>12.10g}",
                                    k, massive.angularFrequency(k), vPhase, vGroup, vPhase * vGroup));
            report.checkNear("  v_faz * v_grup = c^2", vPhase * vGroup - c * c, 1e-12);
        }
        report.note("Hiz TUREV bir buyukluk: dispersiyon bagintisindan cikiyor.");
        report.note("Faz hizi bizim tarafta bile c'yi asiyor; grup hizi asmiyor.");

        report.subsection("2) Sinir davranisi");
        report.value("v_grup, k -> 0   limiti", massive.groupVelocity(1e-8));
        report.value("v_grup, k -> oo  limiti", massive.groupVelocity(1e12));
        report.check("k -> 0'da grup hizi 0'a gidiyor", massive.groupVelocity(1e-8) < 1e-6);
        report.check("k -> oo'da grup hizi c'ye gidiyor",
                     std::abs(massive.groupVelocity(1e12) - c) < 1e-12);

        report.subsection("3) Kutlesiz durum: dispersiyon yok");
        report.value("mu = 0 -> v_faz  =", massless.phaseVelocity(3.7));
        report.value("mu = 0 -> v_grup =", massless.groupVelocity(3.7));
        report.checkNear("ikisi de c; hiz tanimi belirsizlesmiyor",
                         massless.phaseVelocity(3.7) - massless.groupVelocity(3.7));

        report.subsection("4) Oteki tarafta ayni turev: q(kappa)");
        report.line("  q(kappa) = c*sqrt(kappa^2 + mu)  <- AYNI fonksiyon, D ile takas");
        report.line("  Ama 'hiz' = yol/zaman idi; simdi ZAMAN uc boyutlu.");
        report.line("  dr/dt tanimsiz: paydada vektor var.");
        report.line();
        report.line("  bizim : v = d(omega)/dk       skaler/skaler -> SKALER");
        report.line("  otede : dq/d(kappa)           skaler/VEKTOR -> GRADYAN, yani VEKTOR");
        for (double kappa : {0.1, 1.0, 10.0, 1000.0})
        {
            report.value(std::format("|dq/dkappa|, kappa = {:g}", kappa),
                         massive.gradientMagnitude(kappa));
            report.check("  buyuklugu < c (karsi tarafta da hiz siniri var)",
                         massive.gradientMagnitude(kappa) < c);
        }
        report.checkNear("kappa -> oo limitinde -> c",
                         massive.gradientMagnitude(1e12) - c);

        report.subsection("5) Iki tarafin dispersiyonu ayni yapida");
        for (double k : {0.3, 1.0, 4.0})
        {
            report.checkNear(std::format("omega(k)/c = q(kappa)/c, k = kappa = {:g}", k),
                             massive.angularFrequency(k) - massive.spatialFrequency(k));
        }
        report.note("D altinda omega <-> q*c, k <-> kappa takasi.");

        report.subsection("6) Durgun cisim, karsi tarafta");
        report.value("kappa = 0 -> q =", massive.spatialFrequency(0.0));
        report.value("beklenen mc^2/hbar =", mass * c * c / hbar);
        report.checkNear("q(0) = mc^2/hbar != 0",
                         massive.spatialFrequency(0.0) - mass * c * c / hbar);
        report.note("Orada duran cisim bile r ekseninde ilerler —");
        report.note("bizim taraftaki 'duran cisim zamanda ilerler' ifadesinin AYNASI.");

        report.conclusion("Hiz skaler olmaktan cikip YONELIME donusuyor.");
        report.note("'Ne kadar hizli' sorusu 'hangi yonelimde' sorusuna donusuyor.");
        report.note("D'de V'nin gorunmemesi eksiklik degil: V zaten temel degildi.");
        report.note("V bilgisi B boostunda, yani uc-zaman uzayindaki yonelimde yasiyor.");
    }

} // namespace slm
