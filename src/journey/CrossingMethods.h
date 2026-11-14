#ifndef SLM_JOURNEY_CROSSINGMETHODS_H
#define SLM_JOURNEY_CROSSINGMETHODS_H

#include "journey/Traveller.h"

#include <string>
#include <vector>

namespace slm
{

    /// Every way of getting a traveller across the threshold that the project's
    /// libraries can evaluate, tried on each traveller, each with what it
    /// supplies, what it still needs, and what it costs.
    ///
    /// Nothing here is a verdict of impossibility. Each mechanics is asked what
    /// it gives and what has to be added to finish the crossing, and the cost of
    /// the finished crossing is computed.
    ///
    /// Newtonian mechanics has no speed limit: under any force the traveller
    /// passes @f$ c @f$ at the finite time @f$ \beta c/a @f$. What it lacks is a
    /// clock that reacts; its clock transforms by the identity, so the crossing
    /// has to be completed by the signature change, which is the involution
    /// the scan found. Special relativity under the standard shell supplies the
    /// clock that slows and stops, and keeps every massive traveller below the
    /// threshold for all proper time; it is completed by replacing the
    /// divergent energy scaling with the linear one, which is the extended
    /// shell. The extended shell under a constant force is complete by itself:
    /// every traveller crosses at the finite momentum @f$ c\sqrt{\mu + \pi F/2} @f$,
    /// through light speed with mass and from light speed without. Bending the
    /// metric instead of pushing the traveller drives the family
    /// @f$ g(\theta) = \eta\cos 2\theta @f$ through its degenerate point; a
    /// traveller keeping its mass parameter has no real momentum beyond it, so
    /// the bend is completed by reversing the shell along with the metric,
    /// which takes @f$ \mu \to -\mu @f$ and the energy's square with it; the
    /// relabelling section identifies the sign of the mass parameter as the
    /// one thing that separates the two regions. The bend costs the tension of
    /// the wall it creates, @ref bendTension, finite and external to the
    /// traveller. Quantum
    /// tunnelling across a degenerate layer of width @f$ w @f$ transmits
    /// @f$ e^{-2\sqrt{\mu}w} @f$, one for the massless traveller and, for the
    /// others, one only when the layer is thinner than @ref tunnellingHalvingWidth;
    /// it is completed by a far-side state to land in, which the extended
    /// shell supplies.
    ///
    /// The chosen way for each traveller is the complete one of least cost.
    /// The massless traveller needs no acceleration up to light speed and its
    /// tunnelling is lossless, so for it the extended shell started from the
    /// threshold is chosen; for the atom and the molecule the extended shell
    /// under acceleration through light speed is chosen, and the cost of each
    /// is stated as the momentum the accelerator must supply.
    class CrossingMethods
    {
    public:
        /// One way tried on one traveller.
        struct Verdict
        {
            std::string method;
            std::string mechanics;
            std::string supplies;
            std::string completedBy;
            bool completeAsIs = false;
            bool needsExternalField = false;
            bool passesLightSpeed = false;
            double cost = 0.0;
            std::string costMeaning;
        };

        /// Newtonian time to reach speed @p beta from rest under acceleration
        /// @p acceleration, @f$ \beta c / a @f$.
        static double newtonianTimeToSpeed(double c, double acceleration, double beta);

        /// The Galilean clock shift of a trip at any speed, which is zero.
        static double galileanClockShift();

        /// The largest angle the standard shell reaches in @p properTime under
        /// @p acceleration, always below @f$ \pi/4 @f$.
        static double standardAngleReached(double c, double acceleration, double properTime);

        /// The transmission of the traveller across a degenerate layer of
        /// width @p thickness, from DegenerateWindow.
        static double tunnellingTransmission(const Traveller &traveller, double thickness);

        /// The layer width that halves the traveller's transmission; infinite
        /// for the massless one.
        static double tunnellingHalvingWidth(const Traveller &traveller);

        /// Whether a traveller that keeps its mass parameter has a real
        /// momentum on the far side of the bent metric at the given angle and
        /// squared energy.
        static bool hasRealFarSideMomentum(const Traveller &traveller, double angle,
                                           double energySquared);

        /// The same question with the whole shell reversed along with the
        /// metric: @f$ \mu \to -\mu @f$ and the squared energy with it, so the
        /// bracket @f$ E^2 - \mu @f$ changes sign. This is what completes the
        /// bend, and it is more than @f$ \mu \to -\mu @f$ alone, which for the
        /// massless traveller would change nothing.
        static bool hasRealFarSideMomentumWithReversedShell(const Traveller &traveller,
                                                            double angle, double energySquared);

        /// What bending the metric costs: the tension of the wall the bend
        /// creates, from ThresholdWall at the project's reference couplings.
        /// Finite, but an energy per area of wall rather than a momentum on
        /// the traveller, so it is not compared with the accelerator's cost.
        static double bendTension();

        /// Product of group and phase velocity of the traveller's wave at
        /// wavenumber @p k, which is @f$ c^2 @f$.
        static double groupTimesPhase(const Traveller &traveller, double k);

        /// All ways for one traveller.
        static std::vector<Verdict> evaluate(const Traveller &traveller, double force);

        /// The verdict chosen for the traveller: among the complete ways that
        /// need nothing beyond the traveller and its accelerator, the one of
        /// least cost. A way that bends the metric is complete but external,
        /// and is reported beside the choice rather than as it.
        static Verdict best(const Traveller &traveller, double force);
    };

}

#endif
