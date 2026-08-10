#include "scan/PermutationScan.h"

#include "core/Report.h"
#include "transform/SignatureInvolution.h"

#include <algorithm>
#include <array>
#include <format>
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

    void PermutationScan::run(Report &report) const
    {
        const std::vector<Candidate> passing = metricPreserving();

        std::vector<Candidate> involutions;
        std::vector<Candidate> unitDet;
        for (const Candidate &candidate : passing)
        {
            if (candidate.matrix.isInvolution())
            {
                involutions.push_back(candidate);
            }
            if (std::abs(candidate.matrix.determinant() - 1.0) < kEps)
            {
                unitDet.push_back(candidate);
            }
        }
        const std::vector<Candidate> both = admissible();

        report.subsection("Scan: 4! x 2^4 = 384 signed permutation matrices");

        report.check("passing the metric test = 96", passing.size() == 96);
        report.check("of those, involutive = 12", involutions.size() == 12);
        report.check("of those, det = +1 = 8", both.size() == 8);

        report.subsection("The eight solutions: which slot does ct land in?");
        const char *labels[] = {"ct", "x", "y", "z"};
        std::map<int, int> ctSlotHistogram;
        for (const Candidate &candidate : both)
        {
            std::string mapping;
            int ctSlot = -1;
            for (int row = 0; row < 4; ++row)
            {
                mapping += std::format("{}->slot{}{}", labels[candidate.permutation[row]], row,
                                       candidate.signs[row] < 0 ? "(-)" : "");
                if (row != 3)
                {
                    mapping += ", ";
                }
                if (candidate.permutation[row] == 0)
                {
                    ctSlot = row;
                }
            }
            ++ctSlotHistogram[ctSlot];
        }

        const bool allCtToSpace = ctSlotHistogram.size() == 1 && ctSlotHistogram.count(3) == 1;
        report.check("in ALL eight solutions ct maps to the single space axis", allCtToSpace);

        report.subsection("Is D among these eight?");
        const Matrix4 D = SignatureInvolution::matrix();
        const bool contains = std::any_of(both.begin(), both.end(), [&](const Candidate &candidate)
                                          { return candidate.matrix.isEqual(D); });
        report.check("the chosen D is one of the eight solutions found by the scan", contains);
    }
}
