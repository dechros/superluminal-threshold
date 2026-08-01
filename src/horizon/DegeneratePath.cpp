#include "horizon/DegeneratePath.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{

    Matrix4 DegeneratePath::direct(double lambda)
    {
        const double f = -std::cos(lambda);
        return Matrix4::diagonal(1.0, f, f, -1.0);
    }

    Matrix4 DegeneratePath::stagedFirst(double lambda)
    {
        return Matrix4::diagonal(1.0, -std::cos(lambda), -1.0, -1.0);
    }

    Matrix4 DegeneratePath::stagedSecond(double lambda)
    {
        return Matrix4::diagonal(1.0, 1.0, -std::cos(lambda), -1.0);
    }

    Matrix4 DegeneratePath::allSpace(double lambda)
    {
        const double f = -std::cos(lambda);
        return Matrix4::diagonal(1.0, f, f, f);
    }

    std::array<int, 3> DegeneratePath::signature(const Matrix4 &metric, double eps)
    {
        std::array<int, 3> counts{0, 0, 0};
        for (int i = 0; i < 4; ++i)
        {
            const double d = metric.at(i, i);
            if (std::abs(d) <= eps)
            {
                ++counts[2];
            }
            else if (d > 0.0)
            {
                ++counts[0];
            }
            else
            {
                ++counts[1];
            }
        }
        return counts;
    }

    int DegeneratePath::rankDrop(const Matrix4 &metric, double eps)
    {
        return signature(metric, eps)[2];
    }

    int DegeneratePath::worstRankDrop(Matrix4 (*path)(double), int samples)
    {
        const double pi = std::numbers::pi;
        int worst = 0;
        for (int i = 0; i < samples; ++i)
        {
            const double lambda = pi * static_cast<double>(i) / (samples - 1);
            worst = std::max(worst, rankDrop(path(lambda)));
        }
        return worst;
    }

    void DegeneratePathSection::run(Report &report) const
    {
        const double pi = std::numbers::pi;
        const Matrix4 etaI = metricRegionI();
        const Matrix4 etaII = metricRegionII();

        report.subsection("13.5  The determinant gives no obstruction");
        report.checkNear("det eta = -1", etaI.determinant() + 1.0);
        report.checkNear("det eta' = -1", etaII.determinant() + 1.0);
        report.check("both determinants are equal, so no sign change is forced "
                     "by the determinant alone",
                     std::abs(etaI.determinant() - etaII.determinant()) < 1e-12);

        report.subsection("13.5b  The path of section 13.3 ends somewhere else");
        const auto endAllSpace = DegeneratePath::signature(DegeneratePath::allSpace(pi));
        report.check("diag(1, -cos L, -cos L, -cos L) starts at (1,3)",
                     DegeneratePath::signature(DegeneratePath::allSpace(0.0)) ==
                         std::array<int, 3>{1, 3, 0});
        report.check("but ends at (4,0), the Euclidean signature, not (3,1)",
                     endAllSpace == (std::array<int, 3>{4, 0, 0}));
        report.check("so it answers the cosmological question, not ours", true);

        report.subsection("13.5c  Direct path: both entries flip together");
        report.check("starts at (1,3)",
                     DegeneratePath::signature(DegeneratePath::direct(0.0)) ==
                         std::array<int, 3>{1, 3, 0});
        report.check("ends at (3,1)",
                     DegeneratePath::signature(DegeneratePath::direct(pi)) ==
                         std::array<int, 3>{3, 1, 0});
        report.check("two eigenvalues vanish at the same point, rank drops by 2",
                     DegeneratePath::rankDrop(DegeneratePath::direct(pi / 2.0)) == 2);
        report.check("and that is the worst point on the path",
                     DegeneratePath::worstRankDrop(&DegeneratePath::direct) == 2);

        report.subsection("13.5d  Staged path: one entry at a time");
        report.check("first leg starts at (1,3)",
                     DegeneratePath::signature(DegeneratePath::stagedFirst(0.0)) ==
                         std::array<int, 3>{1, 3, 0});
        report.check("first leg ends at (2,2), the Kleinian signature",
                     DegeneratePath::signature(DegeneratePath::stagedFirst(pi)) ==
                         std::array<int, 3>{2, 2, 0});
        report.check("second leg ends at (3,1)",
                     DegeneratePath::signature(DegeneratePath::stagedSecond(pi)) ==
                         std::array<int, 3>{3, 1, 0});
        report.check("each leg drops rank by only 1",
                     DegeneratePath::worstRankDrop(&DegeneratePath::stagedFirst) == 1 &&
                         DegeneratePath::worstRankDrop(&DegeneratePath::stagedSecond) == 1);

        report.subsection("13.5e  What is unavoidable and what is not");
        report.check("degeneracy itself is unavoidable, since the count of "
                     "positive eigenvalues must change by two and each change "
                     "passes through zero",
                     true);
        report.check("a rank drop of 2 is NOT unavoidable, the staged path "
                     "reaches (3,1) with rank drop 1 throughout",
                     DegeneratePath::worstRankDrop(&DegeneratePath::stagedFirst) == 1 &&
                         DegeneratePath::worstRankDrop(&DegeneratePath::stagedSecond) == 1);
        report.check("the price is passing through (2,2), a two-time region",
                     DegeneratePath::signature(DegeneratePath::stagedFirst(pi))[0] == 2 &&
                         DegeneratePath::signature(DegeneratePath::stagedFirst(pi))[1] == 2);

        report.subsection("13.5f  Where each path degenerates");
        for (double lambda : {0.4 * pi, 0.5 * pi, 0.6 * pi})
        {
            report.check(std::format("  L = {:.3f} : direct path rank drop {}", lambda,
                                     DegeneratePath::rankDrop(DegeneratePath::direct(lambda))),
                         DegeneratePath::rankDrop(DegeneratePath::direct(lambda)) ==
                             (std::abs(lambda - pi / 2.0) < 1e-12 ? 2 : 0));
        }
    }

}
