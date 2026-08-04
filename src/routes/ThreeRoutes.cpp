#include "routes/ThreeRoutes.h"

#include "boundary/JunctionFamily.h"
#include "core/Report.h"
#include "intermediate/DwellTime.h"
#include "intermediate/TraversalClocks.h"
#include "intermediate/TwoCrossings.h"
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
            return 0.5 * TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared,
                                                   thickness);
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
        const double claimed =
            thresholdFromRoute(route, kind, centre, c, mu, transverseSquared, thickness);
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

    ThreeRoutes::Grid ThreeRoutes::grid(IntermediateRegion::Kind kind, double c, double mu,
                                        double transverseSquared, double thickness, double centre,
                                        double spread, int samples, double tolerance)
    {
        const auto requirements = JunctionFamily::all();
        const auto routes = all();
        const SurfaceLayer::Profile shape = SurfaceLayer::Profile::Linear;

        Grid counts{};
        counts.cells = static_cast<int>(requirements.size() * routes.size());

        std::vector<double> readings;
        for (JunctionFamily::Requirement requirement : requirements)
        {
            const bool applicable = JunctionFamily::isApplicable(requirement, shape);
            const bool admits = applicable && JunctionFamily::fixesMatching(requirement) &&
                                JunctionFamily::admitsOutgoingOnly(requirement);
            for (Route route : routes)
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
                const double value =
                    roundTripReading(route, kind, centre, c, mu, transverseSquared, thickness);
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
                if (reproducesMeasurement(route, kind, c, mu, transverseSquared, thickness, centre,
                                          spread, samples, tolerance))
                {
                    ++counts.placingTheReturn;
                }
            }
        }
        counts.distinctReadings = static_cast<int>(readings.size());
        return counts;
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
        const ThreeRoutes::Grid counts = ThreeRoutes::grid(kind, c, mu, transverse, thickness,
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
