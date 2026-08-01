#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// Section showing that the family of superluminal rest states is a
    /// single orbit rather than a family of distinct physical states.
    class SuperluminalRest : public Section
    {
    public:
        /// Rest four-momentum (m c s1, m c s2, m c s3, 0).
        /// \param s1,s2,s3 Components of a unit vector on the two-sphere.
        static Vector4 restFourMomentum(double c, double mass, double s1, double s2, double s3);

        /// Rotation of the three time axes, embedded as block-diag(R, 1).
        /// \param alpha,beta,gamma z-y-z Euler angles.
        static Matrix4 timeRotation(double alpha, double beta, double gamma);

        /// Reflection of one time axis, an element of O(3) with det -1.
        /// \param axis Index of the reflected axis in [0, 2].
        static Matrix4 timeReflection(int axis);

        std::string number() const override { return "8"; }
        std::string title() const override
        {
            return "Superluminal rest: a gauge redundancy";
        }
        void run(Report &report) const override;
    };

}
