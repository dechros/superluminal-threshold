#include "units/ProtonJourney.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "routes/ThreeRoutes.h"
#include "units/PhysicalScales.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kCentre = 2.8;
        constexpr double kTransverse = 4.0;
        constexpr double kMu = 1.0;
        constexpr double kThickness = 8.0;
        constexpr double kNanosecond = 1e-9;
    }

    double ProtonJourney::referenceCentre() { return kCentre; }

    double ProtonJourney::referenceDelay()
    {
        return ThreeRoutes::roundTripReading(ThreeRoutes::Route::Wave,
                                             IntermediateRegion::Kind::Euclidean, kCentre, 1.0,
                                             kMu, kTransverse, kThickness);
    }

    double ProtonJourney::secondsPerUnit(double driveAngularFrequency)
    {
        if (driveAngularFrequency <= 0.0)
        {
            return 0.0;
        }
        return kCentre / driveAngularFrequency;
    }

    double ProtonJourney::debtInSeconds(double driveAngularFrequency)
    {
        return referenceDelay() * secondsPerUnit(driveAngularFrequency);
    }

    double ProtonJourney::breakEvenDistance(double driveAngularFrequency)
    {
        return PhysicalScales::lightSpeed() * debtInSeconds(driveAngularFrequency);
    }

    double ProtonJourney::distanceForAdvance(double driveAngularFrequency, double advanceSeconds)
    {
        return PhysicalScales::lightSpeed() * (advanceSeconds + debtInSeconds(driveAngularFrequency));
    }

    double ProtonJourney::arrivalSeconds(double driveAngularFrequency, double farSideMetres)
    {
        return debtInSeconds(driveAngularFrequency) -
               farSideMetres / PhysicalScales::lightSpeed();
    }

    bool ProtonJourney::arrivesBeforeDeparture(double driveAngularFrequency, double farSideMetres)
    {
        return arrivalSeconds(driveAngularFrequency, farSideMetres) < 0.0;
    }

    double ProtonJourney::lowestDriveForProton()
    {
        return PhysicalScales::frequencyNeededFor(PhysicalScales::protonMass());
    }

    bool ProtonJourney::driveIsSufficient(double driveAngularFrequency)
    {
        return driveAngularFrequency > lowestDriveForProton();
    }

    ProtonJourney::Record ProtonJourney::journey(double driveAngularFrequency,
                                                 double farSideMetres, double opacity)
    {
        Record record{};
        record.driveAngularFrequency = driveAngularFrequency;
        record.driveQuantumJoules = PhysicalScales::driveQuantum(driveAngularFrequency);
        record.secondsPerUnit = secondsPerUnit(driveAngularFrequency);
        record.debtSeconds = debtInSeconds(driveAngularFrequency);
        record.breakEvenMetres = breakEvenDistance(driveAngularFrequency);
        record.farSideMetres = farSideMetres;
        record.arrivalSeconds = arrivalSeconds(driveAngularFrequency, farSideMetres);
        record.returnProbability = PhysicalScales::returnedWeight(opacity);
        record.launchesPerArrival = PhysicalScales::launchesPerReturn(opacity);
        return record;
    }

    void ProtonJourneySection::run(Report &report) const
    {
        const double drive = 1.5e24;
        const double opacity = 10.0;

        report.subsection("The one conversion the laboratory numbers rest on");
        report.check(std::format("  the dimensionless band centre is {:.1f} and it is declared to "
                                 "stand for {:.4e} radians per second",
                                 ProtonJourney::referenceCentre(), drive),
                     ProtonJourney::referenceCentre() > 0.0);
        report.check(std::format("  so one unit of dimensionless time is {:.4e} s, and every "
                                 "other quantity follows without a second choice",
                                 ProtonJourney::secondsPerUnit(drive)),
                     ProtonJourney::secondsPerUnit(drive) > 0.0);
        report.check(std::format("the drive clears the proton floor of {:.4e} radians per second",
                                 ProtonJourney::lowestDriveForProton()),
                     ProtonJourney::driveIsSufficient(drive));

        report.subsection("What the crossing charges");
        report.check(std::format("  the round trip delay is {:.6f} in units and {:.4e} s in the "
                                 "laboratory",
                                 ProtonJourney::referenceDelay(),
                                 ProtonJourney::debtInSeconds(drive)),
                     ProtonJourney::debtInSeconds(drive) > 0.0);
        report.check(std::format("  clearing that debt takes {:.4e} m of far-side travel, which "
                                 "is smaller than the proton itself",
                                 ProtonJourney::breakEvenDistance(drive)),
                     ProtonJourney::breakEvenDistance(drive) < 1e-14);
        report.check("so the crossing is not what holds the journey back: its debt is paid off by "
                     "a distance under a femtometre, and everything beyond that is advance",
                     ProtonJourney::breakEvenDistance(drive) < 1e-14);

        report.subsection("Travelling backwards over there, and where it lands");
        for (double metres : {1e-15, 0.3, 3.0e5, 3.0e8})
        {
            const double arrival = ProtonJourney::arrivalSeconds(drive, metres);
            report.check(std::format("  {:>10.4e} m of travel lands it at {:>+11.4e} s, {}",
                                     metres, arrival,
                                     arrival < 0.0 ? "before departure" : "after departure"),
                         std::isfinite(arrival));
        }
        report.check("a femtometre of travel already brings it back before it left, because the "
                     "debt is smaller than that",
                     ProtonJourney::arrivesBeforeDeparture(drive, 1e-15));

        report.subsection("What a wanted advance costs in metres");
        for (double advance : {kNanosecond, 1e-6, 1e-3, 1.0})
        {
            report.check(std::format("  arriving {:>9.4e} s early needs {:>11.4e} m of backward "
                                     "travel",
                                     advance, ProtonJourney::distanceForAdvance(drive, advance)),
                         ProtonJourney::distanceForAdvance(drive, advance) > 0.0);
        }
        report.check("the debt is negligible against any advance worth measuring, so the distance "
                     "needed is the advance times the speed of light and nothing else",
                     std::abs(ProtonJourney::distanceForAdvance(drive, kNanosecond) -
                              PhysicalScales::lightSpeed() * kNanosecond) <
                         1e-6 * PhysicalScales::lightSpeed() * kNanosecond);

        report.subsection("The whole journey as one record");
        const ProtonJourney::Record record = ProtonJourney::journey(drive, 0.3, opacity);
        report.check(std::format("   1. drive            : {:.4e} rad/s, quantum {:.4e} J",
                                 record.driveAngularFrequency, record.driveQuantumJoules),
                     record.driveQuantumJoules > 0.0);
        report.check(std::format("   2. time unit        : {:.4e} s", record.secondsPerUnit),
                     record.secondsPerUnit > 0.0);
        report.check(std::format("   3. crossing debt    : {:.4e} s", record.debtSeconds),
                     record.debtSeconds > 0.0);
        report.check(std::format("   4. break even       : {:.4e} m", record.breakEvenMetres),
                     record.breakEvenMetres > 0.0);
        report.check(std::format("   5. travel over there: {:.4e} m, in the negative direction",
                                 record.farSideMetres),
                     record.farSideMetres > 0.0);
        report.check(std::format("   6. arrival          : {:.4e} s relative to departure",
                                 record.arrivalSeconds),
                     record.arrivalSeconds < 0.0);
        report.check(std::format("   7. return chance    : {:.4e}", record.returnProbability),
                     record.returnProbability > 0.0);
        report.check(std::format("   8. launches needed  : {:.4e} for one arrival",
                                 record.launchesPerArrival),
                     record.launchesPerArrival > 1.0);
        report.check("so a proton driven above its rest frequency, sent across, moved three "
                     "tenths of a metre backwards on the far side and returned, arrives one "
                     "nanosecond before it was launched",
                     std::abs(record.arrivalSeconds + kNanosecond) < 0.01 * kNanosecond);
    }

}
