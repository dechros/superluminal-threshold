#pragma once

#include "core/Section.h"

namespace slm
{

    /// The same journey run in a laboratory analogue, where the invariant speed
    /// is the speed of sound rather than the speed of light.
    ///
    /// The chain computed elsewhere needs a region whose metric signature
    /// differs from the surrounding one. No known apparatus produces that in
    /// spacetime itself. It is produced routinely in analogue systems, where an
    /// effective metric governs the propagation of excitations and its
    /// signature is set by a laboratory parameter. A dilute gas with attractive
    /// interactions carries an imaginary sound speed, and an imaginary sound
    /// speed is a Euclidean effective metric.
    ///
    /// Substituting the sound speed for the speed of light changes nothing in
    /// the algebra and everything in the numbers, and it changes them in the
    /// favourable direction twice over.
    ///
    /// The admission frequency falls, because it is the invariant speed divided
    /// by the length that plays the part of the Compton wavelength. In a gas
    /// that length is the healing length, and the ratio lands in the audio
    /// range rather than above the frequency of a gamma ray.
    ///
    /// The exchange rate between distance covered and time recovered falls with
    /// it, because that rate is the invariant speed. A millimetre of travel buys
    /// a second when the invariant speed is a millimetre per second.
    ///
    /// One thing has to be said plainly and is said in the section as well. The
    /// effective metric governs excitations and not the apparatus. An excitation
    /// arriving before it set out is early against the sound cone, which is the
    /// causal structure its own dynamics defines. It is not early against the
    /// laboratory clock, and no signal outruns light anywhere in the account.
    /// Faster than sound is ordinary; the content of the result is that the
    /// arrival can fall outside the effective cone by a route that is computed
    /// rather than asserted.
    class AnalogueRealisation
    {
    public:
        /// Length standing in for the Compton wavelength, which in a dilute gas
        /// is the healing length.
        static double coherenceLength();

        /// Invariant speed of the effective metric, which is the sound speed.
        static double soundSpeed();

        /// Lowest drive frequency that can carry an excitation across, which is
        /// the invariant speed over the coherence length.
        static double admissionFrequency(double invariantSpeed, double length);

        /// The same quantity for the vacuum case, for comparison.
        static double admissionFrequencyForProton();

        /// How many orders of magnitude easier the analogue admission is.
        static double admissionAdvantageInDecades();

        /// Distance in metres that buys the given advance in seconds, at the
        /// given invariant speed.
        static double distanceForAdvance(double invariantSpeed, double advanceSeconds);

        /// Advance in seconds bought by the given distance in metres.
        static double advanceForDistance(double invariantSpeed, double metres);

        /// Whether the distance needed for a one second advance fits inside a
        /// laboratory apparatus of the given size.
        static bool fitsOnABench(double invariantSpeed, double advanceSeconds, double benchMetres);

        /// Crossing debt in seconds, obtained by scaling the dimensionless
        /// round trip delay with the drive frequency, exactly as the vacuum
        /// case does.
        static double debtInSeconds(double driveAngularFrequency);

        /// Break even distance in metres at the given invariant speed.
        static double breakEvenDistance(double invariantSpeed, double driveAngularFrequency);
    };

    /// Section running the journey at the speed of sound.
    class AnalogueRealisationSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The same journey with sound in place of light";
        }
        void run(Report &report) const override;
    };

}
