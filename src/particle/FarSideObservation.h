#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// What can be observed of the particle while it is on the far side, and
    /// where it can be said to be.
    ///
    /// The literature on spacelike states gives one usable answer and one
    /// refusal. The refusal is localisation: a spacelike four-momentum admits
    /// no position operator whose eigenstates respect causality, so there is no
    /// state that says where the particle is. The usable answer is the missing
    /// mass method, which does not look at the particle at all. It measures
    /// everything that enters and everything that leaves and forms the
    /// invariant mass of the difference; a spacelike carrier shows up as that
    /// invariant being negative. It is a boundary measurement, and its subject
    /// is the balance rather than the traveller.
    ///
    /// Whether it reaches this work depends on a fact that has to be checked
    /// and not assumed: the missing mass method presumes a real on-shell
    /// spacelike momentum leaving the interaction. The interior here is
    /// sometimes propagating and sometimes evanescent, and only the first
    /// carries such a momentum. This class separates the two regimes and finds
    /// them disjoint from the regime the round trip uses.
    ///
    /// That is the result, and it is a tension rather than a method. Where the
    /// particle can be observed over there, the delay does not saturate and the
    /// arrival is not advanced. Where the arrival is advanced, the interior is
    /// evanescent, no on-shell state exists inside, and everything observable
    /// sits in the boundary amplitudes this work already computes. Those
    /// amplitudes are moreover even under the reversal separating the two
    /// families, so they do not even report which way the particle went.
    class FarSideObservation
    {
    public:
        /// Squared four-momentum the interior carries, positive when timelike
        /// on the convention used here and negative when spacelike.
        static double interiorInvariantSquared(IntermediateRegion::Kind kind, double omega,
                                               double c, double mu, double transverseSquared);

        /// Whether the interior momentum is spacelike, which is the signature
        /// the missing mass method looks for.
        static bool interiorIsSpacelike(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared);

        /// Whether the interior carries a real momentum at all, which the
        /// missing mass method presumes.
        static bool interiorIsOnShell(IntermediateRegion::Kind kind, double omega, double c,
                                      double mu, double transverseSquared);

        /// Whether the missing mass method reaches this configuration, which
        /// needs both of the above.
        static bool missingMassApplies(IntermediateRegion::Kind kind, double omega, double c,
                                       double mu, double transverseSquared);

        /// Whether the configuration is the one the round trip uses, meaning
        /// the interior decays so the delay can saturate.
        static bool isRoundTripRegime(IntermediateRegion::Kind kind, double omega, double c,
                                      double mu, double transverseSquared);

        /// Whether any frequency makes the missing mass method apply and the
        /// round trip regime hold at once, which is what an observation of the
        /// travelling particle would need.
        static bool anyFrequencyGivesBoth(IntermediateRegion::Kind kind, double c, double mu,
                                          double transverseSquared);

        /// Frequency above which the interior turns from decaying to
        /// propagating, found by bisection, which is the boundary between the
        /// two regimes.
        static double regimeBoundary(IntermediateRegion::Kind kind, double c, double mu,
                                     double transverseSquared);

        /// Whether a localised interior state is available, which it is not,
        /// and which is reported as a refusal rather than computed.
        static bool localisedStateAvailable();

        /// Number of boundary quantities this work computes that survive as
        /// observables in the evanescent regime.
        static int boundaryObservableCount();

        /// Whether those boundary quantities report which way the particle
        /// travelled, which they do not.
        static bool boundaryObservablesCarryDirection();
    };

    /// Section on observing the particle while it is on the far side.
    class FarSideObservationSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What can be observed of the particle while it is over there";
        }
        void run(Report &report) const override;
    };

}
