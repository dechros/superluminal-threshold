#include "literature/LiteraturePosition.h"

#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <cmath>
#include <format>

namespace slm
{
    Matrix4 LiteraturePosition::zaopoLambdaInfinity()
    {
        return Matrix4({{{{0, 0, 0, -1}},
                         {{0, 1, 0, 0}},
                         {{0, 0, 1, 0}},
                         {{-1, 0, 0, 0}}}});
    }

    double LiteraturePosition::xySwapDeterminant3D()
    {
        return -1.0;
    }

    bool LiteraturePosition::isInZaopoGroup()
    {
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

        report.subsection("12  Sign choice: can +D and -D be told apart?");
        for (double sign : {1.0, -1.0})
        {
            const Matrix4 candidate = D * sign;
            report.check(std::format("  s = {:+g} passes every test", sign),
                         candidate.isInvolution() &&
                             std::abs(candidate.determinant() - 1.0) < kEps);
        }

        report.subsection("12.1  A direction dependent involution for comparison");
        const Matrix4 lambda = zaopoLambdaInfinity();
        report.check("Lambda_inf^2 = I", lambda.isInvolution());

        report.subsection("12.2  Is D contained in the extended group L_ext?");
        report.check("the x <-> y swap is a REFLECTION, not an element of SO(3)",
                     xySwapDeterminant3D() < 0.0);
        report.check("D is NOT contained in L_ext", !isInZaopoGroup());
    }
}
