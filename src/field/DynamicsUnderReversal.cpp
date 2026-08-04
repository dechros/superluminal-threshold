#include "field/DynamicsUnderReversal.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double DynamicsUnderReversal::dispersionResidual(double frequency, double c, double mu,
                                                     double wavenumberSquared)
    {
        return frequency * frequency - c * c * (wavenumberSquared + mu);
    }

    double DynamicsUnderReversal::operatorResidual(double frequency, double c, double mu,
                                                    double wavenumberSquared, double time,
                                                    double position)
    {
        const double wavenumber = std::sqrt(wavenumberSquared);
        const std::complex<double> phase(0.0, wavenumber * position - frequency * time);
        const std::complex<double> wave = std::exp(phase);
        const std::complex<double> applied =
            (-frequency * frequency + c * c * wavenumberSquared + c * c * mu) * wave;
        return std::abs(applied);
    }

    std::complex<double> DynamicsUnderReversal::oddOrderResidual(double frequency, double c,
                                                                 double mu,
                                                                 double wavenumberSquared,
                                                                 double oddCoefficient)
    {
        const std::complex<double> unit(0.0, 1.0);
        return -frequency * frequency + c * c * (wavenumberSquared + mu) -
               unit * oddCoefficient * frequency;
    }

    double DynamicsUnderReversal::farSideResidual(double rate, double c, double mu,
                                                  double timelikeSquared)
    {
        return rate * rate - c * c * (timelikeSquared + mu);
    }

    void DynamicsUnderReversalSection::run(Report &report) const
    {
        const double c = 1.0;
        const double mu = 1.0;

        report.subsection("Both senses solve the equation, on both sides");
        for (double kSquared : {0.0, 0.25, 4.0, 100.0})
        {
            const double omega = std::sqrt(c * c * (kSquared + mu));
            report.checkNear(std::format("  k^2 = {:<6g} : the forward sense solves it",
                                         kSquared),
                             DynamicsUnderReversal::dispersionResidual(omega, c, mu, kSquared));
            report.checkNear(std::format("  k^2 = {:<6g} : the reversed sense solves the same "
                                         "equation with the same parameters",
                                         kSquared),
                             DynamicsUnderReversal::dispersionResidual(-omega, c, mu, kSquared));
            report.checkNear(std::format("  k^2 = {:<6g} : and on the far side as well",
                                         kSquared),
                             DynamicsUnderReversal::farSideResidual(-omega, c, mu, kSquared));
        }

        report.subsection("The operator itself, not only the relation");
        for (double time : {-3.0, 0.0, 1.5})
        {
            const double omega = std::sqrt(c * c * (4.0 + mu));
            report.checkNear(std::format("  t = {:<5g} : the operator annihilates the forward "
                                         "wave",
                                         time),
                             DynamicsUnderReversal::operatorResidual(omega, c, mu, 4.0, time,
                                                                     0.7),
                             1e-12);
            report.checkNear(std::format("  t = {:<5g} : and annihilates the reversed one",
                                         time),
                             DynamicsUnderReversal::operatorResidual(-omega, c, mu, 4.0, time,
                                                                     0.7),
                             1e-12);
        }

        report.subsection("What would have to be added before one sense were preferred");
        const double omega = std::sqrt(c * c * (4.0 + mu));
        report.checkNear("with no term of odd order the forward sense leaves nothing behind",
                         std::abs(DynamicsUnderReversal::oddOrderResidual(omega, c, mu, 4.0, 0.0)));
        report.checkNear("nor does the reversed sense",
                         std::abs(DynamicsUnderReversal::oddOrderResidual(-omega, c, mu, 4.0,
                                                                          0.0)));
        for (double strength : {0.01, 1.0})
        {
            const double forward =
                std::abs(DynamicsUnderReversal::oddOrderResidual(omega, c, mu, 4.0, strength));
            const double reversed =
                std::abs(DynamicsUnderReversal::oddOrderResidual(-omega, c, mu, 4.0, strength));
            report.check(std::format("  strength {:<5g} : a first-order term leaves {:.4f} "
                                     "forward and {:.4f} reversed, so neither is a solution any "
                                     "longer",
                                     strength, forward, reversed),
                         forward > 0.0 && reversed > 0.0);
            report.checkNear(std::format("  strength {:<5g} : and it leaves the same amount "
                                         "either way, so it removes both senses rather than "
                                         "selecting one",
                                         strength),
                             forward - reversed, 1e-12);
        }

        report.subsection("What the result does not say");
        report.check("an equation admitting both senses has been shown; that the two are "
                     "equally occupied has not, and no computation here bears on it, so the "
                     "sense a state carries remains outside what the equation fixes",
                     std::fabs(DynamicsUnderReversal::dispersionResidual(omega, c, mu, 4.0)) <
                             1e-12 &&
                         std::fabs(DynamicsUnderReversal::dispersionResidual(-omega, c, mu,
                                                                            4.0)) < 1e-12);
        report.check("the statement is about the equation modelled here and is not a "
                     "statement about equations in general, the exhibited odd-order term "
                     "being a member of the same family that fails it",
                     std::abs(DynamicsUnderReversal::oddOrderResidual(omega, c, mu, 4.0, 1.0)) >
                         0.0);
        report.check("and the odd-order term is not a model of a preferred sense either, "
                     "since it leaves both senses equally far from solving the equation, so "
                     "breaking the symmetry of an equation is shown here not to supply a "
                     "label by itself",
                     std::fabs(std::abs(DynamicsUnderReversal::oddOrderResidual(omega, c, mu,
                                                                               4.0, 1.0)) -
                               std::abs(DynamicsUnderReversal::oddOrderResidual(-omega, c, mu,
                                                                               4.0, 1.0))) <
                         1e-12);
    }

}
