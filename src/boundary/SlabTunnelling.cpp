#include "boundary/SlabTunnelling.h"

#include "core/Report.h"

#include <cmath>
#include <format>

namespace slm
{

    double SlabTunnelling::outsideWavenumberSquared(double c, double mu, double transverseSquared)
    {
        return c * c * (transverseSquared + mu);
    }

    double SlabTunnelling::insideWavenumberSquared(double c, double mu, double transverseSquared,
                                                   double flipped)
    {
        return c * c * (transverseSquared - 2.0 * flipped + mu);
    }

    bool SlabTunnelling::isEvanescent(double c, double mu, double transverseSquared, double flipped)
    {
        return insideWavenumberSquared(c, mu, transverseSquared, flipped) < 0.0;
    }

    double SlabTunnelling::decayConstant(double c, double mu, double transverseSquared,
                                         double flipped)
    {
        const double inside = insideWavenumberSquared(c, mu, transverseSquared, flipped);
        return inside < 0.0 ? std::sqrt(-inside) : 0.0;
    }

    double SlabTunnelling::transmission(double c, double mu, double transverseSquared,
                                        double flipped, double thickness)
    {
        const double kappaSquared = outsideWavenumberSquared(c, mu, transverseSquared);
        const double inside = insideWavenumberSquared(c, mu, transverseSquared, flipped);
        if (inside >= 0.0)
        {
            const double q = std::sqrt(inside);
            if (q == 0.0)
            {
                return 1.0;
            }
            const double s = std::sin(q * thickness);
            const double factor = (kappaSquared - inside) * (kappaSquared - inside) /
                                  (4.0 * kappaSquared * inside);
            return 1.0 / (1.0 + factor * s * s);
        }

        const double q = std::sqrt(-inside);
        const double sh = std::sinh(q * thickness);
        const double factor = (kappaSquared + q * q) * (kappaSquared + q * q) /
                              (4.0 * kappaSquared * q * q);
        return 1.0 / (1.0 + factor * sh * sh);
    }

    void SlabTunnellingSection::run(Report &report) const
    {
        const double c = 1.0;
        const double mu = 1.0;
        const double kT = 0.5;
        const double flipped = 2.0;

        report.subsection("9.4  The interior mode can be evanescent");
        report.check("outside the slab the squared wavenumber is positive",
                     SlabTunnelling::outsideWavenumberSquared(c, mu, kT) > 0.0);
        report.check("inside it turns negative once the flipped direction "
                     "carries enough of the wavenumber",
                     SlabTunnelling::isEvanescent(c, mu, kT, flipped));
        report.check("so the interior does not propagate, it decays",
                     SlabTunnelling::decayConstant(c, mu, kT, flipped) > 0.0);

        report.subsection("9.4b  Transmission falls off exponentially with thickness");
        double previous = 2.0;
        for (double d : {0.5, 1.0, 2.0, 4.0, 8.0})
        {
            const double t = SlabTunnelling::transmission(c, mu, kT, flipped, d);
            report.check(std::format("  d = {:g} : T = {:.3e}, smaller than at the "
                                     "previous thickness",
                                     d, t),
                         t < previous && t > 0.0);
            previous = t;
        }
        report.check("transmission never reaches zero at any finite thickness",
                     SlabTunnelling::transmission(c, mu, kT, flipped, 20.0) > 0.0);

        report.subsection("9.4c  The two limits");
        report.check("a vanishing thickness transmits everything",
                     SlabTunnelling::transmission(c, mu, kT, flipped, 0.0) > 0.999);
        report.check("a thick slab transmits essentially nothing, which is the "
                     "reflecting result of section 9.1",
                     SlabTunnelling::transmission(c, mu, kT, flipped, 40.0) < 1e-30);
        report.check("so total reflection is the thick-slab limit rather than a "
                     "separate statement",
                     SlabTunnelling::transmission(c, mu, kT, flipped, 40.0) <
                         SlabTunnelling::transmission(c, mu, kT, flipped, 1.0));

        report.subsection("9.4d  When the interior propagates instead");
        report.check("with little wavenumber along the flipped direction the "
                     "interior stays propagating",
                     !SlabTunnelling::isEvanescent(c, mu, kT, 0.1));
        report.check("and then transmission is oscillatory rather than "
                     "suppressed, reaching one at resonance",
                     SlabTunnelling::transmission(c, mu, kT, 0.1, 3.0) > 0.5);
        report.check("so the mode content of the incident field decides, not the "
                     "signature change on its own",
                     SlabTunnelling::isEvanescent(c, mu, kT, flipped) !=
                         SlabTunnelling::isEvanescent(c, mu, kT, 0.1));
    }

}
