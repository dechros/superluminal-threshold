#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the junction conditions at the threshold surface Sigma.
    class ThresholdSurface : public Section
    {
    public:
        /// Conjugate momentum on the region I side, pi = (1/c^2) d_t phi.
        static double conjugateMomentumRegionI(double c, double timeDerivative);

        /// Conjugate momentum on the region II side, which carries the
        /// opposite sign because the normal changes type.
        static double conjugateMomentumRegionII(double c, double timeDerivative);

        /// Residual pi_I - pi_II of the junction condition.
        /// \return Zero only when the conjugate momentum itself vanishes.
        static double junctionResidual(double c, double timeDerivative);

        std::string number() const override { return "9"; }
        std::string title() const override
        {
            return "Threshold surface at V = c: Sigma reflects";
        }
        void run(Report &report) const override;
    };

}
