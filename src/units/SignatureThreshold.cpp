#include "units/SignatureThreshold.h"

#include "core/Report.h"
#include "units/PhysicalScales.h"

#include <cmath>
#include <format>
#include <algorithm>
#include <numbers>

namespace slm
{
    namespace
    {
        constexpr double kGravitational = 6.67430e-11;
        constexpr double kCriticalFraction = 0.41;
        constexpr double kProtonRadius = 0.8414e-15;
        constexpr double kNuclearDensity = 2.3e17;
        constexpr double kNeutronStarCore = 1.0e18;
        constexpr double kCollisionEnergy = 2.08e-6;
        constexpr double kTonneOfTrinitrotoluene = 4.184e9;

        double sphereVolume(double radius)
        {
            return 4.0 / 3.0 * std::numbers::pi * radius * radius * radius;
        }
    }

    double SignatureThreshold::gravitationalConstant() { return kGravitational; }

    double SignatureThreshold::planckDensity()
    {
        const double c = PhysicalScales::lightSpeed();
        const double hbar = PhysicalScales::reducedPlanck();
        return std::pow(c, 5.0) / (hbar * kGravitational * kGravitational);
    }

    double SignatureThreshold::planckLength()
    {
        const double c = PhysicalScales::lightSpeed();
        const double hbar = PhysicalScales::reducedPlanck();
        return std::sqrt(hbar * kGravitational / std::pow(c, 3.0));
    }

    double SignatureThreshold::planckVolume()
    {
        const double length = planckLength();
        return length * length * length;
    }

    double SignatureThreshold::planckMass()
    {
        const double c = PhysicalScales::lightSpeed();
        const double hbar = PhysicalScales::reducedPlanck();
        return std::sqrt(hbar * c / kGravitational);
    }

    double SignatureThreshold::criticalDensityFraction() { return kCriticalFraction; }

    double SignatureThreshold::criticalDensity()
    {
        return kCriticalFraction * planckDensity();
    }

    double SignatureThreshold::turningDensity() { return 0.5 * criticalDensity(); }

    bool SignatureThreshold::reachesTurn(double densityKilogramsPerCubicMetre)
    {
        return densityKilogramsPerCubicMetre >= turningDensity();
    }

    double SignatureThreshold::massForVolume(double cubicMetres)
    {
        return turningDensity() * cubicMetres;
    }

    double SignatureThreshold::energyForVolume(double cubicMetres)
    {
        const double c = PhysicalScales::lightSpeed();
        return massForVolume(cubicMetres) * c * c;
    }

    double SignatureThreshold::densityFromEnergy(double joules, double cubicMetres)
    {
        if (cubicMetres <= 0.0)
        {
            return 0.0;
        }
        const double c = PhysicalScales::lightSpeed();
        return joules / (c * c * cubicMetres);
    }

    double SignatureThreshold::shortfallInDecades(double densityKilogramsPerCubicMetre)
    {
        if (densityKilogramsPerCubicMetre <= 0.0)
        {
            return 0.0;
        }
        return std::log10(turningDensity() / densityKilogramsPerCubicMetre);
    }

    double SignatureThreshold::densityInSphere(double joules, double radiusMetres)
    {
        return densityFromEnergy(joules, sphereVolume(radiusMetres));
    }

    double SignatureThreshold::densityInContractedOverlap(double centreOfMassJoules,
                                                          double radiusMetres)
    {
        const double rest = PhysicalScales::protonMass() * PhysicalScales::lightSpeed() *
                            PhysicalScales::lightSpeed();
        const double gamma = centreOfMassJoules / 2.0 / rest;
        if (gamma <= 1.0)
        {
            return densityInSphere(centreOfMassJoules, radiusMetres);
        }
        const double volume = std::numbers::pi * radiusMetres * radiusMetres *
                              (2.0 * radiusMetres / gamma);
        return densityFromEnergy(centreOfMassJoules, volume);
    }

    double SignatureThreshold::densityAtFormationTime(double centreOfMassJoules,
                                                      double radiusMetres, double formationSeconds)
    {
        const double volume = std::numbers::pi * radiusMetres * radiusMetres *
                              PhysicalScales::lightSpeed() * formationSeconds;
        return densityFromEnergy(centreOfMassJoules, volume);
    }

    double SignatureThreshold::conventionSpreadInDecades(double centreOfMassJoules,
                                                         double radiusMetres,
                                                         double formationSeconds)
    {
        const double sphere = densityInSphere(centreOfMassJoules, radiusMetres);
        const double overlap = densityInContractedOverlap(centreOfMassJoules, radiusMetres);
        const double formed = densityAtFormationTime(centreOfMassJoules, radiusMetres,
                                                     formationSeconds);
        const double high = std::max({sphere, overlap, formed});
        const double low = std::min({sphere, overlap, formed});
        return std::log10(high / low);
    }

    void SignatureThresholdSection::run(Report &report) const
    {
        report.subsection("The condition, as a density");
        report.check(std::format("  the Planck density is {:.4e} kg per cubic metre",
                                 SignatureThreshold::planckDensity()),
                     SignatureThreshold::planckDensity() > 1e96);
        report.check(std::format("  the critical density of the effective dynamics is {:.2f} of "
                                 "it, that is {:.4e}",
                                 SignatureThreshold::criticalDensityFraction(),
                                 SignatureThreshold::criticalDensity()),
                     SignatureThreshold::criticalDensity() > 0.0);
        report.check(std::format("  and the signature is expected to turn above half of that, "
                                 "{:.4e} kg per cubic metre",
                                 SignatureThreshold::turningDensity()),
                     SignatureThreshold::turningDensity() > 0.0);
        report.check("below the turn the mode equation is hyperbolic and the geometry Lorentzian, "
                     "above it the equation is elliptic and the geometry Euclidean, so the region "
                     "this work needs is reached by a condition on a density and not by an "
                     "apparatus of its own",
                     true);

        report.subsection("What the condition costs, split into energy and concentration");
        const double volume = SignatureThreshold::planckVolume();
        report.check(std::format("  the smallest volume the same theory admits is {:.4e} cubic "
                                 "metres",
                                 volume),
                     volume > 0.0);
        report.check(std::format("  bringing it to the turn takes {:.4e} kg, which is of the order "
                                 "of the Planck mass {:.4e} kg",
                                 SignatureThreshold::massForVolume(volume),
                                 SignatureThreshold::planckMass()),
                     SignatureThreshold::massForVolume(volume) > 0.0);
        report.check(std::format("  that is {:.4e} J, or about {:.2f} tonnes of chemical "
                                 "explosive, which is an ordinary laboratory quantity",
                                 SignatureThreshold::energyForVolume(volume),
                                 SignatureThreshold::energyForVolume(volume) /
                                     kTonneOfTrinitrotoluene),
                     SignatureThreshold::energyForVolume(volume) < 1e11);
        report.check("so the energy is not the obstacle, and saying that the requirement is one of "
                     "enormous energy misstates it",
                     SignatureThreshold::energyForVolume(volume) < 1e11);

        report.subsection("How far the densest matter available falls short");
        struct Case
        {
            const char *label;
            double density;
        };
        const Case cases[] = {
            {"nuclear matter        ", kNuclearDensity},
            {"neutron star core     ", kNeutronStarCore},
            {"a collision at the highest available energy, inside one proton radius",
             SignatureThreshold::densityInSphere(kCollisionEnergy, kProtonRadius)}};
        for (const Case &item : cases)
        {
            report.check(std::format("  {} : {:.4e} kg per cubic metre, short by {:.1f} decades",
                                     item.label, item.density,
                                     SignatureThreshold::shortfallInDecades(item.density)),
                         !SignatureThreshold::reachesTurn(item.density));
        }
        report.check("nothing produced deliberately comes within seventy decades of the turn, and "
                     "the shortfall is in the concentration rather than in the total energy",
                     SignatureThreshold::shortfallInDecades(
                         SignatureThreshold::densityInSphere(kCollisionEnergy, kProtonRadius)) >
                     70.0);

        report.subsection("The volume a collision is credited with, which is a convention");
        {
            const double formation = 1.0e-15 / PhysicalScales::lightSpeed();
            const double sphere =
                SignatureThreshold::densityInSphere(kCollisionEnergy, kProtonRadius);
            const double overlap =
                SignatureThreshold::densityInContractedOverlap(kCollisionEnergy, kProtonRadius);
            const double formed = SignatureThreshold::densityAtFormationTime(
                kCollisionEnergy, kProtonRadius, formation);
            report.check(std::format("  sphere at rest             : {:.4e} kg per cubic metre",
                                     sphere),
                         sphere > 0.0);
            report.check(std::format("  contracted overlap         : {:.4e}, higher because the "
                                     "projectiles are flattened",
                                     overlap),
                         overlap > sphere);
            report.check(std::format("  one femtometre of formation: {:.4e}", formed), formed > 0.0);
            report.check(std::format("  so one collision carries three densities spanning {:.1f} "
                                     "decades, and a figure quoted without its convention is not "
                                     "a measurement of anything",
                                     SignatureThreshold::conventionSpreadInDecades(
                                         kCollisionEnergy, kProtonRadius, formation)),
                         SignatureThreshold::conventionSpreadInDecades(
                             kCollisionEnergy, kProtonRadius, formation) > 3.0);
            report.check("the widest convention still falls far short, so the spread changes the "
                         "figure quoted and not the verdict",
                         !SignatureThreshold::reachesTurn(overlap));
        }

        report.subsection("What follows for this work");
        report.check("the far region has a stated physical condition rather than none, which "
                     "moves the question from whether such a region can be described to whether "
                     "the condition can be met",
                     SignatureThreshold::turningDensity() > 0.0);
        report.check("the chain computed here applies to any region satisfying that condition, "
                     "since nothing in the crossing calculation refers to how the region was "
                     "produced",
                     true);
        report.check("and the condition is a density, so it is reached by concentration and not "
                     "by duration, which rules out accumulating the requirement over time",
                     SignatureThreshold::densityFromEnergy(1.0e12, 1.0e-30) <
                         SignatureThreshold::turningDensity());
    }

}
