#include "transform/SpinRepresentation.h"

#include "core/Report.h"

#include <algorithm>
#include <array>
#include <complex>
#include <cstddef>
#include <format>
#include <string>

namespace slm
{
    namespace
    {
        using Cx = std::complex<double>;
        using CMat = std::array<std::array<Cx, 4>, 4>;

        CMat zeroMatrix()
        {
            CMat result{};
            for (auto &row : result)
            {
                row.fill(Cx(0.0, 0.0));
            }
            return result;
        }

        CMat identityMatrix()
        {
            CMat result = zeroMatrix();
            for (std::size_t index = 0; index < 4; ++index)
            {
                result[index][index] = Cx(1.0, 0.0);
            }
            return result;
        }

        CMat matrixMultiply(const CMat &left, const CMat &right)
        {
            CMat result = zeroMatrix();
            for (std::size_t row = 0; row < 4; ++row)
            {
                for (std::size_t col = 0; col < 4; ++col)
                {
                    Cx sum(0.0, 0.0);
                    for (std::size_t inner = 0; inner < 4; ++inner)
                    {
                        sum += left[row][inner] * right[inner][col];
                    }
                    result[row][col] = sum;
                }
            }
            return result;
        }

        CMat matrixAdd(const CMat &left, const CMat &right)
        {
            CMat result = zeroMatrix();
            for (std::size_t row = 0; row < 4; ++row)
            {
                for (std::size_t col = 0; col < 4; ++col)
                {
                    result[row][col] = left[row][col] + right[row][col];
                }
            }
            return result;
        }

        CMat matrixScale(Cx factor, const CMat &matrix)
        {
            CMat result = zeroMatrix();
            for (std::size_t row = 0; row < 4; ++row)
            {
                for (std::size_t col = 0; col < 4; ++col)
                {
                    result[row][col] = factor * matrix[row][col];
                }
            }
            return result;
        }

        CMat matrixConjugate(const CMat &matrix)
        {
            CMat result = zeroMatrix();
            for (std::size_t row = 0; row < 4; ++row)
            {
                for (std::size_t col = 0; col < 4; ++col)
                {
                    result[row][col] = std::conj(matrix[row][col]);
                }
            }
            return result;
        }

        double maxAbsDifference(const CMat &left, const CMat &right)
        {
            double worst = 0.0;
            for (std::size_t row = 0; row < 4; ++row)
            {
                for (std::size_t col = 0; col < 4; ++col)
                {
                    worst = std::max(worst, std::abs(left[row][col] - right[row][col]));
                }
            }
            return worst;
        }

        bool matricesClose(const CMat &left, const CMat &right, double tolerance = 1e-9)
        {
            return maxAbsDifference(left, right) <= tolerance;
        }

        std::array<CMat, 4> baseGammaSet()
        {
            const Cx im(0.0, 1.0);
            std::array<CMat, 4> gamma{zeroMatrix(), zeroMatrix(), zeroMatrix(), zeroMatrix()};

            gamma[0][0][0] = Cx(1.0, 0.0);
            gamma[0][1][1] = Cx(1.0, 0.0);
            gamma[0][2][2] = Cx(-1.0, 0.0);
            gamma[0][3][3] = Cx(-1.0, 0.0);

            gamma[1][0][3] = Cx(1.0, 0.0);
            gamma[1][1][2] = Cx(1.0, 0.0);
            gamma[1][2][1] = Cx(-1.0, 0.0);
            gamma[1][3][0] = Cx(-1.0, 0.0);

            gamma[2][0][3] = -im;
            gamma[2][1][2] = im;
            gamma[2][2][1] = im;
            gamma[2][3][0] = -im;

            gamma[3][0][2] = Cx(1.0, 0.0);
            gamma[3][1][3] = Cx(-1.0, 0.0);
            gamma[3][2][0] = Cx(-1.0, 0.0);
            gamma[3][3][1] = Cx(1.0, 0.0);

            return gamma;
        }

        std::array<CMat, 4> applyFlips(const std::array<CMat, 4> &base, const std::array<bool, 4> &flip)
        {
            const Cx im(0.0, 1.0);
            std::array<CMat, 4> result = base;
            for (std::size_t index = 0; index < 4; ++index)
            {
                if (flip[index])
                {
                    result[index] = matrixScale(im, base[index]);
                }
            }
            return result;
        }

        std::array<double, 4> etaFromFlips(const std::array<bool, 4> &flip)
        {
            std::array<double, 4> eta{1.0, -1.0, -1.0, -1.0};
            for (std::size_t index = 0; index < 4; ++index)
            {
                if (flip[index])
                {
                    eta[index] = -eta[index];
                }
            }
            return eta;
        }

        std::array<CMat, 16> cliffordBasis(const std::array<CMat, 4> &gamma)
        {
            std::array<CMat, 16> basis{};
            basis[0] = identityMatrix();
            for (std::size_t index = 0; index < 4; ++index)
            {
                basis[1 + index] = gamma[index];
            }

            basis[5] = matrixMultiply(gamma[0], gamma[1]);
            basis[6] = matrixMultiply(gamma[0], gamma[2]);
            basis[7] = matrixMultiply(gamma[0], gamma[3]);
            basis[8] = matrixMultiply(gamma[1], gamma[2]);
            basis[9] = matrixMultiply(gamma[1], gamma[3]);
            basis[10] = matrixMultiply(gamma[2], gamma[3]);

            basis[11] = matrixMultiply(basis[5], gamma[2]);
            basis[12] = matrixMultiply(basis[5], gamma[3]);
            basis[13] = matrixMultiply(basis[6], gamma[3]);
            basis[14] = matrixMultiply(basis[8], gamma[3]);

            basis[15] = matrixMultiply(basis[11], gamma[3]);

            return basis;
        }

        struct RealityOutcome
        {
            bool found = false;
            std::size_t basisIndex = 0;
            bool isReal = false;
            bool isSymplectic = false;
        };

        RealityOutcome searchRealityStructure(const std::array<CMat, 4> &gamma, double relationSign)
        {
            const auto basis = cliffordBasis(gamma);
            for (std::size_t index = 0; index < basis.size(); ++index)
            {
                const CMat &candidate = basis[index];
                bool matches = true;
                for (std::size_t mu = 0; mu < 4 && matches; ++mu)
                {
                    const CMat left = matrixMultiply(candidate, gamma[mu]);
                    const CMat right = matrixScale(Cx(relationSign, 0.0),
                                                   matrixMultiply(matrixConjugate(gamma[mu]), candidate));
                    matches = matricesClose(left, right);
                }
                if (matches)
                {
                    const CMat product = matrixMultiply(candidate, matrixConjugate(candidate));
                    const bool isReal = matricesClose(product, identityMatrix());
                    const bool isSymplectic = matricesClose(product, matrixScale(Cx(-1.0, 0.0), identityMatrix()));
                    return RealityOutcome{true, index, isReal, isSymplectic};
                }
            }
            return RealityOutcome{};
        }

        struct Region
        {
            std::string label;
            std::array<bool, 4> flip;
        };
    }

    void SpinRepresentation::run(Report &report) const
    {
        const std::array<Region, 3> regions{
            Region{"region I, signature (1,3)", {false, false, false, false}},
            Region{"the Kleinian intermediate region, signature (2,2)", {false, true, false, false}},
            Region{"region II, signature (3,1)", {false, true, true, false}},
        };

        const auto base = baseGammaSet();

        report.subsection("The Clifford relation, carried into each signature by one substitution");

        std::array<std::array<CMat, 4>, 3> gammaSets{};
        for (std::size_t regionIndex = 0; regionIndex < regions.size(); ++regionIndex)
        {
            const auto &region = regions[regionIndex];
            const auto gamma = applyFlips(base, region.flip);
            gammaSets[regionIndex] = gamma;
            const auto eta = etaFromFlips(region.flip);

            double worst = 0.0;
            for (std::size_t mu = 0; mu < 4; ++mu)
            {
                for (std::size_t nu = 0; nu < 4; ++nu)
                {
                    const CMat anticommutator = matrixAdd(matrixMultiply(gamma[mu], gamma[nu]),
                                                          matrixMultiply(gamma[nu], gamma[mu]));
                    const double expectedEntry = (mu == nu) ? 2.0 * eta[mu] : 0.0;
                    const CMat expected = matrixScale(Cx(expectedEntry, 0.0), identityMatrix());
                    worst = std::max(worst, maxAbsDifference(anticommutator, expected));
                }
            }
            report.checkNear(std::format("  {{gamma_mu, gamma_nu}} = 2 eta I holds for {}", region.label), worst);
        }

        report.subsection("Fixing the sign in B*gamma_mu = sign * conj(gamma_mu)*B against a known case");

        const auto calibration = searchRealityStructure(gammaSets[0], -1.0);
        report.check("with sign -1, region I comes out real, matching the textbook fact that ordinary "
                    "3+1 Minkowski carries a Majorana condition, so -1 rather than +1 is the relation a "
                    "Majorana spinor must obey against the free Dirac equation",
                    calibration.found && calibration.isReal);

        report.subsection("Whether a Clifford-compatible reality structure exists, at the calibrated sign");

        std::array<RealityOutcome, 3> outcomes{};
        for (std::size_t regionIndex = 0; regionIndex < regions.size(); ++regionIndex)
        {
            const auto &region = regions[regionIndex];
            outcomes[regionIndex] = searchRealityStructure(gammaSets[regionIndex], -1.0);
            const auto &outcome = outcomes[regionIndex];
            report.check(std::format("  {} admits a matrix B with B*gamma_mu = -conj(gamma_mu)*B", region.label),
                        outcome.found);
            if (outcome.found)
            {
                const std::string kind = outcome.isReal ? "+I (a real, Majorana-compatible structure)"
                                        : outcome.isSymplectic ? "-I (only a symplectic structure, no single Majorana condition)"
                                                                : "neither +I nor -I";
                report.check(std::format("    for {}, that matrix is basis element {} of 16, and B*conj(B) = {}",
                                        region.label, outcome.basisIndex, kind),
                            outcome.isReal || outcome.isSymplectic);
            }
        }

        report.subsection("What this settles about a transported fermion, and what it does not");

        report.check("region I and the Kleinian intermediate region carry the same reality class",
                    outcomes[0].isReal == outcomes[1].isReal &&
                    outcomes[0].isSymplectic == outcomes[1].isSymplectic);

        report.check("region II's reality class differs from region I's, so the Majorana condition "
                    "available in region I has no counterpart to be carried into on the far side",
                    outcomes[0].isReal && outcomes[2].isSymplectic);

        report.check("this search settles reality class alone; it says nothing about whether the frame "
                    "bundle itself admits a spin structure across a metric that degenerates at the threshold, "
                    "which is the question the literature raises and this project does not compute",
                    true);
    }

}
