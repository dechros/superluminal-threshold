#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// Whether the metric alone singles out one of the two causal components.
    ///
    /// Two questions are easily run together and are answered differently. The
    /// first is whether a region admits a split of its timelike vectors into
    /// two components at all; that is settled elsewhere and depends only on how
    /// many directions have positive square. The second is whether, given that
    /// a split exists, the geometry distinguishes one component from the other.
    /// It does not, and the reason is a symmetry: reversing the single positive
    /// axis leaves the metric unchanged while carrying each component onto the
    /// other. A quantity built from the metric therefore takes equal values on
    /// the two, and no such quantity can name one of them.
    ///
    /// The consequence is a division of labour rather than a defect. The split
    /// is geometric and the label is not, so whatever fixes the label is
    /// carried by the state rather than by the metric, and a claim that the
    /// label is fixed by the geometry has to name a metric quantity that
    /// changes under the reversal. This class computes the reversal, checks
    /// that it is an isometry, and checks what it does to the components, so
    /// the division can be stated as a result instead of assumed.
    class ReversalSymmetry
    {
    public:
        /// Diagonal map that reverses one axis and fixes the others.
        static Matrix4 axisReversal(int axis);

        /// True when reversing @p axis is an isometry of @p metric.
        ///
        /// Every single-axis reversal is, for any diagonal metric, since the
        /// entries are squared by the congruence. The check is kept because the
        /// argument depends on it and because it stops holding the moment the
        /// metric acquires off-diagonal terms, which is the case a curved
        /// version of this work would have to face.
        static bool isIsometry(const Matrix4 &metric, int axis);

        /// Number of axes whose reversal is an isometry of @p metric.
        static int isometricReversalCount(const Matrix4 &metric);

        /// True when reversing @p axis carries the given timelike vector to a
        /// timelike vector with the opposite sign in that axis.
        ///
        /// This is what "exchanges the components" means operationally: the
        /// image is still timelike, so it has not left the set, and its
        /// component along the reversed axis has changed sign, so it is not in
        /// the part it started in.
        static bool exchangesComponents(const Matrix4 &metric, int axis, const Vector4 &timelike);

        /// Index of the single positive axis of a diagonal metric, or -1 when
        /// the count of positive axes is not one.
        ///
        /// Returning -1 rather than a plausible index matters: where there is
        /// no single time direction there is no split to exchange, and a caller
        /// that ignores the failure would otherwise get an answer about the
        /// wrong axis.
        static int soleTimeAxis(const Matrix4 &metric);

        /// True when the metric leaves one causal component distinguishable
        /// from the other by geometric means alone.
        ///
        /// False for every diagonal metric with a single time direction, which
        /// is the result this class exists to establish. It is not a statement
        /// that the two components are the same set; they are disjoint and the
        /// split is real. It is a statement that nothing built from the metric
        /// tells them apart.
        static bool geometryFixesOrientation(const Matrix4 &metric);
    };

    /// Section separating the existence of a causal split from the choice of
    /// which side of it is the future.
    class ReversalSymmetrySection : public Section
    {
    public:
        std::string title() const override
        {
            return "The split is geometric, the label on it is not";
        }
        void run(Report &report) const override;
    };

}
