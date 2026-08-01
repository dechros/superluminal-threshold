#include "scan/PermutationScan.h"

#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <algorithm>
#include <array>
#include <format>
#include <map>
#include <string>

namespace slm
{

    std::vector<PermutationScan::Candidate> PermutationScan::metricPreserving()
    {
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();

        std::vector<Candidate> found;
        std::array<int, 4> perm{0, 1, 2, 3};

        // 4! permutasyon x 2^4 isaret = 384 aday.
        do
        {
            for (int mask = 0; mask < 16; ++mask)
            {
                Candidate candidate;
                candidate.permutation = perm;
                candidate.matrix = Matrix4::zero();

                for (int row = 0; row < 4; ++row)
                {
                    const int sign = ((mask >> row) & 1) ? -1 : 1;
                    candidate.signs[row] = sign;
                    candidate.matrix.at(row, perm[row]) = sign;
                }

                if (candidate.matrix.flipsMetric(eta, etaPrime))
                {
                    found.push_back(candidate);
                }
            }
        } while (std::next_permutation(perm.begin(), perm.end()));

        return found;
    }

    void PermutationScan::run(Report &report) const
    {
        const std::vector<Candidate> passing = metricPreserving();

        std::vector<Candidate> involutions;
        std::vector<Candidate> unitDet;
        std::vector<Candidate> both;
        for (const Candidate &candidate : passing)
        {
            const bool isInvolution = candidate.matrix.isInvolution();
            const bool isUnitDet = std::abs(candidate.matrix.determinant() - 1.0) < kEps;
            if (isInvolution)
            {
                involutions.push_back(candidate);
            }
            if (isUnitDet)
            {
                unitDet.push_back(candidate);
            }
            if (isInvolution && isUnitDet)
            {
                both.push_back(candidate);
            }
        }

        report.subsection("Tarama: 4! x 2^4 = 384 isaretli permutasyon matrisi");
        report.value("metrik testini gecen (M^T eta' M = -eta)", static_cast<double>(passing.size()));
        report.value("bunlardan involusyon olan (M^2 = I)", static_cast<double>(involutions.size()));
        report.value("bunlardan det = +1 olan", static_cast<double>(unitDet.size()));
        report.value("HEM involusyon HEM det = +1", static_cast<double>(both.size()));

        report.check("metrik testini gecen sayisi = 96", passing.size() == 96);
        report.check("involusyon olanlarin sayisi = 12", involutions.size() == 12);
        report.check("her iki kosulu saglayan sayisi = 8", both.size() == 8);

        report.subsection("Sekiz cozum: ct hangi slota gidiyor?");
        const char *labels[] = {"ct", "x", "y", "z"};
        std::map<int, int> ctSlotHistogram;
        for (const Candidate &candidate : both)
        {
            std::string mapping;
            int ctSlot = -1;
            for (int row = 0; row < 4; ++row)
            {
                mapping += std::format("{}->slot{}{}", labels[candidate.permutation[row]], row,
                                       candidate.signs[row] < 0 ? "(-)" : "");
                if (row != 3)
                {
                    mapping += ", ";
                }
                if (candidate.permutation[row] == 0)
                {
                    ctSlot = row;
                }
            }
            ++ctSlotHistogram[ctSlot];
            report.line("    " + mapping);
        }

        report.line();
        for (const auto &[slot, count] : ctSlotHistogram)
        {
            report.value(std::format("ct -> slot {} olan cozum sayisi", slot),
                         static_cast<double>(count));
        }
        report.line("  (slot 0,1,2 = zaman eksenleri, slot 3 = tek uzay ekseni)");

        const bool allCtToSpace = ctSlotHistogram.size() == 1 && ctSlotHistogram.count(3) == 1;
        report.check("sekiz cozumun TAMAMINDA ct -> tek uzay ekseni", allCtToSpace);
        report.conclusion("\"Bizim zamanimiz onlarin uzayi olur\" bir secim degil, ZORUNLULUK.");
        report.note("Kalan 8 cozumun farki yalnizca uzay eksenlerinin etiketlenmesi;");
        report.note("donme ile birbirine geciyorlar, fiziksel icerik tasimiyorlar.");

        report.subsection("D bu sekizin icinde mi?");
        const Matrix4 D = InvolutionD::matrix();
        const bool contains = std::any_of(both.begin(), both.end(), [&](const Candidate &candidate)
                                          { return candidate.matrix.isEqual(D); });
        report.check("secilen D, taramanin sonucu olan 8 cozumden biri", contains);
    }

} // namespace slm
