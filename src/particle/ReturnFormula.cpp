#include "particle/ReturnFormula.h"

#include "core/Report.h"
#include "intermediate/TwoCrossings.h"
#include "particle/ReturnEvent.h"

#include <cmath>
#include <format>

namespace slm
{
    double ReturnFormula::length(const Three &energy)
    {
        return std::sqrt(energy[0] * energy[0] + energy[1] * energy[1] + energy[2] * energy[2]);
    }

    double ReturnFormula::frequency(const Three &energy, double c, double mu)
    {
        const double magnitude = length(energy);
        return c * std::sqrt(magnitude * magnitude + mu);
    }

    double ReturnFormula::transverseSquared(const Three &energy)
    {
        return energy[1] * energy[1] + energy[2] * energy[2];
    }

    double ReturnFormula::outsideWavenumber(const Three &energy)
    {
        return std::abs(energy[0]);
    }

    double ReturnFormula::interiorDecay(const Three &energy, IntermediateRegion::Kind kind)
    {
        const int turned = IntermediateRegion::flippedDirections(kind);
        if (turned < 0)
        {
            return 0.0;
        }
        const double squared =
            (2.0 * turned / 3.0) * transverseSquared(energy) - energy[0] * energy[0];
        return squared > 0.0 ? std::sqrt(squared) : 0.0;
    }

    bool ReturnFormula::isBarrier(const Three &energy, IntermediateRegion::Kind kind)
    {
        const int turned = IntermediateRegion::flippedDirections(kind);
        if (turned < 0)
        {
            return true;
        }
        return (2.0 * turned / 3.0) * transverseSquared(energy) > energy[0] * energy[0];
    }

    double ReturnFormula::saturatedElapsed(const Three &energy, IntermediateRegion::Kind kind,
                                           double c, double mu)
    {
        const double kappa = outsideWavenumber(energy);
        const double beta = interiorDecay(energy, kind);
        if (kappa <= 0.0 || beta <= 0.0 || c <= 0.0)
        {
            return 0.0;
        }
        return 2.0 * frequency(energy, c, mu) / (c * c * kappa * beta);
    }

    double ReturnFormula::elapsedAtThickness(const Three &energy, IntermediateRegion::Kind kind,
                                             double c, double mu, double thickness)
    {
        const double kappa = outsideWavenumber(energy);
        const double beta = interiorDecay(energy, kind);
        if (kappa <= 0.0 || beta <= 0.0 || c <= 0.0 || thickness <= 0.0)
        {
            return 0.0;
        }
        const double omega = frequency(energy, c, mu);
        const double difference = kappa * kappa - beta * beta;
        const double t = std::tanh(beta * thickness);
        const double u = 2.0 * kappa * beta / (difference * t);
        const double dKappa = omega / (c * c * kappa);
        const double dBeta = -omega / (c * c * beta);
        const double dT = (1.0 - t * t) * thickness * dBeta;
        const double numerator = 2.0 * (dKappa * beta + kappa * dBeta);
        const double dDifference = 2.0 * (kappa * dKappa - beta * dBeta);
        const double du = (numerator * difference * t -
                           2.0 * kappa * beta * (dDifference * t + difference * dT)) /
                          (difference * difference * t * t);
        return -du / (1.0 + u * u);
    }

    double ReturnFormula::crossingDisplacement(int branch, double thickness)
    {
        return branch > 0 ? thickness : 0.0;
    }

    double ReturnFormula::transverseFactor(double thickness, double c, double mu)
    {
        return ReturnEvent::transverseFactor(thickness, c, mu);
    }

    std::array<double, 2> ReturnFormula::transverseDisplacement(const Three &energy,
                                                                double thickness, double c,
                                                                double mu)
    {
        const double magnitude = length(energy);
        if (magnitude <= 0.0)
        {
            return {0.0, 0.0};
        }
        const double factor = transverseFactor(thickness, c, mu);
        return {factor * energy[1] / magnitude, factor * energy[2] / magnitude};
    }

    bool ReturnFormula::agreesWithScattering(const Three &energy, IntermediateRegion::Kind kind,
                                             double c, double mu, double thickness,
                                             double tolerance)
    {
        const double fromScattering = TwoCrossings::returnDelay(
            kind, frequency(energy, c, mu), c, mu, transverseSquared(energy), thickness);
        const double fromFormula = elapsedAtThickness(energy, kind, c, mu, thickness);
        return std::abs(fromScattering - fromFormula) <= tolerance;
    }

    void ReturnFormulaSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const ReturnFormula::Three probe{1.685230, 1.6, 1.2};

        report.subsection("The outside wavenumber is a coordinate, not a function of one");
        for (const ReturnFormula::Three &energy :
             {ReturnFormula::Three{1.5, 2.0, 1.0}, ReturnFormula::Three{0.4, 3.0, 2.0},
              ReturnFormula::Three{2.6, 0.5, 0.5}})
        {
            const double fromComponents = ReturnFormula::outsideWavenumber(energy);
            const double fromDispersion = std::sqrt(TwoCrossings::outsideSquared(
                ReturnFormula::frequency(energy, c, mu), c, mu,
                ReturnFormula::transverseSquared(energy)));
            report.checkNear(std::format("  E = ({:g}, {:g}, {:g}) : |E1| = {:.6f} against the "
                                         "dispersion's {:.6f}",
                                         energy[0], energy[1], energy[2], fromComponents,
                                         fromDispersion),
                             fromComponents - fromDispersion, 1e-12);
        }
        report.check("so the mass shell makes the normal wavenumber equal to the first "
                     "component exactly, which is what shortens the whole formula",
                     std::abs(ReturnFormula::outsideWavenumber(probe) -
                              std::sqrt(TwoCrossings::outsideSquared(
                                  ReturnFormula::frequency(probe, c, mu), c, mu,
                                  ReturnFormula::transverseSquared(probe)))) < 1e-12);

        report.subsection("Whether the crossing is a barrier is an inequality in the components");
        for (const ReturnFormula::Three &energy :
             {ReturnFormula::Three{1.0, 2.0, 2.0}, ReturnFormula::Three{4.0, 0.5, 0.5}})
        {
            report.check(std::format("  E = ({:g}, {:g}, {:g}) : 2(E2^2 + E3^2) = {:.4f} against "
                                     "E1^2 = {:.4f}, so it is {}",
                                     energy[0], energy[1], energy[2],
                                     2.0 * ReturnFormula::transverseSquared(energy),
                                     energy[0] * energy[0],
                                     ReturnFormula::isBarrier(energy, Kind::Euclidean)
                                         ? "a barrier"
                                         : "a passage"),
                         ReturnFormula::isBarrier(energy, Kind::Euclidean) ==
                             (2.0 * ReturnFormula::transverseSquared(energy) >
                              energy[0] * energy[0]));
        }

        report.subsection("The elapsed time in closed form, with no thickness in it");
        report.check(std::format("  the formula gives {:.6f}",
                                 ReturnFormula::saturatedElapsed(probe, Kind::Euclidean, c, mu)),
                     ReturnFormula::saturatedElapsed(probe, Kind::Euclidean, c, mu) > 0.0);
        for (double thickness : {4.0, 8.0, 16.0, 32.0})
        {
            const double fromScattering = TwoCrossings::returnDelay(
                Kind::Euclidean, ReturnFormula::frequency(probe, c, mu), c, mu,
                ReturnFormula::transverseSquared(probe), thickness);
            report.checkNear(std::format("  d = {:5g} : the scattering calculation gives {:.6f}",
                                         thickness, fromScattering),
                             fromScattering -
                                 ReturnFormula::saturatedElapsed(probe, Kind::Euclidean, c, mu),
                             1e-6);
        }
        report.check("the closed form carries no thickness, so the saturation is an "
                     "identity here rather than something noticed in a table",
                     ReturnFormula::saturatedElapsed(probe, Kind::Euclidean, c, mu) > 0.0);

        report.subsection("The finite-thickness form and its agreement");
        for (double thickness : {1.0, 2.0, 4.0, 16.0})
        {
            report.check(std::format("  d = {:5g} : formula {:.6f} against scattering {:.6f}",
                                     thickness,
                                     ReturnFormula::elapsedAtThickness(probe, Kind::Euclidean, c,
                                                                        mu, thickness),
                                     TwoCrossings::returnDelay(
                                         Kind::Euclidean, ReturnFormula::frequency(probe, c, mu), c,
                                         mu, ReturnFormula::transverseSquared(probe), thickness)),
                         ReturnFormula::agreesWithScattering(probe, Kind::Euclidean, c, mu,
                                                             thickness, 1e-6));
        }
        report.check("the formula reproduces the scattering calculation at every "
                     "thickness, so it is the same map written differently and not an "
                     "approximation to it",
                     ReturnFormula::agreesWithScattering(probe, Kind::Euclidean, c, mu, 1.0, 1e-6) &&
                         ReturnFormula::agreesWithScattering(probe, Kind::Euclidean, c, mu, 16.0,
                                                             1e-6));

        report.subsection("The whole event, coordinate by coordinate");
        for (int branch : {1, -1})
        {
            const ReturnEvent::State state{probe, branch};
            const ReturnEvent::Event scanned =
                ReturnEvent::map(state, Kind::Euclidean, c, mu, 2.0);
            const std::array<double, 2> transverse =
                ReturnFormula::transverseDisplacement(probe, 2.0, c, mu);
            report.check(std::format("  branch {:+d} : t = {:.4f}, x = {:.4f}, y = {:+.4f}, "
                                     "z = {:+.4f}",
                                     branch,
                                     ReturnFormula::elapsedAtThickness(probe, Kind::Euclidean, c,
                                                                        mu, 2.0),
                                     ReturnFormula::crossingDisplacement(branch, 2.0),
                                     transverse[0], transverse[1]),
                         std::abs(ReturnFormula::crossingDisplacement(branch, 2.0) -
                                  scanned.crossing) < 1e-12 &&
                             std::abs(transverse[0] - scanned.transverseFirst) < 1e-12 &&
                             std::abs(transverse[1] - scanned.transverseSecond) < 1e-12);
        }
        report.check("every coordinate of the scanned event is reproduced by the "
                     "formula, so the scan is now a check on the formula rather than "
                     "the only way to the answer",
                     ReturnFormula::agreesWithScattering(probe, Kind::Euclidean, c, mu, 2.0, 1e-6));
    }

}
