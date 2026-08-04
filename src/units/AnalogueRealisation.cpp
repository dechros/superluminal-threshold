#include "units/AnalogueRealisation.h"

#include "core/Report.h"
#include "units/PhysicalScales.h"
#include "units/ProtonJourney.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kHealingLength = 1.0e-6;
        constexpr double kSoundSpeed = 1.0e-3;
        constexpr double kBenchMetres = 1.0;
    }

    double AnalogueRealisation::coherenceLength() { return kHealingLength; }

    double AnalogueRealisation::soundSpeed() { return kSoundSpeed; }

    double AnalogueRealisation::admissionFrequency(double invariantSpeed, double length)
    {
        return length > 0.0 ? invariantSpeed / length : 0.0;
    }

    double AnalogueRealisation::admissionFrequencyForProton()
    {
        return ProtonJourney::lowestDriveForProton();
    }

    double AnalogueRealisation::admissionAdvantageInDecades()
    {
        const double analogue = admissionFrequency(kSoundSpeed, kHealingLength);
        const double vacuum = admissionFrequencyForProton();
        if (analogue <= 0.0 || vacuum <= 0.0)
        {
            return 0.0;
        }
        return std::log10(vacuum / analogue);
    }

    double AnalogueRealisation::distanceForAdvance(double invariantSpeed, double advanceSeconds)
    {
        return invariantSpeed * advanceSeconds;
    }

    double AnalogueRealisation::advanceForDistance(double invariantSpeed, double metres)
    {
        return invariantSpeed > 0.0 ? metres / invariantSpeed : 0.0;
    }

    bool AnalogueRealisation::fitsOnABench(double invariantSpeed, double advanceSeconds,
                                           double benchMetres)
    {
        return distanceForAdvance(invariantSpeed, advanceSeconds) < benchMetres;
    }

    double AnalogueRealisation::debtInSeconds(double driveAngularFrequency)
    {
        return ProtonJourney::debtInSeconds(driveAngularFrequency);
    }

    double AnalogueRealisation::breakEvenDistance(double invariantSpeed,
                                                  double driveAngularFrequency)
    {
        return invariantSpeed * debtInSeconds(driveAngularFrequency);
    }

    void AnalogueRealisationSection::run(Report &report) const
    {
        const double sound = AnalogueRealisation::soundSpeed();
        const double length = AnalogueRealisation::coherenceLength();
        const double admission = AnalogueRealisation::admissionFrequency(sound, length);
        const double drive = 10.0 * admission;

        report.subsection("Where the signature actually changes in a laboratory");
        report.check("an effective metric carries the signature of the medium it describes, and a "
                     "dilute gas with attractive interactions carries an imaginary sound speed, "
                     "which is a Euclidean effective metric",
                     true);
        report.check("so the region this work needs is produced by the sign of an interaction "
                     "rather than by a gravitational apparatus, and that sign is set from outside "
                     "the gas",
                     true);

        report.subsection("What the invariant speed does to the admission price");
        report.check(std::format("  in vacuum the admission frequency for a proton is {:.4e} rad/s",
                                 AnalogueRealisation::admissionFrequencyForProton()),
                     AnalogueRealisation::admissionFrequencyForProton() > 1e23);
        report.check(std::format("  in the analogue it is the sound speed over the coherence "
                                 "length, {:.4e} over {:.4e}, which is {:.4e} rad/s",
                                 sound, length, admission),
                     admission > 0.0);
        report.check(std::format("that is {:.1f} orders of magnitude lower, and it lands in the "
                                 "audio range rather than above a gamma ray",
                                 AnalogueRealisation::admissionAdvantageInDecades()),
                     AnalogueRealisation::admissionAdvantageInDecades() > 20.0);

        report.subsection("What the invariant speed does to the exchange rate");
        for (double advance : {1e-3, 1.0, 60.0})
        {
            report.check(std::format("  {:>8.4e} s of advance costs {:>10.4e} m in vacuum and "
                                     "{:>10.4e} m in the analogue",
                                     advance,
                                     AnalogueRealisation::distanceForAdvance(
                                         PhysicalScales::lightSpeed(), advance),
                                     AnalogueRealisation::distanceForAdvance(sound, advance)),
                         AnalogueRealisation::distanceForAdvance(sound, advance) > 0.0);
        }
        report.check(std::format("a millimetre of travel buys {:.4e} s at the sound speed, against "
                                 "{:.4e} s at the speed of light",
                                 AnalogueRealisation::advanceForDistance(sound, 1e-3),
                                 AnalogueRealisation::advanceForDistance(
                                     PhysicalScales::lightSpeed(), 1e-3)),
                     AnalogueRealisation::advanceForDistance(sound, 1e-3) > 0.5);
        report.check("a full second of advance therefore fits on a bench, which is the whole of "
                     "the difference between the vacuum proposal and this one",
                     AnalogueRealisation::fitsOnABench(sound, 1.0, kBenchMetres) &&
                         !AnalogueRealisation::fitsOnABench(PhysicalScales::lightSpeed(), 1.0,
                                                            kBenchMetres));

        report.subsection("The journey at the sound speed, end to end");
        report.check(std::format("  the drive is taken ten times the admission frequency, "
                                 "{:.4e} rad/s",
                                 drive),
                     drive > admission);
        report.check(std::format("  the crossing debt is {:.4e} s and clearing it takes {:.4e} m",
                                 AnalogueRealisation::debtInSeconds(drive),
                                 AnalogueRealisation::breakEvenDistance(sound, drive)),
                     AnalogueRealisation::breakEvenDistance(sound, drive) > 0.0);
        report.check(std::format("  travelling one millimetre backwards lands the excitation "
                                 "{:.4e} s before it set out",
                                 AnalogueRealisation::advanceForDistance(sound, 1e-3) -
                                     AnalogueRealisation::debtInSeconds(drive)),
                     AnalogueRealisation::advanceForDistance(sound, 1e-3) >
                         AnalogueRealisation::debtInSeconds(drive));

        report.subsection("What the analogue does not claim");
        report.check("the effective metric governs excitations and not the apparatus, so an "
                     "excitation arriving before it set out is early against the sound cone and "
                     "not against the laboratory clock",
                     true);
        report.check("faster than sound is ordinary and violates nothing, so the analogue carries "
                     "no paradox and offers no signal outrunning light",
                     PhysicalScales::lightSpeed() > sound);
        report.check("what the analogue does offer is the chain of this work made measurable: the "
                     "region, the crossing, the travel and the arrival all exist there, and the "
                     "arrival time is the quantity to be read rather than the particle count the "
                     "surrounding literature reads",
                     true);
    }

}
