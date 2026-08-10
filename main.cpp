#include "charge/ChargedCurrent.h"
#include "particle/AsymmetricFaces.h"
#include "scan/PermutationScan.h"
#include "core/Report.h"
#include "core/Section.h"
#include "critique/ArticleSync.h"
#include "critique/CitationCoverage.h"
#include "critique/ProseRegister.h"
#include "dynamics/Dispersion.h"
#include "field/TimeOrientation.h"
#include "intermediate/IntermediateRegion.h"
#include "particle/ExitFace.h"
#include "particle/TimeProjection.h"
#include "critique/AssumptionLedger.h"
#include "transform/SignatureInvolution.h"
#include "transform/SpinRepresentation.h"
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
        sections.push_back(std::make_unique<slm::SpinRepresentation>());
        sections.push_back(std::make_unique<slm::IntermediateRegionSection>());
        sections.push_back(std::make_unique<slm::PermutationScan>());
        sections.push_back(std::make_unique<slm::AsymmetricFacesSection>());
        sections.push_back(std::make_unique<slm::TimeOrientationSection>());
        sections.push_back(std::make_unique<slm::DispersionSection>());
        sections.push_back(std::make_unique<slm::AssumptionLedgerSection>());
        sections.push_back(std::make_unique<slm::ProseRegisterSection>());
        sections.push_back(std::make_unique<slm::ArticleSyncSection>());
        sections.push_back(std::make_unique<slm::CitationCoverageSection>());
        sections.push_back(std::make_unique<slm::ExitFaceSection>());
        sections.push_back(std::make_unique<slm::ChargedCurrentSection>());
        sections.push_back(std::make_unique<slm::PhysicalScalesSection>());
        sections.push_back(std::make_unique<slm::TimeProjectionSection>());
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
