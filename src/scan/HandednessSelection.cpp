#include "scan/HandednessSelection.h"

#include "core/Report.h"
#include "scan/PermutationScan.h"
#include "transform/SignatureInvolution.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{

    double HandednessSelection::freeBlockDeterminant(const Matrix4 &matrix)
    {
        const double a = matrix.at(1, 0);
        const double b = matrix.at(1, 1);
        const double c = matrix.at(1, 2);
        const double d = matrix.at(2, 0);
        const double e = matrix.at(2, 1);
        const double f = matrix.at(2, 2);
        const double g = matrix.at(3, 0);
        const double h = matrix.at(3, 1);
        const double k = matrix.at(3, 2);
        return a * (e * k - f * h) - b * (d * k - f * g) + c * (d * h - e * g);
    }

    double HandednessSelection::nearTimeCoefficient(const Matrix4 &matrix)
    {
        return matrix.at(0, 3);
    }

    bool HandednessSelection::preservesHandedness(const Matrix4 &matrix)
    {
        return freeBlockDeterminant(matrix) > 0.0;
    }

    std::vector<Matrix4> HandednessSelection::selected()
    {
        std::vector<Matrix4> kept;
        for (const PermutationScan::Candidate &candidate : PermutationScan::admissible())
        {
            if (preservesHandedness(candidate.matrix))
            {
                kept.push_back(candidate.matrix);
            }
        }
        return kept;
    }

    Matrix4 HandednessSelection::exchange()
    {
        return Matrix4::diagonal(-1.0, 1.0, 1.0, -1.0);
    }

    void HandednessSelectionSection::run(Report &report) const
    {
        const std::vector<PermutationScan::Candidate> eight = PermutationScan::admissible();

        report.subsection("The lock between handedness and the direction of the time difference");
        report.check(std::format("the three earlier filters leave {} maps", eight.size()),
                     eight.size() == 8);
        bool lockHolds = true;
        for (const PermutationScan::Candidate &candidate : eight)
        {
            const double block = HandednessSelection::freeBlockDeterminant(candidate.matrix);
            const double time = HandednessSelection::nearTimeCoefficient(candidate.matrix);
            report.checkNear(std::format("  free block determinant {:+.0f}, near-side time "
                                         "coefficient {:+.0f}, product",
                                         block, time),
                             block * time + 1.0, 1e-12);
            if (std::abs(block * time + 1.0) > 1e-12)
            {
                lockHolds = false;
            }
        }
        report.check("in all eight the two multiply to minus one, so neither may be chosen "
                     "without the other following",
                     lockHolds);

        report.subsection("Applying the filter");
        const std::vector<Matrix4> kept = HandednessSelection::selected();
        report.check(std::format("demanding a proper free block leaves {} of the eight",
                                 kept.size()),
                     kept.size() == 4);
        bool allRecoverTime = true;
        for (const Matrix4 &matrix : kept)
        {
            const double time = HandednessSelection::nearTimeCoefficient(matrix);
            report.checkNear("  a positive step along the far-side space axis lands one unit "
                             "earlier on the near-side clock",
                             time + 1.0, 1e-12);
            if (std::abs(time + 1.0) > 1e-12)
            {
                allRecoverTime = false;
            }
        }
        report.check("every surviving map recovers time rather than spending it, so the "
                     "direction is now a result of the filters and not a choice made after "
                     "them",
                     allRecoverTime && kept.size() == 4);

        report.subsection("What the rejected family carries instead");
        int rejected = 0;
        for (const PermutationScan::Candidate &candidate : eight)
        {
            if (!HandednessSelection::preservesHandedness(candidate.matrix))
            {
                ++rejected;
                report.checkNear("  a rejected map reflects the free directions and sends the "
                                 "same step later",
                                 HandednessSelection::nearTimeCoefficient(candidate.matrix) - 1.0,
                                 1e-12);
            }
        }
        report.check(std::format("the {} rejected maps each contain a reflection, which no "
                                 "continuous crossing can reach",
                                 rejected),
                     rejected == 4);

        report.subsection("The two families differ by one reflection the earlier filters could "
                          "not see");
        const Matrix4 exchange = HandednessSelection::exchange();
        report.checkNear("the exchanging matrix has unit determinant, which is why the third "
                         "filter kept both families",
                         exchange.determinant() - 1.0, 1e-12);
        report.check("it is an involution", exchange.isInvolution());
        report.checkNear("it reverses the near-side clock", exchange.at(0, 0) + 1.0, 1e-12);
        report.checkNear("and one near-side space direction with it", exchange.at(3, 3) + 1.0,
                         1e-12);
        int mapped = 0;
        for (const PermutationScan::Candidate &candidate : eight)
        {
            const Matrix4 image = exchange * candidate.matrix;
            const bool inSet =
                std::any_of(eight.begin(), eight.end(),
                            [&](const PermutationScan::Candidate &other)
                            { return other.matrix.isEqual(image); });
            const bool flipped =
                HandednessSelection::preservesHandedness(image) !=
                HandednessSelection::preservesHandedness(candidate.matrix);
            report.check("  multiplying by it stays inside the eight and crosses to the other "
                         "family",
                         inSet && flipped);
            if (inSet && flipped)
            {
                ++mapped;
            }
        }
        report.check(std::format("all {} are exchanged in pairs, so the split is one "
                                 "reflection wide and nothing else",
                                 mapped),
                     mapped == 8);

        report.subsection("Where this leaves the matrix the earlier sections used");
        const Matrix4 d = SignatureInvolution::matrix();
        const Matrix4 sd = exchange * d;
        report.check("the plain involution reflects the free directions and is now rejected",
                     !HandednessSelection::preservesHandedness(d));
        report.check("its reflection survives the filter",
                     HandednessSelection::preservesHandedness(sd));
        report.check("and it is the matrix the time projection already used, which the filter "
                     "now forces rather than permits",
                     std::any_of(kept.begin(), kept.end(),
                                 [&](const Matrix4 &matrix) { return matrix.isEqual(sd); }));

        report.subsection("What freedom is left, and whether anything physical rests on it");
        double worstSpread = 0.0;
        for (const Matrix4 &matrix : kept)
        {
            worstSpread = std::max(worstSpread,
                                   std::abs(HandednessSelection::nearTimeCoefficient(matrix) -
                                            HandednessSelection::nearTimeCoefficient(kept.front())));
        }
        report.checkNear("the four survivors differ only in which far-side time carries which "
                         "near-side direction, and agree exactly on the coefficient that sets "
                         "the time difference",
                         worstSpread, 1e-12);
    }

}
