#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <array>

namespace slm
{

    /// How degenerate a continuous path between the two signatures has to be.
    ///
    /// Signature is a discrete invariant of non-degenerate symmetric forms, so
    /// some degeneracy on the way is unavoidable. What is not fixed in advance
    /// is how many eigenvalues have to vanish at the same point, and that is
    /// what these paths measure. All paths here are diagonal, which is enough:
    /// the two endpoint metrics are diagonal and a congruence can be applied
    /// afterwards.
    class DegeneratePath
    {
    public:
        /// Path flipping both middle entries together,
        /// diag(1, -cos L, -cos L, -1), running from region I to region II.
        static Matrix4 direct(double lambda);

        /// First leg of the staged path, flipping one entry only,
        /// diag(1, -cos L, -1, -1). Ends at signature (2,2).
        static Matrix4 stagedFirst(double lambda);

        /// Second leg, flipping the remaining entry,
        /// diag(1, 1, -cos L, -1). Ends at region II.
        static Matrix4 stagedSecond(double lambda);

        /// The path used in section 13.3, diag(1, -cos L, -cos L, -cos L).
        static Matrix4 allSpace(double lambda);

        /// Counts of positive, negative and vanishing diagonal entries.
        /// \param eps Below this magnitude an entry counts as vanishing.
        static std::array<int, 3> signature(const Matrix4 &metric, double eps = 1e-9);

        /// Number of vanishing eigenvalues, that is the drop in rank.
        static int rankDrop(const Matrix4 &metric, double eps = 1e-9);

        /// Largest rank drop encountered along a path, sampled uniformly.
        /// \param path Function of the path parameter.
        /// \param samples Number of samples over [0, pi].
        static int worstRankDrop(Matrix4 (*path)(double), int samples = 20001);
    };

    /// Section asking what a continuous interpolation between the two
    /// signatures actually costs.
    class DegeneratePathSection : public Section
    {
    public:
        std::string number() const override { return "7.1"; }
        std::string title() const override
        {
            return "Interpolating between the signatures: how degenerate must it get";
        }
        void run(Report &report) const override;
    };

}
