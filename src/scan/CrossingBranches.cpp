#include "scan/CrossingBranches.h"

#include "core/Report.h"
#include "core/Vector4.h"
#include "transform/SignatureInvolution.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{

    namespace
    {
        std::vector<CrossingBranches::Branch> scan(bool requireInvolution, bool requireUnitDet)
        {
            const Matrix4 eta = metricRegionI();
            const Matrix4 etaPrime = metricRegionII();
            std::vector<CrossingBranches::Branch> found;
            std::array<int, 4> permutation{0, 1, 2, 3};
            do
            {
                for (int mask = 0; mask < 16; ++mask)
                {
                    Matrix4 candidate = Matrix4::zero();
                    for (int row = 0; row < 4; ++row)
                    {
                        const double sign = (mask >> row & 1) ? -1.0 : 1.0;
                        candidate.at(static_cast<std::size_t>(row),
                                     static_cast<std::size_t>(permutation[row])) = sign;
                    }
                    if (!candidate.flipsMetric(eta, etaPrime))
                    {
                        continue;
                    }
                    if (requireInvolution && !candidate.isInvolution())
                    {
                        continue;
                    }
                    if (requireUnitDet && std::abs(candidate.determinant() - 1.0) > kEps)
                    {
                        continue;
                    }
                    const int axis = permutation[0];
                    const double entry =
                        candidate.at(0, static_cast<std::size_t>(axis));
                    found.push_back({candidate, axis, entry > 0.0 ? 1 : -1});
                }
            } while (std::next_permutation(permutation.begin(), permutation.end()));
            return found;
        }
    }

    std::vector<CrossingBranches::Branch> CrossingBranches::metricAdmissible()
    {
        return scan(false, false);
    }

    std::vector<CrossingBranches::Branch> CrossingBranches::closedUnderRepetition()
    {
        return scan(true, false);
    }

    std::vector<CrossingBranches::Branch> CrossingBranches::orientationPreserving()
    {
        return scan(true, true);
    }

    int CrossingBranches::countWithSign(const std::vector<Branch> &branches, int sign)
    {
        return static_cast<int>(
            std::count_if(branches.begin(), branches.end(),
                          [sign](const Branch &branch) { return branch.timeSign == sign; }));
    }

    bool CrossingBranches::axisIsCommon(const std::vector<Branch> &branches)
    {
        if (branches.empty())
        {
            return false;
        }
        const int axis = branches.front().farSideAxis;
        return std::all_of(branches.begin(), branches.end(),
                           [axis](const Branch &branch) { return branch.farSideAxis == axis; });
    }

    Matrix4 CrossingBranches::pairedReversal()
    {
        return Matrix4::diagonal(-1.0, 1.0, 1.0, -1.0);
    }

    bool CrossingBranches::isIsometryOfBothRegions(const Matrix4 &map)
    {
        return map.congruence(metricRegionI()).isEqual(metricRegionI(), kEps) &&
               map.congruence(metricRegionII()).isEqual(metricRegionII(), kEps);
    }

    bool CrossingBranches::familiesDifferByPairedReversal(const std::vector<Branch> &branches)
    {
        const Matrix4 reversal = pairedReversal();
        for (const Branch &branch : branches)
        {
            const Matrix4 image = reversal * branch.matrix;
            const auto match = std::find_if(branches.begin(), branches.end(),
                                            [&image](const Branch &other) {
                                                return other.matrix.isEqual(image, kEps);
                                            });
            if (match == branches.end() || match->timeSign != -branch.timeSign)
            {
                return false;
            }
        }
        return true;
    }

    double CrossingBranches::nearTimeFromUnitFarSide(const Branch &branch)
    {
        if (branch.farSideAxis < 0)
        {
            return 0.0;
        }
        Vector4 unit{};
        unit[static_cast<std::size_t>(branch.farSideAxis)] = 1.0;
        return (branch.matrix * unit)[0];
    }

    void CrossingBranchesSection::run(Report &report) const
    {
        const auto admissible = CrossingBranches::metricAdmissible();
        const auto closed = CrossingBranches::closedUnderRepetition();
        const auto oriented = CrossingBranches::orientationPreserving();

        report.subsection("The filter chain reproduces the counts of the earlier scan");
        report.check(std::format("metric relation leaves {} candidates", admissible.size()),
                     admissible.size() == 96);
        report.check(std::format("  and closure under repetition leaves {}", closed.size()),
                     closed.size() == 12);
        report.check(std::format("    and unit determinant leaves {}", oriented.size()),
                     oriented.size() == 8);

        report.subsection("All survivors agree on the axis, and none on the sign");
        report.check("every one of the eight sends the near-side time slot to the same far-side "
                     "axis",
                     CrossingBranches::axisIsCommon(oriented));
        report.check(std::format("but they divide evenly on its sign: {} later, {} earlier",
                                 CrossingBranches::countWithSign(oriented, 1),
                                 CrossingBranches::countWithSign(oriented, -1)),
                     CrossingBranches::countWithSign(oriented, 1) == 4 &&
                         CrossingBranches::countWithSign(oriented, -1) == 4);

        report.subsection("The division survives every stage of the filter");
        report.check(std::format("metric relation: {} later, {} earlier",
                                 CrossingBranches::countWithSign(admissible, 1),
                                 CrossingBranches::countWithSign(admissible, -1)),
                     CrossingBranches::countWithSign(admissible, 1) ==
                         CrossingBranches::countWithSign(admissible, -1));
        report.check(std::format("  closure: {} later, {} earlier",
                                 CrossingBranches::countWithSign(closed, 1),
                                 CrossingBranches::countWithSign(closed, -1)),
                     CrossingBranches::countWithSign(closed, 1) ==
                         CrossingBranches::countWithSign(closed, -1));
        report.check("so no strengthening of these three conditions removes the earlier branch",
                     CrossingBranches::countWithSign(oriented, -1) > 0);

        report.subsection("Each branch is admissible on its own terms");
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        bool everyBranchIsSound = true;
        for (const auto &branch : oriented)
        {
            everyBranchIsSound = everyBranchIsSound && branch.matrix.flipsMetric(eta, etaPrime) &&
                                 branch.matrix.isInvolution() &&
                                 std::abs(branch.matrix.determinant() - 1.0) <= kEps;
        }
        report.check("all eight satisfy the metric relation, close under repetition, and "
                     "preserve orientation",
                     everyBranchIsSound);

        const auto earlier = std::find_if(oriented.begin(), oriented.end(),
                                          [](const CrossingBranches::Branch &branch) {
                                              return branch.timeSign < 0;
                                          });
        report.check("an earlier-sending branch exists", earlier != oriented.end());
        if (earlier != oriented.end())
        {
            report.checkNear(std::format("  it sends a unit far-side displacement to {:+.4f} on "
                                         "the near-side clock",
                                         CrossingBranches::nearTimeFromUnitFarSide(*earlier)),
                             CrossingBranches::nearTimeFromUnitFarSide(*earlier) + 1.0);
        }

        report.subsection("What relates the two families");
        report.check("reversing the near-side time axis alone does not: it turns the determinant "
                     "negative and breaks the closure, leaving the admissible set",
                     [&oriented] {
                         const Matrix4 single = Matrix4::diagonal(-1.0, 1.0, 1.0, 1.0);
                         for (const auto &branch : oriented)
                         {
                             const Matrix4 image = single * branch.matrix;
                             if (image.isInvolution() ||
                                 std::abs(image.determinant() - 1.0) <= kEps)
                             {
                                 return false;
                             }
                         }
                         return true;
                     }());
        report.check("reversing the far side's distinguished axis alone does not either",
                     [&oriented] {
                         const Matrix4 single = Matrix4::diagonal(1.0, 1.0, 1.0, -1.0);
                         for (const auto &branch : oriented)
                         {
                             const Matrix4 image = single * branch.matrix;
                             if (image.isInvolution() ||
                                 std::abs(image.determinant() - 1.0) <= kEps)
                             {
                                 return false;
                             }
                         }
                         return true;
                     }());
        report.check("the two reversed together do: diag(-1,+1,+1,-1) maps the eight onto "
                     "themselves and flips every time sign",
                     CrossingBranches::familiesDifferByPairedReversal(oriented));
        report.check("and it is an isometry of both region metrics",
                     CrossingBranches::isIsometryOfBothRegions(CrossingBranches::pairedReversal()));
        report.checkNear("with unit determinant, so it satisfies every condition imposed on a "
                         "crossing",
                         CrossingBranches::pairedReversal().determinant() - 1.0);
        report.check("the pair it reverses is exactly the pair the crossing identifies: the "
                     "near-side "
                     "time and the far side's single space direction",
                     CrossingBranches::pairedReversal().at(0, 0) < 0.0 &&
                         CrossingBranches::pairedReversal().at(3, 3) < 0.0 &&
                         CrossingBranches::axisIsCommon(oriented) &&
                         oriented.front().farSideAxis == 3);

        report.subsection("Where this leaves the selection");
        const Matrix4 D = SignatureInvolution::matrix();
        const auto chosen = std::find_if(oriented.begin(), oriented.end(),
                                         [&D](const CrossingBranches::Branch &branch) {
                                             return branch.matrix.isEqual(D, kEps);
                                         });
        report.check("the matrix used throughout is one of the eight",
                     chosen != oriented.end());
        report.check("and it belongs to the later-sending family, which is a choice among "
                     "the eight and not a consequence of the three conditions",
                     chosen != oriented.end() && chosen->timeSign > 0);
        report.check("nothing computed here selects between the families, and the "
                     "transformation separating them is an isometry of both metrics with "
                     "unit determinant, so the selection is not geometric",
                     CrossingBranches::familiesDifferByPairedReversal(oriented) &&
                         CrossingBranches::isIsometryOfBothRegions(
                             CrossingBranches::pairedReversal()) &&
                         CrossingBranches::countWithSign(oriented, -1) == 4);
    }

}
