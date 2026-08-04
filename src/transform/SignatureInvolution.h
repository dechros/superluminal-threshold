#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    /// Section on the factorisation M(V) = D * B(c^2/V) and its consequences.
    ///
    /// The matrix builders are static because none of them depends on any
    /// instance state; the class exists to group them with the verifications
    /// that exercise them.
    class SignatureInvolution : public Section
    {
    public:
        /// The discrete involution D, mapping (ct, x, y, z) to (z, y, x, ct).
        static Matrix4 matrix();

        /// Ordinary hyperbolic rotation along x.
        /// \param c Speed of light.
        /// \param u Boost speed, expected below c.
        static Matrix4 hyperbolicRotation(double c, double u);

        /// The composite transformation M(V) = D * B(c^2/V).
        /// \param c Speed of light.
        /// \param V Speed above c, so that the inner boost stays below c.
        static Matrix4 superboost(double c, double V);

        /// Image of a speed under the velocity map, v' = c^2/v.
        /// \return The transformed speed; c is the fixed point.
        static double transformVelocity(double c, double v);

        std::string title() const override
        {
            return "Factorisation, the matrix D and group closure";
        }
        void run(Report &report) const override;
    };

}
