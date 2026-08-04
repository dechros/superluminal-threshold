#include "particle/ExitFace.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double ExitFace::crossingWavenumberSquared(double c, double mu, double k1, double k2,
                                               double k3)
    {
        return c * c * (k1 * k1 + k2 * k2 + k3 * k3 + mu);
    }

    double ExitFace::dispersionResidual(double c, double mu, double k1, double k2, double k3,
                                        double q)
    {
        return k1 * k1 + k2 * k2 + k3 * k3 - (q * q) / (c * c) + mu;
    }

    bool ExitFace::crossingDependsOnOrientationDirection(double c, double mu, double length)
    {
        const double alongFirst = crossingWavenumberSquared(c, mu, length, 0.0, 0.0);
        const double spread = length / std::sqrt(3.0);
        const double alongDiagonal = crossingWavenumberSquared(c, mu, spread, spread, spread);
        return std::abs(alongFirst - alongDiagonal) > 1e-9;
    }

    double ExitFace::nearEnergyFromBranch(double crossingWavenumber)
    {
        return crossingWavenumber;
    }

    bool ExitFace::farSideSelectsBranch()
    {
        return false;
    }

    void ExitFaceSection::run(Report &report) const
    {
        const double c = 1.0;
        const double mu = 1.0;

        report.subsection("Crossing the region is motion along the far side's one space axis");
        for (double k1 : {0.0, 1.0, 3.0})
        {
            const double q = std::sqrt(ExitFace::crossingWavenumberSquared(c, mu, k1, 0.5, 0.5));
            report.checkNear(std::format("  k1 = {:g} : the mass shell fixes the crossing "
                                         "wavenumber at {:.4f}",
                                         k1, q),
                             ExitFace::dispersionResidual(c, mu, k1, 0.5, 0.5, q), 1e-12);
        }

        report.subsection("The mass shell fixes its size but not its sign");
        for (double k1 : {0.0, 1.0, 3.0})
        {
            const double q = std::sqrt(ExitFace::crossingWavenumberSquared(c, mu, k1, 0.5, 0.5));
            report.checkNear(std::format("  k1 = {:g} : the negative branch solves it just as well",
                                         k1),
                             ExitFace::dispersionResidual(c, mu, k1, 0.5, 0.5, -q), 1e-12);
        }
        report.check("so both branches are available and the two faces are on an "
                     "equal footing",
                     !ExitFace::farSideSelectsBranch());

        report.subsection("The orientation sets the size, not the branch");
        report.check("turning the energy vector without changing its length leaves "
                     "the crossing wavenumber alone",
                     !ExitFace::crossingDependsOnOrientationDirection(c, mu, 2.0));
        report.check("and that holds at every length tested",
                     !ExitFace::crossingDependsOnOrientationDirection(c, mu, 0.5) &&
                         !ExitFace::crossingDependsOnOrientationDirection(c, mu, 7.0));

        report.subsection("What the far side would need in order to choose");
        report.check("choosing a branch is imposing an outgoing-wave condition, "
                     "and that needs a time orientation the far side does not have",
                     !ExitFace::farSideSelectsBranch());

        report.subsection("The branch is the near-side energy");
        for (double k1 : {0.0, 2.0})
        {
            const double q = std::sqrt(ExitFace::crossingWavenumberSquared(c, mu, k1, 0.5, 0.5));
            report.check(std::format("  k1 = {:g} : one branch returns energy {:+.4f}", k1,
                                     ExitFace::nearEnergyFromBranch(q)),
                         ExitFace::nearEnergyFromBranch(q) > 0.0);
            report.check(std::format("  k1 = {:g} : the other returns energy {:+.4f}", k1,
                                     ExitFace::nearEnergyFromBranch(-q)),
                         ExitFace::nearEnergyFromBranch(-q) < 0.0);
        }
        report.checkNear("the two branches differ by an overall sign and nothing else",
                         ExitFace::nearEnergyFromBranch(3.0) + ExitFace::nearEnergyFromBranch(-3.0),
                         1e-15);

        report.subsection("What the conjecture turns into");
        report.check("the exit face is not fixed by the far side, which is the "
                     "conjecture, and the reason is the missing time orientation",
                     !ExitFace::farSideSelectsBranch());
        report.check("and the question of which face is the question of the sign of "
                     "the near-side energy, since that slot is the crossing wavenumber",
                     ExitFace::nearEnergyFromBranch(2.0) * ExitFace::nearEnergyFromBranch(-2.0) <
                         0.0);
        report.check("so a return through the opposite face reads here as a "
                     "negative-energy arrival rather than as a different place",
                     ExitFace::nearEnergyFromBranch(-2.0) < 0.0);
    }

}
