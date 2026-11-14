#ifndef SLM_CHECKS_PARTICLE_ACCELERATEDCROSSINGSECTION_H
#define SLM_CHECKS_PARTICLE_ACCELERATEDCROSSINGSECTION_H

#include "core/Section.h"
#include "particle/AcceleratedCrossing.h"

#include <string>

namespace slm
{

    /// Section verifying the constant-force crossing and its guaranteed reach.
    class AcceleratedCrossingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A constant force along the single space axis, and the crossing it guarantees";
        }
        void run(Report &report) const override;
    };

}

#endif
