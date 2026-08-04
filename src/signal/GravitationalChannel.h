#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// Whether the gravitational coupling across the junction carries a signal
    /// or only exists.
    ///
    /// A junction's matter layer touches both sides at once, so it does not
    /// have to cross the region and stays coupled when every field channel is
    /// shut. That establishes a channel. It does not
    /// establish that anything can be sent along it, which needs two further
    /// things: the layer has to respond to what a sender does, and the response
    /// has to be readable from the other side.
    ///
    /// The layer's surface stress-energy is fixed by the jump in extrinsic
    /// curvature across it. A mass placed on the near side bends the metric there,
    /// changes the extrinsic curvature on that face, and so changes the jump.
    /// The calculation below is linearised and weak field: enough to decide
    /// whether the response exists and how it scales, not enough to give a
    /// capacity.
    class GravitationalChannel
    {
    public:
        /// Extrinsic curvature contributed on the near face by a mass at a distance,
        /// in the weak field.
        static double curvatureFromMass(double mass, double distance);

        /// Surface density of the layer, set by the jump in extrinsic
        /// curvature between the two faces.
        static double layerDensity(IntermediateRegion::Kind kind, double thickness, double mass,
                                   double distance);

        /// Change in the layer when the sender moves the mass, which is what a
        /// signal would ride on.
        static double responseToMass(IntermediateRegion::Kind kind, double thickness,
                                     double distance);

        /// Whether the layer responds at all, that is whether the channel can
        /// be modulated rather than merely being present.
        static bool modulable(IntermediateRegion::Kind kind, double thickness, double distance);

        /// Time for the sender's action to reach the surface, which is set by
        /// the speed of light in the near-side region.
        static double responseDelay(double distance, double c);

        /// Ratio of the modulated part of the layer to its static part, the
        /// contrast an observer on the far side would have to resolve.
        static double contrast(IntermediateRegion::Kind kind, double thickness, double mass,
                               double distance);
    };

    /// Section deciding whether the gravitational channel signals.
    class GravitationalChannelSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Does the gravitational channel carry a signal, or only exist";
        }
        void run(Report &report) const override;
    };

}
