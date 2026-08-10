#pragma once

#include "core/Section.h"

#include <array>

namespace slm
{

    /// A particle in Region II under a constant force along the single space
    /// axis, replacing the question the free mass shell leaves open: which of
    /// its two signs the crossing wavenumber takes.
    ///
    /// The free constraint k1^2+k2^2+k3^2 - q^2/c^2 + mu = 0 is extended by a
    /// potential linear in r, V(r) = 2*force*r. This is the minimal term that
    /// breaks the r-translation symmetry alone: it carries no dependence on
    /// t1, t2 or t3, so the three conserved "energy" components and their
    /// O(3) symmetry are untouched. Hamilton's equations from the extended
    /// constraint,
    ///
    ///   dr/dsigma = -q/c^2,  dq/dsigma = -force,
    ///
    /// integrate in closed form. The entry branch is fixed by taking the
    /// negative root of the free mass shell at r = 0, which is the sign that
    /// carries the particle into increasing r; a positive force then drives
    /// q strictly more negative, so r increases without bound and reaches
    /// any target exactly once, for every mass, every energy vector and
    /// every positive force. No second branch and no threshold survive this
    /// substitution.
    class AcceleratedCrossing
    {
    public:
        using Three = std::array<double, 3>;

        /// The entry value of q at r = 0, the negative root of the free mass
        /// shell, which is the branch that enters increasing r.
        static double entryMomentum(double c, double mu, const Three &energy);

        /// Position along the single space axis after trajectory parameter
        /// sigma, starting from r = 0 with the entry momentum above.
        static double position(double c, double mu, const Three &energy, double force,
                               double sigma);

        /// Conjugate momentum q after trajectory parameter sigma.
        static double conjugateMomentum(double c, double mu, const Three &energy, double force,
                                        double sigma);

        /// Residual of the extended mass shell at the given point of the
        /// trajectory, held at exactly zero by construction.
        static double constraintResidual(double c, double mu, const Three &energy, double force,
                                         double sigma);

        /// Trajectory parameter at which position(...) first equals target,
        /// in closed form from the quadratic it solves.
        static double parameterToReach(double c, double mu, const Three &energy, double force,
                                       double target);
    };

    /// Section verifying the constant-force crossing and its guaranteed reach.
    class AcceleratedCrossingSection : public Section
    {
    public:
        std::string title() const override
        {
            return "A constant force along the single space axis, and the crossing it guarantees";
        }
        void run(Report &report) const override;
    };

}
