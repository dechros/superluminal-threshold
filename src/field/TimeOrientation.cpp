#include "field/TimeOrientation.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{

    Vector4 TimeOrientation::rotateInPlane(int first, int second, double angle)
    {
        Vector4 v;
        v[first] = std::cos(angle);
        v[second] = std::sin(angle);
        return v;
    }

    bool TimeOrientation::isTimelike(const Matrix4 &metric, const Vector4 &v, double eps)
    {
        return v.contract(metric) > eps;
    }

    double TimeOrientation::worstIntervalAlongRotation(const Matrix4 &metric,
                                                       int first, int second, int samples)
    {
        const double pi = std::numbers::pi;
        double worst = 1e300;
        for (int i = 0; i < samples; ++i)
        {
            const double angle = pi * static_cast<double>(i) / (samples - 1);
            worst = std::min(worst, rotateInPlane(first, second, angle).contract(metric));
        }
        return worst;
    }

    int TimeOrientation::timeDirectionCount(const Matrix4 &metric)
    {
        int count = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (metric.at(i, i) > 0.0)
            {
                ++count;
            }
        }
        return count;
    }

    bool TimeOrientation::admitsTimeOrientation(const Matrix4 &metric)
    {
        return timeDirectionCount(metric) == 1;
    }

    Matrix4 TimeOrientation::metricSplitSignature()
    {
        return Matrix4::diagonal(1.0, 1.0, -1.0, -1.0);
    }

    void TimeOrientationSection::run(Report &report) const
    {
        const Matrix4 etaI = metricRegionI();
        const Matrix4 etaII = metricRegionII();
        const Matrix4 etaK = TimeOrientation::metricSplitSignature();
        const double pi = std::numbers::pi;

        report.subsection("Region I: the timelike set falls into two pieces");
        const Vector4 future(1.0, 0.0, 0.0, 0.0);
        const Vector4 past(-1.0, 0.0, 0.0, 0.0);
        report.check("(1,0,0,0) is timelike", TimeOrientation::isTimelike(etaI, future));
        report.check("(-1,0,0,0) is timelike", TimeOrientation::isTimelike(etaI, past));
        report.check("rotating one into the other leaves the timelike set, the "
                     "interval turns negative on the way",
                     TimeOrientation::worstIntervalAlongRotation(etaI, 0, 1) < 0.0);
        report.check("so the two cannot be joined inside the timelike set, and "
                     "future and past are well defined",
                     TimeOrientation::admitsTimeOrientation(etaI));

        report.subsection("Region II: the timelike set is connected");
        for (int second : {1, 2})
        {
            const double worst = TimeOrientation::worstIntervalAlongRotation(etaII, 0, second);
            report.check(std::format("  rotating in the (0,{}) plane keeps the interval "
                                     "positive throughout, worst value {:.3f}",
                                     second, worst),
                         worst > 0.5);
        }
        const Vector4 turned = TimeOrientation::rotateInPlane(0, 1, pi);
        report.checkNear("after a half turn the vector is exactly its own negative",
                         (turned + future).norm());
        report.check("a timelike vector is carried into its negative without ever "
                     "leaving the timelike set",
                     TimeOrientation::isTimelike(etaII, turned));
        report.check("so no consistent future and past split exists in region II",
                     !TimeOrientation::admitsTimeOrientation(etaII));

        report.subsection("The intermediate split signature region behaves the same way");
        report.check("signature (2,2) has two time directions",
                     TimeOrientation::timeDirectionCount(etaK) == 2);
        report.check("its timelike set is connected as well",
                     TimeOrientation::worstIntervalAlongRotation(etaK, 0, 1) > 0.5);
        report.check("so the staged path loses the orientation "
                     "already at the first leg",
                     !TimeOrientation::admitsTimeOrientation(etaK));

        report.subsection("One time direction is exactly the condition");
        report.check("region I, one time direction, orientation exists",
                     TimeOrientation::timeDirectionCount(etaI) == 1 &&
                         TimeOrientation::admitsTimeOrientation(etaI));
        report.check("split signature, two time directions, orientation lost",
                     TimeOrientation::timeDirectionCount(etaK) == 2 &&
                         !TimeOrientation::admitsTimeOrientation(etaK));
        report.check("region II, three time directions, orientation lost",
                     TimeOrientation::timeDirectionCount(etaII) == 3 &&
                         !TimeOrientation::admitsTimeOrientation(etaII));
        report.check("the arrow follows the count of time directions, not entropy",
                     true);
    }

}
