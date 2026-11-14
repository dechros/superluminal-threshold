#include "physics/intermediate/DegenerateWindow.h"

#include "core/Report.h"
#include "physics/intermediate/IntermediateRegion.h"
#include "physics/mechanism/ThresholdWall.h"

#include <cmath>
#include <numbers>
#include <format>

namespace slm
{

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
}
