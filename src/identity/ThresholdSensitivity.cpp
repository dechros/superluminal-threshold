#include "identity/ThresholdSensitivity.h"

#include "sim/PacketSimulation.h"
#include "sim/WavePacketField.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace slm
{
    const std::vector<double> &ThresholdSensitivity::massGrid()
    {
        static const std::vector<double> grid = {0.25, 0.5, 1.0, 2.0, 3.0};
        return grid;
    }

    const std::vector<double> &ThresholdSensitivity::extentGrid()
    {
        static const std::vector<double> grid = {0.005, 0.01, 0.02, 0.04, 0.08};
        return grid;
    }

    double ThresholdSensitivity::predictedDelayAtMass(double mass, IntermediateRegion::Kind kind,
                                                       double c, double transverseSquared,
                                                       double thickness, double centre)
    {
        return PacketSimulation::predictedDelay(kind, c, mass, transverseSquared, thickness,
                                                centre);
    }

    double ThresholdSensitivity::measuredThresholdAtMass(double mass,
                                                          IntermediateRegion::Kind kind, double c,
                                                          double transverseSquared,
                                                          double thickness, double centre,
                                                          double spread, int samples)
    {
        return PacketSimulation::measuredThreshold(kind, c, mass, transverseSquared, thickness, -1,
                                                   centre, spread, samples);
    }

    bool ThresholdSensitivity::thresholdGrowsWithMass(IntermediateRegion::Kind kind, double c,
                                                       double transverseSquared, double thickness,
                                                       double centre, double spread, int samples)
    {
        double previous = -std::numeric_limits<double>::infinity();
        for (double mass : massGrid())
        {
            const double value = measuredThresholdAtMass(mass, kind, c, transverseSquared,
                                                         thickness, centre, spread, samples);
            if (!(value > previous))
            {
                return false;
            }
            previous = value;
        }
        return true;
    }

    bool ThresholdSensitivity::saturationHoldsAtMass(double mass, IntermediateRegion::Kind kind,
                                                      double c, double transverseSquared,
                                                      double centre, double spread, int samples,
                                                      double tolerance)
    {
        const double thin = measuredThresholdAtMass(mass, kind, c, transverseSquared, 8.0, centre,
                                                    spread, samples);
        const double thick = measuredThresholdAtMass(mass, kind, c, transverseSquared, 16.0, centre,
                                                     spread, samples);
        if (std::abs(thin) <= 0.0)
        {
            return false;
        }
        return std::abs(thick - thin) / std::abs(thin) < tolerance;
    }

    double ThresholdSensitivity::largestAdmissibleMass(double c, double transverseSquared,
                                                        double centre)
    {
        return centre * centre / (c * c) - transverseSquared;
    }

    bool ThresholdSensitivity::propagatesOutside(double mass, double c, double transverseSquared,
                                                  double centre)
    {
        return mass < largestAdmissibleMass(c, transverseSquared, centre);
    }

    double ThresholdSensitivity::largestAdmissibleExtent(double c, double mu,
                                                          double transverseSquared, double centre,
                                                          double reach)
    {
        if (reach <= 0.0)
        {
            return 0.0;
        }
        const double floorFrequency =
            WavePacketField::lowestPropagatingFrequency(c, mu, transverseSquared);
        const double headroom = centre - floorFrequency;
        return headroom > 0.0 ? headroom / reach : 0.0;
    }

    bool ThresholdSensitivity::extentIsAdmissible(double spread, double c, double mu,
                                                   double transverseSquared, double centre,
                                                   double reach)
    {
        return spread < largestAdmissibleExtent(c, mu, transverseSquared, centre, reach);
    }

    bool ThresholdSensitivity::thresholdGrowsWithExtent(IntermediateRegion::Kind kind, double c,
                                                         double mu, double transverseSquared,
                                                         double thickness, double centre,
                                                         int samples)
    {
        double previous = -std::numeric_limits<double>::infinity();
        for (double width : extentGrid())
        {
            const double value = measuredThresholdAtExtent(width, kind, c, mu, transverseSquared,
                                                           thickness, centre, samples);
            if (!(value > previous))
            {
                return false;
            }
            previous = value;
        }
        return true;
    }

    double ThresholdSensitivity::measuredThresholdAtExtent(double spread,
                                                            IntermediateRegion::Kind kind, double c,
                                                            double mu, double transverseSquared,
                                                            double thickness, double centre,
                                                            int samples)
    {
        return PacketSimulation::measuredThreshold(kind, c, mu, transverseSquared, thickness, -1,
                                                   centre, spread, samples);
    }

    double ThresholdSensitivity::thresholdVariationOverExtent(IntermediateRegion::Kind kind,
                                                               double c, double mu,
                                                               double transverseSquared,
                                                               double thickness, double centre,
                                                               int samples)
    {
        double smallest = std::numeric_limits<double>::infinity();
        double largest = -std::numeric_limits<double>::infinity();
        for (double spread : extentGrid())
        {
            const double value = measuredThresholdAtExtent(spread, kind, c, mu, transverseSquared,
                                                           thickness, centre, samples);
            smallest = std::min(smallest, value);
            largest = std::max(largest, value);
        }
        if (!std::isfinite(smallest) || std::abs(smallest) <= 0.0)
        {
            return 0.0;
        }
        return (largest - smallest) / std::abs(smallest);
    }

}
