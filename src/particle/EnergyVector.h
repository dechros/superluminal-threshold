#pragma once

#include <array>

namespace slm
{

    /// Geometry of an energy vector in the three-time space, independent of
    /// any crossing or region it might be evaluated against.
    ///
    /// The three time axes carry an O(3) symmetry, so a rotation of the vector
    /// among them changes its direction but never its length. The mass shell
    /// ties the near-side frequency to that length alone, so the same rotation
    /// leaves the frequency untouched as well.
    class EnergyVector
    {
    public:
        using Three = std::array<double, 3>;

        /// Length of the vector.
        static double length(const Three &energy);

        /// Rotation of the vector by the given angle in one of the three time
        /// planes, indexed 0, 1, 2.
        static Three rotateInPlane(const Three &energy, int plane, double angle);

        /// Angle between two vectors, which is what a path of rotations sweeps
        /// out in total.
        static double sweptAngle(const Three &from, const Three &to);

        /// Frequency the mass shell assigns to the vector, from its length and
        /// the mass parameter.
        static double massShellFrequency(double c, double mu, const Three &energy);

        /// Whether any rotation of the vector changes that frequency, which it
        /// cannot since rotation preserves the length the frequency is built
        /// from.
        static bool rotationChangesFrequency(double c, double mu, const Three &energy);
    };

}
