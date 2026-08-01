#include "quantum/VacuumCasimir.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{

    double VacuumCasimir::casimirEnergyPerArea(double hbar, double c, double separation)
    {
        const double pi = std::numbers::pi;
        return -pi * pi * hbar * c / (720.0 * std::pow(separation, 3));
    }

    double VacuumCasimir::singleSurfaceEnergyDensityScale(double hbar, double c, double distance)
    {
        return hbar * c / std::pow(distance, 4);
    }

    void VacuumCasimir::run(Report &report) const
    {
        const double hbar = 1.0;
        const double c = 1.0;

        report.subsection("§22.1  Parcacik kavrami neden tanimsiz");
        report.line("  Parcacik kavrami uc yapiya dayanir:");
        report.bullet("pozitif/negatif frekans ayrimi      -> tek zaman ekseni gerekir");
        report.bullet("Hamiltonyenin alttan sinirli olmasi -> siralama gerekir");
        report.bullet("Poincare grubunun uniter temsili    -> tek zamanli grup yapisi");
        report.check("Bolge II'de ucu de yok", true);

        report.subsection("§22.2  Ama teori bos degil");
        report.line("  Korelasyon fonksiyonlari <psi(x) psi(y)> Oklid bolgesinde tanimli,");
        report.line("  analitik devamla Lorentz bolgesine tasinabilir.");
        report.conclusion("Bolge II bir PARCACIK teorisi degil, bir KORELASYON teorisidir.");
        report.note("'Kac parcacik var' cevapsiz; 'ne kadar korelasyon var' cevaplanabilir.");
        report.note("Bu, §16'daki 'yorunge yok, cephe var' sonucunun kuantum karsiligi.");

        report.subsection("§22.3  Casimir: tek yuzey");
        report.line("  Sigma'daki pi = 0 kosulu (§9) kuantumda NEUMANN sinir kosulu.");
        report.line("  Tek yansitici yuzey -> ikinci duvar yok -> Casimir etkisi DOGMAZ.");
        report.line("  Yalnizca yuzey yakininda vakum enerji yogunlugu kayiyor:");
        report.line("       z (yuzeye uzaklik)     <T_00(z)> ~ hbar c / z^4");
        for (double z : {1.0, 0.5, 0.1, 0.01})
        {
            report.line(std::format("   {:>20.3g}  {:>24.6g}", z,
                                    singleSurfaceEnergyDensityScale(hbar, c, z)));
        }
        report.check("z -> 0 iken iraksiyor -> renormalizasyon gerekir",
                     singleSurfaceEnergyDensityScale(hbar, c, 0.01) >
                         singleSurfaceEnergyDensityScale(hbar, c, 1.0));

        report.subsection("§22.3b  Casimir: iki yuzey arasinda");
        report.line("  L aralikli iki Sigma yuzeyi -> standart Neumann-Neumann sonucu:");
        report.line("      E/A = -pi^2 hbar c / (720 L^3)");
        report.line("        L            E/A");
        for (double separation : {1.0, 2.0, 5.0, 10.0})
        {
            report.line(std::format("   {:>7.3g}  {:>16.8g}", separation,
                                    casimirEnergyPerArea(hbar, c, separation)));
        }
        report.check("enerji NEGATIF (cekici)", casimirEnergyPerArea(hbar, c, 1.0) < 0.0);
        // L^-3 olcek yasasinin dogrulanmasi: L iki katina cikinca enerji 1/8'e duser.
        report.checkNear("olcek yasasi E ~ L^-3",
                         casimirEnergyPerArea(hbar, c, 2.0) * 8.0 -
                             casimirEnergyPerArea(hbar, c, 1.0),
                         1e-12);

        report.subsection("§22.3c  Degerlendirme");
        report.line("  Sigma, v = c yuzeyidir; laboratuvarda erisilebilir DEGILDIR.");
        report.conclusion("Prensipte var olan ama pratikte olculemeyen bir imza.");
    }

} // namespace slm
