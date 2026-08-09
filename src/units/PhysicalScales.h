#pragma once

#include "core/Section.h"

#include <string>

namespace slm
{

    /// The journey written in kilograms, metres and seconds.
    ///
    /// Every other library here works in units where the speed of light is one,
    /// which is right for the algebra and useless for asking whether a thing can
    /// be done. This class carries the two conversions that turn the geometric
    /// statements into laboratory ones, and it carries nothing else.
    ///
    /// The first conversion is the heaviest state a given drive can send across.
    /// The crossing needs the band centre to clear the frequency built from the
    /// rest energy, so the state's rest energy has to fall below the energy
    /// quantum of the drive. That single inequality fixes a mass in kilograms
    /// for every frequency, and it is the hard wall: below it the journey is
    /// expensive, above it there is no journey.
    ///
    /// The second conversion is the exchange rate between distance travelled on
    /// the far side and time recovered on the near side. In geometric units they
    /// are the same number, which hides the size of the bill. In metres and
    /// seconds one second of recovered time costs the light travel distance of
    /// one second, so the rate is the speed of light and the bill is large.
    ///
    /// A third quantity is reported alongside, because a journey that can be
    /// made and not seen is not a journey that has been made: the weight the
    /// state comes back with, against a stated detection floor.
    class PhysicalScales
    {
    public:
        static double lightSpeed();
        static double reducedPlanck();
        static double elementaryCharge();
        static double electronMass();
        static double protonMass();

        /// Ground-state binding energy of hydrogen, in joules. A fixed
        /// textbook constant, not something this project derives.
        static double hydrogenBindingEnergyJoules();

        /// Rest mass of a ground-state hydrogen atom: the proton and the
        /// electron, less the mass equivalent of the energy that binds them.
        static double hydrogenAtomMass();

        /// Energy quantum of a drive at the given angular frequency, in joules.
        static double driveQuantum(double angularFrequency);

        /// Heaviest rest mass, in kilograms, that a drive at this frequency can
        /// send across. This is the hard wall and it is an equality in the rest
        /// energy: the state's rest energy must fall below the drive quantum.
        static double heaviestMass(double angularFrequency);

        /// The same wall read the other way: the angular frequency a drive needs
        /// in order to carry a state of the given mass.
        static double frequencyNeededFor(double massInKilograms);

        /// Rest energy in electronvolts, for reporting.
        static double restEnergyInElectronvolts(double massInKilograms);

        /// Whether a drive at this frequency can carry this mass at all.
        static bool driveCanCarry(double angularFrequency, double massInKilograms);

        /// Far-side distance in metres that buys the given time advance in
        /// seconds. The exchange rate is the speed of light.
        static double distanceForAdvance(double seconds);

        /// Time advance in seconds bought by the given far-side distance in
        /// metres.
        static double advanceForDistance(double metres);

        /// Weight the state returns with, for a barrier of the given opacity,
        /// which is the decay constant times the thickness. Two crossings, so
        /// the exponent is doubled.
        static double returnedWeight(double opacity);

        /// Largest opacity a barrier may have if the returned weight is to clear
        /// the given detection floor.
        static double largestOpacityForFloor(double floor);

        /// Whether the state comes back at a weight above the floor.
        static bool returnsVisibly(double opacity, double floor);

        /// Number of states that have to be launched for one to be expected
        /// back, at the given opacity.
        static double launchesPerReturn(double opacity);
    };

    /// Section reporting the journey in laboratory units.
    class PhysicalScalesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The journey in kilograms, metres and seconds";
        }
        void run(Report &report) const override;
    };

}
