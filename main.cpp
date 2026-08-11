#include "particle/AcceleratedCrossing.h"
#include "particle/ContinuousCrossing.h"
#include "particle/PairedExcursion.h"
#include "scan/DirectionFamily.h"
#include "scan/HandednessSelection.h"
#include "scan/PermutationScan.h"
#include "core/Report.h"
#include "core/Section.h"
#include "dynamics/Dispersion.h"
#include "dynamics/ThresholdField.h"
#include "intermediate/DegenerateWindow.h"
#include "intermediate/IntermediateRegion.h"
#include "mechanism/ThresholdWall.h"
#include "particle/TimeProjection.h"
#include "particle/VelocityCrossing.h"
#include "transform/RelabellingObstruction.h"
#include "transform/SignatureInvolution.h"
#include "units/PhysicalScales.h"

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
        sections.push_back(std::make_unique<slm::RelabellingObstructionSection>());
        sections.push_back(std::make_unique<slm::IntermediateRegionSection>());
        sections.push_back(std::make_unique<slm::PermutationScan>());
        sections.push_back(std::make_unique<slm::DirectionFamily>());
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
