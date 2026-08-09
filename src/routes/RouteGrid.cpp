#include "routes/RouteGrid.h"

#include "sim/PacketSimulation.h"

#include <algorithm>
#include <cmath>

namespace slm
{
    RouteGrid::Grid RouteGrid::grid(IntermediateRegion::Kind kind, double c, double mu,
                                    double transverseSquared, double thickness, double centre,
                                    double spread, int samples, double tolerance)
    {
        const auto requirements = JunctionFamily::all();
        const auto routes = ThreeRoutes::all();
        const SurfaceLayer::Profile shape = SurfaceLayer::Profile::Linear;

        Grid counts{};
        counts.cells = static_cast<int>(requirements.size() * routes.size());

        std::vector<double> readings;
        for (JunctionFamily::Requirement requirement : requirements)
        {
            const bool applicable = JunctionFamily::isApplicable(requirement, shape);
            const bool admits = applicable && JunctionFamily::fixesMatching(requirement) &&
                                JunctionFamily::admitsOutgoingOnly(requirement);
            for (ThreeRoutes::Route route : routes)
            {
                if (!applicable)
                {
                    ++counts.deadByPremise;
                    continue;
                }
                ++counts.live;
                if (!admits)
                {
                    ++counts.barredByRequirement;
                    continue;
                }
                ++counts.journeys;
                const double value = ThreeRoutes::roundTripReading(route, kind, centre, c, mu,
                                                                    transverseSquared, thickness);
                bool seen = false;
                for (double held : readings)
                {
                    if (std::abs(held - value) <= tolerance * std::max(1.0, std::abs(held)))
                    {
                        seen = true;
                        break;
                    }
                }
                if (!seen)
                {
                    readings.push_back(value);
                }
                if (ThreeRoutes::reproducesMeasurement(route, kind, c, mu, transverseSquared,
                                                       thickness, centre, spread, samples,
                                                       tolerance))
                {
                    ++counts.placingTheReturn;
                }
            }
        }
        counts.distinctReadings = static_cast<int>(readings.size());
        return counts;
    }

    int RouteGrid::cellsArrivingEarlier(IntermediateRegion::Kind kind, double c, double mu,
                                        double transverseSquared, double thickness,
                                        double centre, double farSideDistance)
    {
        const SurfaceLayer::Profile shape = SurfaceLayer::Profile::Linear;
        int count = 0;
        for (JunctionFamily::Requirement requirement : JunctionFamily::all())
        {
            if (!JunctionFamily::isApplicable(requirement, shape) ||
                !JunctionFamily::fixesMatching(requirement) ||
                !JunctionFamily::admitsOutgoingOnly(requirement))
            {
                continue;
            }
            for (ThreeRoutes::Route route : ThreeRoutes::all())
            {
                if (ThreeRoutes::arrivesEarlier(route, kind, centre, c, mu, transverseSquared,
                                                thickness, farSideDistance))
                {
                    ++count;
                }
            }
        }
        return count;
    }

    bool RouteGrid::everyCellArrivesEarlier(IntermediateRegion::Kind kind, double c, double mu,
                                            double transverseSquared, double thickness,
                                            double centre, double farSideDistance)
    {
        const Grid counts =
            grid(kind, c, mu, transverseSquared, thickness, centre, 0.02, 300, 1e-2);
        return cellsArrivingEarlier(kind, c, mu, transverseSquared, thickness, centre,
                                    farSideDistance) == counts.journeys;
    }

    double RouteGrid::simulatedReturnMoment(IntermediateRegion::Kind kind, double c, double mu,
                                            double transverseSquared, double thickness,
                                            double centre, double spread, int samples,
                                            double farSideDistance)
    {
        return PacketSimulation::measuredReturnMoment(kind, c, mu, transverseSquared, thickness,
                                                       farSideDistance, -1, centre, spread,
                                                       samples, false);
    }

    std::vector<RouteGrid::Cell> RouteGrid::cells(IntermediateRegion::Kind kind, double c,
                                                  double mu, double transverseSquared,
                                                  double thickness, double centre, double spread,
                                                  int samples, double farSideDistance,
                                                  double tolerance)
    {
        const SurfaceLayer::Profile shape = SurfaceLayer::Profile::Linear;
        const double simulated = simulatedReturnMoment(kind, c, mu, transverseSquared, thickness,
                                                       centre, spread, samples, farSideDistance);
        std::vector<Cell> grid;
        for (JunctionFamily::Requirement requirement : JunctionFamily::all())
        {
            const bool applicable = JunctionFamily::isApplicable(requirement, shape);
            const bool holds = applicable && JunctionFamily::fixesMatching(requirement) &&
                               JunctionFamily::admitsOutgoingOnly(requirement);
            for (ThreeRoutes::Route route : ThreeRoutes::all())
            {
                Cell cell{};
                cell.requirement = requirement;
                cell.route = route;
                cell.applicable = applicable;
                cell.holdsJourney = holds;
                cell.claimedMoment = ThreeRoutes::returnMoment(route, kind, centre, c, mu,
                                                               transverseSquared, thickness,
                                                               farSideDistance);
                cell.simulatedMoment = simulated;
                const double scale = std::max(1.0, std::abs(simulated));
                cell.agreesWithSimulation =
                    std::abs(cell.claimedMoment - simulated) / scale < tolerance;
                cell.claimsEarlier = cell.claimedMoment < 0.0;
                cell.simulationSaysEarlier = simulated < 0.0;
                grid.push_back(cell);
            }
        }
        return grid;
    }

    bool RouteGrid::everyJourneyAgreesOnSign(IntermediateRegion::Kind kind, double c, double mu,
                                             double transverseSquared, double thickness,
                                             double centre, double spread, int samples,
                                             double farSideDistance, double tolerance)
    {
        bool seen = false;
        for (const Cell &cell : cells(kind, c, mu, transverseSquared, thickness, centre, spread,
                                      samples, farSideDistance, tolerance))
        {
            if (!cell.holdsJourney)
            {
                continue;
            }
            seen = true;
            if (cell.claimsEarlier != cell.simulationSaysEarlier)
            {
                return false;
            }
        }
        return seen;
    }

}
