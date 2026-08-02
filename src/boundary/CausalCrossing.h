#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// Whether a curve can cross the threshold on causal grounds alone.
    ///
    /// Section 9.1 forbids flux from crossing, which is a statement about the
    /// field and its junction condition. This section asks the separate and
    /// weaker question of whether a direction that is timelike on one side
    /// stays timelike on the other, which is a statement about the two metrics
    /// and nothing else. The two questions have different answers, and keeping
    /// them apart is what allows the loops found in the literature to coexist
    /// with a threshold that carries no flux.
    class CausalCrossing
    {
    public:
        /// Difference between the two quadratic forms, eta' minus eta, applied
        /// to a vector. Non-negative for every vector, since the two metrics
        /// differ by twice the sum of two squares.
        static double intervalGain(const Vector4 &v);

        /// True when the vector is timelike for the region I metric.
        static bool timelikeInRegionI(const Vector4 &v);

        /// True when the vector is timelike for the region II metric.
        static bool timelikeInRegionII(const Vector4 &v);

        /// Whether every direction timelike in region I stays timelike in
        /// region II, tested over a grid of directions.
        /// \param steps Grid resolution per component.
        static bool timelikeSetIsNested(int steps = 25);

        /// A direction timelike in region II but not in region I, showing the
        /// inclusion is strict.
        static Vector4 timelikeOnlyBeyond();
    };

    /// Section separating the causal question from the flux question at the
    /// threshold.
    class CausalCrossingSection : public Section
    {
    public:
        std::string number() const override { return "9.3"; }
        std::string title() const override
        {
            return "Geometry permits the crossing that the field forbids";
        }
        void run(Report &report) const override;
    };

}
