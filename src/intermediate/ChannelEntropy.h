#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// Entropy of the outcome distribution a threshold leaves behind.
    ///
    /// A mode arriving at the region occupies one channel. What leaves occupies
    /// two, with weights fixed by flux conservation, so the outcome is a
    /// distribution where the input was a point. The Shannon entropy of that
    /// distribution is what this class computes.
    ///
    /// It is a different quantity from the entropy of a mode distribution
    /// computed elsewhere in this project, and the difference is the point of
    /// having both. That one compares the shape of a packet before and after a
    /// journey and can move either way, since a region can sharpen a packet as
    /// well as blur it. This one is the entropy of a two-outcome split and is
    /// non-negative by construction, vanishing exactly when the split is not a
    /// split at all.
    ///
    /// Non-negativity is a property of the definition and is not by itself
    /// evidence of anything. What carries content is where the quantity
    /// vanishes and where it is largest: a threshold that transmits everything
    /// or reflects everything produces none of it, and a threshold that is
    /// evenly divided produces the most possible, ln 2 for two channels.
    class ChannelEntropy
    {
    public:
        /// Binary Shannon entropy in nats, with the convention @f$ 0\ln 0 = 0 @f$.
        static double binaryEntropy(double probability);

        /// Entropy of the outcome distribution of a single crossing.
        static double outcomeEntropy(IntermediateRegion::Kind kind, double c, double mu,
                                     double transverseSquared, double thickness);

        /// Entropy of the incoming state, which occupies one channel and is
        /// therefore zero.
        ///
        /// Present as a function rather than as a literal zero so that the
        /// difference taken below is a difference of two computed quantities,
        /// and so that the assumption it encodes is stated where it is used.
        static double incomingEntropy();

        /// Entropy produced by one crossing.
        static double entropyGain(IntermediateRegion::Kind kind, double c, double mu,
                                  double transverseSquared, double thickness);

        /// Largest entropy a two-channel split can carry, @f$ \ln 2 @f$.
        static double maximalEntropy();

        /// True when the crossing produces no entropy, that is when the outcome
        /// is decided.
        static bool outcomeIsDecided(IntermediateRegion::Kind kind, double c, double mu,
                                     double transverseSquared, double thickness,
                                     double tolerance = 1e-9);

        /// Thickness at which the entropy is largest, found by scanning.
        /// \param maximumThickness Upper end of the scan.
        /// \param samples Number of thicknesses examined.
        static double thicknessOfMaximalEntropy(IntermediateRegion::Kind kind, double c, double mu,
                                                double transverseSquared,
                                                double maximumThickness = 20.0,
                                                int samples = 20000);

        /// Largest entropy reached over that scan.
        static double maximalEntropyOverThickness(IntermediateRegion::Kind kind, double c,
                                                  double mu, double transverseSquared,
                                                  double maximumThickness = 20.0,
                                                  int samples = 20000);

        /// True when the region reaches an even split at some thickness, so that
        /// its entropy attains the two-channel bound.
        static bool reachesEvenSplit(IntermediateRegion::Kind kind, double c, double mu,
                                     double transverseSquared, double maximumThickness = 20.0,
                                     int samples = 20000, double tolerance = 1e-6);
    };

    /// Section computing where a crossing produces entropy and where it does
    /// not.
    class ChannelEntropySection : public Section
    {
    public:
        std::string title() const override
        {
            return "Which crossings produce entropy, and which are already decided";
        }
        void run(Report &report) const override;
    };

}
