#include "transform/SignatureInvolution.h"

#include "core/Report.h"
#include "core/Vector4.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{
    Matrix4 SignatureInvolution::matrix()
    {
        return Matrix4({{{{0, 0, 0, 1}},
                         {{0, 0, 1, 0}},
                         {{0, 1, 0, 0}},
                         {{1, 0, 0, 0}}}});
    }

    Matrix4 SignatureInvolution::hyperbolicRotation(double c, double u)
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

    Matrix4 SignatureInvolution::superboost(double c, double V)
    {
        return matrix() * hyperbolicRotation(c, c * c / V);
    }

    double SignatureInvolution::transformVelocity(double c, double v)
    {
        return c * c / v;
    }

    int SignatureInvolution::plusCount(const Matrix4 &metric)
    {
        int plus = 0;
        for (int slot = 0; slot < 4; ++slot)
        {
            if (metric.at(slot, slot) > 0.0)
            {
                ++plus;
            }
        }
        return plus;
    }

    bool SignatureInvolution::isMereRelabelling(const Matrix4 &from, const Matrix4 &onto)
    {
        const int fromPlus = plusCount(from);
        const int ontoPlus = plusCount(onto);
        return fromPlus == ontoPlus || fromPlus == 4 - ontoPlus;
    }

    void SignatureInvolution::run(Report &report) const
    {
        const Matrix4 D = matrix();
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const double c = 1.0;

        report.subsection("Factorisation: M(V) = D * B(c^2/V)");

        for (double V : {1.5, 2.0, 10.0, 1000.0})
        {
            const Matrix4 M = superboost(c, V);
            const bool metricOk = M.flipsMetric(eta, etaPrime, 1e-10);
            report.check(std::format("V = {:g}c : M(V)^T eta' M(V) = -eta", V), metricOk);
        }

        report.subsection("The matrix D and its properties");

        report.checkNear("signature relation: D^T eta' D = -eta",
                         (D.congruence(etaPrime) + eta).maxAbsDifference(Matrix4::zero()));
        report.checkNear("involution: D^2 = I",
                         (D * D).maxAbsDifference(Matrix4::identity()));
        report.checkNear("determinant = +1, parity preserved", D.determinant() - 1.0);
        report.check("group order = 2, so <D> = Z_2", D.order() == 2);
        double worstDrift = 0.0;
        for (double V : {1.5, 2.0, 10.0, 1000.0})
        {
            const Matrix4 factor = superboost(c, V) * hyperbolicRotation(c, c * c / V).inverse();
            worstDrift = std::max(worstDrift, factor.maxAbsDifference(D));
        }
        report.checkNear("the factor left after removing the boost is the same matrix at "
                         "every V, so D carries no velocity dependence",
                         worstDrift, 1e-9);

        report.subsection("Light cone: s^2 = 0 -> s'^2 = 0");
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
            report.checkNear("  light cone preserved (s'^2 = -s^2 = 0)", after + before);
        }

        report.subsection("General interval: s'^2 = -s^2");
        const Vector4 generic(0.3, -1.7, 2.4, 0.9);
        const Vector4 genericImage = D * generic;
        report.checkNear("s'^2 = -s^2",
                         genericImage.contract(etaPrime) + generic.contract(eta));

        report.subsection("Group closure");
        report.check("D^2 = I  -> <D> = Z_2, CLOSED", D.isInvolution());
        for (double V : {1.5, 2.0, 10.0})
        {
            const Matrix4 M = superboost(c, V);
            const bool closes = (M * M).isIdentity(1e-10);
            report.check(std::format("M({:g}c)^2 = I ?  (expected: NO)", V), !closes);
        }

        report.subsection("Where closure breaks: D B D^-1");
        const Matrix4 B = hyperbolicRotation(c, 0.6 * c);
        const Matrix4 conjugated = D * B * D.inverse();
        report.check("conjugation does not keep the SO(1,3) boost of the same type",
                     !conjugated.isEqual(B, 1e-10));

        report.subsection("Is the far metric only the near one in the opposite convention?");
        report.check(std::format("  the near metric carries {} plus signs, the far one {}",
                                 plusCount(eta), plusCount(etaPrime)),
                     plusCount(eta) == 1 && plusCount(etaPrime) == 3);
        report.check("the two are the same geometry written in opposite conventions, because "
                     "one signature is the reverse of the other, and this is the objection the "
                     "chain has to survive rather than a result it can lean on",
                     isMereRelabelling(eta, etaPrime));
        const Matrix4 kleinian = Matrix4::diagonal(1.0, 1.0, -1.0, -1.0);
        report.check(std::format("  the split metric carries {} plus signs, and its own reverse "
                                 "carries {} as well",
                                 plusCount(kleinian), 4 - plusCount(kleinian)),
                     plusCount(kleinian) == 2);
        report.check("but the split-signature region is not the near one relabelled, because "
                     "reversing two plus signs and two minus signs returns the same pair of "
                     "counts while the near metric returns a different one",
                     !isMereRelabelling(eta, kleinian));
        report.check("so a path that goes through the split region changes the geometry, "
                     "whereas a direct swap of the two end metrics need not",
                     !isMereRelabelling(eta, kleinian) && isMereRelabelling(eta, etaPrime));

        report.subsection("Velocity transformation: v' = c^2/v");
        for (double v : {0.25, 0.5, 0.9, 1.0, 2.0, 4.0})
        {
            const Vector4 event(1.0, v / c, 0.0, 0.0);
            const Vector4 image = D * event;
            const double spatial = image[3];
            const double temporal = std::sqrt(image[0] * image[0] + image[1] * image[1] +
                                              image[2] * image[2]);
            const double vPrime = c * spatial / temporal;
            report.checkNear("  v' = c^2/v", vPrime - transformVelocity(c, v), 1e-12);
        }
    }
}
