#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    /// Whether a coordinate is one way, and whether that is the same thing as
    /// being dragged along it.
    ///
    /// It is easy to write down that a coordinate "flows", and harder to say
    /// what was claimed. Two separate statements hide inside the word and they
    /// have different standing:
    ///
    /// ORIENTABILITY. The directions of a given causal type fall into two
    /// pieces that cannot be joined without leaving the type, so one end can be
    /// told from the other and no motion carries a body from one to the other.
    /// This is a statement about the metric and it is decidable: rotate a unit
    /// vector of that type through half a turn, which carries it into its own
    /// negative, and watch whether the interval ever changes sign on the way.
    ///
    /// COMPULSION. A body must move along the coordinate, at a rate it cannot
    /// choose. This is not a statement about the metric. Nothing in a metric
    /// says that a worldline has to advance, and the sense that our own time
    /// carries us is not evidence that it does.
    ///
    /// The two are routinely run together, and the cost of running them
    /// together is a hidden assumption. This class separates them, decides the
    /// first by computation for every causal type on both sides, and shows that
    /// the second is used by nothing here. What is left after the separation is
    /// a sharper statement than either: along a coordinate that is orientable,
    /// how far a body goes is free and which way it goes is not.
    class FlowAssumption
    {
    public:
        /// Metric of our own region.
        static Matrix4 metricHere();

        /// Metric beyond the threshold.
        static Matrix4 metricThere();

        /// Number of diagonal entries carrying the given sign, that is the
        /// number of directions of that causal type.
        static int directionCount(const Matrix4 &metric, int sign);

        /// Whether a unit vector of the given causal type can be carried into
        /// its own negative without ever leaving that type. When it cannot, the
        /// type is orientable.
        ///
        /// The rotation plane is spanned with a second direction of the same
        /// type where one exists, and otherwise with a direction of the other
        /// type, which is the only plane available when the type has a single
        /// direction. That case is the one the result is about, so it is run
        /// rather than short circuited: the interval is watched along the whole
        /// half turn and the answer can come out either way.
        static bool canReachOwnNegative(const Matrix4 &metric, int sign, int samples = 4001);

        /// Whether the given causal type is orientable, decided by the rotation
        /// above rather than by counting.
        static bool isOrientable(const Matrix4 &metric, int sign);

        /// Whether orientability agrees with the count being one, which is the
        /// shortcut used elsewhere. This exists so the shortcut is checked
        /// rather than trusted.
        static bool countPredictsOrientability(const Matrix4 &metric, int sign);

        /// Whether anything in this work requires a body to advance along a
        /// coordinate rather than merely being unable to reverse along it. The
        /// return map takes the amount of crossing as an input, so nothing
        /// does.
        static bool compulsionIsUsedAnywhere();

        /// Displacement produced in our time slot by a given displacement along
        /// the far side's single space axis.
        static double ourTimeFromTheirSpace(double displacement);

        /// Whether that relation is one to one in the amount, so that how far a
        /// body goes along their space axis is a free choice with a definite
        /// consequence here.
        static bool amountIsFree();

        /// Whether the sign of that displacement can be reversed, which it
        /// cannot while the axis is orientable.
        static bool signCanBeReversed();
    };

    /// Section separating being one way from being carried, and computing what
    /// survives the separation.
    class FlowAssumptionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "One way is not the same as carried, and only one of them is in the metric";
        }
        void run(Report &report) const override;
    };

}
