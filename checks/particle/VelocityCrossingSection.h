#ifndef SLM_CHECKS_PARTICLE_VELOCITYCROSSINGSECTION_H
#define SLM_CHECKS_PARTICLE_VELOCITYCROSSINGSECTION_H

#include "core/Section.h"
#include "particle/VelocityCrossing.h"

#include <string>

namespace slm
{

    /// Section proving that the standard shell forbids the crossing and locates
    /// the obstruction at the metric's degeneracy, that the extended shell
    /// carries the particle across at finite cost, and that running the curve
    /// backwards returns the same particle below light speed.
    class VelocityCrossingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The crossing in the particle's own speed, with accelerating and decelerating as the only mechanism";
        }
        void run(Report &report) const override;
    };

}

#endif
