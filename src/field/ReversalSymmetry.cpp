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

    int ReversalSymmetry::soleMinorityAxis(const Matrix4 &metric)
    {
        int positives = 0;
        int positiveAxis = -1;
        int negativeAxis = -1;
        int negatives = 0;
        for (int axis = 0; axis < 4; ++axis)
        {
            const double entry =
                metric.at(static_cast<std::size_t>(axis), static_cast<std::size_t>(axis));
            if (entry > 0.0)
            {
                ++positives;
                positiveAxis = axis;
            }
            else if (entry < 0.0)
            {
                ++negatives;
                negativeAxis = axis;
            }
        }
        if (positives == 1 && negatives == 3)
        {
            return positiveAxis;
        }
        if (negatives == 1 && positives == 3)
        {
            return negativeAxis;
        }
        return -1;
    }

    bool ReversalSymmetry::minoritySetIsSplit(const Matrix4 &metric)
    {
        const int axis = soleMinorityAxis(metric);
        if (axis < 0)
        {
            return false;
        }

        const double sign =
            metric.at(static_cast<std::size_t>(axis), static_cast<std::size_t>(axis)) > 0.0 ? 1.0
                                                                                            : -1.0;
        const Matrix4 aligned = sign > 0.0 ? metric : -metric;
        const int other = axis == 0 ? 1 : 0;
        return TimeOrientation::worstIntervalAlongRotation(aligned, axis, other) < 0.0;
    }

    bool ReversalSymmetry::labelIsGeometric(const Matrix4 &metric)
    {
        const int axis = soleMinorityAxis(metric);
        if (axis < 0)
        {
            return false;
        }
        if (!isIsometry(metric, axis))
        {
            return true;
        }

        const double sign =
            metric.at(static_cast<std::size_t>(axis), static_cast<std::size_t>(axis)) > 0.0 ? 1.0
                                                                                            : -1.0;
        const Matrix4 aligned = sign > 0.0 ? metric : -metric;
        Vector4 unit{};
        unit[static_cast<std::size_t>(axis)] = 1.0;
        return !exchangesComponents(aligned, axis, unit);
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

        report.subsection("The same statement without a preference for which sign is time");
        report.check("region I has one axis in the minority, and it is the time axis",
                     ReversalSymmetry::soleMinorityAxis(eta) == 0);
        report.check("region II has one too, and it is its single space axis",
                     ReversalSymmetry::soleMinorityAxis(etaPrime) == 3);
        report.check("negating a metric does not move its distinguished axis, so the axis "
                     "does not depend on which sign the convention calls time",
                     ReversalSymmetry::soleMinorityAxis(-eta) ==
                             ReversalSymmetry::soleMinorityAxis(eta) &&
                         ReversalSymmetry::soleMinorityAxis(-etaPrime) ==
                             ReversalSymmetry::soleMinorityAxis(etaPrime));

        report.subsection("Both distinguished axes carry a split");
        report.check("region I: the set attached to the time axis falls into two components",
                     ReversalSymmetry::minoritySetIsSplit(eta));
        report.check("region II: the set attached to its space axis does the same",
                     ReversalSymmetry::minoritySetIsSplit(etaPrime));

        report.subsection("And neither split is labelled by its metric");
        report.check("region I: the label on future against past is not geometric",
                     !ReversalSymmetry::labelIsGeometric(eta));
        report.check("region II: the label on the two ends of its space line is not either",
                     !ReversalSymmetry::labelIsGeometric(etaPrime));
        report.check("reversing region II's distinguished axis is an isometry of its metric",
                     ReversalSymmetry::isIsometry(etaPrime, 3));
        report.check("so the asymmetry between the regions is which character the "
                     "distinguished axis has, and not whether its label is geometric",
                     ReversalSymmetry::soleMinorityAxis(eta) !=
                             ReversalSymmetry::soleMinorityAxis(etaPrime) &&
                         !ReversalSymmetry::labelIsGeometric(eta) &&
                         !ReversalSymmetry::labelIsGeometric(etaPrime));
    }

}
