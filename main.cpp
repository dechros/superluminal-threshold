#include "boundary/JunctionScattering.h"
#include "boundary/ThresholdSurface.h"
#include "core/Report.h"
#include "core/Section.h"
#include "critique/DirectionDependentD.h"
#include "critique/SylvesterObstruction.h"
#include "dynamics/Dispersion.h"
#include "dynamics/EnergyMomentum.h"
#include "field/KleinGordonField.h"
#include "field/MaxwellField.h"
#include "field/TimeOrientation.h"
#include "horizon/BlackHoleHorizon.h"
#include "horizon/DegeneratePath.h"
#include "horizon/SurfaceLayer.h"
#include "literature/LiteraturePosition.h"
#include "quantum/CanonicalQuantization.h"
#include "quantum/PathIntegral.h"
#include "quantum/VacuumCasimir.h"
#include "rest/SuperluminalRest.h"
#include "scan/PermutationScan.h"
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
        sections.push_back(std::make_unique<slm::EnergyMomentum>());
        sections.push_back(std::make_unique<slm::DispersionSection>());
        sections.push_back(std::make_unique<slm::KleinGordonField>());
        sections.push_back(std::make_unique<slm::TimeOrientationSection>());
        sections.push_back(std::make_unique<slm::SuperluminalRest>());
        sections.push_back(std::make_unique<slm::ThresholdSurface>());
        sections.push_back(std::make_unique<slm::JunctionScattering>());
        sections.push_back(std::make_unique<slm::SurfaceLayerSection>());
        sections.push_back(std::make_unique<slm::SphericalSolution>());
        sections.push_back(std::make_unique<slm::MaxwellSection>());
        sections.push_back(std::make_unique<slm::LiteraturePosition>());
        sections.push_back(std::make_unique<slm::BlackHoleHorizon>());
        sections.push_back(std::make_unique<slm::DegeneratePathSection>());
        sections.push_back(std::make_unique<slm::CanonicalQuantization>());
        sections.push_back(std::make_unique<slm::PathIntegral>());
        sections.push_back(std::make_unique<slm::VacuumCasimir>());
        sections.push_back(std::make_unique<slm::SylvesterObstruction>());
        sections.push_back(std::make_unique<slm::DirectionDependentD>());
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
        std::cout << "  1. Beyond c space and time swap roles; abrupt, speed independent\n";
        std::cout << "  2. The one transformation doing it is D; involutive, parity and c preserving\n";
        std::cout << "  3. On the far side speed is not a scalar but an orientation\n";
        std::cout << "  4. Energy and momentum swap\n";
        std::cout << "  5. v' = c^2/v\n";
        std::cout << "  6. Prediction collapses there, forced by the equation type\n";
        std::cout << "  7. The threshold is reflecting, not transmitting\n";
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
