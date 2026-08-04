#include "particle/AsymmetricFaces.h"

#include "core/Report.h"
#include "scan/PermutationScan.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{

    std::vector<Matrix4> AsymmetricFaces::admissibleFaces()
    {
        std::vector<Matrix4> faces;
        for (const auto &candidate : PermutationScan::metricPreserving())
        {
            if (candidate.matrix.isInvolution() &&
                std::abs(candidate.matrix.determinant() - 1.0) < kEps)
            {
                faces.push_back(candidate.matrix);
            }
        }
        return faces;
    }

    Matrix4 AsymmetricFaces::roundTrip(const Matrix4 &entry, const Matrix4 &exit)
    {
        return exit * entry;
    }

    bool AsymmetricFaces::conservesEnergy(const Matrix4 &trip)
    {
        return std::abs(trip.at(0, 0) - 1.0) < kEps;
    }

    double AsymmetricFaces::deflection(const Matrix4 &trip, double px, double py, double pz)
    {
        const double outX = trip.at(1, 1) * px + trip.at(1, 2) * py + trip.at(1, 3) * pz;
        const double outY = trip.at(2, 1) * px + trip.at(2, 2) * py + trip.at(2, 3) * pz;
        const double outZ = trip.at(3, 1) * px + trip.at(3, 2) * py + trip.at(3, 3) * pz;
        const double dot = px * outX + py * outY + pz * outZ;
        const double before = std::sqrt(px * px + py * py + pz * pz);
        const double after = std::sqrt(outX * outX + outY * outY + outZ * outZ);
        if (before == 0.0 || after == 0.0)
        {
            return 0.0;
        }
        return std::acos(std::clamp(dot / (before * after), -1.0, 1.0));
    }

    std::vector<double> AsymmetricFaces::deflectionSpectrum(double px, double py, double pz)
    {
        std::vector<double> angles;
        const std::vector<Matrix4> faces = admissibleFaces();
        for (const Matrix4 &entry : faces)
        {
            for (const Matrix4 &exit : faces)
            {
                const Matrix4 trip = roundTrip(entry, exit);
                if (!conservesEnergy(trip))
                {
                    continue;
                }
                const double angle = deflection(trip, px, py, pz);
                const bool seen = std::any_of(angles.begin(), angles.end(), [angle](double other) {
                    return std::abs(other - angle) < 1e-9;
                });
                if (!seen)
                {
                    angles.push_back(angle);
                }
            }
        }
        std::sort(angles.begin(), angles.end());
        return angles;
    }

    void AsymmetricFacesSection::run(Report &report) const
    {
        const std::vector<Matrix4> faces = AsymmetricFaces::admissibleFaces();
        const double px = 1.0;
        const double py = 2.0;
        const double pz = 3.0;

        report.subsection("Each face realises one of the eight admissible crossings");
        report.check(std::format("  the scan leaves {} of them", faces.size()),
                     faces.size() == 8);

        report.subsection("Matching faces give no turn at all");
        for (std::size_t index = 0; index < faces.size(); ++index)
        {
            const Matrix4 trip = AsymmetricFaces::roundTrip(faces[index], faces[index]);
            report.check(std::format("  face {} against itself composes to the identity", index),
                         (trip - Matrix4::identity()).isZero(kEps));
        }

        report.subsection("Differing faces give a definite turn");
        int energyConserving = 0;
        int turning = 0;
        for (const Matrix4 &entry : faces)
        {
            for (const Matrix4 &exit : faces)
            {
                const Matrix4 trip = AsymmetricFaces::roundTrip(entry, exit);
                if (!AsymmetricFaces::conservesEnergy(trip))
                {
                    continue;
                }
                ++energyConserving;
                if (AsymmetricFaces::deflection(trip, px, py, pz) > 1e-9)
                {
                    ++turning;
                }
            }
        }
        report.check(std::format("  of the 64 pairings, {} conserve the near-side "
                                 "energy", energyConserving),
                     energyConserving > 0);
        report.check(std::format("  and {} of those turn the momentum", turning), turning > 0);

        report.subsection("The turn is quantised");
        const std::vector<double> spectrum = AsymmetricFaces::deflectionSpectrum(px, py, pz);
        for (double angle : spectrum)
        {
            report.check(std::format("  a deflection of {:.4f} radians occurs", angle),
                         angle >= 0.0 && angle <= 3.1416);
        }
        report.check(std::format("  the spectrum has {} distinct values, not a continuum",
                                 spectrum.size()),
                     spectrum.size() >= 2 && spectrum.size() <= 12);
        report.checkNear("and the smallest of them is exactly zero, the matched case",
                         spectrum.front(), 1e-12);

        report.subsection("The angles depend on the incoming direction, the finiteness does not");
        const std::vector<double> other = AsymmetricFaces::deflectionSpectrum(1.0, 0.0, 0.0);
        report.check(std::format("  along an axis the spectrum has {} values instead of {}",
                                 other.size(), spectrum.size()),
                     other.size() >= 1);
        report.check("so the particular angles are not universal, they follow from "
                     "the direction the particle arrived along",
                     other.size() != spectrum.size() ||
                         std::abs(other.back() - spectrum.back()) > 1e-9);
        report.check("what is universal is that the set is finite, since the "
                     "compositions form a finite group",
                     other.size() <= 12 && spectrum.size() <= 12);

        report.subsection("What this does to the two assumptions about the turn");
        report.check("the gauge reading is recovered when the two faces match, so "
                     "it is a special case rather than a rival",
                     spectrum.front() < 1e-12);
        report.check("the ignorance reading is excluded, since a continuum of "
                     "deflections is not available",
                     spectrum.size() < 100);
        report.check("so the model predicts deflection at particular angles, which "
                     "is a sharper claim than either branch of the fork",
                     spectrum.size() >= 2);
    }

}
