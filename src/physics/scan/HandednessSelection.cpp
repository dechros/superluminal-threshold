#include "physics/scan/HandednessSelection.h"

#include "core/Report.h"
#include "physics/scan/PermutationScan.h"
#include "physics/transform/SignatureInvolution.h"

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
}
