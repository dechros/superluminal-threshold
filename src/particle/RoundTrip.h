#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// The accounting for a particle that crosses, spends time on the far side,
    /// and crosses back.
    ///
    /// The journey is two traversals of the same intermediate region, so the
    /// mode weights are acted on twice. Three separate ledgers are kept, since
    /// no one of them captures what is lost: the mode content, which says which
    /// parts of the packet came back; the conserved quantities, which say what
    /// the crossing could not touch; and an information measure, which says how
    /// far the returning distribution is from the one that set out.
    ///
    /// The information ledger is the weakest of the three and is reported as
    /// such. It compares distributions over modes, which is well defined, but
    /// it is not an entropy of states, because the far side has no particle
    /// number and no vacuum to count against.
    class RoundTrip
    {
    public:
        /// Weight of the outgoing distribution at wavenumber k, that is the
        /// incoming weight acted on by two traversals.
        static double returnedWeight(double k, double centre, double spread,
                                     IntermediateRegion::Kind kind, double c, double mu,
                                     double thickness);

        /// Fraction of the packet that survives a single crossing, computed on
        /// the same region so that the two can be compared.
        static double oneWayFraction(double centre, double spread, IntermediateRegion::Kind kind,
                                     double c, double mu, double thickness);

        /// Fraction of the packet that survives both crossings.
        static double survivingFraction(double centre, double spread,
                                        IntermediateRegion::Kind kind, double c, double mu,
                                        double thickness);

        /// Mean wavenumber of what came back.
        static double returnedMean(double centre, double spread, IntermediateRegion::Kind kind,
                                   double c, double mu, double thickness);

        /// Centroid displacement over the whole journey, in units of the
        /// incoming spread.
        static double centroidShiftInSpreads(double centre, double spread,
                                             IntermediateRegion::Kind kind, double c, double mu,
                                             double thickness);

        /// Relative entropy of the returning distribution against the one that
        /// set out, in nats. Zero exactly when the journey changed nothing.
        static double relativeEntropy(double centre, double spread,
                                      IntermediateRegion::Kind kind, double c, double mu,
                                      double thickness);

        /// Shannon entropy of a distribution over the mode grid, used to say
        /// whether the journey sharpened or blurred the packet.
        static double incomingEntropy(double centre, double spread);
        static double returnedEntropy(double centre, double spread,
                                      IntermediateRegion::Kind kind, double c, double mu,
                                      double thickness);
    };

    /// Section keeping the three ledgers of the round trip.
    class RoundTripSection : public Section
    {
    public:
        std::string number() const override { return "15"; }
        std::string title() const override
        {
            return "What came back: mode content, conserved charges, information";
        }
        void run(Report &report) const override;
    };

}
