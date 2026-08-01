#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// Builders for the electromagnetic quantities used by the section below.
    ///
    /// Every member is static; the class is a namespace with a name.
    class MaxwellField
    {
    public:
        /// Field tensor F_munu in the (ct, x, y, z) ordering.
        static Matrix4 fieldTensor(double c, double ex, double ey, double ez,
                                   double bx, double by, double bz);

        /// Image of the field tensor, F' = D^T F D.
        static Matrix4 transformedFieldTensor(const Matrix4 &f);

        /// The scalar F_munu F^munu, evaluated with the given metric.
        static double invariant(const Matrix4 &f, const Matrix4 &metric);

        /// Four-potential A^mu = (phi/c, Ax, Ay, Az).
        static Vector4 fourPotential(double c, double phi, double ax, double ay, double az);

        /// Four-current j^mu = (rho c, jx, jy, jz).
        static Vector4 fourCurrent(double c, double rho, double jx, double jy, double jz);
    };

    /// Section running the electromagnetic verifications.
    class MaxwellSection : public Section
    {
    public:
        std::string number() const override { return "11"; }
        std::string title() const override
        {
            return "Electromagnetism under D";
        }
        void run(Report &report) const override;
    };

}
