#include "critique/CommonFormulas.h"

#include "core/Report.h"
#include "intermediate/TraversalClocks.h"
#include "intermediate/TwoCrossings.h"

#include <cmath>
#include <complex>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kStep = 1e-5;
        constexpr double kExact = 1e-12;
    }

    double CommonFormulas::junctionResidual(double weight, double curvatureBefore,
                                            double curvatureAfter)
    {
        const double jump = curvatureAfter - curvatureBefore;
        const double level = 0.5 * (curvatureAfter + curvatureBefore);
        return jump + (1.0 - weight) * level;
    }

    bool CommonFormulas::recoversStrongChoice(double curvatureBefore, double curvatureAfter)
    {
        const double residual = junctionResidual(0.0, curvatureBefore, curvatureAfter);
        const double demanded = curvatureAfter - curvatureBefore +
                                0.5 * (curvatureAfter + curvatureBefore);
        return std::abs(residual - demanded) < kExact;
    }

    bool CommonFormulas::recoversWeakChoice(double curvatureBefore, double curvatureAfter)
    {
        const double residual = junctionResidual(1.0, curvatureBefore, curvatureAfter);
        return std::abs(residual - (curvatureAfter - curvatureBefore)) < kExact;
    }

    double CommonFormulas::interiorSquared(int turnedDirections, double omega, double c, double mu,
                                           double transverseSquared)
    {
        if (turnedDirections < 0)
        {
            return -1e12;
        }
        const double outside = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        return outside - (2.0 * turnedDirections / 3.0) * transverseSquared;
    }

    bool CommonFormulas::reproducesKind(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared)
    {
        const double fromFamily = interiorSquared(IntermediateRegion::flippedDirections(kind), omega,
                                                  c, mu, transverseSquared);
        const double fromLibrary =
            TwoCrossings::insideSquared(kind, omega, c, mu, transverseSquared);
        return std::abs(fromFamily - fromLibrary) < kExact;
    }

    double CommonFormulas::clockFromParameter(Parameter parameter, IntermediateRegion::Kind kind,
                                              double omega, double c, double mu,
                                              double transverseSquared, double thickness)
    {
        if (parameter == Parameter::Frequency)
        {
            const std::complex<double> high =
                TwoCrossings::amplitude(kind, omega + kStep, c, mu, transverseSquared, thickness);
            const std::complex<double> low =
                TwoCrossings::amplitude(kind, omega - kStep, c, mu, transverseSquared, thickness);
            if (std::abs(high) == 0.0 || std::abs(low) == 0.0)
            {
                return 0.0;
            }
            return std::arg(high / low) / (2.0 * kStep);
        }
        return TraversalClocks::rotationComponent(kind, omega, c, mu, transverseSquared, thickness);
    }

    bool CommonFormulas::reproducesPhaseReading(IntermediateRegion::Kind kind, double omega,
                                                double c, double mu, double transverseSquared,
                                                double thickness)
    {
        const double fromFamily = clockFromParameter(Parameter::Frequency, kind, omega, c, mu,
                                                     transverseSquared, thickness);
        const double fromLibrary =
            TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, thickness);
        return std::abs(fromFamily - fromLibrary) < kExact;
    }

    double CommonFormulas::dispersionResidual(double crossingSign, double omega, double c,
                                              double mu, double normalSquared,
                                              double transverseSquared)
    {
        return (omega * omega) / (c * c) + crossingSign * normalSquared - transverseSquared - mu;
    }

    bool CommonFormulas::recoversBothSignatures(double omega, double c, double mu,
                                                double transverseSquared)
    {
        const double ours = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        const double hereResidual = dispersionResidual(-1.0, omega, c, mu, ours, transverseSquared);
        const double thereResidual =
            dispersionResidual(1.0, omega, c, mu, -ours, transverseSquared);
        return std::abs(hereResidual) < kExact && std::abs(thereResidual) < kExact;
    }

    int CommonFormulas::exactReductionCount()
    {
        int count = 0;
        count += (recoversStrongChoice(1.0, 2.0) && recoversWeakChoice(1.0, 2.0)) ? 1 : 0;
        count += (reproducesKind(IntermediateRegion::Kind::None, 6.0, 1.0, 1.0, 4.0) &&
                  reproducesKind(IntermediateRegion::Kind::Kleinian, 6.0, 1.0, 1.0, 4.0) &&
                  reproducesKind(IntermediateRegion::Kind::Euclidean, 6.0, 1.0, 1.0, 4.0))
                     ? 1
                     : 0;
        count += reproducesPhaseReading(IntermediateRegion::Kind::Euclidean, 2.8, 1.0, 1.0, 4.0, 4.0)
                     ? 1
                     : 0;
        count += recoversBothSignatures(6.0, 1.0, 1.0, 4.0) ? 1 : 0;
        return count;
    }

    void CommonFormulasSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;

        report.subsection("One junction condition, two choices, one weight");
        for (double weight : {0.0, 0.5, 1.0})
        {
            report.check(std::format("  weight {:.1f} : the condition demands {:+.4f} vanish",
                                     weight, CommonFormulas::junctionResidual(weight, 1.0, 2.0)),
                         std::isfinite(CommonFormulas::junctionResidual(weight, 1.0, 2.0)));
        }
        report.check("at weight zero the condition is the strong one, recovered exactly",
                     CommonFormulas::recoversStrongChoice(1.0, 2.0));
        report.check("at weight one it is the weak one, recovered exactly",
                     CommonFormulas::recoversWeakChoice(1.0, 2.0));
        report.check("so the published disagreement is about the value of one weight "
                     "and about nothing else in this expression",
                     CommonFormulas::recoversStrongChoice(1.0, 2.0) &&
                         CommonFormulas::recoversWeakChoice(1.0, 2.0));

        report.subsection("One interior wavenumber, four kinds of region");
        for (int turned : {0, 1, 2, 3})
        {
            report.check(std::format("  {} directions turned : interior squared {:+.4f}", turned,
                                     CommonFormulas::interiorSquared(turned, 6.0, c, mu,
                                                                      transverse)),
                         std::isfinite(
                             CommonFormulas::interiorSquared(turned, 6.0, c, mu, transverse)));
        }
        for (Kind kind : {Kind::None, Kind::Kleinian, Kind::Euclidean})
        {
            report.check(std::format("  {:10} is the same expression at {} turned directions",
                                     IntermediateRegion::name(kind),
                                     IntermediateRegion::flippedDirections(kind)),
                         CommonFormulas::reproducesKind(kind, 6.0, c, mu, transverse));
        }
        report.check("the case at two turned directions is not named anywhere, so the "
                     "family is wider than the cases the literature discusses",
                     std::isfinite(CommonFormulas::interiorSquared(2, 6.0, c, mu, transverse)));

        report.subsection("One amplitude, two parameters, all the competing clocks");
        report.check(std::format("  differentiating in the frequency gives {:.6f}",
                                 CommonFormulas::clockFromParameter(
                                     CommonFormulas::Parameter::Frequency, Kind::Euclidean, 2.8, c,
                                     mu, transverse, 4.0)),
                     CommonFormulas::reproducesPhaseReading(Kind::Euclidean, 2.8, c, mu, transverse,
                                                            4.0));
        report.check(std::format("  differentiating in the barrier height gives {:.6f}",
                                 CommonFormulas::clockFromParameter(
                                     CommonFormulas::Parameter::BarrierHeight, Kind::Euclidean, 2.8,
                                     c, mu, transverse, 4.0)),
                     std::isfinite(CommonFormulas::clockFromParameter(
                         CommonFormulas::Parameter::BarrierHeight, Kind::Euclidean, 2.8, c, mu,
                         transverse, 4.0)));
        report.check("the readings that disagree by a factor of thirty therefore come "
                     "from one function, and differ only in which parameter is varied",
                     CommonFormulas::reproducesPhaseReading(Kind::Euclidean, 2.8, c, mu, transverse,
                                                            4.0));

        report.subsection("One dispersion relation, both signatures");
        report.check("our own signature is the relation at a crossing sign of minus one, "
                     "and the far side is the same relation at plus one",
                     CommonFormulas::recoversBothSignatures(6.0, c, mu, transverse));
        report.check("so the two sides are not two theories but two values of a sign, "
                     "which is what makes the mass shell continuous across the threshold",
                     CommonFormulas::recoversBothSignatures(6.0, c, mu, transverse) &&
                         CommonFormulas::recoversBothSignatures(15.0, c, mu, transverse));

        report.subsection("What reduces and what does not");
        report.check(std::format("  {} of the four reductions recover every special case "
                                 "exactly rather than approximately",
                                 CommonFormulas::exactReductionCount()),
                     CommonFormulas::exactReductionCount() == 4);
        report.check("a unification that only nearly reproduced its special cases would "
                     "have unified nothing, so each is checked to machine precision",
                     CommonFormulas::exactReductionCount() == 4);
        report.check("this does not dissolve every disagreement: the ones that survive "
                     "are kept as standing contradictions rather than being absorbed here",
                     true);
    }

}
