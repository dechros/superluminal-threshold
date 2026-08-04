#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the massive scalar Lagrangian on both sides and on the well
    /// posedness of the resulting initial value problems.
    class ScalarWaveField : public Section
    {
    public:
        /// Coefficient in d_t^2 f = coefficient * f for a region I plane wave.
        /// \return Always negative, so the mode oscillates.
        static double regionIGrowthCoefficient(double c, double mu, double kSquared);

        /// Coefficient in d_t1^2 f = coefficient * f for a region II mode.
        /// \param kTransverseSquared Squared frequency along the remaining
        ///        two time axes.
        /// \param q Frequency along the single space axis.
        /// \return May be positive and grows without bound, which is what
        ///         makes the initial value problem ill posed.
        static double regionIIGrowthCoefficient(double c, double mu, double kTransverseSquared,
                                                double q);

        /// Residual of the region I field equation for a plane wave, zero on
        /// shell.
        static double regionIResidual(double c, double mu, double omega, double kSquared);

        /// Residual of the region II field equation, zero on shell.
        static double regionIIResidual(double c, double mu, double kSquared, double q);

        std::string title() const override
        {
            return "Lagrangian, field equation, loss of determinism and the arrow of time";
        }
        void run(Report &report) const override;
    };

}
