#pragma once

#include "core/Section.h"
#include "horizon/SurfaceLayer.h"

namespace slm
{

    /// Which energy conditions the layer at a signature-changing surface can
    /// satisfy, and which it cannot.
    ///
    /// A junction that transmits carries a surface layer whose strength is set
    /// by the jump in extrinsic curvature. Whether such a layer is physically
    /// acceptable is a separate question from whether it exists, and it is
    /// settled by the causal character of the surface rather than by any choice
    /// of matter: a surface across which the signature changes is not timelike,
    /// and a layer on a non-timelike surface is constrained far more tightly
    /// than one on a timelike shell.
    ///
    /// The induced tensor is classified by its eigenvalue structure. On a
    /// spacelike surface the eigenvalues are all of one causal type and the
    /// dominant energy condition fails, since the energy flux measured by some
    /// observer exceeds the energy density. On a null surface with vanishing
    /// surface pressure the tensor is of the degenerate type that fails every
    /// standard condition, the null one included.
    ///
    /// These functions build the induced tensor from the same profile family
    /// used for the layer strength, evaluate each condition on it, and record
    /// that no profile in the family escapes. The one profile that carries no
    /// layer at all escapes trivially, by having nothing to constrain.
    class LayerEnergyConditions
    {
    public:
        /// Causal character of the surface, decided by the sign the normal
        /// carries in the metric on each side.
        enum class Character
        {
            Timelike,
            Null,
            Spacelike
        };

        /// Strength of the layer the junction carries, which goes as one over
        /// the thickness for a generic profile and vanishes for one stationary
        /// at the crossing.
        static double layerStrength(SurfaceLayer::Profile shape, double thickness);

        /// Surface energy density carried by that layer. On a surface whose
        /// normal is not timelike the roles of density and pressure are
        /// exchanged relative to an ordinary shell, which is what puts the
        /// density on the negative branch.
        static double surfaceDensity(SurfaceLayer::Profile shape, double thickness);

        /// Surface pressure of the same layer.
        static double surfacePressure(SurfaceLayer::Profile shape, double thickness);

        /// Character of a surface across which the signature changes, which
        /// cannot be timelike because the normal changes causal type.
        static Character surfaceCharacter();

        /// Whether the layer satisfies the null energy condition, density plus
        /// pressure not negative.
        static bool satisfiesNull(SurfaceLayer::Profile shape, double thickness);

        /// Whether it satisfies the weak condition, which adds a non-negative
        /// density.
        static bool satisfiesWeak(SurfaceLayer::Profile shape, double thickness);

        /// Whether it satisfies the dominant condition, which requires the
        /// density to dominate the pressure in magnitude.
        static bool satisfiesDominant(SurfaceLayer::Profile shape, double thickness);

        /// Whether the layer vanishes altogether, in which case there is
        /// nothing for a condition to constrain.
        static bool layerIsAbsent(SurfaceLayer::Profile shape, double thickness);

        /// Whether any profile in the family carries a layer that satisfies
        /// the dominant condition.
        static bool anyProfileEscapesDominant(double thickness);

        /// Whether any profile carries a layer satisfying the null condition.
        static bool anyProfileEscapesNull(double thickness);
    };

    /// Section evaluating the energy conditions on the layer the junction
    /// carries.
    class LayerEnergyConditionsSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What the transmitting junction costs in energy conditions";
        }
        void run(Report &report) const override;
    };

}
