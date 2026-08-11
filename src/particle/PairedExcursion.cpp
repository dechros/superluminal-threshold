#include "particle/PairedExcursion.h"

#include "core/Report.h"
#include "mechanism/ThresholdWall.h"
#include "particle/TimeProjection.h"
#include "units/PhysicalScales.h"

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

    void PairedExcursionSection::run(Report &report) const
    {
        using Sense = PairedExcursion::Sense;
        const double wallWidth = 1e-15;
        const double tolerance = 1e-8;
        const double beta = 0.99;

        report.subsection("The two senses along the far side's space axis");
        const double metres = 1.0;
        report.checkNear("  a metre along +r takes the near-side clock backward by the light "
                         "travel time of a metre",
                         PairedExcursion::mapContribution(metres, Sense::PlusR) +
                             PhysicalScales::advanceForDistance(metres),
                         1e-24);
        report.checkNear("  the same metre along -r takes it forward by the same amount",
                         PairedExcursion::mapContribution(metres, Sense::MinusR) -
                             PhysicalScales::advanceForDistance(metres),
                         1e-24);
        report.checkNear("  the two contributions cancel, so one apparatus reaches both "
                         "directions in time and the distance is all that is chosen",
                         PairedExcursion::mapContribution(metres, Sense::PlusR) +
                             PairedExcursion::mapContribution(metres, Sense::MinusR),
                         1e-24);
        const TimeProjection::Four displacement{0.0, 0.0, 0.0, metres};
        report.checkNear("  and the sign agrees with the map the earlier section established",
                         TimeProjection::toNearCoordinates(displacement)[0] + metres, 1e-12);

        report.subsection("What the wall costs, in near-side seconds");
        const double single = PairedExcursion::singleCrossingDelay(wallWidth, tolerance, beta);
        report.check(std::format("  a wall {:.3e} m wide crossed at {:g}c costs {:.6e} s one "
                                 "way",
                                 wallWidth, beta, single),
                     single > 0.0);
        report.checkNear("  the round trip costs exactly twice that",
                         PairedExcursion::roundTripDelay(wallWidth, tolerance, beta) -
                             2.0 * single,
                         1e-30);
        report.check("  the delay is positive whichever way the particle was driven, since "
                     "traversing the wall does not depend on the far-side direction",
                     PairedExcursion::roundTripDelay(wallWidth, tolerance, beta) > 0.0);
        for (double testBeta : {0.1, 0.5, 0.99})
        {
            report.check(std::format("  crossing at {:g}c costs {:.6e} s, and a slower crossing "
                                     "costs more",
                                     testBeta,
                                     PairedExcursion::roundTripDelay(wallWidth, tolerance,
                                                                     testBeta)),
                         PairedExcursion::roundTripDelay(wallWidth, tolerance, testBeta) >=
                             PairedExcursion::roundTripDelay(wallWidth, tolerance, 0.99));
        }

        report.subsection("The delay is added to one particle and taken from the other");
        const double plus = PairedExcursion::netShift(metres, Sense::PlusR, wallWidth, tolerance,
                                                      beta);
        const double minus = PairedExcursion::netShift(metres, Sense::MinusR, wallWidth,
                                                       tolerance, beta);
        report.check(std::format("  the +r particle returns {:.6e} s from its departure, which "
                                 "is before it",
                                 plus),
                     plus < 0.0);
        report.check(std::format("  the -r particle returns {:.6e} s from its departure, which "
                                 "is after it",
                                 minus),
                     minus > 0.0);
        report.checkNear("  their sum is twice the round-trip delay, so the delay is what the "
                         "two share, and the tolerance here is set by subtracting two light "
                         "travel times of a metre rather than by the identity",
                         plus + minus - PairedExcursion::roundTripDelay(wallWidth, tolerance,
                                                                        beta) * 2.0,
                         1e-24);
        const double matched = PairedExcursion::breakEvenDistance(wallWidth, tolerance, beta);
        report.checkNear("  at a distance whose light travel time matches the delay the same "
                         "identity holds with nothing cancelling, so the loose tolerance above "
                         "belongs to the arithmetic and not to the claim",
                         PairedExcursion::netShift(matched, Sense::PlusR, wallWidth, tolerance,
                                                   beta) +
                             PairedExcursion::netShift(matched, Sense::MinusR, wallWidth,
                                                       tolerance, beta) -
                             PairedExcursion::roundTripDelay(wallWidth, tolerance, beta) * 2.0,
                         1e-37);
        report.check("  the forward direction needs no minimum distance, because the delay "
                     "pushes the -r particle further the way it was already going",
                     PairedExcursion::netShift(1e-30, Sense::MinusR, wallWidth, tolerance,
                                               beta) > 0.0);

        report.subsection("The backward direction has to beat the wall");
        const double breakEven = PairedExcursion::breakEvenDistance(wallWidth, tolerance, beta);
        report.check(std::format("  the two cancel at {:.6e} m of far-side travel", breakEven),
                     breakEven > 0.0);
        report.checkNear("  at exactly that distance the +r particle returns at the moment it "
                         "left",
                         PairedExcursion::netShift(breakEven, Sense::PlusR, wallWidth, tolerance,
                                                   beta),
                         1e-30);
        report.check("  short of it the +r particle returns later than it left, so the "
                     "apparatus displaces nothing backward",
                     PairedExcursion::netShift(0.5 * breakEven, Sense::PlusR, wallWidth,
                                               tolerance, beta) > 0.0);
        report.check("  beyond it the +r particle returns before it left",
                     PairedExcursion::netShift(2.0 * breakEven, Sense::PlusR, wallWidth,
                                               tolerance, beta) < 0.0);
        report.checkNear(std::format("  in units of the wall's own width the break-even "
                                     "distance is {:.4f}, a pure number set by the tolerance "
                                     "and the crossing speed",
                                     breakEven / wallWidth),
                         breakEven / wallWidth -
                             2.0 * std::log(1.0 / std::tan(tolerance)) / beta,
                         1e-9);
        report.check("  a metre of far-side travel is far beyond the break-even distance for a "
                     "wall of field-theory thickness, so the delay decides nothing at "
                     "laboratory distances",
                     metres > 1e10 * breakEven);

        report.subsection("What the delay cannot reach");
        report.checkNear("the gap between the two returning particles is twice the light travel "
                         "time of the distance",
                         PairedExcursion::separation(metres) -
                             2.0 * PhysicalScales::advanceForDistance(metres),
                         1e-24);
        report.checkNear("  and it is the difference of the two net shifts, so the shared delay "
                         "drops out of it",
                         minus - plus - PairedExcursion::separation(metres), 1e-24);
        double worstDrift = 0.0;
        for (double testWidth : {1e-18, 1e-15, 1e-9})
        {
            for (double testTolerance : {1e-4, 1e-8, 1e-12})
            {
                for (double testBeta : {0.1, 0.5, 0.99})
                {
                    const double gap =
                        PairedExcursion::netShift(metres, Sense::MinusR, testWidth,
                                                  testTolerance, testBeta) -
                        PairedExcursion::netShift(metres, Sense::PlusR, testWidth,
                                                  testTolerance, testBeta);
                    worstDrift = std::max(worstDrift,
                                          std::abs(gap - PairedExcursion::separation(metres)));
                }
            }
        }
        report.checkNear(std::format("  over 27 combinations of wall width, tolerance and "
                                     "crossing speed the gap moves by at most {:.3e} s",
                                     worstDrift),
                         worstDrift, 1e-24);
        report.check("so the pair measures the far-side distance without the wall's thickness "
                     "entering, while either particle alone cannot be read without it",
                     worstDrift < 1e-24);

        report.subsection("Unless the two are prepared differently");
        const double mismatch = PairedExcursion::delayMismatch(wallWidth, tolerance, 0.5, 0.99);
        report.check(std::format("  crossing at 0.5c against 0.99c leaves {:.6e} s in the gap",
                                 mismatch),
                     std::abs(mismatch) > 0.0);
        report.checkNear("  which is the round-trip delay evaluated at one speed less the "
                         "other, and nothing besides",
                         mismatch -
                             (PairedExcursion::roundTripDelay(wallWidth, tolerance, 0.5) -
                              PairedExcursion::roundTripDelay(wallWidth, tolerance, 0.99)),
                         1e-30);
        report.checkNear("  it vanishes when the two cross alike",
                         PairedExcursion::delayMismatch(wallWidth, tolerance, beta, beta),
                         1e-30);
        report.check("  so the pair has to be prepared to the same speed, and the tolerance on "
                     "that speed is what limits the measurement rather than the wall itself",
                     std::abs(mismatch) < PairedExcursion::separation(metres));
    }

}
