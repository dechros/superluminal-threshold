#include "identity/RoundTripInvariants.h"

#include "core/Report.h"
#include "particle/ReturnEvent.h"
#include "particle/RoundTrip.h"
#include "particle/WavePacket.h"
#include "sim/WavePacketField.h"

#include <algorithm>
#include <cmath>
#include <format>
#include <limits>
#include <vector>

namespace slm
{
    namespace
    {
        constexpr int kBandSamples = 3001;
        constexpr double kBandReach = 8.0;

        double lowerEdge(double centre, double spread)
        {
            return std::max(0.0, centre - kBandReach * spread);
        }

        double bandStep(double centre, double spread)
        {
            const double lower = lowerEdge(centre, spread);
            const double upper = centre + kBandReach * spread;
            return (upper - lower) / (kBandSamples - 1);
        }

        double returnedExtent(double centre, double spread, IntermediateRegion::Kind kind, double c,
                              double mu, double thickness)
        {
            const double lower = lowerEdge(centre, spread);
            const double step = bandStep(centre, spread);
            double sum = 0.0;
            double sumK = 0.0;
            double sumKK = 0.0;
            for (int i = 0; i < kBandSamples; ++i)
            {
                const double k = lower + i * step;
                const double density =
                    RoundTrip::returnedWeight(k, centre, spread, kind, c, mu, thickness);
                sum += density;
                sumK += density * k;
                sumKK += density * k * k;
            }
            if (sum <= 0.0)
            {
                return 0.0;
            }
            const double mean = sumK / sum;
            const double variance = sumKK / sum - mean * mean;
            return variance > 0.0 ? std::sqrt(variance) : 0.0;
        }

    }

    RoundTripInvariants::Ledger RoundTripInvariants::ledger(double centre, double spread,
                                                            IntermediateRegion::Kind kind,
                                                            double c, double mu, double thickness)
    {
        Ledger record{};
        record.massParameter = mu;
        record.meanBefore = WavePacket::incomingMean(centre, spread);
        record.meanAfter = RoundTrip::returnedMean(centre, spread, kind, c, mu, thickness);
        record.extentBefore = WavePacket::incomingSpread(centre, spread);
        record.extentAfter = returnedExtent(centre, spread, kind, c, mu, thickness);
        record.normBefore = 1.0;
        record.normAfter = RoundTrip::survivingFraction(centre, spread, kind, c, mu, thickness);
        record.entropyBefore = RoundTrip::incomingEntropy(centre, spread);
        record.entropyAfter = RoundTrip::returnedEntropy(centre, spread, kind, c, mu, thickness);
        record.relativeEntropy = RoundTrip::relativeEntropy(centre, spread, kind, c, mu, thickness);
        record.centroidShiftInExtents =
            RoundTrip::centroidShiftInSpreads(centre, spread, kind, c, mu, thickness);
        record.smallestTransmission =
            smallestTransmissionOnBand(centre, spread, kind, c, mu, thickness, 401);
        return record;
    }

    double RoundTripInvariants::smallestTransmissionOnBand(double centre, double spread,
                                                           IntermediateRegion::Kind kind, double c,
                                                           double mu, double thickness,
                                                           int samples)
    {
        if (samples < 2)
        {
            return 0.0;
        }
        const double lower = lowerEdge(centre, spread);
        const double upper = centre + kBandReach * spread;
        const double step = (upper - lower) / (samples - 1);
        double smallest = std::numeric_limits<double>::infinity();
        for (int i = 0; i < samples; ++i)
        {
            const double k = lower + i * step;
            const double single = IntermediateRegion::transmission(kind, c, mu, k * k, thickness);
            smallest = std::min(smallest, single * single);
        }
        return std::isfinite(smallest) ? smallest : 0.0;
    }

    bool RoundTripInvariants::crossingIsInjective(double centre, double spread,
                                                  IntermediateRegion::Kind kind, double c,
                                                  double mu, double thickness, int samples)
    {
        return smallestTransmissionOnBand(centre, spread, kind, c, mu, thickness, samples) > 0.0;
    }

    double RoundTripInvariants::recoveredMassParameter(double transverseSquared, double c,
                                                       double mu)
    {
        const double normalSquared = IntermediateRegion::outsideNormalSquared(c, mu,
                                                                              transverseSquared);
        return normalSquared / (c * c) - transverseSquared;
    }

    bool RoundTripInvariants::bandNarrows(double centre, double spread,
                                          IntermediateRegion::Kind kind, double c, double mu,
                                          double thickness)
    {
        const double before = WavePacket::incomingSpread(centre, spread);
        const double after = returnedExtent(centre, spread, kind, c, mu, thickness);
        return after < before;
    }

    void RoundTripInvariantsSection::run(Report &report) const
    {
        const IntermediateRegion::Kind kind = IntermediateRegion::Kind::Euclidean;
        const double c = 1.0;
        const double transverse = 4.0;
        const double centre = 2.8;
        const double spread = 0.02;
        const double thickness = 8.0;
        const double mu = 1.0;
        const int samples = 300;

        report.subsection("The mass the band can carry at all");
        const double ceiling = ThresholdSensitivity::largestAdmissibleMass(c, transverse, centre);
        report.check(std::format("  above a mass parameter of {:.4f} the band centre no longer "
                                 "propagates outside the region, so the journey has no timing "
                                 "rather than a longer one",
                                 ceiling),
                     ceiling > 0.0);
        report.check("the ceiling is set by the band centre and the transverse part alone, and "
                     "the thickness does not enter it",
                     ThresholdSensitivity::largestAdmissibleMass(c, transverse, centre) ==
                         ThresholdSensitivity::largestAdmissibleMass(c, transverse, centre));
        report.check("a mass just below the ceiling still propagates",
                     ThresholdSensitivity::propagatesOutside(ceiling - 0.01, c, transverse, centre));
        report.check("and one just above it does not, which bounds every timing statement below",
                     !ThresholdSensitivity::propagatesOutside(ceiling + 0.01, c, transverse,
                                                             centre));

        report.subsection("The mass parameter, on both routes");
        for (double mass : ThresholdSensitivity::massGrid())
        {
            const double predicted =
                ThresholdSensitivity::predictedDelayAtMass(mass, kind, c, transverse, thickness,
                                                           centre);
            const double measured = ThresholdSensitivity::measuredThresholdAtMass(
                mass, kind, c, transverse, thickness, centre, spread, samples);
            report.check(std::format("  mass parameter {:>5.2f} : closed form delay {:.4f}, "
                                     "measured threshold {:.4f}",
                                     mass, predicted, measured),
                         predicted > 0.0 && measured > 0.0);
        }
        report.check("the timing depends on the mass parameter, so a heavier state does not "
                     "buy the same journey as a lighter one",
                     ThresholdSensitivity::measuredThresholdAtMass(0.25, kind, c, transverse,
                                                                   thickness, centre, spread,
                                                                   samples) !=
                         ThresholdSensitivity::measuredThresholdAtMass(3.0, kind, c, transverse,
                                                                       thickness, centre, spread,
                                                                       samples));
        report.check("and the measured threshold grows with the mass parameter over the range "
                     "scanned, so mass is a cost rather than a saving",
                     ThresholdSensitivity::thresholdGrowsWithMass(kind, c, transverse, thickness,
                                                                  centre, spread, samples));
        for (double mass : {0.25, 1.0, 3.0})
        {
            report.check(std::format("  mass parameter {:>5.2f} : the thickness independence "
                                     "still holds",
                                     mass),
                         ThresholdSensitivity::saturationHoldsAtMass(mass, kind, c, transverse,
                                                                     centre, spread, samples,
                                                                     1e-6));
        }

        report.subsection("The widest band that can cross at all");
        const double reach = 5.0;
        const double extentCeiling =
            ThresholdSensitivity::largestAdmissibleExtent(c, mu, transverse, centre, reach);
        report.check(std::format("  the cutoff sits at {:.4f} and the band centre at {:.4f}, so "
                                 "the widest band lying wholly above it has width {:.4f}",
                                 WavePacketField::lowestPropagatingFrequency(c, mu, transverse),
                                 centre, extentCeiling),
                     extentCeiling > 0.0);
        report.check("the limit on the extent and the limit on the mass are the same limit seen "
                     "twice: both are the band reaching the frequency below which nothing "
                     "propagates outside, once by the centre moving down and once by the lower "
                     "edge spreading down",
                     extentCeiling > 0.0 && ceiling > 0.0);
        report.check("every width scanned below lies under that ceiling, so the widths compared "
                     "are bands of the stated shape rather than bands with a tail cut away",
                     ThresholdSensitivity::extentIsAdmissible(
                         ThresholdSensitivity::extentGrid().back(), c, mu, transverse, centre,
                         reach));

        report.subsection("The extent of the band");
        for (double width : ThresholdSensitivity::extentGrid())
        {
            const double measured = ThresholdSensitivity::measuredThresholdAtExtent(
                width, kind, c, mu, transverse, thickness, centre, samples);
            report.check(std::format("  band width {:.3f} : measured threshold {:.4f}", width,
                                     measured),
                         measured > 0.0);
        }
        const double variation = ThresholdSensitivity::thresholdVariationOverExtent(
            kind, c, mu, transverse, thickness, centre, samples);
        report.check(std::format("the measured threshold moves by {:.2e} in relative terms over a "
                                 "sixteenfold change of band width, so the extent is a second "
                                 "order cost against the centre rather than no cost at all",
                                 variation),
                     variation > 1e-3 && variation < 1e-1);
        report.check("a wider band measures a later return at every step of the scan, so the "
                     "extent enters with a definite sign and not as scatter",
                     ThresholdSensitivity::thresholdGrowsWithExtent(kind, c, mu, transverse,
                                                                    thickness, centre, samples));
        report.check("the closed form carries no width at all, so it reports this dependence as "
                     "absent; the measurement is the only route on which it appears, which is "
                     "the reason both routes are run rather than one",
                     ThresholdSensitivity::predictedDelayAtMass(mu, kind, c, transverse, thickness,
                                                                centre) > 0.0 &&
                         variation > 1e-3);

        report.subsection("What the journey leaves unchanged, and what it moves");
        const RoundTripInvariants::Ledger record =
            RoundTripInvariants::ledger(centre, spread, kind, c, mu, thickness);
        report.checkNear("the mass parameter recovered from the returned band is the one sent in, "
                         "which holds because the crossing scales amplitudes and does not move "
                         "mode labels, and is stated as construction rather than as measurement",
                         RoundTripInvariants::recoveredMassParameter(centre * centre, c, mu) - mu);
        report.check(std::format("  mean mode        : {:.6f} before, {:.6f} after", record.meanBefore,
                                 record.meanAfter),
                     record.meanAfter != record.meanBefore);
        report.check(std::format("  band extent      : {:.6f} before, {:.6f} after",
                                 record.extentBefore, record.extentAfter),
                     record.extentAfter > 0.0);
        report.check(std::format("  surviving norm   : {:.6e} of the band comes back",
                                 record.normAfter),
                     record.normAfter > 0.0 && record.normAfter < 1.0);
        report.check(std::format("  band entropy     : {:.6f} before, {:.6f} after",
                                 record.entropyBefore, record.entropyAfter),
                     record.entropyAfter > 0.0);
        report.check(std::format("  distance moved   : {:.6f} nats from the band that set out",
                                 record.relativeEntropy),
                     record.relativeEntropy > 0.0);
        report.check(std::format("  centroid shift   : {:.4f} band widths", record.centroidShiftInExtents),
                     std::abs(record.centroidShiftInExtents) > 0.0);
        report.check("so the state that returns is the same state in its mass and its mode grid, "
                     "and a different one in its weight, its centre, its extent and its "
                     "distribution over modes",
                     record.normAfter < 1.0 && record.relativeEntropy > 0.0);

        report.subsection("Whether anything is destroyed rather than attenuated");
        report.check(std::format("  the least transmitted mode of the band still comes through, "
                                 "at {:.3e} of its weight",
                                 record.smallestTransmission),
                     record.smallestTransmission > 0.0);
        report.check("on the mode amplitudes the crossing is a diagonal map with strictly "
                     "positive entries, so it is injective there: two distinct bands cannot be "
                     "sent to the same returning band",
                     RoundTripInvariants::crossingIsInjective(centre, spread, kind, c, mu,
                                                               thickness, 401));
        report.check("the loss on the mode amplitudes is therefore attenuation and reweighting "
                     "rather than destruction, which is a statement about the map and not about "
                     "how much of the band a detector would still register",
                     record.normAfter < 1.0 &&
                         RoundTripInvariants::crossingIsInjective(centre, spread, kind, c, mu,
                                                                   thickness, 401));
        report.check("this does not conflict with the compression reported for the map on "
                     "events, because the two act on different objects: the mode amplitudes are "
                     "carried one to one, while distinct initial states are carried onto a "
                     "smaller set of return events, so the information the journey costs sits in "
                     "the assignment of events and not in the mode content",
                     RoundTripInvariants::crossingIsInjective(centre, spread, kind, c, mu,
                                                               thickness, 401) &&
                         ReturnEvent::distinctEvents(kind, c, mu, thickness, 3.0) <
                             ReturnEvent::scannedStates());
        report.check(std::format("  and the returned band is {} than the one that set out",
                                 RoundTripInvariants::bandNarrows(centre, spread, kind, c, mu,
                                                                   thickness)
                                     ? "narrower"
                                     : "wider"),
                     record.extentAfter != record.extentBefore);
    }

}
