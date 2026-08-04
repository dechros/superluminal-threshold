#pragma once

#include "core/Section.h"
#include "core/Vector4.h"
#include "intermediate/IntermediateRegion.h"
#include "routes/ThreeRoutes.h"

namespace slm
{

    /// A state carrying charge as well as mass, sent across and brought back.
    ///
    /// Charge changes three things and leaves a fourth alone, and separating
    /// them is the whole content of this class.
    ///
    /// It changes what the words mean on the far side. Charge density is the
    /// time component of the four-current, and the crossing carries the near
    /// side's time axis onto a far-side space axis. So the quantity a near-side
    /// observer calls a density is a current component over there, and one of
    /// the currents is the density. The four-current maps covariantly and
    /// nothing is lost, but the split into density and current is reshuffled,
    /// so asking how much charge sits over there is not the same question as
    /// asking it here.
    ///
    /// It supplies a control that a neutral state does not have. The timing of
    /// the crossing depends on the frequency, and minimal coupling shifts the
    /// frequency by the potential times the charge. So an applied electrostatic
    /// potential moves the far-side distance the state needs, which is a knob
    /// on the return moment rather than a correction to it. A neutral state
    /// offers no such knob.
    ///
    /// It raises the price of admission, because the mass ceiling is a ceiling
    /// on the mass parameter and a charged state of interest is heavy. The band
    /// centre has to exceed the frequency built from the rest energy, and for a
    /// proton that is a definite number rather than a scale to be estimated
    /// later.
    ///
    /// It does not change the timing by itself. With no potential applied the
    /// crossing knows nothing about the charge, and that is checked rather than
    /// assumed, since it is the claim a reader is least likely to grant.
    class ChargedRoundTrip
    {
    public:
        /// Rest energy of the state, in joules, from its mass in kilograms.
        static double restEnergy(double massInKilograms, double c);

        /// Angular frequency built from that rest energy, which is the lowest
        /// band centre able to carry the state at all.
        static double restFrequency(double massInKilograms, double c, double hbar);

        /// Mass parameter the libraries use, mu = (m c / hbar)^2.
        static double massParameter(double massInKilograms, double c, double hbar);

        /// Whether a band at the given centre frequency can carry a state of
        /// this mass across, which asks the centre to clear the rest frequency.
        static bool bandCanCarry(double massInKilograms, double c, double hbar, double centre);

        /// Frequency the state effectively presents to the region when an
        /// electrostatic potential is applied, which is the frequency shifted
        /// by the charge times the potential.
        static double effectiveFrequency(double omega, double charge, double potential,
                                         double hbar);

        /// Round trip reading under an applied potential, by the given
        /// description.
        static double readingUnderPotential(ThreeRoutes::Route route,
                                            IntermediateRegion::Kind kind, double omega, double c,
                                            double mu, double transverseSquared, double thickness,
                                            double charge, double potential, double hbar);

        /// Far-side distance needed under an applied potential, which is that
        /// reading.
        static double thresholdUnderPotential(ThreeRoutes::Route route,
                                              IntermediateRegion::Kind kind, double omega,
                                              double c, double mu, double transverseSquared,
                                              double thickness, double charge, double potential,
                                              double hbar);

        /// Whether the timing is unchanged when the charge is changed at zero
        /// potential, which is the statement that charge alone does not enter.
        static bool timingIgnoresChargeWithoutPotential(ThreeRoutes::Route route,
                                                        IntermediateRegion::Kind kind,
                                                        double omega, double c, double mu,
                                                        double transverseSquared,
                                                        double thickness, double hbar);

        /// Whether an applied potential moves the far-side distance needed, so
        /// that the return moment can be steered from outside.
        static bool potentialSteersTheReturn(ThreeRoutes::Route route,
                                             IntermediateRegion::Kind kind, double omega, double c,
                                             double mu, double transverseSquared, double thickness,
                                             double charge, double potential, double hbar);

        /// Cheapest far-side distance reachable by tuning the potential, found
        /// by scanning it over the given range.
        ///
        /// The price is not monotone in the frequency: it falls, reaches a
        /// minimum, and rises again, diverging at both ends of the band that
        /// can cross at all. So the potential is not a lever that makes the
        /// journey arbitrarily cheap. It is a tuning onto that minimum, and the
        /// minimum is a floor no charge and no potential can go under.
        static double cheapestThreshold(ThreeRoutes::Route route, IntermediateRegion::Kind kind,
                                        double omega, double c, double mu,
                                        double transverseSquared, double thickness, double charge,
                                        double reach, int samples, double hbar);

        /// Potential that reaches that cheapest distance.
        static double potentialAtCheapest(ThreeRoutes::Route route, IntermediateRegion::Kind kind,
                                          double omega, double c, double mu,
                                          double transverseSquared, double thickness,
                                          double charge, double reach, int samples, double hbar);

        /// Whether the cheapest point lies strictly inside the scanned range,
        /// which is what makes it a minimum rather than an edge.
        static bool cheapestIsInterior(ThreeRoutes::Route route, IntermediateRegion::Kind kind,
                                       double omega, double c, double mu, double transverseSquared,
                                       double thickness, double charge, double reach, int samples,
                                       double hbar);

        /// Four-current of the state as the near side writes it.
        static Vector4 nearSideCurrent(double c, double chargeDensity, double jx, double jy,
                                       double jz);

        /// The same four-current as the far side writes it, obtained by the
        /// crossing map rather than by relabelling.
        static Vector4 farSideCurrent(const Vector4 &near);

        /// Whether the near side's charge density has become a far-side current
        /// component, which is the reshuffling the crossing forces.
        static bool densityBecomesCurrent(const Vector4 &near);

        /// Squared length of the four-current under the metric of the side it
        /// is written on, which is the invariant that has to survive if the
        /// current is to be the same current.
        static double currentInvariant(const Vector4 &current, bool farSide);

        /// Whether that invariant is carried across up to the overall sign the
        /// crossing imposes, which is what conservation of the current means
        /// here and is weaker than equality.
        static bool invariantSurvives(const Vector4 &near, double tolerance);
    };

    /// Section carrying a charged massive state through the whole journey.
    class ChargedRoundTripSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A charged massive state: what charge buys and what it costs";
        }
        void run(Report &report) const override;
    };

}
