#ifndef SLM_CHECKS_JOURNEY_JOURNEYSTATESECTION_H
#define SLM_CHECKS_JOURNEY_JOURNEYSTATESECTION_H

#include "core/Section.h"
#include "journey/JourneyState.h"

#include <string>

namespace slm
{

    /// Section checking that the sampled trip is continuous across every phase
    /// join, starts and ends in the traveller's own state, reaches the chosen
    /// far-side distance, and ends with the clock shift the round trip
    /// establishes.
    class JourneyStateSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The round trip sampled for the viewer, continuous across its phases and ending where the trip ends";
        }

        void run(Report &report) const override;
    };

}

#endif
