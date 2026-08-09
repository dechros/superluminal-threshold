#pragma once

#include "core/Section.h"

namespace slm
{

    /// Whether a rigid five-body tetrahedral configuration, carried by five
    /// calls to the single-mass map already verified elsewhere, keeps its
    /// shape on return.
    ///
    /// Four masses are launched along the four vertex directions of a
    /// regular tetrahedron and a fifth, heavier mass is launched along a
    /// separate reference direction, standing in for a central atom whose
    /// own displacement from the configuration's centre of mass vanishes by
    /// symmetry. Each direction is used as a literal unit vector, never
    /// scaled by a bond length: no rule converting a physical length into an
    /// orientation angle is assumed or invented, because none exists in this
    /// project or in the literature it draws on. Only the mass-shell length,
    /// already established elsewhere, depends on which mass is launched.
    ///
    /// This gives a shape comparison with no free parameter beyond a chosen
    /// drive frequency: the angle between every pair of the four returned
    /// events is measured against the angle between the four launch
    /// directions, which is uniform by construction. Agreement or
    /// disagreement is read off, not assumed either way.
    class RigidMoleculeSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A rigid tetrahedron of masses, and whether its shape returns with it";
        }
        void run(Report &report) const override;
    };

}
