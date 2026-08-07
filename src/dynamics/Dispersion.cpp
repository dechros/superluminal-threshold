#include "dynamics/Dispersion.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{
    Dispersion::Dispersion(double c, double mass, double hbar)
        : c_(c), mass_(mass), hbar_(hbar) {}

    double Dispersion::mu() const
    {
        const double value = mass_ * c_ / hbar_;
        return value * value;
    }

    double Dispersion::angularFrequency(double k) const
    {
        return c_ * std::sqrt(k * k + mu());
    }

    double Dispersion::phaseVelocity(double k) const
    {
        return angularFrequency(k) / k;
    }

    double Dispersion::groupVelocity(double k) const
    {
        return c_ * k / std::sqrt(k * k + mu());
    }

    double Dispersion::spatialFrequency(double kappa) const
    {
        return c_ * std::sqrt(kappa * kappa + mu());
    }

    double Dispersion::gradientMagnitude(double kappa) const
    {
        return c_ * kappa / std::sqrt(kappa * kappa + mu());
    }

    double Dispersion::frontVelocityAt(double k) const
    {
        return phaseVelocity(k);
    }

    void DispersionSection::run(Report &report) const
    {
        const double c = 1.0;
        const double hbar = 1.0;
        const double mass = 1.0;
        const Dispersion massive(c, mass, hbar);
        const Dispersion massless(c, 0.0, hbar);

        report.subsection("Where velocity comes from on the near side");
        for (double k : {0.1, 0.5, 1.0, 2.0, 10.0, 100.0})
        {
            const double vPhase = massive.phaseVelocity(k);
            const double vGroup = massive.groupVelocity(k);
            report.checkNear("  v_phase * v_group = c^2", vPhase * vGroup - c * c, 1e-12);
        }

        report.subsection("Limiting behaviour");
        report.check("k -> 0 : group velocity goes to 0", massive.groupVelocity(1e-8) < 1e-6);
        report.check("k -> infinity : group velocity goes to c",
                     std::abs(massive.groupVelocity(1e12) - c) < 1e-12);

        report.subsection("The signal front descends to c as the frequency rises");
        double previous = massive.frontVelocityAt(1.0);
        for (double k : {10.0, 100.0, 1000.0, 1e6})
        {
            const double here = massive.frontVelocityAt(k);
            report.check(std::format("  k = {:>8.0f} : phase velocity {:.6f}, still above c "
                                     "and still falling",
                                     k, here),
                         here > c && here < previous);
            previous = here;
        }
        report.check("so the front travels at c in the infinite-frequency limit, which is the "
                     "speed a causal boundary is allowed to have",
                     std::abs(massive.frontVelocityAt(1e12) - c) < 1e-12);

        report.subsection("Massless case: no dispersion");
        report.checkNear("both equal c, the velocity stays well defined",
                         massless.phaseVelocity(3.7) - massless.groupVelocity(3.7));

        report.subsection("Same derivative on the far side: q(kappa)");
        for (double kappa : {0.1, 1.0, 10.0, 1000.0})
        {
            report.check("  magnitude < c, the far side has a speed limit too",
                         massive.gradientMagnitude(kappa) < c);
        }
        report.checkNear("kappa -> infinity : tends to c",
                         massive.gradientMagnitude(1e12) - c);

        report.subsection("Both sides share the same dispersion structure");
        for (double k : {0.3, 1.0, 4.0})
        {
            report.checkNear(std::format("omega(k)/c = q(kappa)/c at k = kappa = {:g}", k),
                             massive.angularFrequency(k) - massive.spatialFrequency(k));
        }

        report.subsection("A body at rest, on the far side");
        report.checkNear("q(0) = mc^2/hbar != 0",
                         massive.spatialFrequency(0.0) - mass * c * c / hbar);
    }
}
