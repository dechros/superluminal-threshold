#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <array>

namespace slm
{

    /// Motion inside a region of changed signature, and how much of it reaches
    /// the exit face.
    ///
    /// Two observables of a round trip can be computed without reference to any
    /// trajectory: the exit face, which is the sign of the crossing wavenumber,
    /// and the exit moment, which is the frequency derivative of the
    /// transmission phase. These functions connect both to the motion inside.
    ///
    /// Motion there is not motion along a time axis. The far side carries
    /// three times and one space direction, so a state is an energy vector in
    /// the three-time space together with a wavenumber along the single spatial
    /// axis. Crossing the region is displacement along that spatial axis;
    /// everything else the particle can do is a rotation of the energy vector,
    /// which sweeps out an angle in one of the three time planes.
    ///
    /// Which of the two motions each observable sees is the question these
    /// functions answer. The crossing displacement sets the exit moment, but
    /// only while the interior propagates; where it does not, the moment comes
    /// from the phase and there is no journey at all. The rotation never
    /// touches the exit face, since the mass shell fixes the crossing
    /// wavenumber from the length of the energy vector alone. It does touch the
    /// exit moment, but only in two of the three time planes: the plane
    /// spanned by the two transverse slots moves no weight into the crossing
    /// direction and leaves the moment exactly where it was.
    class FarSideMotion
    {
    public:
        using Three = std::array<double, 3>;

        /// Interior wavenumber along the crossing axis, zero when the interior
        /// is evanescent and the particle therefore does not travel at all.
        static double crossingWavenumber(IntermediateRegion::Kind kind, double omega, double c,
                                         double mu, double transverseSquared);

        /// Whether the interior supports travel rather than decay.
        static bool interiorPropagates(IntermediateRegion::Kind kind, double omega, double c,
                                       double mu, double transverseSquared);

        /// Group speed along the crossing axis, obtained as the frequency
        /// derivative of the interior wavenumber. Zero when evanescent.
        static double crossingGroupSpeed(IntermediateRegion::Kind kind, double omega, double c,
                                         double mu, double transverseSquared);

        /// Time the crossing takes if it is taken to be travel at the group
        /// speed. This is the motion reading of the exit moment.
        static double motionTime(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                 double transverseSquared, double thickness);

        /// The exit moment as the phase already gives it, for comparison.
        static double phaseTime(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                double transverseSquared, double thickness);

        /// Length of an energy vector in the three-time space.
        static double vectorLength(const Three &energy);

        /// Rotation of the energy vector by the given angle in one of the three
        /// time planes, indexed 0, 1, 2.
        static Three rotateInTimePlane(const Three &energy, int plane, double angle);

        /// Angle between two energy vectors, which is what a path of rotations
        /// sweeps out in total.
        static double sweptAngle(const Three &from, const Three &to);

        /// Crossing wavenumber the mass shell assigns to an energy vector.
        static double crossingWavenumberFromEnergy(double c, double mu, const Three &energy);

        /// Whether any rotation of the energy vector changes the crossing
        /// wavenumber, which is what would let the interior path decide the
        /// exit face.
        static bool rotationChangesCrossingWavenumber(double c, double mu, const Three &energy);

        /// The exit moment as a function of the far-side energy vector alone.
        /// The vector is our own three-momentum under the crossing, so its
        /// length fixes our frequency and two of its components are the
        /// transverse data the slab amplitude needs.
        static double momentFromEnergy(IntermediateRegion::Kind kind, double c, double mu,
                                       const Three &energy, double thickness);

        /// Whether rotating in the given time plane moves the exit moment.
        static bool timePlaneMovesTheMoment(IntermediateRegion::Kind kind, double c, double mu,
                                            const Three &energy, double thickness, int plane);

        /// Number of distinct observable turns the interior rotation can leave
        /// behind, given that the two faces are drawn from the admissible set.
        static int observableTurnCount(double px, double py, double pz);
    };

    /// Section tying the exit face and the exit moment to interior motion.
    class FarSideMotionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Motion over there, and which of it the exit face and the exit moment see";
        }
        void run(Report &report) const override;
    };

}
