#pragma once

#include "core/Section.h"

namespace slm
{

    /// The standard prescription for building a signature-changing metric, and
    /// what the rate condition does to it.
    ///
    /// The obstruction computed elsewhere in these libraries was found in one
    /// particular family of transitions, which leaves open whether it is a
    /// property of signature change or a property of that family. This class
    /// closes that question by running the same test on the prescription the
    /// surrounding literature uses generally: a metric whose one degenerating
    /// component vanishes on a hypersurface, with the directions along that
    /// hypersurface carried by a separate block.
    ///
    /// Two conditions are attached to that prescription and they are usually
    /// stated separately. TRANSVERSALITY asks the degenerating component to
    /// vanish to first order, which is what makes the determinant vanish to
    /// first order and keeps the hypersurface smoothly embedded. TOTALLY
    /// GEODESIC asks the extrinsic curvature of that hypersurface to vanish,
    /// which is what removes the distributional source.
    ///
    /// The two constrain DIFFERENT components. Transversality is a statement
    /// about the derivative of the degenerating component; the extrinsic
    /// curvature is the derivative of the tangential block divided by twice the
    /// lapse. They are independent knobs and both can be turned at once, which
    /// is why the surrounding literature imposes them together without
    /// remarking on any tension. Any computation that finds them incompatible
    /// is a computation that has conflated the two blocks.
    ///
    /// That conflation is exactly what the earlier family did: there the
    /// quantity called the extrinsic curvature was half the derivative of the
    /// component that was changing sign. This class carries both readings so
    /// the difference is a computed number rather than a remark, and it gives
    /// the exponent in closed form. Writing the order of vanishing of the
    /// degenerating component as q and that of the tangential slope as p, the
    /// ratio the rate condition tests behaves as the distance to the power
    /// p - q/2, and the conflated reading is the special case p = q - 1, giving
    /// q/2 - 1. Transversality is q = 1, so the conflated reading can never
    /// pass and the general one passes as soon as the tangential slope is
    /// stationary, which is the totally geodesic condition itself.
    ///
    /// So the earlier obstruction is not a feature of signature change. What
    /// does survive as an obstruction is a different pair: a surface layer
    /// needs the extrinsic curvature nonvanishing at the crossing and the rate
    /// condition needs it to die faster than the lapse, and no order satisfies
    /// both. That is the strong against weak dichotomy already in the
    /// literature, reached from the side of a rate.
    class TransversePrescription
    {
    public:
        /// The component that degenerates, vanishing to the given order at the
        /// crossing and changing sign through it.
        static double degenerateComponent(double xi, int degenerateOrder);

        /// Its derivative.
        static double degenerateSlope(double xi, int degenerateOrder);

        /// Whether the transversality condition holds, that the degenerating
        /// component vanishes to first order and no faster.
        static bool isTransverse(int degenerateOrder);

        /// Lapse, the square root of the magnitude of the degenerating
        /// component.
        static double lapse(double xi, int degenerateOrder);

        /// Normal derivative of the tangential block, vanishing to the given
        /// order at the crossing. This is the quantity the extrinsic curvature
        /// is built from, and it is not the same quantity transversality
        /// constrains.
        static double tangentialSlope(double xi, int tangentialOrder);

        /// Extrinsic curvature of the surfaces of constant coordinate, which is
        /// the tangential slope over twice the lapse.
        static double extrinsicCurvature(double xi, int degenerateOrder, int tangentialOrder);

        /// Whether the hypersurface is totally geodesic, that the tangential
        /// slope vanishes at the crossing.
        static bool isTotallyGeodesic(int tangentialOrder);

        /// Whether both conditions hold at once, which is the configuration the
        /// literature's clean case asks for and which is available.
        static bool bothConditionsHold(int degenerateOrder, int tangentialOrder);

        /// Ratio whose limit the rate condition tests, which is twice the
        /// extrinsic curvature and is therefore that curvature measured with
        /// proper distance rather than coordinate distance.
        static double ratio(double distance, int degenerateOrder, int tangentialOrder);

        /// Power with which that ratio behaves in the distance from the
        /// crossing, measured.
        static double ratioExponent(int degenerateOrder, int tangentialOrder, double nearDistance,
                                    double farDistance);

        /// The same power in closed form, which is the tangential order less
        /// half the degenerate order.
        static double predictedExponent(int degenerateOrder, int tangentialOrder);

        /// Whether the rate condition is met, that the ratio dies.
        static bool satisfiesRateCondition(int degenerateOrder, int tangentialOrder);

        /// The ratio as the earlier family computed it, with the curvature
        /// taken from the degenerating component instead of the tangential
        /// block.
        static double conflatedRatio(double distance, int degenerateOrder);

        /// Its measured power.
        static double conflatedExponent(int degenerateOrder, double nearDistance,
                                        double farDistance);

        /// Its closed form, half the degenerate order less one, which is the
        /// general formula at a tangential order one below the degenerate one.
        static double predictedConflatedExponent(int degenerateOrder);

        /// Whether the conflated reading admits any transverse order that also
        /// passes the rate condition, which it does not, and which is where the
        /// earlier obstruction came from.
        static bool conflatedAllowsBoth(int highestOrder);

        /// Whether the general prescription admits a transverse, totally
        /// geodesic configuration that passes the rate condition, which it
        /// does.
        static bool generalAllowsBoth();

        /// Whether any order both carries a layer and meets the rate condition,
        /// which is what a transmitting junction with a source would need, and
        /// which is the obstruction that does survive.
        static bool anyOrderKeepsLayerAndRate(int highestOrder);
    };

    /// Section running the rate condition on the general prescription rather
    /// than on one family.
    class TransversePrescriptionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The same test on the general prescription, not one family";
        }
        void run(Report &report) const override;
    };

}
