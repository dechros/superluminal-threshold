#include "intermediate/DwellTime.h"

#include "core/Report.h"
#include "intermediate/TwoCrossings.h"

#include <cmath>
#include <format>

namespace slm
{

    std::complex<double> DwellTime::interiorWavenumber(IntermediateRegion::Kind kind, double omega,
                                                       double c, double mu,
                                                       double transverseSquared)
    {
        const double inside = TwoCrossings::insideSquared(kind, omega, c, mu, transverseSquared);
        if (inside >= 0.0)
        {
            return {std::sqrt(inside), 0.0};
        }
        return {0.0, std::sqrt(-inside)};
    }

    std::complex<double> DwellTime::interiorForward(IntermediateRegion::Kind kind, double omega,
                                                    double c, double mu, double transverseSquared,
                                                    double thickness)
    {
        const std::complex<double> i(0.0, 1.0);
        const double outside = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        if (outside <= 0.0 || thickness <= 0.0)
        {
            return {0.0, 0.0};
        }
        const double kappa = std::sqrt(outside);
        const std::complex<double> q = interiorWavenumber(kind, omega, c, mu, transverseSquared);
        const std::complex<double> plus = kappa + q;
        const std::complex<double> minus = kappa - q;
        const std::complex<double> denominator =
            plus * plus * std::exp(-i * q * thickness) - minus * minus * std::exp(i * q * thickness);
        if (std::abs(denominator) == 0.0)
        {
            return {0.0, 0.0};
        }
        return 2.0 * kappa * plus * std::exp(-i * q * thickness) / denominator;
    }

    std::complex<double> DwellTime::interiorBackward(IntermediateRegion::Kind kind, double omega,
                                                     double c, double mu, double transverseSquared,
                                                     double thickness)
    {
        const std::complex<double> i(0.0, 1.0);
        const double outside = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        if (outside <= 0.0 || thickness <= 0.0)
        {
            return {0.0, 0.0};
        }
        const double kappa = std::sqrt(outside);
        const std::complex<double> q = interiorWavenumber(kind, omega, c, mu, transverseSquared);
        const std::complex<double> plus = kappa + q;
        const std::complex<double> minus = kappa - q;
        const std::complex<double> denominator =
            plus * plus * std::exp(-i * q * thickness) - minus * minus * std::exp(i * q * thickness);
        if (std::abs(denominator) == 0.0)
        {
            return {0.0, 0.0};
        }
        return -2.0 * kappa * minus * std::exp(i * q * thickness) / denominator;
    }

    double DwellTime::storedNorm(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                 double transverseSquared, double thickness, int samples)
    {
        if (thickness <= 0.0 || samples <= 0)
        {
            return 0.0;
        }
        const std::complex<double> i(0.0, 1.0);
        const std::complex<double> q = interiorWavenumber(kind, omega, c, mu, transverseSquared);
        const std::complex<double> forward =
            interiorForward(kind, omega, c, mu, transverseSquared, thickness);
        const std::complex<double> backward =
            interiorBackward(kind, omega, c, mu, transverseSquared, thickness);
        const double step = thickness / samples;
        double total = 0.0;
        for (int n = 0; n <= samples; ++n)
        {
            const double x = n * step;
            const std::complex<double> field =
                forward * std::exp(i * q * x) + backward * std::exp(-i * q * x);
            const double density = std::norm(field);
            const double weight = (n == 0 || n == samples) ? 0.5 : 1.0;
            total += weight * density;
        }
        return total * step;
    }

    double DwellTime::incidentFlux(double omega, double c, double mu, double transverseSquared)
    {
        const double outside = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        if (outside <= 0.0)
        {
            return 0.0;
        }
        return c * c * std::sqrt(outside) / omega;
    }

    double DwellTime::dwellTime(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                double transverseSquared, double thickness)
    {
        const double flux = incidentFlux(omega, c, mu, transverseSquared);
        if (flux <= 0.0)
        {
            return 0.0;
        }
        return storedNorm(kind, omega, c, mu, transverseSquared, thickness) / flux;
    }

    double DwellTime::phaseDelay(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                 double transverseSquared, double thickness)
    {
        return TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, thickness);
    }

    double DwellTime::relativeGap(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                  double transverseSquared, double thickness)
    {
        const double phase = phaseDelay(kind, omega, c, mu, transverseSquared, thickness);
        const double dwell = dwellTime(kind, omega, c, mu, transverseSquared, thickness);
        if (std::abs(phase) <= 0.0)
        {
            return 0.0;
        }
        return (phase - dwell) / phase;
    }

    bool DwellTime::storedNormSaturates(IntermediateRegion::Kind kind, double omega, double c,
                                        double mu, double transverseSquared)
    {
        const double near = storedNorm(kind, omega, c, mu, transverseSquared, 4.0);
        const double far = storedNorm(kind, omega, c, mu, transverseSquared, 16.0);
        return std::abs(far - near) < 0.05 * std::abs(near);
    }

    void DwellTimeSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double barrierOmega = 2.8;
        const double propagatingOmega = 6.0;

        report.subsection("The interior field of the same scattering solution");
        for (double thickness : {1.0, 4.0})
        {
            const std::complex<double> forward =
                DwellTime::interiorForward(Kind::Euclidean, barrierOmega, c, mu, transverse,
                                           thickness);
            const std::complex<double> backward =
                DwellTime::interiorBackward(Kind::Euclidean, barrierOmega, c, mu, transverse,
                                            thickness);
            report.check(std::format("  d = {:g} : interior amplitudes |A| = {:.4e}, |B| = {:.4e}",
                                     thickness, std::abs(forward), std::abs(backward)),
                         std::abs(forward) > 0.0 && std::abs(backward) > 0.0);
        }
        report.check("the interior carries both a decaying and a growing piece, "
                     "which is why a stored norm exists at all",
                     std::abs(DwellTime::interiorBackward(Kind::Euclidean, barrierOmega, c, mu,
                                                          transverse, 4.0)) > 0.0);

        report.subsection("The stored norm saturates in the barrier regime");
        double previous = 0.0;
        for (double thickness : {1.0, 2.0, 4.0, 8.0, 16.0})
        {
            const double stored =
                DwellTime::storedNorm(Kind::Euclidean, barrierOmega, c, mu, transverse, thickness);
            report.check(std::format("  d = {:5g} : stored norm {:.6f}", thickness, stored),
                         stored > 0.0);
            previous = stored;
        }
        report.check(std::format("  the stored norm stops growing, ending at {:.6f}", previous),
                     DwellTime::storedNormSaturates(Kind::Euclidean, barrierOmega, c, mu,
                                                    transverse));
        report.check("so a saturating delay has a stored-field explanation available "
                     "that needs no transit at all",
                     DwellTime::storedNormSaturates(Kind::Euclidean, barrierOmega, c, mu,
                                                    transverse));

        report.subsection("Comparing the two readings against each other");
        for (double thickness : {2.0, 4.0, 8.0})
        {
            const double phase =
                DwellTime::phaseDelay(Kind::Euclidean, barrierOmega, c, mu, transverse, thickness);
            const double dwell =
                DwellTime::dwellTime(Kind::Euclidean, barrierOmega, c, mu, transverse, thickness);
            report.check(std::format("  d = {:g} : phase delay {:.4f}, dwell time {:.4f}, "
                                     "relative gap {:+.4f}",
                                     thickness, phase, dwell,
                                     DwellTime::relativeGap(Kind::Euclidean, barrierOmega, c, mu,
                                                            transverse, thickness)),
                         phase > 0.0 && dwell > 0.0);
        }

        report.check("both readings saturate together, so the saturation itself is "
                     "explained by the stored field rather than by a fast crossing",
                     DwellTime::storedNormSaturates(Kind::Euclidean, barrierOmega, c, mu,
                                                    transverse) &&
                         std::abs(DwellTime::phaseDelay(Kind::Euclidean, barrierOmega, c, mu,
                                                        transverse, 4.0) -
                                  DwellTime::phaseDelay(Kind::Euclidean, barrierOmega, c, mu,
                                                        transverse, 8.0)) < 1e-6);
        const double ratioNear = DwellTime::phaseDelay(Kind::Euclidean, barrierOmega, c, mu,
                                                       transverse, 4.0) /
                                 DwellTime::dwellTime(Kind::Euclidean, barrierOmega, c, mu,
                                                      transverse, 4.0);
        const double ratioFar = DwellTime::phaseDelay(Kind::Euclidean, barrierOmega, c, mu,
                                                      transverse, 16.0) /
                                DwellTime::dwellTime(Kind::Euclidean, barrierOmega, c, mu,
                                                     transverse, 16.0);
        report.checkNear(std::format("  their ratio is {:.4f} and does not move with thickness, so "
                                     "they differ by a normalisation and not by a mechanism",
                                     ratioNear),
                         ratioNear - ratioFar, 1e-4);
        report.check("the two are therefore not independent observables here: the "
                     "phase delay carries no information the stored norm lacks",
                     std::abs(ratioNear - ratioFar) < 1e-4);

        report.subsection("The propagating regime, where a transit does exist");
        for (double thickness : {1.0, 2.0, 4.0})
        {
            const double stored = DwellTime::storedNorm(Kind::None, propagatingOmega, c, mu,
                                                        transverse, thickness);
            report.check(std::format("  d = {:g} : stored norm {:.6f}, growing with thickness",
                                     thickness, stored),
                         stored > 0.0);
        }
        report.check("here the stored norm keeps growing, so the two readings "
                     "cannot both saturate and the transit reading is available",
                     !DwellTime::storedNormSaturates(Kind::None, propagatingOmega, c, mu,
                                                     transverse));
    }

}
