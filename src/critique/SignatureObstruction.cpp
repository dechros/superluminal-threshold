#include "critique/SignatureObstruction.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "transform/SignatureInvolution.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <random>

namespace slm
{
    double SignatureObstruction::randomSearchBestResidual(int trials, unsigned seed)
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

    void SignatureObstruction::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const Matrix4 D = SignatureInvolution::matrix();

        report.subsection("Numerical scan over 20000 random real matrices");
        const double best = randomSearchBestResidual();
        report.check("the error does NOT approach zero, confirming the theorem numerically",
                     best > 1e-3);

        report.subsection("What does D actually satisfy?");
        const double withEtaPrime =
            (D.congruence(etaPrime) + eta).maxAbsDifference(Matrix4::zero());
        const double withEta = (D.congruence(eta) + eta).maxAbsDifference(Matrix4::zero());
        report.checkNear("D^T eta' D + eta = 0  (HOLDS)", withEtaPrime);
        report.check("D^T eta  D + eta = 0  (DOES NOT HOLD)", withEta > 1e-9);

        report.subsection("The fork");
        double closestRealScalar = 1e9;
        for (int step = -4000; step <= 4000; ++step)
        {
            const double s = step * 0.001;
            closestRealScalar = std::min(closestRealScalar, std::abs(s * s + 1.0));
        }
        report.check(std::format("scaling by s sends eta to s^2 eta, and no real s comes "
                                 "nearer than {:.4f} to s^2 = -1, so the congruence by i*I "
                                 "lives only over the complex field",
                                 closestRealScalar),
                     closestRealScalar > 0.5);
    }
}
