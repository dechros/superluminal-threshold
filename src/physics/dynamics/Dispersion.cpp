#include "physics/dynamics/Dispersion.h"

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
}
