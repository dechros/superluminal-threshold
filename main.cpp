#include "boundary/CausalCrossing.h"
#include "boundary/JunctionScattering.h"
#include "boundary/ModeFilter.h"
#include "boundary/SlabTunnelling.h"
#include "boundary/ThresholdSurface.h"
#include "core/Report.h"
#include "core/Section.h"
#include "critique/AlternativeRoutes.h"
#include "critique/ObjectionTests.h"
#include "critique/Reconciliation.h"
#include "critique/SylvesterObstruction.h"
#include "dynamics/Dispersion.h"
#include "dynamics/EnergyMomentum.h"
#include "field/KleinGordonField.h"
#include "field/MaxwellField.h"
#include "field/TimeOrientation.h"
#include "horizon/BlackHoleHorizon.h"
#include "horizon/DegeneratePath.h"
#include "horizon/SurfaceLayer.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/TwoCrossings.h"
#include "literature/LiteraturePosition.h"
#include "particle/AsymmetricFaces.h"
#include "particle/CellDistribution.h"
#include "particle/EnergyBookkeeping.h"
#include "particle/ExitFace.h"
#include "particle/FarSideMotion.h"
#include "particle/StateTable.h"
#include "particle/RoundTrip.h"
#include "particle/WavePacket.h"
#include "quantum/CanonicalQuantization.h"
#include "quantum/CasimirDiscriminant.h"
#include "quantum/DerivedTransition.h"
#include "quantum/PathIntegral.h"
#include "quantum/VacuumCasimir.h"
#include "rest/SuperluminalRest.h"
#include "scan/PermutationScan.h"
#include "signal/Channels.h"
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
        sections.push_back(std::make_unique<slm::IntermediateRegionSection>());
        sections.push_back(std::make_unique<slm::ThresholdSurface>());
        sections.push_back(std::make_unique<slm::JunctionScattering>());
        sections.push_back(std::make_unique<slm::SurfaceLayerSection>());
        sections.push_back(std::make_unique<slm::CausalCrossingSection>());
        sections.push_back(std::make_unique<slm::SlabTunnellingSection>());
        sections.push_back(std::make_unique<slm::DegeneratePathSection>());
        sections.push_back(std::make_unique<slm::BlackHoleHorizon>());
        sections.push_back(std::make_unique<slm::KleinGordonField>());
        sections.push_back(std::make_unique<slm::EnergyMomentum>());
        sections.push_back(std::make_unique<slm::TimeOrientationSection>());
        sections.push_back(std::make_unique<slm::SuperluminalRest>());
        sections.push_back(std::make_unique<slm::DispersionSection>());
        sections.push_back(std::make_unique<slm::SphericalSolution>());
        sections.push_back(std::make_unique<slm::CanonicalQuantization>());
        sections.push_back(std::make_unique<slm::PathIntegral>());
        sections.push_back(std::make_unique<slm::DerivedTransitionSection>());
        sections.push_back(std::make_unique<slm::VacuumCasimir>());
        sections.push_back(std::make_unique<slm::CasimirDiscriminantSection>());
        sections.push_back(std::make_unique<slm::WavePacketSection>());
        sections.push_back(std::make_unique<slm::ModeFilterSection>());
        sections.push_back(std::make_unique<slm::TwoCrossingsSection>());
        sections.push_back(std::make_unique<slm::RoundTripSection>());
        sections.push_back(std::make_unique<slm::EnergyBookkeepingSection>());
        sections.push_back(std::make_unique<slm::StateTableSection>());
        sections.push_back(std::make_unique<slm::ExitFaceSection>());
        sections.push_back(std::make_unique<slm::CellDistributionSection>());
        sections.push_back(std::make_unique<slm::AsymmetricFacesSection>());
        sections.push_back(std::make_unique<slm::LiteraturePosition>());
        sections.push_back(std::make_unique<slm::ChannelsSection>());
        sections.push_back(std::make_unique<slm::GravitationalChannelSection>());
        sections.push_back(std::make_unique<slm::MaxwellSection>());
        sections.push_back(std::make_unique<slm::SylvesterObstruction>());
        sections.push_back(std::make_unique<slm::ObjectionTestsSection>());
        sections.push_back(std::make_unique<slm::AlternativeRoutesSection>());
        sections.push_back(std::make_unique<slm::ReconciliationSection>());
        sections.push_back(std::make_unique<slm::FarSideMotionSection>());
        return sections;
    }

    void printBanner()
    {
        std::cout << "\n";
        std::cout << "################################################################\n";
        std::cout << "#                                                              #\n";
        std::cout << "#   SIGNATURE CHANGE ACROSS A SUPERLUMINAL TRANSITION          #\n";
        std::cout << "#   Discrete involution model, verification of every claim     #\n";
        std::cout << "#                                                              #\n";
        std::cout << "################################################################\n";
    }

    void printModelSummary()
    {
        std::cout << "\n  MODEL SUMMARY\n";
        std::cout << "  1. Three regions: ours, the intermediate one, the far side\n";
        std::cout << "  2. Beyond c space and time swap roles; abrupt, speed independent\n";
        std::cout << "  3. The one transformation doing it is D; involutive, parity and c preserving\n";
        std::cout << "  4. On the far side speed is not a scalar but an orientation\n";
        std::cout << "  5. Energy and momentum swap, and v' = c^2/v\n";
        std::cout << "  6. The far side is ill posed in itself, but the part reachable by\n";
        std::cout << "     crossing is not: on its mass shell nothing arriving can grow\n";
        std::cout << "  7. The threshold transmits, under the weak junction condition, and\n";
        std::cout << "     the price is a matter layer going as one over the thickness\n";
        std::cout << "  8. The return moment is read off the phase, not off any duration\n";
        std::cout << "  9. A gauge rotation over there is a free deflection here, quantised\n";
    }
}

int main()
{
    try
    {
        printBanner();
        printModelSummary();

        slm::Report report;
        const auto sections = buildSections();

        for (const auto &section : sections)
        {
            report.section(section->number(), section->title());
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
