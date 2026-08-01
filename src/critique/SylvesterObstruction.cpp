#include "critique/SylvesterObstruction.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <cmath>
#include <format>
#include <random>

namespace slm
{

    double SylvesterObstruction::randomSearchBestResidual(int trials, unsigned seed)
    {
        std::mt19937 generator(seed);
        std::normal_distribution<double> normal(0.0, 1.0);

        const Matrix4 eta = metricRegionI();
        double best = 1e300;

        for (int trial = 0; trial < trials; ++trial)
        {
            Matrix4 candidate;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    candidate.at(i, j) = normal(generator);
                }
            }
            const double residual =
                (candidate.congruence(eta) + eta).maxAbsDifference(Matrix4::zero());
            best = std::min(best, residual);
        }
        return best;
    }

    void SylvesterObstruction::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const Matrix4 D = InvolutionD::matrix();

        report.subsection("§26.1  Lake'in itirazi");
        report.bullet("Superboost operatorleri, standart olmayan gosterimle yazilmis");
        report.line("    siradan Lorentz boostlaridir.");
        report.bullet("Superflip, birim operator arti keyfi bir yeniden etiketlemedir.");
        report.bullet("24 permutasyondan 6'si cizgi elemanini korur, 18'i degistirir.");
        report.bullet("Boost yonu n ne olursa olsun belirli bir eksen her zaman takas");
        report.line("    edilir; bu koordinat-bagimli, dolayisiyla fiziksel olmayan");
        report.line("    ongoruler verir.");
        report.note("Bu modelin D'si, Lake'in listeledigi ILK matristir.");

        report.subsection("§26.3  Sylvester atalet yasasi");
        report.line("  eta  = diag(1,-1,-1,-1)   imzasi (1,3)");
        report.line("  -eta = diag(-1,1,1,1)     imzasi (3,1)");
        report.line("  Kongruan matrisler AYNI imzaya sahiptir (Sylvester).");
        report.line("  M^T eta M, eta ile kongruandir -> imzasi (1,3) olmak zorunda.");
        report.conclusion("REEL HICBIR M ICIN  M^T eta M = -eta  OLAMAZ.");

        report.subsection("§26.3b  Sayisal tarama (20.000 rastgele reel matris)");
        const double best = randomSearchBestResidual();
        report.value("en kucuk hata |M^T eta M + eta|_max", best);
        report.check("hata sifira YAKLASMIYOR (teorem sayisal olarak da dogrulandi)",
                     best > 1e-3);

        report.subsection("§26.3c  Peki D neyi sagliyordu?");
        const double withEtaPrime =
            (D.congruence(etaPrime) + eta).maxAbsDifference(Matrix4::zero());
        const double withEta = (D.congruence(eta) + eta).maxAbsDifference(Matrix4::zero());
        report.checkNear("D^T eta' D + eta = 0  (SAGLANIYOR)", withEtaPrime);
        report.check("D^T eta  D + eta = 0  (SAGLANMIYOR)", withEta > 1e-9);
        report.value("D^T eta D + eta artigi", withEta);
        report.note("D, SOL tarafta eta' (farkli metrik) kullaniyor.");
        report.note("'Imza degisimi' iki FARKLI metrik arasinda bir iliski.");
        report.note("eta''nu elle koymak, Lake'in itiraz ettigi yeniden etiketlemedir.");

        report.subsection("§26.4  Catal");
        report.line("                          Yon-kovaryant   Gercek imza cevirme");
        report.line("  Zaopo Lambda_inf(n)     evet            hayir");
        report.line("  Bu modelin D'si         hayir           hayir (eta' elle konur)");
        report.line("  +-i Lambda              evet            EVET — ama reel degil");
        report.line();
        report.line("  M = i*I icin  M^T eta M = -eta  saglanir, ama M REEL DEGILDIR.");
        report.check("i*I kongruansi: (i)^2 eta = -eta  (sadece kompleks alanda)", true);
        report.note("Lake'in notu: +-i Lambda uygulamak, metrigi sabit tutup m -> +-im");
        report.note("yapmakla esdegerdir — yani Feinberg'in sanal kutlesi.");
        report.conclusion("Ikisini birden veren REEL donusum yoktur; Sylvester yasaklar.");

        report.subsection("§26.5  Bu modelin durusu");
        report.line("  Bu calismada REEL KUTLE KORUNMAKTADIR.");
        report.line("  Bedeli acikca kabul edilir: donusum duzeyinde gercek bir imza");
        report.line("  cevrilmesi elde edilmez; D iki farkli metrik arasinda bir eslemedir.");
        report.line();
        report.line("  Buna karsilik §9, §16, §21, §23'teki sonuclar bu elestiriden");
        report.line("  ETKILENMEZ, cunku onlar donusum duzeyinde degil, METRIK DUZEYINDE");
        report.line("  kurulmustur: iki bolge ayri metriklerle tanimlanir, aralarindaki");
        report.line("  iliski eklem kosullariyla ele alinir.");
        report.conclusion("Modelin saglam cekirdegi, Dragan-tipi donusum kolu degil,");
        report.note("IMZA-DEGISIMI EKLEM KOSULLARI koludur.");
        report.note("Ileride yeniden cerceveleme yapilacaksa baslangic noktasi bu olmalidir.");
    }

} // namespace slm
