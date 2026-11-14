#ifndef SLM_PARTICLE_CONSTANTFORCE_H
#define SLM_PARTICLE_CONSTANTFORCE_H

namespace slm
{

    /// The one closed-form trajectory every constant-force drive in the
    /// project is an instance of.
    ///
    /// A coordinate @f$ x @f$ with conjugate momentum @f$ p @f$ sits on the
    /// shell @f$ S + 2F(x - x_0) - p^2/c^2 = 0 @f$, where @f$ S @f$ is the value
    /// the shell takes at the start, @f$ x_0 @f$, before any work is done.
    /// Hamilton's equations from that constraint,
    /// @f$ dx/d\sigma = -p/c^2 @f$ and @f$ dp/d\sigma = -F @f$, integrate to a
    /// quadratic in the parameter. The entry branch is the negative root of the
    /// shell at the start, which is the sign that carries the coordinate
    /// upward; a positive force then drives the momentum strictly more
    /// negative, so the coordinate increases without bound and reaches every
    /// target exactly once.
    ///
    /// The crossing angle, the far side's space axis and the round trips are
    /// three readings of this one trajectory with different @f$ x_0 @f$ and
    /// @f$ S @f$.
    class ConstantForce
    {
    public:
        /// The negative root of the shell at the start, @f$ -c\sqrt{S} @f$.
        static double entryMomentum(double c, double shellAtStart);

        /// The coordinate after parameter @p sigma, from @p start.
        static double coordinate(double c, double shellAtStart, double force, double start,
                                 double sigma);

        /// The conjugate momentum after parameter @p sigma.
        static double momentum(double c, double shellAtStart, double force, double sigma);

        /// The shell residual at a point, which the trajectory holds at zero.
        static double residual(double c, double shellAtStart, double force, double start,
                               double coordinate, double momentum);

        /// The parameter at which the coordinate first equals @p target, from
        /// the positive root of the quadratic written in the form that does
        /// not cancel when the entry momentum dwarfs the work term.
        static double parameterToReach(double c, double shellAtStart, double force, double start,
                                       double target);
    };

}

#endif
