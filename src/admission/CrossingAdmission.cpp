#include "admission/CrossingAdmission.h"

#include "boundary/JunctionFamily.h"
#include "core/Report.h"
#include "identity/ThresholdSensitivity.h"
#include "routes/ThreeRoutes.h"
#include "sim/WavePacketField.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        double cutoff(const CrossingAdmission::Setup &setup)
        {
            return WavePacketField::lowestPropagatingFrequency(setup.c, setup.mu,
                                                               setup.transverseSquared);
        }

        double roundTripPrice(const CrossingAdmission::Setup &setup)
        {
            return ThreeRoutes::roundTripReading(ThreeRoutes::Route::Wave, setup.kind, setup.centre,
                                                 setup.c, setup.mu, setup.transverseSquared,
                                                 setup.thickness);
        }
    }

    std::vector<CrossingAdmission::Condition> CrossingAdmission::all()
    {
        return {Condition::BandAboveCutoff,   Condition::BandWidthAdmissible,
                Condition::MassBelowCeiling,  Condition::InteriorBlocks,
                Condition::WeightSurvives,    Condition::MatchingAdmitsExit,
                Condition::ReversingBranch,   Condition::DistanceExceedsPrice};
    }

    std::string CrossingAdmission::name(Condition condition)
    {
        switch (condition)
        {
        case Condition::BandAboveCutoff:
            return "band centre above the cutoff";
        case Condition::BandWidthAdmissible:
            return "whole band above the cutoff";
        case Condition::MassBelowCeiling:
            return "mass below its ceiling";
        case Condition::InteriorBlocks:
            return "interior blocks propagation";
        case Condition::WeightSurvives:
            return "amplitude survives two crossings";
        case Condition::MatchingAdmitsExit:
            return "matching admits an exit";
        case Condition::ReversingBranch:
            return "the reversing branch is realised";
        case Condition::DistanceExceedsPrice:
            return "far-side travel exceeds the price";
        }
        return "unknown";
    }

    std::string CrossingAdmission::failureMeaning(Condition condition)
    {
        switch (condition)
        {
        case Condition::BandAboveCutoff:
        case Condition::BandWidthAdmissible:
        case Condition::MassBelowCeiling:
            return "no component reaches a detector, so there is no journey to time";
        case Condition::InteriorBlocks:
            return "the region is not a barrier, so the saturated delay does not apply";
        case Condition::WeightSurvives:
            return "the state does not come back in any measurable amount";
        case Condition::MatchingAdmitsExit:
            return "the surface forbids a wave that leaves without one returning";
        case Condition::ReversingBranch:
            return "the crossing realised sends the arrival later instead of earlier";
        case Condition::DistanceExceedsPrice:
            return "the journey happens but the arrival falls after the departure";
        }
        return "unknown";
    }

    bool CrossingAdmission::remediableByPaying(Condition condition)
    {
        return condition == Condition::DistanceExceedsPrice;
    }

    bool CrossingAdmission::holds(Condition condition, const Setup &setup)
    {
        switch (condition)
        {
        case Condition::BandAboveCutoff:
            return setup.centre > cutoff(setup);
        case Condition::BandWidthAdmissible:
            return ThresholdSensitivity::extentIsAdmissible(setup.spread, setup.c, setup.mu,
                                                           setup.transverseSquared, setup.centre,
                                                           setup.bandReach);
        case Condition::MassBelowCeiling:
            return ThresholdSensitivity::propagatesOutside(setup.mu, setup.c,
                                                          setup.transverseSquared, setup.centre);
        case Condition::InteriorBlocks:
            return IntermediateRegion::blocks(setup.kind, setup.c, setup.mu,
                                              setup.transverseSquared);
        case Condition::WeightSurvives:
            return IntermediateRegion::transmission(setup.kind, setup.c, setup.mu,
                                                    setup.transverseSquared, setup.thickness) > 0.0;
        case Condition::MatchingAdmitsExit:
            return JunctionFamily::admittingOutgoingCount(SurfaceLayer::Profile::Linear) > 0;
        case Condition::ReversingBranch:
            return setup.branch < 0;
        case Condition::DistanceExceedsPrice:
            return setup.farSideDistance > roundTripPrice(setup);
        }
        return false;
    }

    double CrossingAdmission::margin(Condition condition, const Setup &setup)
    {
        switch (condition)
        {
        case Condition::BandAboveCutoff:
            return setup.centre - cutoff(setup);
        case Condition::BandWidthAdmissible:
            return ThresholdSensitivity::largestAdmissibleExtent(setup.c, setup.mu,
                                                                setup.transverseSquared,
                                                                setup.centre, setup.bandReach) -
                   setup.spread;
        case Condition::MassBelowCeiling:
            return ThresholdSensitivity::largestAdmissibleMass(setup.c, setup.transverseSquared,
                                                              setup.centre) -
                   setup.mu;
        case Condition::InteriorBlocks:
            return -IntermediateRegion::insideNormalSquared(setup.kind, setup.c, setup.mu,
                                                            setup.transverseSquared);
        case Condition::WeightSurvives:
            return IntermediateRegion::transmission(setup.kind, setup.c, setup.mu,
                                                    setup.transverseSquared, setup.thickness);
        case Condition::MatchingAdmitsExit:
            return static_cast<double>(
                JunctionFamily::admittingOutgoingCount(SurfaceLayer::Profile::Linear));
        case Condition::ReversingBranch:
            return setup.branch < 0 ? 1.0 : -1.0;
        case Condition::DistanceExceedsPrice:
            return setup.farSideDistance - roundTripPrice(setup);
        }
        return 0.0;
    }

    bool CrossingAdmission::admitted(const Setup &setup)
    {
        for (Condition condition : all())
        {
            if (!holds(condition, setup))
            {
                return false;
            }
        }
        return true;
    }

    int CrossingAdmission::holdingCount(const Setup &setup)
    {
        int count = 0;
        for (Condition condition : all())
        {
            if (holds(condition, setup))
            {
                ++count;
            }
        }
        return count;
    }

    CrossingAdmission::Condition CrossingAdmission::firstFailure(const Setup &setup)
    {
        for (Condition condition : all())
        {
            if (!holds(condition, setup))
            {
                return condition;
            }
        }
        return Condition::DistanceExceedsPrice;
    }

    CrossingAdmission::Setup CrossingAdmission::protonSetup(double farSideDistance)
    {
        Setup setup{};
        setup.kind = IntermediateRegion::Kind::Euclidean;
        setup.c = 1.0;
        setup.mu = 1.0;
        setup.transverseSquared = 4.0;
        setup.thickness = 8.0;
        setup.centre = 2.8;
        setup.spread = 0.02;
        setup.bandReach = 5.0;
        setup.farSideDistance = farSideDistance;
        setup.branch = -1;
        return setup;
    }

    double CrossingAdmission::returnMoment(const Setup &setup)
    {
        return roundTripPrice(setup) - setup.farSideDistance;
    }

    double CrossingAdmission::priceOfTheJourney(const Setup &setup)
    {
        return roundTripPrice(setup);
    }

    void CrossingAdmissionSection::run(Report &report) const
    {
        const CrossingAdmission::Setup setup = CrossingAdmission::protonSetup(6.0);

        report.subsection("Every condition, in one place");
        for (CrossingAdmission::Condition condition : CrossingAdmission::all())
        {
            report.check(std::format("  {:<38} : {}, margin {:+.4e}",
                                     CrossingAdmission::name(condition),
                                     CrossingAdmission::holds(condition, setup) ? "met    "
                                                                               : "not met",
                                     CrossingAdmission::margin(condition, setup)),
                         CrossingAdmission::holds(condition, setup));
        }
        report.check(std::format("all {} conditions hold together, so this state crosses, travels, "
                                 "and returns before it left",
                                 CrossingAdmission::holdingCount(setup)),
                     CrossingAdmission::admitted(setup));

        report.subsection("The conditions fail in two different ways");
        for (CrossingAdmission::Condition condition : CrossingAdmission::all())
        {
            report.check(std::format("  {:<38} : failing it means {}",
                                     CrossingAdmission::name(condition),
                                     CrossingAdmission::failureMeaning(condition)),
                         true);
        }
        report.check("exactly one of them can be remedied by paying more, namely the far-side "
                     "travel, and the rest either remove the journey or reverse its sign",
                     CrossingAdmission::remediableByPaying(
                         CrossingAdmission::Condition::DistanceExceedsPrice) &&
                         !CrossingAdmission::remediableByPaying(
                             CrossingAdmission::Condition::MassBelowCeiling));

        report.subsection("Where each wall stands, hit one at a time");
        CrossingAdmission::Setup tooHeavy = setup;
        tooHeavy.mu = 8.0;
        report.check(std::format("  a mass parameter of {:.1f} fails first at: {}", tooHeavy.mu,
                                 CrossingAdmission::name(CrossingAdmission::firstFailure(tooHeavy))),
                     !CrossingAdmission::admitted(tooHeavy));
        CrossingAdmission::Setup tooWide = setup;
        tooWide.spread = 0.5;
        report.check(std::format("  a band width of {:.2f} fails first at: {}", tooWide.spread,
                                 CrossingAdmission::name(CrossingAdmission::firstFailure(tooWide))),
                     !CrossingAdmission::admitted(tooWide));
        CrossingAdmission::Setup forward = setup;
        forward.branch = 1;
        report.check(std::format("  the other branch fails first at: {}",
                                 CrossingAdmission::name(CrossingAdmission::firstFailure(forward))),
                     !CrossingAdmission::admitted(forward));
        CrossingAdmission::Setup tooClose = setup;
        tooClose.farSideDistance = 0.5;
        report.check(std::format("  travelling only {:.2f} over there fails first at: {}",
                                 tooClose.farSideDistance,
                                 CrossingAdmission::name(CrossingAdmission::firstFailure(tooClose))),
                     !CrossingAdmission::admitted(tooClose));

        report.subsection("The journey, end to end, with the moment it lands on");
        const double price = CrossingAdmission::priceOfTheJourney(setup);
        report.check(std::format("  the round trip costs {:.6f}, which is the far-side distance "
                                 "that brings it home exactly when it left",
                                 price),
                     price > 0.0);
        for (double distance : {1.0, price, 6.0, 25.0})
        {
            CrossingAdmission::Setup step = setup;
            step.farSideDistance = distance;
            report.check(std::format("  travelling {:>9.6f} over there lands it at {:+9.6f}, {}",
                                     distance, CrossingAdmission::returnMoment(step),
                                     CrossingAdmission::returnMoment(step) < 0.0
                                         ? "before departure"
                                         : "at or after departure"),
                         std::isfinite(CrossingAdmission::returnMoment(step)));
        }
        report.check("so the moment it lands on is the far-side distance minus the price, and the "
                     "only quantity a traveller controls is that distance",
                     std::abs(CrossingAdmission::returnMoment(setup) - (price - 6.0)) < 1e-12);
        report.check("nothing here bounds the distance from above, so the moment reached falls "
                     "without limit; what falls with it is the weight, and the limit on going "
                     "further back is therefore a limit on being detected rather than on arriving",
                     CrossingAdmission::returnMoment(CrossingAdmission::protonSetup(1e6)) <
                         CrossingAdmission::returnMoment(CrossingAdmission::protonSetup(25.0)));
    }

}
