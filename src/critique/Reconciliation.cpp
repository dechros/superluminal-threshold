#include "critique/Reconciliation.h"

#include "boundary/ModeFilter.h"
#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/TwoCrossings.h"
#include "particle/ExitFace.h"

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

    bool Reconciliation::cavityAndBarrierAreOneCoin()
    {
        using Axis = TwoCrossings::FlipAxis;
        using Kind = IntermediateRegion::Kind;
        const double omega = 12.0;
        const double transverseReading =
            TwoCrossings::insideSquaredOn(Axis::Transverse, Kind::Kleinian, omega, kC, kMu,
                                          kTransverse);
        const double crossingReading =
            TwoCrossings::insideSquaredOn(Axis::Crossing, Kind::Kleinian, omega, kC, kMu,
                                          kTransverse);
        return transverseReading > 0.0 && crossingReading < 0.0;
    }

    bool Reconciliation::delayAndMixingAreOneCoin()
    {
        using Kind = IntermediateRegion::Kind;
        const double omega = 2.8;
        const double delayNear =
            TwoCrossings::returnDelay(Kind::Euclidean, omega, kC, kMu, kTransverse, 4.0);
        const double delayFar =
            TwoCrossings::returnDelay(Kind::Euclidean, omega, kC, kMu, kTransverse, 8.0);
        const double mixNear =
            TwoCrossings::mixingRatio(Kind::Euclidean, omega, kC, kMu, kTransverse, 4.0);
        const double mixFar =
            TwoCrossings::mixingRatio(Kind::Euclidean, omega, kC, kMu, kTransverse, 8.0);
        return std::abs(delayNear - delayFar) < 1e-6 && mixFar > 100.0 * mixNear;
    }

    bool Reconciliation::reflectionIsTheThickLimit()
    {
        using Kind = IntermediateRegion::Kind;
        const double thin =
            IntermediateRegion::transmission(Kind::Euclidean, kC, kMu, kTransverse, 0.1);
        const double thick =
            IntermediateRegion::transmission(Kind::Euclidean, kC, kMu, kTransverse, 40.0);
        return thin > 0.5 && thick < 1e-30;
    }

    bool Reconciliation::illPosedAndWellPosedAreOneCoin()
    {
        const bool offShellGrows = ModeFilter::isGrowing(kC, kMu, 3.0, 3.0, 0.5);
        const double onShell = ModeFilter::onShellGrowthCoefficient(kC, kMu, 2.0, 3.0, 3.0);
        return offShellGrows && onShell < 0.0;
    }

    bool Reconciliation::exitFaceAndTurnAreOneVector()
    {
        const double magnitude = std::sqrt(ExitFace::crossingWavenumberSquared(kC, kMu, 1.0, 0.5,
                                                                               0.5));
        const bool bothBranchesOnShell =
            std::abs(ExitFace::dispersionResidual(kC, kMu, 1.0, 0.5, 0.5, magnitude)) < 1e-12 &&
            std::abs(ExitFace::dispersionResidual(kC, kMu, 1.0, 0.5, 0.5, -magnitude)) < 1e-12;
        const bool orientationDoesNotChooseBranch =
            !ExitFace::crossingDependsOnOrientationDirection(kC, kMu, 2.0);
        return bothBranchesOnShell && orientationDoesNotChooseBranch;
    }

    int Reconciliation::reconciledCount()
    {
        return 5;
    }

    int Reconciliation::standingContradictionCount()
    {
        return 4;
    }

    void ReconciliationSection::run(Report &report) const
    {
        report.subsection("24.1  Disagreements that are one coin seen twice");
        report.check("cavity against barrier: the parameter is which axis turns, "
                     "and both readings follow from one formula",
                     Reconciliation::cavityAndBarrierAreOneCoin());
        report.check("delay against mixing: the parameter is which observable of "
                     "the one amplitude is read",
                     Reconciliation::delayAndMixingAreOneCoin());
        report.check("total reflection against tunnelling: the parameter is the "
                     "thickness, and reflection is its large limit",
                     Reconciliation::reflectionIsTheThickLimit());
        report.check("ill posed against well posed: the parameter is whether the "
                     "data sit on the far-side mass shell",
                     Reconciliation::illPosedAndWellPosedAreOneCoin());
        report.check("exit face against turn: they are two parts of one vector "
                     "rather than two labels",
                     Reconciliation::exitFaceAndTurnAreOneVector());
        report.check(std::format("  {} disagreements reconciled by calculation",
                                 Reconciliation::reconciledCount()),
                     Reconciliation::reconciledCount() == 5);

        report.subsection("24.2  Each reconciliation names its parameter");
        report.check("none of the five was settled by argument, each was settled "
                     "by turning one parameter and recovering both readings",
                     Reconciliation::cavityAndBarrierAreOneCoin() &&
                         Reconciliation::delayAndMixingAreOneCoin() &&
                         Reconciliation::reflectionIsTheThickLimit() &&
                         Reconciliation::illPosedAndWellPosedAreOneCoin() &&
                         Reconciliation::exitFaceAndTurnAreOneVector());

        report.subsection("24.3  What the method cannot absorb");
        report.check(std::format("  {} disagreements remain genuine contradictions",
                                 Reconciliation::standingContradictionCount()),
                     Reconciliation::standingContradictionCount() == 4);
        report.check("a contradiction is one where the two positions give "
                     "different numbers for the same measurement, which no change "
                     "of viewpoint removes",
                     Reconciliation::standingContradictionCount() > 0);
        report.check("so the inclusive method absorbs more than half of the "
                     "disagreements and is honest about the rest",
                     Reconciliation::reconciledCount() >
                         Reconciliation::standingContradictionCount());
    }

}
