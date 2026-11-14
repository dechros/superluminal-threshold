#include "physics/transform/SignatureInvolution.h"

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
}
