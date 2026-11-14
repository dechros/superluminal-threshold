#include "physics/scan/PermutationScanSection.h"
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

    void PermutationScanSection::run(Report &report) const
    {
        const std::vector<PermutationScan::Candidate> passing = PermutationScan::metricPreserving();

        std::vector<PermutationScan::Candidate> involutions;
        std::vector<PermutationScan::Candidate> unitDet;
        for (const PermutationScan::Candidate &candidate : passing)
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
        const std::vector<PermutationScan::Candidate> both = PermutationScan::admissible();

        report.subsection("Scan: 4! x 2^4 = 384 signed permutation matrices");

        report.check("passing the metric test = 96", passing.size() == 96);
        report.check("of those, involutive = 12", involutions.size() == 12);
        report.check("of those, det = +1 = 8", both.size() == 8);

        report.subsection("The eight solutions: which slot does ct land in?");
        constexpr std::array<std::string_view, 4> labels{"ct", "x", "y", "z"};
        std::map<int, int> ctSlotHistogram;
        for (const PermutationScan::Candidate &candidate : both)
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
        const bool contains = std::any_of(both.begin(), both.end(), [&](const PermutationScan::Candidate &candidate)
                                          { return candidate.matrix.isEqual(D); });
        report.check("the chosen D is one of the eight solutions found by the scan", contains);
    }
}
