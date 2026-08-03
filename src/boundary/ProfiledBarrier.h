#pragma once

#include "core/Section.h"

#include <functional>
#include <string>
#include <vector>

namespace slm
{

    /// Transmission through a barrier whose decay constant varies with position.
    ///
    /// A uniform slab answers how much gets through a barrier of a given
    /// thickness, but not the sharper question: how much of the answer is set by
    /// the thickness alone, and how much by the shape of the profile inside it.
    /// The distinction matters because a published result on propagation across a
    /// change of signature states that the outcome depends only on the total size
    /// of the region and not on the detailed form of the metric. That statement is
    /// checkable, and checking it requires barriers that differ in shape while
    /// agreeing in total.
    ///
    /// The measure of total is the integrated decay constant, not the geometric
    /// width. Two profiles are comparable here when their integrals agree, which
    /// is the quantity the exponential actually sees.
    ///
    /// The transmission is computed by composing exact single-slice solutions
    /// rather than by an asymptotic formula, so the result carries the prefactor
    /// as well as the exponent. That is what makes the comparison informative:
    /// the claim under test is about the exponent, and a method that only ever
    /// produced exponents could not tell whether the prefactor was also fixed.
    ///
    /// The composition runs from the far side towards the near one, which is not
    /// a matter of taste. Composed in the natural direction, the transmitted
    /// amplitude appears as the difference of two quantities each of which is
    /// larger than the answer by the whole exponential, so a thick barrier asks
    /// for a cancellation of more digits than a double holds and returns
    /// transmissions above one. Run the other way, the solution being propagated
    /// is the growing one and the answer is a reciprocal of something large,
    /// which loses nothing. The change of direction is what lets the totals here
    /// reach the regime where the claim is supposed to hold.
    class ProfiledBarrier
    {
    public:
        /// A decay constant as a function of position within the barrier, given
        /// as a fraction of the width.
        using Profile = std::function<double(double)>;

        /// The profiles compared here.
        enum class Shape
        {
            Uniform,
            Triangle,
            HalfSine,
            Plateau,
            Skewed
        };

        static std::string name(Shape shape);

        /// A profile of the given shape, scaled so that its integral over the
        /// barrier equals the requested total.
        static Profile profile(Shape shape, double width, double total);

        /// The integral of a profile across the barrier.
        static double integratedDecay(const Profile &profile, double width, int slices = 4096);

        /// Transmission probability, by composing exact slice solutions.
        /// \param outsideWavenumber Real wavenumber in the regions either side.
        static double transmission(const Profile &profile, double width, double outsideWavenumber,
                                   int slices = 2048);

        /// The exponent the transmission realises, defined as the logarithm of
        /// the transmission divided by minus twice the integrated decay. The
        /// claim under test is that this tends to one, independently of shape.
        static double realisedExponent(const Profile &profile, double width,
                                       double outsideWavenumber, int slices = 2048);

        /// Every shape compared here.
        static std::vector<Shape> shapes();
    };

    /// Section testing whether the total alone fixes what gets through.
    class ProfiledBarrierSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Whether the total alone fixes what gets through";
        }
        void run(Report &report) const override;
    };

}
