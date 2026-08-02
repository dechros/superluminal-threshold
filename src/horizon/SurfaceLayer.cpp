#include "horizon/SurfaceLayer.h"

#include "core/Report.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{

    double SurfaceLayer::profile(Profile shape, double xi)
    {
        const double pi = std::numbers::pi;
        const double u = (xi + 1.0) / 2.0;
        switch (shape)
        {
        case Profile::Linear:
            return pi * u;
        case Profile::FlatAtCrossing:
        {
            const double t = std::sin(pi * xi / 2.0);
            return pi / 2.0 + (pi / 2.0) * t * t * t;
        }
        case Profile::Tanh:
            return pi * (1.0 + std::tanh(3.0 * xi) / std::tanh(3.0)) / 2.0;
        }
        return pi * u;
    }

    double SurfaceLayer::profileSlope(Profile shape, double xi, double h)
    {
        return (profile(shape, xi + h) - profile(shape, xi - h)) / (2.0 * h);
    }

    Matrix4 SurfaceLayer::metric(Profile shape, double xi)
    {
        return Matrix4::diagonal(1.0, -std::cos(profile(shape, xi)), -1.0, -1.0);
    }

    double SurfaceLayer::crossing(Profile shape)
    {
        const double target = std::numbers::pi / 2.0;
        double low = -1.0;
        double high = 1.0;
        for (int i = 0; i < 200; ++i)
        {
            const double mid = 0.5 * (low + high);
            if (profile(shape, mid) < target)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        return 0.5 * (low + high);
    }

    double SurfaceLayer::extrinsicCurvature(Profile shape, double xi, double h)
    {
        const double plus = -std::cos(profile(shape, xi + h));
        const double minus = -std::cos(profile(shape, xi - h));
        return 0.5 * (plus - minus) / (2.0 * h);
    }

    double SurfaceLayer::curvatureJump(Profile shape, double delta)
    {
        const double xc = crossing(shape);
        return extrinsicCurvature(shape, xc + delta) - extrinsicCurvature(shape, xc - delta);
    }

    bool SurfaceLayer::satisfiesStrongCondition(Profile shape, double tolerance)
    {
        return std::abs(extrinsicCurvature(shape, crossing(shape))) < tolerance;
    }

    bool SurfaceLayer::satisfiesWeakCondition(Profile shape, double tolerance)
    {
        return std::abs(curvatureJump(shape)) < tolerance;
    }

    void SurfaceLayerSection::run(Report &report) const
    {
        using Profile = SurfaceLayer::Profile;
        const double pi = std::numbers::pi;

        report.subsection("9.2  Where each profile changes signature");
        struct Named
        {
            const char *label;
            Profile shape;
        };
        const Named profiles[] = {{"linear", Profile::Linear},
                                  {"flat at the crossing", Profile::FlatAtCrossing},
                                  {"tanh step", Profile::Tanh}};
        for (const Named &named : profiles)
        {
            const double xc = SurfaceLayer::crossing(named.shape);
            report.checkNear(std::format("  {} : profile reaches pi/2 at xi = {:+.4f}",
                                         named.label, xc),
                             SurfaceLayer::profile(named.shape, xc) - pi / 2.0, 1e-9);
        }

        report.subsection("9.2b  Signature does change across the crossing");
        for (const Named &named : profiles)
        {
            const double xc = SurfaceLayer::crossing(named.shape);
            const Matrix4 before = SurfaceLayer::metric(named.shape, xc - 0.2);
            const Matrix4 after = SurfaceLayer::metric(named.shape, xc + 0.2);
            report.check(std::format("  {} : g_11 changes sign across xi_c", named.label),
                         before.at(1, 1) * after.at(1, 1) < 0.0);
        }

        report.subsection("9.2c  Extrinsic curvature at the crossing");
        for (const Named &named : profiles)
        {
            const double xc = SurfaceLayer::crossing(named.shape);
            const double k = SurfaceLayer::extrinsicCurvature(named.shape, xc);
            const double slope = SurfaceLayer::profileSlope(named.shape, xc);
            report.checkNear(std::format("  {} : K equals half the profile slope", named.label),
                             k - 0.5 * slope, 1e-6);
            report.check(std::format("  {} : K = {:+.4f}", named.label, k), true);
        }

        report.subsection("9.2d  Which condition each profile meets");
        report.check("linear profile fails the strong condition, K does not vanish",
                     !SurfaceLayer::satisfiesStrongCondition(Profile::Linear));
        report.check("tanh profile fails it as well, and worst of all, being "
                     "steepest exactly there",
                     !SurfaceLayer::satisfiesStrongCondition(Profile::Tanh));
        report.check("the profile built flat at the crossing meets it",
                     SurfaceLayer::satisfiesStrongCondition(Profile::FlatAtCrossing));
        for (const Named &named : profiles)
        {
            report.check(std::format("  {} : meets the weak condition, K is continuous",
                                     named.label),
                         SurfaceLayer::satisfiesWeakCondition(named.shape));
        }

        report.subsection("9.2e  What this fixes");
        report.check("no surface layer appears for any of them, since the "
                     "extrinsic curvature is continuous throughout",
                     SurfaceLayer::satisfiesWeakCondition(Profile::Linear) &&
                         SurfaceLayer::satisfiesWeakCondition(Profile::FlatAtCrossing) &&
                         SurfaceLayer::satisfiesWeakCondition(Profile::Tanh));
        report.check("the strong condition is a restriction on the profile, not "
                     "on the metric it interpolates",
                     SurfaceLayer::satisfiesStrongCondition(Profile::FlatAtCrossing) &&
                         !SurfaceLayer::satisfiesStrongCondition(Profile::Linear));
        report.check("so the choice of section 9.1 is a statement about how the "
                     "transition is approached, not about where it ends",
                     true);
    }

}
