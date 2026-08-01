#include "boundary/ThresholdSurface.h"

#include "core/Report.h"
#include "dynamics/Dispersion.h"

#include <cmath>
#include <format>

namespace slm
{
    double ThresholdSurface::conjugateMomentumRegionI(double c, double timeDerivative)
    {
        return timeDerivative / (c * c);
    }

    double ThresholdSurface::conjugateMomentumRegionII(double c, double timeDerivative)
    {
        return -conjugateMomentumRegionI(c, timeDerivative);
    }

    double ThresholdSurface::junctionResidual(double c, double timeDerivative)
    {
        return conjugateMomentumRegionI(c, timeDerivative) -
               conjugateMomentumRegionII(c, timeDerivative);
    }

    void ThresholdSurface::run(Report &report) const
    {
        const double c = 1.0;
        const double hbar = 1.0;

        report.subsection("Threshold condition: v_phase = v_group = c only for mu = 0");
        const Dispersion massive(c, 1.0, hbar);
        const Dispersion massless(c, 0.0, hbar);
        for (double k : {0.5, 2.0, 10.0})
        {
            report.check("  massive field: v_phase > c and v_group < c",
                         massive.phaseVelocity(k) > c && massive.groupVelocity(k) < c);
        }
        report.checkNear("massless field: v_phase = v_group = c, exactly on the threshold",
                         massless.phaseVelocity(1.0) - c);

        report.subsection("Junction conditions");

        for (double derivative : {1.0, 0.5, 0.1, 0.0})
        {
            report.checkNear(std::format("d_t psi = {:g} : pi_II = -pi_I", derivative),
                             conjugateMomentumRegionII(c, derivative) +
                                 conjugateMomentumRegionI(c, derivative));
        }
        report.check("the junction condition holds only for d_t psi = 0",
                     std::abs(junctionResidual(c, 0.0)) < 1e-12 &&
                         std::abs(junctionResidual(c, 0.1)) > 1e-12);
    }
}
