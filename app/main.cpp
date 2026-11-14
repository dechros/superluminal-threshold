#include "core/Report.h"
#include "core/Section.h"
#include "journey/CrossingMethodsSection.h"
#include "journey/JourneyStateSection.h"
#include "journey/RoundTripSection.h"
#include "particle/AcceleratedCrossingSection.h"
#include "particle/ContinuousCrossingSection.h"
#include "particle/PairedExcursionSection.h"
#include "particle/TimeProjectionSection.h"
#include "particle/VelocityCrossingSection.h"
#include "physics/dynamics/DispersionSection.h"
#include "physics/dynamics/ThresholdFieldSection.h"
#include "physics/intermediate/DegenerateWindowSection.h"
#include "physics/intermediate/IntermediateRegionSection.h"
#include "physics/mechanism/ThresholdWallSection.h"
#include "physics/scan/DirectionFamilySection.h"
#include "physics/scan/HandednessSelectionSection.h"
#include "physics/scan/PermutationScanSection.h"
#include "physics/transform/RelabellingObstructionSection.h"
#include "physics/transform/SignatureInvolutionSection.h"
#include "physics/units/PhysicalScalesSection.h"

#include <exception>
#include <print>
#include <memory>
#include <vector>

namespace
{
    std::vector<std::unique_ptr<slm::Section>> buildSections()
    {
        std::vector<std::unique_ptr<slm::Section>> sections;
        sections.push_back(std::make_unique<slm::SignatureInvolutionSection>());
        sections.push_back(std::make_unique<slm::RelabellingObstructionSection>());
        sections.push_back(std::make_unique<slm::IntermediateRegionSection>());
        sections.push_back(std::make_unique<slm::PermutationScanSection>());
        sections.push_back(std::make_unique<slm::DirectionFamilySection>());
        sections.push_back(std::make_unique<slm::HandednessSelectionSection>());
        sections.push_back(std::make_unique<slm::ThresholdFieldSection>());
        sections.push_back(std::make_unique<slm::VelocityCrossingSection>());
        sections.push_back(std::make_unique<slm::ThresholdWallSection>());
        sections.push_back(std::make_unique<slm::DegenerateWindowSection>());
        sections.push_back(std::make_unique<slm::ContinuousCrossingSection>());
        sections.push_back(std::make_unique<slm::DispersionSection>());
        sections.push_back(std::make_unique<slm::PhysicalScalesSection>());
        sections.push_back(std::make_unique<slm::TimeProjectionSection>());
        sections.push_back(std::make_unique<slm::AcceleratedCrossingSection>());
        sections.push_back(std::make_unique<slm::PairedExcursionSection>());
        sections.push_back(std::make_unique<slm::CrossingMethodsSection>());
        sections.push_back(std::make_unique<slm::RoundTripSection>());
        sections.push_back(std::make_unique<slm::JourneyStateSection>());
        return sections;
    }

    void printBanner()
    {
        std::println("");
        std::println("################################################################");
        std::println("#                                                              #");
        std::println("#   SIGNATURE CHANGE LIBRARIES: TEST SUITE                     #");
        std::println("#                                                              #");
        std::println("################################################################");
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
        std::println(stderr, "\nERROR: {}", error.what());
        return 2;
    }
}
