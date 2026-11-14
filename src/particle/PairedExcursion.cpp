#include "particle/PairedExcursion.h"

#include "core/Report.h"
#include "physics/mechanism/ThresholdWall.h"
#include "particle/TimeProjection.h"
#include "physics/units/PhysicalScales.h"

#include <cmath>
#include <format>

namespace slm
{
    double PairedExcursion::mapContribution(double metres, Sense sense)
    {
        const double magnitude = PhysicalScales::advanceForDistance(metres);
        return sense == Sense::PlusR ? -magnitude : magnitude;
    }

    double PairedExcursion::singleCrossingDelay(double wallWidth, double tolerance, double beta)
    {
        const double distance = ThresholdWall::distanceToReach(wallWidth, tolerance);
        return PhysicalScales::advanceForDistance(distance / beta);
    }

    double PairedExcursion::roundTripDelay(double wallWidth, double tolerance, double beta)
    {
        return 2.0 * singleCrossingDelay(wallWidth, tolerance, beta);
    }

    double PairedExcursion::netShift(double metres, Sense sense, double wallWidth,
                                     double tolerance, double beta)
    {
        return mapContribution(metres, sense) + roundTripDelay(wallWidth, tolerance, beta);
    }

    double PairedExcursion::breakEvenDistance(double wallWidth, double tolerance, double beta)
    {
        return 2.0 * ThresholdWall::distanceToReach(wallWidth, tolerance) / beta;
    }

    double PairedExcursion::separation(double metres)
    {
        return 2.0 * PhysicalScales::advanceForDistance(metres);
    }

    double PairedExcursion::delayMismatch(double wallWidth, double tolerance, double firstBeta,
                                          double secondBeta)
    {
        return roundTripDelay(wallWidth, tolerance, firstBeta) -
               roundTripDelay(wallWidth, tolerance, secondBeta);
    }
}
