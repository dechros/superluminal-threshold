#pragma once

#include "core/Section.h"

namespace slm
{

    /// Dispersion relation of a massive field, evaluated on either side.
    ///
    /// One instance fixes the constants c, m and hbar; the member functions
    /// are pure queries on those constants.
    class Dispersion
    {
    public:
        /// \param c Speed of light.
        /// \param mass Field mass, may be zero.
        /// \param hbar Reduced Planck constant.
        Dispersion(double c, double mass, double hbar);

        /// The mass parameter mu = (m c / hbar)^2.
        double mu() const;

        /// Region I angular frequency omega(k) = c sqrt(k^2 + mu).
        double angularFrequency(double k) const;
        /// Phase velocity omega/k.
        double phaseVelocity(double k) const;
        /// Group velocity d(omega)/dk.
        double groupVelocity(double k) const;

        /// Region II counterpart q(kappa), the same functional form.
        double spatialFrequency(double kappa) const;
        /// Magnitude |dq/dkappa|, which is a gradient rather than a scalar
        /// derivative because region II has three time axes.
        double gradientMagnitude(double kappa) const;

    private:
        double c_;
        double mass_;
        double hbar_;
    };

    /// Section wrapper running the dispersion verifications.
    class DispersionSection : public Section
    {
    public:
        std::string number() const override { return "9.1"; }
        std::string title() const override
        {
            return "Velocity: from scalar to orientation";
        }
        void run(Report &report) const override;
    };

}
