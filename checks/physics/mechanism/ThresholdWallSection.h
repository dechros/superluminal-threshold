#ifndef SLM_CHECKS_PHYSICS_MECHANISM_THRESHOLDWALLSECTION_H
#define SLM_CHECKS_PHYSICS_MECHANISM_THRESHOLDWALLSECTION_H

#include "core/Section.h"
#include "physics/mechanism/ThresholdWall.h"

#include <string>

namespace slm
{

    /// Section verifying that the kink solves the field equation, that its
    /// degenerate point is crossed at maximum speed, and that the coupling
    /// reproduces the mass shell the earlier sections assumed. The section
    /// establishes an alternative reading and not the mechanism.
    class ThresholdWallSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The threshold as a domain wall, an alternative reading of the same constant that the project does not use as its mechanism";
        }
        void run(Report &report) const override;
    };

}

#endif
