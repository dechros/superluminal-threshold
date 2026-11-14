#ifndef SLM_CHECKS_PHYSICS_DYNAMICS_DISPERSIONSECTION_H
#define SLM_CHECKS_PHYSICS_DYNAMICS_DISPERSIONSECTION_H

#include "core/Section.h"
#include "physics/dynamics/Dispersion.h"

#include <string>

namespace slm
{

    /// Section wrapper running the dispersion verifications.
    class DispersionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Velocity: from scalar to orientation";
        }
        void run(Report &report) const override;
    };

}

#endif
