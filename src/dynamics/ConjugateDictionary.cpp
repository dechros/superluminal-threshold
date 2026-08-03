#include "dynamics/ConjugateDictionary.h"

#include "core/Report.h"
#include "scan/CrossingBranches.h"
#include "scan/SlotDictionary.h"
#include "transform/InvolutionD.h"

#include <cmath>
#include <format>

namespace slm
{

    Matrix4 ConjugateDictionary::conjugateMap(const Matrix4 &crossing)
    {
        return crossing.inverse().transpose();
    }

    bool ConjugateDictionary::preservesInnerProduct(const Matrix4 &crossing, double tolerance)
    {
        return (crossing.transpose() * crossing).isEqual(Matrix4::identity(), tolerance);
    }

    bool ConjugateDictionary::conjugateMapEqualsCoordinateMap(const Matrix4 &crossing,
                                                              double tolerance)
    {
        return conjugateMap(crossing).isEqual(crossing, tolerance);
    }

    bool ConjugateDictionary::isSymmetric(const Matrix4 &crossing, double tolerance)
    {
        return crossing.transpose().isEqual(crossing, tolerance);
    }

    int ConjugateDictionary::conjugateSlot()
    {
        return 3;
    }

    double ConjugateDictionary::conjugateCoefficient(const Matrix4 &crossing)
    {
        const std::size_t row = static_cast<std::size_t>(conjugateSlot());
        const std::size_t column = static_cast<std::size_t>(SlotDictionary::timeSlot());
        return conjugateMap(crossing).at(row, column);
    }

    double ConjugateDictionary::conjugateVariable(const Matrix4 &crossing, const Vector4 &momentum)
    {
        return (conjugateMap(crossing) * momentum)[static_cast<std::size_t>(conjugateSlot())];
    }

    Vector4 ConjugateDictionary::shellMomentum(double frequency, double mu)
    {
        const double squared = frequency * frequency - mu;
        const double magnitude = squared > 0.0 ? std::sqrt(squared) : 0.0;
        const double polar = 0.4 * frequency;
        const double azimuth = 0.7 * frequency * frequency;
        return {frequency, magnitude * std::sin(polar) * std::cos(azimuth),
                magnitude * std::sin(polar) * std::sin(azimuth), magnitude * std::cos(polar)};
    }

    double ConjugateDictionary::frequencyDerivative(const Matrix4 &crossing)
    {
        return conjugateCoefficient(crossing);
    }

    double ConjugateDictionary::frequencyDerivativeByDifference(const Matrix4 &crossing,
                                                               double frequency, double mu,
                                                               double step)
    {
        const double above = conjugateVariable(crossing, shellMomentum(frequency + step, mu));
        const double below = conjugateVariable(crossing, shellMomentum(frequency - step, mu));
        return (above - below) / (2.0 * step);
    }

    double ConjugateDictionary::arrivalMoment(const Matrix4 &crossing, double phaseDelay,
                                             double distance)
    {
        return phaseDelay + distance * frequencyDerivative(crossing);
    }

    double ConjugateDictionary::additionResidual(const Matrix4 &crossing, double phaseDelay,
                                                double distance, int expectedSign)
    {
        return arrivalMoment(crossing, phaseDelay, distance) -
               (phaseDelay + expectedSign * distance);
    }

    double ConjugateDictionary::groupVelocityCoefficient(double wavenumber, double mu)
    {
        return wavenumber / std::sqrt(wavenumber * wavenumber + mu);
    }

    void ConjugateDictionarySection::run(Report &report) const
    {
        const auto eight = CrossingBranches::orientationPreserving();
        const Matrix4 D = InvolutionD::matrix();

        report.subsection("Coordinates and their conjugates need not share a dictionary");
        report.check("the conjugate map is the inverse transpose, which for a general "
                     "map differs from the map itself",
                     !ConjugateDictionary::conjugateMapEqualsCoordinateMap(
                         Matrix4::diagonal(2.0, 1.0, 1.0, 1.0)));

        report.subsection("For the admissible crossings they do");
        bool allOrthogonal = true;
        bool allSymmetric = true;
        bool allAgree = true;
        for (const auto &branch : eight)
        {
            allOrthogonal = allOrthogonal && ConjugateDictionary::preservesInnerProduct(branch.matrix);
            allSymmetric = allSymmetric && ConjugateDictionary::isSymmetric(branch.matrix);
            allAgree = allAgree &&
                       ConjugateDictionary::conjugateMapEqualsCoordinateMap(branch.matrix);
        }
        report.check("all eight preserve the Euclidean inner product, being signed "
                     "permutations, so the inverse transpose is the map itself",
                     allOrthogonal);
        report.check("all eight are their own transpose, being orthogonal involutions, so "
                     "the conjugate coefficient is the coordinate coefficient and not "
                     "merely its magnitude",
                     allSymmetric);
        report.check("so momenta transform by the same matrix as coordinates, entry by entry",
                     allAgree);

        report.subsection("The derivative of the conjugate variable in the frequency");
        bool everyDerivativeIsUnit = true;
        bool everyDerivativeMatchesTheSign = true;
        for (const auto &branch : eight)
        {
            const double derivative = ConjugateDictionary::frequencyDerivative(branch.matrix);
            everyDerivativeIsUnit =
                everyDerivativeIsUnit && std::abs(std::abs(derivative) - 1.0) <= kEps;
            everyDerivativeMatchesTheSign =
                everyDerivativeMatchesTheSign &&
                std::abs(derivative - static_cast<double>(branch.timeSign)) <= kEps;
        }
        report.check("its magnitude is exactly one for all eight, so the displacement "
                     "enters the arrival moment with no factor",
                     everyDerivativeIsUnit);
        report.check("and its sign is the branch's own time sign, so the direction the "
                     "coordinate dictionary assigns is the direction the phase produces",
                     everyDerivativeMatchesTheSign);
        report.checkNear(std::format("for the map used in this work the derivative is {:+.0f}",
                                     ConjugateDictionary::frequencyDerivative(D)),
                         ConjugateDictionary::frequencyDerivative(D) - 1.0);

        report.subsection("The same derivative by central difference along the mass shell");
        bool differenceAgrees = true;
        for (double mu : {0.0, 0.25, 1.0, 9.0})
        {
            for (double frequency : {4.0, 7.5, 20.0})
            {
                for (const auto &branch : eight)
                {
                    const double numeric = ConjugateDictionary::frequencyDerivativeByDifference(
                        branch.matrix, frequency, mu);
                    const double exact = ConjugateDictionary::frequencyDerivative(branch.matrix);
                    differenceAgrees = differenceAgrees && std::abs(numeric - exact) <= 1e-9;
                }
            }
        }
        report.check("over four masses, three frequencies and all eight crossings the "
                     "difference reproduces the exact value to nine digits",
                     differenceAgrees);
        report.check("the transverse components were given a nonlinear dependence on the "
                     "frequency, so their absence from the result is a computed fact and "
                     "not an omission",
                     std::abs(ConjugateDictionary::shellMomentum(4.0, 1.0)[1] -
                              ConjugateDictionary::shellMomentum(4.001, 1.0)[1]) > 1e-6);

        report.subsection("So the arrival moment is one derivative, not two calculations");
        bool sumIsDerived = true;
        for (const auto &branch : eight)
        {
            for (double delay : {0.0, 1.25, 2.565988})
            {
                for (double distance : {0.5, 3.0, 8.0})
                {
                    sumIsDerived = sumIsDerived &&
                                   std::abs(ConjugateDictionary::additionResidual(
                                       branch.matrix, delay, distance, branch.timeSign)) <= kEps;
                }
            }
        }
        report.check("the stationary-phase moment equals the phase delay plus the signed "
                     "displacement, over all eight crossings and nine parameter pairs, so "
                     "the addition is a consequence of the phase rather than an assumption "
                     "placed between two separate results",
                     sumIsDerived);

        report.subsection("Why the dispersion relation does not enter");
        report.check("the row producing the conjugate variable has a single nonzero entry, "
                     "so that variable is proportional to the frequency and blind to the "
                     "rest of the momentum",
                     SlotDictionary::contributingAxes(
                         ConjugateDictionary::conjugateMap(D).transpose()) == 1);
        for (double wavenumber : {1.0, 10.0, 1000.0})
        {
            const double viaGroup = ConjugateDictionary::groupVelocityCoefficient(wavenumber, 1.0);
            report.check(std::format("  a group velocity argument would give {:.9f} at k = {:g}, "
                                     "short of one",
                                     viaGroup, wavenumber),
                         viaGroup < 1.0);
        }
        report.check("so the unit coefficient is not the massless limit of a velocity but an "
                     "exact property of the map, and it holds at finite mass",
                     std::abs(ConjugateDictionary::frequencyDerivative(D)) == 1.0);
    }

}
