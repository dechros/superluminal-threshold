#ifndef SLM_CHECKS_PHYSICS_DYNAMICS_THRESHOLDFIELDSECTION_H
#define SLM_CHECKS_PHYSICS_DYNAMICS_THRESHOLDFIELDSECTION_H

#include "core/Section.h"
#include "physics/dynamics/ThresholdField.h"

#include <string>

namespace slm
{

    /// Section verifying the metric family's endpoints, its single degenerate
    /// point, and the naive fixed-mass attempt's failure to cross it.
    class ThresholdFieldSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A family of metrics carrying one signature to the other, and why mass alone does not cross it";
        }
        void run(Report &report) const override;
    };

}

#endif
