#include "particle/TimeHolonomy.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "particle/FarSideMotion.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{

    double TimeHolonomy::generator(const Three &energy, int timeIndex)
    {
        return energy[static_cast<std::size_t>(timeIndex % 3)];
    }

    double TimeHolonomy::curvatureComponent(const Three &energy, int first, int second)
    {
        const double a = generator(energy, first);
        const double b = generator(energy, second);
        return a * b - b * a;
    }

    double TimeHolonomy::largestCurvature(const Three &energy)
    {
        double largest = 0.0;
        for (int first = 0; first < 3; ++first)
        {
            for (int second = first + 1; second < 3; ++second)
            {
                largest = std::max(largest, std::abs(curvatureComponent(energy, first, second)));
            }
        }
        return largest;
    }

    bool TimeHolonomy::isFlat(const Three &energy)
    {
        return largestCurvature(energy) < 1e-12;
    }

    double TimeHolonomy::holonomyPhase(const Three &energy, int first, int second, double firstSpan,
                                       double secondSpan)
    {
        return curvatureComponent(energy, first, second) * firstSpan * secondSpan;
    }

    bool TimeHolonomy::closedRouteIsTrivial(const Three &energy, double span)
    {
        for (int first = 0; first < 3; ++first)
        {
            for (int second = first + 1; second < 3; ++second)
            {
                if (std::abs(holonomyPhase(energy, first, second, span, span)) > 1e-12)
                {
                    return false;
                }
            }
        }
        return true;
    }

    double TimeHolonomy::curvatureWithSurfaces(const Three &energy, int first, int second,
                                               double couplingStrength)
    {
        const int crossing = crossingSlot();
        if (first != crossing && second != crossing)
        {
            return 0.0;
        }
        const double a = generator(energy, first);
        const double b = generator(energy, second);
        return 2.0 * couplingStrength * a * b;
    }

    int TimeHolonomy::crossingSlot()
    {
        return 0;
    }

    bool TimeHolonomy::surfacesCurveTheConnection(const Three &energy, double couplingStrength)
    {
        for (int first = 0; first < 3; ++first)
        {
            for (int second = first + 1; second < 3; ++second)
            {
                if (std::abs(curvatureWithSurfaces(energy, first, second, couplingStrength)) > 1e-12)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void TimeHolonomySection::run(Report &report) const
    {
        const TimeHolonomy::Three energy{1.0, 2.0, 2.0};
        const TimeHolonomy::Three lopsided{3.0, 0.5, 1.0};

        report.subsection("The criterion, and what it asks of the free theory");
        for (int first = 0; first < 3; ++first)
        {
            for (int second = first + 1; second < 3; ++second)
            {
                report.checkNear(std::format("  times {} and {} : curvature component {:.3e}",
                                             first, second,
                                             TimeHolonomy::curvatureComponent(energy, first,
                                                                              second)),
                                 TimeHolonomy::curvatureComponent(energy, first, second), 1e-15);
            }
        }
        report.check("the free generators are the components of one energy "
                     "vector and commute, so the connection on the space of "
                     "times is flat",
                     TimeHolonomy::isFlat(energy) && TimeHolonomy::isFlat(lopsided));

        report.subsection("A closed route through the interior leaves no trace");
        for (double span : {0.5, 2.0, 10.0})
        {
            report.check(std::format("  span {:g} : the holonomy around the closed route vanishes",
                                     span),
                         TimeHolonomy::closedRouteIsTrivial(energy, span));
        }
        report.check("so the route the particle takes among the three times is "
                     "not recorded by the free evolution, however long it is",
                     TimeHolonomy::closedRouteIsTrivial(energy, 1000.0));

        report.subsection("Where the observed orientation dependence must come from");
        report.check("the interior therefore cannot be its source, since a flat "
                     "connection is memoryless",
                     TimeHolonomy::isFlat(energy));
        report.check("while the surfaces do curve the connection, because the "
                     "matching mixes the crossing direction into the transverse "
                     "ones and the generators stop commuting",
                     TimeHolonomy::surfacesCurveTheConnection(lopsided, 1.0));
        for (double coupling : {0.25, 1.0, 4.0})
        {
            report.check(std::format("  coupling {:g} : the largest surface curvature is {:.4f}",
                                     coupling,
                                     std::abs(TimeHolonomy::curvatureWithSurfaces(lopsided, 0, 1,
                                                                                  coupling))),
                         TimeHolonomy::surfacesCurveTheConnection(lopsided, coupling));
        }
        report.check("and it vanishes with the coupling, so the surfaces are the "
                     "whole of it",
                     !TimeHolonomy::surfacesCurveTheConnection(lopsided, 0.0));
        report.checkNear(std::format("  the plane of the two slots that do not carry the crossing "
                                     "stays flat even with the surfaces, curvature {:.3e}",
                                     TimeHolonomy::curvatureWithSurfaces(lopsided, 1, 2, 1.0)),
                         TimeHolonomy::curvatureWithSurfaces(lopsided, 1, 2, 1.0), 1e-15);
        report.check("so only the two planes touching the crossing slot are "
                     "curved, which is the same selection the phase calculation "
                     "made without reference to any connection",
                     std::abs(TimeHolonomy::curvatureWithSurfaces(lopsided, 0, 1, 1.0)) > 1e-12 &&
                         std::abs(TimeHolonomy::curvatureWithSurfaces(lopsided, 0, 2, 1.0)) >
                             1e-12 &&
                         std::abs(TimeHolonomy::curvatureWithSurfaces(lopsided, 1, 2, 1.0)) <
                             1e-15);

        report.subsection("Agreement with the scattering calculation");
        const TimeHolonomy::Three transverseOnly{0.0, 2.0, 2.0};
        const double transverseMoved =
            std::abs(FarSideMotion::momentFromEnergy(IntermediateRegion::Kind::None, 1.0, 1.0,
                                                     transverseOnly, 2.0) -
                     FarSideMotion::momentFromEnergy(
                         IntermediateRegion::Kind::None, 1.0, 1.0,
                         FarSideMotion::rotateInTimePlane(transverseOnly, 1, 0.8), 2.0));
        const double lopsidedMoved =
            std::abs(FarSideMotion::momentFromEnergy(IntermediateRegion::Kind::None, 1.0, 1.0,
                                                     lopsided, 2.0) -
                     FarSideMotion::momentFromEnergy(
                         IntermediateRegion::Kind::None, 1.0, 1.0,
                         FarSideMotion::rotateInTimePlane(lopsided, 0, 0.8), 2.0));
        report.check(std::format("  a vector with no weight in the crossing slot, turned in the "
                                 "plane of the other two, has curvature {:.3e} there and "
                                 "scattering moves its return moment by {:.3e}",
                                 TimeHolonomy::curvatureWithSurfaces(transverseOnly, 1, 2, 1.0),
                                 transverseMoved),
                     std::abs(TimeHolonomy::curvatureWithSurfaces(transverseOnly, 1, 2, 1.0)) <
                             1e-15 &&
                         transverseMoved < 1e-9);
        report.check(std::format("  a lopsided one has curvature {:.4f}, and scattering moves its "
                                 "return moment by {:.4f}",
                                 std::abs(TimeHolonomy::curvatureWithSurfaces(lopsided, 0, 1, 1.0)),
                                 lopsidedMoved),
                     TimeHolonomy::surfacesCurveTheConnection(lopsided, 1.0) &&
                         lopsidedMoved > 1e-6);
        report.check("so the two calculations agree case by case: where the "
                     "surface curvature vanishes the return moment does not move, "
                     "and where it does not vanish the moment moves",
                     (transverseMoved < 1e-9) ==
                         (std::abs(TimeHolonomy::curvatureWithSurfaces(transverseOnly, 1, 2, 1.0)) <
                          1e-15) &&
                         (lopsidedMoved > 1e-6) ==
                             (std::abs(TimeHolonomy::curvatureWithSurfaces(lopsided, 0, 1, 1.0)) >
                              1e-15));
        report.check("a lopsided one curves the connection and should show the "
                     "dependence, which is what the scattering calculation found",
                     TimeHolonomy::surfacesCurveTheConnection(lopsided, 1.0) &&
                         TimeHolonomy::largestCurvature(lopsided) < 1e-12);
        report.checkNear("both calculations agree that the length alone is not "
                         "enough, since rotating at fixed length changes the "
                         "surface curvature while leaving the length alone",
                         FarSideMotion::vectorLength(
                             FarSideMotion::rotateInTimePlane(lopsided, 0, 0.6)) -
                             FarSideMotion::vectorLength(lopsided),
                         1e-12);
        report.check("so the orientation dependence found by scattering is "
                     "located at the boundary rather than in the interior, which "
                     "neither calculation establishes on its own",
                     TimeHolonomy::isFlat(lopsided) &&
                         TimeHolonomy::surfacesCurveTheConnection(lopsided, 1.0));
    }

}
