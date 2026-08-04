#pragma once

#include "core/Section.h"
#include "horizon/SurfaceLayer.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// The formulas the rival treatments share, written once with the parameter
    /// that separates them left free.
    ///
    /// Positions that argue with each other in the literature often turn out to
    /// be one expression evaluated at different values of one parameter. Where
    /// that is so it is worth writing down, for two reasons. It says exactly
    /// what the disagreement is about, namely the value of that parameter and
    /// nothing else. And it removes the temptation to treat a rival position as
    /// a different physics when it is the same physics at a different setting.
    ///
    /// The point of this class is not to dissolve every disagreement. Some of
    /// them survive, and those are kept elsewhere as standing contradictions.
    /// What is collected here is the part that does reduce, together with the
    /// check that each special case is recovered exactly rather than
    /// approximately, since a unification that only nearly reproduces its
    /// special cases has not unified anything.
    ///
    /// Four reductions are built. The junction condition, where the strong and
    /// the weak choice are one condition at two values of a weight. The
    /// interior wavenumber, where all four kinds of intermediate region are one
    /// expression in the number of turned directions. The crossing time, where
    /// the competing clocks are one amplitude differentiated with respect to
    /// different parameters. The dispersion relation, where both signatures are
    /// one relation in the sign the metric assigns the crossing direction.
    class CommonFormulas
    {
    public:
        /// The junction condition with the weight left free: zero asks the
        /// extrinsic curvature to vanish, which is the strong choice, and one
        /// asks only for continuity, which is the weak one. Returns the
        /// residual the condition demands be zero.
        static double junctionResidual(double weight, double curvatureBefore,
                                       double curvatureAfter);

        /// Whether the condition at weight zero agrees, profile by profile,
        /// with the strong test built separately from the extrinsic curvature.
        /// The comparison is against an independent construction rather than
        /// against the same expression restated, so it can fail.
        static bool recoversStrongChoice(SurfaceLayer::Profile shape);

        /// Whether the condition at weight one agrees with the weak test built
        /// separately, on the same terms.
        static bool recoversWeakChoice(SurfaceLayer::Profile shape);

        /// The interior squared wavenumber as one expression in the number of
        /// turned directions, which runs from none through the Kleinian case to
        /// the fully turned one.
        static double interiorSquared(int turnedDirections, double omega, double c, double mu,
                                      double transverseSquared);

        /// Whether that expression reproduces the value the region library
        /// gives for a named kind, exactly.
        static bool reproducesKind(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                   double transverseSquared);

        /// The crossing time as one amplitude differentiated with respect to a
        /// chosen parameter: the frequency gives the phase reading, the barrier
        /// height gives the clock components.
        enum class Parameter
        {
            Frequency,
            BarrierHeight
        };

        /// Logarithmic derivative of the transmission amplitude with respect to
        /// the chosen parameter, whose parts are the competing clocks.
        static double clockFromParameter(Parameter parameter, IntermediateRegion::Kind kind,
                                         double omega, double c, double mu,
                                         double transverseSquared, double thickness);

        /// Whether the phase reading is recovered exactly by differentiating
        /// with respect to the frequency.
        static bool reproducesPhaseReading(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared, double thickness);

        /// The dispersion relation with the sign the metric assigns the
        /// crossing direction left free, so that both signatures are one
        /// relation. Returns the residual, zero on shell.
        static double dispersionResidual(double crossingSign, double omega, double c, double mu,
                                         double normalSquared, double transverseSquared);

        /// Whether the near-side signature is recovered at a crossing sign of minus
        /// one, and the far side at plus one.
        static bool recoversBothSignatures(double omega, double c, double mu,
                                           double transverseSquared);

        /// How many of the four reductions recover every one of their special
        /// cases exactly.
        static int exactReductionCount();
    };

    /// Section writing each shared formula once and checking that every special
    /// case falls out of it exactly.
    class CommonFormulasSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The formulas the rival treatments share, written once";
        }
        void run(Report &report) const override;
    };

}
