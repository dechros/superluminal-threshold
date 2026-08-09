#pragma once

#include "boundary/JunctionFamily.h"
#include "intermediate/IntermediateRegion.h"
#include "routes/ThreeRoutes.h"

#include <vector>

namespace slm
{

    /// The grid of matching requirements against descriptions, counted rather
    /// than asserted, and confronted with a propagated packet on every cell.
    ///
    /// The two indices do not enter the same way, and the counts are what show
    /// it. A matching requirement decides whether a crossing carrying no
    /// returning wave exists at all, so it governs whether the cell holds a
    /// journey. A description decides which duration is read off, so it
    /// governs what the cell reports. Neither index touches the other's job:
    /// the transmitted phase is built from the interior wavenumber and the
    /// thickness, and no matching requirement appears in it. So the grid
    /// factorises, and the number of genuinely distinct answers is far below
    /// the number of cells.
    class RouteGrid
    {
    public:
        /// Tally of the grid of requirements against descriptions.
        struct Grid
        {
            int cells;              ///< requirements times descriptions
            int deadByPremise;      ///< cells whose requirement cannot be imposed here
            int live;               ///< cells whose requirement applies
            int barredByRequirement;///< live cells whose requirement admits no outgoing-only wave
            int journeys;           ///< live cells that do hold a round trip
            int placingTheReturn;   ///< journeys whose description reproduces the measurement
            int distinctReadings;   ///< how many different durations the grid contains
        };

        static Grid grid(IntermediateRegion::Kind kind, double c, double mu,
                         double transverseSquared, double thickness, double centre, double spread,
                         int samples, double tolerance);

        /// How many cells of the grid place the return before the departure at
        /// the given far-side distance. Cells barred by their own matching
        /// requirement are not counted, since they hold no journey to place.
        static int cellsArrivingEarlier(IntermediateRegion::Kind kind, double c, double mu,
                                        double transverseSquared, double thickness, double centre,
                                        double farSideDistance);

        /// Whether every cell holding a journey places the return before the
        /// departure at that distance, across all matching requirements and
        /// all descriptions at once.
        static bool everyCellArrivesEarlier(IntermediateRegion::Kind kind, double c, double mu,
                                            double transverseSquared, double thickness,
                                            double centre, double farSideDistance);

        /// Moment the propagated packet is found at, measured from its
        /// departure, after the same far-side displacement. This is the referee
        /// for every cell of the grid and it belongs to no cell: it uses no
        /// reading and no matching requirement, only a packet summed over
        /// frequencies and a peak searched for.
        static double simulatedReturnMoment(IntermediateRegion::Kind kind, double c, double mu,
                                            double transverseSquared, double thickness,
                                            double centre, double spread, int samples,
                                            double farSideDistance);

        /// One cell of the grid, with what it claims and what the simulation
        /// finds, so that every cell is confronted with the measurement on
        /// every run rather than only the cell expected to survive.
        struct Cell
        {
            JunctionFamily::Requirement requirement;
            ThreeRoutes::Route route;
            bool applicable;
            bool holdsJourney;
            double claimedMoment;
            double simulatedMoment;
            bool agreesWithSimulation;
            bool claimsEarlier;
            bool simulationSaysEarlier;
        };

        /// Every cell of the grid, evaluated. The simulated moment is computed
        /// once and shared, since it depends on neither index.
        static std::vector<Cell> cells(IntermediateRegion::Kind kind, double c, double mu,
                                       double transverseSquared, double thickness, double centre,
                                       double spread, int samples, double farSideDistance,
                                       double tolerance);

        /// Whether every cell that holds a journey agrees with the simulation
        /// about the SIGN of the return, even where it disagrees about the
        /// amount. This is the weaker claim, and it is the one the conclusion
        /// needs.
        static bool everyJourneyAgreesOnSign(IntermediateRegion::Kind kind, double c, double mu,
                                             double transverseSquared, double thickness,
                                             double centre, double spread, int samples,
                                             double farSideDistance, double tolerance);
    };

}
