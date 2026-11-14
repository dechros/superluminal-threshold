#ifndef SLM_CHECKS_PHYSICS_INTERMEDIATE_DEGENERATEWINDOWSECTION_H
#define SLM_CHECKS_PHYSICS_INTERMEDIATE_DEGENERATEWINDOWSECTION_H

#include "core/Section.h"
#include "physics/intermediate/DegenerateWindow.h"

#include <string>

namespace slm
{

    /// Section verifying that the crossing meets a degenerate set of vanishing
    /// width, that the suppression tends to one with it, and that a layer thick
    /// enough to block is not a solution of the field equation.
    class DegenerateWindowSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Why a degenerate layer blocks and a degenerate point does not, and why only the point is a solution";
        }
        void run(Report &report) const override;
    };

}

#endif
