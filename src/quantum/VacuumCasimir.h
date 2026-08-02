#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on the vacuum reading and the Casimir signature of a
    /// reflecting threshold.
    class VacuumCasimir : public Section
    {
    public:
        /// Casimir energy per unit area between two Neumann surfaces,
        /// -pi^2 hbar c / (1440 L^3), the single massless scalar value, which is
        /// the same for Dirichlet and for Neumann conditions on both surfaces.
        /// \param separation Distance L between the surfaces.
        static double casimirEnergyPerArea(double hbar, double c, double separation);

        /// Scaling of the vacuum energy density near a single surface,
        /// hbar c / z^4, which still needs renormalisation.
        static double singleSurfaceEnergyDensityScale(double hbar, double c, double distance);

        std::string number() const override { return "10.11"; }
        std::string title() const override
        {
            return "Vacuum reading: correlation theory and the Casimir signature";
        }
        void run(Report &report) const override;
    };

}
