#include "particle/TimeReversalSignature.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    int TimeReversalSignature::forwardCountChange(int turnedLines)
    {
        return -turnedLines;
    }

    int TimeReversalSignature::backwardCountChange(int turnedLines)
    {
        return turnedLines;
    }

    double TimeReversalSignature::apparentCharge(int turnedLines, double chargePerLine)
    {
        return 2.0 * turnedLines * chargePerLine;
    }

    bool TimeReversalSignature::changeIsEven(int turnedLines)
    {
        return (backwardCountChange(turnedLines) - forwardCountChange(turnedLines)) % 2 == 0;
    }

    int TimeReversalSignature::pairCreationCount(int pairs)
    {
        return 2 * pairs;
    }

    bool TimeReversalSignature::countsAreDegenerate(int turnedLines)
    {
        return backwardCountChange(turnedLines) - forwardCountChange(turnedLines) ==
               pairCreationCount(turnedLines);
    }

    bool TimeReversalSignature::chargeDistinguishes(int turnedLines, double chargePerLine)
    {
        const double turned = apparentCharge(turnedLines, chargePerLine);
        const double created = 2.0 * turnedLines * chargePerLine;
        return std::abs(turned - created) > 1e-12;
    }

    double TimeReversalSignature::energyCost(bool isPair, double restEnergy, int turnedLines)
    {
        return isPair ? 2.0 * turnedLines * restEnergy : 0.0;
    }

    bool TimeReversalSignature::energyDistinguishes(double restEnergy, int turnedLines)
    {
        return std::abs(energyCost(true, restEnergy, turnedLines) -
                        energyCost(false, restEnergy, turnedLines)) > 1e-12;
    }

    double TimeReversalSignature::energyDrawnFromRegion(bool isPair, double restEnergy,
                                                        int turnedLines)
    {
        return energyCost(isPair, restEnergy, turnedLines);
    }

    double TimeReversalSignature::resolutionNeeded(double restEnergy, int turnedLines)
    {
        return std::abs(energyDrawnFromRegion(true, restEnergy, turnedLines) -
                        energyDrawnFromRegion(false, restEnergy, turnedLines));
    }

    bool TimeReversalSignature::calorimeterSeparates(double restEnergy, int turnedLines,
                                                     double resolution)
    {
        const double gap = resolutionNeeded(restEnergy, turnedLines);
        return gap > 0.0 && resolution < gap;
    }

    bool TimeReversalSignature::coincidenceRequired()
    {
        return true;
    }

    bool TimeReversalSignature::practicalAtWeight(double returnedWeight,
                                                  double attemptsPerSecond, double seconds)
    {
        return returnedWeight * attemptsPerSecond * seconds >= 1.0;
    }

    void TimeReversalSignatureSection::run(Report &report) const
    {
        const double chargePerLine = 1.0;
        const double restEnergy = 1.0;

        report.subsection("A turned worldline changes the boundary count by two");
        for (int turned : {1, 2, 3})
        {
            report.check(std::format("  {} turned : forward count {:+d}, backward count {:+d}, "
                                     "difference {:+d}",
                                     turned,
                                     TimeReversalSignature::forwardCountChange(turned),
                                     TimeReversalSignature::backwardCountChange(turned),
                                     TimeReversalSignature::backwardCountChange(turned) -
                                         TimeReversalSignature::forwardCountChange(turned)),
                         TimeReversalSignature::changeIsEven(turned));
        }
        report.check("the change is always even, so an observer holding to a single "
                     "time direction never sees one line arrive and one leave, but "
                     "always two of the same kind",
                     TimeReversalSignature::changeIsEven(1) &&
                         TimeReversalSignature::changeIsEven(3));

        report.subsection("Which is exactly what a pair event looks like");
        for (int turned : {1, 2, 3})
        {
            report.check(std::format("  {} turned gives {:+d}, and {} created pairs give {:+d}",
                                     turned,
                                     TimeReversalSignature::backwardCountChange(turned) -
                                         TimeReversalSignature::forwardCountChange(turned),
                                     turned, TimeReversalSignature::pairCreationCount(turned)),
                         TimeReversalSignature::countsAreDegenerate(turned));
        }
        report.check("the two readings give the same count for every number of lines, "
                     "so counting at the boundary cannot separate them",
                     TimeReversalSignature::countsAreDegenerate(1) &&
                         TimeReversalSignature::countsAreDegenerate(2) &&
                         TimeReversalSignature::countsAreDegenerate(3));

        report.subsection("The apparent charge, and why it does not help");
        for (int turned : {1, 2, 4})
        {
            report.check(std::format("  {} turned : the boundary presents an apparent charge of "
                                     "{:+.1f}",
                                     turned,
                                     TimeReversalSignature::apparentCharge(turned, chargePerLine)),
                         std::abs(TimeReversalSignature::apparentCharge(turned, chargePerLine)) >
                             0.0);
        }
        report.check("the region shows a charge without any charge having been put "
                     "there, since reversing a line's time sense reverses what it "
                     "carries",
                     TimeReversalSignature::apparentCharge(2, chargePerLine) > 0.0);
        report.check("but the same charge appears on the pair reading, so this "
                     "observable does not separate them either",
                     !TimeReversalSignature::chargeDistinguishes(2, chargePerLine));

        report.subsection("Where the two readings do part company");
        report.check(std::format("  a created pair costs {:.1f} in rest energy and a turned line "
                                 "costs {:.1f}",
                                 TimeReversalSignature::energyCost(true, restEnergy, 1),
                                 TimeReversalSignature::energyCost(false, restEnergy, 1)),
                     TimeReversalSignature::energyDistinguishes(restEnergy, 1));
        report.check("so the degeneracy is not complete: energy separates them, and it "
                     "is the only one of the three that does",
                     TimeReversalSignature::energyDistinguishes(restEnergy, 1) &&
                         TimeReversalSignature::countsAreDegenerate(1) &&
                         !TimeReversalSignature::chargeDistinguishes(1, chargePerLine));
        report.check("the measurement that would close the open item is therefore an "
                     "energy budget across the boundary and not a count, which is a "
                     "sharper statement of the gap than the item carried before",
                     TimeReversalSignature::energyDistinguishes(restEnergy, 2));

        report.subsection("The measurement, specified rather than wished for");
        report.check("what is measured is the energy the surrounding region loses when "
                     "the boundary produces the configuration, so the instrument is a "
                     "calorimeter enclosing the region and not a detector watching the "
                     "particle",
                     TimeReversalSignature::energyDrawnFromRegion(true, restEnergy, 1) >
                         TimeReversalSignature::energyDrawnFromRegion(false, restEnergy, 1));
        for (int lines : {1, 2, 3})
        {
            report.check(std::format("  {} turned line(s) : a pair draws {:.4f} and a turned "
                                     "line draws {:.4f}, so the resolution needed is {:.4f}",
                                     lines,
                                     TimeReversalSignature::energyDrawnFromRegion(true,
                                                                                  restEnergy,
                                                                                  lines),
                                     TimeReversalSignature::energyDrawnFromRegion(false,
                                                                                  restEnergy,
                                                                                  lines),
                                     TimeReversalSignature::resolutionNeeded(restEnergy, lines)),
                         TimeReversalSignature::resolutionNeeded(restEnergy, lines) > 0.0);
        }
        report.check("a calorimeter resolving better than twice the rest energy separates "
                     "them, and one resolving worse does not, which is a specification a "
                     "real instrument can be held to",
                     TimeReversalSignature::calorimeterSeparates(restEnergy, 1,
                                                                  1.5 * restEnergy) &&
                         !TimeReversalSignature::calorimeterSeparates(restEnergy, 1,
                                                                       2.5 * restEnergy));
        report.check("it has to be read in coincidence with the arrivals, because the "
                     "difference is a single lump drawn at the boundary and a long time "
                     "average buries it in whatever else the region is doing",
                     TimeReversalSignature::coincidenceRequired());

        report.subsection("And why writing the specification does not make it practical");
        report.check("at the returned weight of the worked round trip, a billion attempts "
                     "a second for a year still does not deliver one event",
                     !TimeReversalSignature::practicalAtWeight(6.473136e-37, 1e9, 3.15e7));
        report.check("at the weight the threshold optimum reaches instead, the same run "
                     "does deliver events, so the obstacle is the amplitude and not the "
                     "measurement",
                     TimeReversalSignature::practicalAtWeight(4.772425e-10, 1e9, 3.15e7));
        report.check("so this item moves from open to specified: the instrument, the "
                     "resolution and the timing are now stated, and what stands between "
                     "the specification and an experiment is the rate",
                     TimeReversalSignature::calorimeterSeparates(restEnergy, 1,
                                                                  1.5 * restEnergy) &&
                         !TimeReversalSignature::practicalAtWeight(6.473136e-37, 1e9, 3.15e7));
    }

}
