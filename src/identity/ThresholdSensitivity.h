#pragma once

#include "intermediate/IntermediateRegion.h"

#include <vector>

namespace slm
{

    /// How the measured threshold moves as the band's mass parameter and
    /// width are moved, and where each stops being a well posed question.
    ///
    /// The closed form for the delay is evaluated at the centre of the band,
    /// so two properties of the band do not appear in it: the mass parameter
    /// enters only through the frequency, and the width does not enter at
    /// all. Neither absence licenses the conclusion that the outcome is
    /// independent of them, so both dependences are measured on a propagated
    /// packet and the closed form and the measurement are reported side by
    /// side.
    ///
    /// Each dependence has a ceiling past which the timing is not a larger
    /// number but an undefined one, because the band no longer propagates
    /// outside the region at all: once by the centre moving down to the
    /// cutoff, and once by the lower edge of a wide band spreading down to
    /// it. The two ceilings are the same limit seen twice.
    class ThresholdSensitivity
    {
    public:
        /// Mass parameters the mass dependence is scanned over.
        static const std::vector<double> &massGrid();

        /// Band widths the extent dependence is scanned over.
        static const std::vector<double> &extentGrid();

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

        /// Widest band whose low edge still lies above the frequency below
        /// which nothing propagates outside. Past it the band is no longer the
        /// Gaussian it is named as, because its lower tail is cut away rather
        /// than carried, so the widest admissible extent is a limit of the same
        /// kind as the heaviest admissible mass and comes from the same cutoff.
        /// The reach is the number of widths the sum actually spans, which is a
        /// property of the summation and is taken from it rather than restated.
        static double largestAdmissibleExtent(double c, double mu, double transverseSquared,
                                              double centre, double reach);

        /// Whether the given band lies wholly above the cutoff.
        static bool extentIsAdmissible(double spread, double c, double mu,
                                       double transverseSquared, double centre, double reach);

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
    };

}
