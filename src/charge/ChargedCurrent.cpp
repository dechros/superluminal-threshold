#include "charge/ChargedCurrent.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{

    Vector4 ChargedCurrent::nearSideCurrent(double c, double chargeDensity, double jx, double jy,
                                            double jz)
    {
        return Vector4(chargeDensity * c, jx, jy, jz);
    }

    Vector4 ChargedCurrent::farSideCurrent(const Vector4 &near)
    {
        const Matrix4 d = SignatureInvolution::matrix();
        Vector4 far(0.0, 0.0, 0.0, 0.0);
        for (std::size_t row = 0; row < 4; ++row)
        {
            double sum = 0.0;
            for (std::size_t column = 0; column < 4; ++column)
            {
                sum += d.at(row, column) * near[column];
            }
            far[row] = sum;
        }
        return far;
    }

    bool ChargedCurrent::densityBecomesCurrent(const Vector4 &near)
    {
        const Vector4 far = farSideCurrent(near);
        return std::abs(far[3] - near[0]) < 1e-12 && std::abs(far[0] - near[3]) < 1e-12;
    }

    double ChargedCurrent::currentInvariant(const Vector4 &current, bool farSide)
    {
        return current.contract(farSide ? metricRegionII() : metricRegionI());
    }

    bool ChargedCurrent::invariantSurvives(const Vector4 &near, double tolerance)
    {
        const double here = currentInvariant(near, false);
        const double there = currentInvariant(farSideCurrent(near), true);
        return std::abs(there + here) < tolerance;
    }

    void ChargedCurrentSection::run(Report &report) const
    {
        report.subsection("What charge means on the far side");
        const Vector4 near = ChargedCurrent::nearSideCurrent(1.0, 3.0, 0.0, 0.0, 0.5);
        const Vector4 far = ChargedCurrent::farSideCurrent(near);
        report.check(std::format("  the near-side four-current is ({:.1f}, {:.1f}, {:.1f}, {:.1f})",
                                 near[0], near[1], near[2], near[3]),
                     true);
        report.check(std::format("  the far side writes it as ({:.1f}, {:.1f}, {:.1f}, {:.1f})",
                                 far[0], far[1], far[2], far[3]),
                     true);
        report.check("the near side's charge density has become a far-side current component and "
                     "one of its currents has become the density, because the crossing carries "
                     "the time axis onto a space axis and the density is the time component",
                     ChargedCurrent::densityBecomesCurrent(near));
        report.check("so asking how much charge sits over there is not the question it is here: "
                     "the four-current maps whole, and only its split into density and current is "
                     "reshuffled",
                     ChargedCurrent::densityBecomesCurrent(near));
        report.check("the invariant square of the four-current is carried across up to the overall "
                     "sign the crossing imposes, which is what conservation of the current amounts "
                     "to here and is weaker than equality",
                     ChargedCurrent::invariantSurvives(near, 1e-12));
    }

}
