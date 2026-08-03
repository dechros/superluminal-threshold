#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace slm
{

    class Matrix4;

    /// A four-component vector, with no signature attached to it.
    ///
    /// The metric is deliberately not a member. This project works with two
    /// signatures at once and passes between them, so a vector that carried its
    /// own metric would have to be converted at every crossing, and the
    /// conversion would be the place where a mistake hides. Here a vector is
    /// four numbers, and every question that depends on a signature takes the
    /// metric as an argument. @ref contract is the only such question, and it
    /// answers all of them.
    class Vector4
    {
    public:
        Vector4() = default;

        /// Builds from components, in the order the metric is written in.
        Vector4(double x0, double x1, double x2, double x3);

        /// Builds from an array of components.
        explicit Vector4(const std::array<double, 4> &components);

        /// Component access, unchecked.
        double operator[](std::size_t index) const;

        /// Mutable component access, unchecked.
        double &operator[](std::size_t index);

        /// The scalar @f$ v^T g v @f$ for the given metric.
        ///
        /// Its sign classifies the vector against that metric, which is what
        /// makes it the single question worth asking: with a signature whose
        /// timelike directions are the negative ones, a negative value is
        /// timelike, a positive value spacelike, and zero null. Which sign
        /// means what therefore depends on the metric passed, not on the
        /// vector, and that is the intended asymmetry.
        double contract(const Matrix4 &metric) const;

        /// The Euclidean length of the components, with no metric involved.
        ///
        /// Not a physical length, and not to be confused with @ref contract.
        /// Its only use is as a distance in component space: it vanishes if and
        /// only if every component does, which @ref contract does not, since a
        /// null vector has zero square without being the zero vector.
        double norm() const;

        /// The largest absolute component-wise difference from @p other.
        ///
        /// Used to state that two vectors agree: the claim is about the worst
        /// component, not about a norm, because a norm can hide a single bad
        /// component behind three good ones.
        double maxAbsDifference(const Vector4 &other) const;

        /// True when no component differs from @p other by more than
        /// @p tolerance.
        bool isEqual(const Vector4 &other, double tolerance) const;

        /// Components, formatted for a report line.
        std::string toString() const;

    private:
        std::array<double, 4> components_{};
    };

    Vector4 operator+(const Vector4 &left, const Vector4 &right);
    Vector4 operator-(const Vector4 &left, const Vector4 &right);
    Vector4 operator*(double scale, const Vector4 &vector);
    Vector4 operator*(const Vector4 &vector, double scale);

}
