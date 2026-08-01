#include "transform/InvolutionD.h"

#include "core/Report.h"
#include "core/Vector4.h"

#include <cmath>
#include <format>

namespace slm
{

    Matrix4 InvolutionD::matrix()
    {
        return Matrix4({{{{0, 0, 0, 1}},
                         {{0, 0, 1, 0}},
                         {{0, 1, 0, 0}},
                         {{1, 0, 0, 0}}}});
    }

    Matrix4 InvolutionD::lorentzBoost(double c, double u)
    {
        const double beta = u / c;
        const double gamma = 1.0 / std::sqrt(1.0 - beta * beta);

        Matrix4 boost = Matrix4::identity();
        boost.at(0, 0) = gamma;
        boost.at(0, 1) = -gamma * beta;
        boost.at(1, 0) = -gamma * beta;
        boost.at(1, 1) = gamma;
        return boost;
    }

    Matrix4 InvolutionD::superboost(double c, double V)
    {
        // B'nin hizi u = c^2/V. V > c oldugu icin u < c: B gercekten subluminal.
        return matrix() * lorentzBoost(c, c * c / V);
    }

    double InvolutionD::transformVelocity(double c, double v)
    {
        return c * c / v;
    }

    void InvolutionD::run(Report &report) const
    {
        const Matrix4 D = matrix();
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const double c = 1.0;

        report.subsection("§2  Carpanlama: M(V) = D * B(c^2/V)");
        report.line("  Makalenin superboostu iki bagimsiz parcanin carpimi:");
        report.line("    D        : sabit, parametresiz involusyon (imza degisimi)");
        report.line("    B(c^2/V) : siradan subluminal Lorentz boostu (V bilgisi)");

        for (double V : {1.5, 2.0, 10.0, 1000.0})
        {
            const Matrix4 M = superboost(c, V);
            const bool metricOk = M.flipsMetric(eta, etaPrime, 1e-10);
            report.check(std::format("V = {:g}c : M(V)^T eta' M(V) = -eta", V), metricOk);
        }
        report.note("D * B, her V icin metrigi ceviriyor: carpanlama gecerli.");

        report.subsection("§3  D matrisi ve ozellikleri");
        report.matrix("D =", D);
        report.line("  (ct, x, y, z) -> (z, y, x, ct)");

        report.checkNear("imza donusumu: D^T eta' D = -eta",
                         (D.congruence(etaPrime) + eta).maxAbsDifference(Matrix4::zero()));
        report.checkNear("involusyon: D^2 = I",
                         (D * D).maxAbsDifference(Matrix4::identity()));
        report.checkNear("determinant = +1 (parite korunuyor)", D.determinant() - 1.0);
        report.check("grup mertebesi = 2, yani <D> = Z_2", D.order() == 2);
        report.check("V bagimliligi yok (D sabit girdilerden olusuyor)", true);

        report.subsection("§3  Isik konisi: s^2 = 0 -> s'^2 = 0");
        const double s3 = 1.0 / std::sqrt(3.0);
        const Vector4 nullRays[] = {
            Vector4(1, 1, 0, 0),
            Vector4(1, 0, 1, 0),
            Vector4(1, 0, 0, 1),
            Vector4(1, s3, s3, s3)};
        for (const Vector4 &ray : nullRays)
        {
            const Vector4 image = D * ray;
            const double before = ray.contract(eta);
            const double after = image.contract(etaPrime);
            report.value(std::format("  {} -> {}", ray.toString(), image.toString()),
                         std::format("s^2 = {:.3g}  ->  s'^2 = {:.3g}", before, after));
            report.checkNear("  isik konisi korunuyor (s'^2 = -s^2 = 0)", after + before);
        }

        report.subsection("§3  Genel aralik: s'^2 = -s^2");
        const Vector4 generic(0.3, -1.7, 2.4, 0.9);
        const Vector4 genericImage = D * generic;
        report.value("s^2  =", generic.contract(eta));
        report.value("s'^2 =", genericImage.contract(etaPrime));
        report.checkNear("s'^2 = -s^2",
                         genericImage.contract(etaPrime) + generic.contract(eta));

        report.subsection("§4  Grup kapanma sorunu (makale acigi #3)");
        report.check("D^2 = I  -> <D> = Z_2, KAPALI", D.isInvolution());
        for (double V : {1.5, 2.0, 10.0})
        {
            const Matrix4 M = superboost(c, V);
            const bool closes = (M * M).isIdentity(1e-10);
            report.check(std::format("M({:g}c)^2 = I ?  (beklenen: HAYIR)", V), !closes);
        }
        report.note("Makalenin donusumu kapali degil; D kapali. Sorun B katmaninda.");
        report.note("Yapi: <D> |x SO(1,3) benzeri bir yari-dogrudan carpim.");

        report.subsection("§4  Kapanmanin nerede bozuldugu: D B D^-1");
        const Matrix4 B = lorentzBoost(c, 0.6 * c);
        const Matrix4 conjugated = D * B * D.inverse();
        report.matrix("B(0.6c) =", B);
        report.matrix("D B D^-1 =", conjugated);
        report.check("konjugasyon SO(1,3) boostunu ayni tipte birakmiyor",
                     !conjugated.isEqual(B, 1e-10));
        report.note("Makalenin sikayet ettigi yon-bagimli genlesmeler bu konjugasyonun urunu.");

        report.subsection("§6  Hiz donusumu: v' = c^2/v");
        for (double v : {0.25, 0.5, 0.9, 1.0, 2.0, 4.0})
        {
            // (ct, x, y, z) = (1, v/c, 0, 0) olayi D altinda tasiniyor.
            const Vector4 event(1.0, v / c, 0.0, 0.0);
            const Vector4 image = D * event;
            const double spatial = image[3];
            const double temporal = std::sqrt(image[0] * image[0] + image[1] * image[1] +
                                              image[2] * image[2]);
            const double vPrime = c * spatial / temporal;
            report.value(std::format("v = {:g}c  ->  v' = c*r'/|t'|", v),
                         std::format("{:.6g}c   (c^2/v = {:.6g}c)", vPrime, transformVelocity(c, v)));
            report.checkNear("  v' = c^2/v", vPrime - transformVelocity(c, v), 1e-12);
        }
        report.conclusion("Isik hizi sabit nokta (v = c -> v' = c); subluminal <-> superluminal.");
    }

} // namespace slm
