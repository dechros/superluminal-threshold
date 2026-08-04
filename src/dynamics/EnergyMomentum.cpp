#include "dynamics/EnergyMomentum.h"

#include "core/Matrix4.h"
#include "core/Report.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{
    Vector4 EnergyMomentum::fourMomentum(double c, double energy, double px, double py, double pz)
    {
        return Vector4(energy / c, px, py, pz);
    }

    Vector4 EnergyMomentum::transformed(double, const Vector4 &p)
    {
        return SignatureInvolution::matrix() * p;
    }

    double EnergyMomentum::invariant(const Vector4 &p)
    {
        return p.contract(metricRegionI());
    }

    double EnergyMomentum::shellEnergy(double c, double mass, double px, double py, double pz)
    {
        const double pSquared = px * px + py * py + pz * pz;
        return std::sqrt(pSquared * c * c + mass * mass * std::pow(c, 4));
    }

    void EnergyMomentum::run(Report &report) const
    {
        const double c = 1.0;
        const Matrix4 eta = metricRegionI();
        const Matrix4 etaPrime = metricRegionII();

        const Vector4 p = fourMomentum(c, 5.0, 1.0, 2.0, 3.0);
        const Vector4 pPrime = transformed(c, p);

        report.subsection("Invariant");
        const double before = p.contract(eta);
        const double after = pPrime.contract(etaPrime);
        report.checkNear("far side = -near side", after + before);

        report.subsection("Conservation in a general 2->2 collision");
        const Vector4 p1 = fourMomentum(c, 7.0, 1.0, -2.0, 0.5);
        const Vector4 p2 = fourMomentum(c, 3.0, -0.5, 1.5, 2.0);
        const Vector4 p4 = fourMomentum(c, 4.0, 0.25, -1.0, 1.25);
        const Vector4 p3 = p1 + p2 - p4;

        const Vector4 incoming = p1 + p2;
        const Vector4 outgoing = p3 + p4;
        report.checkNear("conservation holds on the near side",
                         incoming.maxAbsDifference(outgoing));

        const Vector4 incomingPrime = transformed(c, incoming);
        const Vector4 outgoingPrime = transformed(c, outgoing);
        report.checkNear("conservation holds automatically on the far side",
                         incomingPrime.maxAbsDifference(outgoingPrime));

        report.subsection("Mass shell");
        const double mass = 2.0;
        const double energy = shellEnergy(c, mass, 1.0, 0.0, 0.0);
        const Vector4 shell = fourMomentum(c, energy, 1.0, 0.0, 0.0);
        report.checkNear("the near side: p.p = m^2c^2",
                         shell.contract(eta) - mass * mass * c * c);
        const Vector4 shellPrime = transformed(c, shell);
        report.checkNear("far side: p'.p' = -m^2c^2, the sign flips",
                         shellPrime.contract(etaPrime) + mass * mass * c * c);

        report.subsection("Infinite speed limit: E -> 0, p -> mc");
        double previousEnergy = mass * c * c;
        double previousMomentum = 0.0;
        for (double v : {0.9, 0.99, 0.9999})
        {
            const double gamma = 1.0 / std::sqrt(1.0 - v * v / (c * c));
            const double energy = mass * c * c / gamma;
            const double momentum = mass * v;
            report.check(std::format("v = {:g}c : E decreasing, p increasing towards mc", v),
                         energy < previousEnergy && momentum > previousMomentum &&
                             momentum < mass * c);
            previousEnergy = energy;
            previousMomentum = momentum;
        }

        report.subsection("Mixed collision: body at rest plus an infinitely fast tachyon");
        const double M = 3.0;
        const Vector4 restBody = fourMomentum(c, mass * c * c, 0.0, 0.0, 0.0);
        const Vector4 tachyon = fourMomentum(c, 0.0, M * c, 0.0, 0.0);
        const Vector4 totalBefore = restBody + tachyon;

        const double MPrime = 1.0;
        const Vector4 tachyonAfter = fourMomentum(c, 0.0, MPrime * c, 0.0, 0.0);
        const Vector4 bodyAfter = totalBefore - tachyonAfter;

        report.checkNear("the energy of the body is unchanged",
                         bodyAfter[0] * c - restBody[0] * c);
        report.checkNear("the body gains (M - M')c of momentum",
                         bodyAfter[1] - (M - MPrime) * c);

        report.subsection("Energy positivity under D");
        const double magnitude = std::sqrt(pPrime[0] * pPrime[0] + pPrime[1] * pPrime[1] +
                                           pPrime[2] * pPrime[2]);
        report.check("|E'| >= 0 always holds", magnitude >= 0.0);
    }
}
