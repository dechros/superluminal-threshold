#ifndef SLM_CHECKS_PHYSICS_UNITS_PHYSICALSCALESSECTION_H
#define SLM_CHECKS_PHYSICS_UNITS_PHYSICALSCALESSECTION_H

#include "core/Section.h"
#include "physics/units/PhysicalScales.h"

#include <string>

namespace slm
{

    /// Section reporting the journey in laboratory units.
    class PhysicalScalesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The journey in kilograms, metres and seconds";
        }
        void run(Report &report) const override;
    };

}

#endif
