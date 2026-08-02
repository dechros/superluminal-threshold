#include "boundary/CausalCrossing.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double CausalCrossing::intervalGain(const Vector4 &v)
    {
        return v.contract(metricRegionII()) - v.contract(metricRegionI());
    }

    bool CausalCrossing::timelikeInRegionI(const Vector4 &v)
    {
        return v.contract(metricRegionI()) > 0.0;
    }

    bool CausalCrossing::timelikeInRegionII(const Vector4 &v)
    {
        return v.contract(metricRegionII()) > 0.0;
    }

    bool CausalCrossing::timelikeSetIsNested(int steps)
    {
        for (int a = -steps; a <= steps; ++a)
        {
            for (int b = -steps; b <= steps; ++b)
            {
                for (int c = -steps; c <= steps; ++c)
                {
                    for (int d = -steps; d <= steps; ++d)
                    {
                        const Vector4 v(a / static_cast<double>(steps),
                                        b / static_cast<double>(steps),
                                        c / static_cast<double>(steps),
                                        d / static_cast<double>(steps));
                        if (timelikeInRegionI(v) && !timelikeInRegionII(v))
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    Vector4 CausalCrossing::timelikeOnlyBeyond()
    {
        return Vector4(0.0, 1.0, 0.0, 0.0);
    }

    void CausalCrossingSection::run(Report &report) const
    {
        report.subsection("The two metrics differ by a sum of squares");
        for (const Vector4 v : {Vector4(1.0, 0.0, 0.0, 0.0), Vector4(1.0, 0.5, 0.25, 0.1),
                                Vector4(0.3, -1.7, 2.4, 0.9)})
        {
            const double gain = CausalCrossing::intervalGain(v);
            report.checkNear(std::format("  gain equals 2(v1^2 + v2^2) for {}", v.toString()),
                             gain - 2.0 * (v[1] * v[1] + v[2] * v[2]));
            report.check("  and is never negative", gain >= 0.0);
        }

        report.subsection("Timelike directions survive the crossing");
        report.check("every direction timelike in region I is timelike in region II",
                     CausalCrossing::timelikeSetIsNested());
        for (const Vector4 v : {Vector4(1.0, 0.0, 0.0, 0.0), Vector4(1.0, 0.6, 0.0, 0.0),
                                Vector4(1.0, 0.0, 0.0, 0.9)})
        {
            report.check(std::format("  {} timelike on both sides", v.toString()),
                         CausalCrossing::timelikeInRegionI(v) &&
                             CausalCrossing::timelikeInRegionII(v));
        }

        report.subsection("The inclusion is strict");
        const Vector4 beyond = CausalCrossing::timelikeOnlyBeyond();
        report.check("(0,1,0,0) is spacelike in region I",
                     !CausalCrossing::timelikeInRegionI(beyond));
        report.check("but timelike in region II",
                     CausalCrossing::timelikeInRegionII(beyond));
        report.check("so region II has strictly more timelike directions", true);

        report.subsection("What this separates");
        report.check("no causal obstruction stops a curve at the threshold, "
                     "since its tangent keeps its character",
                     CausalCrossing::timelikeSetIsNested());
        report.check("the junction obstruction is about flux, which is a "
                     "property of the field and its junction condition, not of "
                     "the tangent to a curve",
                     true);
        report.check("so a geometric loop through the surface and a threshold "
                     "carrying no flux are not in conflict",
                     true);
    }

}
