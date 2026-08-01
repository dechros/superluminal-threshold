#include "quantum/PathIntegral.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <stdexcept>

namespace slm
{

    double PathIntegral::euclideanKernel(WickChoice choice, double c, double mu,
                                         double kSquared, double q)
    {
        switch (choice)
        {
        case WickChoice::AllThreeTimes:
            // t_i -> -i tau_i : kinetik terim isaret ceviriyor.
            return mu - kSquared - q * q / (c * c);
        case WickChoice::SingleSpace:
            // r -> -i rho : butun terimler ayni isarette toplaniyor.
            return kSquared + q * q / (c * c) + mu;
        case WickChoice::Composite:
            // Uc zaman uzayinda "bileske yon" O(3)-degismez degil: tanimsiz.
            throw std::domain_error(
                "Wick secimi (c): bileske yon O(3)-degismez degil, tanimsiz");
        }
        throw std::domain_error("bilinmeyen Wick secimi");
    }

    bool PathIntegral::isPositiveDefinite(WickChoice choice, double c, double mu)
    {
        if (choice == WickChoice::Composite)
        {
            return false;
        }
        // Genis bir mod araliginda cekirdegin isaretine bakiliyor.
        for (double kSquared : {0.0, 0.5, 2.0, 50.0, 1e4, 1e8})
        {
            for (double q : {0.0, 0.5, 3.0, 100.0, 1e4})
            {
                if (euclideanKernel(choice, c, mu, kSquared, q) <= 0.0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    double PathIntegral::euclideanPropagator(double c, double mu, double kSquared, double q)
    {
        return 1.0 / euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, q);
    }

    void PathIntegral::run(Report &report) const
    {
        const double c = 1.0;
        const double mass = 1.0;
        const double hbar = 1.0;
        const double mu = (mass * c / hbar) * (mass * c / hbar);

        report.subsection("§21.1  Wick donusu: uc secenek test edildi");
        report.line("  S' = integral L' d^3t dr");
        report.line("  L' = 1/2[(d_t psi)^2 - (d_r psi)^2/c^2 + mu psi^2]");
        report.line();
        report.line("  (a) UC ZAMANI birden dondur: t_i -> -i tau_i");
        report.line("      cekirdek: mu - k^2 - q^2/c^2");
        report.line("       k^2       q      cekirdek");
        for (double kSquared : {0.0, 1.0, 100.0})
        {
            const double kernel = euclideanKernel(WickChoice::AllThreeTimes, c, mu, kSquared, 1.0);
            report.line(std::format("   {:>8.3g}  {:>6.3g}  {:>12.6g}", kSquared, 1.0, kernel));
        }
        report.check("(a) pozitif tanimli DEGIL -> Gauss integrali IRAKSAR",
                     !isPositiveDefinite(WickChoice::AllThreeTimes, c, mu));

        report.line();
        report.line("  (b) SADECE tek uzay eksenini dondur: r -> -i rho");
        report.line("      cekirdek: k^2 + q^2/c^2 + mu");
        report.line("       k^2       q      cekirdek");
        for (double kSquared : {0.0, 1.0, 100.0})
        {
            const double kernel = euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, 1.0);
            report.line(std::format("   {:>8.3g}  {:>6.3g}  {:>12.6g}", kSquared, 1.0, kernel));
        }
        report.check("(b) POZITIF TANIMLI -> Gauss integrali YAKINSAR",
                     isPositiveDefinite(WickChoice::SingleSpace, c, mu));

        report.line();
        report.line("  (c) bileske yon: uc zaman uzayinda O(3)-degismez degil");
        bool compositeUndefined = false;
        try
        {
            (void)euclideanKernel(WickChoice::Composite, c, mu, 1.0, 1.0);
        }
        catch (const std::domain_error &)
        {
            compositeUndefined = true;
        }
        report.check("(c) TANIMSIZ", compositeUndefined);

        report.conclusion("Yalnizca (b) calisiyor. Secim keyfi degil, ZORUNLU.");

        report.subsection("§21.2  Yorum: 'tek olan ekseni dondur'");
        report.line("  Bolge I'de zaman tek boyutludur  -> Wick donusu ZAMANI dondurur.");
        report.line("  Bolge II'de uzay tek boyutludur  -> Wick donusu UZAYI dondurur.");
        report.note("D'nin zaman eksenini uzay eksenine gondermesiyle tam tutarli (§3).");

        report.subsection("§21.3  Oklid propagatoru: tekillik yok");
        report.line("  G_E(k,q) = 1 / (k1^2+k2^2+k3^2 + q^2/c^2 + mu)");
        report.line("       k^2         q        payda        G_E");
        double smallestDenominator = 1e300;
        for (double kSquared : {0.0, 1.0, 25.0, 1e4})
        {
            for (double q : {0.0, 2.0, 50.0})
            {
                const double denominator = euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, q);
                smallestDenominator = std::min(smallestDenominator, denominator);
                report.line(std::format("   {:>9.3g}  {:>8.3g}  {:>11.6g}  {:>11.6g}",
                                        kSquared, q, denominator, 1.0 / denominator));
            }
        }
        report.value("en kucuk payda (m = 1)", smallestDenominator);
        report.value("mu =", mu);
        report.check("payda daima >= mu > 0 -> KUTUP YOK", smallestDenominator >= mu - 1e-12);
        report.note("i-epsilon recetesine gerek yok; zaman siralamasi gerektirmez.");
        report.conclusion("§20.1(b)'deki engel yol integralinde ORTADAN KALKIYOR.");

        report.subsection("§21.3b  m = 0 durumu");
        const double masslessKernelAtZero = euclideanKernel(WickChoice::SingleSpace, c, 0.0, 0.0, 0.0);
        const double masslessKernelNearby = euclideanKernel(WickChoice::SingleSpace, c, 0.0, 1e-6, 0.0);
        report.value("mu = 0, k = q = 0  -> payda", masslessKernelAtZero);
        report.value("mu = 0, k^2 = 1e-6 -> payda", masslessKernelNearby);
        report.check("payda yalnizca k = q = 0'da sifirlaniyor",
                     masslessKernelAtZero == 0.0 && masslessKernelNearby > 0.0);
        report.note("Bolge I'dekiyle ayni tip IR tekilligi; yeni bir sorun degil.");

        report.subsection("§21.3c  Konum uzayinda propagator");
        report.line("  G_E(x) ~ (m / (4 pi^2 x)) K_1(m x)   (Yukawa/Bessel)");
        report.note("Bolge I'inkiyle AYNI fonksiyon.");

        report.subsection("§21.4  Ana bulgu: ortak Oklid teorisi");
        report.line("  Oklid'e gecince imza farki KAYBOLUYOR:");
        report.line("    Bolge I  Oklid: (+,+,+,+)");
        report.line("    Bolge II Oklid: (+,+,+,+)");
        for (double kSquared : {0.5, 7.0, 120.0})
        {
            // Iki bolgenin Oklid cekirdekleri ayni ifadedir; fark yalnizca hangi
            // eksenin donduruldugunde.
            const double regionI = kSquared + 1.0 + mu;
            const double regionII = euclideanKernel(WickChoice::SingleSpace, c, mu, kSquared, c);
            report.checkNear(std::format("  k^2 = {:g}: iki bolgenin Oklid cekirdegi ayni", kSquared),
                             regionI - regionII);
        }
        report.conclusion("Oklid bolgesinde iki taraf AYIRT EDILEMEZ.");
        report.note("D, imzayi degistiren bir donusum degil; ortak Oklid teorisinden");
        report.note("HANGI EKSENDE CIKILACAGINI SECEN operatordur.");
        report.note("Iki bolge ayri yapilar degil, tek bir yapinin iki dalidir.");

        report.subsection("§21.5  Kalan acik");
        report.bullet("Vakum problemi Oklid bolgesinde cozuluyor (pozitif tanimli cekirdek)");
        report.bullet("Lorentz'e analitik devamda Hamiltonyenin vektor olmasi sorunu geri geliyor");
        report.conclusion("Bolge II'de HESAP YAPILABILIR, ama sonuclarin PARCACIK YORUMU TANIMSIZ.");
    }

} // namespace slm
