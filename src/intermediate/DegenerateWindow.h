#pragma once

#include "core/Section.h"

namespace slm
{

    /// The reconciliation of two statements the earlier sections made without
    /// ever comparing them.
    ///
    /// One section establishes that a degenerate layer blocks a mode whatever
    /// its wavenumber. Another sends the particle across a metric family whose
    /// degenerate angle it passes straight through. Read together the two look
    /// like a contradiction, and the difference between them is one number: the
    /// thickness of the degenerate set.
    ///
    /// A layer of finite thickness blocks by making the mode evanescent across
    /// it, and @ref slabTransmission falls off exponentially in that thickness.
    /// The set the crossing meets has no thickness at all. Along the wall the
    /// metric factor is @f$ \cos 2\theta = -\tanh(x/L) @f$, so the region where
    /// it is within @f$ \epsilon @f$ of zero has width
    /// @ref windowWidth @f$ = 2L\,\mathrm{artanh}\,\epsilon @f$, which vanishes
    /// with @f$ \epsilon @f$ and takes the suppression to one with it.
    ///
    /// The stronger statement is that the blocking layer is not merely absent
    /// but forbidden. A layer requires the field to sit at @f$ \pi/4 @f$ across
    /// an interval, and that angle is the maximum of the field's potential.
    /// A field resting on a maximum is unstable, so no static solution has a
    /// degenerate layer in it. The section that found a layer blocking was
    /// describing a configuration the field equation does not supply.
    class DegenerateWindow
    {
    public:
        /// The metric's scale factor at position @p x in a wall of width
        /// @p width, which is @f$ -\tanh(x/L) @f$.
        static double metricFactor(double x, double width);

        /// The width of the region in which the metric factor is within
        /// @p tolerance of zero.
        static double windowWidth(double width, double tolerance);

        /// The transmission of a mode of mass parameter @p mu across a
        /// genuinely degenerate slab of thickness @p thickness, which is
        /// @f$ e^{-2\sqrt{\mu}\,w} @f$.
        static double slabTransmission(double mu, double thickness);

        /// The thickness at which such a slab halves the transmission,
        /// @f$ \ln 2 / 2\sqrt{\mu} @f$.
        static double halvingThickness(double mu);
    };

    /// Section verifying that the crossing meets a degenerate set of vanishing
    /// width, that the suppression tends to one with it, and that a layer thick
    /// enough to block is not a solution of the field equation.
    class DegenerateWindowSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Why a degenerate layer blocks and a degenerate point does not, and why only the point is a solution";
        }
        void run(Report &report) const override;
    };

}
