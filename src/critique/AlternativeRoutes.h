#pragma once

#include "core/Section.h"

namespace slm
{

    /// Two checks on constructions that would weaken a multi-time region.
    ///
    /// The first asks whether imposing probability conservation collapses
    /// several time directions to one effective time. The second asks whether
    /// self-adjointness at a reflecting wall selects vanishing-value conditions over
    /// vanishing-slope ones, and whether the reflection coefficient depends on that
    /// choice.
    class AlternativeRoutes
    {
    public:
        /// Free evolution in two times: a particle with velocity components
        /// along both time axes, parametrised by the two times, traces a
        /// straight line. The position after (t1, t2) depends only on the
        /// combination that the velocities single out.
        /// \return Position reached, in one space dimension.
        static double twoTimePosition(double v1, double v2, double t1, double t2);

        /// The effective single time that reproduces the same motion, that is
        /// the combination the trajectory actually depends on.
        static double effectiveSingleTime(double v1, double v2, double t1, double t2);

        /// Residual between the two-time motion and its single-time
        /// reconstruction. Vanishing means the second time carries no
        /// independent dynamical content.
        static double collapseResidual(double v1, double v2, double t1, double t2);

        /// Reflection amplitude for a wall carrying a mixed condition
        /// cos(a) psi + sin(a) psi' = 0, which interpolates between vanishing-value
        /// at a = 0 and vanishing-slope at a = pi/2.
        /// \param mixing The angle a.
        /// \param wavenumber Normal wavenumber of the incident mode.
        static double mixedConditionReflection(double mixing, double wavenumber);

        /// Whether every member of the mixed-condition family reflects completely,
        /// sampled over the range of mixing angles.
        static bool wholeFamilyReflects(double wavenumber, int samples = 2001);
    };

    /// Section running these two objections.
    class AlternativeRoutesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Two more objections, computed";
        }
        void run(Report &report) const override;
    };

}
