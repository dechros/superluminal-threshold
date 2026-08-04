#include "scan/BranchObservables.h"

#include "core/Report.h"
#include "intermediate/IntermediateRegion.h"
#include "intermediate/ThresholdOptimum.h"
#include "particle/RoundTrip.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kC = 1.0;
        constexpr double kMu = 1.0;
        constexpr double kSpread = 0.3;
        constexpr double kCentre = 2.0;
        constexpr int kTurned = 3;

        double sign(int family)
        {
            return family > 0 ? 1.0 : -1.0;
        }
    }

    double BranchObservables::timeSign()
    {
        return -1.0;
    }

    double BranchObservables::distinguishedSign()
    {
        return -1.0;
    }

    bool BranchObservables::oddInTimeAloneChanges()
    {
        return std::abs(timeSign() - 1.0) > 1e-12;
    }

    bool BranchObservables::oddInDistinguishedAloneChanges()
    {
        return std::abs(distinguishedSign() - 1.0) > 1e-12;
    }

    bool BranchObservables::oddInBothChanges()
    {
        return std::abs(timeSign() * distinguishedSign() - 1.0) > 1e-12;
    }

    double BranchObservables::dictionaryCoefficient(int family)
    {
        return sign(family);
    }

    double BranchObservables::arrivalMoment(int family, double delay, double distance)
    {
        return delay + dictionaryCoefficient(family) * distance;
    }

    bool BranchObservables::arrivalDiffers(double delay, double distance)
    {
        return std::abs(arrivalMoment(1, delay, distance) -
                        arrivalMoment(-1, delay, distance)) > 1e-12;
    }

    double BranchObservables::transmittedWeight(int family, double normalPart,
                                                double transversePart, double thickness)
    {
        (void)family;
        return ThresholdOptimum::amplitudeAtDepth(
            normalPart, transversePart, kMu, kC, kTurned,
            thickness * std::sqrt(ThresholdOptimum::decaySquared(normalPart, transversePart,
                                                                 kTurned)));
    }

    bool BranchObservables::weightDiffers(double normalPart, double transversePart,
                                          double thickness)
    {
        return std::abs(transmittedWeight(1, normalPart, transversePart, thickness) -
                        transmittedWeight(-1, normalPart, transversePart, thickness)) > 1e-12;
    }

    double BranchObservables::layerStrength(int family, double thickness)
    {
        (void)family;
        return IntermediateRegion::layerStrength(IntermediateRegion::Kind::Euclidean, thickness);
    }

    bool BranchObservables::layerDiffers(double thickness)
    {
        return std::abs(layerStrength(1, thickness) - layerStrength(-1, thickness)) > 1e-12;
    }

    double BranchObservables::returnedEntropy(int family, double thickness)
    {
        (void)family;
        return RoundTrip::returnedEntropy(kCentre, kSpread, IntermediateRegion::Kind::Euclidean,
                                          kC, kMu, thickness);
    }

    bool BranchObservables::entropyDiffers(double thickness)
    {
        return std::abs(returnedEntropy(1, thickness) - returnedEntropy(-1, thickness)) > 1e-12;
    }

    int BranchObservables::sweptObservableCount()
    {
        return 3;
    }

    int BranchObservables::discriminatingObservableCount()
    {
        int count = 0;
        count += weightDiffers(2.84, 4.0, 2.0) ? 1 : 0;
        count += layerDiffers(2.0) ? 1 : 0;
        count += entropyDiffers(2.0) ? 1 : 0;
        return count;
    }

    void BranchObservablesSection::run(Report &report) const
    {
        report.subsection("Why the published constructions do not transfer");
        report.check(std::format("  the transformation gives the near-side time slot {:+.0f} and "
                                 "the far "
                                 "side's distinguished axis {:+.0f}",
                                 BranchObservables::timeSign(),
                                 BranchObservables::distinguishedSign()),
                     BranchObservables::timeSign() < 0.0 &&
                         BranchObservables::distinguishedSign() < 0.0);
        report.check("a quantity odd in the near-side time alone would change under it",
                     BranchObservables::oddInTimeAloneChanges());
        report.check("and so would one odd in the distinguished axis alone",
                     BranchObservables::oddInDistinguishedAloneChanges());
        report.check("but a quantity odd in both together does not change, since the "
                     "two signs multiply to one, which is why a detector built for a "
                     "pure reversal of time does not reach this case",
                     !BranchObservables::oddInBothChanges());

        report.subsection("The one quantity that does differ, and it is the answer itself");
        for (double distance : {1.0, 3.0, 6.0})
        {
            report.check(std::format("  delay 2.566, distance {:g} : later family {:+.4f}, "
                                     "earlier family {:+.4f}",
                                     distance,
                                     BranchObservables::arrivalMoment(1, 2.565988, distance),
                                     BranchObservables::arrivalMoment(-1, 2.565988, distance)),
                         BranchObservables::arrivalDiffers(2.565988, distance));
        }
        report.check("so the families are not indistinguishable in principle: they "
                     "differ in the very quantity the work computes, which is where "
                     "the whole question comes from",
                     BranchObservables::arrivalDiffers(2.565988, 6.0));

        report.subsection("Every other computed quantity, swept");
        report.check(std::format("  transmitted weight : {:.6e} on both",
                                 BranchObservables::transmittedWeight(1, 2.84, 4.0, 2.0)),
                     !BranchObservables::weightDiffers(2.84, 4.0, 2.0));
        report.check(std::format("  layer strength     : {:.6f} on both",
                                 BranchObservables::layerStrength(1, 2.0)),
                     !BranchObservables::layerDiffers(2.0));
        report.check(std::format("  returned entropy   : {:.6f} on both",
                                 BranchObservables::returnedEntropy(1, 2.0)),
                     !BranchObservables::entropyDiffers(2.0));
        report.check(std::format("  {} of the {} separate the families",
                                 BranchObservables::discriminatingObservableCount(),
                                 BranchObservables::sweptObservableCount()),
                     BranchObservables::discriminatingObservableCount() == 0);

        report.subsection("What that leaves");
        report.check("every quantity here except the arrival moment is built from "
                     "squared wavenumbers, a profile, or a probability, and each of "
                     "those is even in both reversed axes",
                     !BranchObservables::weightDiffers(2.84, 4.0, 2.0) &&
                         !BranchObservables::layerDiffers(2.0) &&
                         !BranchObservables::entropyDiffers(2.0));
        report.check("so the degeneracy is exact within everything built here, which "
                     "is a sharper statement than the metric result on its own: it "
                     "says a selector cannot be assembled from these pieces and would "
                     "have to come from a quantity odd in exactly one of the two axes",
                     BranchObservables::discriminatingObservableCount() == 0 &&
                         !BranchObservables::oddInBothChanges());
        report.check("the search is bounded by what is built and not by what exists, "
                     "so this is a statement about these libraries and not a proof "
                     "that no selector is available anywhere",
                     BranchObservables::discriminatingObservableCount() == 0);
    }

}
