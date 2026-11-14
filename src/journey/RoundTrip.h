#ifndef SLM_JOURNEY_ROUNDTRIP_H
#define SLM_JOURNEY_ROUNDTRIP_H

#include "journey/Traveller.h"

#include <array>
#include <vector>

namespace slm
{

    /// One complete round trip in time for one traveller: accelerate across the
    /// threshold, drive along the far side's single space axis in a chosen
    /// sense, come back across, and read the near-side clock.
    ///
    /// The crossing is the one VelocityCrossing describes, generalised to start
    /// from any angle. The shell is @f$ \mu + 2F\theta - p^2/c^2 = 0 @f$ and the
    /// entry momentum is its negative root at the start angle,
    /// @f$ p_0 = -c\sqrt{\mu + 2F\theta_0} @f$. A traveller with mass starts at
    /// rest, @f$ \theta_0 = 0 @f$, and passes light speed at @ref
    /// thresholdParameter. A massless traveller has no rest frame; it is born
    /// at light speed, so its start angle is @f$ \pi/4 @f$ and its entry
    /// momentum is exactly the momentum the massive crossing demands at light
    /// speed, @f$ c\sqrt{\pi F/2} @f$. Anchoring the shell at that angle with
    /// @f$ \mu = 0 @f$ is the one posited element added here: it says the
    /// massless traveller enters in the state a massive one passes through.
    ///
    /// The return is the time reverse of the outward leg: the far-side state
    /// has its conjugate momentum reflected and the same force carries it back,
    /// so the returning angle is the outward angle read from the other end and
    /// the returning momentum is its negative. Hamilton's equations are
    /// invariant under that reversal, which is why the shell residual stays
    /// zero on the way back and the traveller arrives with the mass parameter,
    /// the speed and the momentum magnitude it left with.
    ///
    /// The three legs are three constrained systems on different coordinates,
    /// and the handoff between them is stated rather than left open. The
    /// crossing ends with the momentum conjugate to the angle at
    /// @f$ p(\sigma_{out}) @f$; that momentum is held while the angle stands at
    /// @f$ \pi/2 @f$ on the far side, and the return leg starts from it
    /// reflected. The far-side drive starts from the shell's rest state there,
    /// with no energy along the three time axes: any energy laid along them
    /// would move the traveller along those axes, which are the near side's
    /// space, and it would not return to the place it left. For the massless
    /// traveller that rest state is the null state, and the drive leaves it at
    /// once. The drive moves the traveller along @f$ r @f$ alone, so it comes
    /// back to the place it left and only its clock moves. A displacement
    /// @f$ s @f$ along @f$ +r @f$ moves that clock by @f$ -s/c @f$, along
    /// @f$ -r @f$ by @f$ +s/c @f$; the sign is the one the handedness filter
    /// fixed.
    ///
    /// Two readings of what the crossing costs in near-side time are reported
    /// side by side. Under the field-wall reading the threshold has a width and
    /// traversing it twice costs PairedExcursion's round-trip delay, taken at
    /// light speed since that is the speed every traveller holds at the
    /// threshold. Under the velocity reading the threshold has no width and the
    /// map's contribution is the whole shift; the near-side time spent
    /// accelerating is not fixed by the shell, whose parameter is not a clock,
    /// so nothing is added for it.
    ///
    /// A traveller with shape carries its atoms as offsets from its centre. On
    /// the far side those offsets land entirely in the three times, with no
    /// spread along @f$ r @f$: the molecule is a point in far-side space and an
    /// extended object in far-side time. The drive moves every atom by the
    /// same @f$ r @f$, so every atom gets the same clock shift, and the return
    /// restores every offset exactly. The block carrying the shape is a proper
    /// rotation, so the signed volume of the labelled bond vectors, and with it
    /// the molecule's handedness, comes back with the sign it left with.
    class RoundTrip
    {
    public:
        using Three = std::array<double, 3>;
        using Four = std::array<double, 4>;

        /// Which way the traveller is driven along the far side's space axis.
        enum class Sense
        {
            PlusR,
            MinusR
        };

        /// What every trip shares.
        struct Settings
        {
            double c = 1.0;
            double force = 1.0;
            double farDistance = 1.0;
            double wallWidth = 1e-15;
            double wallTolerance = 1e-8;
        };

        /// The settings every section and the viewer share: SI constants, the
        /// electron scale as the force, one metre of far-side travel, and the
        /// field wall at a femtometre.
        static Settings referenceSettings();

        /// Everything one trip establishes.
        struct Outcome
        {
            double mu = 0.0;
            double startAngle = 0.0;
            double entryMomentum = 0.0;
            double thresholdMomentum = 0.0;
            double thresholdParameter = 0.0;
            double outwardParameter = 0.0;
            double farSideParameter = 0.0;
            double returnParameter = 0.0;
            double maxOutwardResidual = 0.0;
            double maxReturnResidual = 0.0;
            double maxFarSideResidual = 0.0;
            double maxHamiltonResidual = 0.0;
            double joinAngleResidual = 0.0;
            double joinMomentumResidual = 0.0;
            double speedAtReturn = 0.0;
            double momentumAtReturn = 0.0;
            double massAtReturn = 0.0;
            double mapShift = 0.0;
            double wallDelay = 0.0;
            double netShiftFieldWall = 0.0;
            double netShiftVelocity = 0.0;
            std::vector<Four> farSideAtoms;
            std::vector<Three> returnedAtoms;
            std::vector<double> atomClockShifts;
        };

        /// The negative root of the shell at the start angle.
        static double entryMomentum(double c, double mu, double force, double startAngle);

        /// The crossing angle after parameter @p sigma, from the start angle.
        static double angle(double c, double mu, double force, double startAngle, double sigma);

        /// The conjugate momentum after parameter @p sigma.
        static double momentum(double c, double mu, double force, double startAngle,
                               double sigma);

        /// The parameter at which the angle first reaches @p target.
        static double parameterToAngle(double c, double mu, double force, double startAngle,
                                       double target);

        /// The shell residual @f$ \mu + 2F\theta - p^2/c^2 @f$ relative to the
        /// squared entry momentum, so that it is dimensionless and comparable
        /// across travellers whose @f$ \mu @f$ differ by thirty orders.
        static double relativeResidual(double c, double mu, double force, double angle,
                                       double momentum);

        /// The returning angle after parameter @p sigma of the return leg,
        /// which is the outward angle at @p outward minus @p sigma.
        static double returningAngle(double c, double mu, double force, double startAngle,
                                     double outward, double sigma);

        /// The returning momentum, the reflected outward momentum at the same
        /// point of the curve.
        static double returningMomentum(double c, double mu, double force, double startAngle,
                                        double outward, double sigma);

        /// The larger of the two Hamilton residuals on the return leg at
        /// @p sigma, @f$ d\theta/d\sigma + p/c^2 @f$ scaled by the momentum and
        /// @f$ dp/d\sigma + F @f$ scaled by the force, by central difference
        /// with step @p step, which is exact for the quadratic at any step.
        static double hamiltonResidual(double c, double mu, double force, double startAngle,
                                       double outward, double sigma, double step);

        /// The parameter at which the far-side drive has covered @p farDistance.
        static double farSideParameter(double c, double mu, double force, double farDistance);

        /// The signed far-side position after parameter @p sigma: the
        /// constant-force drive run along @f$ +r @f$ or along @f$ -r @f$, with
        /// the force and the entry branch mirrored for the latter.
        static double farSidePosition(double c, double mu, double force, Sense sense,
                                      double sigma);

        /// The signed far-side conjugate momentum after parameter @p sigma.
        static double farSideMomentum(double c, double mu, double force, Sense sense,
                                      double sigma);

        /// The far-side shell residual on the signed branch,
        /// @f$ \mu + 2F\,\mathrm{sgn}\,r - q^2/c^2 @f$ relative to
        /// @f$ \mu + 2Fs @f$.
        static double farSideResidual(double c, double mu, double force, Sense sense,
                                      double sigma, double farDistance);

        /// The near-side clock rate @f$ d\tau/dt = \sqrt{\cos 2\theta}/\cos\theta @f$,
        /// one at rest, falling to zero at the threshold, and zero beyond it
        /// where the square root has no real value.
        static double clockRate(double angle);

        /// The far-side image of a near-side spatial offset, as
        /// @f$ (t_1, t_2, t_3, r) @f$.
        static Four farSideImage(const Three &offset);

        /// The signed volume of the three labelled bond vectors from the first
        /// atom to the second, third and fourth.
        static double signedVolume(const std::vector<Three> &atoms);

        /// The whole trip.
        static Outcome run(const Traveller &traveller, Sense sense, const Settings &settings);
    };

}

#endif
