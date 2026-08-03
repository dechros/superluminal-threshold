#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <vector>

namespace slm
{

    /// What a route that is not a straight line leaves behind on the clock.
    ///
    /// The coordinate dictionary is linear, so a journey confined to one axis
    /// gives a displacement that depends on the net amount travelled and on
    /// nothing else: an outward leg and an equal return leg cancel exactly. A
    /// route that changes frame between its legs is a different question, since
    /// the coefficient relating the two regions is read off a matrix and that
    /// matrix is composed with whatever the frame change is.
    ///
    /// Two kinds of frame change are available, and they behave differently.
    ///
    /// ROTATIONS AMONG THE LIKE-SIGNED AXES DO NOTHING. A rotation of the three
    /// like-signed axes into one another fixes the distinguished axis, so it
    /// leaves the relevant matrix entry untouched. Any route built from
    /// displacements and rotations of this kind returns the clock to where it
    /// started once the net displacement vanishes, no matter how involved the
    /// route was. Wandering, by itself, buys nothing.
    ///
    /// A HYPERBOLIC ROTATION INVOLVING THE DISTINGUISHED AXIS DOES NOT. Mixing
    /// the distinguished axis with a like-signed one is an isometry of the far
    /// metric as well, but it does not fix that axis, and it multiplies the
    /// coefficient by the hyperbolic cosine of its rapidity. A closed route
    /// whose two legs are separated by such a rotation therefore leaves a
    /// residue, and the residue is unbounded in the rapidity.
    ///
    /// WHAT THE RESIDUE IS WORTH. The same hyperbolic cosine is the factor an
    /// ordinary boost applies to a time interval in the subluminal region. The
    /// residue is therefore the far-side counterpart of a familiar dilation
    /// rather than an independent effect, and it is reported as such. The cost
    /// is also computed: composing the crossing with a nonzero rapidity
    /// destroys the closure under repetition that the admissible set was
    /// selected for, so the boosted crossing is no longer a map whose second
    /// application returns the original frame.
    class RouteHolonomy
    {
    public:
        /// One leg of a route: the frame the far side is in while it is
        /// travelled, and the signed amount travelled along the distinguished
        /// axis.
        struct Leg
        {
            Matrix4 frame;
            double displacement = 0.0;
        };

        /// Index of the far side's distinguished axis.
        static int distinguishedAxis();

        /// Rotation of two like-signed far-side axes into each other.
        static Matrix4 likeSignedRotation(int first, int second, double angle);

        /// Hyperbolic rotation mixing the distinguished axis with a like-signed
        /// one.
        static Matrix4 hyperbolicRotation(int likeSignedAxis, double rapidity);

        /// Whether the given frame change is an isometry of the far metric, and
        /// so a legitimate change of frame there.
        static bool preservesFarMetric(const Matrix4 &frame, double tolerance = 1e-9);

        /// Whether the frame change leaves the distinguished axis alone.
        static bool fixesDistinguishedAxis(const Matrix4 &frame, double tolerance = 1e-9);

        /// Crossing map obtained by composing a crossing with a frame change on
        /// the far side.
        static Matrix4 composedCrossing(const Matrix4 &crossing, const Matrix4 &frame);

        /// Whether the composed map still satisfies the metric relation between
        /// the two regions, which is what makes it an admissible crossing.
        static bool composedIsAdmissible(const Matrix4 &crossing, const Matrix4 &frame,
                                         double tolerance = 1e-9);

        /// Whether the composed map is still an involution, so that crossing
        /// twice returns the frame it started in.
        static bool composedIsClosed(const Matrix4 &crossing, const Matrix4 &frame,
                                     double tolerance = 1e-9);

        /// Coefficient relating a unit displacement along the distinguished axis
        /// to a displacement on the clock, in the given frame.
        static double clockCoefficient(const Matrix4 &crossing, const Matrix4 &frame);

        /// Clock displacement a whole route produces.
        static double clockDisplacement(const Matrix4 &crossing, const std::vector<Leg> &route);

        /// Net amount travelled along the distinguished axis, summed over legs.
        static double netDisplacement(const std::vector<Leg> &route);

        /// Clock displacement of a route whose net displacement vanishes, which
        /// is zero when the frame changes fix the distinguished axis and need
        /// not be otherwise.
        static double closedRouteResidue(const Matrix4 &crossing, const std::vector<Leg> &route);

        /// A route that travels out, changes frame by the given rapidity, and
        /// travels the same amount back.
        static std::vector<Leg> outAndBack(double distance, double rapidity, int likeSignedAxis = 0);

        /// A route that travels out, rotates among the like-signed axes, and
        /// travels the same amount back.
        static std::vector<Leg> outAndBackWithRotation(double distance, double angle);

        /// Factor an ordinary boost of the given rapidity applies to a time
        /// interval in the subluminal region, retained for comparison with the
        /// residue.
        static double subluminalDilation(double rapidity);
    };

    /// Section computing what a route that is not a straight line leaves on the
    /// clock, and at what cost.
    class RouteHolonomySection : public Section
    {
    public:
        std::string title() const override
        {
            return "Wandering leaves nothing, changing frame leaves something";
        }
        void run(Report &report) const override;
    };

}
