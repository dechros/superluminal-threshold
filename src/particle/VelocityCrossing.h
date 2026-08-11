#pragma once

#include "core/Section.h"

namespace slm
{

    /// The crossing expressed in the particle's own speed, with accelerating
    /// and decelerating as the only mechanism.
    ///
    /// The crossing angle is not a field and not an extra coordinate. It is the
    /// particle's speed, written as @f$ \beta = \tan\theta @f$. The dictionary
    /// this fixes is exact and it settles where the threshold sits without
    /// anything being arranged: @f$ \theta = 0 @f$ is rest,
    /// @f$ \theta = \pi/4 @f$ is @f$ \beta = 1 @f$, and
    /// @f$ \theta = \pi/2 @f$ is infinite speed. The metric family's scale
    /// factor becomes a function of the speed alone,
    /// @f[ \cos 2\theta = \frac{1-\beta^2}{1+\beta^2}, @f]
    /// so the metric degenerates exactly where the particle reaches light
    /// speed. Accelerating the particle is therefore the same operation as
    /// driving the metric towards its degenerate point, and no second mechanism
    /// is needed for the crossing.
    ///
    /// The same dictionary explains why the earlier scan found what it found.
    /// The discrete involution reflects the angle about the degenerate value,
    /// @f$ \theta \mapsto \pi/2 - \theta @f$, and the reflection reads
    /// @f$ \beta \mapsto 1/\beta @f$ in speeds, which is the relation
    /// @f$ v' = c^2/v @f$ the involution section established by another route.
    ///
    /// Two results follow and they point in opposite directions. Under the
    /// standard mass shell the crossing does not happen: @ref standardAngle
    /// gives @f$ \theta(\tau) = \arctan\tanh(a\tau/c) @f$ under constant proper
    /// acceleration, which stays below @f$ \pi/4 @f$ for every finite proper
    /// time, and @ref standardEnergy diverges as the angle approaches it. The
    /// obstruction is located precisely, and it is the same vanishing factor
    /// that degenerates the metric: the energy needed grows as
    /// @f$ 1/\sqrt{\cos 2\theta} @f$. What stays finite through the point is
    /// not the energy but @ref regularisedEnergy, the energy weighed against the
    /// degenerating metric rather than against the near-side one.
    ///
    /// Under the extended shell the crossing does happen, and the energy the
    /// accelerator must supply to reach light speed is
    /// @ref momentumAtLightSpeed, a finite number. The whole of the difference
    /// between the two results is how the required energy scales with the
    /// angle: divergently in the first, linearly in the second. That
    /// replacement is the one posited element left in this account, and it is
    /// posited about the shell rather than about a force.
    ///
    /// Deceleration returns the particle by the same closed form with the sign
    /// of the accelerating force reversed. @ref returnToSubluminalParameter is
    /// where the speed falls back below light speed, and the particle arrives
    /// with the mass parameter it left with.
    class VelocityCrossing
    {
    public:
        /// The angle whose tangent is the given speed in units of @c c.
        static double angleFromSpeed(double beta);

        /// The speed in units of @c c whose angle is given.
        static double speedFromAngle(double theta);

        /// The metric family's scale factor as a function of speed,
        /// @f$ (1-\beta^2)/(1+\beta^2) @f$.
        static double metricScale(double beta);

        /// The Lorentz factor at the given angle,
        /// @f$ \cos\theta/\sqrt{\cos 2\theta} @f$.
        static double lorentzFactor(double theta);

        /// The angle a particle of constant proper acceleration @p acceleration
        /// has reached after proper time @p properTime, which is
        /// @f$ \arctan\tanh(a\tau/c) @f$.
        static double standardAngle(double c, double acceleration, double properTime);

        /// The rate at which that angle advances. The rate falls off like the
        /// square of a hyperbolic secant, so the approach to the threshold is
        /// exponentially slow and the angle stalls rather than the force
        /// failing.
        static double standardAngularRate(double c, double acceleration, double properTime);

        /// The energy in units of the rest energy that the standard shell
        /// demands at the given angle, which is the Lorentz factor and diverges
        /// at @f$ \pi/4 @f$.
        static double standardEnergy(double theta);

        /// The energy weighed against the degenerating metric rather than the
        /// near-side one, @f$ E^2\cos 2\theta @f$ in units of the squared rest
        /// energy, which equals @f$ \cos^2\theta @f$ and is finite everywhere.
        static double regularisedEnergy(double theta);

        /// The momentum conjugate to the angle that the extended shell demands
        /// at light speed, @f$ c\sqrt{\mu + \pi F/2} @f$. Finite for every
        /// accelerating force, which is the whole of the difference from the
        /// standard shell.
        static double momentumAtLightSpeed(double c, double mu, double force);

        /// The parameter at which the accelerated particle reaches light speed.
        static double luminalParameter(double c, double mu, double force);

        /// The speed the accelerated particle carries at the given parameter.
        static double speedAtParameter(double c, double mu, double force, double sigma);

        /// The speed the decelerating particle carries at the given parameter,
        /// counted from the far-side end of the crossing.
        static double returningSpeedAtParameter(double c, double mu, double force, double sigma);

        /// The parameter at which the decelerating particle falls back below
        /// light speed. The return angle is the outward angle reflected about
        /// @f$ \pi/4 @f$, and the reflection fixes that angle, so the return
        /// crosses light speed at exactly the parameter the outward flight
        /// reached it: @ref luminalParameter.
        static double returnToSubluminalParameter(double c, double mu, double force);
    };

    /// Section proving that the standard shell forbids the crossing and locates
    /// the obstruction at the metric's degeneracy, that the extended shell
    /// carries the particle across at finite cost, and that reversing the
    /// accelerating force returns the same particle below light speed.
    class VelocityCrossingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The crossing in the particle's own speed, with accelerating and decelerating as the only mechanism";
        }
        void run(Report &report) const override;
    };

}
