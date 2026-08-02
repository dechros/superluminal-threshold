#include "particle/CellDistribution.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{
    namespace
    {
        constexpr int kAngleSamples = 20001;

        double integrateSine(double from, double to)
        {
            const double step = (to - from) / (kAngleSamples - 1);
            double total = 0.0;
            for (int i = 0; i < kAngleSamples; ++i)
            {
                const double theta = from + i * step;
                const double weight = (i == 0 || i == kAngleSamples - 1) ? 0.5 : 1.0;
                total += weight * 0.5 * std::sin(theta);
            }
            return total * step;
        }

        double integrateSineMoment(double from, double to)
        {
            const double step = (to - from) / (kAngleSamples - 1);
            double total = 0.0;
            for (int i = 0; i < kAngleSamples; ++i)
            {
                const double theta = from + i * step;
                const double weight = (i == 0 || i == kAngleSamples - 1) ? 0.5 : 1.0;
                total += weight * theta * 0.5 * std::sin(theta);
            }
            return total * step;
        }
    }

    double CellDistribution::exitFarFace(IntermediateRegion::Kind kind, double c, double mu,
                                         double transverseSquared, double thickness)
    {
        return IntermediateRegion::transmission(kind, c, mu, transverseSquared, thickness);
    }

    double CellDistribution::exitEntryFace(IntermediateRegion::Kind kind, double c, double mu,
                                           double transverseSquared, double thickness)
    {
        return 1.0 - exitFarFace(kind, c, mu, transverseSquared, thickness);
    }

    double CellDistribution::exitNever(IntermediateRegion::Kind, double, double, double, double)
    {
        return 0.0;
    }

    double CellDistribution::isotropicMeanDeflection()
    {
        return integrateSineMoment(0.0, std::numbers::pi);
    }

    double CellDistribution::isotropicFractionBeyond(double angle)
    {
        return integrateSine(angle, std::numbers::pi);
    }

    double CellDistribution::signatureProbabilityIsotropic(IntermediateRegion::Kind kind, double c,
                                                           double mu, double transverseSquared,
                                                           double thickness)
    {
        return exitFarFace(kind, c, mu, transverseSquared, thickness);
    }

    double CellDistribution::signatureProbabilityGauge(IntermediateRegion::Kind, double, double,
                                                       double, double)
    {
        return 0.0;
    }

    void CellDistributionSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double thickness = 1.0;

        report.subsection("The exit face is settled by flux conservation");
        for (Kind kind : {Kind::Kleinian, Kind::Euclidean, Kind::Degenerate})
        {
            const double far = CellDistribution::exitFarFace(kind, c, mu, transverse, thickness);
            const double entry =
                CellDistribution::exitEntryFace(kind, c, mu, transverse, thickness);
            const double never = CellDistribution::exitNever(kind, c, mu, transverse, thickness);
            report.checkNear(std::format("  {:22} : far {:.4f}, entry {:.4f}, never {:.4f}, "
                                         "summing to one",
                                         IntermediateRegion::name(kind), far, entry, never),
                             far + entry + never - 1.0, 1e-12);
        }
        report.checkNear("nothing is left over, so a lossless region never swallows "
                         "the particle",
                         CellDistribution::exitNever(Kind::Euclidean, c, mu, transverse, thickness),
                         1e-15);
        report.check("three of the nine cells therefore have probability zero "
                     "before the turn is even considered",
                     CellDistribution::exitNever(Kind::Degenerate, c, mu, transverse, thickness) ==
                         0.0);

        report.subsection("The turn on the ignorance reading");
        report.checkNear("a uniform exit orientation gives a mean deflection of a "
                         "right angle",
                         CellDistribution::isotropicMeanDeflection() - std::numbers::pi / 2.0,
                         1e-6);
        report.checkNear("the deflection distribution is normalised",
                         CellDistribution::isotropicFractionBeyond(0.0) - 1.0, 1e-6);
        report.checkNear("half the outcomes are deflected by more than a right angle",
                         CellDistribution::isotropicFractionBeyond(std::numbers::pi / 2.0) - 0.5,
                         1e-6);
        report.check("and almost none come back undeflected, since the undeflected "
                     "direction is a single point on the sphere",
                     CellDistribution::isotropicFractionBeyond(0.05) > 0.999);

        report.subsection("The two readings give opposite predictions");
        for (Kind kind : {Kind::Kleinian, Kind::Euclidean})
        {
            report.check(
                std::format("  {:22} : signature probability {:.4f} on the ignorance "
                            "reading against {:.4f} on the gauge reading",
                            IntermediateRegion::name(kind),
                            CellDistribution::signatureProbabilityIsotropic(kind, c, mu, transverse,
                                                                            thickness),
                            CellDistribution::signatureProbabilityGauge(kind, c, mu, transverse,
                                                                        thickness)),
                CellDistribution::signatureProbabilityIsotropic(kind, c, mu, transverse,
                                                                thickness) >
                    CellDistribution::signatureProbabilityGauge(kind, c, mu, transverse,
                                                                thickness));
        }
        report.checkNear("on the gauge reading a symmetric region turns nothing, so "
                         "the model predicts no signature at all",
                         CellDistribution::signatureProbabilityGauge(Kind::Kleinian, c, mu,
                                                                     transverse, thickness),
                         1e-15);
        report.checkNear("on the ignorance reading every transmitted particle "
                         "carries the signature, so its probability is just the "
                         "transmission",
                         CellDistribution::signatureProbabilityIsotropic(Kind::Kleinian, c, mu,
                                                                         transverse, thickness) -
                             CellDistribution::exitFarFace(Kind::Kleinian, c, mu, transverse,
                                                           thickness),
                         1e-15);

        report.subsection("What the fork means for testability");
        report.check("the two readings are as far apart as they can be, one "
                     "predicting the signature at the transmission rate and the "
                     "other predicting it never",
                     CellDistribution::signatureProbabilityIsotropic(Kind::Kleinian, c, mu,
                                                                     transverse, thickness) >
                             0.5 &&
                         CellDistribution::signatureProbabilityGauge(Kind::Kleinian, c, mu,
                                                                     transverse, thickness) ==
                             0.0);
        report.check("so a single experiment that transmits and looks for free "
                     "deflection separates them",
                     CellDistribution::signatureProbabilityIsotropic(Kind::Euclidean, c, mu,
                                                                     transverse, thickness) >
                         0.0);
    }

}
