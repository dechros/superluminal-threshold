#ifndef SLM_PARTICLE_CONTINUOUSCROSSING_H
#define SLM_PARTICLE_CONTINUOUSCROSSING_H

namespace slm
{

    /// A constant force driving the crossing angle itself, closing the gap
    /// the metric family in ThresholdField leaves open.
    ///
    /// The crossing angle theta is treated as an ordinary canonical
    /// coordinate with its own conjugate momentum, under a shell
    /// mu + 2*force*theta - p^2/c^2 = 0 linear in theta, the same
    /// construction already used elsewhere for a single space axis. Because
    /// the driving term is linear in theta rather than multiplied through
    /// the way the metric family is, the degenerate point at theta = pi/4
    /// carries no special weight in this constraint: the entry branch is
    /// fixed by the negative root at theta = 0, a positive force drives the
    /// conjugate momentum strictly more negative, and theta increases
    /// without bound, reaching pi/2 and beyond for every mass and every
    /// positive force.
    ///
    /// The return is the time reverse of the same trajectory: the far-side
    /// state has its conjugate momentum reflected and the same force carries
    /// it back, so the returning angle is the outward angle read from the
    /// other end, theta(sigma_out - sigma). It starts at pi/2 and falls to
    /// zero at exactly the parameter the outward leg took, Hamilton's
    /// equations hold along it with the same shell, and no second
    /// construction is needed.
    class ContinuousCrossing
    {
    public:
        /// The entry value of the momentum conjugate to theta, the negative
        /// root of the shell at theta = 0.
        static double entryMomentum(double c, double mu);

        /// Crossing angle after trajectory parameter sigma, starting from
        /// theta = 0 with the entry momentum above.
        static double theta(double c, double mu, double force, double sigma);

        /// Momentum conjugate to theta after trajectory parameter sigma.
        static double conjugateMomentum(double c, double mu, double force, double sigma);

        /// Residual of the extended shell at the given point of the
        /// trajectory, held at exactly zero by construction.
        static double constraintResidual(double c, double mu, double force, double sigma);

        /// Trajectory parameter at which theta(...) first equals target, in
        /// closed form from the quadratic it solves.
        static double sigmaToReach(double c, double mu, double force, double target);

        /// The time reverse of the outward trajectory, theta(sigma_out -
        /// sigma): starts at pi/2 when sigma = 0 and reaches zero at sigma =
        /// sigmaToReach(..., pi/2).
        static double thetaReturning(double c, double mu, double force, double sigma);
    };

}

#endif
