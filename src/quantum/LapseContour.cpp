#include "quantum/LapseContour.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        const std::complex<double> kI(0.0, 1.0);
    }

    std::complex<double> LapseContour::exponent(std::complex<double> lapse, double distance,
                                                double mass)
    {
        if (std::abs(lapse) == 0.0)
        {
            return {0.0, 0.0};
        }
        return (distance * distance) / (2.0 * lapse) - 0.5 * mass * lapse;
    }

    std::complex<double> LapseContour::integrand(std::complex<double> lapse, double distance,
                                                 double mass)
    {
        if (std::abs(lapse) == 0.0)
        {
            return {0.0, 0.0};
        }
        return std::exp(kI * exponent(lapse, distance, mass));
    }

    std::complex<double> LapseContour::saddle(int sign, double distance, double mass)
    {
        if (mass <= 0.0)
        {
            return {0.0, 0.0};
        }
        const double magnitude = distance / std::sqrt(mass);
        return {0.0, sign >= 0 ? magnitude : -magnitude};
    }

    double LapseContour::magnitudeAtSaddle(int sign, double distance, double mass)
    {
        return std::abs(integrand(saddle(sign, distance, mass), distance, mass));
    }

    bool LapseContour::singularAtZero(double distance, double mass)
    {
        const double near = std::abs(exponent({1e-8, 0.0}, distance, mass));
        const double far = std::abs(exponent({1e-4, 0.0}, distance, mass));
        return near > 1e3 * far;
    }

    double LapseContour::rotatedIntegral(int side, double distance, double mass, double limit,
                                         int samples)
    {
        if (samples <= 0 || limit <= 0.0 || distance <= 0.0)
        {
            return 0.0;
        }
        const double step = limit / samples;
        double total = 0.0;
        for (int n = 1; n <= samples; ++n)
        {
            const double s = n * step;
            const double weightedExponent =
                side < 0 ? -((distance * distance) / (2.0 * s) + 0.5 * mass * s)
                         : ((distance * distance) / (2.0 * s) + 0.5 * mass * s);
            total += std::exp(weightedExponent) * step;
        }
        return total;
    }

    double LapseContour::decayRate(double distance, double mass)
    {
        const double value = rotatedIntegral(-1, distance, mass);
        if (value <= 0.0 || distance <= 0.0)
        {
            return 0.0;
        }
        return -std::log(value) / distance;
    }

    bool LapseContour::upperRotationDiverges(double distance, double mass)
    {
        const double shortLimit = rotatedIntegral(1, distance, mass, 20.0, 20000);
        const double longLimit = rotatedIntegral(1, distance, mass, 40.0, 40000);
        return !std::isfinite(longLimit) || longLimit > 1e6 * shortLimit;
    }

    bool LapseContour::contoursDisagree(double distance, double mass)
    {
        return upperRotationDiverges(distance, mass) &&
               std::isfinite(rotatedIntegral(-1, distance, mass));
    }

    int LapseContour::saddleReached(double distance, double mass)
    {
        const double rate = decayRate(distance, mass);
        const double lowerRate = -std::log(magnitudeAtSaddle(-1, distance, mass)) / distance;
        const double upperRate = -std::log(magnitudeAtSaddle(1, distance, mass)) / distance;
        return std::abs(rate - lowerRate) < std::abs(rate - upperRate) ? -1 : 1;
    }

    bool LapseContour::belowSelectsDecaying(double distance, double mass)
    {
        return saddleReached(distance, mass) == -1 &&
               magnitudeAtSaddle(-1, distance, mass) < 1.0;
    }

    void LapseContourSection::run(Report &report) const
    {
        const double mass = 1.0;

        report.subsection("The integrand cannot be continued through the degenerate point");
        for (double lapse : {1e-2, 1e-4, 1e-8})
        {
            report.check(std::format("  lapse {:.0e} : the exponent reaches {:.4e}", lapse,
                                     std::abs(LapseContour::exponent({lapse, 0.0}, 2.0, mass))),
                         std::isfinite(
                             std::abs(LapseContour::exponent({lapse, 0.0}, 2.0, mass))));
        }
        report.check("the exponent diverges as the lapse goes to zero, which is where "
                     "the metric degenerates, so a contour cannot run through the origin",
                     LapseContour::singularAtZero(2.0, mass));

        report.subsection("Two saddle points, one decaying and one growing");
        for (double distance : {1.0, 2.0, 4.0})
        {
            report.check(std::format("  d = {:g} : saddles at {:+.4f}i and {:+.4f}i, with "
                                     "magnitudes {:.4e} and {:.4e}",
                                     distance, LapseContour::saddle(1, distance, mass).imag(),
                                     LapseContour::saddle(-1, distance, mass).imag(),
                                     LapseContour::magnitudeAtSaddle(1, distance, mass),
                                     LapseContour::magnitudeAtSaddle(-1, distance, mass)),
                         LapseContour::magnitudeAtSaddle(-1, distance, mass) <
                             LapseContour::magnitudeAtSaddle(1, distance, mass));
        }
        report.check("the two saddles sit on the imaginary axis at equal distances "
                     "from the origin, so neither is nearer and only the side of the "
                     "contour tells them apart",
                     std::abs(LapseContour::saddle(1, 2.0, mass).imag() +
                              LapseContour::saddle(-1, 2.0, mass).imag()) < 1e-12);
        report.check("the lower saddle carries a decaying amplitude and the upper one "
                     "a growing amplitude, so the choice of side is the choice between "
                     "them",
                     LapseContour::magnitudeAtSaddle(-1, 2.0, mass) < 1.0 &&
                         LapseContour::magnitudeAtSaddle(1, 2.0, mass) > 1.0);

        report.subsection("One rotation converges and the other does not");
        report.check(std::format("  rotated downwards : {:.6e}",
                                 LapseContour::rotatedIntegral(-1, 2.0, mass)),
                     std::isfinite(LapseContour::rotatedIntegral(-1, 2.0, mass)) &&
                         LapseContour::rotatedIntegral(-1, 2.0, mass) > 0.0);
        report.check("rotated upwards the integral does not converge at all, so the "
                     "two sides do not merely give different answers: one of them "
                     "gives none",
                     LapseContour::upperRotationDiverges(2.0, mass));
        report.check("the continuation is therefore not free, and a criterion is "
                     "needed rather than optional",
                     LapseContour::contoursDisagree(2.0, mass));

        report.subsection("Which saddle the surviving contour actually landed on");
        for (double distance : {2.0, 4.0, 8.0, 16.0})
        {
            report.check(std::format("  d = {:5g} : measured fall-off rate {:.4f} against "
                                     "{:.4f} for the lower saddle and {:.4f} for the upper",
                                     distance, LapseContour::decayRate(distance, mass),
                                     -std::log(LapseContour::magnitudeAtSaddle(-1, distance, mass)) /
                                         distance,
                                     -std::log(LapseContour::magnitudeAtSaddle(1, distance, mass)) /
                                         distance),
                         LapseContour::saddleReached(distance, mass) == -1);
        }
        report.check("the rate is measured from the integral and compared against both "
                     "saddles, so which one was reached is computed and not assumed",
                     LapseContour::belowSelectsDecaying(8.0, mass));
        report.check("the measured rate climbs towards the saddle rate as the distance "
                     "grows, which is the prefactor dying rather than the saddle moving",
                     LapseContour::decayRate(2.0, mass) < LapseContour::decayRate(4.0, mass) &&
                         LapseContour::decayRate(4.0, mass) < LapseContour::decayRate(8.0, mass) &&
                         LapseContour::decayRate(8.0, mass) < LapseContour::decayRate(16.0, mass));
        report.check("and it stays below the saddle rate at every distance, so the "
                     "saddle bounds the integral rather than being fitted to it",
                     LapseContour::decayRate(16.0, mass) < 1.0);
        report.check("the selected amplitude falls with distance rather than growing, "
                     "which is the behaviour the crossing calculation uses in the "
                     "barrier regime",
                     LapseContour::magnitudeAtSaddle(-1, 8.0, mass) <
                         LapseContour::magnitudeAtSaddle(-1, 1.0, mass));
        report.check("so adopting the contour criterion is consistent with what this "
                     "model already does, rather than overturning it: the criterion "
                     "was unstated, not violated",
                     LapseContour::belowSelectsDecaying(2.0, mass) &&
                         LapseContour::belowSelectsDecaying(8.0, mass));
    }

}
