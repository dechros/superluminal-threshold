// ============================================================================
//  Superluminal geciste imza degisimi: ayrik involusyon modeli
// ----------------------------------------------------------------------------
//  Bu program, modelin butun cebirsel ve sayisal iddialarini ard arda
//  calistirir ve her birini GECTI / KALDI olarak raporlar.
//
//  Modelin ozeti (calisma notu §10):
//    1. c asilirsa uzay ve zaman rol degistirir; ani, hizdan bagimsiz
//    2. Bunu yapan tek donusum D; involusyon, parite korur, isik hizi korur
//    3. Otede hiz skaler degil, yonelim
//    4. Enerji ve momentum takas olur
//    5. v' = c^2/v
//    6. Otede ongoru coker (denklem tipi geregi)
//    7. Esik gecirgen degil, yansitici
//
//  Bolumlerin kaynagi ve turetimleri, ilgili siniflarin baslik dosyalarinda
//  yorum olarak tutulur. Her sinif calisma notunun bir bolumune karsilik gelir.
//
//  YONTEM NOTU (§13)
//  Tum dogrulamalar once sympy ile SEMBOLIK olarak yapilmisti:
//    - Matris ozellikleri: metrik, involusyon, determinant, grup mertebesi
//    - 384 permutasyon taramasi
//    - Dort-momentum donusumu ve genel 2->2 korunum
//    - Euler-Lagrange turetmeleri
//    - O(3) stabilizator hesabi
//    - Dispersiyon ve limit hesaplari
//  Elle yapilan iki hesap (parite argumani, boyut sayimi) sembolik kontrolde
//  YANLIS CIKTI ve duzeltildi. Modelin bugunku hali bu duzeltmeleri icerir.
//
//  Burada ayni dogrulamalar C++ ile sayisal/cebirsel olarak yeniden kuruldu.
//  Matrislerin buyuk kismi tamsayi girdilidir ve cift duyarlikta tam temsil
//  edilir, dolayisiyla permutasyon, involusyon ve determinant testleri
//  sembolik hesapla birebir ayni sonucu verir.
// ============================================================================

#include "boundary/ThresholdSurface.h"
#include "core/Report.h"
#include "core/Section.h"
#include "critique/DirectionDependentD.h"
#include "critique/SylvesterObstruction.h"
#include "dynamics/Dispersion.h"
#include "dynamics/EnergyMomentum.h"
#include "field/KleinGordonField.h"
#include "field/MaxwellField.h"
#include "horizon/BlackHoleHorizon.h"
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
        sections.push_back(std::make_unique<slm::SuperluminalRest>());
        sections.push_back(std::make_unique<slm::ThresholdSurface>());
        sections.push_back(std::make_unique<slm::SphericalSolution>());
        sections.push_back(std::make_unique<slm::MaxwellSection>());
        sections.push_back(std::make_unique<slm::BlackHoleHorizon>());
        sections.push_back(std::make_unique<slm::CanonicalQuantization>());
        sections.push_back(std::make_unique<slm::PathIntegral>());
        sections.push_back(std::make_unique<slm::VacuumCasimir>());
        sections.push_back(std::make_unique<slm::SylvesterObstruction>());
        sections.push_back(std::make_unique<slm::DirectionDependentD>());
        sections.push_back(std::make_unique<slm::LiteraturePosition>());
        return sections;
    }

    void printBanner()
    {
        std::cout << "\n";
        std::cout << "################################################################\n";
        std::cout << "#                                                              #\n";
        std::cout << "#   SUPERLUMINAL GECISTE IMZA DEGISIMI                         #\n";
        std::cout << "#   Ayrik involusyon modeli — butun hesaplarin dogrulanmasi     #\n";
        std::cout << "#                                                              #\n";
        std::cout << "################################################################\n";
    }

    void printModelSummary()
    {
        std::cout << "\n  MODELIN OZETI\n";
        std::cout << "  1. c asilirsa uzay ve zaman rol degistirir; ani, hizdan bagimsiz\n";
        std::cout << "  2. Bunu yapan tek donusum D; involusyon, parite korur, c'yi korur\n";
        std::cout << "  3. Otede hiz skaler degil, yonelim\n";
        std::cout << "  4. Enerji ve momentum takas olur\n";
        std::cout << "  5. v' = c^2/v\n";
        std::cout << "  6. Otede ongoru coker (denklem tipi geregi)\n";
        std::cout << "  7. Esik gecirgen degil, yansitici\n";
    }

} // namespace

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
        std::cerr << "\nHATA: " << error.what() << "\n";
        return 2;
    }
}
