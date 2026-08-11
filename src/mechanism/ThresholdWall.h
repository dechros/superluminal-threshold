#pragma once

#include "core/Section.h"

namespace slm
{

    /// The threshold as a domain wall, which is what replaces the posited
    /// force with something that solves an equation.
    ///
    /// The crossing angle is treated as a real scalar field rather than as a
    /// coordinate the particle carries. The field has the potential
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
    /// What remains posited is the field itself: its potential scale, its
    /// stiffness, and the coupling by which a particle feels it. Those are the
    /// ordinary ingredients of a scalar sector rather than a force invented for
    /// one trajectory, and that is the whole of the improvement claimed here.
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
        /// This is the whole of the mechanism on the particle's side. A linear
        /// coupling to the field is an ordinary Yukawa term, and the constant
        /// that the earlier work applied as a force is one half the slope of
        /// this mass parameter. The force was never a force; it was a mass that
        /// depends on where the particle stands in the wall.
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
    /// reproduces the mass shell the earlier sections assumed.
    class ThresholdWallSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The threshold as a domain wall, so that the crossing follows from a field equation rather than from an applied force";
        }
        void run(Report &report) const override;
    };

}
