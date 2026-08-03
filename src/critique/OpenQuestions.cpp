#include "critique/OpenQuestions.h"

#include "boundary/ModeFilter.h"
#include "core/Report.h"
#include "particle/TimeReversalSignature.h"
#include "critique/Reconciliation.h"
#include "horizon/DegeneratePath.h"
#include "horizon/LayerEnergyConditions.h"
#include "horizon/RateCondition.h"
#include "horizon/SurfaceLayer.h"
#include "intermediate/DwellTime.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/TraversalClocks.h"
#include "particle/AsymmetricFaces.h"
#include "particle/CellDistribution.h"
#include "quantum/LapseContour.h"
#include "signal/GravitationalChannel.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kC = 1.0;
        constexpr double kMu = 1.0;
        constexpr double kTransverse = 4.0;
    }

    std::string OpenQuestions::name(Status status)
    {
        switch (status)
        {
        case Status::Withdrawn:
            return "withdrawn";
        case Status::Gap:
            return "no counterpart";
        case Status::Open:
            return "open";
        default:
            return "disputed";
        }
    }

    bool OpenQuestions::continuousPathClaimWithdrawn()
    {
        const double pi = std::acos(-1.0);
        const auto endpoint = DegeneratePath::signature(DegeneratePath::allSpace(pi));
        return endpoint != std::array<int, 3>{3, 1, 0};
    }

    bool OpenQuestions::illPosedForEverythingWithdrawn()
    {
        return ModeFilter::isGrowing(kC, kMu, 3.0, 3.0, 0.5) &&
               ModeFilter::onShellGrowthCoefficient(kC, kMu, 2.0, 3.0, 3.0) < 0.0;
    }

    bool OpenQuestions::fastTransitReadingWithdrawn()
    {
        const double near = DwellTime::phaseDelay(IntermediateRegion::Kind::Euclidean, 2.8, kC, kMu,
                                                  kTransverse, 4.0) /
                            DwellTime::dwellTime(IntermediateRegion::Kind::Euclidean, 2.8, kC, kMu,
                                                 kTransverse, 4.0);
        const double far = DwellTime::phaseDelay(IntermediateRegion::Kind::Euclidean, 2.8, kC, kMu,
                                                 kTransverse, 16.0) /
                           DwellTime::dwellTime(IntermediateRegion::Kind::Euclidean, 2.8, kC, kMu,
                                                kTransverse, 16.0);
        return std::abs(near - far) < 1e-4;
    }

    bool OpenQuestions::benignLayerClaimWithdrawn()
    {
        return !LayerEnergyConditions::anyProfileEscapesDominant(1.0) &&
               !LayerEnergyConditions::layerIsAbsent(SurfaceLayer::Profile::Linear, 1.0);
    }

    int OpenQuestions::withdrawnCount()
    {
        int count = 0;
        count += continuousPathClaimWithdrawn() ? 1 : 0;
        count += illPosedForEverythingWithdrawn() ? 1 : 0;
        count += fastTransitReadingWithdrawn() ? 1 : 0;
        count += benignLayerClaimWithdrawn() ? 1 : 0;
        return count;
    }

    bool OpenQuestions::publishedTransmissionExists()
    {
        return false;
    }

    bool OpenQuestions::publishedPacketCrossingExists()
    {
        return false;
    }

    bool OpenQuestions::publishedReturnMapExists()
    {
        return false;
    }

    int OpenQuestions::gapCount()
    {
        int count = 0;
        count += publishedTransmissionExists() ? 0 : 1;
        count += publishedPacketCrossingExists() ? 0 : 1;
        count += publishedReturnMapExists() ? 0 : 1;
        return count;
    }

    bool OpenQuestions::outcomeDistributionKnown()
    {
        const std::vector<double> spectrum = AsymmetricFaces::deflectionSpectrum(1.0, 2.0, 3.0);
        return spectrum.empty();
    }

    bool OpenQuestions::gravitationalCapacityKnown()
    {
        return false;
    }

    bool OpenQuestions::allowabilityCriterionAdopted()
    {
        return false;
    }

    bool OpenQuestions::pairDegeneracyBroken()
    {
        return Reconciliation::returnedQuanta().disagree() &&
               !Reconciliation::returnedEnergy(2.0).disagree();
    }

    bool OpenQuestions::physicalReadingSettled()
    {
        return TraversalClocks::readingsAgreeAgainstLight(IntermediateRegion::Kind::Euclidean, 2.8,
                                                          kC, kMu, kTransverse, 16.0);
    }

    bool OpenQuestions::transmittingThresholdSurvivesRate()
    {
        return RateCondition::anyProfileKeepsLayerAndRate();
    }

    int OpenQuestions::openCount()
    {
        int count = 0;
        count += outcomeDistributionKnown() ? 0 : 1;
        count += gravitationalCapacityKnown() ? 0 : 1;
        count += allowabilityCriterionAdopted() ? 0 : 1;
        count += pairDegeneracyBroken() ? 0 : 1;
        count += physicalReadingSettled() ? 0 : 1;
        count += transmittingThresholdSurvivesRate() ? 0 : 1;
        return count;
    }

    int OpenQuestions::disputedCount()
    {
        return Reconciliation::standingContradictionCount();
    }

    int OpenQuestions::totalCount()
    {
        return withdrawnCount() + gapCount() + openCount() + disputedCount();
    }

    void OpenQuestionsSection::run(Report &report) const
    {
        report.subsection("Claims withdrawn, each by a calculation rather than a change of mind");
        report.check("that no continuous path joins the two signatures: withdrawn, "
                     "since a path exists at the cost of a two-time region",
                     OpenQuestions::continuousPathClaimWithdrawn());
        report.check("that the far side is ill posed for everything: withdrawn, "
                     "since off its mass shell modes grow but on it none do",
                     OpenQuestions::illPosedForEverythingWithdrawn());
        report.check("that a saturating delay is a fast transit: withdrawn, since "
                     "in that regime the delay is a fixed multiple of the stored norm",
                     OpenQuestions::fastTransitReadingWithdrawn());
        report.check("that the transmitting junction is energetically benign: "
                     "withdrawn, since every layer-carrying profile fails the "
                     "dominant condition",
                     OpenQuestions::benignLayerClaimWithdrawn());
        report.check(std::format("  {} claims withdrawn", OpenQuestions::withdrawnCount()),
                     OpenQuestions::withdrawnCount() == 4);

        report.subsection("Questions with no published counterpart to compare against");
        report.check("a transmission coefficient across a signature change: none "
                     "published, so the number computed here stands alone",
                     !OpenQuestions::publishedTransmissionExists());
        report.check("a wave packet carried across a signature change: none "
                     "published, so the packet layer has no precedent for this case",
                     !OpenQuestions::publishedPacketCrossingExists());
        report.check("a map from a far-side orientation to the coordinates of the "
                     "return event: none published",
                     !OpenQuestions::publishedReturnMapExists());
        report.check(std::format("  {} questions with no counterpart", OpenQuestions::gapCount()),
                     OpenQuestions::gapCount() == 3);

        report.subsection("Questions open here as well as outside");
        report.check(std::format("  the outcomes range over a set of {} deflections, but the "
                                 "weight on each is not computed",
                                 AsymmetricFaces::deflectionSpectrum(1.0, 2.0, 3.0).size()),
                     !OpenQuestions::outcomeDistributionKnown());
        report.check(std::format("  the gravitational channel responds, with a contrast of "
                                 "{:.4f} at half a unit, and its capacity is unknown, but the "
                                 "chapter that used it is out of scope, so this is carried as "
                                 "a record and not as an obstacle to the round trip",
                                 GravitationalChannel::contrast(IntermediateRegion::Kind::Kleinian, 1.0, 1.0, 0.5)),
                     !OpenQuestions::gravitationalCapacityKnown());
        report.check("the complex-time construction the return uses needs an "
                     "allowability criterion; one has now been computed and found "
                     "consistent with what this model does, but in the minisuperspace "
                     "form rather than on the two-crossing amplitude itself, so the "
                     "item is narrowed and not closed",
                     !OpenQuestions::allowabilityCriterionAdopted() &&
                         LapseContour::belowSelectsDecaying(8.0, 1.0));
        report.check("a returning particle and a created pair agree in boundary count "
                     "and in apparent charge, and differ only in the energy the region "
                     "loses, which is now specified as a calorimeter measurement with a "
                     "stated resolution and timing, so the item is no longer open in its "
                     "physics but only in its rate",
                     !OpenQuestions::pairDegeneracyBroken() &&
                         TimeReversalSignature::calorimeterSeparates(1.0, 1, 1.5) &&
                         !TimeReversalSignature::practicalAtWeight(6.473136e-37, 1e9, 3.15e7));
        report.check(std::format("  {} of the five readings of the crossing time put it above "
                                 "the speed of light and the rest below, and which reading is "
                                 "the physical one is not settled",
                                 TraversalClocks::readingsFasterThanLight(
                                     IntermediateRegion::Kind::Euclidean, 2.8, kC, kMu, kTransverse,
                                     16.0)),
                     !OpenQuestions::physicalReadingSettled());
        report.check("no profile in this family both carries a layer and satisfies "
                     "the rate condition, so whether a wider family of transitions "
                     "would carry the transmitting reading is not known",
                     !OpenQuestions::transmittingThresholdSurvivesRate());
        report.check(std::format("  {} questions open", OpenQuestions::openCount()),
                     OpenQuestions::openCount() == 6);

        report.subsection("Disagreements an experiment could close");
        report.check(std::format("  {} disagreements give different numbers for one "
                                 "measurement, taken from the reconciliation rather than "
                                 "restated",
                                 OpenQuestions::disputedCount()),
                     OpenQuestions::disputedCount() == Reconciliation::standingContradictionCount());

        report.subsection("The ledger");
        report.check(std::format("  {} items tracked in all: {} withdrawn, {} without "
                                 "counterpart, {} open, {} disputed",
                                 OpenQuestions::totalCount(), OpenQuestions::withdrawnCount(),
                                 OpenQuestions::gapCount(), OpenQuestions::openCount(),
                                 OpenQuestions::disputedCount()),
                     OpenQuestions::totalCount() == OpenQuestions::withdrawnCount() +
                                                        OpenQuestions::gapCount() +
                                                        OpenQuestions::openCount() +
                                                        OpenQuestions::disputedCount());
        report.check("the withdrawn ones outnumber neither the open ones nor the "
                     "disputed ones taken together, so the account is not a "
                     "list of victories",
                     OpenQuestions::withdrawnCount() <=
                         OpenQuestions::openCount() + OpenQuestions::disputedCount());
    }

}
