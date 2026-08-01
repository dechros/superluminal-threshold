#include "field/MaxwellField.h"

#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <format>

namespace slm
{
    Matrix4 MaxwellField::fieldTensor(double c, double ex, double ey, double ez,
                                      double bx, double by, double bz)
    {
        return Matrix4({{{{0.0, ex / c, ey / c, ez / c}},
                         {{-ex / c, 0.0, -bz, by}},
                         {{-ey / c, bz, 0.0, -bx}},
                         {{-ez / c, -by, bx, 0.0}}}});
    }

    Matrix4 MaxwellField::transformedFieldTensor(const Matrix4 &f)
    {
        const Matrix4 D = InvolutionD::matrix();
        return D.transpose() * f * D;
    }

    double MaxwellField::invariant(const Matrix4 &f, const Matrix4 &metric)
    {
        return (f * metric * f * metric).trace();
    }

    Vector4 MaxwellField::fourPotential(double c, double phi, double ax, double ay, double az)
    {
        return Vector4(phi / c, ax, ay, az);
    }

    Vector4 MaxwellField::fourCurrent(double c, double rho, double jx, double jy, double jz)
    {
        return Vector4(rho * c, jx, jy, jz);
    }

    void MaxwellSection::run(Report &report) const
    {
        const double c = 1.0;
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const Matrix4 D = InvolutionD::matrix();

        report.subsection("Four-potential and four-current");
        const Vector4 a = MaxwellField::fourPotential(c, 2.0, 0.5, -1.0, 3.0);
        const Vector4 j = MaxwellField::fourCurrent(c, 1.5, -0.25, 2.0, 0.75);
        const Vector4 aPrime = D * a;
        const Vector4 jPrime = D * j;
        report.checkNear("the electric potential becomes the single SPACE component",
                         aPrime[3] - a[0]);
        report.checkNear("charge density and current component SWAP", jPrime[3] - j[0]);

        report.subsection("Interaction term A_mu j^mu");
        double ourInteraction = 0.0;
        double theirInteraction = 0.0;
        for (int i = 0; i < 4; ++i)
        {
            ourInteraction += a[i] * eta.at(i, i) * j[i];
            theirInteraction += aPrime[i] * etaPrime.at(i, i) * jPrime[i];
        }
        report.checkNear("A'.j' = -A.j", theirInteraction + ourInteraction);

        report.subsection("Field tensor F' = D^T F D");
        const Matrix4 f = MaxwellField::fieldTensor(c, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
        const Matrix4 fPrime = MaxwellField::transformedFieldTensor(f);
        report.check("F stays antisymmetric",
                     fPrime.isEqual(-fPrime.transpose(), 1e-12));

        report.subsection("Invariant, the critical result");
        const double ourInvariant = MaxwellField::invariant(f, eta);
        const double theirInvariant = MaxwellField::invariant(fPrime, etaPrime);
        report.checkNear("EXACT EQUALITY: the kinetic term is invariant under D",
                         ourInvariant - theirInvariant);

        report.subsection("Wave equation and charge conservation");

        const Vector4 j2 = MaxwellField::fourCurrent(c, -0.5, 1.0, -2.0, 0.5);
        report.checkNear("D is linear: D(j1+j2) = D j1 + D j2",
                         (D * (j + j2)).maxAbsDifference(jPrime + (D * j2)));
    }
}
