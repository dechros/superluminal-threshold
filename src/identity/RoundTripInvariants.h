#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// What a crossing changes about a band of modes and what it leaves alone.
    ///
    /// The closed form for the delay is evaluated at the centre of the band, so
    /// two properties of the band do not appear in it: the mass parameter
    /// enters only through the frequency, and the width does not enter at all.
    /// Neither absence licenses the conclusion that the outcome is independent
    /// of them. The transmission is mode dependent and the peak a detector
    /// finds belongs to the whole band, so both dependences are measured on a
    /// propagated packet as well as read off the closed form, and the two
    /// routes are reported side by side.
    ///
    /// The second half is a ledger over the quantities a reader would use to
    /// call the returning object the same object. Two of them are preserved
    /// for reasons of construction rather than by measurement, and are
    /// reported that way: the crossing multiplies each mode amplitude by a
    /// factor and does not move the mode label, so the mass parameter and the
    /// mode grid survive by definition. Everything computed from the band
    /// rather than fixed by the field can move, and those are measured.
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
        /// Delay the closed form predicts at a given mass, other parameters
        /// held fixed.
        static double predictedDelayAtMass(double mass, IntermediateRegion::Kind kind, double c,
                                           double transverseSquared, double thickness,
                                           double centre);

        /// Threshold distance the propagated packet measures at a given mass.
        /// This is the same quantity by the route that uses no delay formula.
        static double measuredThresholdAtMass(double mass, IntermediateRegion::Kind kind, double c,
                                              double transverseSquared, double thickness,
                                              double centre, double spread, int samples);

        /// Whether the measured threshold grows as the mass grows, over the
        /// given range. Reported rather than assumed, since the mass enters the
        /// frequency and the frequency enters the decay constant with opposite
        /// tendencies.
        static bool thresholdGrowsWithMass(IntermediateRegion::Kind kind, double c,
                                           double transverseSquared, double thickness,
                                           double centre, double spread, int samples);

        /// Whether the thickness independence of the delay still holds at the
        /// given mass. Saturation is a statement about the opaque regime and
        /// the mass changes how opaque the region is, so it is checked at each
        /// mass rather than once.
        static bool saturationHoldsAtMass(double mass, IntermediateRegion::Kind kind, double c,
                                          double transverseSquared, double centre, double spread,
                                          int samples, double tolerance);

        /// Largest mass parameter for which the band centre still propagates
        /// outside the region. Above it the outside normal wavenumber is
        /// imaginary, no component of the band reaches a detector, and the
        /// delay is not a smaller number but an undefined one. The ceiling is
        /// set by the band centre and the transverse part alone.
        static double largestAdmissibleMass(double c, double transverseSquared, double centre);

        /// Whether the configuration lies below that ceiling, which every
        /// timing statement here presupposes.
        static bool propagatesOutside(double mass, double c, double transverseSquared,
                                      double centre);

        /// Threshold distance the propagated packet measures at a given band
        /// width, everything else held fixed.
        static double measuredThresholdAtExtent(double spread, IntermediateRegion::Kind kind,
                                                double c, double mu, double transverseSquared,
                                                double thickness, double centre, int samples);

        /// Whether a wider band measures a later return, over the range
        /// scanned. The closed form carries no width at all, so any dependence
        /// found here is one the formula cannot report and its direction is a
        /// result rather than a correction.
        static bool thresholdGrowsWithExtent(IntermediateRegion::Kind kind, double c, double mu,
                                             double transverseSquared, double thickness,
                                             double centre, int samples);

        /// Largest relative difference in the measured threshold across a
        /// range of band widths, which is how much the timing depends on the
        /// extent of the packet.
        static double thresholdVariationOverExtent(IntermediateRegion::Kind kind, double c,
                                                   double mu, double transverseSquared,
                                                   double thickness, double centre, int samples);

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
