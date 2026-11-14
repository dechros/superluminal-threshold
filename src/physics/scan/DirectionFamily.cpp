#include "physics/scan/DirectionFamily.h"

#include "core/Report.h"
#include "physics/scan/PermutationScan.h"
#include "physics/transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{
    bool DirectionFamily::Outcome::sendsLater() const
    {
        return fromPositiveStep > 0.0;
    }

    namespace
    {
        double nearTimeFromSpaceStep(const Matrix4 &matrix, double step)
        {
            return matrix.at(0, 3) * step;
        }
    }

    std::vector<DirectionFamily::Outcome> DirectionFamily::outcomes()
    {
        std::vector<Outcome> result;
        for (const PermutationScan::Candidate &candidate : PermutationScan::admissible())
        {
            Outcome outcome;
            outcome.matrix = candidate.matrix;
            outcome.fromPositiveStep = nearTimeFromSpaceStep(candidate.matrix, 1.0);
            outcome.fromNegativeStep = nearTimeFromSpaceStep(candidate.matrix, -1.0);
            result.push_back(outcome);
        }
        return result;
    }
}
