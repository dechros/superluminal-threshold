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

        /// Whether one diagonal metric is carried onto another by nothing more
        /// than renaming the axes and flipping the overall sign. A signature
        /// that answers true is the same geometry written in the opposite
        /// convention, so no transformation between the two carries physical
        /// content; a signature that answers false is a different geometry.
        /// \param from The metric written in the first convention.
        /// \param onto The metric the caller wants to reach.
        static bool isMereRelabelling(const Matrix4 &from, const Matrix4 &onto);

        /// The count of plus signs on the diagonal of a diagonal metric, which
        /// with the dimension fixes the signature.
        static int plusCount(const Matrix4 &metric);

        std::string title() const override
        {
            return "Factorisation, the matrix D and group closure";
        }
        void run(Report &report) const override;
    };

}
