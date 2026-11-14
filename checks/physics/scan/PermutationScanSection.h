#ifndef SLM_CHECKS_PHYSICS_SCAN_PERMUTATIONSCANSECTION_H
#define SLM_CHECKS_PHYSICS_SCAN_PERMUTATIONSCANSECTION_H

#include "core/Section.h"
#include "physics/scan/PermutationScan.h"

#include <string>

namespace slm
{

    /// Section running the checks on PermutationScan.
    class PermutationScanSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Scan over the 384 signed permutation matrices";
        }

        void run(Report &report) const override;
    };

}

#endif
