#include "journey/Traveller.h"

#include "physics/units/PhysicalScales.h"

#include <cmath>
#include <numbers>

namespace slm
{
    double Traveller::mu() const
    {
        const double scale = mass * PhysicalScales::lightSpeed() / PhysicalScales::reducedPlanck();
        return scale * scale;
    }

    double Traveller::startSpeed() const
    {
        return mass > 0.0 ? 0.0 : 1.0;
    }

    double Traveller::startAngle() const
    {
        return std::atan(startSpeed());
    }

    bool Traveller::hasShape() const
    {
        return atoms.size() >= 3;
    }

    namespace
    {
        constexpr double kAtomicMassUnit = 1.66053906660e-27;
        constexpr double kAngstrom = 1e-10;
        constexpr double kHydrogenRadius = 0.31 * kAngstrom;
        constexpr double kCarbonRadius = 0.45 * kAngstrom;
        constexpr double kNitrogenRadius = 0.42 * kAngstrom;
        constexpr double kOxygenRadius = 0.40 * kAngstrom;
        constexpr double kFluorineRadius = 0.38 * kAngstrom;
        constexpr double kChlorineRadius = 0.55 * kAngstrom;
        constexpr double kBromineRadius = 0.62 * kAngstrom;

        Traveller::Three tetrahedral(int corner, double bondLength)
        {
            const double a = bondLength / std::numbers::sqrt3;
            switch (corner)
            {
            case 0:
                return {a, a, a};
            case 1:
                return {a, -a, -a};
            case 2:
                return {-a, a, -a};
            default:
                return {-a, -a, a};
            }
        }
    }

    Traveller Traveller::massless()
    {
        return Traveller{.name = "massless particle", .mass = 0.0, .atoms = {}, .radii = {}};
    }

    Traveller Traveller::hydrogenAtom()
    {
        return Traveller{.name = "hydrogen atom",
                         .mass = PhysicalScales::hydrogenAtomMass(),
                         .atoms = {},
                         .radii = {}};
    }

    Traveller Traveller::methane()
    {
        constexpr double bondLength = 1.087 * kAngstrom;
        return Traveller{.name = "methane molecule",
                         .mass = 16.043 * kAtomicMassUnit,
                         .atoms = {{0.0, 0.0, 0.0}, tetrahedral(0, bondLength), tetrahedral(1, bondLength),
                                   tetrahedral(2, bondLength), tetrahedral(3, bondLength)},
                         .radii = {kCarbonRadius, kHydrogenRadius, kHydrogenRadius, kHydrogenRadius,
                                   kHydrogenRadius}};
    }

    Traveller Traveller::water()
    {
        constexpr double bondLength = 0.9572 * kAngstrom;
        constexpr double halfAngle = 104.52 / 2.0 * std::numbers::pi / 180.0;
        const double x = bondLength * std::sin(halfAngle);
        const double y = bondLength * std::cos(halfAngle);
        return Traveller{.name = "water molecule",
                         .mass = 18.015 * kAtomicMassUnit,
                         .atoms = {{0.0, 0.0, 0.0}, {x, y, 0.0}, {-x, y, 0.0}},
                         .radii = {kOxygenRadius, kHydrogenRadius, kHydrogenRadius}};
    }

    Traveller Traveller::ammonia()
    {
        constexpr double bondLength = 1.012 * kAngstrom;
        constexpr double tilt = 112.0 * std::numbers::pi / 180.0;
        const double rise = bondLength * std::cos(tilt);
        const double spread = bondLength * std::sin(tilt);
        std::vector<Three> atoms{{0.0, 0.0, 0.0}};
        for (int k : {0, 1, 2})
        {
            const double phi = 2.0 * std::numbers::pi * k / 3.0;
            atoms.push_back({spread * std::cos(phi), rise, spread * std::sin(phi)});
        }
        return Traveller{.name = "ammonia molecule",
                         .mass = 17.031 * kAtomicMassUnit,
                         .atoms = atoms,
                         .radii = {kNitrogenRadius, kHydrogenRadius, kHydrogenRadius, kHydrogenRadius}};
    }

    Traveller Traveller::bromochlorofluoromethane()
    {
        return Traveller{.name = "bromochlorofluoromethane, chiral",
                         .mass = 147.37 * kAtomicMassUnit,
                         .atoms = {{0.0, 0.0, 0.0}, tetrahedral(0, 1.09 * kAngstrom),
                                   tetrahedral(1, 1.35 * kAngstrom), tetrahedral(2, 1.77 * kAngstrom),
                                   tetrahedral(3, 1.93 * kAngstrom)},
                         .radii = {kCarbonRadius, kHydrogenRadius, kFluorineRadius, kChlorineRadius,
                                   kBromineRadius}};
    }

    std::vector<Traveller> Traveller::reference()
    {
        return {massless(), hydrogenAtom(), methane()};
    }

    std::vector<Traveller> Traveller::all()
    {
        return {massless(), hydrogenAtom(), methane(), water(), ammonia(), bromochlorofluoromethane()};
    }
}
