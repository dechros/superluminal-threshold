#pragma once

#include "boundary/JunctionScattering.h"
#include "core/Section.h"
#include "horizon/SurfaceLayer.h"

#include <string>
#include <vector>

namespace slm
{

    /// The matching requirements available at a surface where the signature
    /// turns over, each named by what it demands rather than by who proposed
    /// it, and each tested for whether it can be imposed here at all.
    ///
    /// Two questions have to be kept apart, and running them together is what
    /// makes this subject confusing. The first is whether a requirement is
    /// SATISFIED by a given transition profile. The second is whether the
    /// requirement is APPLICABLE at a surface of this kind in the first place.
    /// A requirement that presupposes an invertible metric is not failed by a
    /// degenerate one, it is inapplicable to it, and reporting that as a
    /// failure would credit the profile with a defect belonging to the
    /// requirement.
    ///
    /// The split is decided by one computation. The four dimensional metric
    /// degenerates at the crossing, because the component that turns over
    /// passes through zero there. The metric induced on the surface does not,
    /// because that component is the normal one and is absent from the induced
    /// metric. So every requirement phrased on the induced metric and its
    /// extrinsic curvature survives, and every requirement phrased on all four
    /// dimensional components and their normal derivatives loses its premise.
    /// Both determinants are computed rather than asserted.
    ///
    /// The requirements that do apply are then carried through to the
    /// scattering problem, since a matching condition earns its place by what
    /// it implies for a crossing and not by being stateable.
    class JunctionFamily
    {
    public:
        enum class Requirement
        {
            CurvatureJumpFree,          ///< induced metric and extrinsic curvature both continuous
            CurvatureVanishing,         ///< the second fundamental form itself required to vanish
            LayerPermitted,             ///< a curvature jump allowed, and read as surface content
            NormalDerivativeContinuous, ///< all four-metric components differentiable across
            AllComponentsMatched,       ///< every component and its normal derivative matched
            DegenerateSurfaceAdapted,   ///< written for a degenerate induced metric
            ArbitrarySignatureAdapted,  ///< carrying no constant-signature assumption
            SignatureChangeAdapted      ///< written at the turning surface itself
        };

        /// Every requirement, in the order they are reported.
        static std::vector<Requirement> all();

        static std::string name(Requirement requirement);

        /// What the requirement asks of the geometry, in one clause.
        static std::string demand(Requirement requirement);

        /// Determinant of the four dimensional metric at the crossing, which
        /// vanishes because the turning component passes through zero.
        static double fourMetricDeterminantAtCrossing(SurfaceLayer::Profile shape);

        /// Determinant of the metric induced on the surface, which omits the
        /// turning component and so stays away from zero.
        static double inducedMetricDeterminantAtCrossing(SurfaceLayer::Profile shape);

        /// Whether the requirement presupposes a metric that can be inverted at
        /// the crossing. These are the ones whose premise fails here.
        static bool needsInvertibleFourMetric(Requirement requirement);

        /// Whether the requirement presupposes a degenerate induced metric,
        /// which is the opposite premise and also fails here.
        static bool needsDegenerateInducedMetric(Requirement requirement);

        /// Whether the requirement can be imposed at this surface at all.
        static bool isApplicable(Requirement requirement, SurfaceLayer::Profile shape);

        /// Residual the requirement asks to vanish, for the requirements that
        /// apply. Meaningless where the requirement is inapplicable, and the
        /// caller is expected to ask that first.
        static double residual(Requirement requirement, SurfaceLayer::Profile shape);

        /// Whether an applicable requirement is met by the given profile.
        static bool isSatisfied(Requirement requirement, SurfaceLayer::Profile shape,
                                double tolerance = 1e-6);

        /// Whether the requirement fixes the conjugate momentum across the
        /// surface, which is what the scattering problem needs from it.
        static bool fixesMatching(Requirement requirement);

        /// The momentum matching an applicable requirement implies.
        static JunctionScattering::Matching impliedMatching(Requirement requirement);

        /// Whether the crossing built on the requirement admits a solution
        /// carrying no wave back towards the surface, which is the property the
        /// round trip depends on.
        static bool admitsOutgoingOnly(Requirement requirement);

        /// How many applicable requirements fix the momentum matching, and so
        /// have a verdict on the crossing at all.
        static int fixingCount(SurfaceLayer::Profile shape);

        /// How many of those admit a solution carrying no wave back towards the
        /// surface. Compared against the count above this says whether the
        /// crossing depends on which requirement is imposed, and the answer
        /// here is that it does: the requirements asking only for continuity
        /// agree with each other, and the one asking the curvature itself to
        /// vanish stands apart.
        static int admittingOutgoingCount(SurfaceLayer::Profile shape);

        /// Whether exactly one applicable requirement disagrees with the rest,
        /// which is the situation found here and is weaker than independence of
        /// the choice.
        static bool exactlyOneRequirementDisagrees(SurfaceLayer::Profile shape);

        /// How many of the family can be imposed at this surface.
        static int applicableCount(SurfaceLayer::Profile shape);
    };

    /// Section testing the whole family of matching requirements.
    class JunctionFamilySection : public Section
    {
    public:
        std::string title() const override
        {
            return "Every matching requirement on offer, and which of them apply here";
        }
        void run(Report &report) const override;
    };

}
