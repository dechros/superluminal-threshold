#pragma once

#include "core/Section.h"

#include <array>

namespace slm
{

    /// What can be done from this side to set which way the particle travels
    /// along the far side's single spatial axis.
    ///
    /// This is not the question of which crossing map is realised, which is
    /// settled elsewhere and concerns a joint reversal of the near-side time slot and the
    /// far side's distinguished axis. Here the map is given and the question is
    /// the direction of travel under it. The two are separate and the first
    /// business of this class is to show they are separate, because they are
    /// easy to merge and merging them would make a known theorem look like an
    /// answer to a question it does not reach.
    ///
    /// The published result that does bear on this is a reciprocity theorem:
    /// when each asymptotic side carries a single propagating channel per
    /// direction, the transmission through a spatially asymmetric barrier is
    /// the same for incidence from the left and from the right. It follows from
    /// time reversal invariance together with unitarity, and it says that
    /// shaping the transition cannot bias the direction. That is checked here
    /// against the profiles already built rather than taken on credit.
    ///
    /// The escape the same literature points to is a coherent superposition of
    /// incident channels, where the direction dependence comes from the
    /// relative phase between channels and not from the barrier. That is the
    /// same shape of requirement the branch sweep reached from the other side:
    /// a quantity odd in exactly one axis. Whether the model supplies such a
    /// channel structure is not claimed, and the class ends by saying so.
    class DirectionControl
    {
    public:
        using Signs = std::array<double, 4>;

        /// The reversal reciprocity concerns, which turns the crossing axis
        /// alone. Slot one is the far side's distinguished spatial axis.
        static Signs reciprocityElement();

        /// The reversal separating the two families of crossing, which turns
        /// the near-side time slot and the distinguished axis together.
        static Signs jointReversalElement();

        /// Product of the two, componentwise.
        static Signs product(const Signs &left, const Signs &right);

        /// Whether the two reversals are the same group element, which they are
        /// not.
        static bool operationsAreDistinct();

        /// Whether their product is a pure reversal of the near-side time slot, which is
        /// exactly how they differ.
        static bool productIsPureTimeReversal();

        /// Transmission through a skewed barrier for incidence from the left.
        static double transmissionFromLeft(double width, double total, double outsideWavenumber);

        /// The same barrier entered from the right, which is the mirrored
        /// profile.
        static double transmissionFromRight(double width, double total, double outsideWavenumber);

        /// Size of the difference between the two, which reciprocity requires
        /// to vanish.
        static double reciprocityResidual(double width, double total, double outsideWavenumber);

        /// Whether any of the asymmetric profiles built here transmits
        /// differently from the two sides, which would be a way of steering by
        /// shaping alone.
        static bool anyShapeSteers(double width, double total, double outsideWavenumber,
                                   double tolerance);

        /// Whether the barrier's own asymmetry is real, so that the equality
        /// above is a theorem doing work rather than a mirror symmetry hiding
        /// in the profile.
        static bool profileIsGenuinelyAsymmetric(double width, double total);

        /// Direction of travel carried by a single incident channel, which is
        /// the sign of its crossing wavenumber and is fixed by the sign it
        /// arrives with.
        static double directionFromChannel(double incidentWavenumber);

        /// Direction carried by a coherent pair of channels with the given
        /// relative phase, as the imaginary part of their interference, which
        /// is the one construction able to depend on a sign without depending
        /// on the barrier.
        static double directionFromPair(double firstWeight, double secondWeight,
                                        double relativePhase);

        /// Whether that pair construction actually depends on the sign of the
        /// relative phase, which is what makes it a candidate steer.
        static bool pairIsOddInPhase(double firstWeight, double secondWeight);

        /// Whether a single channel can be biased at all once reciprocity
        /// holds, which it cannot.
        static bool singleChannelCanBeBiased(double width, double total,
                                             double outsideWavenumber, double tolerance);
    };

    /// Section on steering the far-side direction from this side.
    class DirectionControlSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What this side can do to set the direction of travel on the far side";
        }
        void run(Report &report) const override;
    };

}
