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
    /// Whether it reaches this work depends on a necessary condition that has
    /// to be checked and not assumed: the method presumes a real on-shell
    /// momentum leaving the interaction, and the interior here is sometimes
    /// propagating and sometimes evanescent. Only the first carries one.
    ///
    /// The sufficient condition is NOT checked and is not claimed. What the
    /// method actually reads is the sign of an invariant of the four-momentum,
    /// and no such invariant is computed anywhere in this work. The quantity
    /// available here is the squared wavenumber along the crossing axis, which
    /// is a different object; conflating the two would be claiming a mass
    /// signature that has not been derived.
    ///
    /// So the result is the regime split alone, and it is a tension rather
    /// than a method. Where an on-shell mode exists inside, the delay does not
    /// saturate and the arrival is not advanced. Where the arrival is
    /// advanced, the interior is evanescent, no on-shell mode exists inside,
    /// and everything observable sits in the boundary amplitudes this work
    /// already computes. Those amplitudes are moreover even under the reversal
    /// separating the two families, so they do not report which way the
    /// particle went.
    class FarSideObservation
    {
    public:
        /// Squared wavenumber the interior carries along the crossing axis.
        /// This is NOT an invariant of the four-momentum and its sign is not
        /// the mass sign the missing mass method looks for; keeping the two
        /// apart is the point of the name.
        static double interiorCrossingWavenumberSquared(IntermediateRegion::Kind kind,
                                                        double omega, double c, double mu,
                                                        double transverseSquared);

        /// Whether the interior carries a real wavenumber at all, which is a
        /// necessary condition for any on-shell interior mode.
        static bool interiorIsOnShell(IntermediateRegion::Kind kind, double omega, double c,
                                      double mu, double transverseSquared);

        /// Whether the missing mass method can reach this configuration at
        /// all. Only the necessary condition is computed: an on-shell interior
        /// mode has to exist. The sign of the four-momentum invariant, which
        /// is what the method actually reads, is not computed anywhere in this
        /// work and is therefore not claimed.
        static bool missingMassCanApply(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared);

        /// Whether the configuration is the one the round trip uses, meaning
        /// the delay can saturate. Decided through the barrier predicate the
        /// threshold optimum uses, which reaches the answer by its own route,
        /// so the disjointness below holds between two independently written
        /// predicates rather than between a predicate and its negation.
        static bool isRoundTripRegime(IntermediateRegion::Kind kind, double omega, double c,
                                      double mu, double transverseSquared);

        /// Whether any frequency puts an on-shell mode inside and still lets
        /// the delay saturate, which is what an observation of the travelling
        /// particle would need.
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
        /// observables in the evanescent regime, taken from the sweep that
        /// tested them rather than written down here.
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
