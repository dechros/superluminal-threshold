#include "charge/ChargedCurrent.h"
#include "particle/AcceleratedCrossing.h"
#include "particle/AsymmetricFaces.h"
#include "scan/DirectionFamily.h"
#include "scan/PermutationScan.h"
#include "core/Report.h"
#include "core/Section.h"
#include "dynamics/Dispersion.h"
#include "field/TimeOrientation.h"
#include "intermediate/IntermediateRegion.h"
#include "particle/ExitFace.h"
#include "particle/TimeProjection.h"
#include "transform/SignatureInvolution.h"
#include "transform/SpinRepresentation.h"
#include "units/PhysicalScales.h"

#include <exception>
#include <fstream>
#include <iomanip>
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
        sections.push_back(std::make_unique<slm::DirectionFamily>());
        sections.push_back(std::make_unique<slm::AsymmetricFacesSection>());
        sections.push_back(std::make_unique<slm::TimeOrientationSection>());
        sections.push_back(std::make_unique<slm::DispersionSection>());
        sections.push_back(std::make_unique<slm::ExitFaceSection>());
        sections.push_back(std::make_unique<slm::ChargedCurrentSection>());
        sections.push_back(std::make_unique<slm::PhysicalScalesSection>());
        sections.push_back(std::make_unique<slm::TimeProjectionSection>());
        sections.push_back(std::make_unique<slm::AcceleratedCrossingSection>());
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

    /// Writes the numbers the article quotes from a calculation, so the
    /// Python-side article checks (tools/check_article.py) can hold the
    /// text to them without duplicating the formula that produces them.
    /// This is the one bridge between the two halves of the test suite: the
    /// article-analysis half asks only "does the text still agree with
    /// this file", never "how was this file's number computed".
    void writeQuotations()
    {
        std::ofstream out("build/quotations.json");
        out << std::setprecision(17);
        out << "{\n";
        out << "  \"the light-year distance a year of advance costs\": "
            << slm::PhysicalScales::distanceForAdvance(3.155695e7) << ",\n";
        out << "  \"the nanoseconds a metre of far-side travel buys\": "
            << slm::PhysicalScales::advanceForDistance(1.0) * 1e9 << "\n";
        out << "}\n";
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
        writeQuotations();
        return report.allPassed() ? 0 : 1;
    }
    catch (const std::exception &error)
    {
        std::cerr << "\nERROR: " << error.what() << "\n";
        return 2;
    }
}
