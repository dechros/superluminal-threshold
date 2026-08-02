#pragma once

#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// Section on how the four-momentum and its invariant behave under D.
    class EnergyMomentum : public Section
    {
    public:
        /// Builds the region I four-momentum (E/c, px, py, pz).
        static Vector4 fourMomentum(double c, double energy, double px, double py, double pz);

        /// Image of a four-momentum under D.
        /// \param c Unused, kept so the call sites read uniformly.
        /// \param p Four-momentum in region I.
        static Vector4 transformed(double c, const Vector4 &p);

        /// The invariant E^2/c^2 - p^2, contracted with the region I metric.
        static double invariant(const Vector4 &p);

        /// Energy on the mass shell, sqrt(p^2 c^2 + m^2 c^4).
        static double shellEnergy(double c, double mass, double px, double py, double pz);

        std::string title() const override { return "Energy and momentum swap"; }
        void run(Report &report) const override;
    };

}
