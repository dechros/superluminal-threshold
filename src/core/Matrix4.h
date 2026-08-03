#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace slm
{

    class Vector4;

    /// Shared tolerance for comparisons that ought to be exact.
    ///
    /// It is used where the quantities compared are built from permutations,
    /// signs and small integers, so the only error present is the rounding of a
    /// few dozen operations. It is deliberately far tighter than the tolerance
    /// appropriate to a converged numerical result: a determinant that is meant
    /// to be exactly one and comes back as 0.999 is a bug, not noise, and this
    /// constant is what refuses to absorb it.
    inline constexpr double kEps = 1e-12;

    /// A four by four real matrix, used both as a metric and as a map.
    ///
    /// One type serves both roles on purpose. The operations that matter here
    /// mix them: @ref congruence asks what a map does to a metric, and it is
    /// the operation the whole crossing argument turns on, since a transform
    /// carries one signature to another exactly when the congruence of the
    /// first metric is the second.
    class Matrix4
    {
    public:
        using Rows = std::array<std::array<double, 4>, 4>;

        Matrix4() = default;

        /// Builds from rows, outermost index first.
        explicit Matrix4(const Rows &rows);

        /// All entries zero.
        static Matrix4 zero();

        /// The identity.
        static Matrix4 identity();

        /// A diagonal matrix, which is how every metric in this project is
        /// written.
        static Matrix4 diagonal(double d0, double d1, double d2, double d3);

        /// Entry access, unchecked. Row @p row, column @p column.
        double at(std::size_t row, std::size_t column) const;

        /// Mutable entry access, unchecked.
        double &at(std::size_t row, std::size_t column);

        /// The transpose.
        Matrix4 transpose() const;

        /// The determinant.
        double determinant() const;

        /// The trace.
        double trace() const;

        /// The inverse.
        ///
        /// Throws @c std::domain_error when the matrix is singular. Throwing
        /// rather than returning a sentinel is deliberate and is relied upon: a
        /// degenerate metric is a physical situation here, not an error, and
        /// the statement being made about it is precisely that no inverse
        /// exists. A sentinel return would let the caller carry on and produce
        /// numbers for a field equation that is undefined.
        ///
        /// Singular is judged against @ref kEps rather than against the
        /// smallest representable number. A metric that degenerates at a
        /// turning point reaches it through a cosine, so at the point itself
        /// the entry is a rounding residue of order @f$ 10^{-17} @f$ and not a
        /// zero. Inverting that would return entries of order @f$ 10^{17} @f$
        /// and every check downstream would pass on nonsense.
        Matrix4 inverse() const;

        /// The congruence @f$ M^T g M @f$ of @p metric by this matrix.
        ///
        /// This is how a metric transforms under a change of coordinates, and
        /// it is the test for whether a map preserves a signature: the map
        /// preserves @p metric exactly when the result equals @p metric, and
        /// carries it to another signature when the result is that one.
        Matrix4 congruence(const Matrix4 &metric) const;

        /// True when @f$ M^T g' M = -g @f$, for @p from as @f$ g @f$ and @p to
        /// as @f$ g' @f$.
        ///
        /// This is the signature-reversing relation, and the minus sign is the
        /// content of it. A map that carried one metric to the other with a
        /// plus sign would be an isometry between two different signatures,
        /// which does not exist; what can exist is a map that carries one to
        /// the negative of the other, and negating a metric of signature
        /// @f$ (1,3) @f$ gives @f$ (3,1) @f$. Every candidate transform in this
        /// project is tested against this relation rather than against
        /// preservation.
        bool flipsMetric(const Matrix4 &from, const Matrix4 &to,
                         double tolerance = kEps) const;

        /// This matrix raised to a non-negative integer power. Power zero is
        /// the identity.
        Matrix4 power(unsigned exponent) const;

        /// True when this matrix is the identity to the given tolerance.
        bool isIdentity(double tolerance = kEps) const;

        /// True when applying this matrix twice gives the identity, to the
        /// given tolerance. An involution generates a group of order two.
        bool isInvolution(double tolerance = kEps) const;

        /// The smallest positive power at which this matrix becomes the
        /// identity, or zero when no power up to @p limit does.
        ///
        /// Returning zero for "no finite order found" rather than something
        /// like -1 keeps the failure out of the arithmetic: a caller comparing
        /// against an expected order can never accidentally match.
        std::size_t order(std::size_t limit = 64, double tolerance = 1e-12) const;

        /// The largest absolute entry-wise difference from @p other.
        double maxAbsDifference(const Matrix4 &other) const;

        /// True when no entry differs from @p other by more than @p tolerance.
        bool isEqual(const Matrix4 &other, double tolerance = 1e-12) const;

        /// True when no entry exceeds @p tolerance in absolute value.
        bool isZero(double tolerance = 1e-12) const;

        /// Entries, formatted for a report line.
        std::string toString() const;

    private:
        Rows rows_{};
    };

    /// The metric of region I, signature @f$ (1,3) @f$, mostly minus.
    ///
    /// Mostly minus rather than mostly plus so that a timelike vector has
    /// positive square. Every predicate in this project reads "timelike" as
    /// @ref Vector4::contract greater than zero, and that reading has to hold
    /// on both sides of the threshold, where the count of positive directions
    /// is what changes.
    Matrix4 metricRegionI();

    /// The metric of region II, signature @f$ (3,1) @f$: three directions of
    /// positive square and one of negative.
    ///
    /// The two metrics differ by @f$ \mathrm{diag}(0,2,2,0) @f$, a sum of
    /// squares, so no vector loses positive square on crossing. That is the
    /// arithmetic behind the causal statement that the crossing is permitted
    /// by geometry whatever the field does.
    Matrix4 metricRegionII();

    Matrix4 operator+(const Matrix4 &left, const Matrix4 &right);
    Matrix4 operator-(const Matrix4 &left, const Matrix4 &right);
    Matrix4 operator-(const Matrix4 &matrix);
    Matrix4 operator*(const Matrix4 &left, const Matrix4 &right);
    Matrix4 operator*(double scale, const Matrix4 &matrix);
    Matrix4 operator*(const Matrix4 &matrix, double scale);
    Vector4 operator*(const Matrix4 &matrix, const Vector4 &vector);

}
