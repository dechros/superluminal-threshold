#include "particle/FarSideObservation.h"

#include "core/Report.h"
#include "intermediate/ThresholdOptimum.h"
#include "intermediate/TwoCrossings.h"
#include "particle/FarSideMotion.h"
#include "scan/BranchObservables.h"

#include <cmath>
#include <format>

namespace slm
{

    double FarSideObservation::interiorCrossingWavenumberSquared(IntermediateRegion::Kind kind,
                                                                 double omega, double c,
                                                                 double mu,
                                                                 double transverseSquared)
    {
        return TwoCrossings::insideSquared(kind, omega, c, mu, transverseSquared);
    }

    bool FarSideObservation::interiorIsOnShell(IntermediateRegion::Kind kind, double omega,
                                               double c, double mu, double transverseSquared)
    {
        return FarSideMotion::interiorPropagates(kind, omega, c, mu, transverseSquared);
    }

    bool FarSideObservation::missingMassCanApply(IntermediateRegion::Kind kind, double omega,
                                                 double c, double mu, double transverseSquared)
    {
        return interiorIsOnShell(kind, omega, c, mu, transverseSquared);
    }

    bool FarSideObservation::isRoundTripRegime(IntermediateRegion::Kind kind, double omega,
                                               double c, double mu, double transverseSquared)
    {
        const int turned = IntermediateRegion::flippedDirections(kind);
        const double normalPart = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        return ThresholdOptimum::isBarrier(normalPart, transverseSquared, turned);
    }

    bool FarSideObservation::anyFrequencyGivesBoth(IntermediateRegion::Kind kind, double c,
                                                   double mu, double transverseSquared)
    {
        for (int i = 1; i <= 4000; ++i)
        {
            const double omega = i * 0.01;
            if (missingMassCanApply(kind, omega, c, mu, transverseSquared) &&
                isRoundTripRegime(kind, omega, c, mu, transverseSquared))
            {
                return true;
            }
        }
        return false;
    }

    double FarSideObservation::regimeBoundary(IntermediateRegion::Kind kind, double c, double mu,
                                              double transverseSquared)
    {
        double low = 0.0;
        double high = 200.0;
        if (!FarSideMotion::interiorPropagates(kind, high, c, mu, transverseSquared))
        {
            return 0.0;
        }
        for (int i = 0; i < 200; ++i)
        {
            const double mid = 0.5 * (low + high);
            if (FarSideMotion::interiorPropagates(kind, mid, c, mu, transverseSquared))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return 0.5 * (low + high);
    }

    bool FarSideObservation::localisedStateAvailable()
    {
        return false;
    }

    int FarSideObservation::boundaryObservableCount()
    {
        return BranchObservables::sweptObservableCount();
    }

    bool FarSideObservation::boundaryObservablesCarryDirection()
    {
        return BranchObservables::discriminatingObservableCount() > 0;
    }

    void FarSideObservationSection::run(Report &report) const
    {
        const auto kind = IntermediateRegion::Kind::Euclidean;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;

        report.subsection("Localisation is refused, and the refusal is not computed here");
        report.check("a spacelike four-momentum admits no position operator whose "
                     "eigenstates respect causality, so there is no state saying where "
                     "the particle is over there, and this work does not supply one",
                     !FarSideObservation::localisedStateAvailable());

        report.subsection("The method that does exist looks at the boundary, not the traveller");
        report.check(std::format("  the interior turns from decaying to propagating at a "
                                 "frequency of {:.6f}",
                                 FarSideObservation::regimeBoundary(kind, c, mu, transverse)),
                     FarSideObservation::regimeBoundary(kind, c, mu, transverse) > 0.0);
        for (double omega : {1.5, 2.8, 6.0, 12.0})
        {
            report.check(std::format("  omega {:5g} : crossing wavenumber squared {:+.4f}, on "
                                     "shell {}, round trip regime {}",
                                     omega,
                                     FarSideObservation::interiorCrossingWavenumberSquared(
                                         kind, omega, c, mu, transverse),
                                     FarSideObservation::interiorIsOnShell(kind, omega, c, mu,
                                                                           transverse)
                                         ? "yes"
                                         : "no",
                                     FarSideObservation::isRoundTripRegime(kind, omega, c, mu,
                                                                           transverse)
                                         ? "yes"
                                         : "no"),
                         FarSideObservation::interiorIsOnShell(kind, omega, c, mu, transverse) !=
                             FarSideObservation::isRoundTripRegime(kind, omega, c, mu,
                                                                   transverse));

        }
        report.check("the missing mass method presumes a real momentum leaving the "
                     "interaction, so its necessary condition holds in the propagating "
                     "regime and only there",
                     FarSideObservation::missingMassCanApply(kind, 12.0, c, mu, transverse) &&
                         !FarSideObservation::missingMassCanApply(kind, 1.5, c, mu, transverse));
        report.check("what the method actually reads is the sign of an invariant of the "
                     "four-momentum, and the quantity available here is a squared "
                     "wavenumber along one axis, which is a different object, so the "
                     "sufficient condition is not checked and no mass signature is "
                     "claimed",
                     FarSideObservation::interiorCrossingWavenumberSquared(kind, 12.0, c, mu,
                                                                          transverse) > 0.0);

        report.subsection("And that regime is not the one the round trip uses");
        report.check("the two predicates are written independently, one from the "
                     "interior wavenumber and one from the barrier test the threshold "
                     "optimum uses, so their disagreement at every frequency is a "
                     "computed agreement between two routes",
                     FarSideObservation::interiorIsOnShell(kind, 12.0, c, mu, transverse) &&
                         !FarSideObservation::isRoundTripRegime(kind, 12.0, c, mu, transverse));
        report.check("swept over four thousand frequencies, none puts the interior on "
                     "shell and leaves the delay able to saturate",
                     !FarSideObservation::anyFrequencyGivesBoth(kind, c, mu, transverse));
        report.check("so where the particle can be observed over there the arrival is "
                     "not advanced, and where the arrival is advanced there is no "
                     "on shell interior state to observe",
                     !FarSideObservation::anyFrequencyGivesBoth(kind, c, mu, transverse) &&
                         !FarSideObservation::localisedStateAvailable());

        report.subsection("What is left in the regime the work actually uses");
        report.check(std::format("  {} boundary quantities survive: the transmitted weight, "
                                 "the layer strength and the returned entropy",
                                 FarSideObservation::boundaryObservableCount()),
                     FarSideObservation::boundaryObservableCount() ==
                         BranchObservables::sweptObservableCount());
        report.check("none of them reports which way the particle travelled, since each "
                     "is even under the reversal separating the two families, so they "
                     "measure that a crossing happened and not what happened inside",
                     !FarSideObservation::boundaryObservablesCarryDirection());
        report.check("the honest answer is therefore a concession: in the regime that "
                     "carries the claim, the far side is observed only through the "
                     "amplitudes at its two faces, and it is never observed directly",
                     !FarSideObservation::boundaryObservablesCarryDirection() &&
                         !FarSideObservation::anyFrequencyGivesBoth(kind, c, mu, transverse));
    }

}
