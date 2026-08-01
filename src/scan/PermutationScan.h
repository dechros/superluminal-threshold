#pragma once

// ============================================================================
//  PermutationScan — model.md §3 (tarama sonucu)
// ----------------------------------------------------------------------------
//  384 olasi isaretli permutasyon matrisi tarandi (4! permutasyon x 2^4 isaret):
//
//      Metrik testini gecen        : 96
//      + involusyon (M^2 = I)      : 12
//      + det = +1                  : 8
//
//  Sekiz cozumun TAMAMINDA ct -> tek uzay ekseni. Yani "bizim zamanimiz
//  onlarin uzayi olur" sonucu secim degil, ZORUNLULUK. Kalan 8 cozum
//  arasindaki fark uzay eksenlerinin etiketlenmesi — donme ile birbirine
//  geciyorlar, fiziksel icerik tasimiyorlar.
//
//  Metrik testi:  M^T eta' M = -eta,  eta = diag(1,-1,-1,-1),
//                                     eta' = diag(1,1,1,-1).
// ============================================================================

#include "core/Matrix4.h"
#include "core/Section.h"

#include <array>
#include <vector>

namespace slm
{

    class PermutationScan : public Section
    {
    public:
        struct Candidate
        {
            std::array<int, 4> permutation{}; // satir r'nin hangi girdi eksenini aldigi
            std::array<int, 4> signs{};       // o girdinin isareti
            Matrix4 matrix;
        };

        // Metrik testini gecen butun isaretli permutasyon matrisleri.
        static std::vector<Candidate> metricPreserving();

        std::string number() const override { return "§3b"; }
        std::string title() const override
        {
            return "384 isaretli permutasyon matrisinin taranmasi";
        }
        void run(Report &report) const override;
    };

} // namespace slm
