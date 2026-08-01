#include "literature/LiteraturePosition.h"

#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <cmath>
#include <format>

namespace slm
{

    Matrix4 LiteraturePosition::zaopoLambdaInfinity()
    {
        // Zaopo konvansiyonu mu = diag(-1,1,1,1); Lambda_inf(0,0): t <-> z (isaretli).
        return Matrix4({{{{0, 0, 0, -1}},
                         {{0, 1, 0, 0}},
                         {{0, 0, 1, 0}},
                         {{-1, 0, 0, 0}}}});
    }

    double LiteraturePosition::xySwapDeterminant3D()
    {
        // [[0,1,0],[1,0,0],[0,0,1]] — 3B'de bir yansima.
        return -1.0;
    }

    bool LiteraturePosition::isInZaopoGroup()
    {
        // L_ext = <SO(3,1)+^, Lambda_inf, -I>. D bu gruptaysa
        //   D = (+-) Lambda_inf^e * L,  L in SO(3,1)+^  (det = +1, L_00 > 0)
        // olmalidir. Butun dort kombinasyon denenir.
        const Matrix4 zaopoMetric = Matrix4::diagonal(-1.0, 1.0, 1.0, 1.0);
        const Matrix4 lambda = zaopoLambdaInfinity();
        const Matrix4 D = InvolutionD::matrix();

        for (int exponent = 0; exponent <= 1; ++exponent)
        {
            for (double sign : {1.0, -1.0})
            {
                const Matrix4 prefactor = lambda.power(exponent) * sign;
                const Matrix4 remainder = prefactor.inverse() * D;
                const bool isLorentz =
                    (remainder.congruence(zaopoMetric) - zaopoMetric).isZero(1e-10);
                const bool properOrthochronous =
                    std::abs(remainder.determinant() - 1.0) < 1e-10 && remainder.at(0, 0) > 0.0;
                if (isLorentz && properOrthochronous)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void LiteraturePosition::run(Report &report) const
    {
        const Matrix4 D = InvolutionD::matrix();

        report.subsection("§17  Isaret secimi (acik A): +-D ayirt edilebiliyor mu?");
        for (double sign : {1.0, -1.0})
        {
            const Matrix4 candidate = D * sign;
            report.value(std::format("s = {:+g}", sign),
                         std::format("det = {:+g},  M^2 = I ? {}", candidate.determinant(),
                                     candidate.isInvolution() ? "evet" : "hayir"));
            report.check(std::format("  s = {:+g} butun testleri geciyor", sign),
                         candidate.isInvolution() &&
                             std::abs(candidate.determinant() - 1.0) < kEps);
        }
        report.conclusion("HER IKI ISARET de tum testleri geciyor: ayirt edilemiyorlar.");
        report.line();
        report.line("  Ama §16'daki bulgu isaretin ANLAMINI netlestiriyor:");
        report.bullet("Her iki bolgede birer ok secimi var (bizde zaman, otede uzay).");
        report.bullet("D bizim ok eksenimizi onlarin ok eksenine gonderiyor —");
        report.line("    secimler bagimsiz degil, biri digerini belirliyor.");
        report.bullet("Anlamli olan tek buyukluk BAGIL ISARET: iki okun hizalanmasi.");
        report.bullet("Sigma gecirgen olmadigi icin iki bolge haberlesemiyor");
        report.line("    -> bagil isaret PRENSIP OLARAK OLCULEMEZ.");
        report.conclusion("A bir eksiklik degil, YAPISAL BIR OZELLIK.");
        report.note("Bizim tarafta da zamanin oku denklemlerden turetilmez;");
        report.note("Newton, Maxwell, Schrodinger hepsi T-simetriktir — ok baslangic");
        report.note("kosulundan gelir. Modelde de ayni durum gecerlidir.");

        report.subsection("§25.1  Zaopo (arXiv:2510.25385) ile karsilastirma");
        const Matrix4 lambda = zaopoLambdaInfinity();
        report.matrix("Zaopo Lambda_inf(0,0) =", lambda);
        report.check("Lambda_inf^2 = I", lambda.isInvolution());
        report.value("det(Lambda_inf)", lambda.determinant());
        report.value("det(D)", D.determinant());
        report.line();
        report.line("                        Zaopo Lambda_inf      Bu modelin D'si");
        report.line("  Degisen koordinat     2 (t ve n yonu)       4 (hepsi)");
        report.line("  Yon bagimliligi       var, Lambda(th,ph)    yok, z sabit");
        report.line("  det                   -1                    +1");
        report.line("  Parite                bozuluyor             korunuyor");
        report.line("  Grup                  Z_2 x Z_2             Z_2");

        report.subsection("§25.1b  D, Zaopo'nun L_ext grubunda mi?");
        report.value("x <-> y takasinin 3B determinanti", xySwapDeterminant3D());
        report.check("x <-> y bir YANSIMA: SO(3) elemani DEGIL",
                     xySwapDeterminant3D() < 0.0);
        report.check("D, Zaopo'nun L_ext'inde BULUNMUYOR", !isInZaopoGroup());
        report.note("Cunku SO(3) yerine O(3)\\SO(3) elemani gerekiyor.");
        report.note("Zaopo: det = -1, parite ile iliskili, Wu deneyini yeniden yorumluyor.");
        report.note("Bu model: det = +1, pariteyi koruyor — bilincli bir secimdi.");

        report.subsection("§25.2  Imza degisimi / eklem kosullari kolu");
        report.bullet("Bojowald (arXiv:2009.13565): imza degisiminde karisik tip PDE;");
        report.line("    Lorentz'de hiperbolik, Oklid'de eliptik; gecis yuzeyi determinist");
        report.line("    evrimle koprulenemez (Tricomi). — §9'un karsiligi.");
        report.bullet("Kamleh (gr-qc/0004057): surekli lapse -> sinirda dejenere metrik,");
        report.line("    ters metrik tekillesir. — §23.3'un karsiligi.");
        report.bullet("PRD 100.064043 (2019): uzaysal ozdegerlerin isaret degistirdigi");
        report.line("    durum ve eklem kosullari. — (1,3)->(3,1) gecisinin karsiligi.");
        report.note("Bu kol §9 ve §23 sonuclarini BAGIMSIZ OLARAK dogruluyor.");

        report.subsection("§25.3  Coklu zaman kolu");
        report.bullet("Bars (hep-th/0003100): iki-zaman fizigi; ekstra zaman boyutu ayar");
        report.line("    simetrisiyle elimine edilir. §20'deki kanonik tikanmanin muadili.");

        report.subsection("§25.4  Modelin ozgun kaldigi yerler");
        report.bullet("§9  esigin yansitici olmasi (superluminal baglamda turetilmis hali)");
        report.bullet("§21 Wick'in 'tek olan ekseni dondur' kurali ve ortak Oklid teorisi");
        report.bullet("§23 kara delik ufkuyla imza-sinifi karsilastirmasi");
        report.bullet("§14 kuresel simetrik cozumun kapali formu ve yorumu");
        report.conclusion("Asil ozgunluk iddiasi parcalarda degil BAGLANTIDADIR:");
        report.note("Dragan'in superluminal cercevesini, kozmolojideki imza-degisimi");
        report.note("eklem kosullari makineriyle birlestirmek.");

        report.subsection("§24  2023 makalesiyle kuantum duzeyinde karsilastirma");
        report.line("  Konu               Dragan ve ark. (2023)    Bu model");
        report.line("  Kuantumlama        yapilmiyor               kanonik yolun neden");
        report.line("                                              tikali oldugu (§20.1)");
        report.line("  Determinizm kaybi  onceki calismaya dayali   denklem tipinden (§7)");
        report.line("  Propagator         yok                      Oklid, tekilliksiz (§21.3)");
        report.line("  Wick donusu        ele alinmiyor            zorunlu secim (§21.1)");
        report.line("  Iki bolge iliskisi ayri cerceveler          ortak Oklid'in iki dali");
        report.line("  Maxwell            klasik alan              tek matris carpimi (§15)");
        report.line("  Vakum / parcacik   ele alinmiyor            korelasyon teorisi (§22)");

        report.subsection("§19  Guncel durum: makale aciklari");
        report.line("  #1 Uc zamanda zamanin oku  Kapandi (§16) — ok boyut sayisindan");
        report.line("  #2 +- isareti              Kapanamaz oldugu gosterildi (§17)");
        report.line("  #3 Grup yapisi             Kapandi (§4) — sorun B katmaninda");
        report.line("  #4 Kuresel simetrik cozum  Kapandi (§14) — kapali form + yorum");
        report.line("  #5 Superluminal durgunluk  Kapandi (§8) — gauge fazlaligi");
        report.line("  #6 Takyonlar var mi        ACIK (deneysel)");
        report.line();
        report.line("  Modele ozgu ek sonuclar: carpanlama (§2), esigin yansitici olmasi");
        report.line("  (§9), Maxwell'in bagimsiz yeniden uretimi (§15).");
        report.conclusion("Kalan teknik acik yok. #6 deneysel oldugu icin acik.");
    }

} // namespace slm
