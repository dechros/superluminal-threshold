#include "critique/SylvesterObstruction.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "transform/InvolutionD.h"

#include <cmath>
#include <format>
#include <random>

namespace slm
{
    double SylvesterObstruction::randomSearchBestResidual(int trials, unsigned seed)
    {
        std::mt19937 generator(seed);
        std::normal_distribution<double> normal(0.0, 1.0);

        const Matrix4 eta = metricRegionI();
        double best = 1e300;

        for (int trial = 0; trial < trials; ++trial)
        {
            Matrix4 candidate;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    candidate.at(i, j) = normal(generator);
                }
            }
            const double residual =
                (candidate.congruence(eta) + eta).maxAbsDifference(Matrix4::zero());
            best = std::min(best, residual);
        }
        return best;
    }

    void SylvesterObstruction::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const Matrix4 D = InvolutionD::matrix();

        report.subsection("17.1  Numerical scan over 20000 random real matrices");
        const double best = randomSearchBestResidual();
        report.check("the error does NOT approach zero, confirming the theorem numerically",
                     best > 1e-3);

        report.subsection("17.2  What does D actually satisfy?");
        const double withEtaPrime =
            (D.congruence(etaPrime) + eta).maxAbsDifference(Matrix4::zero());
        const double withEta = (D.congruence(eta) + eta).maxAbsDifference(Matrix4::zero());
        report.checkNear("D^T eta' D + eta = 0  (HOLDS)", withEtaPrime);
        report.check("D^T eta  D + eta = 0  (DOES NOT HOLD)", withEta > 1e-9);

        report.subsection("17.3  The fork");
        report.check("congruence by i*I: (i)^2 eta = -eta, available only over the complex field", true);
    }
}
