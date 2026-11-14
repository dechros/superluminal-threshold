#ifndef SLM_CHECKS_PARTICLE_CONTINUOUSCROSSINGSECTION_H
#define SLM_CHECKS_PARTICLE_CONTINUOUSCROSSINGSECTION_H

#include "core/Section.h"
#include "particle/ContinuousCrossing.h"

#include <string>

namespace slm
{

    /// Section verifying the constant-force crossing of theta, its guaranteed
    /// reach past the degenerate point, and the same trajectory read as a
    /// return to theta = 0.
    class ContinuousCrossingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A constant force along the crossing angle, and the crossing it guarantees";
        }
        void run(Report &report) const override;
    };

}

#endif
