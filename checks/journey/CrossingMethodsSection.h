#ifndef SLM_CHECKS_JOURNEY_CROSSINGMETHODSSECTION_H
#define SLM_CHECKS_JOURNEY_CROSSINGMETHODSSECTION_H

#include "core/Section.h"
#include "journey/CrossingMethods.h"

#include <string>

namespace slm
{

    /// Section trying every way on every traveller and recording what each
    /// mechanics supplies, what completes it, whether it passes light speed,
    /// and which way the round trips therefore use.
    class CrossingMethodsSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Six ways across the threshold, what each needs to be completed, and the one chosen for each traveller";
        }

        void run(Report &report) const override;
    };

}

#endif
