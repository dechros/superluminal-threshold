#pragma once

#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// What the crossing does to a four-current, independent of any timing or
    /// admission question.
    ///
    /// Charge density is the time component of the four-current, and the
    /// crossing carries the near side's time axis onto a far-side space axis.
    /// So the near-side density becomes a far-side current component, and one
    /// of the near-side currents becomes the far-side density. The four-current
    /// maps whole under the crossing and loses no component; only the split
    /// into density and current is reshuffled.
    class ChargedCurrent
    {
    public:
        /// Four-current as the near side writes it, from a charge density and
        /// three current components.
        static Vector4 nearSideCurrent(double c, double chargeDensity, double jx, double jy,
                                       double jz);

        /// The same four-current as the far side writes it, obtained by the
        /// crossing map rather than by relabelling.
        static Vector4 farSideCurrent(const Vector4 &near);

        /// Whether the near side's charge density has become a far-side current
        /// component, which is the reshuffling the crossing forces.
        static bool densityBecomesCurrent(const Vector4 &near);

        /// Squared length of the four-current under the metric of the side it
        /// is written on, which is the invariant that has to survive if the
        /// current is to be the same current.
        static double currentInvariant(const Vector4 &current, bool farSide);

        /// Whether that invariant is carried across up to the overall sign the
        /// crossing imposes, which is what conservation of the current means
        /// here and is weaker than equality.
        static bool invariantSurvives(const Vector4 &near, double tolerance);
    };

    /// Section on what the crossing does to a four-current.
    class ChargedCurrentSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What charge means on the far side";
        }
        void run(Report &report) const override;
    };

}
