#pragma once

#include "core/Section.h"

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
    /// Reading the same trajectory as a displacement from the far endpoint,
    /// pi/2 minus theta, gives a second angle that starts at pi/2 and falls
    /// to zero at exactly the trajectory parameter theta itself reaches
    /// pi/2. No second construction is needed for the return: it is the
    /// same one, read from the other end.
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

        /// The same trajectory read as a displacement from pi/2: starts at
        /// pi/2 when sigma = 0 and reaches zero at sigma = sigmaToReach(...,
        /// pi/2).
        static double thetaReturning(double c, double mu, double force, double sigma);
    };

    /// Section verifying the constant-force crossing of theta, its guaranteed
    /// reach past the degenerate point, and the same trajectory read as a
    /// return to theta = 0.
    class ContinuousCrossingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A constant force along the crossing angle, and the crossing it guarantees";
        }
        void run(Report &report) const override;
    };

}
