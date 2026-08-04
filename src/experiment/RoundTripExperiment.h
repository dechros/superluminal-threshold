#pragma once

#include "core/Section.h"

#include <string>
#include <vector>

namespace slm
{

    /// The apparatus that would carry out the core measurement, specified
    /// requirement by requirement.
    ///
    /// The measurement is one thing and the whole of the work points at it: a
    /// proton is launched, crosses into the far region, is displaced along the
    /// one spatial axis available there, crosses back, and is registered at a
    /// moment earlier than its launch on the same clock.
    ///
    /// Each requirement is stated with the number that has to be met and the
    /// number a present laboratory reaches, so the specification says which
    /// parts are solved and which are not, rather than describing an apparatus
    /// uniformly out of reach. Most of them are met comfortably. One is not met
    /// at all, and separating the two is the point of listing them.
    ///
    /// One requirement that looks severe is not. The band centre a proton
    /// presents is its own total energy over the reduced Planck constant, and a
    /// proton at rest already sits at the frequency built from its rest energy.
    /// Any kinetic energy puts it above. So no source has to supply that
    /// frequency; the proton carries it. What the beam does have to supply is
    /// collimation, because the condition compares the total energy against the
    /// transverse momentum and the mass together.
    class RoundTripExperiment
    {
    public:
        enum class Requirement
        {
            BeamEnergy,        ///< the proton must be above the frequency built from its rest energy
            Collimation,       ///< transverse momentum small against the total
            RegionDensity,     ///< the far region must exist, which is a density condition
            BarrierOpacity,    ///< opaque enough to saturate, transparent enough to return
            FarSideDisplacement,///< the distance covered on the far side
            TimingResolution,  ///< fine enough to resolve the advance
            Statistics,        ///< enough launches for one arrival
            Identification     ///< the returning proton attributable to the launch
        };

        static std::vector<Requirement> all();
        static std::string name(Requirement requirement);

        /// What the requirement asks for, in words and in a unit.
        static std::string unit(Requirement requirement);

        /// Value the requirement demands.
        static double demanded(Requirement requirement);

        /// Value a present laboratory reaches.
        static double available(Requirement requirement);

        /// Whether a larger available value is the satisfying direction. Two of
        /// the requirements are satisfied by being small rather than large.
        static bool largerIsBetter(Requirement requirement);

        static bool isMet(Requirement requirement);

        /// Orders of magnitude between what is asked and what is reached,
        /// positive when short.
        static double shortfallInDecades(Requirement requirement);

        static int metCount();

        /// The advance the experiment aims to observe, in seconds.
        static double targetAdvanceSeconds();

        /// Far-side displacement that produces it, in metres.
        static double displacementMetres();

        /// Launches needed for one arrival at the working opacity.
        static double launchesNeeded();

        /// Running time in seconds at the available beam rate.
        static double runTimeSeconds();

        /// Separation between the advance and the timing resolution, in
        /// standard deviations, which is what makes the result a measurement
        /// rather than a coincidence.
        static double separationInResolutions();
    };

    /// Section specifying the apparatus for the core measurement.
    class RoundTripExperimentSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The apparatus for the core measurement, requirement by requirement";
        }
        void run(Report &report) const override;
    };

}
