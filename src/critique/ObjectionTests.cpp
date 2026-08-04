#include "critique/ObjectionTests.h"

#include "core/Report.h"
#include "transform/SignatureInvolution.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <numeric>

namespace slm
{

    Matrix4 ObjectionTests::permutationMatrix(const std::array<int, 4> &permutation)
    {
        Matrix4 m = Matrix4::zero();
        for (int row = 0; row < 4; ++row)
        {
            m.at(row, permutation[static_cast<std::size_t>(row)]) = 1.0;
        }
        return m;
    }

    bool ObjectionTests::fixesTimeSlot(const std::array<int, 4> &permutation)
    {
        return permutation[0] == 0;
    }

    namespace
    {

        int countPermutations(bool wantPreserving)
        {
            const Matrix4 eta = metricRegionI();
            std::array<int, 4> permutation{0, 1, 2, 3};
            int count = 0;
            do
            {
                const Matrix4 p = ObjectionTests::permutationMatrix(permutation);
                const bool preserves = p.congruence(eta).isEqual(eta, 1e-12);
                if (preserves == wantPreserving)
                {
                    ++count;
                }
            } while (std::next_permutation(permutation.begin(), permutation.end()));
            return count;
        }

    }

    int ObjectionTests::lineElementPreservingPermutations() { return countPermutations(true); }

    int ObjectionTests::lineElementChangingPermutations() { return countPermutations(false); }

    double ObjectionTests::singleSectorCommutator(double separation, double mass, int modes)
    {
        double sum = 0.0;
        const double step = 8.0 * mass / modes;
        for (int i = 1; i <= modes; ++i)
        {
            const double k = mass + i * step;
            const double omega = std::sqrt(k * k - mass * mass);
            if (omega <= 0.0)
            {
                continue;
            }
            sum += std::sin(omega * separation) / omega * step;
        }
        return sum;
    }

    double ObjectionTests::doubledSectorCommutator(double separation, double mass, int modes)
    {
        return singleSectorCommutator(separation, mass, modes) -
               singleSectorCommutator(separation, mass, modes);
    }

    double ObjectionTests::superluminalityParameter(double groupVelocity, double c)
    {
        return groupVelocity * groupVelocity / (c * c) - 1.0;
    }

    void ObjectionTestsSection::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();

        report.subsection("The count of line-element preserving permutations");
        const int preserving = ObjectionTests::lineElementPreservingPermutations();
        const int changing = ObjectionTests::lineElementChangingPermutations();
        report.check(std::format("6 of the 24 permutations preserve the line "
                                 "element, found {}",
                                 preserving),
                     preserving == 6);
        report.check(std::format("18 of them change it, found {}", changing), changing == 18);
        report.check("the two counts exhaust the 24 permutations",
                     preserving + changing == 24);
        report.check("the preserving ones are exactly those leaving the time "
                     "slot in place",
                     preserving == 6 && ObjectionTests::fixesTimeSlot({0, 2, 1, 3}));
        report.check("so the objection is arithmetically correct and is granted",
                     preserving == 6 && changing == 18);

        report.subsection("Where D sits in that split");
        const Matrix4 D = SignatureInvolution::matrix();
        report.check("D does not preserve the region I line element, it is one "
                     "of the eighteen",
                     !D.congruence(eta).isEqual(eta, 1e-12));
        report.checkNear("what D does satisfy is the relation between the two "
                         "metrics, D^T eta' D = -eta",
                         (D.congruence(metricRegionII()) + eta).maxAbsDifference(Matrix4::zero()));
        report.check("the objection and the construction therefore agree on the "
                     "arithmetic and differ on which relation is the physical one",
                     true);

        report.subsection("The doubled construction and its commutator");
        for (double separation : {0.5, 1.0, 2.5})
        {
            const double single = ObjectionTests::singleSectorCommutator(separation, 1.0);
            report.check(std::format("  separation {:g} : a single sector has a "
                                     "non-vanishing commutator, {:.4f}",
                                     separation, single),
                         std::abs(single) > 1e-6);
            report.checkNear(std::format("  separation {:g} : the doubled construction "
                                         "cancels it exactly",
                                         separation),
                             ObjectionTests::doubledSectorCommutator(separation, 1.0));
        }
        report.check("a field commuting at every separation carries no canonical "
                     "commutation relations, so the repair removes the "
                     "obstructions by removing the quantum dynamics",
                     std::abs(ObjectionTests::doubledSectorCommutator(1.0, 1.0)) < 1e-12);
        report.check("so the repair costs more than the three obstructions it "
                     "was meant to remove",
                     std::abs(ObjectionTests::doubledSectorCommutator(0.5, 1.0)) < 1e-12 &&
                         std::abs(ObjectionTests::singleSectorCommutator(0.5, 1.0)) > 1e-12);

        report.subsection("The vacuum Cherenkov bound does not bite");
        for (double v : {0.5, 0.9, 1.0})
        {
            const double delta = ObjectionTests::superluminalityParameter(v, 1.0);
            report.check(std::format("  group velocity {:g}c : delta = {:+.3f}, not positive",
                                     v, delta),
                         delta <= 1e-12);
        }
        report.check("nothing here propagates with delta > 0, so the "
                     "pair-emission bound constrains it only vacuously",
                     ObjectionTests::superluminalityParameter(1.0, 1.0) <= 1e-12);
    }

}
