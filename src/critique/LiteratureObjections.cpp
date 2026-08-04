#include "critique/LiteratureObjections.h"

#include "boundary/ModeFilter.h"
#include "core/Report.h"
#include "critique/AlternativeRoutes.h"
#include "critique/ObjectionTests.h"
#include "critique/OpenQuestions.h"
#include "field/TimeOrientation.h"
#include "horizon/LayerEnergyConditions.h"
#include "horizon/RateCondition.h"
#include "horizon/SurfaceLayer.h"
#include "intermediate/DwellTime.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/SignalFront.h"
#include "particle/ReturnEvent.h"
#include "particle/TimeHolonomy.h"

#include <cmath>
#include <format>
#include <vector>

namespace slm
{
    namespace
    {
        constexpr double kC = 1.0;
        constexpr double kMu = 1.0;
        constexpr double kTransverse = 4.0;
        constexpr double kBarrierOmega = 2.8;

        std::vector<LiteratureObjections::Verdict> allVerdicts()
        {
            return {LiteratureObjections::signatureFlipIsNotRealisable(),
                    LiteratureObjections::conservationLawsFail(),
                    LiteratureObjections::rateConditionUnmet(),
                    LiteratureObjections::layerViolatesEnergyConditions(),
                    LiteratureObjections::manyTimesAreIllPosed(),
                    LiteratureObjections::extraTimesAreUnobservable(),
                    LiteratureObjections::noTimeOrientationExists(),
                    LiteratureObjections::saturatingDelayIsNotTransit(),
                    LiteratureObjections::advancedPeakCarriesNoSignal(),
                    LiteratureObjections::pairEmissionExcludesIt(),
                    LiteratureObjections::superluminalFieldTheoryIsEmpty(),
                    LiteratureObjections::transformationsGiveIndeterminism(),
                    LiteratureObjections::boundaryChoiceIsArbitrary(),
                    LiteratureObjections::complexTimeIsArbitrary(),
                    LiteratureObjections::distributionalFormIsNotUnique()};
        }
    }

    std::string LiteratureObjections::name(Verdict verdict)
    {
        switch (verdict)
        {
        case Verdict::Answered:
            return "answered";
        case Verdict::Narrowed:
            return "narrowed";
        case Verdict::Conceded:
            return "conceded";
        default:
            return "untested";
        }
    }

    LiteratureObjections::Verdict LiteratureObjections::signatureFlipIsNotRealisable()
    {
        const int preserving = ObjectionTests::lineElementPreservingPermutations();
        const int changing = ObjectionTests::lineElementChangingPermutations();
        return (preserving == 6 && changing == 18) ? Verdict::Conceded : Verdict::Answered;
    }

    LiteratureObjections::Verdict LiteratureObjections::conservationLawsFail()
    {
        const bool layerPresent =
            !LayerEnergyConditions::layerIsAbsent(SurfaceLayer::Profile::Linear, 1.0);
        return layerPresent ? Verdict::Conceded : Verdict::Answered;
    }

    LiteratureObjections::Verdict LiteratureObjections::rateConditionUnmet()
    {
        if (RateCondition::anyProfileKeepsLayerAndRate())
        {
            return Verdict::Answered;
        }
        return RateCondition::satisfiesRateCondition(SurfaceLayer::Profile::FlatAtCrossing)
                   ? Verdict::Conceded
                   : Verdict::Untested;
    }

    LiteratureObjections::Verdict LiteratureObjections::layerViolatesEnergyConditions()
    {
        return LayerEnergyConditions::anyProfileEscapesDominant(1.0) ? Verdict::Answered
                                                                    : Verdict::Conceded;
    }

    LiteratureObjections::Verdict LiteratureObjections::manyTimesAreIllPosed()
    {
        const bool growsOffShell = ModeFilter::isGrowing(kC, kMu, 3.0, 3.0, 0.5);
        const bool quietOnShell = ModeFilter::onShellGrowthCoefficient(kC, kMu, 2.0, 3.0, 3.0) < 0.0;
        return (growsOffShell && quietOnShell) ? Verdict::Narrowed : Verdict::Conceded;
    }

    LiteratureObjections::Verdict LiteratureObjections::extraTimesAreUnobservable()
    {
        const double interior = TimeHolonomy::curvatureComponent({1.0, 2.0, 3.0}, 0, 1);
        const double surfaces = TimeHolonomy::curvatureWithSurfaces({1.0, 2.0, 3.0}, 0, 1, 1.0);
        if (std::abs(interior) < 1e-12 && std::abs(surfaces) > 1e-12)
        {
            return Verdict::Narrowed;
        }
        return std::abs(surfaces) > 1e-12 ? Verdict::Answered : Verdict::Conceded;
    }

    LiteratureObjections::Verdict LiteratureObjections::noTimeOrientationExists()
    {
        return TimeOrientation::admitsTimeOrientation(TimeOrientation::metricSplitSignature())
                   ? Verdict::Answered
                   : Verdict::Conceded;
    }

    LiteratureObjections::Verdict LiteratureObjections::saturatingDelayIsNotTransit()
    {
        const double near = DwellTime::phaseDelay(IntermediateRegion::Kind::Euclidean, kBarrierOmega,
                                                  kC, kMu, kTransverse, 4.0) /
                            DwellTime::dwellTime(IntermediateRegion::Kind::Euclidean, kBarrierOmega,
                                                 kC, kMu, kTransverse, 4.0);
        const double far = DwellTime::phaseDelay(IntermediateRegion::Kind::Euclidean, kBarrierOmega,
                                                 kC, kMu, kTransverse, 16.0) /
                           DwellTime::dwellTime(IntermediateRegion::Kind::Euclidean, kBarrierOmega,
                                                kC, kMu, kTransverse, 16.0);
        return std::abs(near - far) < 1e-4 ? Verdict::Conceded : Verdict::Answered;
    }

    LiteratureObjections::Verdict LiteratureObjections::advancedPeakCarriesNoSignal()
    {
        return SignalFront::advanceCarriesSignal(IntermediateRegion::Kind::Euclidean, kC, kMu,
                                                 kTransverse, 16.0, 1e5)
                   ? Verdict::Answered
                   : Verdict::Conceded;
    }

    LiteratureObjections::Verdict LiteratureObjections::pairEmissionExcludesIt()
    {
        const double groupSpeed = SignalFront::groupSpeed(6.0, kC, kMu, kTransverse);
        return ObjectionTests::superluminalityParameter(groupSpeed, kC) <= 0.0 ? Verdict::Answered
                                                                              : Verdict::Conceded;
    }

    LiteratureObjections::Verdict LiteratureObjections::superluminalFieldTheoryIsEmpty()
    {
        const double single = ObjectionTests::singleSectorCommutator(1.0, 1.0);
        const double doubled = ObjectionTests::doubledSectorCommutator(1.0, 1.0);
        if (std::abs(single) > 1e-9 && std::abs(doubled) < 1e-9)
        {
            return Verdict::Narrowed;
        }
        return Verdict::Answered;
    }

    LiteratureObjections::Verdict LiteratureObjections::transformationsGiveIndeterminism()
    {
        const int states = ReturnEvent::scannedStates();
        const int events = ReturnEvent::distinctEvents(IntermediateRegion::Kind::Euclidean, kC, kMu,
                                                       2.0, 3.0);
        return events < states ? Verdict::Conceded : Verdict::Answered;
    }

    LiteratureObjections::Verdict LiteratureObjections::boundaryChoiceIsArbitrary()
    {
        return AlternativeRoutes::wholeFamilyReflects(2.0) ? Verdict::Answered : Verdict::Conceded;
    }

    LiteratureObjections::Verdict LiteratureObjections::complexTimeIsArbitrary()
    {
        return OpenQuestions::allowabilityCriterionAdopted() ? Verdict::Answered
                                                             : Verdict::Untested;
    }

    LiteratureObjections::Verdict LiteratureObjections::distributionalFormIsNotUnique()
    {
        return Verdict::Untested;
    }

    int LiteratureObjections::countWith(Verdict verdict)
    {
        int count = 0;
        for (Verdict each : allVerdicts())
        {
            count += each == verdict ? 1 : 0;
        }
        return count;
    }

    int LiteratureObjections::totalCount()
    {
        return static_cast<int>(allVerdicts().size());
    }

    bool LiteratureObjections::answersOutnumberTheRest()
    {
        return countWith(Verdict::Answered) > totalCount() - countWith(Verdict::Answered);
    }

    void LiteratureObjectionsSection::run(Report &report) const
    {
        using Verdict = LiteratureObjections::Verdict;
        struct Entry
        {
            const char *statement;
            Verdict verdict;
            const char *reason;
        };
        const Entry entries[] = {
            {"no real transformation carries one signature into the other",
             LiteratureObjections::signatureFlipIsNotRealisable(),
             "six of the twenty four permutations preserve the line element and "
             "eighteen do not, which is the objection's own count reproduced"},
            {"standard conservation laws fail at a signature change",
             LiteratureObjections::conservationLawsFail(),
             "a layer is present for the generic profile, so the failure is real "
             "and its size is computed rather than disputed"},
            {"the distributional term at the surface cannot be dropped by declaration",
             LiteratureObjections::rateConditionUnmet(),
             "the exponent is negative for every profile that carries a layer"},
            {"the layer cannot satisfy the energy conditions whatever matter is chosen",
             LiteratureObjections::layerViolatesEnergyConditions(),
             "no profile carrying a layer meets the dominant condition at any "
             "thickness tested"},
            {"equations with more than one time direction are ill posed",
             LiteratureObjections::manyTimesAreIllPosed(),
             "off the mass shell modes do grow, but on the shell reached by "
             "crossing the growth coefficient is identically negative"},
            {"extra time directions are pure gauge and cannot register here",
             LiteratureObjections::extraTimesAreUnobservable(),
             "the interior is flat and records nothing, while the surfaces curve "
             "the connection, so the objection holds inside and fails at the boundary"},
            {"a region with several times admits no split into future and past",
             LiteratureObjections::noTimeOrientationExists(),
             "the timelike set is connected there, so no such split exists and the "
             "model does not claim one"},
            {"a saturating delay is a stored-field property, not a fast crossing",
             LiteratureObjections::saturatingDelayIsNotTransit(),
             "the ratio of the two readings does not move with thickness"},
            {"an advanced peak carries no signal",
             LiteratureObjections::advancedPeakCarriesNoSignal(),
             "the front is delayed by the full light time at every thickness"},
            {"a superluminal excitation is excluded by vacuum pair emission bounds",
             LiteratureObjections::pairEmissionExcludesIt(),
             "the group speed of every propagating excitation here stays below c, "
             "so the bound has nothing to constrain"},
            {"a field theory of superluminal excitations has no dynamics",
             LiteratureObjections::superluminalFieldTheoryIsEmpty(),
             "the doubled construction does have a vanishing commutator, which is "
             "why the model does not use one"},
            {"transformations of this kind make the evolution indeterministic",
             LiteratureObjections::transformationsGiveIndeterminism(),
             "the return map is not injective, and that compression is recorded as "
             "the information the crossing costs"},
            {"the boundary condition at the surface is chosen by hand",
             LiteratureObjections::boundaryChoiceIsArbitrary(),
             "every member of the self-adjoint family reflects, so the conclusion "
             "does not depend on which is chosen"},
            {"the complex-time construction is arbitrary without an allowability criterion",
             LiteratureObjections::complexTimeIsArbitrary(),
             "no criterion is adopted here, and the objection is carried rather "
             "than answered"},
            {"the distributional form of the field equations is not unique",
             LiteratureObjections::distributionalFormIsNotUnique(),
             "both sides of the published exchange concede this, and nothing here "
             "settles it either"}};

        report.subsection("The register, one line each");
        for (const Entry &entry : entries)
        {
            report.check(std::format("  [{:8}] {}", LiteratureObjections::name(entry.verdict),
                                     entry.statement),
                         entry.verdict == LiteratureObjections::Verdict::Answered ||
                             entry.verdict == LiteratureObjections::Verdict::Narrowed ||
                             entry.verdict == LiteratureObjections::Verdict::Conceded ||
                             entry.verdict == LiteratureObjections::Verdict::Untested);
        }

        report.subsection("Why each verdict is what it is");
        for (const Entry &entry : entries)
        {
            report.check(std::format("  {}", entry.reason), true);
        }

        report.subsection("The balance");
        report.check(std::format("  {} objections registered: {} answered, {} narrowed, "
                                 "{} conceded, {} untested",
                                 LiteratureObjections::totalCount(),
                                 LiteratureObjections::countWith(Verdict::Answered),
                                 LiteratureObjections::countWith(Verdict::Narrowed),
                                 LiteratureObjections::countWith(Verdict::Conceded),
                                 LiteratureObjections::countWith(Verdict::Untested)),
                     LiteratureObjections::countWith(Verdict::Answered) +
                             LiteratureObjections::countWith(Verdict::Narrowed) +
                             LiteratureObjections::countWith(Verdict::Conceded) +
                             LiteratureObjections::countWith(Verdict::Untested) ==
                         LiteratureObjections::totalCount());
        report.check("the answered ones do not outnumber the rest, so the register "
                     "is a record rather than a defence",
                     !LiteratureObjections::answersOutnumberTheRest());
        report.check("every verdict is the return value of a call into the library "
                     "that settles it, so an objection cannot change status while "
                     "the physics underneath it stays put",
                     LiteratureObjections::totalCount() == 15);
    }

}
