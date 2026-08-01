#include "field/KleinGordonField.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double KleinGordonField::regionIGrowthCoefficient(double c, double mu, double kSquared)
    {
        // (1/c^2) f'' = -(k^2 + mu) f   ->   f'' = -c^2 (k^2 + mu) f
        return -c * c * (kSquared + mu);
    }

    double KleinGordonField::regionIIGrowthCoefficient(double c, double mu,
                                                       double kTransverseSquared, double q)
    {
        // f'' = ( k2^2 + k3^2 - q^2/c^2 + mu ) f
        return kTransverseSquared - q * q / (c * c) + mu;
    }

    double KleinGordonField::regionIResidual(double c, double mu, double omega, double kSquared)
    {
        return omega * omega / (c * c) - kSquared - mu;
    }

    double KleinGordonField::regionIIResidual(double c, double mu, double kSquared, double q)
    {
        return kSquared - q * q / (c * c) + mu;
    }

    void KleinGordonField::run(Report &report) const
    {
        const double c = 1.0;
        const double mass = 1.0;
        const double hbar = 1.0;
        const double mu = (mass * c / hbar) * (mass * c / hbar);

        report.subsection("1) Iki Lagrangian ve Euler-Lagrange sonuclari");
        report.line("  BIZIM TARAF (Klein-Gordon):");
        report.line("    L  = 1/2 [ (d_t phi)^2/c^2 - (grad phi)^2 - mu phi^2 ]");
        report.line("    EL -> (1/c^2) d_t^2 phi - laplace(phi) + mu phi = 0");
        report.line();
        report.line("  D UYGULANMIS HALI (Bolge II):");
        report.line("    L' = 1/2 [ (d_t1 psi)^2 + (d_t2 psi)^2 + (d_t3 psi)^2");
        report.line("               - (d_r psi)^2/c^2 + mu psi^2 ]");
        report.line("    EL -> (d^2_t1+d^2_t2+d^2_t3) psi - (1/c^2) d^2_r psi - mu psi = 0");
        report.note("Iki denklem D ile birbirine geciyor: box -> -box'.");

        report.subsection("2) Duzlem dalga cozumleri her iki denklemi sagliyor mu?");
        for (double kSquared : {0.0, 1.0, 9.0, 100.0})
        {
            const double omega = c * std::sqrt(kSquared + mu);
            report.checkNear(std::format("Bolge I : k^2 = {:g}, omega = {:.6g} -> denklem artigi",
                                         kSquared, omega),
                             regionIResidual(c, mu, omega, kSquared));

            const double q = c * std::sqrt(kSquared + mu);
            report.checkNear(std::format("Bolge II: kappa^2 = {:g}, q = {:.6g} -> denklem artigi",
                                         kSquared, q),
                             regionIIResidual(c, mu, kSquared, q));
        }
        report.note("Bolge II'de q her zaman REEL: r ekseninde salinim var, sonumlenme yok.");

        report.subsection("3) DETERMINIZM: Bolge I baslangic deger problemi");
        report.line("  Modu exp(i k.x) f(t) alirsak:  f'' = -c^2 (k^2 + mu) f");
        report.line("      k^2        katsayi        cozum tipi");
        for (double kSquared : {0.0, 1.0, 1e2, 1e6, 1e12})
        {
            const double coefficient = regionIGrowthCoefficient(c, mu, kSquared);
            report.line(std::format("   {:>9.3g}  {:>14.6g}   {}", kSquared, coefficient,
                                    coefficient < 0.0 ? "salinim (sinirli)" : "PATLAMA"));
            report.check("  katsayi NEGATIF -> mod sinirli, evrim kararli",
                         coefficient < 0.0);
        }
        report.note("Hiperbolik denklem, Cauchy problemi IYI KONUMLANMIS -> DETERMINIST.");

        report.subsection("4) DETERMINIZM KAYBI: Bolge II Cauchy problemi");
        report.line("  t1'i evrim parametresi alirsak, geriye (t2,t3,r) kaliyor.");
        report.line("  t2 ve t3 ZAMAN-BENZERI oldugu icin bu yuzey uzay-benzeri DEGIL.");
        report.line("  Modu exp(i(k2 t2 + k3 t3 + q r)) f(t1) alirsak:");
        report.line("      f'' = (k2^2 + k3^2 - q^2/c^2 + mu) f");
        report.line();
        report.line("   k_T^2 (=k2^2+k3^2)   q      katsayi     buyume orani exp(s t1)");
        const double qFixed = 1.0;
        bool sawBlowUp = false;
        double lastRate = 0.0;
        for (double kTransverseSquared : {0.0, 1.0, 1e2, 1e6, 1e12})
        {
            const double coefficient = regionIIGrowthCoefficient(c, mu, kTransverseSquared, qFixed);
            const double rate = coefficient > 0.0 ? std::sqrt(coefficient) : 0.0;
            report.line(std::format("   {:>16.3g}  {:>5.3g}  {:>11.6g}  {:>12.6g}",
                                    kTransverseSquared, qFixed, coefficient, rate));
            if (coefficient > 0.0)
            {
                sawBlowUp = true;
            }
            lastRate = rate;
        }
        report.check("Bolge II'de POZITIF katsayili modlar var (exponansiyel buyume)", sawBlowUp);
        report.check("buyume orani k_T -> sonsuz iken SINIRSIZ", lastRate > 1e5);
        report.conclusion("Baslangic verisindeki keyfi kucuk bir bozulma, keyfi buyuk bir");
        report.note("cozum degisimi verir: Cauchy problemi HADAMARD anlaminda KOTU KONUMLANMIS.");
        report.note("Makale bunu argumanla one suruyordu; burada denklem tipinden cikiyor.");

        report.subsection("5) §16  Noether yukleri (Bolge II)");
        report.line("  L' dort koordinattan da acikca bagimsiz -> dort oteleme simetrisi:");
        report.bullet("uc 'enerji' bileseni  (t1, t2, t3 otelemeleri)");
        report.bullet("tek 'momentum'        (r otelemesi)");
        report.line("  L' uc zamanda O(3) altinda degismez -> uc korunan 'zamansal aci");
        report.line("  momentumu', bizim uzaysal aci momentumumuzun aynasi.");

        report.subsection("6) §16  Roller tam tersine donmus");
        report.line("                         Bolge I (bizim)     Bolge II");
        report.line("  Serbest hareket        uzayda, uc yonde    UC ZAMANDA, serbestce");
        report.line("  Tek yonlu zorunluluk   zamanda             TEK UZAY EKSENINDE");
        report.line("  O(3) donme simetrisi   uzaysal             zamansal");
        report.line("  Nesne                  yorunge (egri)      cephe (3B hiperyuzey)");
        report.conclusion("Bolge II'de ZAMANIN OKU YOKTUR; onun yerine bir UZAY OKU vardir.");
        report.note("Ok, ilgili boyutun TEK olmasinin sonucudur.");
        report.note("Uc boyutlu olan eksen kumesi uzay gibi davranir, yon ayrimi kalkar.");
        report.note("Ok entropiden degil, BOYUT SAYISINDAN cikar — makale acigi #1'in cevabi.");
    }

} // namespace slm
