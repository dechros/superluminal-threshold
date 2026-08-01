#include "horizon/BlackHoleHorizon.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>
#include <stdexcept>

namespace slm
{

    double BlackHoleHorizon::lapse(double r, double schwarzschildRadius)
    {
        return 1.0 - schwarzschildRadius / r;
    }

    Matrix4 BlackHoleHorizon::schwarzschildMetric(double r, double schwarzschildRadius,
                                                  double theta)
    {
        const double f = lapse(r, schwarzschildRadius);
        const double sinTheta = std::sin(theta);
        return Matrix4::diagonal(f, -1.0 / f, -r * r, -r * r * sinTheta * sinTheta);
    }

    std::array<int, 3> BlackHoleHorizon::signature(const Matrix4 &metric)
    {
        std::array<int, 3> counts{0, 0, 0}; // {arti, eksi, sifir}
        for (int i = 0; i < 4; ++i)
        {
            const double value = metric.at(i, i);
            if (value > kEps)
            {
                ++counts[0];
            }
            else if (value < -kEps)
            {
                ++counts[1];
            }
            else
            {
                ++counts[2];
            }
        }
        return counts;
    }

    Matrix4 BlackHoleHorizon::interpolatedMetric(double lambda)
    {
        const double value = -std::cos(lambda);
        return Matrix4::diagonal(1.0, value, value, value);
    }

    void BlackHoleHorizon::run(Report &report) const
    {
        const double schwarzschildRadius = 1.0;
        const double theta = std::numbers::pi / 2.0;

        report.subsection("§23.1  Ufuk: kac koordinat donuyor");
        report.line("  f(r) = 1 - r_s/r ;  ds^2 = f c^2 dt^2 - dr^2/f - r^2 dOmega^2");
        report.line("       r         f(r)      imza (arti, eksi)   yorum");
        for (double r : {3.0, 2.0, 1.5, 0.9, 0.5})
        {
            const Matrix4 metric = schwarzschildMetric(r, schwarzschildRadius, theta);
            const auto counts = signature(metric);
            const double f = lapse(r, schwarzschildRadius);
            report.line(std::format("   {:>6.3g}  {:>9.4g}   ({}, {})            {}", r, f,
                                    counts[0], counts[1],
                                    f > 0.0 ? "dt zaman-benzeri" : "dt UZAY-benzeri, dr ZAMAN-benzeri"));
            report.check("  imza sinifi (1,3) olarak KALIYOR",
                         counts[0] == 1 && counts[1] == 3);
        }
        report.note("Aci koordinatlari degismiyor; degisen yalnizca t ve r.");
        report.note("Imza: (+,-,-,-) -> (-,+,-,-), yani HALA 1 zaman + 3 uzay.");

        report.subsection("§23.1b  Sigma: dort koordinat birden");
        const auto regionICounts = signature(metricRegionI());
        const auto regionIICounts = signature(metricRegionII());
        report.value("Bolge I  imzasi (arti, eksi)",
                     std::format("({}, {})", regionICounts[0], regionICounts[1]));
        report.value("Bolge II imzasi (arti, eksi)",
                     std::format("({}, {})", regionIICounts[0], regionIICounts[1]));
        report.check("Sigma'da imza SINIFI degisiyor: (1,3) -> (3,1)",
                     regionICounts[0] == 1 && regionIICounts[0] == 3);

        report.subsection("§23.2  Gecirgenlik farkinin kaynagi");
        report.line("                        Ufuk                    Sigma");
        report.line("  Imza sinifi           (1,3)->(1,3) DEGISMIYOR (1,3)->(3,1) DEGISIYOR");
        report.line("  Lorentz yapisi        korunuyor               degisiyor");
        report.line("  Normal vektor tipi    surekli donuyor         sicrayarak degisiyor");
        report.line("  Konjuge momentum      surekli, sifir olmak    isaret cevirmek");
        report.line("                        zorunda degil           zorunda -> pi = 0");
        report.line("  Sonuc                 GECIRGEN                YANSITICI");

        report.subsection("§23.2b  Ufukta f surekli sifirdan geciyor");
        report.line("  f(r) surekli, f(r_s) = 0. Gecis SUREKLI bir limit.");
        for (double r : {1.1, 1.01, 1.001, 0.999, 0.99, 0.9})
        {
            report.line(std::format("   r = {:<8.5g} f = {:>11.4g}", r,
                                    lapse(r, schwarzschildRadius)));
        }
        report.checkNear("f(r_s) = 0 (surekli gecis)", lapse(1.0, schwarzschildRadius));
        report.note("Sigma'da ise D ayrik (Z_2): ara durum YOK, gecis SICRAMA.");

        report.subsection("§23.3  Surekli kopru kurulabilir mi?");
        report.line("  Interpolasyon: g(L) = diag(1, -cos L, -cos L, -cos L)");
        report.line("  det g(L) = -cos^3(L)");
        report.line("       lambda       det g       imza (arti, eksi, sifir)");
        const double pi = std::numbers::pi;
        for (double lambda : {0.0, pi / 4.0, pi / 2.0, 3.0 * pi / 4.0, pi})
        {
            const Matrix4 metric = interpolatedMetric(lambda);
            const auto counts = signature(metric);
            report.line(std::format("   {:>10.6g}  {:>11.4g}   ({}, {}, {})", lambda,
                                    metric.determinant(), counts[0], counts[1], counts[2]));
        }
        const Matrix4 degenerate = interpolatedMetric(pi / 2.0);
        report.checkNear("lambda = pi/2'de det g = 0: DEJENERE METRIK",
                         degenerate.determinant(), 1e-12);

        bool inverseFails = false;
        try
        {
            (void)degenerate.inverse();
        }
        catch (const std::domain_error &)
        {
            inverseFails = true;
        }
        report.check("dejenere noktada metrik tersi YOK -> alan denklemi tanimsiz",
                     inverseFails);
        report.note("lambda = pi'de imza (+,+,+,+) olur: 4 zaman, istedigimiz DEGIL.");
        report.conclusion("Iki imza sinifi arasinda dejenere olmayan surekli bir yol YOKTUR.");

        report.subsection("§23.4  Sonuc");
        report.line("  Ufuk imza sinifini KORUR, bu yuzden GECIRGENDIR.");
        report.line("  Sigma imza sinifini DEGISTIRIR, bu yuzden YANSITICIDIR.");
        report.conclusion("Kara delik ufku bu modelin 'kismi' hali degil; FARKLI SINIFTA");
        report.note("bir olaydir. Surekli kopru dejenere bir nokta gerektirir ve orada da");
        report.note("gecis saglanmaz — tikanma yalnizca yer degistirir.");
        report.note("Bu, §9'daki yansiticilik sonucunun BAGIMSIZ bir dogrulamasidir.");
    }

} // namespace slm
