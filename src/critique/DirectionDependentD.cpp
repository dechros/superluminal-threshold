#include "critique/DirectionDependentD.h"

#include "core/Report.h"
#include "core/Vector4.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{
    namespace
    {

        struct UnitVector
        {
            double x, y, z;
        };

        UnitVector direction(double theta, double phi)
        {
            return {std::sin(theta) * std::cos(phi),
                    std::sin(theta) * std::sin(phi),
                    std::cos(theta)};
        }

        // 4x4 blok kurulumu: [[0, s*n^T],[s*n, block]]
        Matrix4 assemble(const UnitVector &n, double sign, const double block[3][3])
        {
            Matrix4 m = Matrix4::zero();
            const double components[3] = {n.x, n.y, n.z};
            for (int i = 0; i < 3; ++i)
            {
                m.at(0, i + 1) = sign * components[i];
                m.at(i + 1, 0) = sign * components[i];
                for (int j = 0; j < 3; ++j)
                {
                    m.at(i + 1, j + 1) = block[i][j];
                }
            }
            return m;
        }

    } // namespace

    Matrix4 DirectionDependentD::candidate(Form form, double theta, double phi)
    {
        const UnitVector n = direction(theta, phi);
        const double components[3] = {n.x, n.y, n.z};

        double projector[3][3]{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                projector[i][j] = components[i] * components[j];
            }
        }

        double block[3][3]{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                const double identity = (i == j) ? 1.0 : 0.0;
                block[i][j] = (form == Form::MinusIdentity) ? (projector[i][j] - identity)
                                                            : (identity - projector[i][j]);
            }
        }

        const double sign = (form == Form::Zaopo) ? -1.0 : 1.0;
        return assemble(n, sign, block);
    }

    Matrix4 DirectionDependentD::householder(double theta, double phi)
    {
        const UnitVector n = direction(theta, phi);
        const double components[3] = {n.x, n.y, n.z};

        double block[3][3]{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                const double identity = (i == j) ? 1.0 : 0.0;
                block[i][j] = identity - 2.0 * components[i] * components[j];
            }
        }
        return assemble(n, 1.0, block);
    }

    void DirectionDependentD::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();
        const double pi = std::numbers::pi;

        struct Named
        {
            const char *label;
            Form form;
        };
        const Named forms[] = {
            {"A Zaopo   [[0,-n],[-n, I-P]]", Form::Zaopo},
            {"B         [[0, n],[ n, I-P]]", Form::PlusIdentity},
            {"C         [[0, n],[ n, P-I]]", Form::MinusIdentity}};

        report.subsection("Aday formlar, yon n'ye bagli (Lake itirazi #4'e cevap denemesi)");
        report.line("  n = (sin(th)cos(ph), sin(th)sin(ph), cos(th)),  P = n n^T");
        report.line();

        for (const Named &named : forms)
        {
            report.line(std::format("  {}", named.label));
            bool alwaysInvolution = true;
            bool everFlips = false;
            double determinant = 0.0;

            const double angles[][2] = {
                {0.0, 0.0},              // z ekseni
                {pi / 2.0, 0.0},         // x ekseni
                {pi / 2.0, pi / 2.0},    // y ekseni
                {0.7, 1.3}};             // genel yon

            for (const auto &angle : angles)
            {
                const Matrix4 m = candidate(named.form, angle[0], angle[1]);
                determinant = m.determinant();
                if (!m.isInvolution(1e-10))
                {
                    alwaysInvolution = false;
                }
                if (m.flipsMetric(eta, eta, 1e-10))
                {
                    everFlips = true;
                }
            }

            report.value("    M^2 = I her yonde?", alwaysInvolution ? "evet" : "hayir");
            report.value("    det (genel yon)", determinant);
            report.value("    eta -> -eta (gercek imza cevirme)?", everFlips ? "EVET" : "hayir");
            report.check("    gercek imza cevirmesi YOK", !everFlips);
            report.check("    det = -1 (parite bozuluyor)", std::abs(determinant + 1.0) < 1e-9);
            report.line();
        }

        report.subsection("Zaopo Lambda_inf araligi koruyor mu, ceviriyor mu?");
        const Matrix4 zaopo = candidate(Form::Zaopo, 0.0, 0.0); // n = z
        report.matrix("Lambda_inf(z) =", zaopo);

        // (a) Yalnizca t ve n'nin gerdigi 2B alt uzayda kalan bir olay.
        const Vector4 inSector(0.3, 0.0, 0.0, 0.9);
        const Vector4 inSectorImage = zaopo * inSector;
        report.value("2B sektorde  s^2  =", inSector.contract(eta));
        report.value("2B sektorde  s'^2 =", inSectorImage.contract(eta));
        report.checkNear("(t,n) sektorunde s'^2 = -s^2: orada GERCEKTEN ceviriyor",
                         inSectorImage.contract(eta) + inSector.contract(eta), 1e-10);

        // (b) n'ye dik yonde kalan bir olay: blok I - P orada birim gibi davraniyor.
        const Vector4 perpendicular(0.0, -1.7, 2.4, 0.0);
        const Vector4 perpendicularImage = zaopo * perpendicular;
        report.value("dik yonde    s^2  =", perpendicular.contract(eta));
        report.value("dik yonde    s'^2 =", perpendicularImage.contract(eta));
        report.checkNear("dik yonlerde s'^2 = s^2: orada HIC cevirmiyor",
                         perpendicularImage.contract(eta) - perpendicular.contract(eta), 1e-10);

        // (c) Genel bir olay: ne korunuyor ne ceviriliyor.
        const Vector4 event(0.3, -1.7, 2.4, 0.9);
        const Vector4 image = zaopo * event;
        const double before = event.contract(eta);
        const double after = image.contract(eta);
        report.value("genel yonde  s^2  =", before);
        report.value("genel yonde  s'^2 =", after);
        report.check("genel olayda s'^2 != s^2 (aralik KORUNMUYOR)",
                     std::abs(after - before) > 1e-10);
        report.check("genel olayda s'^2 != -s^2 (isaret de CEVRILMIYOR)",
                     std::abs(after + before) > 1e-10);
        report.conclusion("Lambda_inf araligi yalnizca (t,n) sektorunde ceviriyor.");

        report.subsection("Isaret cevirme Zaopo'nun (8) numarali KONJUGASYON kosulu");
        const Matrix4 zaopoMetric = Matrix4::diagonal(-1.0, 1.0, 1.0, 1.0);
        const Matrix4 conjugated = zaopo * zaopoMetric * zaopo.inverse();
        const double conjugationResidual =
            (conjugated + zaopoMetric).maxAbsDifference(Matrix4::zero());
        const double congruenceResidual =
            (zaopo.congruence(zaopoMetric) + zaopoMetric).maxAbsDifference(Matrix4::zero());
        report.value("A mu A^-1 + mu artigi", conjugationResidual);
        report.value("A^T mu A  + mu artigi", congruenceResidual);
        report.check("konjugasyon kosulu da (1+3)'te TAM saglanmiyor",
                     conjugationResidual > 1e-9);
        report.check("kongruans kosulu SAGLANMIYOR", congruenceResidual > 1e-9);
        report.note("Konjugasyon kosulu metrik BILESENLERININ yeniden siralanmasidir;");
        report.note("(1+1) sektorunde tutar, (1+3)'te dik yonlerde tutmaz —");
        report.note("Lake'in itiraz ettigi sey tam olarak budur.");

        report.subsection("Householder tipi aday: [[0, n^T],[n, I - 2P]]");
        const Matrix4 house = householder(0.7, 1.3);
        report.matrix("M =", house);
        report.value("det", house.determinant());
        report.value("M^2 - I artigi", (house * house).maxAbsDifference(Matrix4::identity()));
        report.check("M^2 = I DEGIL: involusyon bile olmuyor", !house.isInvolution(1e-10));
        report.check("gercek imza cevirmesi YOK", !house.flipsMetric(eta, eta, 1e-10));

        report.subsection("Sonuc");
        report.line("  Zaopo'nun Lambda_inf'i araligi yalnizca t ve n'nin gerdigi 2B alt");
        report.line("  uzayda cevirir; dik yonlerde cevirmez.");
        report.conclusion("Lake'in '(1+1) sektorunde gercek cevirme olur, (1+3)'te olmaz'");
        report.note("tespiti dogrulanmis oldu. Yon-bagimlilik ile gercek imza cevirmesi");
        report.note("ayni anda elde edilemiyor (bkz. §26.3, Sylvester).");
    }

} // namespace slm
