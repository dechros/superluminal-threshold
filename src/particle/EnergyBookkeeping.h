#pragma once

#include "core/Section.h"

#include <array>

namespace slm
{

    /// Tracking the three-component far-side energy through a round trip.
    ///
    /// On the far side the Lagrangian is invariant under three time
    /// translations and one spatial one, so the conserved quantities are an
    /// energy with three components and a momentum with one. The question this
    /// section settles is what those three components are in our own terms, and
    /// what a rotation among them means once the particle is back.
    ///
    /// The far side also carries an O(3) symmetry among its three times, so the
    /// direction of its energy vector is not physical there, only its length.
    /// A round trip can therefore return the particle with its far-side energy
    /// vector rotated, and the question is what that costs here.
    class EnergyBookkeeping
    {
    public:
        using Four = std::array<double, 4>;

        /// Our four-momentum carried across, giving the far-side quantities.
        static Four across(const Four &ours);

        /// Length of the far-side energy vector, its first three slots.
        static double farEnergyMagnitude(const Four &far);

        /// The far side's single momentum, its last slot.
        static double farMomentum(const Four &far);

        /// A rotation among the three far-side times, about the third axis.
        static Four rotateFarEnergy(const Four &far, double angle);

        /// The invariant, which flips sign on crossing.
        static double invariant(const Four &vector, bool farSide);

        /// Our energy, read off our own four-momentum.
        static double ourEnergy(const Four &ours) { return ours[0]; }

        /// Length of our three-momentum.
        static double ourMomentumMagnitude(const Four &ours);

        /// Angle between the three-momenta of two of our four-vectors.
        static double momentumAngle(const Four &first, const Four &second);
    };

    /// Section on what a rotation over there does to the particle here.
    class EnergyBookkeepingSection : public Section
    {
    public:
        std::string number() const override { return "16"; }
        std::string title() const override
        {
            return "The three-component energy, and what rotating it costs here";
        }
        void run(Report &report) const override;
    };

}
