#ifndef SLM_CHECKS_PHYSICS_TRANSFORM_RELABELLINGOBSTRUCTIONSECTION_H
#define SLM_CHECKS_PHYSICS_TRANSFORM_RELABELLINGOBSTRUCTIONSECTION_H

#include "core/Section.h"
#include "physics/transform/RelabellingObstruction.h"

#include <string>

namespace slm
{

    /// Section verifying that the relabelling costs the particle its real mass,
    /// that the count of free directions separates the two regions while the
    /// particle is held fixed, and that no continuous path relabels one into
    /// the other.
    class RelabellingObstructionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Why the far region is not the near one relabelled, once the particle is counted as part of the region";
        }
        void run(Report &report) const override;
    };

}

#endif
