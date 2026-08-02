#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// How often each of the nine cells occurs.
    ///
    /// The table of section 18 says what each outcome looks like here. It says
    /// nothing about which outcomes happen, and without that it is a dictionary
    /// rather than a prediction. This section supplies the missing half, and
    /// finds that it splits in two.
    ///
    /// The exit face is settled: flux conservation across a lossless region
    /// gives the transmitted and reflected weights and leaves nothing over, so
    /// the particle always comes out somewhere.
    ///
    /// The turn is not settled, and the two readings of it disagree completely.
    /// On the gauge reading the far-side orientation carries no physical
    /// content, so the relative turn between the two faces is fixed by the
    /// junction conditions and vanishes for a symmetric region. On the
    /// ignorance reading the far side has no preferred direction at all, so the
    /// exit orientation is distributed uniformly and the particle returns
    /// pointing anywhere. The article computes both rather than choosing.
    class CellDistribution
    {
    public:
        /// Probability of leaving by the far face.
        static double exitFarFace(IntermediateRegion::Kind kind, double c, double mu,
                                  double transverseSquared, double thickness);

        /// Probability of returning by the entry face.
        static double exitEntryFace(IntermediateRegion::Kind kind, double c, double mu,
                                    double transverseSquared, double thickness);

        /// Probability of never coming out, which flux conservation forbids
        /// unless the junction is dissipative.
        static double exitNever(IntermediateRegion::Kind kind, double c, double mu,
                                double transverseSquared, double thickness);

        /// Mean deflection when the exit orientation is uniform on the sphere.
        static double isotropicMeanDeflection();

        /// Fraction of isotropic outcomes deflected by more than the given angle.
        static double isotropicFractionBeyond(double angle);

        /// Probability of the model's signature, a deflected crossing, on the
        /// ignorance reading.
        static double signatureProbabilityIsotropic(IntermediateRegion::Kind kind, double c,
                                                    double mu, double transverseSquared,
                                                    double thickness);

        /// The same on the gauge reading with a symmetric region.
        static double signatureProbabilityGauge(IntermediateRegion::Kind kind, double c, double mu,
                                                double transverseSquared, double thickness);
    };

    /// Section supplying the distribution the table of section 18 lacked.
    class CellDistributionSection : public Section
    {
    public:
        std::string number() const override { return "18.7"; }
        std::string title() const override
        {
            return "How often each outcome happens, and the fork in the answer";
        }
        void run(Report &report) const override;
    };

}
