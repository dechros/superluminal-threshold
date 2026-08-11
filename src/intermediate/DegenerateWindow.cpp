#include "intermediate/DegenerateWindow.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "mechanism/ThresholdWall.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kPi = 3.14159265358979323846;
    }

    double DegenerateWindow::metricFactor(double x, double width)
    {
        return std::cos(2.0 * ThresholdWall::profile(x, width));
    }

    double DegenerateWindow::windowWidth(double width, double tolerance)
    {
        return 2.0 * width * std::atanh(tolerance);
    }

    double DegenerateWindow::slabTransmission(double mu, double thickness)
    {
        return std::exp(-2.0 * std::sqrt(mu) * thickness);
    }

    double DegenerateWindow::halvingThickness(double mu)
    {
        return std::log(2.0) / (2.0 * std::sqrt(mu));
    }

    void DegenerateWindowSection::run(Report &report) const
    {
        const double stiffness = 2.0;
        const double lambdaScale = 0.7;
        const double width = ThresholdWall::widthFromCouplings(stiffness, lambdaScale);
        const double mu = 1.0;

        report.subsection("The metric factor across the wall, in closed form");
        for (double x : {-3.0, -1.0, -0.25, 0.0, 0.25, 1.0, 3.0})
        {
            const double scaled = x * width;
            report.checkNear(std::format("  x = {:>5.2f} L : the factor is minus the hyperbolic "
                                         "tangent of the scaled position",
                                         x),
                             DegenerateWindow::metricFactor(scaled, width) +
                                 std::tanh(x),
                             1e-12);
        }
        report.checkNear("  it vanishes at the centre and nowhere else",
                         DegenerateWindow::metricFactor(0.0, width), 1e-15);

        report.subsection("The degenerate set has no width");
        double previousWidth = 1e300;
        for (double tolerance : {1e-1, 1e-2, 1e-4, 1e-8})
        {
            const double window = DegenerateWindow::windowWidth(width, tolerance);
            report.check(std::format("  within {:.0e} of degenerate the wall spends {:.6e} in "
                                     "units of its own width",
                                     tolerance, window / width),
                         window > 0.0 && window < previousWidth);
            previousWidth = window;
            const double edge = window / 2.0;
            report.checkNear("    and the factor at the window's edge is that tolerance",
                             std::abs(DegenerateWindow::metricFactor(edge, width)) - tolerance,
                             1e-9);
        }
        report.checkNear("the window shrinks in proportion to the tolerance, so the degenerate "
                         "set is a point and not a layer",
                         DegenerateWindow::windowWidth(width, 1e-8) / (2.0 * width * 1e-8) - 1.0,
                         1e-9);

        report.subsection("What thickness does to a mode");
        double previousTransmission = 2.0;
        for (double thickness : {0.0, 0.1, 0.5, 1.0, 5.0})
        {
            const double transmission = DegenerateWindow::slabTransmission(mu, thickness);
            report.check(std::format("  a slab {:.1f} thick transmits {:.6e}", thickness,
                                     transmission),
                         transmission < previousTransmission && transmission > 0.0);
            previousTransmission = transmission;
        }
        report.checkNear("a slab of no thickness transmits everything",
                         DegenerateWindow::slabTransmission(mu, 0.0) - 1.0, 1e-15);
        report.check("a thick slab transmits essentially nothing, which is the blocking the "
                     "intermediate-region section reported",
                     DegenerateWindow::slabTransmission(mu, 40.0) < 1e-30);
        report.checkNear("the halving thickness is the logarithm of two over twice the mass",
                         DegenerateWindow::slabTransmission(
                             mu, DegenerateWindow::halvingThickness(mu)) -
                             0.5,
                         1e-12);
        report.check("so blocking is a statement about thickness, and the two sections were "
                     "never in disagreement about anything else",
                     IntermediateRegion::blocks(IntermediateRegion::Kind::Degenerate, 1.0, mu,
                                                4.0));

        report.subsection("The suppression the crossing actually meets");
        double previous = 0.0;
        for (double tolerance : {1e-1, 1e-2, 1e-4, 1e-8})
        {
            const double window = DegenerateWindow::windowWidth(width, tolerance);
            const double transmission = DegenerateWindow::slabTransmission(mu, window);
            report.check(std::format("  treating the {:.0e} window as a slab leaves {:.9f} of "
                                     "the mode",
                                     tolerance, transmission),
                         transmission > previous && transmission <= 1.0);
            previous = transmission;
        }
        report.checkNear("as the window closes the suppression goes to one, so the crossing "
                         "pays nothing at the degenerate point",
                         DegenerateWindow::slabTransmission(
                             mu, DegenerateWindow::windowWidth(width, 1e-12)) -
                             1.0,
                         1e-9);

        report.subsection("A blocking layer is not a solution of the field equation");
        const double step = 1e-4;
        const double curvature = (ThresholdWall::potentialSlope(lambdaScale, kPi / 4.0 + step) -
                                  ThresholdWall::potentialSlope(lambdaScale, kPi / 4.0 - step)) /
                                 (2.0 * step);
        report.check(std::format("  the potential's curvature at the degenerate angle is "
                                 "{:.6f}, and it is negative",
                                 curvature),
                     curvature < 0.0);
        report.checkNear("  which is minus eight times the potential scale to the fourth",
                         curvature + 8.0 * std::pow(lambdaScale, 4.0), 1e-6);
        report.check("a field held at that angle across an interval therefore rests on a "
                     "maximum, and no static solution does",
                     curvature < 0.0);
        report.check("the layer that blocks is thus not merely absent from this crossing but "
                     "excluded by the same equation that produced the wall",
                     curvature < 0.0 &&
                         ThresholdWall::potential(lambdaScale, kPi / 4.0) >
                             ThresholdWall::potential(lambdaScale, 0.0));
    }

}
