#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// How the possible outcomes of a round trip are distributed.
    ///
    /// An outcome carries two labels: which face the particle leaves by, and
    /// how far its orientation turned. The first follows from flux
    /// conservation, which splits a lossless region's weight between
    /// transmission and reflection and leaves nothing over.
    ///
    /// The second admits two incompatible assumptions, both computed here. On
    /// the gauge assumption the orientation carries no physical content, the
    /// relative turn is fixed by the junction conditions, and it vanishes for a
    /// symmetric region. On the ignorance assumption no direction is preferred,
    /// the exit orientation is uniform on the sphere, and the mean turn is the
    /// isotropic average.
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

        /// Probability of a deflected crossing on the
        /// ignorance reading.
        static double signatureProbabilityIsotropic(IntermediateRegion::Kind kind, double c,
                                                    double mu, double transverseSquared,
                                                    double thickness);

        /// The same on the gauge reading with a symmetric region.
        static double signatureProbabilityGauge(IntermediateRegion::Kind kind, double c, double mu,
                                                double transverseSquared, double thickness);
    };

    /// Section computing how the outcomes are distributed.
    class CellDistributionSection : public Section
    {
    public:
        std::string title() const override
        {
            return "How often each outcome happens, and the fork in the answer";
        }
        void run(Report &report) const override;
    };

}
