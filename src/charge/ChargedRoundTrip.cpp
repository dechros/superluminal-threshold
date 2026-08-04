#include "charge/ChargedRoundTrip.h"

#include "core/Report.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <limits>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kProtonMass = 1.67262192369e-27;
        constexpr double kLightSpeed = 2.99792458e8;
        constexpr double kReducedPlanck = 1.054571817e-34;
        constexpr double kElementaryCharge = 1.602176634e-19;
        constexpr double kJoulesPerMegaElectronVolt = 1.602176634e-13;
    }

    double ChargedRoundTrip::restEnergy(double massInKilograms, double c)
    {
        return massInKilograms * c * c;
    }

    double ChargedRoundTrip::restFrequency(double massInKilograms, double c, double hbar)
    {
        return restEnergy(massInKilograms, c) / hbar;
    }

    double ChargedRoundTrip::massParameter(double massInKilograms, double c, double hbar)
    {
        const double inverseLength = massInKilograms * c / hbar;
        return inverseLength * inverseLength;
    }

    bool ChargedRoundTrip::bandCanCarry(double massInKilograms, double c, double hbar,
                                       double centre)
    {
        return centre > restFrequency(massInKilograms, c, hbar);
    }

    double ChargedRoundTrip::effectiveFrequency(double omega, double charge, double potential,
                                                double hbar)
    {
        return omega - charge * potential / hbar;
    }

    double ChargedRoundTrip::readingUnderPotential(ThreeRoutes::Route route,
                                                   IntermediateRegion::Kind kind, double omega,
                                                   double c, double mu, double transverseSquared,
                                                   double thickness, double charge,
                                                   double potential, double hbar)
    {
        const double shifted = effectiveFrequency(omega, charge, potential, hbar);
        return ThreeRoutes::roundTripReading(route, kind, shifted, c, mu, transverseSquared,
                                             thickness);
    }

    double ChargedRoundTrip::thresholdUnderPotential(ThreeRoutes::Route route,
                                                    IntermediateRegion::Kind kind, double omega,
                                                    double c, double mu, double transverseSquared,
                                                    double thickness, double charge,
                                                    double potential, double hbar)
    {
        return readingUnderPotential(route, kind, omega, c, mu, transverseSquared, thickness,
                                     charge, potential, hbar);
    }

    bool ChargedRoundTrip::timingIgnoresChargeWithoutPotential(
        ThreeRoutes::Route route, IntermediateRegion::Kind kind, double omega, double c, double mu,
        double transverseSquared, double thickness, double hbar)
    {
        const double light = readingUnderPotential(route, kind, omega, c, mu, transverseSquared,
                                                   thickness, 1.0, 0.0, hbar);
        const double heavy = readingUnderPotential(route, kind, omega, c, mu, transverseSquared,
                                                   thickness, 5.0, 0.0, hbar);
        return std::abs(light - heavy) < 1e-15;
    }

    bool ChargedRoundTrip::potentialSteersTheReturn(ThreeRoutes::Route route,
                                                    IntermediateRegion::Kind kind, double omega,
                                                    double c, double mu, double transverseSquared,
                                                    double thickness, double charge,
                                                    double potential, double hbar)
    {
        const double unbiased = readingUnderPotential(route, kind, omega, c, mu, transverseSquared,
                                                      thickness, charge, 0.0, hbar);
        const double biased = readingUnderPotential(route, kind, omega, c, mu, transverseSquared,
                                                    thickness, charge, potential, hbar);
        return std::abs(biased - unbiased) > 1e-9;
    }

    namespace
    {
        struct Cheapest
        {
            double value = 0.0;
            double potential = 0.0;
            int index = 0;
        };

        Cheapest scanPotential(ThreeRoutes::Route route, IntermediateRegion::Kind kind,
                               double omega, double c, double mu, double transverseSquared,
                               double thickness, double charge, double reach, int samples,
                               double hbar)
        {
            Cheapest best;
            best.value = std::numeric_limits<double>::infinity();
            if (samples < 2)
            {
                return best;
            }
            const double step = 2.0 * reach / (samples - 1);
            for (int i = 0; i < samples; ++i)
            {
                const double potential = -reach + i * step;
                const double value = ChargedRoundTrip::readingUnderPotential(
                    route, kind, omega, c, mu, transverseSquared, thickness, charge, potential,
                    hbar);
                if (std::isfinite(value) && value > 0.0 && value < best.value)
                {
                    best.value = value;
                    best.potential = potential;
                    best.index = i;
                }
            }
            return best;
        }
    }

    double ChargedRoundTrip::cheapestThreshold(ThreeRoutes::Route route,
                                               IntermediateRegion::Kind kind, double omega,
                                               double c, double mu, double transverseSquared,
                                               double thickness, double charge, double reach,
                                               int samples, double hbar)
    {
        return scanPotential(route, kind, omega, c, mu, transverseSquared, thickness, charge, reach,
                             samples, hbar)
            .value;
    }

    double ChargedRoundTrip::potentialAtCheapest(ThreeRoutes::Route route,
                                                 IntermediateRegion::Kind kind, double omega,
                                                 double c, double mu, double transverseSquared,
                                                 double thickness, double charge, double reach,
                                                 int samples, double hbar)
    {
        return scanPotential(route, kind, omega, c, mu, transverseSquared, thickness, charge, reach,
                             samples, hbar)
            .potential;
    }

    bool ChargedRoundTrip::cheapestIsInterior(ThreeRoutes::Route route,
                                              IntermediateRegion::Kind kind, double omega,
                                              double c, double mu, double transverseSquared,
                                              double thickness, double charge, double reach,
                                              int samples, double hbar)
    {
        const Cheapest best = scanPotential(route, kind, omega, c, mu, transverseSquared, thickness,
                                            charge, reach, samples, hbar);
        return best.index > 0 && best.index < samples - 1;
    }

    Vector4 ChargedRoundTrip::nearSideCurrent(double c, double chargeDensity, double jx, double jy,
                                              double jz)
    {
        return Vector4(chargeDensity * c, jx, jy, jz);
    }

    Vector4 ChargedRoundTrip::farSideCurrent(const Vector4 &near)
    {
        const Matrix4 d = SignatureInvolution::matrix();
        Vector4 far(0.0, 0.0, 0.0, 0.0);
        for (std::size_t row = 0; row < 4; ++row)
        {
            double sum = 0.0;
            for (std::size_t column = 0; column < 4; ++column)
            {
                sum += d.at(row, column) * near[column];
            }
            far[row] = sum;
        }
        return far;
    }

    bool ChargedRoundTrip::densityBecomesCurrent(const Vector4 &near)
    {
        const Vector4 far = farSideCurrent(near);
        return std::abs(far[3] - near[0]) < 1e-12 && std::abs(far[0] - near[3]) < 1e-12;
    }

    double ChargedRoundTrip::currentInvariant(const Vector4 &current, bool farSide)
    {
        return current.contract(farSide ? metricRegionII() : metricRegionI());
    }

    bool ChargedRoundTrip::invariantSurvives(const Vector4 &near, double tolerance)
    {
        const double here = currentInvariant(near, false);
        const double there = currentInvariant(farSideCurrent(near), true);
        return std::abs(there + here) < tolerance;
    }

    void ChargedRoundTripSection::run(Report &report) const
    {
        const IntermediateRegion::Kind kind = IntermediateRegion::Kind::Euclidean;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double centre = 2.8;
        const double thickness = 8.0;
        const double hbar = 1.0;
        const ThreeRoutes::Route wave = ThreeRoutes::Route::Wave;

        report.subsection("What charge does not do");
        report.check("changing the charge at zero applied potential leaves the round trip reading "
                     "exactly where it was, so the crossing does not know the charge and the "
                     "timing is not a charge effect",
                     ChargedRoundTrip::timingIgnoresChargeWithoutPotential(
                         wave, kind, centre, c, mu, transverse, thickness, hbar));
        for (ThreeRoutes::Route route : ThreeRoutes::all())
        {
            report.check(std::format("  {:<11} : the same holds on this description",
                                     ThreeRoutes::name(route)),
                         ChargedRoundTrip::timingIgnoresChargeWithoutPotential(
                             route, kind, centre, c, mu, transverse, thickness, hbar));
        }

        report.subsection("What charge buys: a knob on the return moment");
        const double baseline = ChargedRoundTrip::thresholdUnderPotential(
            wave, kind, centre, c, mu, transverse, thickness, 1.0, 0.0, hbar);
        for (double potential : {-0.2, -0.1, 0.0, 0.1, 0.2})
        {
            const double needed = ChargedRoundTrip::thresholdUnderPotential(
                wave, kind, centre, c, mu, transverse, thickness, 1.0, potential, hbar);
            report.check(std::format("  potential {:+.2f} : the far-side distance needed becomes "
                                     "{:.6f}, against {:.6f} unbiased",
                                     potential, needed, baseline),
                         needed > 0.0);
        }
        report.check("an applied potential moves the distance the state needs, so for a charged "
                     "state the return moment is steerable from outside the region rather than "
                     "fixed by the state alone",
                     ChargedRoundTrip::potentialSteersTheReturn(wave, kind, centre, c, mu,
                                                                 transverse, thickness, 1.0, 0.1,
                                                                 hbar));
        const double reach = 0.5;
        const int scanSamples = 2001;
        const double cheapest = ChargedRoundTrip::cheapestThreshold(
            wave, kind, centre, c, mu, transverse, thickness, 1.0, reach, scanSamples, hbar);
        const double tuned = ChargedRoundTrip::potentialAtCheapest(
            wave, kind, centre, c, mu, transverse, thickness, 1.0, reach, scanSamples, hbar);
        report.check(std::format("the knob is not a lever: the price falls, reaches {:.6f} at a "
                                 "potential of {:+.4f}, and rises again on both sides",
                                 cheapest, tuned),
                     ChargedRoundTrip::cheapestIsInterior(wave, kind, centre, c, mu, transverse,
                                                           thickness, 1.0, reach, scanSamples,
                                                           hbar));
        report.check("so what the potential buys is a tuning onto the cheapest journey rather than "
                     "an arbitrarily cheap one, and the cheapest journey is a floor that no charge "
                     "and no potential goes under",
                     cheapest > 0.0 && cheapest <= baseline);
        report.check("the unbiased configuration is not already at that floor, so the tuning has "
                     "something to do, and the amount it gains is small against the price itself",
                     baseline > cheapest && (baseline - cheapest) / baseline < 0.05);
        report.check("a neutral state offers no such knob, since the shift is the charge times "
                     "the potential and vanishes with the charge",
                     !ChargedRoundTrip::potentialSteersTheReturn(wave, kind, centre, c, mu,
                                                                  transverse, thickness, 0.0, 0.1,
                                                                  hbar));

        report.subsection("What charge means on the far side");
        const Vector4 near = ChargedRoundTrip::nearSideCurrent(1.0, 3.0, 0.0, 0.0, 0.5);
        const Vector4 far = ChargedRoundTrip::farSideCurrent(near);
        report.check(std::format("  the near-side four-current is ({:.1f}, {:.1f}, {:.1f}, {:.1f})",
                                 near[0], near[1], near[2], near[3]),
                     true);
        report.check(std::format("  the far side writes it as ({:.1f}, {:.1f}, {:.1f}, {:.1f})",
                                 far[0], far[1], far[2], far[3]),
                     true);
        report.check("the near side's charge density has become a far-side current component and "
                     "one of its currents has become the density, because the crossing carries "
                     "the time axis onto a space axis and the density is the time component",
                     ChargedRoundTrip::densityBecomesCurrent(near));
        report.check("so asking how much charge sits over there is not the question it is here: "
                     "the four-current maps whole, and only its split into density and current is "
                     "reshuffled",
                     ChargedRoundTrip::densityBecomesCurrent(near));
        report.check("the invariant square of the four-current is carried across up to the overall "
                     "sign the crossing imposes, which is what conservation of the current amounts "
                     "to here and is weaker than equality",
                     ChargedRoundTrip::invariantSurvives(near, 1e-12));

        report.subsection("The price of admission for a proton, in laboratory units");
        const double restMev =
            ChargedRoundTrip::restEnergy(kProtonMass, kLightSpeed) / kJoulesPerMegaElectronVolt;
        const double frequency =
            ChargedRoundTrip::restFrequency(kProtonMass, kLightSpeed, kReducedPlanck);
        report.check(std::format("  the proton rest energy is {:.1f} MeV", restMev),
                     restMev > 900.0 && restMev < 950.0);
        report.check(std::format("  so the band centre has to clear {:.4e} radians per second, "
                                 "which is the frequency built from that rest energy",
                                 frequency),
                     frequency > 1e24 && frequency < 2e24);
        report.check("a band below that frequency cannot carry a proton across at all, which turns "
                     "the mass ceiling into a stated laboratory requirement rather than a scale to "
                     "be estimated later",
                     !ChargedRoundTrip::bandCanCarry(kProtonMass, kLightSpeed, kReducedPlanck,
                                                     1e23) &&
                         ChargedRoundTrip::bandCanCarry(kProtonMass, kLightSpeed, kReducedPlanck,
                                                        2e24));
        report.check(std::format("  the mass parameter it corresponds to is {:.4e} per square "
                                 "metre, the squared inverse Compton wavelength",
                                 ChargedRoundTrip::massParameter(kProtonMass, kLightSpeed,
                                                                  kReducedPlanck)),
                     ChargedRoundTrip::massParameter(kProtonMass, kLightSpeed, kReducedPlanck) >
                         1e31);
        report.check(std::format("  and an elementary charge against a one volt potential shifts "
                                 "the effective frequency by {:.4e} radians per second, which is "
                                 "the size of the knob in the same units",
                                 kElementaryCharge / kReducedPlanck),
                     kElementaryCharge / kReducedPlanck > 1e15);
        report.check("the knob is therefore about nine orders of magnitude below the admission "
                     "frequency, so steering the return is a fine adjustment on a coarse "
                     "requirement and not a way around it",
                     kElementaryCharge / kReducedPlanck < 1e-6 * frequency);
    }

}
