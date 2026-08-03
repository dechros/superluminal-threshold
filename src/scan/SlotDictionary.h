#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// The coordinate dictionary between the two regions, and what adds.
    ///
    /// The crossing is stated informally as "the far side's single space
    /// direction is the subluminal time direction". This class turns that into
    /// two theorems and proves both by construction over the whole admissible
    /// set rather than for one representative.
    ///
    /// THE COEFFICIENT IS EXACTLY ONE. For every admissible crossing, the row
    /// that produces the time coordinate has a single nonzero entry, that entry
    /// sits on the far side's distinguished axis, and its magnitude is one. So a
    /// displacement of @f$ s @f$ along that axis produces a displacement of
    /// exactly @f$ s @f$ on the clock, not @f$ s @f$ times something. Nothing is
    /// scaled, and no other far-side direction contributes.
    ///
    /// DISPLACEMENTS ADD. Because the map is linear, travelling @f$ s_1 @f$ and
    /// then @f$ s_2 @f$ produces the same displacement as travelling
    /// @f$ s_1 + s_2 @f$ once. This is checked rather than assumed, since it is
    /// the property that lets a journey be split into pieces and the pieces
    /// summed, and it would fail for any map that was not linear.
    ///
    /// WHAT IS NOT PROVED HERE. These two results concern displacements that are
    /// both far-side displacements. On their own they do not license adding a
    /// delay obtained from the phase of a scattering amplitude to a displacement
    /// obtained from this dictionary, since those two come from different
    /// calculations. That addition is settled elsewhere, by the dictionary
    /// induced on the conjugate variables: with the displacement placed inside
    /// the phase, both terms come from one stationary-phase condition and the
    /// weight on the second is a computed derivative. The distinction is kept
    /// sharp here on purpose, because collapsing it would turn a separate result
    /// into a corollary of this one by wording alone.
    class SlotDictionary
    {
    public:
        /// Index of the coordinate that carries the subluminal time.
        static int timeSlot();

        /// Row of the given crossing map that produces the time coordinate.
        static Vector4 timeRow(const Matrix4 &crossing);

        /// Number of nonzero entries in that row.
        static int contributingAxes(const Matrix4 &crossing);

        /// The single far-side axis feeding the time slot, or -1 when more than
        /// one does.
        static int sourceAxis(const Matrix4 &crossing);

        /// Coefficient with which that axis enters the time slot.
        static double coefficient(const Matrix4 &crossing);

        /// True when exactly one far-side axis feeds the time slot and it does
        /// so with unit magnitude.
        static bool isUnitOneToOne(const Matrix4 &crossing);

        /// Displacement produced on the clock by travelling @p distance along
        /// the source axis of the given crossing.
        static double clockDisplacement(const Matrix4 &crossing, double distance);

        /// Difference between travelling two legs separately and travelling
        /// their sum in one go. Zero for a linear map.
        static double additivityResidual(const Matrix4 &crossing, double first, double second);

        /// True when the map is homogeneous in the amount, so that doubling the
        /// far-side distance doubles the clock displacement.
        static bool isHomogeneous(const Matrix4 &crossing, double distance = 3.0,
                                  double scale = 2.0);

        /// True when travel confined to the far side's three like-signed axes
        /// produces no clock displacement at all, which is what makes the single
        /// distinguished axis the only route to the clock.
        static bool likeSignedAxesContributeNothing(const Matrix4 &crossing);
    };

    /// Section proving the coordinate dictionary and the additivity it licenses.
    class SlotDictionarySection : public Section
    {
    public:
        std::string title() const override
        {
            return "The dictionary is one to one, and far-side displacements add";
        }
        void run(Report &report) const override;
    };

}
