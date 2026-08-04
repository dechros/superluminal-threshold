#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the vacuum reading and the vacuum energy signature of a
    /// reflecting threshold.
    class BoundaryVacuumEnergy : public Section
    {
    public:
        /// vacuum energy per unit area between two vanishing-slope surfaces,
        /// -pi^2 hbar c / (1440 L^3), the single massless scalar value, which is
        /// the same for vanishing-value and for vanishing-slope conditions on both surfaces.
        /// \param separation Distance L between the surfaces.
        static double boundaryEnergyPerArea(double hbar, double c, double separation);

        /// Scaling of the vacuum energy density near a single surface,
        /// hbar c / z^4, which still needs renormalisation.
        static double singleSurfaceEnergyDensityScale(double hbar, double c, double distance);

        std::string title() const override
        {
            return "Vacuum reading: correlation theory and the vacuum energy signature";
        }
        void run(Report &report) const override;
    };

}
