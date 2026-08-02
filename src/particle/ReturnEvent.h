#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <array>

namespace slm
{

    /// The map from a state on the far side to the event at which the particle
    /// comes back.
    ///
    /// A far-side state is an orientation together with a branch. The
    /// orientation is a unit vector in the three-time space, so it ranges over
    /// a two-sphere. The branch is the sign of the wavenumber along the single
    /// spatial axis, and it takes two values. The state space of orientations
    /// is therefore a two-sphere times a two-element set.
    ///
    /// The return event is a point of the subluminal region, so it has four
    /// coordinates measured from the entry event: an elapsed time, a
    /// displacement along the crossing direction, and two transverse
    /// displacements. These functions compute all four from the far-side state
    /// and the region parameters, and record which part of the state each
    /// coordinate can see.
    ///
    /// The elapsed time comes from the phase of the two-crossing amplitude,
    /// since no clock survives the far side. The crossing displacement is
    /// either zero or the thickness, according to the branch, since the branch
    /// is which face the particle leaves by. The transverse displacements come
    /// from the shift of the packet centroid.
    class ReturnEvent
    {
    public:
        using Three = std::array<double, 3>;

        /// Four coordinates of the return event, measured from the entry event.
        struct Event
        {
            double elapsed;
            double crossing;
            double transverseFirst;
            double transverseSecond;
        };

        /// A far-side state: an orientation of the energy vector and a branch.
        struct State
        {
            Three orientation;
            int branch;
        };

        /// A state built from the two angles of the two-sphere and a branch.
        static State stateFromAngles(double polar, double azimuth, double length, int branch);

        /// The return event a given far-side state produces.
        static Event map(const State &state, IntermediateRegion::Kind kind, double c, double mu,
                         double thickness);

        /// Time an uninterrupted signal at the speed of light would need to
        /// cover the same round trip.
        static double lightRoundTrip(double thickness, double c);

        /// How much earlier than that signal the particle returns. Positive
        /// means the return event lies inside the light cone of nothing that
        /// stayed behind, which is the quantity the whole construction is
        /// built to produce.
        static double advanceOverLight(const State &state, IntermediateRegion::Kind kind, double c,
                                       double mu, double thickness);

        /// Whether the advance keeps growing as the region is made thicker.
        static bool advanceGrowsWithThickness(IntermediateRegion::Kind kind, double c, double mu,
                                              double omega);

        /// Whether any state in the scanned grid changes the given coordinate.
        /// The four are indexed 0 to 3 in the order of Event.
        static bool coordinateDependsOnOrientation(int coordinate, IntermediateRegion::Kind kind,
                                                   double c, double mu, double thickness,
                                                   int steps = 12);

        /// Whether the given coordinate depends on the branch.
        static bool coordinateDependsOnBranch(int coordinate, IntermediateRegion::Kind kind,
                                              double c, double mu, double thickness);

        /// One coordinate of an event, indexed as above.
        static double coordinate(const Event &event, int index);

        /// Number of distinct return events the scanned grid of states
        /// produces, counted to the given tolerance.
        static int distinctEvents(IntermediateRegion::Kind kind, double c, double mu,
                                  double thickness, int steps = 12);

        /// Number of states scanned at that resolution, which is the size of
        /// the domain the previous count reduces.
        static int scannedStates(int steps = 12);
    };

    /// Section computing the map from far-side states to return events.
    class ReturnEventSection : public Section
    {
    public:
        std::string title() const override
        {
            return "From a far-side orientation to the four coordinates of the return event";
        }
        void run(Report &report) const override;
    };

}
