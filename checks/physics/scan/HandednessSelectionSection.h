#ifndef SLM_CHECKS_PHYSICS_SCAN_HANDEDNESSSELECTIONSECTION_H
#define SLM_CHECKS_PHYSICS_SCAN_HANDEDNESSSELECTIONSECTION_H

#include "core/Section.h"
#include "physics/scan/HandednessSelection.h"

#include <string>

namespace slm
{

    /// Section verifying that handedness cuts the eight to four, that the four
    /// it keeps are the ones that recover time, and that the two families
    /// differ by a single reflection the earlier filters could not see.
    class HandednessSelectionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Handedness as a fourth filter, which leaves one family and makes the direction of the time difference a result rather than a choice";
        }
        void run(Report &report) const override;
    };

}

#endif
