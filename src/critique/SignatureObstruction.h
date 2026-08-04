#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the inertia law forbidding a real transformation from
    /// flipping the signature of one metric.
    class SignatureObstruction : public Section
    {
    public:
        /// Smallest residual of M^T eta M + eta found by random search.
        /// \param trials Number of random matrices to try.
        /// \param seed Seed of the generator, fixed so runs reproduce.
        /// \return A value that stays far from zero.
        static double randomSearchBestResidual(int trials = 20000, unsigned seed = 20250801u);

        std::string title() const override
        {
            return "signature obstruction and where the model stands";
        }
        void run(Report &report) const override;
    };

}
