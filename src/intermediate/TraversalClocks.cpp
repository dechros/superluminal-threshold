#include "intermediate/TraversalClocks.h"

#include "core/Report.h"
#include "intermediate/DwellTime.h"
#include "intermediate/TwoCrossings.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kStep = 1e-5;
    }

    std::complex<double> TraversalClocks::complexClock(IntermediateRegion::Kind kind, double omega,
                                                       double c, double mu,
                                                       double transverseSquared, double thickness)
    {
        const std::complex<double> high = TwoCrossings::amplitudeWithInteriorOffset(
            kind, omega, c, mu, transverseSquared, thickness, kStep);
        const std::complex<double> low = TwoCrossings::amplitudeWithInteriorOffset(
            kind, omega, c, mu, transverseSquared, thickness, -kStep);
        if (std::abs(high) == 0.0 || std::abs(low) == 0.0)
        {
            return {0.0, 0.0};
        }
        const std::complex<double> ratio = high / low;
        const double phaseDerivative = std::arg(ratio) / (2.0 * kStep);
        const double magnitudeDerivative = std::log(std::abs(high) / std::abs(low)) / (2.0 * kStep);
        const double scale = 2.0 * omega / (c * c);
        return {-scale * phaseDerivative, -scale * magnitudeDerivative};
    }

    double TraversalClocks::rotationComponent(IntermediateRegion::Kind kind, double omega, double c,
                                              double mu, double transverseSquared, double thickness)
    {
        return complexClock(kind, omega, c, mu, transverseSquared, thickness).real();
    }

    double TraversalClocks::alignmentComponent(IntermediateRegion::Kind kind, double omega,
                                               double c, double mu, double transverseSquared,
                                               double thickness)
    {
        return complexClock(kind, omega, c, mu, transverseSquared, thickness).imag();
    }

    double TraversalClocks::modulatedBarrierTime(IntermediateRegion::Kind kind, double omega,
                                                 double c, double mu, double transverseSquared,
                                                 double thickness)
    {
        return std::abs(complexClock(kind, omega, c, mu, transverseSquared, thickness));
    }

    double TraversalClocks::semiclassicalTime(IntermediateRegion::Kind kind, double omega, double c,
                                              double mu, double transverseSquared, double thickness)
    {
        const std::complex<double> q =
            DwellTime::interiorWavenumber(kind, omega, c, mu, transverseSquared);
        const double magnitude = std::abs(q);
        if (magnitude <= 0.0 || omega <= 0.0)
        {
            return 0.0;
        }
        const double speed = c * c * magnitude / omega;
        return thickness / speed;
    }

    bool TraversalClocks::saturates(double nearValue, double farValue)
    {
        if (std::abs(nearValue) <= 0.0)
        {
            return std::abs(farValue) <= 0.0;
        }
        return std::abs(farValue - nearValue) < 0.05 * std::abs(nearValue);
    }

    double TraversalClocks::alignmentSlope(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared,
                                           double firstThickness, double secondThickness)
    {
        if (secondThickness == firstThickness)
        {
            return 0.0;
        }
        const double first =
            alignmentComponent(kind, omega, c, mu, transverseSquared, firstThickness);
        const double second =
            alignmentComponent(kind, omega, c, mu, transverseSquared, secondThickness);
        return (second - first) / (secondThickness - firstThickness);
    }

    bool TraversalClocks::rotationMatchesDwell(IntermediateRegion::Kind kind, double omega,
                                               double c, double mu, double transverseSquared,
                                               double thickness, double tolerance)
    {
        const double rotation =
            rotationComponent(kind, omega, c, mu, transverseSquared, thickness);
        const double dwell =
            DwellTime::dwellTime(kind, omega, c, mu, transverseSquared, thickness);
        if (std::abs(dwell) <= 0.0)
        {
            return false;
        }
        return std::abs(rotation - dwell) <= tolerance * std::abs(dwell);
    }

    int TraversalClocks::unsaturatedReadingCount(IntermediateRegion::Kind kind, double omega,
                                                 double c, double mu, double transverseSquared)
    {
        const double near = 4.0;
        const double far = 16.0;
        int count = 0;
        count += saturates(TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, near),
                           TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, far))
                     ? 0
                     : 1;
        count += saturates(DwellTime::dwellTime(kind, omega, c, mu, transverseSquared, near),
                           DwellTime::dwellTime(kind, omega, c, mu, transverseSquared, far))
                     ? 0
                     : 1;
        count += saturates(rotationComponent(kind, omega, c, mu, transverseSquared, near),
                           rotationComponent(kind, omega, c, mu, transverseSquared, far))
                     ? 0
                     : 1;
        count += saturates(alignmentComponent(kind, omega, c, mu, transverseSquared, near),
                           alignmentComponent(kind, omega, c, mu, transverseSquared, far))
                     ? 0
                     : 1;
        count += saturates(semiclassicalTime(kind, omega, c, mu, transverseSquared, near),
                           semiclassicalTime(kind, omega, c, mu, transverseSquared, far))
                     ? 0
                     : 1;
        return count;
    }

    double TraversalClocks::speedInLightUnits(double reading, double thickness, double c)
    {
        if (reading <= 0.0 || c <= 0.0)
        {
            return 0.0;
        }
        return thickness / (reading * c);
    }

    int TraversalClocks::readingsFasterThanLight(IntermediateRegion::Kind kind, double omega,
                                                 double c, double mu, double transverseSquared,
                                                 double thickness)
    {
        const double readings[] = {
            TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, thickness),
            DwellTime::dwellTime(kind, omega, c, mu, transverseSquared, thickness),
            rotationComponent(kind, omega, c, mu, transverseSquared, thickness),
            alignmentComponent(kind, omega, c, mu, transverseSquared, thickness),
            semiclassicalTime(kind, omega, c, mu, transverseSquared, thickness)};
        int count = 0;
        for (double reading : readings)
        {
            count += speedInLightUnits(reading, thickness, c) > 1.0 ? 1 : 0;
        }
        return count;
    }

    bool TraversalClocks::readingsAgreeAgainstLight(IntermediateRegion::Kind kind, double omega,
                                                    double c, double mu, double transverseSquared,
                                                    double thickness)
    {
        const int fast =
            readingsFasterThanLight(kind, omega, c, mu, transverseSquared, thickness);
        return fast == 0 || fast == 5;
    }

    void TraversalClocksSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double barrierOmega = 2.8;
        const double propagatingOmega = 6.0;

        report.subsection("Five readings of one crossing, in the barrier regime");
        for (double thickness : {2.0, 4.0, 8.0, 16.0, 32.0})
        {
            report.check(
                std::format("  d = {:5g} : phase {:8.4f}, dwell {:8.4f}, rotation {:8.4f}, "
                            "alignment {:9.4f}, semiclassical {:9.4f}",
                            thickness,
                            TwoCrossings::returnDelay(Kind::Euclidean, barrierOmega, c, mu,
                                                      transverse, thickness),
                            DwellTime::dwellTime(Kind::Euclidean, barrierOmega, c, mu, transverse,
                                                 thickness),
                            TraversalClocks::rotationComponent(Kind::Euclidean, barrierOmega, c, mu,
                                                               transverse, thickness),
                            TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega, c,
                                                                mu, transverse, thickness),
                            TraversalClocks::semiclassicalTime(Kind::Euclidean, barrierOmega, c, mu,
                                                               transverse, thickness)),
                std::isfinite(TraversalClocks::modulatedBarrierTime(Kind::Euclidean, barrierOmega,
                                                                    c, mu, transverse, thickness)));
        }

        report.subsection("The rotation component and the dwell time are the same quantity");
        for (double thickness : {2.0, 8.0})
        {
            report.check(std::format("  d = {:g} : rotation {:.6f} against dwell {:.6f}", thickness,
                                     TraversalClocks::rotationComponent(Kind::Euclidean,
                                                                        barrierOmega, c, mu,
                                                                        transverse, thickness),
                                     DwellTime::dwellTime(Kind::Euclidean, barrierOmega, c, mu,
                                                          transverse, thickness)),
                         TraversalClocks::rotationMatchesDwell(Kind::Euclidean, barrierOmega, c, mu,
                                                               transverse, thickness, 1e-2));
        }
        report.check("two constructions that share no formula agree, so the stored-field "
                     "reading is not an artefact of how the norm was integrated",
                     TraversalClocks::rotationMatchesDwell(Kind::Euclidean, barrierOmega, c, mu,
                                                           transverse, 8.0, 1e-2));

        report.subsection("Which readings stop growing and which do not");
        report.check("the phase reading saturates, which is what makes it look fast",
                     TraversalClocks::saturates(TwoCrossings::returnDelay(Kind::Euclidean,
                                                                          barrierOmega, c, mu,
                                                                          transverse, 4.0),
                                                TwoCrossings::returnDelay(Kind::Euclidean,
                                                                          barrierOmega, c, mu,
                                                                          transverse, 16.0)));
        report.check("the dwell reading saturates with it, for the same reason",
                     TraversalClocks::saturates(DwellTime::dwellTime(Kind::Euclidean, barrierOmega,
                                                                     c, mu, transverse, 4.0),
                                                DwellTime::dwellTime(Kind::Euclidean, barrierOmega,
                                                                     c, mu, transverse, 16.0)));
        report.check(std::format("  the alignment reading does not: it grows by {:.4f} per unit "
                                 "thickness between eight and thirty two",
                                 TraversalClocks::alignmentSlope(Kind::Euclidean, barrierOmega, c,
                                                                 mu, transverse, 8.0, 32.0)),
                     !TraversalClocks::saturates(
                         TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega, c, mu,
                                                             transverse, 4.0),
                         TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega, c, mu,
                                                             transverse, 16.0)));
        report.check(std::format("  {} of the five readings still grow with thickness here",
                                 TraversalClocks::unsaturatedReadingCount(Kind::Euclidean,
                                                                          barrierOmega, c, mu,
                                                                          transverse)),
                     TraversalClocks::unsaturatedReadingCount(Kind::Euclidean, barrierOmega, c, mu,
                                                              transverse) > 0);

        report.subsection("The two growing readings agree with each other");
        for (double thickness : {8.0, 32.0})
        {
            const double alignment = TraversalClocks::alignmentComponent(
                Kind::Euclidean, barrierOmega, c, mu, transverse, thickness);
            const double semiclassical = TraversalClocks::semiclassicalTime(
                Kind::Euclidean, barrierOmega, c, mu, transverse, thickness);
            report.check(std::format("  d = {:5g} : alignment {:8.4f} against semiclassical "
                                     "{:8.4f}, differing by {:.2f} per cent",
                                     thickness, alignment, semiclassical,
                                     100.0 * std::abs(alignment - semiclassical) / semiclassical),
                         std::abs(alignment - semiclassical) < 0.07 * semiclassical);
        }
        report.check("their difference is a fixed offset rather than a fixed ratio, so "
                     "the two agree in slope and separate only by the surfaces",
                     std::abs((TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega, c,
                                                                   mu, transverse, 32.0) -
                               TraversalClocks::semiclassicalTime(Kind::Euclidean, barrierOmega, c,
                                                                  mu, transverse, 32.0)) -
                              (TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega, c,
                                                                   mu, transverse, 8.0) -
                               TraversalClocks::semiclassicalTime(Kind::Euclidean, barrierOmega, c,
                                                                  mu, transverse, 8.0))) < 1e-2);

        report.subsection("Each reading measured against light, which is what the "
                          "comparison is for");
        for (double thickness : {4.0, 16.0})
        {
            report.check(
                std::format("  d = {:5g} : phase {:6.3f} c, dwell {:6.3f} c, rotation {:6.3f} c, "
                            "alignment {:6.3f} c, semiclassical {:6.3f} c",
                            thickness,
                            TraversalClocks::speedInLightUnits(
                                TwoCrossings::returnDelay(Kind::Euclidean, barrierOmega, c, mu,
                                                          transverse, thickness),
                                thickness, c),
                            TraversalClocks::speedInLightUnits(
                                DwellTime::dwellTime(Kind::Euclidean, barrierOmega, c, mu,
                                                     transverse, thickness),
                                thickness, c),
                            TraversalClocks::speedInLightUnits(
                                TraversalClocks::rotationComponent(Kind::Euclidean, barrierOmega, c,
                                                                   mu, transverse, thickness),
                                thickness, c),
                            TraversalClocks::speedInLightUnits(
                                TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega,
                                                                    c, mu, transverse, thickness),
                                thickness, c),
                            TraversalClocks::speedInLightUnits(
                                TraversalClocks::semiclassicalTime(Kind::Euclidean, barrierOmega, c,
                                                                   mu, transverse, thickness),
                                thickness, c)),
                std::isfinite(TraversalClocks::speedInLightUnits(
                    DwellTime::dwellTime(Kind::Euclidean, barrierOmega, c, mu, transverse,
                                         thickness),
                    thickness, c)));
        }
        report.check(std::format("  {} of the five readings put the crossing above the speed of "
                                 "light and the remaining {} put it below",
                                 TraversalClocks::readingsFasterThanLight(
                                     Kind::Euclidean, barrierOmega, c, mu, transverse, 16.0),
                                 5 - TraversalClocks::readingsFasterThanLight(
                                         Kind::Euclidean, barrierOmega, c, mu, transverse, 16.0)),
                     TraversalClocks::readingsFasterThanLight(Kind::Euclidean, barrierOmega, c, mu,
                                                              transverse, 16.0) > 0);
        report.check("the readings do not agree on which side of light the crossing "
                     "falls, so the comparison with light is not a property of the "
                     "region either and has to be made reading by reading",
                     !TraversalClocks::readingsAgreeAgainstLight(Kind::Euclidean, barrierOmega, c,
                                                                 mu, transverse, 16.0));
        report.check("the split is not an accident of thickness: it is the same at "
                     "four and at sixteen",
                     TraversalClocks::readingsFasterThanLight(Kind::Euclidean, barrierOmega, c, mu,
                                                              transverse, 4.0) ==
                         TraversalClocks::readingsFasterThanLight(Kind::Euclidean, barrierOmega, c,
                                                                  mu, transverse, 16.0));
        report.check("the three readings that saturate are the three that outrun "
                     "light, and they saturate for the same reason they outrun it",
                     TraversalClocks::readingsFasterThanLight(Kind::Euclidean, barrierOmega, c, mu,
                                                              transverse, 16.0) ==
                         5 - TraversalClocks::unsaturatedReadingCount(Kind::Euclidean, barrierOmega,
                                                                       c, mu, transverse));

        report.subsection("What that costs the fast reading");
        report.check("the saturation is a property of two readings and not of the "
                     "crossing, since a reading built on the same amplitude keeps "
                     "growing at every thickness tested",
                     TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega, c, mu,
                                                         transverse, 32.0) >
                         TraversalClocks::alignmentComponent(Kind::Euclidean, barrierOmega, c, mu,
                                                             transverse, 8.0));
        report.check("so no single number answers how long the crossing took, and "
                     "quoting one of them is a choice of measurement rather than a "
                     "property of the region",
                     TraversalClocks::unsaturatedReadingCount(Kind::Euclidean, barrierOmega, c, mu,
                                                              transverse) < 5);

        report.subsection("The propagating regime, where the readings converge");
        for (double thickness : {2.0, 8.0})
        {
            report.check(std::format("  d = {:g} : phase {:.4f}, semiclassical {:.4f}", thickness,
                                     TwoCrossings::returnDelay(Kind::None, propagatingOmega, c, mu,
                                                               transverse, thickness),
                                     TraversalClocks::semiclassicalTime(Kind::None,
                                                                        propagatingOmega, c, mu,
                                                                        transverse, thickness)),
                         std::abs(TwoCrossings::returnDelay(Kind::None, propagatingOmega, c, mu,
                                                            transverse, thickness) -
                                  TraversalClocks::semiclassicalTime(Kind::None, propagatingOmega,
                                                                     c, mu, transverse,
                                                                     thickness)) < 1e-6);
        }
        report.check("where the interior propagates the phase reading and the "
                     "semiclassical reading are the same number, so the disagreement "
                     "belongs to the barrier and not to the method",
                     std::abs(TwoCrossings::returnDelay(Kind::None, propagatingOmega, c, mu,
                                                        transverse, 8.0) -
                              TraversalClocks::semiclassicalTime(Kind::None, propagatingOmega, c,
                                                                 mu, transverse, 8.0)) < 1e-6);
    }

}
