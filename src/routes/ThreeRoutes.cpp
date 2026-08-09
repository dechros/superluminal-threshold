#include "routes/ThreeRoutes.h"

#include "boundary/JunctionFamily.h"
#include "core/Report.h"
#include "intermediate/DwellTime.h"
#include "intermediate/TraversalClocks.h"
#include "intermediate/TwoCrossings.h"
#include "routes/RouteGrid.h"
#include "sim/PacketSimulation.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <format>
#include <vector>

namespace slm
{

    std::vector<ThreeRoutes::Route> ThreeRoutes::all()
    {
        return {Route::PointBody, Route::Wave, Route::Amplitude};
    }

    std::string ThreeRoutes::name(Route route)
    {
        switch (route)
        {
        case Route::PointBody:
            return "point body";
        case Route::Wave:
            return "wave";
        case Route::Amplitude:
            return "amplitude";
        }
        return "unknown";
    }

    std::string ThreeRoutes::construction(Route route)
    {
        switch (route)
        {
        case Route::PointBody:
            return "the thickness divided by a speed built from the interior wavenumber";
        case Route::Wave:
            return "the frequency derivative of the transmitted phase";
        case Route::Amplitude:
            return "the stored norm divided by the incident flux";
        }
        return "unknown";
    }

    double ThreeRoutes::reading(Route route, IntermediateRegion::Kind kind, double omega, double c,
                                double mu, double transverseSquared, double thickness)
    {
        switch (route)
        {
        case Route::PointBody:
            return TraversalClocks::semiclassicalTime(kind, omega, c, mu, transverseSquared,
                                                      thickness);
        case Route::Wave:
            return TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, thickness);
        case Route::Amplitude:
            return DwellTime::dwellTime(kind, omega, c, mu, transverseSquared, thickness);
        }
        return 0.0;
    }

    double ThreeRoutes::roundTripReading(Route route, IntermediateRegion::Kind kind, double omega,
                                         double c, double mu, double transverseSquared,
                                         double thickness)
    {
        return 2.0 * reading(route, kind, omega, c, mu, transverseSquared, thickness);
    }

    double ThreeRoutes::thresholdFromRoute(Route route, IntermediateRegion::Kind kind, double omega,
                                           double c, double mu, double transverseSquared,
                                           double thickness)
    {
        return roundTripReading(route, kind, omega, c, mu, transverseSquared, thickness);
    }

    double ThreeRoutes::departureFromMeasurement(Route route, IntermediateRegion::Kind kind,
                                                 double c, double mu, double transverseSquared,
                                                 double thickness, double centre, double spread,
                                                 int samples)
    {
        const double measured = PacketSimulation::measuredThreshold(
            kind, c, mu, transverseSquared, thickness, -1, centre, spread, samples);
        if (std::abs(measured) < 1e-12)
        {
            return std::numeric_limits<double>::infinity();
        }
        const double claimed = reading(route, kind, centre, c, mu, transverseSquared, thickness);
        return std::abs(claimed - measured) / std::abs(measured);
    }

    bool ThreeRoutes::reproducesMeasurement(Route route, IntermediateRegion::Kind kind, double c,
                                            double mu, double transverseSquared, double thickness,
                                            double centre, double spread, int samples,
                                            double tolerance)
    {
        return departureFromMeasurement(route, kind, c, mu, transverseSquared, thickness, centre,
                                        spread, samples) < tolerance;
    }

    int ThreeRoutes::reproducingCount(IntermediateRegion::Kind kind, double c, double mu,
                                      double transverseSquared, double thickness, double centre,
                                      double spread, int samples, double tolerance)
    {
        int count = 0;
        for (Route route : all())
        {
            if (reproducesMeasurement(route, kind, c, mu, transverseSquared, thickness, centre,
                                      spread, samples, tolerance))
            {
                ++count;
            }
        }
        return count;
    }

    bool ThreeRoutes::saturates(Route route, IntermediateRegion::Kind kind, double omega, double c,
                                double mu, double transverseSquared)
    {
        const double nearValue = reading(route, kind, omega, c, mu, transverseSquared, 8.0);
        const double farValue = reading(route, kind, omega, c, mu, transverseSquared, 16.0);
        return TraversalClocks::saturates(nearValue, farValue);
    }

    bool ThreeRoutes::routesDisagree(IntermediateRegion::Kind kind, double omega, double c,
                                     double mu, double transverseSquared, double thickness,
                                     double tolerance)
    {
        const double body = reading(Route::PointBody, kind, omega, c, mu, transverseSquared,
                                    thickness);
        const double wave = reading(Route::Wave, kind, omega, c, mu, transverseSquared, thickness);
        const double amplitude =
            reading(Route::Amplitude, kind, omega, c, mu, transverseSquared, thickness);
        const double scale = std::max({std::abs(body), std::abs(wave), std::abs(amplitude)});
        if (scale <= 0.0)
        {
            return false;
        }
        return std::abs(body - wave) / scale > tolerance ||
               std::abs(wave - amplitude) / scale > tolerance;
    }

    double ThreeRoutes::returnMoment(Route route, IntermediateRegion::Kind kind, double omega,
                                     double c, double mu, double transverseSquared,
                                     double thickness, double farSideDistance)
    {
        return roundTripReading(route, kind, omega, c, mu, transverseSquared, thickness) -
               farSideDistance;
    }

    bool ThreeRoutes::arrivesEarlier(Route route, IntermediateRegion::Kind kind, double omega,
                                     double c, double mu, double transverseSquared,
                                     double thickness, double farSideDistance)
    {
        return returnMoment(route, kind, omega, c, mu, transverseSquared, thickness,
                            farSideDistance) < 0.0;
    }

    double ThreeRoutes::distanceForUnanimousAdvance(IntermediateRegion::Kind kind, double omega,
                                                    double c, double mu, double transverseSquared,
                                                    double thickness)
    {
        double largest = 0.0;
        for (Route route : all())
        {
            largest = std::max(
                largest, roundTripReading(route, kind, omega, c, mu, transverseSquared, thickness));
        }
        return largest;
    }

    ThreeRoutes::Route ThreeRoutes::mostConservativeRoute(IntermediateRegion::Kind kind,
                                                          double omega, double c, double mu,
                                                          double transverseSquared,
                                                          double thickness)
    {
        Route worst = Route::PointBody;
        double largest = -std::numeric_limits<double>::infinity();
        for (Route route : all())
        {
            const double value =
                roundTripReading(route, kind, omega, c, mu, transverseSquared, thickness);
            if (value > largest)
            {
                largest = value;
                worst = route;
            }
        }
        return worst;
    }

    void ThreeRoutesSection::run(Report &report) const
    {
        const IntermediateRegion::Kind kind = IntermediateRegion::Kind::Euclidean;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double centre = 2.8;
        const double spread = 0.02;
        const double thickness = 8.0;
        const int samples = 300;
        const double tolerance = 1e-2;

        report.subsection("What each description divides by what");
        for (ThreeRoutes::Route route : ThreeRoutes::all())
        {
            report.check(std::format("  {:<11} : {}", ThreeRoutes::name(route),
                                     ThreeRoutes::construction(route)),
                         true);
        }

        report.subsection("The three readings of one crossing");
        for (ThreeRoutes::Route route : ThreeRoutes::all())
        {
            const double single =
                ThreeRoutes::reading(route, kind, centre, c, mu, transverse, thickness);
            report.check(std::format("  {:<11} : one crossing takes {:.6f}, the round trip {:.6f}",
                                     ThreeRoutes::name(route), single, 2.0 * single),
                         std::isfinite(single));
        }
        report.check("the three do not agree, so the crossing has no single duration and the "
                     "choice among the readings is not a matter of taste",
                     ThreeRoutes::routesDisagree(kind, centre, c, mu, transverse, thickness,
                                                 tolerance));

        report.subsection("Which reading places the returning state, decided by measurement");
        for (ThreeRoutes::Route route : ThreeRoutes::all())
        {
            const double departure = ThreeRoutes::departureFromMeasurement(
                route, kind, c, mu, transverse, thickness, centre, spread, samples);
            report.check(std::format("  {:<11} : its threshold differs from the measured peak by "
                                     "{:.2e} in relative terms",
                                     ThreeRoutes::name(route), departure),
                         std::isfinite(departure));
        }
        report.check(std::format("{} of the three reproduce the measured threshold",
                                 ThreeRoutes::reproducingCount(kind, c, mu, transverse, thickness,
                                                                centre, spread, samples,
                                                                tolerance)),
                     ThreeRoutes::reproducingCount(kind, c, mu, transverse, thickness, centre,
                                                    spread, samples, tolerance) == 1);
        report.check("and it is the wave reading, the frequency derivative of the phase, so the "
                     "placement of the returning state on the near-side time axis is a property "
                     "of the phase and not of residence in the region",
                     ThreeRoutes::reproducesMeasurement(ThreeRoutes::Route::Wave, kind, c, mu,
                                                         transverse, thickness, centre, spread,
                                                         samples, tolerance));
        report.check("the other two are not thereby wrong: they answer how long the state resides "
                     "and how long a forbidden interior takes to cross, and offering either as an "
                     "arrival time is the substitution this section refuses",
                     !ThreeRoutes::reproducesMeasurement(ThreeRoutes::Route::PointBody, kind, c, mu,
                                                          transverse, thickness, centre, spread,
                                                          samples, tolerance) &&
                         !ThreeRoutes::reproducesMeasurement(ThreeRoutes::Route::Amplitude, kind, c,
                                                              mu, transverse, thickness, centre,
                                                              spread, samples, tolerance));

        report.subsection("The grid of matching requirements against descriptions");
        const RouteGrid::Grid counts = RouteGrid::grid(kind, c, mu, transverse, thickness,
                                                       centre, spread, samples, tolerance);
        report.check(std::format("  the full grid is {} cells, eight requirements against three "
                                 "descriptions",
                                 counts.cells),
                     counts.cells == 24);
        report.check(std::format("  {} cells are dead before any physics, their requirement having "
                                 "no premise at this surface",
                                 counts.deadByPremise),
                     counts.deadByPremise == 9);
        report.check(std::format("  {} cells are live, which is the five applicable requirements "
                                 "against the three descriptions",
                                 counts.live),
                     counts.live == 15);
        report.check(std::format("  {} of those are barred by their own requirement, the one "
                                 "asking the curvature itself to vanish admitting no wave that "
                                 "leaves without one returning",
                                 counts.barredByRequirement),
                     counts.barredByRequirement == 3);
        report.check(std::format("  {} cells therefore hold a round trip", counts.journeys),
                     counts.journeys == 12);
        report.check(std::format("  and those twelve contain only {} distinct durations, because "
                                 "the transmitted phase is built from the interior wavenumber and "
                                 "the thickness and carries no matching requirement at all",
                                 counts.distinctReadings),
                     counts.distinctReadings == 3);
        report.check("so the grid factorises: the requirement decides whether a cell holds a "
                     "journey, the description decides what the cell reports, and neither index "
                     "does the other's work",
                     counts.journeys == 12 && counts.distinctReadings == 3);
        report.check(std::format("  {} cells both hold a journey and place the returning state "
                                 "where it is measured, which is the four surviving requirements "
                                 "against the one surviving description",
                                 counts.placingTheReturn),
                     counts.placingTheReturn == 4);

        report.subsection("Travel in the second region, priced by each description in turn");
        const double unanimous = ThreeRoutes::distanceForUnanimousAdvance(kind, centre, c, mu,
                                                                          transverse, thickness);
        for (ThreeRoutes::Route route : ThreeRoutes::all())
        {
            for (double distance : {2.0, 6.0, 25.0})
            {
                const double moment = ThreeRoutes::returnMoment(
                    route, kind, centre, c, mu, transverse, thickness, distance);
                report.check(std::format("  {:<11} : covering {:>5.1f} over there returns at "
                                         "{:+9.4f}, which is {}",
                                         ThreeRoutes::name(route), distance, moment,
                                         moment < 0.0 ? "before departure" : "after departure"),
                             std::isfinite(moment));
            }
        }
        report.check("no description places the return earlier without motion in the second "
                     "region: with the distance set to zero every one of them returns after the "
                     "departure, so the advance is bought by the travel there and not by the "
                     "crossing",
                     !ThreeRoutes::arrivesEarlier(ThreeRoutes::Route::Wave, kind, centre, c, mu,
                                                   transverse, thickness, 0.0) &&
                         !ThreeRoutes::arrivesEarlier(ThreeRoutes::Route::PointBody, kind, centre, c,
                                                       mu, transverse, thickness, 0.0) &&
                         !ThreeRoutes::arrivesEarlier(ThreeRoutes::Route::Amplitude, kind, centre, c,
                                                       mu, transverse, thickness, 0.0));
        report.check(std::format("every description places the return before the departure once "
                                 "the far-side distance passes {:.4f}, and the description "
                                 "demanding that much is the {} one",
                                 unanimous,
                                 ThreeRoutes::name(ThreeRoutes::mostConservativeRoute(
                                     kind, centre, c, mu, transverse, thickness))),
                     unanimous > 0.0);
        report.check(std::format("at a far-side distance of 25 all {} cells holding a journey "
                                 "place the return before the departure, across every applicable "
                                 "matching requirement and every description at once",
                                 counts.journeys),
                     RouteGrid::everyCellArrivesEarlier(kind, c, mu, transverse, thickness,
                                                        centre, 25.0));
        report.check("so the mechanism is common to all of them and only its price is not: the "
                     "advance comes from displacement in the second region, which every "
                     "description converts the same way, while how much displacement is needed "
                     "depends on which duration is charged for the crossing",
                     RouteGrid::everyCellArrivesEarlier(kind, c, mu, transverse, thickness,
                                                        centre, 25.0) &&
                         !RouteGrid::everyCellArrivesEarlier(kind, c, mu, transverse, thickness,
                                                             centre, 6.0));
        report.check("below that distance the descriptions disagree about the sign, which is "
                     "exactly the range where a reader is entitled to ask which clock was chosen, "
                     "and above it the question does not arise",
                     ThreeRoutes::arrivesEarlier(ThreeRoutes::Route::Wave, kind, centre, c, mu,
                                                  transverse, thickness, 6.0) &&
                         !ThreeRoutes::arrivesEarlier(ThreeRoutes::Route::PointBody, kind, centre, c,
                                                       mu, transverse, thickness, 6.0));

        report.subsection("Every cell of the grid against the simulation, on every run");
        const double farSide = 25.0;
        const auto allCells = RouteGrid::cells(kind, c, mu, transverse, thickness, centre, spread,
                                               samples, farSide, tolerance);
        report.check(std::format("  the packet is propagated once with a far-side displacement of "
                                 "{:.1f} and found at {:+.4f}, and that one number referees all "
                                 "{} cells because it uses neither index",
                                 farSide,
                                 RouteGrid::simulatedReturnMoment(kind, c, mu, transverse,
                                                                  thickness, centre, spread,
                                                                  samples, farSide),
                                 allCells.size()),
                     allCells.size() == 24);
        for (const RouteGrid::Cell &cell : allCells)
        {
            if (!cell.applicable)
            {
                continue;
            }
            report.check(std::format("  {:<28} x {:<11} : {} claims {:+9.4f} against {:+9.4f}, {}",
                                     JunctionFamily::name(cell.requirement),
                                     ThreeRoutes::name(cell.route),
                                     cell.holdsJourney ? "journey " : "barred  ",
                                     cell.claimedMoment, cell.simulatedMoment,
                                     cell.agreesWithSimulation ? "agrees" : "differs"),
                         std::isfinite(cell.claimedMoment) &&
                             std::isfinite(cell.simulatedMoment));
        }
        report.check("every cell holding a journey agrees with the simulation on the SIGN of the "
                     "return, even the two descriptions whose amount is wrong, so the conclusion "
                     "that the state comes back before it left survives every description and "
                     "every applicable matching requirement at once",
                     RouteGrid::everyJourneyAgreesOnSign(kind, c, mu, transverse, thickness,
                                                         centre, spread, samples, farSide,
                                                         tolerance));
        report.check("and this comparison runs on every execution rather than being recorded from "
                     "one, which is what keeps a later change to any reading or to any matching "
                     "requirement from passing unnoticed",
                     !allCells.empty());

        report.subsection("Which readings stop growing with thickness");
        for (ThreeRoutes::Route route : ThreeRoutes::all())
        {
            report.check(std::format("  {:<11} : {}", ThreeRoutes::name(route),
                                     ThreeRoutes::saturates(route, kind, centre, c, mu, transverse)
                                         ? "stops growing"
                                         : "keeps growing"),
                         true);
        }
        report.check("a reading that saturates and a reading that does not cannot both be a "
                     "transit time across the same thickness, which is the sharpest form of the "
                     "statement that these are different quantities",
                     ThreeRoutes::saturates(ThreeRoutes::Route::Wave, kind, centre, c, mu,
                                            transverse) !=
                         ThreeRoutes::saturates(ThreeRoutes::Route::PointBody, kind, centre, c, mu,
                                                transverse));
    }

}
