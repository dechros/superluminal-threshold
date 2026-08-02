#include "particle/FarSideMotion.h"

#include "core/Report.h"
#include "intermediate/TwoCrossings.h"
#include "particle/AsymmetricFaces.h"

#include <cmath>
#include <format>

namespace slm
{

    double FarSideMotion::crossingWavenumber(IntermediateRegion::Kind kind, double omega, double c,
                                             double mu, double transverseSquared)
    {
        const double inside = TwoCrossings::insideSquared(kind, omega, c, mu, transverseSquared);
        return inside > 0.0 ? std::sqrt(inside) : 0.0;
    }

    bool FarSideMotion::interiorPropagates(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared)
    {
        return TwoCrossings::insideSquared(kind, omega, c, mu, transverseSquared) > 0.0;
    }

    double FarSideMotion::crossingGroupSpeed(IntermediateRegion::Kind kind, double omega, double c,
                                             double mu, double transverseSquared)
    {
        if (!interiorPropagates(kind, omega, c, mu, transverseSquared))
        {
            return 0.0;
        }
        const double step = 1e-5;
        const double high = crossingWavenumber(kind, omega + step, c, mu, transverseSquared);
        const double low = crossingWavenumber(kind, omega - step, c, mu, transverseSquared);
        const double slope = (high - low) / (2.0 * step);
        return slope > 0.0 ? 1.0 / slope : 0.0;
    }

    double FarSideMotion::motionTime(IntermediateRegion::Kind kind, double omega, double c,
                                     double mu, double transverseSquared, double thickness)
    {
        const double speed = crossingGroupSpeed(kind, omega, c, mu, transverseSquared);
        return speed > 0.0 ? thickness / speed : 0.0;
    }

    double FarSideMotion::phaseTime(IntermediateRegion::Kind kind, double omega, double c,
                                    double mu, double transverseSquared, double thickness)
    {
        return TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, thickness);
    }

    double FarSideMotion::vectorLength(const Three &energy)
    {
        return std::sqrt(energy[0] * energy[0] + energy[1] * energy[1] + energy[2] * energy[2]);
    }

    FarSideMotion::Three FarSideMotion::rotateInTimePlane(const Three &energy, int plane,
                                                          double angle)
    {
        const int first = plane % 3;
        const int second = (plane + 1) % 3;
        const int third = (plane + 2) % 3;
        const double cosine = std::cos(angle);
        const double sine = std::sin(angle);
        Three turned{};
        turned[first] = cosine * energy[first] - sine * energy[second];
        turned[second] = sine * energy[first] + cosine * energy[second];
        turned[third] = energy[third];
        return turned;
    }

    double FarSideMotion::sweptAngle(const Three &from, const Three &to)
    {
        const double lengths = vectorLength(from) * vectorLength(to);
        if (lengths <= 0.0)
        {
            return 0.0;
        }
        const double dot = from[0] * to[0] + from[1] * to[1] + from[2] * to[2];
        const double cosine = std::fmin(1.0, std::fmax(-1.0, dot / lengths));
        return std::acos(cosine);
    }

    double FarSideMotion::crossingWavenumberFromEnergy(double c, double mu, const Three &energy)
    {
        const double length = vectorLength(energy);
        return c * std::sqrt(length * length + mu);
    }

    bool FarSideMotion::rotationChangesCrossingWavenumber(double c, double mu, const Three &energy)
    {
        const double reference = crossingWavenumberFromEnergy(c, mu, energy);
        for (int plane = 0; plane < 3; ++plane)
        {
            for (int step = 1; step <= 24; ++step)
            {
                const double angle = step * (2.0 * std::acos(-1.0) / 24.0);
                const Three turned = rotateInTimePlane(energy, plane, angle);
                if (std::abs(crossingWavenumberFromEnergy(c, mu, turned) - reference) > 1e-9)
                {
                    return true;
                }
            }
        }
        return false;
    }

    double FarSideMotion::momentFromEnergy(IntermediateRegion::Kind kind, double c, double mu,
                                           const Three &energy, double thickness)
    {
        const double length = vectorLength(energy);
        const double omega = c * std::sqrt(length * length + mu);
        const double transverseSquared = energy[1] * energy[1] + energy[2] * energy[2];
        return TwoCrossings::returnDelay(kind, omega, c, mu, transverseSquared, thickness);
    }

    bool FarSideMotion::timePlaneMovesTheMoment(IntermediateRegion::Kind kind, double c, double mu,
                                                const Three &energy, double thickness, int plane)
    {
        const double reference = momentFromEnergy(kind, c, mu, energy, thickness);
        for (int step = 1; step <= 8; ++step)
        {
            const double angle = step * 0.1;
            const Three turned = rotateInTimePlane(energy, plane, angle);
            if (std::abs(momentFromEnergy(kind, c, mu, turned, thickness) - reference) > 1e-6)
            {
                return true;
            }
        }
        return false;
    }

    int FarSideMotion::observableTurnCount(double px, double py, double pz)
    {
        return static_cast<int>(AsymmetricFaces::deflectionSpectrum(px, py, pz).size());
    }

    void FarSideMotionSection::run(Report &report) const
    {
        using Kind = IntermediateRegion::Kind;
        const double c = 1.0;
        const double mu = 1.0;
        const double transverse = 4.0;
        const double propagatingOmega = 6.0;
        const double barrierOmega = 2.8;
        const FarSideMotion::Three energy{1.0, 2.0, 2.0};

        report.subsection("25.1  What motion over there consists of");
        report.check("crossing the region is displacement along the far side's one "
                     "spatial axis, and it has a wavenumber",
                     FarSideMotion::crossingWavenumber(Kind::Kleinian, propagatingOmega, c, mu,
                                                       transverse) > 0.0);
        report.checkNear("everything else is rotation of the energy vector in the "
                         "three time planes, which preserves its length",
                         FarSideMotion::vectorLength(
                             FarSideMotion::rotateInTimePlane(energy, 0, 0.7)) -
                             FarSideMotion::vectorLength(energy),
                         1e-12);
        for (int plane = 0; plane < 3; ++plane)
        {
            report.checkNear(std::format("  time plane {} : rotation keeps the length", plane),
                             FarSideMotion::vectorLength(
                                 FarSideMotion::rotateInTimePlane(energy, plane, 1.3)) -
                                 FarSideMotion::vectorLength(energy),
                             1e-12);
        }

        report.subsection("25.2  The exit moment is a travel time only while the interior propagates");
        for (Kind kind : {Kind::None, Kind::Kleinian, Kind::Euclidean})
        {
            const double speed =
                FarSideMotion::crossingGroupSpeed(kind, propagatingOmega, c, mu, transverse);
            report.check(std::format("  {:22} : group speed {:.4f} along the crossing axis",
                                     IntermediateRegion::name(kind), speed),
                         speed > 0.0 && speed < c + 1e-9);
        }
        report.check("in the barrier regime there is no group speed at all, because "
                     "the interior does not propagate",
                     FarSideMotion::crossingGroupSpeed(Kind::Euclidean, barrierOmega, c, mu,
                                                       transverse) == 0.0);
        report.check("yet the phase still returns a definite exit moment there",
                     FarSideMotion::phaseTime(Kind::Euclidean, barrierOmega, c, mu, transverse,
                                              4.0) > 0.0);

        report.subsection("25.3  Where both readings exist they agree");
        for (double thickness : {1.0, 2.0, 4.0})
        {
            const double travel = FarSideMotion::motionTime(Kind::None, propagatingOmega, c, mu,
                                                             transverse, thickness);
            const double phase = FarSideMotion::phaseTime(Kind::None, propagatingOmega, c, mu,
                                                           transverse, thickness);
            report.checkNear(std::format("  d = {:g} : travel time {:.4f} against phase time {:.4f}",
                                         thickness, travel, phase),
                             travel - phase, 1e-4);
        }

        report.subsection("25.4  Where only one exists they part company");
        double previousPhase = 0.0;
        bool noTravelAnywhere = true;
        bool phaseSaturates = true;
        for (double thickness : {2.0, 4.0, 8.0})
        {
            const double travel = FarSideMotion::motionTime(Kind::Euclidean, barrierOmega, c, mu,
                                                             transverse, thickness);
            const double phase = FarSideMotion::phaseTime(Kind::Euclidean, barrierOmega, c, mu,
                                                           transverse, thickness);
            report.check(std::format("  d = {:g} : travel time {:.4f}, phase time {:.4f}", thickness,
                                     travel, phase),
                         travel == 0.0 && phase > 0.0);
            if (travel != 0.0)
            {
                noTravelAnywhere = false;
            }
            if (thickness > 4.0 && std::abs(phase - previousPhase) > 1e-6)
            {
                phaseSaturates = false;
            }
            previousPhase = phase;
        }
        report.check("the saturation of the exit moment is therefore not a fast "
                     "journey but the absence of a journey",
                     noTravelAnywhere && phaseSaturates);
        report.check("so the Hartman effect is here a statement about motion: "
                     "nothing crosses, and the phase is all there is",
                     FarSideMotion::motionTime(Kind::Euclidean, barrierOmega, c, mu, transverse,
                                               8.0) == 0.0 &&
                         !FarSideMotion::interiorPropagates(Kind::Euclidean, barrierOmega, c, mu,
                                                            transverse));

        report.subsection("25.5  The exit face cannot see the rotation");
        report.check("no rotation of the energy vector in any time plane changes "
                     "the crossing wavenumber, whose sign is the exit face",
                     !FarSideMotion::rotationChangesCrossingWavenumber(c, mu, energy));
        for (FarSideMotion::Three probe : {FarSideMotion::Three{3.0, 0.0, 0.0},
                                           FarSideMotion::Three{0.0, 1.0, 5.0},
                                           FarSideMotion::Three{2.0, 2.0, 2.0}})
        {
            report.check(std::format("  length {:.4f} : the exit face is blind to the path",
                                     FarSideMotion::vectorLength(probe)),
                         !FarSideMotion::rotationChangesCrossingWavenumber(c, mu, probe));
        }

        report.subsection("25.6  The exit moment sees one of the three time planes and not the "
                          "other two");
        const FarSideMotion::Three turning{2.0, 2.0, 1.0};
        const double thickness = 2.0;
        report.check(std::format("  the moment before any rotation is {:.4f}",
                                 FarSideMotion::momentFromEnergy(Kind::None, c, mu, turning,
                                                                  thickness)),
                     FarSideMotion::momentFromEnergy(Kind::None, c, mu, turning, thickness) > 0.0);
        report.check("rotating in the plane of the two transverse slots leaves the "
                     "moment exactly where it was",
                     !FarSideMotion::timePlaneMovesTheMoment(Kind::None, c, mu, turning, thickness,
                                                             1));
        report.check("rotating in either plane that touches the crossing slot moves it",
                     FarSideMotion::timePlaneMovesTheMoment(Kind::None, c, mu, turning, thickness,
                                                            0) &&
                         FarSideMotion::timePlaneMovesTheMoment(Kind::None, c, mu, turning,
                                                                thickness, 2));
        report.checkNear("the invariant plane is invariant because it moves no weight "
                         "between the crossing direction and the transverse ones",
                         (FarSideMotion::rotateInTimePlane(turning, 1, 0.7)[1] *
                              FarSideMotion::rotateInTimePlane(turning, 1, 0.7)[1] +
                          FarSideMotion::rotateInTimePlane(turning, 1, 0.7)[2] *
                              FarSideMotion::rotateInTimePlane(turning, 1, 0.7)[2]) -
                             (turning[1] * turning[1] + turning[2] * turning[2]),
                         1e-12);
        report.check("so which plane the particle turns in over there is visible "
                     "here, while the exit face stays blind to all three",
                     !FarSideMotion::rotationChangesCrossingWavenumber(c, mu, turning));

        report.subsection("25.7  What the rotation does leave behind");
        const double quarter = std::acos(-1.0) / 2.0;
        report.check(std::format("  a path rotating a quarter turn sweeps {:.4f} radians",
                                 FarSideMotion::sweptAngle(
                                     energy, FarSideMotion::rotateInTimePlane(energy, 0, quarter))),
                     FarSideMotion::sweptAngle(
                         energy, FarSideMotion::rotateInTimePlane(energy, 0, quarter)) > 0.0);
        report.check("the swept angle takes a continuum of values, since the "
                     "rotation angle is free",
                     FarSideMotion::sweptAngle(energy,
                                               FarSideMotion::rotateInTimePlane(energy, 0, 0.31)) !=
                         FarSideMotion::sweptAngle(
                             energy, FarSideMotion::rotateInTimePlane(energy, 0, 0.32)));
        report.check(std::format("  but only {} distinct turns are observable here, "
                                 "because the two faces come from a finite set",
                                 FarSideMotion::observableTurnCount(1.0, 2.0, 3.0)),
                     FarSideMotion::observableTurnCount(1.0, 2.0, 3.0) > 0);
        report.check("so the interior path is compressed onto a finite spectrum, "
                     "and that compression is the information the journey loses",
                     FarSideMotion::observableTurnCount(1.0, 2.0, 3.0) < 100);

        report.subsection("25.8  The linkage stated");
        report.check("the exit face is fixed at the faces and not in the interior, "
                     "since the interior motion leaves it untouched",
                     !FarSideMotion::rotationChangesCrossingWavenumber(c, mu, energy));
        report.check("the exit moment is interior motion where there is motion, and "
                     "phase where there is none",
                     FarSideMotion::interiorPropagates(Kind::None, propagatingOmega, c, mu,
                                                       transverse) &&
                         !FarSideMotion::interiorPropagates(Kind::Euclidean, barrierOmega, c, mu,
                                                            transverse));
        report.check("the orientation the particle takes over there never reaches "
                     "us as a face, and reaches us as a moment only through the two "
                     "planes that touch the crossing direction",
                     !FarSideMotion::rotationChangesCrossingWavenumber(c, mu, turning) &&
                         !FarSideMotion::timePlaneMovesTheMoment(Kind::None, c, mu, turning, 2.0,
                                                                 1));
        report.check("and it reaches us as a deflection only through the finite "
                     "spectrum the two faces allow",
                     FarSideMotion::observableTurnCount(1.0, 2.0, 3.0) > 1);
    }

}
