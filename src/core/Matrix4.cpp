#include "core/Matrix4.h"

#include "core/Vector4.h"

#include <cmath>
#include <format>
#include <stdexcept>

namespace slm
{

    Matrix4::Matrix4(const Rows &rows)
        : rows_(rows)
    {
    }

    Matrix4 Matrix4::zero()
    {
        return Matrix4{};
    }

    Matrix4 Matrix4::identity()
    {
        return diagonal(1.0, 1.0, 1.0, 1.0);
    }

    Matrix4 Matrix4::diagonal(double d0, double d1, double d2, double d3)
    {
        Matrix4 result;
        result.rows_[0][0] = d0;
        result.rows_[1][1] = d1;
        result.rows_[2][2] = d2;
        result.rows_[3][3] = d3;
        return result;
    }

    double Matrix4::at(std::size_t row, std::size_t column) const
    {
        return rows_[row][column];
    }

    double &Matrix4::at(std::size_t row, std::size_t column)
    {
        return rows_[row][column];
    }

    Matrix4 Matrix4::transpose() const
    {
        Matrix4 result;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                result.rows_[i][j] = rows_[j][i];
            }
        }
        return result;
    }

    double Matrix4::determinant() const
    {
        Rows work = rows_;
        double result = 1.0;
        for (std::size_t column = 0; column < 4; ++column)
        {
            std::size_t pivot = column;
            for (std::size_t row = column + 1; row < 4; ++row)
            {
                if (std::abs(work[row][column]) > std::abs(work[pivot][column]))
                {
                    pivot = row;
                }
            }
            if (std::abs(work[pivot][column]) < 1e-300)
            {
                return 0.0;
            }
            if (pivot != column)
            {
                std::swap(work[pivot], work[column]);
                result = -result;
            }
            result *= work[column][column];
            for (std::size_t row = column + 1; row < 4; ++row)
            {
                const double factor = work[row][column] / work[column][column];
                for (std::size_t k = column; k < 4; ++k)
                {
                    work[row][k] -= factor * work[column][k];
                }
            }
        }
        return result;
    }

    double Matrix4::trace() const
    {
        return rows_[0][0] + rows_[1][1] + rows_[2][2] + rows_[3][3];
    }

    Matrix4 Matrix4::inverse() const
    {
        std::array<std::array<double, 8>, 4> work{};
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                work[i][j] = rows_[i][j];
            }
            work[i][4 + i] = 1.0;
        }

        for (std::size_t column = 0; column < 4; ++column)
        {
            std::size_t pivot = column;
            for (std::size_t row = column + 1; row < 4; ++row)
            {
                if (std::abs(work[row][column]) > std::abs(work[pivot][column]))
                {
                    pivot = row;
                }
            }
            if (std::abs(work[pivot][column]) < kEps)
            {
                throw std::domain_error("Matrix4::inverse: matrix is singular");
            }
            std::swap(work[pivot], work[column]);

            const double scale = work[column][column];
            for (std::size_t k = 0; k < 8; ++k)
            {
                work[column][k] /= scale;
            }
            for (std::size_t row = 0; row < 4; ++row)
            {
                if (row == column)
                {
                    continue;
                }
                const double factor = work[row][column];
                for (std::size_t k = 0; k < 8; ++k)
                {
                    work[row][k] -= factor * work[column][k];
                }
            }
        }

        Matrix4 result;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                result.rows_[i][j] = work[i][4 + j];
            }
        }
        return result;
    }

    Matrix4 Matrix4::congruence(const Matrix4 &metric) const
    {
        return transpose() * metric * (*this);
    }

    bool Matrix4::flipsMetric(const Matrix4 &from, const Matrix4 &to, double tolerance) const
    {
        return (congruence(to) + from).isZero(tolerance);
    }

    Matrix4 Matrix4::power(unsigned exponent) const
    {
        Matrix4 result = identity();
        for (unsigned n = 0; n < exponent; ++n)
        {
            result = result * (*this);
        }
        return result;
    }

    bool Matrix4::isIdentity(double tolerance) const
    {
        return isEqual(identity(), tolerance);
    }

    bool Matrix4::isInvolution(double tolerance) const
    {
        return ((*this) * (*this)).isEqual(identity(), tolerance);
    }

    std::size_t Matrix4::order(std::size_t limit, double tolerance) const
    {
        Matrix4 power = *this;
        for (std::size_t n = 1; n <= limit; ++n)
        {
            if (power.isEqual(identity(), tolerance))
            {
                return n;
            }
            power = power * (*this);
        }
        return 0;
    }

    double Matrix4::maxAbsDifference(const Matrix4 &other) const
    {
        double worst = 0.0;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                worst = std::max(worst, std::abs(rows_[i][j] - other.rows_[i][j]));
            }
        }
        return worst;
    }

    bool Matrix4::isEqual(const Matrix4 &other, double tolerance) const
    {
        return maxAbsDifference(other) <= tolerance;
    }

    bool Matrix4::isZero(double tolerance) const
    {
        return maxAbsDifference(zero()) <= tolerance;
    }

    std::string Matrix4::toString() const
    {
        std::string text = "[";
        for (std::size_t i = 0; i < 4; ++i)
        {
            text += "(";
            for (std::size_t j = 0; j < 4; ++j)
            {
                text += std::format("{:g}", rows_[i][j]);
                if (j + 1 < 4)
                {
                    text += ", ";
                }
            }
            text += i + 1 < 4 ? "), " : ")";
        }
        text += "]";
        return text;
    }

    Matrix4 metricRegionI()
    {
        return Matrix4::diagonal(1.0, -1.0, -1.0, -1.0);
    }

    Matrix4 metricRegionII()
    {
        return Matrix4::diagonal(1.0, 1.0, 1.0, -1.0);
    }

    Matrix4 operator+(const Matrix4 &left, const Matrix4 &right)
    {
        Matrix4 result;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                result.at(i, j) = left.at(i, j) + right.at(i, j);
            }
        }
        return result;
    }

    Matrix4 operator-(const Matrix4 &left, const Matrix4 &right)
    {
        Matrix4 result;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                result.at(i, j) = left.at(i, j) - right.at(i, j);
            }
        }
        return result;
    }

    Matrix4 operator-(const Matrix4 &matrix)
    {
        return -1.0 * matrix;
    }

    Matrix4 operator*(const Matrix4 &left, const Matrix4 &right)
    {
        Matrix4 result;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                double sum = 0.0;
                for (std::size_t k = 0; k < 4; ++k)
                {
                    sum += left.at(i, k) * right.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }
        return result;
    }

    Matrix4 operator*(double scale, const Matrix4 &matrix)
    {
        Matrix4 result;
        for (std::size_t i = 0; i < 4; ++i)
        {
            for (std::size_t j = 0; j < 4; ++j)
            {
                result.at(i, j) = scale * matrix.at(i, j);
            }
        }
        return result;
    }

    Matrix4 operator*(const Matrix4 &matrix, double scale)
    {
        return scale * matrix;
    }

    Vector4 operator*(const Matrix4 &matrix, const Vector4 &vector)
    {
        Vector4 result;
        for (std::size_t i = 0; i < 4; ++i)
        {
            double sum = 0.0;
            for (std::size_t j = 0; j < 4; ++j)
            {
                sum += matrix.at(i, j) * vector[j];
            }
            result[i] = sum;
        }
        return result;
    }

}
