#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <complex>

namespace slm
{

    /// The competing readings of how long a crossing takes, computed side by
    /// side on one and the same scattering solution.
    ///
    /// There is no single accepted answer to how long a particle spends inside
    /// a region it cannot classically enter, and the disagreement is not about
    /// arithmetic: several inequivalent quantities each have a claim to the
    /// name, each is what some measurement would return, and they do not agree
    /// with one another. Quoting one of them alone is therefore a choice that
    /// has to be argued rather than a result. This class computes them all from
    /// the same amplitude so that the choice is visible.
    ///
    /// Four readings are built:
    ///
    /// The PHASE reading is the frequency derivative of the transmission phase,
    /// the delay seen by an observer who stayed outside and watched a peak
    /// arrive. It is the one that saturates with thickness.
    ///
    /// The DWELL reading is the stored norm over the incident flux, the
    /// lifetime of the field inside the region.
    ///
    /// The two clock components come from the derivative of the transmission
    /// amplitude with respect to the barrier height rather than the frequency,
    /// and they form one complex number. Its real part is the component a clock
    /// coupled to the field would show as a rotation, and it is expected to
    /// reproduce the dwell time exactly, which makes it an independent check on
    /// two constructions at once. Its imaginary part is the component that
    /// shows up instead as an alignment of the clock, and it is the one reading
    /// known not to saturate: it grows with thickness where the phase reading
    /// stops. The magnitude of the complex number is the reading obtained from
    /// a barrier whose height is modulated, the crossing being fast or slow
    /// according to whether the particle sees the modulation as static.
    ///
    /// No spin is introduced anywhere for this. The clock components are read
    /// off the barrier-height derivative of the scalar amplitude, which is
    /// where they come from in the first place; a precessing spin is one way to
    /// measure them, not what defines them.
    class TraversalClocks
    {
    public:
        /// The complex clock time, the barrier-height derivative of the
        /// logarithm of the transmission amplitude. Both components below are
        /// its parts.
        static std::complex<double> complexClock(IntermediateRegion::Kind kind, double omega,
                                                 double c, double mu, double transverseSquared,
                                                 double thickness);

        /// Component a coupled clock would show as a rotation, the real part.
        static double rotationComponent(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared, double thickness);

        /// Component a coupled clock would show as an alignment, the imaginary
        /// part. This is the reading that keeps growing with thickness.
        static double alignmentComponent(IntermediateRegion::Kind kind, double omega, double c,
                                         double mu, double transverseSquared, double thickness);

        /// Reading obtained from a barrier of modulated height, the magnitude
        /// of the complex clock.
        static double modulatedBarrierTime(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared, double thickness);

        /// Semiclassical reading, the thickness divided by the speed built from
        /// the magnitude of the interior wavenumber. Under the barrier this is
        /// the imaginary-time crossing of the classically forbidden region.
        static double semiclassicalTime(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared, double thickness);

        /// Whether a reading stops growing when the region is made thicker,
        /// tested between two thicknesses far apart.
        static bool saturates(double nearValue, double farValue);

        /// Growth of the alignment component per unit thickness, which is the
        /// slope that decides whether any clock survives the saturation.
        static double alignmentSlope(IntermediateRegion::Kind kind, double omega, double c,
                                     double mu, double transverseSquared, double firstThickness,
                                     double secondThickness);

        /// Whether the rotation component reproduces the dwell time, which is
        /// the identity that ties the two independent constructions together.
        static bool rotationMatchesDwell(IntermediateRegion::Kind kind, double omega, double c,
                                         double mu, double transverseSquared, double thickness,
                                         double tolerance);

        /// Number of readings among those built here that keep growing with
        /// thickness in the barrier regime, and so still carry a transit
        /// interpretation there.
        static int unsaturatedReadingCount(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared);

        /// Speed a given reading implies, in units of the speed of light.
        /// Above one the reading says the crossing outran light; below one it
        /// says the crossing fell behind it.
        static double speedInLightUnits(double reading, double thickness, double c);

        /// How many of the five readings imply a crossing faster than light at
        /// a given thickness. The readings do not agree on this, which is why
        /// the comparison has to be made reading by reading rather than once.
        static int readingsFasterThanLight(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared, double thickness);

        /// Whether the readings agree with one another on the sign of the
        /// comparison with light, which they do not in the barrier regime.
        static bool readingsAgreeAgainstLight(IntermediateRegion::Kind kind, double omega, double c,
                                              double mu, double transverseSquared,
                                              double thickness);
    };

    /// Section computing every reading of the crossing time side by side.
    class TraversalClocksSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Every reading of how long the crossing takes, on one solution";
        }
        void run(Report &report) const override;
    };

}
