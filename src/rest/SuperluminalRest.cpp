#include "rest/SuperluminalRest.h"

#include "core/Report.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <numbers>

namespace slm
{
    namespace
    {

        // Uc boyutlu donme: z-y-z Euler acilariyla, blok-diag(R,1) icine gomulur.
        Matrix4 embed(const double r[3][3])
        {
            Matrix4 out = Matrix4::zero();
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    out.at(i, j) = r[i][j];
                }
            }
            out.at(3, 3) = 1.0;
            return out;
        }

    } // namespace

    Vector4 SuperluminalRest::restFourMomentum(double c, double mass,
                                               double s1, double s2, double s3)
    {
        return Vector4(mass * c * s1, mass * c * s2, mass * c * s3, 0.0);
    }

    Matrix4 SuperluminalRest::timeRotation(double alpha, double beta, double gamma)
    {
        const double ca = std::cos(alpha), sa = std::sin(alpha);
        const double cb = std::cos(beta), sb = std::sin(beta);
        const double cg = std::cos(gamma), sg = std::sin(gamma);

        // Rz(alpha) Ry(beta) Rz(gamma)
        const double r[3][3] = {
            {ca * cb * cg - sa * sg, -ca * cb * sg - sa * cg, ca * sb},
            {sa * cb * cg + ca * sg, -sa * cb * sg + ca * cg, sa * sb},
            {-sb * cg, sb * sg, cb}};
        return embed(r);
    }

    Matrix4 SuperluminalRest::timeReflection(int axis)
    {
        double r[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        r[axis][axis] = -1.0;
        return embed(r);
    }

    void SuperluminalRest::run(Report &report) const
    {
        const double c = 1.0;
        const double mass = 1.0;
        const Matrix4 etaPrime = metricRegionII();

        report.subsection("Sorun: superluminal 'durgun' cerceve neden tek degil");
        report.line("  Makale: p' = (mcs, 0), her s yonu icin ayri dunya cizgisi demeti.");
        report.line("  Makale bunu 'ilginc muamma' diye biraiyor.");

        report.subsection("1) Kutle kabugu kosulu s'yi birim kureye kilitliyor");
        const double s3 = 1.0 / std::sqrt(3.0);
        const Vector4 rest = restFourMomentum(c, mass, s3, s3, s3);
        report.vector("durgun dort-momentum p' =", rest);
        report.value("p'^T eta' p' =", rest.contract(etaPrime));
        report.checkNear("p'.p' = m^2c^2 (s1^2+s2^2+s3^2) = m^2c^2",
                         rest.contract(etaPrime) - mass * mass * c * c);
        report.note("Kabuk kosulu: s1^2+s2^2+s3^2 = 1, yani s BIRIM KURE (S^2) uzerinde.");

        report.subsection("2) Durgunlugu koruyan grup: O(3)");
        report.line("  eta' = diag(+1,+1,+1,-1) icinde ilk uc slot AYNI isaretli");
        report.line("  -> onlari koruyan grup O(3) (uc boyutlu donmeler + yansimalar)");

        const double pi = std::numbers::pi;
        const Matrix4 rotations[] = {
            timeRotation(0.3, 0.0, 0.0),
            timeRotation(0.0, 0.7, 0.0),
            timeRotation(0.4, 1.1, -0.6),
            timeRotation(pi / 3.0, pi / 4.0, pi / 5.0)};

        for (const Matrix4 &rotation : rotations)
        {
            report.checkNear("  metrigi koruyor: R^T eta' R = eta'",
                             (rotation.congruence(etaPrime) - etaPrime).maxAbsDifference(Matrix4::zero()),
                             1e-12);
            const Vector4 image = rotation * rest;
            report.checkNear("  durgunlugu bozmuyor: son bilesen 0 kaliyor", image[3]);
            report.checkNear("  kutle kabugu korunuyor",
                             image.contract(etaPrime) - rest.contract(etaPrime), 1e-12);
        }

        for (int axis = 0; axis < 3; ++axis)
        {
            const Matrix4 reflection = timeReflection(axis);
            report.checkNear(std::format("  yansima (eksen {}): metrigi koruyor, det = {:g}",
                                         axis, reflection.determinant()),
                             (reflection.congruence(etaPrime) - etaPrime).maxAbsDifference(Matrix4::zero()));
        }

        report.subsection("3) O(3) etkisi S^2 uzerinde GECISLI");
        // Herhangi bir s'yi herhangi bir s'ye goturen bir donme her zaman var.
        const Vector4 targets[] = {
            restFourMomentum(c, mass, 1.0, 0.0, 0.0),
            restFourMomentum(c, mass, 0.0, 1.0, 0.0),
            restFourMomentum(c, mass, 0.0, 0.0, 1.0),
            restFourMomentum(c, mass, s3, s3, s3)};

        for (const Vector4 &target : targets)
        {
            // Kaynak (0,0,1) alinip hedefe goturuluyor: kuresel acilar yeterli.
            const double sx = target[0] / (mass * c);
            const double sy = target[1] / (mass * c);
            const double sz = target[2] / (mass * c);
            const double beta = std::acos(std::clamp(sz, -1.0, 1.0));
            const double alpha = std::atan2(sy, sx);
            const Matrix4 rotation = timeRotation(alpha, beta, 0.0);
            const Vector4 mapped = rotation * restFourMomentum(c, mass, 0.0, 0.0, 1.0);
            report.checkNear(std::format("  (0,0,1) -> {} bir O(3) elemaniyla erisilebilir",
                                         target.toString()),
                             mapped.maxAbsDifference(target), 1e-10);
        }

        report.subsection("4) SONUC");
        report.line("  Tum s secimleri AYNI YORUNGEDE.");
        report.conclusion("Sonsuz sayida fiziksel durum YOK; tek bir durumu yazmanin");
        report.note("sonsuz yolu var. Bu bir AYAR (gauge) fazlaligidir.");
        report.line();
        report.line("  Stabilizator  : O(2)  (secilen eksen etrafinda donme)");
        report.line("  Yorunge uzayi : O(3)/O(2) = S^2  -> iki parametreli, bir kure");

        // Stabilizator dogrulamasi: (0,0,1) etrafinda z-donmesi s'yi sabit birakiyor.
        const Vector4 north = restFourMomentum(c, mass, 0.0, 0.0, 1.0);
        for (double angle : {0.2, 1.0, 2.5})
        {
            const Matrix4 stabilizer = timeRotation(angle, 0.0, -angle);
            report.checkNear(std::format("  O(2) stabilizatoru s'yi sabit birakiyor (aci {:g})", angle),
                             (stabilizer * north).maxAbsDifference(north), 1e-10);
        }
        report.note("Makale acigi #5 kapandi.");
    }

} // namespace slm
