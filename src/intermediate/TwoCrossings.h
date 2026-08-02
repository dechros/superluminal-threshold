#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <complex>

namespace slm
{

    /// The round trip across two crossings, and where it puts the particle back
    /// on our own time axis.
    ///
    /// No duration can be read off inside the intermediate region: the far side
    /// carries no time orientation and the Euclidean case carries no time at
    /// all. The placement therefore cannot come from a clock carried through.
    /// It comes instead from the phase the transmitted amplitude accumulates
    /// between the two crossings, whose derivative with respect to frequency is
    /// the delay measured by an observer who stayed behind.
    ///
    /// The amplitude is the standard two-interface result with the interior
    /// wavenumber allowed to be imaginary, so the propagating and the decaying
    /// interiors are the same formula evaluated on the two branches.
    class TwoCrossings
    {
    public:
        /// Squared normal wavenumber outside, as a function of frequency.
        static double outsideSquared(double omega, double c, double mu, double transverseSquared);

        /// Which directions the intermediate region turns over. The literature
        /// on the Kleinian slab takes the crossing direction itself to be the
        /// one that turns, which forces the interior wavenumber to be imaginary
        /// and makes every crossing a tunnelling. The model's own construction
        /// turns transverse directions instead, which leaves the interior able
        /// to propagate. The two are computed separately and compared.
        enum class FlipAxis
        {
            Transverse,
            Crossing
        };

        /// Squared normal wavenumber inside, which the kind shifts downwards.
        static double insideSquared(IntermediateRegion::Kind kind, double omega, double c,
                                    double mu, double transverseSquared);

        /// Squared normal wavenumber inside for either choice of turning axis.
        static double insideSquaredOn(FlipAxis axis, IntermediateRegion::Kind kind, double omega,
                                      double c, double mu, double transverseSquared);

        /// Ratio of the counter-propagating to the co-propagating interior
        /// amplitude, which is the mixing the region imposes. Unlike the delay,
        /// this is the quantity that can retain the thickness.
        static double mixingRatio(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                  double transverseSquared, double thickness);

        /// Complex transmission amplitude across both crossings.
        static std::complex<double> amplitude(IntermediateRegion::Kind kind, double omega, double c,
                                              double mu, double transverseSquared,
                                              double thickness);

        /// Phase accumulated between the two crossings.
        static double phase(IntermediateRegion::Kind kind, double omega, double c, double mu,
                            double transverseSquared, double thickness);

        /// Delay on the clock of an observer at the threshold who never
        /// crossed, obtained as the frequency derivative of the phase.
        static double returnDelay(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                  double transverseSquared, double thickness);

        /// Time the same journey would take at the speed of light.
        static double lightTime(double thickness, double c);

        /// Ratio of the delay to the light time. Below one means the exit event
        /// sits earlier than light could have reached it.
        static double delayInLightTimes(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared, double thickness);
    };

    /// Section computing the return placement for every kind of intermediate region.
    class TwoCrossingsSection : public Section
    {
    public:
        std::string number() const override { return "13"; }
        std::string title() const override
        {
            return "Two crossings, and where the particle lands on our clock";
        }
        void run(Report &report) const override;
    };

}
