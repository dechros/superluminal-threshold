#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// Whether a region admits a consistent split of timelike vectors into
    /// future and past directed ones.
    ///
    /// The split exists exactly when the set of timelike vectors falls into
    /// two connected components, and that happens exactly when the metric has
    /// a single positive direction. The tests here settle the question
    /// constructively: in region II a timelike vector is rotated continuously
    /// into its own negative without ever leaving the timelike set, which
    /// leaves no room for a binary label, while in region I no such rotation
    /// exists.
    class TimeOrientation
    {
    public:
        /// Rotation of a vector inside the plane spanned by two axes.
        /// \param metric Metric defining the causal character.
        /// \param first,second Axis indices spanning the rotation plane.
        /// \param angle Rotation angle.
        static Vector4 rotateInPlane(int first, int second, double angle);

        /// True when the vector is timelike for the given metric, that is when
        /// its squared interval is positive.
        static bool isTimelike(const Matrix4 &metric, const Vector4 &v, double eps = 1e-12);

        /// Smallest squared interval met while rotating a unit vector through
        /// half a turn in the plane spanned by two axes, which carries it into
        /// its own negative. A positive value means the whole path stayed
        /// timelike, so the two ends cannot be told apart.
        /// \param first,second Axis indices spanning the rotation plane.
        /// \param samples Number of angles sampled over [0, pi].
        static double worstIntervalAlongRotation(const Matrix4 &metric,
                                                 int first, int second, int samples = 20001);

        /// Number of positive diagonal entries, that is the number of time
        /// directions.
        static int timeDirectionCount(const Matrix4 &metric);

        /// Whether a consistent future and past split exists, which holds only
        /// for a single time direction.
        static bool admitsTimeOrientation(const Matrix4 &metric);

        /// Metric of the intermediate region of the staged path, signature (2,2).
        static Matrix4 metricKleinian();
    };

    /// Section on the time orientation of each region and on what it shares
    /// with the loops found at a signature-change hypersurface.
    class TimeOrientationSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Time orientation: why the far side carries no future and past";
        }
        void run(Report &report) const override;
    };

}
