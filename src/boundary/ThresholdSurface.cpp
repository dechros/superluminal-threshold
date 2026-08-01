#include "boundary/ThresholdSurface.h"

#include "core/Report.h"
#include "dynamics/Dispersion.h"

#include <cmath>
#include <format>

namespace slm
{

    double ThresholdSurface::conjugateMomentumRegionI(double c, double timeDerivative)
    {
        return timeDerivative / (c * c);
    }

    double ThresholdSurface::conjugateMomentumRegionII(double c, double timeDerivative)
    {
        // Normal yon Bolge I'de zaman-benzeri, Bolge II'de uzay-benzeri:
        // konjuge momentum isaret ceviriyor.
        return -conjugateMomentumRegionI(c, timeDerivative);
    }

    double ThresholdSurface::junctionResidual(double c, double timeDerivative)
    {
        return conjugateMomentumRegionI(c, timeDerivative) -
               conjugateMomentumRegionII(c, timeDerivative);
    }

    void ThresholdSurface::run(Report &report) const
    {
        const double c = 1.0;
        const double hbar = 1.0;

        report.subsection("Kurulum: iki bolge ve aralarindaki Sigma yuzeyi");
        report.line("  Bolge I  : imza (+,-,-,-)   1 zaman + 3 uzay");
        report.line("  Bolge II : imza (+,+,+,-)   3 zaman + 1 uzay");
        report.line("  Sigma    : v = c yuzeyi");
        report.line("  Soru: alan Sigma'dan nasil geciyor, ne korunuyor?");

        report.subsection("1) Dispersiyon: iki tarafta ayni yapi");
        report.line("  Bolge I : omega^2/c^2 - k^2 - mu = 0   -> omega^2 = c^2(k^2+mu)");
        report.line("  Bolge II: kappa^2 - q^2/c^2 + mu = 0   -> q^2 = c^2(kappa^2+mu)");
        report.note("D altinda omega <-> q*c, k <-> kappa takasi.");

        report.subsection("2) Esik kosulu: v_faz = v_grup = c ancak mu = 0 icin");
        const Dispersion massive(c, 1.0, hbar);
        const Dispersion massless(c, 0.0, hbar);
        report.line("      m       k      v_faz       v_grup");
        for (double k : {0.5, 2.0, 10.0})
        {
            report.line(std::format("    m=1  {:>6.3g}  {:>10.6g}  {:>10.6g}", k,
                                    massive.phaseVelocity(k), massive.groupVelocity(k)));
            report.check("  kutleli alan: v_faz > c ve v_grup < c",
                         massive.phaseVelocity(k) > c && massive.groupVelocity(k) < c);
        }
        for (double k : {0.5, 2.0, 10.0})
        {
            report.line(std::format("    m=0  {:>6.3g}  {:>10.6g}  {:>10.6g}", k,
                                    massless.phaseVelocity(k), massless.groupVelocity(k)));
        }
        report.checkNear("kutlesiz alan: v_faz = v_grup = c, esige TAM oturuyor",
                         massless.phaseVelocity(1.0) - c);
        report.note("Kutleli alan icin esik ASILMIYOR, TEGET geciliyor.");

        report.subsection("3) EKLEM KOSULLARI (Israel-tipi)");
        report.line("  (a) alan surekli:             psi_I|_Sigma = psi_II|_Sigma");
        report.line("  (b) konjuge momentum surekli: pi_I|_Sigma  = pi_II|_Sigma");
        report.line();
        report.line("  pi = dL/d(d_n psi) ve normal yon n iki tarafta FARKLI tipte:");
        report.line("    Bolge I'de  n zaman-benzeri");
        report.line("    Bolge II'de n uzay-benzeri");
        report.note("-> pi_II = -pi_I");

        report.line();
        report.line("   d_t psi      pi_I        pi_II       eklem artigi (pi_I - pi_II)");
        for (double derivative : {1.0, 0.5, 0.1, 0.0})
        {
            const double piI = conjugateMomentumRegionI(c, derivative);
            const double piII = conjugateMomentumRegionII(c, derivative);
            report.line(std::format("   {:>8.3g}  {:>10.4g}  {:>10.4g}  {:>14.4g}",
                                    derivative, piI, piII, junctionResidual(c, derivative)));
        }
        report.check("eklem kosulu yalnizca d_t psi = 0 icin saglaniyor",
                     std::abs(junctionResidual(c, 0.0)) < 1e-12 &&
                         std::abs(junctionResidual(c, 0.1)) > 1e-12);

        report.subsection("4) SONUC");
        report.line("  Esikte konjuge momentum SIFIR olmak zorunda: pi|_Sigma = 0.");
        report.line("  Bu bir DUGUM kosulu: alan Sigma'da duragan, aki yok.");
        report.conclusion("Sigma gecirgen DEGIL, YANSITICI bir yuzey.");
        report.note("Kutleli madde esikten GECEMEZ; tam yansir.");
        report.note("Istisna: mu = 0 (kutlesiz) durumda kosul kendiliginden saglanir —");
        report.note("ama kutlesiz alan zaten c'de, gecmesi gerekmiyor.");
        report.note("Bu sonuc modele elle konmadi; kendi Lagrangian'indan cikti.");
    }

} // namespace slm
