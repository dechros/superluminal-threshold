#ifndef SLM_CHECKS_PHYSICS_TRANSFORM_SIGNATUREINVOLUTIONSECTION_H
#define SLM_CHECKS_PHYSICS_TRANSFORM_SIGNATUREINVOLUTIONSECTION_H

#include "core/Section.h"
#include "physics/transform/SignatureInvolution.h"

#include <string>

namespace slm
{

    /// Section running the checks on SignatureInvolution.
    class SignatureInvolutionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Factorisation, the matrix D and group closure";
        }

        void run(Report &report) const override;
    };

}

#endif
