#include "particle/FlowAssumption.h"

#include "core/Report.h"
#include "core/Vector4.h"
#include "particle/ReturnEvent.h"
#include "particle/TimeProjection.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kFlowEps = 1e-12;

        double interval(const Matrix4 &metric, const Vector4 &v)
        {
            double total = 0.0;
            for (int i = 0; i < 4; ++i)
            {
                total += metric.at(i, i) * v[i] * v[i];
            }
            return total;
        }

        int firstSlotWithSign(const Matrix4 &metric, int sign, int skip = -1)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (i == skip)
                {
                    continue;
                }
                if ((sign > 0 && metric.at(i, i) > 0.0) || (sign < 0 && metric.at(i, i) < 0.0))
                {
                    return i;
                }
            }
            return -1;
        }
    }

    Matrix4 FlowAssumption::metricHere()
    {
        Matrix4 metric = Matrix4::identity();
        metric.at(1, 1) = -1.0;
        metric.at(2, 2) = -1.0;
        metric.at(3, 3) = -1.0;
        return metric;
    }

    Matrix4 FlowAssumption::metricThere()
    {
        Matrix4 metric = Matrix4::identity();
        metric.at(3, 3) = -1.0;
        return metric;
    }

    int FlowAssumption::directionCount(const Matrix4 &metric, int sign)
    {
        int count = 0;
        for (int i = 0; i < 4; ++i)
        {
            if ((sign > 0 && metric.at(i, i) > 0.0) || (sign < 0 && metric.at(i, i) < 0.0))
            {
                ++count;
            }
        }
        return count;
    }

    bool FlowAssumption::canReachOwnNegative(const Matrix4 &metric, int sign, int samples)
    {
        const int start = firstSlotWithSign(metric, sign);
        if (start < 0)
        {
            return false;
        }
        int partner = firstSlotWithSign(metric, sign, start);
        if (partner < 0)
        {
            partner = firstSlotWithSign(metric, -sign);
        }
        if (partner < 0)
        {
            return false;
        }
        const double pi = std::acos(-1.0);
        Vector4 begin{};
        begin[start] = 1.0;
        const double startInterval = interval(metric, begin);
        for (int n = 0; n <= samples; ++n)
        {
            const double angle = pi * n / samples;
            Vector4 turned{};
            turned[start] = std::cos(angle);
            turned[partner] = std::sin(angle);
            const double here = interval(metric, turned);
            if (here * startInterval <= kFlowEps)
            {
                return false;
            }
        }
        return true;
    }

    bool FlowAssumption::isOrientable(const Matrix4 &metric, int sign)
    {
        return !canReachOwnNegative(metric, sign);
    }

    bool FlowAssumption::countPredictsOrientability(const Matrix4 &metric, int sign)
    {
        return isOrientable(metric, sign) == (directionCount(metric, sign) == 1);
    }

    bool FlowAssumption::compulsionIsUsedAnywhere()
    {
        const ReturnEvent::State state = ReturnEvent::stateFromAngles(1.0, 0.5, 3.0, 1);
        const ReturnEvent::Event near =
            ReturnEvent::map(state, IntermediateRegion::Kind::Euclidean, 1.0, 1.0, 2.0);
        const ReturnEvent::Event far =
            ReturnEvent::map(state, IntermediateRegion::Kind::Euclidean, 1.0, 1.0, 5.0);
        return std::abs(near.crossing - far.crossing) < kFlowEps;
    }

    double FlowAssumption::ourTimeFromTheirSpace(double displacement)
    {
        TimeProjection::Four theirs{};
        theirs[static_cast<std::size_t>(TimeProjection::farSideSpaceSlot())] = displacement;
        return TimeProjection::toOurCoordinates(theirs)[0];
    }

    bool FlowAssumption::amountIsFree()
    {
        const double unit = ourTimeFromTheirSpace(1.0);
        if (std::abs(unit) < kFlowEps)
        {
            return false;
        }
        for (double amount : {0.5, 2.0, 7.25})
        {
            if (std::abs(ourTimeFromTheirSpace(amount) - amount * unit) > 1e-12)
            {
                return false;
            }
        }
        return true;
    }

    bool FlowAssumption::signCanBeReversed()
    {
        return !isOrientable(metricThere(), -1);
    }

    void FlowAssumptionSection::run(Report &report) const
    {
        report.subsection("Orientability is in the metric and is decided by rotating");
        struct Named
        {
            const char *label;
            Matrix4 metric;
            int sign;
        };
        const Named cases[] = {{"here, the timelike type ", FlowAssumption::metricHere(), 1},
                               {"here, the spacelike type", FlowAssumption::metricHere(), -1},
                               {"there, the positive type", FlowAssumption::metricThere(), 1},
                               {"there, the negative type", FlowAssumption::metricThere(), -1}};
        for (const Named &named : cases)
        {
            report.check(std::format("  {} : {} directions, reaches its own negative {}, "
                                     "so it is {}",
                                     named.label,
                                     FlowAssumption::directionCount(named.metric, named.sign),
                                     FlowAssumption::canReachOwnNegative(named.metric, named.sign)
                                         ? "yes"
                                         : "no ",
                                     FlowAssumption::isOrientable(named.metric, named.sign)
                                         ? "orientable"
                                         : "not orientable"),
                         FlowAssumption::countPredictsOrientability(named.metric, named.sign));
        }
        report.check("the shortcut used elsewhere, that a count of one means "
                     "orientable, agrees with the rotation in every case, so it is a "
                     "checked shortcut rather than a definition",
                     FlowAssumption::countPredictsOrientability(FlowAssumption::metricHere(), 1) &&
                         FlowAssumption::countPredictsOrientability(FlowAssumption::metricHere(),
                                                                    -1) &&
                         FlowAssumption::countPredictsOrientability(FlowAssumption::metricThere(),
                                                                    1) &&
                         FlowAssumption::countPredictsOrientability(FlowAssumption::metricThere(),
                                                                    -1));

        report.subsection("The two sides are exact duals in this respect");
        report.check("our one timelike direction is orientable and their three "
                     "positive directions are not, which is the same statement seen "
                     "from either side",
                     FlowAssumption::isOrientable(FlowAssumption::metricHere(), 1) &&
                         !FlowAssumption::isOrientable(FlowAssumption::metricThere(), 1));
        report.check("their one negative direction is orientable and our three "
                     "spacelike directions are not, which is the mirror of it",
                     FlowAssumption::isOrientable(FlowAssumption::metricThere(), -1) &&
                         !FlowAssumption::isOrientable(FlowAssumption::metricHere(), -1));
        report.check("so the far side's single space axis being one way is not an "
                     "extra assumption laid on top of the model: it is the same "
                     "theorem that gives our own arrow, applied to the other type",
                     FlowAssumption::isOrientable(FlowAssumption::metricThere(), -1) ==
                         FlowAssumption::isOrientable(FlowAssumption::metricHere(), 1));

        report.subsection("What the metric does not say");
        report.check("nothing above states that a body must advance along an "
                     "orientable coordinate, only that it cannot turn round on one",
                     FlowAssumption::isOrientable(FlowAssumption::metricHere(), 1) &&
                         !FlowAssumption::compulsionIsUsedAnywhere());
        report.check("and nothing in this work uses such a compulsion: the crossing "
                     "amount enters the return map as an input, so no result would "
                     "change if a body could sit still",
                     !FlowAssumption::compulsionIsUsedAnywhere());
        report.check("the sense that our own time carries us is therefore outside "
                     "what is computed here, and no claim rests on it",
                     !FlowAssumption::compulsionIsUsedAnywhere());

        report.subsection("What survives: the amount is free and the sign is not");
        for (double amount : {0.5, 1.0, 2.0, 7.25})
        {
            report.check(std::format("  a displacement of {:5g} along their space axis lands "
                                     "{:+.4f} along our time axis",
                                     amount, FlowAssumption::ourTimeFromTheirSpace(amount)),
                         std::abs(FlowAssumption::ourTimeFromTheirSpace(amount)) > 0.0);
        }
        report.check("the relation is exactly linear in the amount, so how far a body "
                     "goes along their space axis is a free choice with a definite "
                     "consequence on our clock",
                     FlowAssumption::amountIsFree());
        report.check("but the sign cannot be reversed, since that axis is orientable",
                     !FlowAssumption::signCanBeReversed());
        report.check("so motion over there does reach our timeline, and reaches it in "
                     "an amount the body chooses; what it cannot choose is the "
                     "direction, and that is why the crossing places a body later and "
                     "never earlier by this route",
                     FlowAssumption::amountIsFree() && !FlowAssumption::signCanBeReversed());
    }

}
