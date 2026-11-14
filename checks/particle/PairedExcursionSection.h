#ifndef SLM_CHECKS_PARTICLE_PAIREDEXCURSIONSECTION_H
#define SLM_CHECKS_PARTICLE_PAIREDEXCURSIONSECTION_H

#include "core/Section.h"
#include "particle/PairedExcursion.h"

#include <string>

namespace slm
{

    /// Section verifying that one apparatus reaches both directions in time,
    /// that only the backward direction carries a minimum distance, and that
    /// the gap between the two particles is free of the crossing.
    class PairedExcursionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "One apparatus, two directions in time, and what the thickness of the wall costs each of them";
        }
        void run(Report &report) const override;
    };

}

#endif
