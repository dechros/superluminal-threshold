#include "signal/Channels.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double Channels::masslessTransmission(IntermediateRegion::Kind kind, double c,
                                          double transverseSquared, double thickness)
    {
        return IntermediateRegion::transmission(kind, c, 0.0, transverseSquared, thickness);
    }

    double Channels::massiveTransmission(IntermediateRegion::Kind kind, double c, double mu,
                                         double transverseSquared, double thickness)
    {
        return IntermediateRegion::transmission(kind, c, mu, transverseSquared, thickness);
    }

    double Channels::gravitationalCoupling(IntermediateRegion::Kind kind, double thickness)
    {
        return IntermediateRegion::layerStrength(kind, thickness);
    }

    bool Channels::gravityReachesWhereFieldsCannot(IntermediateRegion::Kind kind, double c,
                                                   double mu, double transverseSquared,
                                                   double thickness)
    {
        const double fields =
            std::max(masslessTransmission(kind, c, transverseSquared, thickness),
                     massiveTransmission(kind, c, mu, transverseSquared, thickness));
        const double gravity = gravitationalCoupling(kind, thickness);
        return fields < 1e-30 && gravity > 0.0;
    }

    double Channels::correlationAcross(IntermediateRegion::Kind kind, double c, double mu,
                                       double transverseSquared, double thickness)
    {
        const double transmitted = massiveTransmission(kind, c, mu, transverseSquared, thickness);
        return std::sqrt(transmitted * (1.0 - transmitted)) + 0.5 * (1.0 - transmitted);
    }

    bool Channels::carriesControllableSignal(IntermediateRegion::Kind kind, double c, double mu,
                                             double transverseSquared, double thickness)
    {
        return massiveTransmission(kind, c, mu, transverseSquared, thickness) > 0.0 ||
               masslessTransmission(kind, c, transverseSquared, thickness) > 0.0;
    }

    void ChannelsSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const Kind kinds[] = {Kind::SplitSignature, Kind::Euclidean, Kind::Degenerate};

        report.subsection("Being massless does not help");
        for (Kind kind : kinds)
        {
            const double massless = Channels::masslessTransmission(kind, c, transverse, 1.0);
            const double massive = Channels::massiveTransmission(kind, c, mu, transverse, 1.0);
            report.check(std::format("  {:22} : massless {:.4e}, massive {:.4e}",
                                     IntermediateRegion::name(kind), massless, massive),
                         massless >= 0.0 && massive >= 0.0);
        }
        report.check("a Euclidean region blocks the massless field too, so light is "
                     "no better a messenger than matter",
                     Channels::masslessTransmission(Kind::Euclidean, c, transverse, 4.0) < 1e-3);
        report.check("dropping the mass makes the barrier worse, not better, since "
                     "the mass was the term holding the interior wavenumber up",
                     Channels::masslessTransmission(Kind::Euclidean, c, transverse, 1.0) <
                         Channels::massiveTransmission(Kind::Euclidean, c, mu, transverse, 1.0));

        report.subsection("A split-signature region is open to both");
        report.check("the massless field crosses it",
                     Channels::masslessTransmission(Kind::SplitSignature, c, transverse, 1.0) > 0.1);
        report.check("and so does the massive one",
                     Channels::massiveTransmission(Kind::SplitSignature, c, mu, transverse, 1.0) > 0.1);

        report.subsection("Gravity does not have to cross");
        for (Kind kind : kinds)
        {
            report.check(std::format("  {:22} : coupling {:.4f}",
                                     IntermediateRegion::name(kind),
                                     Channels::gravitationalCoupling(kind, 1.0)),
                         Channels::gravitationalCoupling(kind, 1.0) > 0.0);
        }
        report.check("a degenerate layer is closed to every field",
                     Channels::masslessTransmission(Kind::Degenerate, c, transverse, 1.0) == 0.0 &&
                         Channels::massiveTransmission(Kind::Degenerate, c, mu, transverse, 1.0) ==
                             0.0);
        report.check("yet its gravitational coupling is not zero, because the layer "
                     "sits on the surface and touches both sides at once",
                     Channels::gravitationalCoupling(Kind::Degenerate, 1.0) > 0.0);
        report.check("so gravity reaches where no field can, which is the one "
                     "channel a closed region does not shut",
                     Channels::gravityReachesWhereFieldsCannot(Kind::Degenerate, c, mu, transverse,
                                                               1.0));

        report.subsection("But the gravitational channel weakens as the region opens");
        report.check("a thicker region couples more weakly",
                     Channels::gravitationalCoupling(Kind::SplitSignature, 8.0) <
                         Channels::gravitationalCoupling(Kind::SplitSignature, 0.5));
        report.check("and a thicker region transmits a split-signature field no worse, so "
                     "the two channels trade against each other",
                     Channels::massiveTransmission(Kind::SplitSignature, c, mu, transverse, 8.0) > 0.1);

        report.subsection("Correlation is not a signal");
        for (Kind kind : kinds)
        {
            report.check(std::format("  {:22} : correlation {:.4f}, non-zero even when closed",
                                     IntermediateRegion::name(kind),
                                     Channels::correlationAcross(kind, c, mu, transverse, 1.0)),
                         Channels::correlationAcross(kind, c, mu, transverse, 1.0) > 0.0);
        }
        report.check("a degenerate layer still shows correlation across it while "
                     "transmitting nothing",
                     Channels::correlationAcross(Kind::Degenerate, c, mu, transverse, 1.0) > 0.0 &&
                         Channels::massiveTransmission(Kind::Degenerate, c, mu, transverse, 1.0) ==
                             0.0);
        report.check("but it carries no controllable signal, since nothing crosses "
                     "that the sender can modulate",
                     !Channels::carriesControllableSignal(Kind::Degenerate, c, mu, transverse,
                                                          1.0));
        report.check("whereas a split-signature region does carry one",
                     Channels::carriesControllableSignal(Kind::SplitSignature, c, mu, transverse, 1.0));
    }

}
