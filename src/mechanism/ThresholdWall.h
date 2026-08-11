#pragma once

#include "core/Section.h"

namespace slm
{

    /// The threshold as a domain wall, which is an alternative reading of the
    /// constant @f$ F @f$ and is not the mechanism this project uses.
    ///
    /// The mechanism is accelerating and decelerating the particle, and
    /// @ref VelocityCrossing carries it: the crossing angle is the particle's
    /// own speed through @f$ \beta = \tan\theta @f$, and @f$ F @f$ is the
    /// accelerating force. This section reads the same constant differently, as
    /// a coupling to a scalar condensate, and the two readings cannot both be
    /// true of one apparatus. What is kept here is the geometry the reading
    /// fixes and the arithmetic that checks it, not a second way across.
    ///
    /// Under that reading the crossing angle is a real scalar field rather than
    /// a coordinate the particle carries. The field has the potential
    /// @f$ U(\theta) = \Lambda^4 \sin^2 2\theta @f$, whose minima sit at
    /// @f$ \theta = 0 @f$ and @f$ \theta = \pi/2 @f$ and whose single maximum
    /// between them sits at @f$ \theta = \pi/4 @f$. The two minima are the two
    /// regions and the maximum is the degenerate metric, so the potential and
    /// the metric family degenerate at the same place without either being
    /// arranged to match the other.
    ///
    /// With that potential the static field equation is sine-Gordon in
    /// @f$ 4\theta @f$, and it has a kink: @ref profile. The kink is a
    /// solution, not a choice, and it is what the earlier work called an
    /// applied force. Two things follow that a posited force could not give.
    /// The width @ref widthFromCouplings is fixed by the two constants of the
    /// field rather than free, and the slope @ref slope is largest exactly at
    /// the degenerate point, so a particle crossing the wall spends its least
    /// time where the metric is worst.
    ///
    /// Read as a mechanism this would leave the field itself posited: its
    /// potential scale, its stiffness, and the coupling by which a particle
    /// feels it. The project does not read it that way, and states the reading
    /// here only to keep the alternative on the record.
    class ThresholdWall
    {
    public:
        /// The potential @f$ \Lambda^4 \sin^2 2\theta @f$.
        static double potential(double lambdaScale, double theta);

        /// The potential's derivative with respect to @p theta.
        static double potentialSlope(double lambdaScale, double theta);

        /// The wall width @f$ L = \sqrt{\lambda / 8\Lambda^4} @f$, fixed by the
        /// field's stiffness @p stiffness and potential scale @p lambdaScale.
        static double widthFromCouplings(double stiffness, double lambdaScale);

        /// The kink @f$ \theta(x) = \arctan e^{x/L} @f$, which carries the
        /// field from @f$ 0 @f$ at @f$ x \to -\infty @f$ through
        /// @f$ \pi/4 @f$ at @f$ x = 0 @f$ to @f$ \pi/2 @f$ at
        /// @f$ x \to +\infty @f$.
        static double profile(double x, double width);

        /// The kink's slope @f$ \sin(2\theta)/2L @f$, in closed form.
        static double slope(double x, double width);

        /// The energy per unit area stored in the wall,
        /// @f$ \sigma = \lambda / 2L @f$.
        static double tension(double stiffness, double width);

        /// The distance beyond the wall centre at which the field is within
        /// @p tolerance of @f$ \pi/2 @f$, which is @f$ L \ln(1/\text{tol}) @f$
        /// to leading order. The far side is reached at a distance that grows
        /// only logarithmically as the tolerance tightens.
        static double distanceToReach(double width, double tolerance);

        /// The mass parameter a particle of bare parameter @p mu carries at
        /// crossing angle @p theta, given a linear coupling @p force to the
        /// field: @f$ \mu(\theta) = \mu + 2 F \theta @f$.
        ///
        /// A linear coupling to the field is an ordinary Yukawa term, and one
        /// half the slope of this mass parameter is numerically the constant the
        /// crossing sections use. The agreement is arithmetic and does not
        /// settle what the constant is: the project reads it as the accelerating
        /// force, and reads a particle standing in a wall as the alternative it
        /// declines.
        static double massParameter(double mu, double force, double theta);

        /// The factor by which a particle's rest energy grows between the two
        /// minima, @f$ \sqrt{\mu + \pi F} / \sqrt{\mu} @f$.
        static double restEnergyRatio(double mu, double force);

        /// The smallest coupling for which the mass parameter stays positive
        /// all the way to @f$ \pi/2 @f$, namely @f$ -\mu/\pi @f$. Couplings
        /// below it drive the particle off the real mass shell inside the wall.
        static double smallestAdmissibleForce(double mu);
    };

    /// Section verifying that the kink solves the field equation, that its
    /// degenerate point is crossed at maximum speed, and that the coupling
    /// reproduces the mass shell the earlier sections assumed. The section
    /// establishes an alternative reading and not the mechanism.
    class ThresholdWallSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The threshold as a domain wall, an alternative reading of the same constant that the project does not use as its mechanism";
        }
        void run(Report &report) const override;
    };

}
