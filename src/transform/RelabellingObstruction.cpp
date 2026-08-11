#include "transform/RelabellingObstruction.h"

#include "core/Report.h"
#include "dynamics/ThresholdField.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kPi = 3.14159265358979323846;
    }

    int RelabellingObstruction::freeDirections(const Matrix4 &metric, double mu)
    {
        int count = 0;
        for (int axis = 0; axis < 4; ++axis)
        {
            const double entry = metric.at(axis, axis);
            if (entry * mu > 0.0)
            {
                ++count;
            }
        }
        return count;
    }

    double RelabellingObstruction::axisMomentum(const Matrix4 &metric, double mu, int axis)
    {
        const double entry = metric.at(axis, axis);
        if (entry * mu <= 0.0)
        {
            return 0.0;
        }
        return std::sqrt(mu / entry);
    }

    int RelabellingObstruction::positiveEntries(double theta)
    {
        int count = 0;
        for (double entry : ThresholdField::metric(theta))
        {
            if (entry > 0.0)
            {
                ++count;
            }
        }
        return count;
    }

    void RelabellingObstructionSection::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();
        const double mu = 1.0;

        report.subsection("What a metric alone cannot tell you");
        report.checkNear("the two metrics share a determinant, so that number does not "
                         "separate them",
                         eta.determinant() - etaPrime.determinant(), 1e-12);
        report.checkNear("  and each determinant is minus one",
                         eta.determinant() + 1.0, 1e-12);
        report.check("the far metric is a permutation of the near one with every sign "
                     "reversed, which is what the objection observes",
                     std::abs(etaPrime.at(3, 3) + 1.0) < 1e-12 &&
                         std::abs(eta.at(0, 0) - 1.0) < 1e-12);

        report.subsection("The count that separates them once a particle is present");
        report.check(std::format("with an ordinary particle the near region admits a real "
                                 "momentum along {} axis",
                                 RelabellingObstruction::freeDirections(eta, mu)),
                     RelabellingObstruction::freeDirections(eta, mu) == 1);
        report.check(std::format("the far region admits one along {}",
                                 RelabellingObstruction::freeDirections(etaPrime, mu)),
                     RelabellingObstruction::freeDirections(etaPrime, mu) == 3);
        report.check("so the two regions differ in a number that no renaming of axes can "
                     "change, because the number counts solutions and not labels",
                     RelabellingObstruction::freeDirections(eta, mu) !=
                         RelabellingObstruction::freeDirections(etaPrime, mu));
        for (int axis = 0; axis < 4; ++axis)
        {
            const double momentum = RelabellingObstruction::axisMomentum(eta, mu, axis);
            const bool admits = momentum > 0.0;
            report.check(std::format("  near-side axis {} {} a real on-shell momentum", axis,
                                     admits ? "admits" : "does not admit"),
                         admits == (axis == 0));
        }

        report.subsection("What the relabelling costs");
        const Matrix4 reversed = -1.0 * eta;
        report.check(std::format("reversing every sign of the near metric leaves {} free "
                                 "directions for the same particle, which is the far-side "
                                 "answer",
                                 RelabellingObstruction::freeDirections(reversed, mu)),
                     RelabellingObstruction::freeDirections(reversed, mu) == 3);
        report.check(std::format("but reversing the mass parameter with it returns {}, the "
                                 "near-side answer",
                                 RelabellingObstruction::freeDirections(reversed, -mu)),
                     RelabellingObstruction::freeDirections(reversed, -mu) == 1);
        report.check("so the pair of metric and mass parameter is what the relabelling acts "
                     "on, and it acts by reversing both",
                     RelabellingObstruction::freeDirections(reversed, -mu) ==
                         RelabellingObstruction::freeDirections(eta, mu));
        report.check("a reversed mass parameter is an imaginary mass, so the relabelling "
                     "exchanges ordinary matter for tachyonic matter rather than exchanging "
                     "one convention for another",
                     -mu < 0.0);
        report.check("holding the particle fixed therefore holds the two regions apart, and "
                     "the objection survives only for a particle nobody has",
                     RelabellingObstruction::freeDirections(etaPrime, mu) !=
                         RelabellingObstruction::freeDirections(eta, mu));

        report.subsection("A second obstruction, with no particle in it");
        int belowQuarter = 0;
        int aboveQuarter = 0;
        for (double theta : {0.0, kPi / 16.0, kPi / 8.0, 3.0 * kPi / 16.0})
        {
            const int count = RelabellingObstruction::positiveEntries(theta);
            report.check(std::format("  theta = {:.4f} : {} positive entries", theta, count),
                         count == 1);
            if (count == 1)
            {
                ++belowQuarter;
            }
        }
        for (double theta : {5.0 * kPi / 16.0, 3.0 * kPi / 8.0, 7.0 * kPi / 16.0, kPi / 2.0})
        {
            const int count = RelabellingObstruction::positiveEntries(theta);
            report.check(std::format("  theta = {:.4f} : {} positive entries", theta, count),
                         count == 3);
            if (count == 3)
            {
                ++aboveQuarter;
            }
        }
        report.check("the count takes exactly two values along the family and changes only "
                     "where the metric degenerates",
                     belowQuarter == 4 && aboveQuarter == 4);
        report.check("so the two regions lie in different components of the nondegenerate "
                     "metrics, and no continuous relabelling reaches one from the other",
                     ThresholdField::isDegenerate(kPi / 4.0, 1e-9));

        report.subsection("What would dissolve the distinction");
        report.check("a particle of negative mass parameter would count three free "
                     "directions on the near side and one on the far side, exchanging the "
                     "two regions outright",
                     RelabellingObstruction::freeDirections(eta, -mu) == 3 &&
                         RelabellingObstruction::freeDirections(etaPrime, -mu) == 1);
        report.check("the construction therefore rests on ordinary matter having a real "
                     "mass, which is an assumption it can state and not one it can prove",
                     mu > 0.0);
    }

}
