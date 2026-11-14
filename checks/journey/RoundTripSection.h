#ifndef SLM_CHECKS_JOURNEY_ROUNDTRIPSECTION_H
#define SLM_CHECKS_JOURNEY_ROUNDTRIPSECTION_H

#include "core/Section.h"
#include "journey/RoundTrip.h"

#include <string>

namespace slm
{

    /// Section running the six trips: three travellers, each driven along
    /// @f$ +r @f$ and along @f$ -r @f$, and checking what each one establishes.
    class RoundTripSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Six round trips: a massless particle, an atom and a molecule, each sent backward and forward in time";
        }

        void run(Report &report) const override;
    };

}

#endif
