#include "physics/scan/PermutationScan.h"

#include "core/Report.h"
#include "physics/transform/SignatureInvolution.h"

#include <algorithm>
#include <array>
#include <format>
#include <string_view>
#include <map>
#include <string>

namespace slm
{
    std::vector<PermutationScan::Candidate> PermutationScan::metricPreserving()
    {
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();

        std::vector<Candidate> found;
        std::array<int, 4> perm{0, 1, 2, 3};

        do
        {
            for (int mask = 0; mask < 16; ++mask)
            {
                Candidate candidate;
                candidate.permutation = perm;
                candidate.matrix = Matrix4::zero();

                for (int row = 0; row < 4; ++row)
                {
                    const int sign = ((mask >> row) & 1) ? -1 : 1;
                    candidate.signs[row] = sign;
                    candidate.matrix.at(row, perm[row]) = sign;
                }

                if (candidate.matrix.flipsMetric(eta, etaPrime))
                {
                    found.push_back(candidate);
                }
            }
        } while (std::next_permutation(perm.begin(), perm.end()));

        return found;
    }

    std::vector<PermutationScan::Candidate> PermutationScan::admissible()
    {
        std::vector<Candidate> found;
        for (const Candidate &candidate : metricPreserving())
        {
            const bool isInvolution = candidate.matrix.isInvolution();
            const bool isUnitDet = std::abs(candidate.matrix.determinant() - 1.0) < kEps;
            if (isInvolution && isUnitDet)
            {
                found.push_back(candidate);
            }
        }
        return found;
    }
}
