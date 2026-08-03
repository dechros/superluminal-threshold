#pragma once

#include "core/Section.h"

#include <complex>

namespace slm
{

    /// Whether reversing the sense of the distinguished axis leaves the field
    /// equation satisfied.
    ///
    /// Elsewhere it is shown that the metric cannot name one of the two causal
    /// components, because reversing the distinguished axis is an isometry. That
    /// result is about the geometry and says nothing about the dynamics, and the
    /// two are separate claims: a geometry with no preferred sense could still
    /// carry an equation that only one sense solves. This class settles the
    /// second claim for the field this work uses.
    ///
    /// The reversal enters the equation through the second derivative, so the
    /// coefficient it contributes is squared and the two senses are solutions of
    /// the same equation with the same parameters. Nothing is chosen when one of
    /// them is written down first.
    ///
    /// The result is bounded in two directions and both bounds are computed here
    /// rather than described. It is bounded from below by being a statement about
    /// this equation and not about equations in general: a term of odd order in
    /// the derivative along that axis destroys it, and such a term is exhibited
    /// so that what would have to be true for an arrow to be dynamical is on the
    /// page. It is bounded from above by saying nothing about which sense a state
    /// occupies; an equation admitting both solutions is not an equation whose
    /// solutions are symmetric.
    class DynamicsUnderReversal
    {
    public:
        /// Residual of the dispersion relation at the given angular frequency,
        /// which vanishes on a solution.
        static double dispersionResidual(double frequency, double c, double mu,
                                         double wavenumberSquared);

        /// Residual of applying the field operator to a plane wave of the given
        /// frequency, evaluated at a point.
        static double operatorResidual(double frequency, double c, double mu,
                                       double wavenumberSquared, double time,
                                       double position);

        /// Residual of the same, for an operator carrying a term of first order
        /// in the derivative along the distinguished axis, of strength
        /// @p oddCoefficient. This is the term whose presence would make the
        /// sense of that axis dynamical.
        static std::complex<double> oddOrderResidual(double frequency, double c, double mu,
                                                    double wavenumberSquared,
                                                    double oddCoefficient);

        /// Region II counterpart, where the distinguished axis is the single
        /// spatial one and the roles of the arguments are exchanged.
        static double farSideResidual(double rate, double c, double mu, double timelikeSquared);
    };

    /// Section testing whether both senses solve the equation, and what would
    /// have to be added before only one did.
    class DynamicsUnderReversalSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Whether the equation prefers a sense, and what would make it";
        }
        void run(Report &report) const override;
    };

}
