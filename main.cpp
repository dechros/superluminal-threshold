#include "boundary/CausalCrossing.h"
#include "boundary/JunctionScattering.h"
#include "boundary/ModeFilter.h"
#include "boundary/ProfiledBarrier.h"
#include "boundary/SlabTunnelling.h"
#include "boundary/ThresholdSurface.h"
#include "core/Report.h"
#include "core/Section.h"
#include "critique/AlternativeRoutes.h"
#include "critique/CommonFormulas.h"
#include "critique/LiteratureObjections.h"
#include "critique/ObjectionTests.h"
#include "critique/OpenQuestions.h"
#include "critique/Reconciliation.h"
#include "critique/ReproductionLedger.h"
#include "critique/SylvesterObstruction.h"
#include "dynamics/Dispersion.h"
#include "dynamics/EnergyMomentum.h"
#include "field/DynamicsUnderReversal.h"
#include "field/KleinGordonField.h"
#include "field/MaxwellField.h"
#include "field/ReversalSymmetry.h"
#include "field/TimeOrientation.h"
#include "horizon/BlackHoleHorizon.h"
#include "horizon/DegeneratePath.h"
#include "horizon/LayerEnergyConditions.h"
#include "horizon/RateCondition.h"
#include "horizon/TransversePrescription.h"
#include "horizon/SurfaceLayer.h"
#include "intermediate/ChannelEntropy.h"
#include "intermediate/DwellTime.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/SignalFront.h"
#include "intermediate/ThresholdOptimum.h"
#include "intermediate/TraversalClocks.h"
#include "intermediate/TwoCrossings.h"
#include "transform/ExtendedLorentzGroup.h"
#include "particle/ArrivalOrder.h"
#include "particle/AsymmetricFaces.h"
#include "particle/CellDistribution.h"
#include "particle/DirectionControl.h"
#include "particle/EnergyBookkeeping.h"
#include "particle/ExitFace.h"
#include "particle/FarSideMotion.h"
#include "particle/FarSideObservation.h"
#include "particle/Feasibility.h"
#include "particle/FlowAssumption.h"
#include "particle/StateTable.h"
#include "particle/LoopClosure.h"
#include "particle/ReturnEvent.h"
#include "particle/ReturnFormula.h"
#include "particle/RoundTrip.h"
#include "particle/TimeHolonomy.h"
#include "particle/TimeProjection.h"
#include "particle/TimeReversalSignature.h"
#include "particle/WavePacket.h"
#include "particle/WorkedRoundTrip.h"
#include "quantum/CanonicalQuantization.h"
#include "quantum/CasimirDiscriminant.h"
#include "quantum/DerivedTransition.h"
#include "quantum/LapseContour.h"
#include "quantum/PathIntegral.h"
#include "quantum/VacuumCasimir.h"
#include "rest/SuperluminalRest.h"
#include "scan/BranchObservables.h"
#include "scan/CrossingBranches.h"
#include "scan/PermutationScan.h"
#include "scan/SlotDictionary.h"
#include "signal/Channels.h"
#include "critique/AssumptionLedger.h"
#include "dynamics/ConjugateDictionary.h"
#include "particle/RouteHolonomy.h"
#include "particle/TimeShiftCost.h"
#include "signal/GravitationalChannel.h"
#include "spherical/SphericalSolution.h"
#include "transform/InvolutionD.h"

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

namespace
{
    std::vector<std::unique_ptr<slm::Section>> buildSections()
    {
        std::vector<std::unique_ptr<slm::Section>> sections;
        sections.push_back(std::make_unique<slm::InvolutionD>());
        sections.push_back(std::make_unique<slm::PermutationScan>());
        sections.push_back(std::make_unique<slm::CrossingBranchesSection>());
        sections.push_back(std::make_unique<slm::BranchObservablesSection>());
        sections.push_back(std::make_unique<slm::SlotDictionarySection>());
        sections.push_back(std::make_unique<slm::IntermediateRegionSection>());
        sections.push_back(std::make_unique<slm::ThresholdSurface>());
        sections.push_back(std::make_unique<slm::JunctionScattering>());
        sections.push_back(std::make_unique<slm::SurfaceLayerSection>());
        sections.push_back(std::make_unique<slm::LayerEnergyConditionsSection>());
        sections.push_back(std::make_unique<slm::RateConditionSection>());
        sections.push_back(std::make_unique<slm::TransversePrescriptionSection>());
        sections.push_back(std::make_unique<slm::CausalCrossingSection>());
        sections.push_back(std::make_unique<slm::SlabTunnellingSection>());
        sections.push_back(std::make_unique<slm::ProfiledBarrierSection>());
        sections.push_back(std::make_unique<slm::DegeneratePathSection>());
        sections.push_back(std::make_unique<slm::BlackHoleHorizon>());
        sections.push_back(std::make_unique<slm::KleinGordonField>());
        sections.push_back(std::make_unique<slm::EnergyMomentum>());
        sections.push_back(std::make_unique<slm::TimeOrientationSection>());
        sections.push_back(std::make_unique<slm::ReversalSymmetrySection>());
        sections.push_back(std::make_unique<slm::DynamicsUnderReversalSection>());
        sections.push_back(std::make_unique<slm::SuperluminalRest>());
        sections.push_back(std::make_unique<slm::DispersionSection>());
        sections.push_back(std::make_unique<slm::ConjugateDictionarySection>());
        sections.push_back(std::make_unique<slm::RouteHolonomySection>());
        sections.push_back(std::make_unique<slm::TimeShiftCostSection>());
        sections.push_back(std::make_unique<slm::AssumptionLedgerSection>());
        sections.push_back(std::make_unique<slm::SphericalSolution>());
        sections.push_back(std::make_unique<slm::CanonicalQuantization>());
        sections.push_back(std::make_unique<slm::PathIntegral>());
        sections.push_back(std::make_unique<slm::LapseContourSection>());
        sections.push_back(std::make_unique<slm::DerivedTransitionSection>());
        sections.push_back(std::make_unique<slm::VacuumCasimir>());
        sections.push_back(std::make_unique<slm::CasimirDiscriminantSection>());
        sections.push_back(std::make_unique<slm::WavePacketSection>());
        sections.push_back(std::make_unique<slm::ModeFilterSection>());
        sections.push_back(std::make_unique<slm::TwoCrossingsSection>());
        sections.push_back(std::make_unique<slm::DwellTimeSection>());
        sections.push_back(std::make_unique<slm::ChannelEntropySection>());
        sections.push_back(std::make_unique<slm::TraversalClocksSection>());
        sections.push_back(std::make_unique<slm::ThresholdOptimumSection>());
        sections.push_back(std::make_unique<slm::SignalFrontSection>());
        sections.push_back(std::make_unique<slm::RoundTripSection>());
        sections.push_back(std::make_unique<slm::EnergyBookkeepingSection>());
        sections.push_back(std::make_unique<slm::StateTableSection>());
        sections.push_back(std::make_unique<slm::ExitFaceSection>());
        sections.push_back(std::make_unique<slm::CellDistributionSection>());
        sections.push_back(std::make_unique<slm::AsymmetricFacesSection>());
        sections.push_back(std::make_unique<slm::ExtendedLorentzGroup>());
        sections.push_back(std::make_unique<slm::ChannelsSection>());
        sections.push_back(std::make_unique<slm::GravitationalChannelSection>());
        sections.push_back(std::make_unique<slm::MaxwellSection>());
        sections.push_back(std::make_unique<slm::SylvesterObstruction>());
        sections.push_back(std::make_unique<slm::ObjectionTestsSection>());
        sections.push_back(std::make_unique<slm::LiteratureObjectionsSection>());
        sections.push_back(std::make_unique<slm::AlternativeRoutesSection>());
        sections.push_back(std::make_unique<slm::CommonFormulasSection>());
        sections.push_back(std::make_unique<slm::ReconciliationSection>());
        sections.push_back(std::make_unique<slm::OpenQuestionsSection>());
        sections.push_back(std::make_unique<slm::ReproductionLedgerSection>());
        sections.push_back(std::make_unique<slm::FarSideMotionSection>());
        sections.push_back(std::make_unique<slm::DirectionControlSection>());
        sections.push_back(std::make_unique<slm::FarSideObservationSection>());
        sections.push_back(std::make_unique<slm::WorkedRoundTripSection>());
        sections.push_back(std::make_unique<slm::FeasibilitySection>());
        sections.push_back(std::make_unique<slm::TimeProjectionSection>());
        sections.push_back(std::make_unique<slm::FlowAssumptionSection>());
        sections.push_back(std::make_unique<slm::TimeReversalSignatureSection>());
        sections.push_back(std::make_unique<slm::TimeHolonomySection>());
        sections.push_back(std::make_unique<slm::ReturnEventSection>());
        sections.push_back(std::make_unique<slm::ReturnFormulaSection>());
        sections.push_back(std::make_unique<slm::ArrivalOrderSection>());
        sections.push_back(std::make_unique<slm::LoopClosureSection>());
        return sections;
    }

    void printBanner()
    {
        std::cout << "\n";
        std::cout << "################################################################\n";
        std::cout << "#                                                              #\n";
        std::cout << "#   SIGNATURE CHANGE LIBRARIES: TEST SUITE                     #\n";
        std::cout << "#                                                              #\n";
        std::cout << "################################################################\n";
    }
}

int main()
{
    try
    {
        printBanner();

        slm::Report report;
        const auto sections = buildSections();

        for (const auto &section : sections)
        {
            report.section(section->title());
            section->run(report);
        }

        report.summary();
        return report.allPassed() ? 0 : 1;
    }
    catch (const std::exception &error)
    {
        std::cerr << "\nERROR: " << error.what() << "\n";
        return 2;
    }
}
