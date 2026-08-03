#include "boundary/ProfiledBarrier.h"

#include "core/Report.h"

#include <cmath>
#include <complex>
#include <format>
#include <numbers>

namespace slm
{

    namespace
    {
        double shapeValue(ProfiledBarrier::Shape shape, double u)
        {
            switch (shape)
            {
            case ProfiledBarrier::Shape::Uniform:
                return 1.0;
            case ProfiledBarrier::Shape::Triangle:
                return 1.0 - std::fabs(2.0 * u - 1.0);
            case ProfiledBarrier::Shape::HalfSine:
                return std::sin(std::numbers::pi * u);
            case ProfiledBarrier::Shape::Plateau:
                return std::tanh(6.0 * u) * std::tanh(6.0 * (1.0 - u));
            case ProfiledBarrier::Shape::Skewed:
                return u * u * (1.0 - u);
            }
            return 1.0;
        }
    }

    std::string ProfiledBarrier::name(Shape shape)
    {
        switch (shape)
        {
        case Shape::Uniform:
            return "uniform";
        case Shape::Triangle:
            return "triangle";
        case Shape::HalfSine:
            return "half sine";
        case Shape::Plateau:
            return "plateau";
        case Shape::Skewed:
            return "skewed";
        }
        return "uniform";
    }

    std::vector<ProfiledBarrier::Shape> ProfiledBarrier::shapes()
    {
        return {Shape::Uniform, Shape::Triangle, Shape::HalfSine, Shape::Plateau, Shape::Skewed};
    }

    ProfiledBarrier::Profile ProfiledBarrier::profile(Shape shape, double width, double total)
    {
        const int samples = 8192;
        double area = 0.0;
        for (int i = 0; i < samples; ++i)
        {
            area += shapeValue(shape, (i + 0.5) / samples);
        }
        area *= width / samples;

        const double gain = area > 0.0 ? total / area : 0.0;
        return [shape, width, gain](double position)
        {
            const double u = width > 0.0 ? position / width : 0.0;
            return gain * shapeValue(shape, u);
        };
    }

    double ProfiledBarrier::integratedDecay(const Profile &profile, double width, int slices)
    {
        double sum = 0.0;
        for (int i = 0; i < slices; ++i)
        {
            sum += profile(width * (i + 0.5) / slices);
        }
        return sum * width / slices;
    }

    double ProfiledBarrier::transmission(const Profile &profile, double width,
                                         double outsideWavenumber, int slices)
    {
        using Complex = std::complex<double>;
        const Complex ik(0.0, outsideWavenumber);

        Complex value(1.0, 0.0);
        Complex slope = ik;

        const double h = width / slices;
        for (int i = slices - 1; i >= 0; --i)
        {
            const double q = profile(width * (i + 0.5) / slices);
            double s11 = 1.0;
            double s12 = h;
            double s21 = 0.0;
            double s22 = 1.0;
            if (q > 0.0)
            {
                const double ch = std::cosh(q * h);
                const double sh = std::sinh(q * h);
                s11 = ch;
                s12 = sh / q;
                s21 = q * sh;
                s22 = ch;
            }

            const Complex nextValue = s22 * value - s12 * slope;
            const Complex nextSlope = -s21 * value + s11 * slope;
            value = nextValue;
            slope = nextSlope;
        }

        return std::norm(2.0 / (value + slope / ik));
    }

    double ProfiledBarrier::realisedExponent(const Profile &profile, double width,
                                             double outsideWavenumber, int slices)
    {
        const double total = integratedDecay(profile, width, slices);
        const double t = transmission(profile, width, outsideWavenumber, slices);
        if (total <= 0.0 || t <= 0.0)
        {
            return 0.0;
        }
        return std::log(t) / (-2.0 * total);
    }

    void ProfiledBarrierSection::run(Report &report) const
    {
        const double width = 4.0;
        const double k = 1.0;

        report.subsection("The profiles differ in shape and agree in total");
        for (ProfiledBarrier::Shape shape : ProfiledBarrier::shapes())
        {
            const auto p = ProfiledBarrier::profile(shape, width, 6.0);
            report.checkNear(std::format("  {:<10} : integrated decay is the requested 6",
                                         ProfiledBarrier::name(shape)),
                             ProfiledBarrier::integratedDecay(p, width) - 6.0, 1e-6);
        }

        const auto uniform = ProfiledBarrier::profile(ProfiledBarrier::Shape::Uniform, width, 6.0);
        const auto triangle = ProfiledBarrier::profile(ProfiledBarrier::Shape::Triangle, width, 6.0);
        report.check("near the edge the shaped profile is under a quarter of the flat "
                     "one, so the agreement in total is not an agreement in shape",
                     triangle(0.05 * width) < 0.25 * uniform(0.05 * width));
        report.check("and at the centre the shaped one stands well above the flat "
                     "one, which is where the total it saved at the edges has gone",
                     triangle(width / 2.0) > 1.5 * uniform(width / 2.0));
        report.check("a triangle and a uniform profile of equal total nonetheless "
                     "agree at one interior point, so a comparison made at a single "
                     "point would have found no difference at all",
                     std::fabs(uniform(width / 4.0) - triangle(width / 4.0)) < 1e-9);

        report.subsection("What gets through is set by the total, not by the shape");
        for (double total : {4.0, 8.0, 16.0, 32.0})
        {
            double smallest = 2.0;
            double largest = 0.0;
            for (ProfiledBarrier::Shape shape : ProfiledBarrier::shapes())
            {
                const auto p = ProfiledBarrier::profile(shape, width, total);
                const double exponent = ProfiledBarrier::realisedExponent(p, width, k);
                smallest = std::min(smallest, exponent);
                largest = std::max(largest, exponent);
            }
            report.check(std::format("  total = {:<4g} : the exponent every shape "
                                     "realises lies in [{:.4f}, {:.4f}]",
                                     total, smallest, largest),
                         smallest > 0.0 && largest > 0.0);
            report.check(std::format("  total = {:<4g} : and the spread across shapes "
                                     "is {:.4f}, which shrinks as the total grows",
                                     total, largest - smallest),
                         largest - smallest < 12.0 / total);
        }

        report.subsection("The limit the spread is shrinking towards");
        for (ProfiledBarrier::Shape shape : ProfiledBarrier::shapes())
        {
            const auto p = ProfiledBarrier::profile(shape, width, 64.0);
            const double exponent = ProfiledBarrier::realisedExponent(p, width, k);
            report.check(std::format("  {:<10} : realised exponent {:.5f}, within a "
                                     "twentieth of one",
                                     ProfiledBarrier::name(shape), exponent),
                         std::fabs(exponent - 1.0) < 0.05);
        }

        report.subsection("The shape is not entirely invisible either");
        const auto uniformThick = ProfiledBarrier::profile(ProfiledBarrier::Shape::Uniform, width,
                                                           8.0);
        const auto skewedThick = ProfiledBarrier::profile(ProfiledBarrier::Shape::Skewed, width,
                                                          8.0);
        const double a = ProfiledBarrier::transmission(uniformThick, width, k);
        const double b = ProfiledBarrier::transmission(skewedThick, width, k);
        report.check(std::format("two shapes of equal total transmit {:.3e} and {:.3e}, "
                                "which differ",
                                a, b),
                     std::fabs(a - b) > 0.0);
        report.check("so it is the exponent that the total fixes and the prefactor "
                     "that it does not, which is the precise form of the published "
                     "statement rather than a stronger one",
                     std::fabs(std::log(a) - std::log(b)) < 0.2 * std::fabs(std::log(a)));

        report.subsection("The slicing is fine enough to be reporting the barrier");
        const auto probe = ProfiledBarrier::profile(ProfiledBarrier::Shape::HalfSine, width, 16.0);
        const double coarse = ProfiledBarrier::transmission(probe, width, k, 512);
        const double fine = ProfiledBarrier::transmission(probe, width, k, 8192);
        report.check(std::format("sixteen times as many slices moves the transmission "
                                 "from {:.6e} to {:.6e}, a relative change under a "
                                 "thousandth",
                                 coarse, fine),
                     std::fabs(coarse - fine) < 1e-3 * fine);
        report.check("and the exact uniform formula computed elsewhere agrees with "
                     "the sliced one, so the composition is not merely converging "
                     "to something of its own",
                     std::fabs(ProfiledBarrier::transmission(
                                   ProfiledBarrier::profile(ProfiledBarrier::Shape::Uniform,
                                                            width, 6.0),
                                   width, k) -
                               1.0 / (1.0 + (k * k + 2.25) * (k * k + 2.25) /
                                                (4.0 * k * k * 2.25) *
                                                std::sinh(1.5 * width) *
                                                std::sinh(1.5 * width))) < 1e-9);
    }

}
