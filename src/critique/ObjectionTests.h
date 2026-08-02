#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <array>

namespace slm
{

    /// Objections raised against this model, computed rather than described.
    ///
    /// Section 19 of the article states each objection in prose. The ones that
    /// carry a number or a structural claim are checked here, so that an
    /// objection is either confirmed against our own arithmetic or shown to
    /// miss. The purely conceptual ones, such as the absence of operational
    /// content, are not representable as a computation and stay in the text.
    class ObjectionTests
    {
    public:
        /// Permutation matrix of the four coordinates, no signs attached.
        /// \param permutation Image of each row index.
        static Matrix4 permutationMatrix(const std::array<int, 4> &permutation);

        /// How many of the 24 coordinate permutations leave the line element
        /// of region I unchanged. The objection puts this at 6.
        static int lineElementPreservingPermutations();

        /// How many change it. The objection puts this at 18.
        static int lineElementChangingPermutations();

        /// Whether a permutation leaves the time slot where it was, which is
        /// what decides the previous two counts.
        static bool fixesTimeSlot(const std::array<int, 4> &permutation);

        /// Pauli-Jordan style commutator function of a single sector,
        /// summed over a grid of modes above the tachyonic threshold.
        /// \param separation Coordinate separation along the mode direction.
        /// \param mass Mass parameter setting the threshold.
        /// \param modes Number of modes summed.
        static double singleSectorCommutator(double separation, double mass, int modes = 4000);

        /// The same quantity in the doubled construction, where a starred
        /// sector is adjoined with the opposite sign. The objection is that
        /// this vanishes identically, leaving no quantum dynamics.
        static double doubledSectorCommutator(double separation, double mass, int modes = 4000);

        /// Superluminality parameter of a propagating excitation, v^2/c^2 - 1,
        /// which the vacuum Cherenkov bound constrains. Nothing in this model
        /// propagates past the threshold, so this is zero by construction.
        static double superluminalityParameter(double groupVelocity, double c);
    };

    /// Section running the computable objections.
    class ObjectionTestsSection : public Section
    {
    public:
        std::string number() const override { return "19"; }
        std::string title() const override
        {
            return "The objections, computed";
        }
        void run(Report &report) const override;
    };

}
