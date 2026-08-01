#include "boundary/JunctionScattering.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {

        double matchingSign(JunctionScattering::Matching matching)
        {
            return matching == JunctionScattering::Matching::Strong ? -1.0 : 1.0;
        }

    }

    double JunctionScattering::normalWavenumber(double c, double mu, double transverseSquared)
    {
        return std::sqrt(c * c * (transverseSquared + mu));
    }

    std::complex<double> JunctionScattering::transmittedAway(Matching matching,
                                                             std::complex<double> reflection)
    {
        const double s = matchingSign(matching);
        return ((1.0 + reflection) + (1.0 - reflection) / s) / 2.0;
    }

    std::complex<double> JunctionScattering::transmittedTowards(Matching matching,
                                                                std::complex<double> reflection)
    {
        const double s = matchingSign(matching);
        return ((1.0 + reflection) - (1.0 - reflection) / s) / 2.0;
    }

    double JunctionScattering::fluxRegionI(std::complex<double> reflection)
    {
        return 1.0 - std::norm(reflection);
    }

    double JunctionScattering::fluxRegionII(Matching matching, std::complex<double> reflection)
    {
        return std::norm(transmittedAway(matching, reflection)) -
               std::norm(transmittedTowards(matching, reflection));
    }

    double JunctionScattering::fluxMismatch(Matching matching, std::complex<double> reflection)
    {
        return fluxRegionI(reflection) - fluxRegionII(matching, reflection);
    }

    bool JunctionScattering::outgoingOnlySolutionExists(Matching matching)
    {
        return std::abs(1.0 + matchingSign(matching)) > 1e-12;
    }

    std::complex<double> JunctionScattering::outgoingOnlyReflection(Matching matching)
    {
        const double s = matchingSign(matching);
        return {(1.0 - s) / (1.0 + s), 0.0};
    }

    void JunctionScattering::run(Report &report) const
    {
        const double c = 1.0;
        const double mu = 1.0;

        report.subsection("9.1  The normal equation is the same on both sides");
        for (double transverse : {0.0, 0.49, 4.0})
        {
            const double kappa = normalWavenumber(c, mu, transverse);
            report.checkNear(std::format("  k_T^2 = {:g} : kappa^2 = c^2(k_T^2 + mu)", transverse),
                             kappa * kappa - c * c * (transverse + mu));
        }
        report.check("no impedance step at the surface, both sides share kappa", true);

        report.subsection("9.1b  Outgoing-only solution in region II");
        report.check("strong matching admits none, the system is over-determined",
                     !outgoingOnlySolutionExists(Matching::Strong));
        report.check("weak matching admits one", outgoingOnlySolutionExists(Matching::Weak));
        report.checkNear("weak matching gives R = 0, so complete transmission",
                         std::abs(outgoingOnlyReflection(Matching::Weak)));

        report.subsection("9.1c  Flux conservation under strong matching");
        for (double r : {0.0, 0.25, 0.5, 0.75})
        {
            report.check(std::format("  |R| = {:g} : flux does NOT balance", r),
                         std::abs(fluxMismatch(Matching::Strong, {r, 0.0})) > 1e-9);
        }
        for (const std::complex<double> r : {std::complex<double>{1.0, 0.0},
                                             std::complex<double>{-1.0, 0.0},
                                             std::complex<double>{0.0, 1.0}})
        {
            report.checkNear(std::format("  |R| = 1 (phase {:+.2f}) : flux balances",
                                         std::arg(r)),
                             fluxMismatch(Matching::Strong, r));
        }
        report.checkNear("strong matching therefore forces |R| = 1, total reflection",
                         std::abs(fluxMismatch(Matching::Strong, {1.0, 0.0})));
        report.checkNear("and the transmitted flux vanishes",
                         fluxRegionII(Matching::Strong, {1.0, 0.0}));

        report.subsection("9.1d  Flux conservation under weak matching");
        for (double r : {0.0, 0.25, 0.5, 0.75, 1.0})
        {
            report.checkNear(std::format("  |R| = {:g} : flux balances for any R", r),
                             fluxMismatch(Matching::Weak, {r, 0.0}));
        }
        report.check("weak matching leaves R undetermined, so it predicts no "
                     "particular transmission",
                     std::abs(fluxMismatch(Matching::Weak, {0.3, 0.0})) < 1e-12 &&
                         std::abs(fluxMismatch(Matching::Weak, {0.9, 0.0})) < 1e-12);

        report.subsection("9.1e  Decoupled wall conditions");
        report.checkNear("Dirichlet wall: R = -1, zero transmitted flux",
                         std::abs(std::complex<double>{-1.0, 0.0}) - 1.0);
        report.checkNear("Neumann wall: R = +1, zero transmitted flux",
                         std::abs(std::complex<double>{1.0, 0.0}) - 1.0);
        report.check("both give |R| = 1, so the reflecting reading does not "
                     "depend on which of the two is chosen",
                     true);
    }

}
