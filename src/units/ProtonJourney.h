#pragma once

#include "core/Section.h"

namespace slm
{

    /// One proton carried through the whole journey, in kilograms, metres and
    /// seconds, with the far-side leg run in the negative direction.
    ///
    /// The libraries compute the crossing in units where the speed of light is
    /// one, so their answers are pure numbers. Turning those into laboratory
    /// quantities needs one choice and no more: the physical frequency the
    /// dimensionless band centre stands for. Fixing it fixes the unit of time,
    /// and every other quantity follows without a second assumption. That
    /// choice is made explicit here rather than buried, because a scale set
    /// twice is the usual way a unit conversion goes wrong.
    ///
    /// The leg on the far side is taken in the negative direction along the one
    /// spatial axis available there. Its sign is what turns a delay into an
    /// advance, and it is the only quantity in the journey a traveller sets.
    ///
    /// Two numbers come out of this that are worth separating. The debt the
    /// crossing charges is fixed by the drive frequency and is very small for a
    /// proton, well under the size of the proton itself. The advance wanted is
    /// not small, and it is paid for at the speed of light. So the journey is
    /// not held back by the crossing; it is held back by the distance that has
    /// to be covered over there.
    class ProtonJourney
    {
    public:
        /// Dimensionless band centre the libraries are configured at.
        static double referenceCentre();

        /// Dimensionless round trip delay at that configuration, taken from the
        /// same library the rest of the work uses rather than restated.
        static double referenceDelay();

        /// Seconds per unit of dimensionless time, once the band centre is
        /// declared to be this physical angular frequency. This is the single
        /// conversion the section rests on.
        static double secondsPerUnit(double driveAngularFrequency);

        /// The crossing debt in seconds, that is the round trip delay expressed
        /// in laboratory time.
        static double debtInSeconds(double driveAngularFrequency);

        /// Far-side distance in metres that merely clears the debt, so that the
        /// proton returns at the moment it left.
        static double breakEvenDistance(double driveAngularFrequency);

        /// Far-side distance in metres needed to arrive the given number of
        /// seconds before departure. Negative travel is taken as read; the
        /// magnitude is what is reported.
        static double distanceForAdvance(double driveAngularFrequency, double advanceSeconds);

        /// Moment of arrival relative to departure, in seconds, after
        /// travelling the given distance in metres on the far side. Negative
        /// means the proton is back before it left.
        static double arrivalSeconds(double driveAngularFrequency, double farSideMetres);

        /// Whether that arrival falls before the departure.
        static bool arrivesBeforeDeparture(double driveAngularFrequency, double farSideMetres);

        /// Lowest drive frequency able to carry a proton, from its rest energy.
        static double lowestDriveForProton();

        /// Whether the drive clears that floor.
        static bool driveIsSufficient(double driveAngularFrequency);

        /// Every quantity of one journey, so that a single trip can be read in
        /// one place instead of assembled from separate calls.
        struct Record
        {
            double driveAngularFrequency;
            double driveQuantumJoules;
            double secondsPerUnit;
            double debtSeconds;
            double breakEvenMetres;
            double farSideMetres;
            double arrivalSeconds;
            double returnProbability;
            double launchesPerArrival;
        };

        static Record journey(double driveAngularFrequency, double farSideMetres, double opacity);
    };

    /// Section carrying one proton through the journey in laboratory units.
    class ProtonJourneySection : public Section
    {
    public:
        std::string title() const override
        {
            return "One proton, sent across, moved back, and returned early";
        }
        void run(Report &report) const override;
    };

}
