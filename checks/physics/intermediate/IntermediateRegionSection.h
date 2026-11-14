#ifndef SLM_CHECKS_PHYSICS_INTERMEDIATE_INTERMEDIATEREGIONSECTION_H
#define SLM_CHECKS_PHYSICS_INTERMEDIATE_INTERMEDIATEREGIONSECTION_H

#include "core/Section.h"
#include "physics/intermediate/IntermediateRegion.h"

#include <string>

namespace slm
{

    /// Section computing the crossing for every kind and thickness.
    class IntermediateRegionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The intermediate region: four kinds against five thicknesses";
        }
        void run(Report &report) const override;
    };

}

#endif
