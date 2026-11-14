#ifndef SLM_CHECKS_PARTICLE_TIMEPROJECTIONSECTION_H
#define SLM_CHECKS_PARTICLE_TIMEPROJECTIONSECTION_H

#include "core/Section.h"
#include "particle/TimeProjection.h"

#include <string>

namespace slm
{

    /// Section computing what motion along each far-side coordinate means here.
    class TimeProjectionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Which coordinates can be moved in, which only flow, and what that means here";
        }
        void run(Report &report) const override;
    };

}

#endif
