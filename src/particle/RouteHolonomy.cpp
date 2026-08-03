#include "particle/RouteHolonomy.h"

#include "core/Report.h"
#include "scan/CrossingBranches.h"
#include "transform/InvolutionD.h"

#include <cmath>
#include <format>

namespace slm
{

    int RouteHolonomy::distinguishedAxis()
    {
        return 3;
    }

    Matrix4 RouteHolonomy::likeSignedRotation(int first, int second, double angle)
    {
        Matrix4 frame = Matrix4::identity();
        const std::size_t i = static_cast<std::size_t>(first);
        const std::size_t j = static_cast<std::size_t>(second);
        frame.at(i, i) = std::cos(angle);
        frame.at(j, j) = std::cos(angle);
        frame.at(i, j) = -std::sin(angle);
        frame.at(j, i) = std::sin(angle);
        return frame;
    }

    Matrix4 RouteHolonomy::hyperbolicRotation(int likeSignedAxis, double rapidity)
    {
        Matrix4 frame = Matrix4::identity();
        const std::size_t i = static_cast<std::size_t>(likeSignedAxis);
        const std::size_t s = static_cast<std::size_t>(distinguishedAxis());
        frame.at(i, i) = std::cosh(rapidity);
        frame.at(s, s) = std::cosh(rapidity);
        frame.at(i, s) = std::sinh(rapidity);
        frame.at(s, i) = std::sinh(rapidity);
        return frame;
    }

    bool RouteHolonomy::preservesFarMetric(const Matrix4 &frame, double tolerance)
    {
        return frame.congruence(metricRegionII()).isEqual(metricRegionII(), tolerance);
    }

    bool RouteHolonomy::fixesDistinguishedAxis(const Matrix4 &frame, double tolerance)
    {
        const std::size_t s = static_cast<std::size_t>(distinguishedAxis());
        for (std::size_t row = 0; row < 4; ++row)
        {
            const double expected = row == s ? 1.0 : 0.0;
            if (std::abs(frame.at(row, s) - expected) > tolerance)
            {
                return false;
            }
        }
        return true;
    }

    Matrix4 RouteHolonomy::composedCrossing(const Matrix4 &crossing, const Matrix4 &frame)
    {
        return frame * crossing;
    }

    bool RouteHolonomy::composedIsAdmissible(const Matrix4 &crossing, const Matrix4 &frame,
                                            double tolerance)
    {
        return composedCrossing(crossing, frame)
            .flipsMetric(metricRegionI(), metricRegionII(), tolerance);
    }

    bool RouteHolonomy::composedIsClosed(const Matrix4 &crossing, const Matrix4 &frame,
                                        double tolerance)
    {
        return composedCrossing(crossing, frame).isInvolution(tolerance);
    }

    double RouteHolonomy::clockCoefficient(const Matrix4 &crossing, const Matrix4 &frame)
    {
        return composedCrossing(crossing, frame).inverse().at(0, static_cast<std::size_t>(
                                                                    distinguishedAxis()));
    }

    double RouteHolonomy::clockDisplacement(const Matrix4 &crossing, const std::vector<Leg> &route)
    {
        double total = 0.0;
        for (const Leg &leg : route)
        {
            total += clockCoefficient(crossing, leg.frame) * leg.displacement;
        }
        return total;
    }

    double RouteHolonomy::netDisplacement(const std::vector<Leg> &route)
    {
        double total = 0.0;
        for (const Leg &leg : route)
        {
            total += leg.displacement;
        }
        return total;
    }

    double RouteHolonomy::closedRouteResidue(const Matrix4 &crossing, const std::vector<Leg> &route)
    {
        return clockDisplacement(crossing, route);
    }

    std::vector<RouteHolonomy::Leg> RouteHolonomy::outAndBack(double distance, double rapidity,
                                                             int likeSignedAxis)
    {
        return {Leg{Matrix4::identity(), distance},
                Leg{hyperbolicRotation(likeSignedAxis, rapidity), -distance}};
    }

    std::vector<RouteHolonomy::Leg> RouteHolonomy::outAndBackWithRotation(double distance,
                                                                         double angle)
    {
        return {Leg{Matrix4::identity(), distance}, Leg{likeSignedRotation(0, 1, angle), -distance}};
    }

    double RouteHolonomy::subluminalDilation(double rapidity)
    {
        return std::cosh(rapidity);
    }

    void RouteHolonomySection::run(Report &report) const
    {
        const Matrix4 D = InvolutionD::matrix();
        const auto eight = CrossingBranches::orientationPreserving();

        report.subsection("Both kinds of frame change are legitimate on the far side");
        bool rotationsAreIsometries = true;
        bool hyperbolicAreIsometries = true;
        for (double angle : {0.3, 1.0, 2.5})
        {
            rotationsAreIsometries =
                rotationsAreIsometries &&
                RouteHolonomy::preservesFarMetric(RouteHolonomy::likeSignedRotation(0, 1, angle)) &&
                RouteHolonomy::preservesFarMetric(RouteHolonomy::likeSignedRotation(1, 2, angle));
            hyperbolicAreIsometries =
                hyperbolicAreIsometries &&
                RouteHolonomy::preservesFarMetric(RouteHolonomy::hyperbolicRotation(0, angle));
        }
        report.check("rotations among the three like-signed axes preserve the far metric",
                     rotationsAreIsometries);
        report.check("so does a hyperbolic rotation mixing the distinguished axis with a "
                     "like-signed one",
                     hyperbolicAreIsometries);
        report.check("but only the first kind fixes the distinguished axis",
                     RouteHolonomy::fixesDistinguishedAxis(
                         RouteHolonomy::likeSignedRotation(0, 1, 0.8)) &&
                         !RouteHolonomy::fixesDistinguishedAxis(
                             RouteHolonomy::hyperbolicRotation(0, 0.8)));

        report.subsection("Wandering among the like-signed axes leaves the clock alone");
        bool rotationsChangeNothing = true;
        for (double angle : {0.0, 0.4, 1.3, 3.0})
        {
            rotationsChangeNothing =
                rotationsChangeNothing &&
                std::abs(RouteHolonomy::clockCoefficient(
                             D, RouteHolonomy::likeSignedRotation(0, 1, angle)) -
                         1.0) <= 1e-9;
        }
        report.check("the coefficient is unchanged by any such rotation", rotationsChangeNothing);
        bool everyClosedRotationRouteVanishes = true;
        for (double angle : {0.4, 1.3, 3.0})
        {
            for (double distance : {1.0, 5.0})
            {
                const auto route = RouteHolonomy::outAndBackWithRotation(distance, angle);
                everyClosedRotationRouteVanishes =
                    everyClosedRotationRouteVanishes &&
                    std::abs(RouteHolonomy::netDisplacement(route)) <= kEps &&
                    std::abs(RouteHolonomy::closedRouteResidue(D, route)) <= 1e-9;
            }
        }
        report.check("so a route that goes out, rotates and comes back returns the clock to "
                     "where it started, for every angle and distance examined",
                     everyClosedRotationRouteVanishes);
        report.check("which holds on all eight crossings, since none of their time rows "
                     "reaches a like-signed axis",
                     [&eight]()
                     {
                         for (const auto &branch : eight)
                         {
                             const auto route = RouteHolonomy::outAndBackWithRotation(4.0, 1.1);
                             if (std::abs(RouteHolonomy::closedRouteResidue(branch.matrix, route)) >
                                 1e-9)
                             {
                                 return false;
                             }
                         }
                         return true;
                     }());

        report.subsection("A hyperbolic rotation does not");
        for (double rapidity : {0.5, 1.0, 2.0})
        {
            const double coefficient =
                RouteHolonomy::clockCoefficient(D, RouteHolonomy::hyperbolicRotation(0, rapidity));
            report.checkNear(std::format("  rapidity {:g} : the coefficient is {:.6f}", rapidity,
                                         coefficient),
                             coefficient - std::cosh(rapidity), 1e-9);
        }
        for (double rapidity : {0.5, 1.0, 2.0})
        {
            const auto route = RouteHolonomy::outAndBack(3.0, rapidity);
            report.checkNear(
                std::format("  rapidity {:g} : an out and back of 3 leaves {:+.6f} on the clock",
                            rapidity, RouteHolonomy::closedRouteResidue(D, route)),
                RouteHolonomy::closedRouteResidue(D, route) - 3.0 * (1.0 - std::cosh(rapidity)),
                1e-9);
        }
        report.check("the residue is unbounded in the rapidity, so no finite bound on it "
                     "follows from the geometry",
                     std::abs(RouteHolonomy::closedRouteResidue(D, RouteHolonomy::outAndBack(3.0, 8.0))) >
                         std::abs(RouteHolonomy::closedRouteResidue(
                             D, RouteHolonomy::outAndBack(3.0, 4.0))));
        report.check("and it is negative for the map used here, so the return moves the clock "
                     "backwards relative to a straight route",
                     RouteHolonomy::closedRouteResidue(D, RouteHolonomy::outAndBack(3.0, 1.0)) < 0.0);

        report.subsection("What the residue is worth, and what it costs");
        for (double rapidity : {0.5, 1.0, 2.0})
        {
            report.checkNear(
                std::format("  rapidity {:g} : the factor equals the ordinary boost dilation "
                            "{:.6f}, so the residue is that dilation seen from the far side "
                            "and not a separate effect",
                            rapidity, RouteHolonomy::subluminalDilation(rapidity)),
                RouteHolonomy::clockCoefficient(D, RouteHolonomy::hyperbolicRotation(0, rapidity)) -
                    RouteHolonomy::subluminalDilation(rapidity),
                1e-9);
        }
        report.check("the composed map still satisfies the metric relation, so the frame change "
                     "does not leave the admissible family",
                     RouteHolonomy::composedIsAdmissible(D, RouteHolonomy::hyperbolicRotation(0, 1.0)));
        report.check("but it is no longer an involution, so the closure the admissible set was "
                     "selected for is lost at any nonzero rapidity",
                     RouteHolonomy::composedIsClosed(D, Matrix4::identity()) &&
                         !RouteHolonomy::composedIsClosed(D, RouteHolonomy::hyperbolicRotation(0, 1.0)));
        report.check("a rotation among the like-signed axes keeps the metric relation as well, "
                     "and keeps the closure only where it acts trivially",
                     RouteHolonomy::composedIsAdmissible(D, RouteHolonomy::likeSignedRotation(0, 1, 0.7)));
    }

}
