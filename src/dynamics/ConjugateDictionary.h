#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"
#include "core/Vector4.h"

namespace slm
{

    /// The dictionary induced on the conjugate variables, and the addition it
    /// makes derivable.
    ///
    /// A linear change of coordinates @f$ x' = M x @f$ acts on coordinates and
    /// on their conjugate momenta by two different matrices: the invariance of
    /// the phase @f$ p_\mu x^\mu @f$ forces @f$ p' = M^{-\mathsf{T}} p @f$. A
    /// statement proved for a coordinate dictionary therefore does not transfer
    /// to the conjugate one for free. This class computes the conjugate map and
    /// establishes when the two coincide.
    ///
    /// THE TWO MAPS COINCIDE HERE. A signed permutation matrix is orthogonal, so
    /// @f$ M^{-\mathsf{T}} = M @f$, and momenta transform by the very same
    /// matrix as coordinates. If in addition the map is an involution, then
    /// @f$ M = M^{-1} = M^{\mathsf{T}} @f$, so it is symmetric, and the entry
    /// governing the conjugate variable is the transpose of the entry governing
    /// the coordinate. The two coefficients are then the same number, not merely
    /// the same magnitude.
    ///
    /// WHY THIS YIELDS AN ADDITION. Place the displacement inside the phase
    /// rather than outside it. A single amplitude carrying a scattering phase
    /// @f$ \varphi(\omega) @f$ and a displacement @f$ s @f$ along the far side's
    /// distinguished axis has total phase @f$ \varphi(\omega) + \kappa(\omega) s
    /// @f$, and stationary phase locates the emerging packet at
    /// @f$ t = \varphi'(\omega) + s\, \mathrm{d}\kappa/\mathrm{d}\omega @f$. The
    /// sum is then read off one calculation instead of being assumed between
    /// two, and the weight on the second term is a derivative that can be
    /// computed rather than a convention.
    ///
    /// WHAT THE DERIVATIVE DOES NOT DEPEND ON. Because the relevant row of the
    /// map has a single nonzero entry, the conjugate variable is proportional to
    /// the frequency alone and is blind to the remaining components of the
    /// momentum. The derivative is therefore independent of the dispersion
    /// relation, unlike an argument routed through a group velocity, which
    /// approaches the same coefficient only asymptotically and never attains it
    /// at finite mass.
    class ConjugateDictionary
    {
    public:
        /// Matrix by which conjugate momenta transform, @f$ M^{-\mathsf{T}} @f$.
        static Matrix4 conjugateMap(const Matrix4 &crossing);

        /// True when the map preserves the Euclidean inner product, which is
        /// what makes the conjugate map equal to the map itself.
        static bool preservesInnerProduct(const Matrix4 &crossing, double tolerance = kEps);

        /// True when the conjugate map and the coordinate map are the same
        /// matrix entry by entry.
        static bool conjugateMapEqualsCoordinateMap(const Matrix4 &crossing,
                                                    double tolerance = kEps);

        /// True when the map is its own transpose, which is what identifies the
        /// conjugate coefficient with the coordinate coefficient rather than
        /// only with its magnitude.
        static bool isSymmetric(const Matrix4 &crossing, double tolerance = kEps);

        /// Index of the conjugate variable along the far side's distinguished
        /// axis.
        static int conjugateSlot();

        /// Coefficient with which the frequency enters that conjugate variable.
        static double conjugateCoefficient(const Matrix4 &crossing);

        /// Conjugate variable obtained from a region I momentum covector.
        static double conjugateVariable(const Matrix4 &crossing, const Vector4 &momentum);

        /// A momentum covector on the region I mass shell at the given
        /// frequency, with transverse components deliberately given a nonlinear
        /// dependence on the frequency so that any leakage from the far side into the
        /// derivative would show up.
        static Vector4 shellMomentum(double frequency, double mu);

        /// Derivative of the conjugate variable with respect to the frequency,
        /// obtained from the map itself.
        static double frequencyDerivative(const Matrix4 &crossing);

        /// The same derivative obtained by a central difference along the mass
        /// shell, which is an independent route to the same number.
        static double frequencyDerivativeByDifference(const Matrix4 &crossing, double frequency,
                                                      double mu, double step = 1e-5);

        /// Moment at which the packet emerges, read from the stationary phase of
        /// a single amplitude carrying both the scattering phase delay and the
        /// far-side displacement.
        static double arrivalMoment(const Matrix4 &crossing, double phaseDelay, double distance);

        /// Difference between that moment and the plain sum of a phase delay and
        /// a displacement. Zero exactly when the derivative has unit magnitude
        /// and the expected sign.
        static double additionResidual(const Matrix4 &crossing, double phaseDelay, double distance,
                                       int expectedSign);

        /// Coefficient a group velocity argument would give at the stated
        /// wavenumber, retained for comparison because it is the route that does
        /// not reach unity at finite mass.
        static double groupVelocityCoefficient(double wavenumber, double mu);
    };

    /// Section deriving the arrival moment from a single amplitude instead of
    /// summing two separately computed contributions.
    class ConjugateDictionarySection : public Section
    {
    public:
        std::string title() const override
        {
            return "The delay and the displacement add, because one phase carries both";
        }
        void run(Report &report) const override;
    };

}
