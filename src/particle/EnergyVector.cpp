#include "particle/EnergyVector.h"

#include <cmath>

namespace slm
{

    double EnergyVector::length(const Three &energy)
    {
        return std::sqrt(energy[0] * energy[0] + energy[1] * energy[1] + energy[2] * energy[2]);
    }

    EnergyVector::Three EnergyVector::rotateInPlane(const Three &energy, int plane, double angle)
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

    double EnergyVector::sweptAngle(const Three &from, const Three &to)
    {
        const double lengths = length(from) * length(to);
        if (lengths <= 0.0)
        {
            return 0.0;
        }
        const double dot = from[0] * to[0] + from[1] * to[1] + from[2] * to[2];
        const double cosine = std::fmin(1.0, std::fmax(-1.0, dot / lengths));
        return std::acos(cosine);
    }

    double EnergyVector::massShellFrequency(double c, double mu, const Three &energy)
    {
        const double magnitude = length(energy);
        return c * std::sqrt(magnitude * magnitude + mu);
    }

    bool EnergyVector::rotationChangesFrequency(double c, double mu, const Three &energy)
    {
        const double reference = massShellFrequency(c, mu, energy);
        for (int plane = 0; plane < 3; ++plane)
        {
            for (int step = 1; step <= 24; ++step)
            {
                const double angle = step * (2.0 * std::acos(-1.0) / 24.0);
                const Three turned = rotateInPlane(energy, plane, angle);
                if (std::abs(massShellFrequency(c, mu, turned) - reference) > 1e-9)
                {
                    return true;
                }
            }
        }
        return false;
    }

}
