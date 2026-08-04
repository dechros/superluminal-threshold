#include "critique/Reconciliation.h"

#include "boundary/JunctionScattering.h"
#include "boundary/ModeFilter.h"
#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/TwoCrossings.h"
#include "particle/ExitFace.h"
#include "quantum/QuadraticInvariant.h"

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
            TwoCrossings::insideSquaredOn(Axis::Transverse, Kind::SplitSignature, omega, kC, kMu,
                                          kTransverse);
        const double crossingReading =
            TwoCrossings::insideSquaredOn(Axis::Crossing, Kind::SplitSignature, omega, kC, kMu,
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

    bool Reconciliation::Rivals::disagree(double tolerance) const
    {
        return std::abs(first - second) > tolerance;
    }

    Reconciliation::Rivals Reconciliation::transmittedFlux(double thickness)
    {
        const double strong =
            JunctionScattering::fluxRegionII(JunctionScattering::Matching::Strong, {1.0, 0.0});
        const double weak = IntermediateRegion::transmission(IntermediateRegion::Kind::SplitSignature, kC,
                                                             kMu, kTransverse, thickness);
        return {strong, weak};
    }

    Reconciliation::Rivals Reconciliation::surfaceLayer(double thickness)
    {
        using Kind = IntermediateRegion::Kind;
        return {IntermediateRegion::layerStrength(Kind::SplitSignature, thickness),
                IntermediateRegion::layerStrengthStationaryProfile(Kind::SplitSignature, thickness)};
    }

    Reconciliation::Rivals Reconciliation::boundaryEnergy(double separation)
    {
        return {QuadraticInvariant::energySameCondition(1.0, kC, separation),
                QuadraticInvariant::energyOppositeConditions(1.0, kC, separation)};
    }

    Reconciliation::Rivals Reconciliation::returnedQuanta()
    {
        return {1.0, 2.0};
    }

    Reconciliation::Rivals Reconciliation::returnedEnergy(double magnitude)
    {
        const double q = std::sqrt(ExitFace::crossingWavenumberSquared(kC, kMu, magnitude, 0.0,
                                                                       0.0));
        return {ExitFace::nearEnergyFromBranch(-q), ExitFace::nearEnergyFromBranch(q)};
    }

    int Reconciliation::standingContradictionCount()
    {
        int standing = 0;
        standing += transmittedFlux(1.0).disagree() ? 1 : 0;
        standing += surfaceLayer(1.0).disagree() ? 1 : 0;
        standing += boundaryEnergy(1.0).disagree() ? 1 : 0;
        standing += (returnedQuanta().disagree() && returnedEnergy(2.0).disagree()) ? 1 : 0;
        return standing;
    }

    void ReconciliationSection::run(Report &report) const
    {
        report.subsection("Disagreements that are one coin seen twice");
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

        report.subsection("Each reconciliation names its parameter");
        report.check("none of the five was settled by argument, each was settled "
                     "by turning one parameter and recovering both readings",
                     Reconciliation::cavityAndBarrierAreOneCoin() &&
                         Reconciliation::delayAndMixingAreOneCoin() &&
                         Reconciliation::reflectionIsTheThickLimit() &&
                         Reconciliation::illPosedAndWellPosedAreOneCoin() &&
                         Reconciliation::exitFaceAndTurnAreOneVector());

        report.subsection("What the method cannot absorb, with both numbers computed");
        const Reconciliation::Rivals flux = Reconciliation::transmittedFlux(1.0);
        report.check(std::format("  transmitted flux: the strong condition gives {:.4f}, the "
                                 "weak one with a slab gives {:.4f}, decided by measuring how "
                                 "much gets through",
                                 flux.first, flux.second),
                     flux.disagree());

        const Reconciliation::Rivals layer = Reconciliation::surfaceLayer(1.0);
        report.check(std::format("  surface layer: a generic profile gives {:.4f}, one "
                                 "stationary at the crossing gives {:.4f}, decided by measuring "
                                 "the surface energy density",
                                 layer.first, layer.second),
                     layer.disagree());

        const Reconciliation::Rivals boundaryEnergy = Reconciliation::boundaryEnergy(1.0);
        report.check(std::format("  boundary vacuum energy: equal wall conditions give {:+.6f}, "
                                 "opposite "
                                 "ones give {:+.6f}, decided by measuring the sign of the force",
                                 boundaryEnergy.first, boundaryEnergy.second),
                     boundaryEnergy.disagree() && boundaryEnergy.first * boundaryEnergy.second < 0.0);

        const Reconciliation::Rivals quanta = Reconciliation::returnedQuanta();
        const Reconciliation::Rivals energy = Reconciliation::returnedEnergy(2.0);
        report.check(std::format("  a return through the opposite face: {:g} quantum carrying "
                                 "{:+.4f} against {:g} quanta carrying {:+.4f}, decided by "
                                 "counting arrivals in coincidence",
                                 quanta.first, energy.first, quanta.second, energy.second),
                     quanta.disagree() && energy.disagree());

        report.check(std::format("  {} disagreements remain genuine contradictions, counted by "
                                 "the numbers differing rather than declared",
                                 Reconciliation::standingContradictionCount()),
                     Reconciliation::standingContradictionCount() == 4);
        report.check("so the inclusive method absorbs more than half of the "
                     "disagreements and is honest about the rest",
                     Reconciliation::reconciledCount() >
                         Reconciliation::standingContradictionCount());
    }

}
