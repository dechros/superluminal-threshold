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
    }

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

        report.subsection("The mass shell condition locks s onto the unit sphere");
        const double s3 = 1.0 / std::sqrt(3.0);
        const Vector4 rest = restFourMomentum(c, mass, s3, s3, s3);
        report.checkNear("p'.p' = m^2c^2 (s1^2+s2^2+s3^2) = m^2c^2",
                         rest.contract(etaPrime) - mass * mass * c * c);

        report.subsection("The group preserving rest: O(3)");

        const double pi = std::numbers::pi;
        const Matrix4 rotations[] = {
            timeRotation(0.3, 0.0, 0.0),
            timeRotation(0.0, 0.7, 0.0),
            timeRotation(0.4, 1.1, -0.6),
            timeRotation(pi / 3.0, pi / 4.0, pi / 5.0)};

        for (const Matrix4 &rotation : rotations)
        {
            report.checkNear("  preserves the metric: R^T eta' R = eta'",
                             (rotation.congruence(etaPrime) - etaPrime).maxAbsDifference(Matrix4::zero()),
                             1e-12);
            const Vector4 image = rotation * rest;
            report.checkNear("  preserves rest: the last component stays 0", image[3]);
            report.checkNear("  the mass shell is preserved",
                             image.contract(etaPrime) - rest.contract(etaPrime), 1e-12);
        }

        for (int axis = 0; axis < 3; ++axis)
        {
            const Matrix4 reflection = timeReflection(axis);
            report.checkNear(std::format("  reflection (axis {}): preserves the metric, det = {:g}",
                                         axis, reflection.determinant()),
                             (reflection.congruence(etaPrime) - etaPrime).maxAbsDifference(Matrix4::zero()));
        }

        report.subsection("The O(3) action on S^2 is transitive");
        const Vector4 targets[] = {
            restFourMomentum(c, mass, 1.0, 0.0, 0.0),
            restFourMomentum(c, mass, 0.0, 1.0, 0.0),
            restFourMomentum(c, mass, 0.0, 0.0, 1.0),
            restFourMomentum(c, mass, s3, s3, s3)};

        for (const Vector4 &target : targets)
        {
            const double sx = target[0] / (mass * c);
            const double sy = target[1] / (mass * c);
            const double sz = target[2] / (mass * c);
            const double beta = std::acos(std::clamp(sz, -1.0, 1.0));
            const double alpha = std::atan2(sy, sx);
            const Matrix4 rotation = timeRotation(alpha, beta, 0.0);
            const Vector4 mapped = rotation * restFourMomentum(c, mass, 0.0, 0.0, 1.0);
            report.checkNear(std::format("  (0,0,1) -> {} is reachable by an O(3) element",
                                         target.toString()),
                             mapped.maxAbsDifference(target), 1e-10);
        }

        report.subsection("Result");

        const Vector4 north = restFourMomentum(c, mass, 0.0, 0.0, 1.0);
        for (double angle : {0.2, 1.0, 2.5})
        {
            const Matrix4 stabilizer = timeRotation(angle, 0.0, -angle);
            report.checkNear(std::format("  the O(2) stabiliser leaves s fixed (angle {:g})", angle),
                             (stabilizer * north).maxAbsDifference(north), 1e-10);
        }
    }
}
