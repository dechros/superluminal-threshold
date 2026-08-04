#pragma once

#include "core/Section.h"

namespace slm
{

    /// What the density condition depends on, and how far a laboratory could
    /// close the gap by changing it rather than by meeting it.
    ///
    /// The turning density is not a universal constant standing on its own. In
    /// the effective dynamics it is built from two things: a dimensionless
    /// parameter of the quantisation, and the fourth power of whatever mass
    /// scale gravity becomes strong at. Written out, the critical density is
    /// the square root of three over thirty two pi squared gamma cubed, in
    /// units of the fourth power of that scale. Both factors are worth
    /// examining, because a gap of seventy four orders of magnitude is not
    /// closed by pushing harder on the same apparatus.
    ///
    /// The first factor is fixed and offers nothing. The parameter is
    /// determined elsewhere by an entropy count, so treating it as adjustable
    /// would be assuming the answer.
    ///
    /// The second factor is not fixed by anything measured. If additional
    /// compact dimensions exist, the scale at which gravity becomes strong can
    /// lie far below the value inferred from the observed strength of gravity
    /// in four dimensions, and the turning density falls as its fourth power.
    /// That is a large lever, and this class measures exactly how large: it
    /// computes the scale at which the gap would close entirely, and compares
    /// it against the range experiment has already excluded.
    ///
    /// The result is stated as a remaining distance rather than as an
    /// encouragement. The lever is real, it is not enough, and the amount by
    /// which it falls short is the useful number.
    class ThresholdScaling
    {
    public:
        /// The four dimensional Planck mass in giga electronvolts.
        static double planckMassInGev();

        /// Parameter of the quantisation, fixed by the entropy count.
        static double quantisationParameter();

        /// Critical density as a fraction of the density built from the given
        /// scale, which is where the fraction near four tenths comes from.
        static double criticalFraction(double parameter);

        /// Turning density in kilograms per cubic metre, when gravity becomes
        /// strong at the given scale in giga electronvolts.
        static double turningDensityAtScale(double scaleInGev);

        /// How many orders of magnitude the turning density falls when the
        /// scale is lowered from the four dimensional value to the given one.
        static double decadesGainedByScale(double scaleInGev);

        /// Scale in giga electronvolts at which the turning density would come
        /// down to the given density, so that the condition would be met by an
        /// apparatus already reaching it.
        static double scaleThatClosesGap(double reachableDensity);

        /// Lower bound on the scale that experiment has already established, in
        /// giga electronvolts.
        static double excludedBelowInGev();

        /// Whether a proposed scale is already excluded.
        static bool isExcluded(double scaleInGev);

        /// Decades still missing at the best scale experiment leaves open.
        static double decadesRemainingAtBound(double reachableDensity);
    };

    /// Section examining what the density condition rests on.
    class ThresholdScalingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What the density condition rests on, and how far it can be lowered";
        }
        void run(Report &report) const override;
    };

}
