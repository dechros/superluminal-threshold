#include "field/ReversalSymmetry.h"

#include "core/Report.h"
#include "field/TimeOrientation.h"

#include <cmath>
#include <format>

namespace slm
{

    Matrix4 ReversalSymmetry::axisReversal(int axis)
    {
        Matrix4 result = Matrix4::identity();
        if (axis >= 0 && axis < 4)
        {
            result.at(static_cast<std::size_t>(axis), static_cast<std::size_t>(axis)) = -1.0;
        }
        return result;
    }

    bool ReversalSymmetry::isIsometry(const Matrix4 &metric, int axis)
    {
        return axisReversal(axis).congruence(metric).isEqual(metric, kEps);
    }

    int ReversalSymmetry::isometricReversalCount(const Matrix4 &metric)
    {
        int count = 0;
        for (int axis = 0; axis < 4; ++axis)
        {
            if (isIsometry(metric, axis))
            {
                ++count;
            }
        }
        return count;
    }

    bool ReversalSymmetry::exchangesComponents(const Matrix4 &metric, int axis,
                                               const Vector4 &timelike)
    {
        if (axis < 0 || axis >= 4)
        {
            return false;
        }
        if (!TimeOrientation::isTimelike(metric, timelike))
        {
            return false;
        }

        const Vector4 image = axisReversal(axis) * timelike;
        const std::size_t index = static_cast<std::size_t>(axis);
        const bool stillTimelike = TimeOrientation::isTimelike(metric, image);
        const bool signFlipped = timelike[index] * image[index] < 0.0;
        return stillTimelike && signFlipped;
    }

    int ReversalSymmetry::soleTimeAxis(const Matrix4 &metric)
    {
        int found = -1;
        int count = 0;
        for (int axis = 0; axis < 4; ++axis)
        {
            if (metric.at(static_cast<std::size_t>(axis), static_cast<std::size_t>(axis)) > 0.0)
            {
                found = axis;
                ++count;
            }
        }
        return count == 1 ? found : -1;
    }

    bool ReversalSymmetry::geometryFixesOrientation(const Matrix4 &metric)
    {
        const int axis = soleTimeAxis(metric);
        if (axis < 0)
        {
            return false;
        }
        if (!isIsometry(metric, axis))
        {
            return true;
        }

        Vector4 unit{};
        unit[static_cast<std::size_t>(axis)] = 1.0;
        return !exchangesComponents(metric, axis, unit);
    }

    void ReversalSymmetrySection::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();

        report.subsection("Region I: the split exists");
        report.check("a single positive direction, so timelike vectors fall into two components",
                     TimeOrientation::admitsTimeOrientation(eta));
        report.check("the positive axis is axis 0", ReversalSymmetry::soleTimeAxis(eta) == 0);

        report.subsection("Reversing that axis is a symmetry of the metric");
        const Matrix4 reversal = ReversalSymmetry::axisReversal(0);
        report.checkNear("T^T eta T = eta, so T is an isometry",
                         reversal.congruence(eta).maxAbsDifference(eta));
        report.check("T is an involution, so it pairs the components rather than ordering them",
                     reversal.isInvolution());
        report.check("all four single-axis reversals are isometries of a diagonal metric",
                     ReversalSymmetry::isometricReversalCount(eta) == 4);

        report.subsection("And it carries each component onto the other");
        const Vector4 future(1.0, 0.0, 0.0, 0.0);
        const Vector4 past = reversal * future;
        report.check("(1,0,0,0) is timelike", TimeOrientation::isTimelike(eta, future));
        report.check("its image is timelike as well", TimeOrientation::isTimelike(eta, past));
        report.checkNear("the image is the negative of the original",
                         (past + future).norm());
        report.check("the two are in different components, since the sign of the time "
                     "component differs and no timelike path connects them",
                     ReversalSymmetry::exchangesComponents(eta, 0, future));
        report.checkNear("the interval is unchanged, so no metric quantity distinguishes them",
                         past.contract(eta) - future.contract(eta));

        report.subsection("Therefore the geometry does not name a future");
        report.check("region I: the split is real but the label on it is not geometric",
                     !ReversalSymmetry::geometryFixesOrientation(eta));

        report.subsection("Region II: there is not even a split to label");
        report.check("three positive directions, so no consistent split exists",
                     !TimeOrientation::admitsTimeOrientation(etaPrime));
        report.check("no sole time axis to reverse",
                     ReversalSymmetry::soleTimeAxis(etaPrime) == -1);
        report.check("so the question of which component is the future does not arise",
                     !ReversalSymmetry::geometryFixesOrientation(etaPrime));

        report.subsection("What this leaves");
        report.check("the two statements are independent: a split can exist without a "
                     "geometric label, which is region I, and a label cannot exist "
                     "without a split, which is region II",
                     TimeOrientation::admitsTimeOrientation(eta) &&
                         !ReversalSymmetry::geometryFixesOrientation(eta) &&
                         !TimeOrientation::admitsTimeOrientation(etaPrime));
    }

}
