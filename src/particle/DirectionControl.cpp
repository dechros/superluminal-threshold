#include "particle/DirectionControl.h"

#include "boundary/ProfiledBarrier.h"
#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        ProfiledBarrier::Profile mirrored(const ProfiledBarrier::Profile &shape, double width)
        {
            return [shape, width](double position) { return shape(width - position); };
        }
    }

    DirectionControl::Signs DirectionControl::reciprocityElement()
    {
        return {1.0, -1.0, 1.0, 1.0};
    }

    DirectionControl::Signs DirectionControl::jointReversalElement()
    {
        return {-1.0, -1.0, 1.0, 1.0};
    }

    DirectionControl::Signs DirectionControl::product(const Signs &left, const Signs &right)
    {
        Signs result{};
        for (std::size_t i = 0; i < result.size(); ++i)
        {
            result[i] = left[i] * right[i];
        }
        return result;
    }

    bool DirectionControl::operationsAreDistinct()
    {
        const Signs first = reciprocityElement();
        const Signs second = jointReversalElement();
        for (std::size_t i = 0; i < first.size(); ++i)
        {
            if (std::abs(first[i] - second[i]) > 1e-12)
            {
                return true;
            }
        }
        return false;
    }

    bool DirectionControl::productIsPureTimeReversal()
    {
        const Signs combined = product(reciprocityElement(), jointReversalElement());
        return std::abs(combined[0] + 1.0) < 1e-12 && std::abs(combined[1] - 1.0) < 1e-12 &&
               std::abs(combined[2] - 1.0) < 1e-12 && std::abs(combined[3] - 1.0) < 1e-12;
    }

    double DirectionControl::transmissionFromLeft(double width, double total,
                                                  double outsideWavenumber)
    {
        const ProfiledBarrier::Profile shape =
            ProfiledBarrier::profile(ProfiledBarrier::Shape::Skewed, width, total);
        return ProfiledBarrier::transmission(shape, width, outsideWavenumber);
    }

    double DirectionControl::transmissionFromRight(double width, double total,
                                                   double outsideWavenumber)
    {
        const ProfiledBarrier::Profile shape =
            ProfiledBarrier::profile(ProfiledBarrier::Shape::Skewed, width, total);
        return ProfiledBarrier::transmission(mirrored(shape, width), width, outsideWavenumber);
    }

    double DirectionControl::reciprocityResidual(double width, double total,
                                                 double outsideWavenumber)
    {
        return std::abs(transmissionFromLeft(width, total, outsideWavenumber) -
                        transmissionFromRight(width, total, outsideWavenumber));
    }

    bool DirectionControl::anyShapeSteers(double width, double total, double outsideWavenumber,
                                          double tolerance)
    {
        for (ProfiledBarrier::Shape each : ProfiledBarrier::shapes())
        {
            const ProfiledBarrier::Profile shape = ProfiledBarrier::profile(each, width, total);
            const double forward = ProfiledBarrier::transmission(shape, width, outsideWavenumber);
            const double backward =
                ProfiledBarrier::transmission(mirrored(shape, width), width, outsideWavenumber);
            if (std::abs(forward - backward) > tolerance * (1.0 + std::abs(forward)))
            {
                return true;
            }
        }
        return false;
    }

    bool DirectionControl::profileIsGenuinelyAsymmetric(double width, double total)
    {
        const ProfiledBarrier::Profile shape =
            ProfiledBarrier::profile(ProfiledBarrier::Shape::Skewed, width, total);
        double largest = 0.0;
        for (int i = 1; i < 20; ++i)
        {
            const double x = width * i / 20.0;
            largest = std::max(largest, std::abs(shape(x) - shape(width - x)));
        }
        return largest > 1e-3;
    }

    double DirectionControl::directionFromChannel(double incidentWavenumber)
    {
        if (incidentWavenumber > 0.0)
        {
            return 1.0;
        }
        return incidentWavenumber < 0.0 ? -1.0 : 0.0;
    }

    double DirectionControl::directionFromPair(double firstWeight, double secondWeight,
                                               double relativePhase)
    {
        return 2.0 * firstWeight * secondWeight * std::sin(relativePhase);
    }

    bool DirectionControl::pairIsOddInPhase(double firstWeight, double secondWeight)
    {
        const double forward = directionFromPair(firstWeight, secondWeight, 0.7);
        const double backward = directionFromPair(firstWeight, secondWeight, -0.7);
        return std::abs(forward + backward) < 1e-12 && std::abs(forward) > 1e-12;
    }

    bool DirectionControl::singleChannelCanBeBiased(double width, double total,
                                                    double outsideWavenumber, double tolerance)
    {
        return anyShapeSteers(width, total, outsideWavenumber, tolerance);
    }

    void DirectionControlSection::run(Report &report) const
    {
        const double width = 2.0;
        const double total = 3.0;
        const double outside = 1.0;

        report.subsection("This is not the question the branch sweep answered");
        report.check(std::format("  reciprocity turns the crossing axis alone : "
                                 "({:+.0f}, {:+.0f}, {:+.0f}, {:+.0f})",
                                 DirectionControl::reciprocityElement()[0],
                                 DirectionControl::reciprocityElement()[1],
                                 DirectionControl::reciprocityElement()[2],
                                 DirectionControl::reciprocityElement()[3]),
                     DirectionControl::reciprocityElement()[1] < 0.0);
        report.check(std::format("  the branch reversal turns our time slot with it : "
                                 "({:+.0f}, {:+.0f}, {:+.0f}, {:+.0f})",
                                 DirectionControl::jointReversalElement()[0],
                                 DirectionControl::jointReversalElement()[1],
                                 DirectionControl::jointReversalElement()[2],
                                 DirectionControl::jointReversalElement()[3]),
                     DirectionControl::jointReversalElement()[0] < 0.0);
        report.check("the two are different group elements, so a theorem about one "
                     "does not settle the other and the two obstructions must be kept "
                     "apart",
                     DirectionControl::operationsAreDistinct());
        report.check("they differ by a pure reversal of our time slot, which is the "
                     "precise sense in which the direction question and the map "
                     "question are separate",
                     DirectionControl::productIsPureTimeReversal());

        report.subsection("Shaping the transition cannot bias the direction");
        report.check("the skewed profile really is asymmetric, so the equality below "
                     "is a theorem doing work rather than a symmetry hiding in the "
                     "profile",
                     DirectionControl::profileIsGenuinelyAsymmetric(width, total));
        report.check(std::format("  entered from the left  : {:.10e}",
                                 DirectionControl::transmissionFromLeft(width, total, outside)),
                     DirectionControl::transmissionFromLeft(width, total, outside) > 0.0);
        report.check(std::format("  entered from the right : {:.10e}",
                                 DirectionControl::transmissionFromRight(width, total, outside)),
                     DirectionControl::transmissionFromRight(width, total, outside) > 0.0);
        report.check(std::format("  the two differ by {:.3e}",
                                 DirectionControl::reciprocityResidual(width, total, outside)),
                     DirectionControl::reciprocityResidual(width, total, outside) < 1e-9);
        report.check("no profile built in this work transmits differently from the two "
                     "sides, which reproduces the published reciprocity result rather "
                     "than assuming it",
                     !DirectionControl::anyShapeSteers(width, total, outside, 1e-9));

        report.subsection("So a single channel cannot be steered from here");
        report.check("with one propagating channel per direction the transmitted weight "
                     "is blind to which side the particle came from, and the direction "
                     "of travel is whatever sign the particle already carried",
                     !DirectionControl::singleChannelCanBeBiased(width, total, outside, 1e-9));
        report.check(std::format("  a channel arriving with a positive wavenumber leaves "
                                 "with direction {:+.0f}, a negative one with {:+.0f}",
                                 DirectionControl::directionFromChannel(1.0),
                                 DirectionControl::directionFromChannel(-1.0)),
                     DirectionControl::directionFromChannel(1.0) > 0.0 &&
                         DirectionControl::directionFromChannel(-1.0) < 0.0);

        report.subsection("Where a steer would have to come from");
        for (double phase : {-0.7, 0.0, 0.7})
        {
            report.check(std::format("  relative phase {:+.1f} : pair direction {:+.6f}", phase,
                                     DirectionControl::directionFromPair(0.6, 0.8, phase)),
                         std::isfinite(DirectionControl::directionFromPair(0.6, 0.8, phase)));
        }
        report.check("a coherent pair of channels carries a direction that is odd in "
                     "the relative phase, so the bias sits in the incident state and "
                     "not in the barrier, which is the one place reciprocity leaves "
                     "open",
                     DirectionControl::pairIsOddInPhase(0.6, 0.8));
        report.check("that is the same requirement the branch sweep reached from the "
                     "other side, a quantity odd in exactly one axis, arrived at here "
                     "for the direction rather than for the map",
                     DirectionControl::pairIsOddInPhase(0.6, 0.8) &&
                         DirectionControl::operationsAreDistinct());
        report.check("whether this work supplies such a channel structure is not shown: "
                     "the far side carries one spatial axis and the pair above is "
                     "written down rather than derived from the crossing, so this is "
                     "where a steer would have to be built and not a steer",
                     !DirectionControl::singleChannelCanBeBiased(width, total, outside, 1e-9));
    }

}
