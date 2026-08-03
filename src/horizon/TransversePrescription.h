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
    /// surrounding literature uses generally: a Lorentzian metric with a
    /// rank-one term added along a chosen direction, the coefficient of that
    /// term interpolating through the value that flips the sign.
    ///
    /// Two conditions are attached to that prescription and they are usually
    /// stated separately. TRANSVERSALITY asks the interpolating coefficient to
    /// have a nonvanishing derivative where it crosses, which is what makes the
    /// determinant vanish only to first order. TOTALLY GEODESIC asks the
    /// hypersurface to have vanishing extrinsic curvature, which is what
    /// removes the distributional source.
    ///
    /// Written in this prescription the extrinsic curvature is half the
    /// derivative of the interpolating coefficient, so the two conditions are
    /// the same derivative asked to be nonzero and zero. They cannot both hold.
    /// That is computed here rather than argued, and it says what the earlier
    /// obstruction was: not a feature of one family, and not a new obstruction
    /// either, but this incompatibility seen from the side of the rate at which
    /// a term dies.
    class TransversePrescription
    {
    public:
        /// Interpolating coefficient at the given coordinate. The shape
        /// parameter sets how many orders it vanishes to at the crossing: one
        /// is the transverse case, three is stationary there.
        static double coefficient(double xi, int order);

        /// Derivative of that coefficient.
        static double coefficientSlope(double xi, int order);

        /// The metric component that changes sign, which is minus one plus the
        /// coefficient.
        static double changingComponent(double xi, int order);

        /// Whether the transversality condition holds, that the coefficient's
        /// derivative does not vanish at the crossing.
        static bool isTransverse(int order);

        /// Extrinsic curvature of the surfaces of constant coordinate, which in
        /// this prescription is half the coefficient's derivative.
        static double extrinsicCurvature(double xi, int order);

        /// Whether the hypersurface is totally geodesic, that the extrinsic
        /// curvature vanishes at the crossing.
        static bool isTotallyGeodesic(int order);

        /// Whether both conditions hold at once, which is the configuration the
        /// literature's clean case asks for.
        static bool bothConditionsHold(int order);

        /// Lapse, the square root of the magnitude of the changing component.
        static double lapse(double xi, int order);

        /// Ratio whose limit the rate condition tests.
        static double ratio(double distance, int order);

        /// Power with which that ratio behaves in the distance from the
        /// crossing.
        static double ratioExponent(int order, double nearDistance, double farDistance);

        /// Whether the rate condition is met, that the ratio dies.
        static bool satisfiesRateCondition(int order);

        /// Whether any order both carries a layer and meets the rate condition,
        /// which is what a transmitting junction would need.
        static bool anyOrderKeepsLayerAndRate();
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
