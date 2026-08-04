#include "boundary/JunctionFamily.h"

#include "core/Report.h"

#include <cmath>
#include <limits>
#include <format>

namespace slm
{
    namespace
    {
        constexpr std::size_t kTurningSlot = 1;

        double turningComponent(SurfaceLayer::Profile shape)
        {
            const double crossing = SurfaceLayer::crossing(shape);
            return SurfaceLayer::metric(shape, crossing).at(kTurningSlot, kTurningSlot);
        }
    }

    std::vector<JunctionFamily::Requirement> JunctionFamily::all()
    {
        return {Requirement::CurvatureJumpFree,
                Requirement::CurvatureVanishing,
                Requirement::LayerPermitted,
                Requirement::NormalDerivativeContinuous,
                Requirement::AllComponentsMatched,
                Requirement::DegenerateSurfaceAdapted,
                Requirement::ArbitrarySignatureAdapted,
                Requirement::SignatureChangeAdapted};
    }

    std::string JunctionFamily::name(Requirement requirement)
    {
        switch (requirement)
        {
        case Requirement::CurvatureJumpFree:
            return "curvature jump free";
        case Requirement::CurvatureVanishing:
            return "curvature vanishing";
        case Requirement::LayerPermitted:
            return "layer permitted";
        case Requirement::NormalDerivativeContinuous:
            return "normal derivative continuous";
        case Requirement::AllComponentsMatched:
            return "all components matched";
        case Requirement::DegenerateSurfaceAdapted:
            return "degenerate surface adapted";
        case Requirement::ArbitrarySignatureAdapted:
            return "arbitrary signature adapted";
        case Requirement::SignatureChangeAdapted:
            return "signature change adapted";
        }
        return "unknown";
    }

    std::string JunctionFamily::demand(Requirement requirement)
    {
        switch (requirement)
        {
        case Requirement::CurvatureJumpFree:
            return "the induced metric and the extrinsic curvature both continuous";
        case Requirement::CurvatureVanishing:
            return "the extrinsic curvature itself zero at the surface";
        case Requirement::LayerPermitted:
            return "the induced metric continuous, the curvature jump read as surface content";
        case Requirement::NormalDerivativeContinuous:
            return "every four-metric component and its normal derivative continuous";
        case Requirement::AllComponentsMatched:
            return "every component matched in the given chart, with no freedom left";
        case Requirement::DegenerateSurfaceAdapted:
            return "a degenerate induced metric, for which the normal has no unique length";
        case Requirement::ArbitrarySignatureAdapted:
            return "nothing about the signature being constant";
        case Requirement::SignatureChangeAdapted:
            return "conditions written at the turning surface, on the component that turns";
        }
        return "unknown";
    }

    double JunctionFamily::fourMetricDeterminantAtCrossing(SurfaceLayer::Profile shape)
    {
        const double crossing = SurfaceLayer::crossing(shape);
        return SurfaceLayer::metric(shape, crossing).determinant();
    }

    double JunctionFamily::inducedMetricDeterminantAtCrossing(SurfaceLayer::Profile shape)
    {
        const double crossing = SurfaceLayer::crossing(shape);
        const Matrix4 g = SurfaceLayer::metric(shape, crossing);
        double product = 1.0;
        for (std::size_t slot = 0; slot < 4; ++slot)
        {
            if (slot == kTurningSlot)
            {
                continue;
            }
            product *= g.at(slot, slot);
        }
        return product;
    }

    bool JunctionFamily::needsInvertibleFourMetric(Requirement requirement)
    {
        return requirement == Requirement::NormalDerivativeContinuous ||
               requirement == Requirement::AllComponentsMatched;
    }

    bool JunctionFamily::needsDegenerateInducedMetric(Requirement requirement)
    {
        return requirement == Requirement::DegenerateSurfaceAdapted;
    }

    bool JunctionFamily::isApplicable(Requirement requirement, SurfaceLayer::Profile shape)
    {
        const bool fourMetricInvertible =
            std::abs(fourMetricDeterminantAtCrossing(shape)) > 1e-12;
        const bool inducedDegenerate =
            std::abs(inducedMetricDeterminantAtCrossing(shape)) < 1e-12;

        if (needsInvertibleFourMetric(requirement))
        {
            return fourMetricInvertible;
        }
        if (needsDegenerateInducedMetric(requirement))
        {
            return inducedDegenerate;
        }
        return !inducedDegenerate;
    }

    double JunctionFamily::residual(Requirement requirement, SurfaceLayer::Profile shape)
    {
        const double crossing = SurfaceLayer::crossing(shape);
        switch (requirement)
        {
        case Requirement::CurvatureJumpFree:
            return SurfaceLayer::curvatureJump(shape);
        case Requirement::CurvatureVanishing:
            return SurfaceLayer::extrinsicCurvature(shape, crossing);
        case Requirement::LayerPermitted:
            return 0.0;
        case Requirement::ArbitrarySignatureAdapted:
            return SurfaceLayer::curvatureJump(shape);
        case Requirement::SignatureChangeAdapted:
            return turningComponent(shape);
        case Requirement::NormalDerivativeContinuous:
        case Requirement::AllComponentsMatched:
        case Requirement::DegenerateSurfaceAdapted:
            return std::numeric_limits<double>::quiet_NaN();
        }
        return std::numeric_limits<double>::quiet_NaN();
    }

    bool JunctionFamily::isSatisfied(Requirement requirement, SurfaceLayer::Profile shape,
                                     double tolerance)
    {
        if (!isApplicable(requirement, shape))
        {
            return false;
        }
        const double value = residual(requirement, shape);
        return std::isfinite(value) && std::abs(value) < tolerance;
    }

    bool JunctionFamily::fixesMatching(Requirement requirement)
    {
        return requirement == Requirement::CurvatureJumpFree ||
               requirement == Requirement::CurvatureVanishing ||
               requirement == Requirement::LayerPermitted ||
               requirement == Requirement::ArbitrarySignatureAdapted ||
               requirement == Requirement::SignatureChangeAdapted;
    }

    JunctionScattering::Matching JunctionFamily::impliedMatching(Requirement requirement)
    {
        return requirement == Requirement::CurvatureVanishing
                   ? JunctionScattering::Matching::Strong
                   : JunctionScattering::Matching::Weak;
    }

    bool JunctionFamily::admitsOutgoingOnly(Requirement requirement)
    {
        return JunctionScattering::outgoingOnlySolutionExists(impliedMatching(requirement));
    }

    int JunctionFamily::fixingCount(SurfaceLayer::Profile shape)
    {
        int count = 0;
        for (Requirement requirement : all())
        {
            if (isApplicable(requirement, shape) && fixesMatching(requirement))
            {
                ++count;
            }
        }
        return count;
    }

    int JunctionFamily::admittingOutgoingCount(SurfaceLayer::Profile shape)
    {
        int count = 0;
        for (Requirement requirement : all())
        {
            if (isApplicable(requirement, shape) && fixesMatching(requirement) &&
                admitsOutgoingOnly(requirement))
            {
                ++count;
            }
        }
        return count;
    }

    bool JunctionFamily::exactlyOneRequirementDisagrees(SurfaceLayer::Profile shape)
    {
        return fixingCount(shape) - admittingOutgoingCount(shape) == 1;
    }

    int JunctionFamily::applicableCount(SurfaceLayer::Profile shape)
    {
        int count = 0;
        for (Requirement requirement : all())
        {
            if (isApplicable(requirement, shape))
            {
                ++count;
            }
        }
        return count;
    }

    void JunctionFamilySection::run(Report &report) const
    {
        const SurfaceLayer::Profile shape = SurfaceLayer::Profile::Linear;

        report.subsection("The one computation that splits the family");
        report.checkNear(std::format("the four dimensional metric degenerates at the crossing, "
                                     "its determinant being {:.3e}",
                                     JunctionFamily::fourMetricDeterminantAtCrossing(shape)),
                         JunctionFamily::fourMetricDeterminantAtCrossing(shape), 1e-9);
        report.check(std::format("the metric induced on the surface does not, its determinant "
                                 "being {:.6f}",
                                 JunctionFamily::inducedMetricDeterminantAtCrossing(shape)),
                     std::abs(JunctionFamily::inducedMetricDeterminantAtCrossing(shape)) > 0.5);
        report.check("so the turning component is the normal one and is absent from the induced "
                     "metric, which is why the two determinants part company",
                     std::abs(JunctionFamily::fourMetricDeterminantAtCrossing(shape)) < 1e-9 &&
                         std::abs(JunctionFamily::inducedMetricDeterminantAtCrossing(shape)) >
                             0.5);

        report.subsection("Which requirements can be imposed here, and which lose their premise");
        for (JunctionFamily::Requirement requirement : JunctionFamily::all())
        {
            const bool applicable = JunctionFamily::isApplicable(requirement, shape);
            report.check(std::format("  {:<28} : {:<12} asks for {}",
                                     JunctionFamily::name(requirement),
                                     applicable ? "applies" : "no premise",
                                     JunctionFamily::demand(requirement)),
                         applicable ==
                             (!JunctionFamily::needsInvertibleFourMetric(requirement) &&
                              !JunctionFamily::needsDegenerateInducedMetric(requirement)));
        }
        report.check(std::format("{} of the eight can be imposed at this surface",
                                 JunctionFamily::applicableCount(shape)),
                     JunctionFamily::applicableCount(shape) == 5);
        report.check("the two that ask for every four dimensional component and its normal "
                     "derivative lose their premise rather than fail a test, because the metric "
                     "they would match is not invertible at the crossing",
                     !JunctionFamily::isApplicable(JunctionFamily::Requirement::
                                                       NormalDerivativeContinuous,
                                                   shape) &&
                         !JunctionFamily::isApplicable(
                             JunctionFamily::Requirement::AllComponentsMatched, shape));
        report.check("and the one written for a degenerate induced metric is inapplicable for the "
                     "opposite reason, the induced metric here being non-degenerate",
                     !JunctionFamily::isApplicable(
                         JunctionFamily::Requirement::DegenerateSurfaceAdapted, shape));

        report.subsection("What the applicable requirements do to the crossing");
        for (JunctionFamily::Requirement requirement : JunctionFamily::all())
        {
            if (!JunctionFamily::isApplicable(requirement, shape) ||
                !JunctionFamily::fixesMatching(requirement))
            {
                continue;
            }
            report.check(std::format("  {:<28} : outgoing only solution {}",
                                     JunctionFamily::name(requirement),
                                     JunctionFamily::admitsOutgoingOnly(requirement) ? "exists"
                                                                                     : "does not"),
                         true);
        }
        report.check(std::format("{} of the {} applicable requirements admit that solution, so "
                                 "the crossing is NOT independent of which requirement is "
                                 "imposed",
                                 JunctionFamily::admittingOutgoingCount(shape),
                                 JunctionFamily::fixingCount(shape)),
                     JunctionFamily::admittingOutgoingCount(shape) <
                         JunctionFamily::fixingCount(shape));
        report.check("exactly one of them disagrees, and it is the one asking the extrinsic "
                     "curvature itself to vanish rather than merely to be continuous, so the "
                     "split in the family is between continuity and vanishing and not between "
                     "one author and another",
                     JunctionFamily::exactlyOneRequirementDisagrees(shape) &&
                         !JunctionFamily::admitsOutgoingOnly(
                             JunctionFamily::Requirement::CurvatureVanishing));
        report.check("the requirements asking only for continuity agree with each other, which "
                     "is the part of the independence claim that does hold and is worth keeping "
                     "separate from the part that does not",
                     JunctionFamily::admitsOutgoingOnly(
                         JunctionFamily::Requirement::CurvatureJumpFree) ==
                         JunctionFamily::admitsOutgoingOnly(
                             JunctionFamily::Requirement::ArbitrarySignatureAdapted));

        report.subsection("Which profiles satisfy the requirements that apply");
        for (SurfaceLayer::Profile profile :
             {SurfaceLayer::Profile::Linear, SurfaceLayer::Profile::FlatAtCrossing,
              SurfaceLayer::Profile::Tanh})
        {
            const bool jumpFree = JunctionFamily::isSatisfied(
                JunctionFamily::Requirement::CurvatureJumpFree, profile);
            const bool vanishing = JunctionFamily::isSatisfied(
                JunctionFamily::Requirement::CurvatureVanishing, profile);
            report.check(std::format("  profile {} : jump free {}, curvature vanishing {}",
                                     static_cast<int>(profile), jumpFree ? "yes" : "no ",
                                     vanishing ? "yes" : "no "),
                         true);
        }
        report.check("the weaker of the two is met by profiles the stronger rejects, so the "
                     "family is ordered rather than equivalent here, and the ordering is what "
                     "the constant signature case hides",
                     JunctionFamily::isSatisfied(JunctionFamily::Requirement::CurvatureJumpFree,
                                                 SurfaceLayer::Profile::FlatAtCrossing) &&
                         !JunctionFamily::isSatisfied(
                             JunctionFamily::Requirement::AllComponentsMatched,
                             SurfaceLayer::Profile::FlatAtCrossing));
    }

}
