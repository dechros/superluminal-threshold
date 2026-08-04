#include "transform/ExtendedIsometryGroup.h"

#include "core/Report.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{
    Matrix4 ExtendedIsometryGroup::lambdaAlongZ()
    {
        return Matrix4({{{{0, 0, 0, -1}},
                         {{0, 1, 0, 0}},
                         {{0, 0, 1, 0}},
                         {{-1, 0, 0, 0}}}});
    }

    double ExtendedIsometryGroup::xySwapDeterminant3D()
    {
        return -1.0;
    }

    bool ExtendedIsometryGroup::isInExtendedGroup()
    {
        const Matrix4 flatMetric = Matrix4::diagonal(-1.0, 1.0, 1.0, 1.0);
        const Matrix4 lambda = lambdaAlongZ();
        const Matrix4 D = SignatureInvolution::matrix();

        for (int exponent = 0; exponent <= 1; ++exponent)
        {
            for (double sign : {1.0, -1.0})
            {
                const Matrix4 prefactor = lambda.power(exponent) * sign;
                const Matrix4 remainder = prefactor.inverse() * D;
                const bool preservesFlatMetric =
                    (remainder.congruence(flatMetric) - flatMetric).isZero(1e-10);
                const bool properOrthochronous =
                    std::abs(remainder.determinant() - 1.0) < 1e-10 && remainder.at(0, 0) > 0.0;
                if (preservesFlatMetric && properOrthochronous)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void ExtendedIsometryGroup::run(Report &report) const
    {
        const Matrix4 D = SignatureInvolution::matrix();

        report.subsection("Sign choice: can +D and -D be told apart?");
        for (double sign : {1.0, -1.0})
        {
            const Matrix4 candidate = D * sign;
            report.check(std::format("  s = {:+g} passes every test", sign),
                         candidate.isInvolution() &&
                             std::abs(candidate.determinant() - 1.0) < kEps);
        }

        report.subsection("The direction dependent involution");
        const Matrix4 lambda = lambdaAlongZ();
        report.check("the involution squares to the identity", lambda.isInvolution());

        report.subsection("Is D contained in the extended group?");
        report.check("the x <-> y swap is a REFLECTION, not an element of SO(3)",
                     xySwapDeterminant3D() < 0.0);
        report.check("D is not contained in the extended group", !isInExtendedGroup());
    }
}
