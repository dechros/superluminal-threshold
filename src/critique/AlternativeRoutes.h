#pragma once

#include "core/Section.h"

namespace slm
{

    /// Two further objections, computed rather than described.
    ///
    /// The first is that extra time directions collapse to an effective single
    /// time once probability conservation is imposed, which would make region
    /// II less exotic than section 7 claims. The second is that self-adjointness
    /// selects Dirichlet conditions at the wall rather than the Neumann ones
    /// used here, which would change the boundary condition but, as it turns
    /// out, not the conclusion.
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

        /// Reflection amplitude for a wall carrying a Robin condition
        /// cos(a) psi + sin(a) psi' = 0, which interpolates between Dirichlet
        /// at a = 0 and Neumann at a = pi/2.
        /// \param mixing The angle a.
        /// \param wavenumber Normal wavenumber of the incident mode.
        static double robinReflectionMagnitude(double mixing, double wavenumber);

        /// Whether every member of the Robin family reflects completely,
        /// sampled over the range of mixing angles.
        static bool wholeFamilyReflects(double wavenumber, int samples = 2001);
    };

    /// Section running these two objections.
    class AlternativeRoutesSection : public Section
    {
    public:
        std::string number() const override { return "21.4"; }
        std::string title() const override
        {
            return "Two more objections, computed";
        }
        void run(Report &report) const override;
    };

}
