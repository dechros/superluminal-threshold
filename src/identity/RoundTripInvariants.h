#pragma once

#include "core/Section.h"
#include "identity/ThresholdSensitivity.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// What a crossing changes about a band of modes and what it leaves alone.
    ///
    /// This is a ledger over the quantities a reader would use to call the
    /// returning object the same object. Two of them are preserved for
    /// reasons of construction rather than by measurement, and are reported
    /// that way: the crossing multiplies each mode amplitude by a factor and
    /// does not move the mode label, so the mass parameter and the mode grid
    /// survive by definition. Everything computed from the band rather than
    /// fixed by the field can move, and those are measured.
    ///
    /// Whether the crossing destroys information is a separate question from
    /// whether it attenuates the band, and the two are kept apart here. A
    /// diagonal map with strictly positive entries is injective, so it loses
    /// amplitude without losing distinguishability; the smallest transmission
    /// over the band is therefore computed and reported, because that is the
    /// number the claim rests on and it is the number that fails first.
    class RoundTripInvariants
    {
    public:
        /// Every quantity of the band before and after the round trip, so that
        /// preserved and altered can be read off one record instead of being
        /// assembled from separate calls.
        struct Ledger
        {
            double massParameter;
            double meanBefore;
            double meanAfter;
            double extentBefore;
            double extentAfter;
            double normBefore;
            double normAfter;
            double entropyBefore;
            double entropyAfter;
            double relativeEntropy;
            double centroidShiftInExtents;
            double smallestTransmission;
        };

        static Ledger ledger(double centre, double spread, IntermediateRegion::Kind kind, double c,
                             double mu, double thickness);

        /// Smallest transmission factor over the band actually carried, which
        /// is what injectivity of the crossing rests on.
        static double smallestTransmissionOnBand(double centre, double spread,
                                                 IntermediateRegion::Kind kind, double c,
                                                 double mu, double thickness, int samples);

        /// Whether every mode of the band is transmitted with a non-zero
        /// factor, so that the crossing is injective on the band and no two
        /// distinct incoming bands are sent to the same outgoing one.
        static bool crossingIsInjective(double centre, double spread,
                                        IntermediateRegion::Kind kind, double c, double mu,
                                        double thickness, int samples);

        /// Mass parameter recovered from a mode of the returned band through
        /// the same relation it went in by. Preserved by construction, since
        /// the crossing scales amplitudes without moving mode labels; kept as
        /// a function so that the construction can be checked rather than
        /// described.
        static double recoveredMassParameter(double transverseSquared, double c, double mu);

        /// Whether the returned band is narrower than the one that set out.
        /// The mode-dependent transmission favours one side of the band, so
        /// the width can move either way and the direction is a result.
        static bool bandNarrows(double centre, double spread, IntermediateRegion::Kind kind,
                                double c, double mu, double thickness);
    };

    /// Section reporting what the round trip preserves and what it moves.
    class RoundTripInvariantsSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Mass, extent, and what the journey leaves unchanged";
        }
        void run(Report &report) const override;
    };

}
