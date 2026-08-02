#include "signal/GravitationalChannel.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double GravitationalChannel::curvatureFromMass(double mass, double distance)
    {
        if (distance <= 0.0)
        {
            return 0.0;
        }
        return mass / (distance * distance);
    }

    double GravitationalChannel::layerDensity(IntermediateRegion::Kind kind, double thickness,
                                              double mass, double distance)
    {
        return IntermediateRegion::layerStrength(kind, thickness) -
               curvatureFromMass(mass, distance);
    }

    double GravitationalChannel::responseToMass(IntermediateRegion::Kind kind, double thickness,
                                                double distance)
    {
        const double step = 1e-6;
        const double high = layerDensity(kind, thickness, 1.0 + step, distance);
        const double low = layerDensity(kind, thickness, 1.0 - step, distance);
        return (high - low) / (2.0 * step);
    }

    bool GravitationalChannel::modulable(IntermediateRegion::Kind kind, double thickness,
                                         double distance)
    {
        return std::abs(responseToMass(kind, thickness, distance)) > 1e-12;
    }

    double GravitationalChannel::responseDelay(double distance, double c)
    {
        return c > 0.0 ? distance / c : 0.0;
    }

    double GravitationalChannel::contrast(IntermediateRegion::Kind kind, double thickness,
                                          double mass, double distance)
    {
        const double stat = IntermediateRegion::layerStrength(kind, thickness);
        if (!std::isfinite(stat) || stat == 0.0)
        {
            return 0.0;
        }
        return std::abs(curvatureFromMass(mass, distance)) / stat;
    }

    void GravitationalChannelSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double thickness = 1.0;

        report.subsection("22.1  A mass on our side changes the layer");
        for (double distance : {1.0, 2.0, 4.0})
        {
            report.check(std::format("  at distance {:g} the layer moves by {:.4f} per unit mass",
                                     distance,
                                     GravitationalChannel::responseToMass(Kind::Kleinian, thickness,
                                                                          distance)),
                         GravitationalChannel::modulable(Kind::Kleinian, thickness, distance));
        }
        report.check("so the channel is not merely present, it can be modulated",
                     GravitationalChannel::modulable(Kind::Kleinian, thickness, 1.0));

        report.subsection("22.2  The response is linear in the mass and falls as the square");
        report.checkNear("doubling the mass doubles the change",
                         GravitationalChannel::curvatureFromMass(2.0, 1.0) -
                             2.0 * GravitationalChannel::curvatureFromMass(1.0, 1.0),
                         1e-12);
        report.checkNear("doubling the distance quarters it",
                         GravitationalChannel::curvatureFromMass(1.0, 2.0) -
                             0.25 * GravitationalChannel::curvatureFromMass(1.0, 1.0),
                         1e-12);

        report.subsection("22.3  It works where every field channel is shut");
        report.check("a degenerate layer still responds to a mass",
                     GravitationalChannel::modulable(Kind::Degenerate, thickness, 1.0));
        report.check("and a Euclidean one does too",
                     GravitationalChannel::modulable(Kind::Euclidean, thickness, 1.0));

        report.subsection("22.4  Nothing here outruns light on our own side");
        for (double distance : {1.0, 5.0, 20.0})
        {
            report.checkNear(std::format("  the sender's action reaches the surface in {:g}",
                                         distance),
                             GravitationalChannel::responseDelay(distance, c) - distance, 1e-12);
        }
        report.check("the delay grows with distance, so the sender cannot beat "
                     "light to the surface",
                     GravitationalChannel::responseDelay(20.0, c) >
                         GravitationalChannel::responseDelay(1.0, c));

        report.subsection("22.5  What the far side would have to resolve");
        for (double distance : {0.5, 1.0, 4.0})
        {
            const double ratio =
                GravitationalChannel::contrast(Kind::Kleinian, thickness, 1.0, distance);
            report.check(std::format("  distance {:g} : contrast {:.4f}", distance, ratio),
                         ratio > 0.0);
        }
        report.check("the contrast falls off quickly with distance, so the sender "
                     "has to sit close to the surface",
                     GravitationalChannel::contrast(Kind::Kleinian, thickness, 1.0, 4.0) <
                         0.1 * GravitationalChannel::contrast(Kind::Kleinian, thickness, 1.0, 1.0));
        report.check("and a thicker region makes the contrast easier, since the "
                     "static layer it is measured against is weaker",
                     GravitationalChannel::contrast(Kind::Kleinian, 8.0, 1.0, 1.0) >
                         GravitationalChannel::contrast(Kind::Kleinian, 0.5, 1.0, 1.0));

        report.subsection("22.6  The verdict");
        report.check("the gravitational channel carries a signal rather than only "
                     "existing, because the layer responds to the sender",
                     GravitationalChannel::modulable(Kind::Degenerate, thickness, 1.0) &&
                         GravitationalChannel::contrast(Kind::Degenerate, thickness, 1.0, 1.0) >
                             0.0);
        report.check("but it is the weakest channel to arrange, needing the sender "
                     "near the surface and a thick region to read against",
                     GravitationalChannel::contrast(Kind::Kleinian, thickness, 1.0, 10.0) < 0.02);
    }

}
