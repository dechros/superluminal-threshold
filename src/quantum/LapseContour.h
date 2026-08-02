#pragma once

#include "core/Section.h"

#include <complex>

namespace slm
{

    /// Which way the lapse contour has to run past the point where the metric
    /// degenerates, and what that choice decides here.
    ///
    /// Integrating over the lapse is what imposes reparametrisation invariance,
    /// and the integrand carries an essential singularity exactly at zero lapse,
    /// which is where the metric degenerates. The contour therefore has to run
    /// from one end of the real line to the other while avoiding the origin, and
    /// which side it passes on is not a matter of taste: the two sides give
    /// different answers.
    ///
    /// This bears on the construction here for a specific reason. The return
    /// moment is read off a phase rather than carried by a clock, and in the
    /// barrier regime that phase comes from a continuation into complex values.
    /// A continuation is only as good as the criterion that says which one is
    /// allowed, and no such criterion has been adopted here. The contour
    /// condition is one, and it is cheap to test: the exponent has two saddle
    /// points, they sit on the imaginary axis at equal distances from the
    /// origin, and one of them belongs to a decaying amplitude while the other
    /// belongs to a growing one. A contour has to pick one.
    ///
    /// The integrand used is the minisuperspace form, an exponential whose
    /// exponent has a term going as one over the lapse and a term linear in it.
    /// That is the form that produces the essential singularity, and it is the
    /// same form the crossing amplitude takes when written as a sum over
    /// interior lapses.
    class LapseContour
    {
    public:
        /// Exponent of the integrand at a complex lapse. The first term carries
        /// the distance and diverges at zero lapse; the second carries the mass.
        static std::complex<double> exponent(std::complex<double> lapse, double distance,
                                             double mass);

        /// The integrand itself.
        static std::complex<double> integrand(std::complex<double> lapse, double distance,
                                              double mass);

        /// The two saddle points of the exponent, which lie on the imaginary
        /// axis. The sign selects which.
        static std::complex<double> saddle(int sign, double distance, double mass);

        /// Value the integrand takes at a saddle, whose magnitude says whether
        /// that saddle carries a decaying or a growing amplitude.
        static double magnitudeAtSaddle(int sign, double distance, double mass);

        /// Whether the integrand grows without bound as the origin is
        /// approached along the real axis, which is what forbids a contour
        /// through zero.
        static bool singularAtZero(double distance, double mass);

        /// Integral over the positive lapse half line rotated onto the
        /// imaginary axis, downwards for a negative side and upwards for a
        /// positive one. The downward rotation is the one a contour passing
        /// below the origin deforms onto; the upward rotation is what a contour
        /// passing above it would need.
        static double rotatedIntegral(int side, double distance, double mass, double limit = 60.0,
                                      int samples = 200000);

        /// Rate at which the downward-rotated integral falls off with distance,
        /// obtained from its logarithm. This is the quantity that identifies
        /// which saddle the contour actually landed on.
        static double decayRate(double distance, double mass);

        /// Whether the upward rotation fails to converge at all, which is a
        /// stronger statement than the two contours merely differing.
        static bool upperRotationDiverges(double distance, double mass);

        /// Whether the two contours give different answers, which is the whole
        /// content of the objection that the continuation is arbitrary without
        /// a criterion.
        static bool contoursDisagree(double distance, double mass);

        /// Which saddle the downward-rotated contour actually landed on,
        /// decided by comparing its measured fall-off rate against the rate
        /// each saddle would give. Nothing here assumes the answer.
        static int saddleReached(double distance, double mass);

        /// Whether the contour passing below the origin selects the decaying
        /// amplitude, which is the one the crossing calculation here uses.
        static bool belowSelectsDecaying(double distance, double mass);
    };

    /// Section computing which side of the degenerate point the contour must
    /// pass, and what it selects here.
    class LapseContourSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Which side of the degenerate point the lapse contour passes";
        }
        void run(Report &report) const override;
    };

}
