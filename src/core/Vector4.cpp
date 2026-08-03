#include "core/Vector4.h"

#include "core/Matrix4.h"

#include <cmath>
#include <format>

namespace slm
{

    Vector4::Vector4(double x0, double x1, double x2, double x3)
        : components_{x0, x1, x2, x3}
    {
    }

    Vector4::Vector4(const std::array<double, 4> &components)
        : components_(components)
    {
    }

    double Vector4::operator[](std::size_t index) const
    {
        return components_[index];
    }

    double &Vector4::operator[](std::size_t index)
    {
        return components_[index];
    }

    double Vector4::contract(const Matrix4 &metric) const
    {
        double sum = 0.0;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                sum += components_[i] * metric.at(i, j) * components_[j];
            }
        }
        return sum;
    }

    double Vector4::norm() const
    {
        double sum = 0.0;
        for (std::size_t i = 0; i < 4; ++i)
        {
            sum += components_[i] * components_[i];
        }
        return std::sqrt(sum);
    }

    double Vector4::maxAbsDifference(const Vector4 &other) const
    {
        double worst = 0.0;
        for (std::size_t i = 0; i < 4; ++i)
        {
            worst = std::max(worst, std::abs(components_[i] - other.components_[i]));
        }
        return worst;
    }

    bool Vector4::isEqual(const Vector4 &other, double tolerance) const
    {
        return maxAbsDifference(other) <= tolerance;
    }

    std::string Vector4::toString() const
    {
        return std::format("({:g}, {:g}, {:g}, {:g})", components_[0], components_[1],
                           components_[2], components_[3]);
    }

    Vector4 operator+(const Vector4 &left, const Vector4 &right)
    {
        return {left[0] + right[0], left[1] + right[1], left[2] + right[2], left[3] + right[3]};
    }

    Vector4 operator-(const Vector4 &left, const Vector4 &right)
    {
        return {left[0] - right[0], left[1] - right[1], left[2] - right[2], left[3] - right[3]};
    }

    Vector4 operator*(double scale, const Vector4 &vector)
    {
        return {scale * vector[0], scale * vector[1], scale * vector[2], scale * vector[3]};
    }

    Vector4 operator*(const Vector4 &vector, double scale)
    {
        return scale * vector;
    }

}
