#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// What a given displacement of the clock costs, in the currencies the model
    /// actually contains.
    ///
    /// Three quantities can be priced here and they behave differently.
    ///
    /// THE AMPLITUDE. A displacement of the clock towards earlier moments
    /// requires the far-side leg to exceed the saturated crossing delay, and
    /// that delay is fixed by the region rather than by the leg. The amplitude
    /// for the whole sequence is therefore set by the region alone and is the
    /// same for every leg beyond the crossover. This is a strong statement and
    /// it is reported together with its reason: the amplitude in this model
    /// carries no far-side path length at all, so the independence is an absence
    /// in the model and not a computed freedom. Anything that priced the journey
    /// would have to enter the amplitude first.
    ///
    /// THE ENERGY OF A STRAIGHT LEG. The far side is invariant under
    /// translation along its distinguished axis, so travelling along it conserves
    /// the conjugate quantity and a straight leg of any length costs nothing.
    /// Rotations among the like-signed axes are likewise free, which is settled
    /// elsewhere. Neither buys any displacement beyond what the leg itself gives.
    ///
    /// THE ENERGY OF A FRAME CHANGE. A hyperbolic rotation involving the
    /// distinguished axis does buy an extra displacement, and it does have a
    /// price: it multiplies the energy by the hyperbolic cosine of its rapidity.
    /// Eliminating the rapidity between the two gives a relation with no free
    /// parameter left, in which the fractional increase in energy equals the
    /// extra displacement divided by the length of the leg. A longer leg buys
    /// the same displacement more cheaply, and the relation is linear rather
    /// than exponential.
    class TimeShiftCost
    {
    public:
        /// Far-side leg needed to place the arrival the given amount before the
        /// entry.
        static double requiredDistance(double backwardAmount, IntermediateRegion::Kind kind,
                                       double c, double mu, double thickness);

        /// Amplitude weight of the whole sequence, which depends on the region
        /// and not on the leg.
        static double amplitudeWeight(IntermediateRegion::Kind kind, double c, double mu,
                                      double transverseSquared, double thickness);

        /// Whether the amplitude weight responds to the region parameters at
        /// all, which is what makes its blindness to the leg a meaningful
        /// statement rather than a degenerate one.
        static bool weightRespondsToTheRegion(IntermediateRegion::Kind kind, double c, double mu,
                                              double transverseSquared);

        /// Rapidity of the frame change that buys the given extra displacement
        /// on a leg of the given length.
        static double rapidityForResidue(double distance, double residue);

        /// Factor by which that frame change multiplies the energy.
        static double energyFactor(double rapidity);

        /// Fractional increase in energy required to buy the given extra
        /// displacement on a leg of the given length.
        static double fractionalEnergyCost(double distance, double residue);

        /// Extra displacement a given fractional increase in energy buys on a
        /// leg of the given length.
        static double residueForEnergyCost(double distance, double fractionalCost);
    };

    /// Section pricing a displacement of the clock in each currency the model
    /// contains, and recording the one it does not contain.
    class TimeShiftCostSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What a displacement of the clock costs, and what the model cannot price";
        }
        void run(Report &report) const override;
    };

}
