#pragma once

#include "core/Section.h"

#include <array>

namespace slm
{

    /// Whether a route through a multi-time region leaves a trace, decided by
    /// the curvature of the connection on the space of times.
    ///
    /// When a state evolves in several time variables at once, each carries its
    /// own generator, and the several evolutions are mutually consistent only
    /// if transport in the space of times is path independent. That condition
    /// is the vanishing of a curvature whose components are the commutators of
    /// the generators taken pairwise. Where the curvature vanishes the route
    /// carries no information and the reduction to a single time is
    /// unambiguous; where it does not, a closed route leaves a holonomy on the
    /// state and the orientation among the times is observable.
    ///
    /// This supplies an independent test of a result obtained elsewhere by
    /// scattering: that turning the energy vector moves the moment at which the
    /// particle returns. If the free theory is flat, the effect cannot come
    /// from the interior evolution and must come from the boundary, which is a
    /// sharper statement than either calculation alone.
    ///
    /// The generators here are those of the free field on the far side, one per
    /// time direction, represented by their action on a mode of given
    /// wavenumbers.
    class TimeHolonomy
    {
    public:
        using Three = std::array<double, 3>;

        /// Generator of translation along one of the three far-side times,
        /// acting on a mode, which for the free field is the corresponding
        /// component of the energy vector.
        static double generator(const Three &energy, int timeIndex);

        /// Commutator of the generators of two time directions, which is the
        /// curvature component of the connection on the space of times.
        static double curvatureComponent(const Three &energy, int first, int second);

        /// Largest curvature component over the three pairs.
        static double largestCurvature(const Three &energy);

        /// Whether the connection is flat, so that transport in the space of
        /// times is path independent.
        static bool isFlat(const Three &energy);

        /// Phase a closed rectangular route in the plane of two times
        /// accumulates, which is the curvature times the enclosed area.
        static double holonomyPhase(const Three &energy, int first, int second, double firstSpan,
                                    double secondSpan);

        /// Whether a closed route through the interior returns the state
        /// unchanged, which is what a flat connection guarantees.
        static bool closedRouteIsTrivial(const Three &energy, double span);

        /// Curvature once the two threshold surfaces are included, where the
        /// matching mixes the crossing direction into the transverse ones and
        /// the generators no longer commute. It is the rate at which a
        /// rotation in the given plane moves weight between the crossing slot
        /// and the transverse ones, so it vanishes for planes that touch
        /// neither and for vectors with no weight in one of the two.
        /// \param couplingStrength Strength of the mixing the surfaces impose.
        static double curvatureWithSurfaces(const Three &energy, int first, int second,
                                            double couplingStrength);

        /// Whether including the surfaces makes the connection curved.
        static bool surfacesCurveTheConnection(const Three &energy, double couplingStrength);

        /// The slot whose component the crossing wavenumber is built from, so
        /// that only planes touching it can be curved by the matching.
        static int crossingSlot();
    };

    /// Section deciding where the orientation dependence can come from.
    class TimeHolonomySection : public Section
    {
    public:
        std::string title() const override
        {
            return "Path dependence in the space of times, and where the trace comes from";
        }
        void run(Report &report) const override;
    };

}
