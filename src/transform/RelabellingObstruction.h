#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    /// The answer to the objection that the far region is the near one written
    /// in the opposite convention.
    ///
    /// The objection is correct about the metric and stops there. Reversing
    /// every sign of the near-side metric and permuting the slots does give the
    /// far-side metric, and no property of a metric alone can tell the two
    /// apart: they even share a determinant.
    ///
    /// What the objection leaves out is that a region is not a metric but a
    /// metric together with the matter in it. The mass shell reads
    /// @f$ p^T g\, p = \mu c^2 @f$, and the relabelling acts on @f$ g @f$ while
    /// @f$ \mu @f$ belongs to the particle and stays where it is. Carrying the
    /// solutions of the shell along with the relabelling therefore demands
    /// @f$ \mu \to -\mu @f$, which is not a change of convention but a change
    /// of particle: a negative mass parameter is an imaginary mass.
    ///
    /// @ref freeDirections is the quantity that makes this countable. It asks
    /// how many coordinate axes admit a real on-shell momentum, which is a
    /// question about the pair and not about the metric. For an ordinary
    /// particle the near region answers one and the far region answers three,
    /// and no relabelling closes that gap while the particle is held fixed.
    ///
    /// A second obstruction is independent of any particle. Along the metric
    /// family the count of positive diagonal entries changes only at the
    /// degenerate angle, so the two regions lie in different components of the
    /// nondegenerate metrics and no continuous relabelling connects them.
    ///
    /// The claim is therefore conditional, and the condition is stated rather
    /// than hidden: were a particle of negative mass parameter available, the
    /// two regions would be the same region and this whole construction would
    /// describe nothing.
    class RelabellingObstruction
    {
    public:
        /// The number of coordinate axes along which a particle of mass
        /// parameter @p mu has a real momentum on the shell of @p metric.
        static int freeDirections(const Matrix4 &metric, double mu);

        /// The momentum such a particle carries along the given axis, or zero
        /// when the axis admits none.
        static double axisMomentum(const Matrix4 &metric, double mu, int axis);

        /// The number of positive diagonal entries of the metric at the given
        /// crossing angle.
        static int positiveEntries(double theta);
    };

    /// Section verifying that the relabelling costs the particle its real mass,
    /// that the count of free directions separates the two regions while the
    /// particle is held fixed, and that no continuous path relabels one into
    /// the other.
    class RelabellingObstructionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Why the far region is not the near one relabelled, once the particle is counted as part of the region";
        }
        void run(Report &report) const override;
    };

}
