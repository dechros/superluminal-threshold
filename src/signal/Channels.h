#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// What can carry information between the two regions.
    ///
    /// The article's electromagnetic chapter shows the field survives the
    /// crossing algebraically, but survival is not the same as carrying a
    /// signal. Four carriers are examined and they do not stand or fall
    /// together: a massless field, a massive one, the gravitational coupling
    /// through the junction's own matter layer, and correlation.
    ///
    /// The interesting case is the third. The layer sits on the surface and
    /// touches both sides at once, so it does not have to cross anything. That
    /// makes it the one channel that can still be open when the region is
    /// closed to every field.
    class Channels
    {
    public:
        /// Transmission of a massless field, the electromagnetic case.
        static double masslessTransmission(IntermediateRegion::Kind kind, double c,
                                           double transverseSquared, double thickness);

        /// Transmission of the massive scalar the particle is made of.
        static double massiveTransmission(IntermediateRegion::Kind kind, double c, double mu,
                                          double transverseSquared, double thickness);

        /// Strength of the gravitational coupling across the junction, which is
        /// carried by the matter layer rather than by anything crossing.
        static double gravitationalCoupling(IntermediateRegion::Kind kind, double thickness);

        /// Whether the field channel is closed while the gravitational one is
        /// not, which is the case that matters.
        static bool gravityReachesWhereFieldsCannot(IntermediateRegion::Kind kind, double c,
                                                    double mu, double transverseSquared,
                                                    double thickness);

        /// Correlation between the two sides, which survives a closed region
        /// because it needs no flux, and which for that same reason carries no
        /// controllable signal.
        static double correlationAcross(IntermediateRegion::Kind kind, double c, double mu,
                                        double transverseSquared, double thickness);

        /// Whether a carrier can be modulated at will, which is what separates
        /// a signal from a correlation.
        static bool carriesControllableSignal(IntermediateRegion::Kind kind, double c, double mu,
                                              double transverseSquared, double thickness);
    };

    /// Section comparing the four carriers.
    class ChannelsSection : public Section
    {
    public:
        std::string number() const override { return "19"; }
        std::string title() const override
        {
            return "Four carriers between the regions, and which of them signal";
        }
        void run(Report &report) const override;
    };

}
