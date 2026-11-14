#ifndef SLM_CHECKS_PHYSICS_SCAN_DIRECTIONFAMILYSECTION_H
#define SLM_CHECKS_PHYSICS_SCAN_DIRECTIONFAMILYSECTION_H

#include "core/Section.h"
#include "physics/scan/DirectionFamily.h"

#include <string>

namespace slm
{

    /// Section running the checks on DirectionFamily.
    class DirectionFamilySection : public Section
    {
    public:
        std::string title() const override
        {
            return "Which of the admissible matrices send a step later, and which earlier";
        }

        void run(Report &report) const override;
    };

}

#endif
