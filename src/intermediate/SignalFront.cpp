#include "intermediate/SignalFront.h"

#include "core/Report.h"
#include "intermediate/DwellTime.h"
#include "intermediate/TraversalClocks.h"
#include "intermediate/TwoCrossings.h"

#include <cmath>
#include <complex>
#include <format>

namespace slm
{

    double SignalFront::phaseSpeed(double omega, double c, double mu, double transverseSquared)
    {
        const double outside = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        if (outside <= 0.0)
        {
            return 0.0;
        }
        return omega / std::sqrt(outside);
    }

    double SignalFront::groupSpeed(double omega, double c, double mu, double transverseSquared)
    {
        const double outside = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
        if (outside <= 0.0 || omega <= 0.0)
        {
            return 0.0;
        }
        return c * c * std::sqrt(outside) / omega;
    }

    double SignalFront::frontSpeed(double c, double mu, double transverseSquared, double omega)
    {
        return phaseSpeed(omega, c, mu, transverseSquared);
    }

    double SignalFront::frontExcess(double omega, double c, double mu, double transverseSquared)
    {
        return phaseSpeed(omega, c, mu, transverseSquared) - c;
    }

    double SignalFront::frontDelay(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                   double transverseSquared, double thickness)
    {
        return TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, thickness);
    }

    double SignalFront::transmittedMagnitude(IntermediateRegion::Kind kind, double omega, double c,
                                             double mu, double transverseSquared, double thickness)
    {
        return std::abs(
            TwoCrossings::amplitude(kind, omega, c, mu, transverseSquared, thickness));
    }

    bool SignalFront::frontRespectsLight(IntermediateRegion::Kind kind, double c, double mu,
                                         double transverseSquared, double thickness,
                                         double probeOmega)
    {
        const double delay = frontDelay(kind, probeOmega, c, mu, transverseSquared, thickness);
        if (delay <= 0.0)
        {
            return false;
        }
        return delay >= thickness / c - 1e-6;
    }

    bool SignalFront::advanceCarriesSignal(IntermediateRegion::Kind kind, double c, double mu,
                                           double transverseSquared, double thickness,
                                           double probeOmega)
    {
        return !frontRespectsLight(kind, c, mu, transverseSquared, thickness, probeOmega);
    }

    void SignalFrontSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double barrierOmega = 2.8;

        report.subsection("A speed above light that carries nothing, which is older than "
                          "any of this");
        for (double omega : {2.8, 6.0, 20.0})
        {
            report.check(std::format("  omega = {:5g} : phase speed {:8.4f} c, group speed "
                                     "{:6.4f} c, and their product is {:.6f}",
                                     omega, SignalFront::phaseSpeed(omega, c, mu, transverse),
                                     SignalFront::groupSpeed(omega, c, mu, transverse),
                                     SignalFront::phaseSpeed(omega, c, mu, transverse) *
                                         SignalFront::groupSpeed(omega, c, mu, transverse)),
                         SignalFront::phaseSpeed(omega, c, mu, transverse) > c &&
                             SignalFront::groupSpeed(omega, c, mu, transverse) < c);
        }
        report.check("the phase outruns light at every frequency while the energy "
                     "never does, so a speed above light is by itself no evidence "
                     "that anything was sent",
                     SignalFront::phaseSpeed(20.0, c, mu, transverse) > c &&
                         SignalFront::groupSpeed(20.0, c, mu, transverse) < c);

        report.subsection("The front takes the limit and the limit is light");
        for (double omega : {10.0, 100.0, 1000.0, 100000.0})
        {
            report.check(std::format("  omega = {:9g} : front speed {:.8f} c, exceeding light by "
                                     "{:.3e}",
                                     omega, SignalFront::frontSpeed(c, mu, transverse, omega),
                                     SignalFront::frontExcess(omega, c, mu, transverse)),
                         SignalFront::frontExcess(omega, c, mu, transverse) > 0.0);
        }
        report.check("the excess falls towards zero as the frequency grows, so the "
                     "front travels at exactly the speed of light and not above it",
                     SignalFront::frontExcess(100000.0, c, mu, transverse) <
                         1e-6 * SignalFront::frontExcess(100.0, c, mu, transverse));

        report.subsection("The region is transparent to the front, whatever it does below");
        for (double thickness : {4.0, 16.0})
        {
            report.check(std::format("  d = {:5g} : the front is delayed by {:.6f} against a "
                                     "light time of {:.6f}",
                                     thickness,
                                     SignalFront::frontDelay(Kind::Euclidean, 100000.0, c, mu,
                                                             transverse, thickness),
                                     TwoCrossings::lightTime(thickness, c)),
                         SignalFront::frontRespectsLight(Kind::Euclidean, c, mu, transverse,
                                                         thickness, 100000.0));
        }
        report.check("the front is never advanced by the region, at any thickness "
                     "tested, so no advance of the peak reaches it",
                     SignalFront::frontRespectsLight(Kind::Euclidean, c, mu, transverse, 4.0,
                                                     100000.0) &&
                         SignalFront::frontRespectsLight(Kind::Euclidean, c, mu, transverse, 16.0,
                                                         100000.0));

        report.subsection("What the advanced peak is carried on");
        for (double thickness : {2.0, 8.0, 32.0})
        {
            report.check(std::format("  d = {:5g} : transmitted magnitude {:.4e}, while the peak "
                                     "advance stands at {:+.4f}",
                                     thickness,
                                     SignalFront::transmittedMagnitude(Kind::Euclidean,
                                                                       barrierOmega, c, mu,
                                                                       transverse, thickness),
                                     TwoCrossings::lightTime(thickness, c) -
                                         TwoCrossings::returnDelay(Kind::Euclidean, barrierOmega, c,
                                                                   mu, transverse, thickness)),
                         SignalFront::transmittedMagnitude(Kind::Euclidean, barrierOmega, c, mu,
                                                           transverse, thickness) > 0.0);
        }
        report.check("the advance grows while the amplitude carrying it falls away, "
                     "so the two move against each other and no amount of thickness "
                     "buys an advance on something detectable",
                     SignalFront::transmittedMagnitude(Kind::Euclidean, barrierOmega, c, mu,
                                                       transverse, 32.0) <
                         SignalFront::transmittedMagnitude(Kind::Euclidean, barrierOmega, c, mu,
                                                           transverse, 2.0));

        report.subsection("What this settles and what it leaves open");
        report.check("the advance of the peak carries no signal, which is conceded "
                     "here rather than argued around",
                     !SignalFront::advanceCarriesSignal(Kind::Euclidean, c, mu, transverse, 16.0,
                                                        100000.0));
        report.check("so the placement of the return event is a statement about "
                     "where a peak lands and not a claim that a message overtook "
                     "light through the region",
                     !SignalFront::advanceCarriesSignal(Kind::Euclidean, c, mu, transverse, 4.0,
                                                        100000.0));
        report.check("this is a bound on transmission through the barrier and says "
                     "nothing about the crossing itself, where the mass shell and "
                     "not the front decides what returns",
                     TraversalClocks::readingsFasterThanLight(Kind::Euclidean, barrierOmega, c, mu,
                                                              transverse, 16.0) > 0);
    }

}
