#include "admission/CrossingAdmission.h"
#include "boundary/JunctionFamily.h"
#include "boundary/JunctionScattering.h"
#include "boundary/SlabTunnelling.h"
#include "charge/ChargedRoundTrip.h"
#include "boundary/ProfiledBarrier.h"
#include "intermediate/ThresholdOptimum.h"
#include "particle/AsymmetricFaces.h"
#include "particle/BoundPair.h"
#include "scan/PermutationScan.h"
#include "core/Report.h"
#include "core/Section.h"
#include "critique/ArticleSync.h"
#include "critique/CitationCoverage.h"
#include "critique/ProseRegister.h"
#include "dynamics/Dispersion.h"
#include "field/TimeOrientation.h"
#include "identity/RoundTripInvariants.h"
#include "horizon/SurfaceLayer.h"
#include "intermediate/DwellTime.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/TraversalClocks.h"
#include "intermediate/TwoCrossings.h"
#include "particle/DirectionControl.h"
#include "particle/ExitFace.h"
#include "particle/FarSideMotion.h"
#include "particle/ReturnEvent.h"
#include "particle/ReturnFormula.h"
#include "particle/RigidMolecule.h"
#include "particle/RoundTrip.h"
#include "particle/TimeProjection.h"
#include "particle/WavePacket.h"
#include "particle/WorkedRoundTrip.h"
#include "routes/ThreeRoutes.h"
#include "sim/PacketSimulation.h"
#include "critique/AssumptionLedger.h"
#include "transform/SignatureInvolution.h"
#include "transform/SpinRepresentation.h"
#include "units/PhysicalScales.h"
#include "experiment/RoundTripExperiment.h"
#include "units/AtomJourney.h"
#include "units/ProtonJourney.h"
#include "units/SignatureThreshold.h"
#include "units/ThresholdScaling.h"

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

namespace
{
    std::vector<std::unique_ptr<slm::Section>> buildSections()
    {
        std::vector<std::unique_ptr<slm::Section>> sections;
        sections.push_back(std::make_unique<slm::SignatureInvolution>());
        sections.push_back(std::make_unique<slm::SpinRepresentation>());
        sections.push_back(std::make_unique<slm::IntermediateRegionSection>());
        sections.push_back(std::make_unique<slm::PermutationScan>());
        sections.push_back(std::make_unique<slm::ProfiledBarrierSection>());
        sections.push_back(std::make_unique<slm::ThresholdOptimumSection>());
        sections.push_back(std::make_unique<slm::AsymmetricFacesSection>());
        sections.push_back(std::make_unique<slm::JunctionScattering>());
        sections.push_back(std::make_unique<slm::JunctionFamilySection>());
        sections.push_back(std::make_unique<slm::SurfaceLayerSection>());
        sections.push_back(std::make_unique<slm::SlabTunnellingSection>());
        sections.push_back(std::make_unique<slm::TimeOrientationSection>());
        sections.push_back(std::make_unique<slm::DispersionSection>());
        sections.push_back(std::make_unique<slm::AssumptionLedgerSection>());
        sections.push_back(std::make_unique<slm::ProseRegisterSection>());
        sections.push_back(std::make_unique<slm::ArticleSyncSection>());
        sections.push_back(std::make_unique<slm::CitationCoverageSection>());
        sections.push_back(std::make_unique<slm::WavePacketSection>());
        sections.push_back(std::make_unique<slm::TwoCrossingsSection>());
        sections.push_back(std::make_unique<slm::DwellTimeSection>());
        sections.push_back(std::make_unique<slm::TraversalClocksSection>());
        sections.push_back(std::make_unique<slm::RoundTripSection>());
        sections.push_back(std::make_unique<slm::ExitFaceSection>());
        sections.push_back(std::make_unique<slm::FarSideMotionSection>());
        sections.push_back(std::make_unique<slm::DirectionControlSection>());
        sections.push_back(std::make_unique<slm::WorkedRoundTripSection>());
        sections.push_back(std::make_unique<slm::PacketSimulationSection>());
        sections.push_back(std::make_unique<slm::RoundTripInvariantsSection>());
        sections.push_back(std::make_unique<slm::ThreeRoutesSection>());
        sections.push_back(std::make_unique<slm::ChargedRoundTripSection>());
        sections.push_back(std::make_unique<slm::CrossingAdmissionSection>());
        sections.push_back(std::make_unique<slm::PhysicalScalesSection>());
        sections.push_back(std::make_unique<slm::ProtonJourneySection>());
        sections.push_back(std::make_unique<slm::AtomJourneySection>());
        sections.push_back(std::make_unique<slm::SignatureThresholdSection>());
        sections.push_back(std::make_unique<slm::ThresholdScalingSection>());
        sections.push_back(std::make_unique<slm::RoundTripExperimentSection>());
        sections.push_back(std::make_unique<slm::TimeProjectionSection>());
        sections.push_back(std::make_unique<slm::ReturnEventSection>());
        sections.push_back(std::make_unique<slm::BoundPairSection>());
        sections.push_back(std::make_unique<slm::RigidMoleculeSection>());
        sections.push_back(std::make_unique<slm::ReturnFormulaSection>());
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
