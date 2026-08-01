#include "critique/DirectionDependentD.h"

#include "core/Report.h"
#include "core/Vector4.h"

#include <cmath>
#include <format>
#include <numbers>

namespace slm
{
    namespace
    {
        struct UnitVector
        {
            double x, y, z;
        };

        UnitVector direction(double theta, double phi)
        {
            return {std::sin(theta) * std::cos(phi),
                    std::sin(theta) * std::sin(phi),
                    std::cos(theta)};
        }

        Matrix4 assemble(const UnitVector &n, double sign, const double block[3][3])
        {
            Matrix4 m = Matrix4::zero();
            const double components[3] = {n.x, n.y, n.z};
            for (int i = 0; i < 3; ++i)
            {
                m.at(0, i + 1) = sign * components[i];
                m.at(i + 1, 0) = sign * components[i];
                for (int j = 0; j < 3; ++j)
                {
                    m.at(i + 1, j + 1) = block[i][j];
                }
            }
            return m;
        }
    }

    Matrix4 DirectionDependentD::candidate(Form form, double theta, double phi)
    {
        const UnitVector n = direction(theta, phi);
        const double components[3] = {n.x, n.y, n.z};

        double projector[3][3]{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                projector[i][j] = components[i] * components[j];
            }
        }

        double block[3][3]{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                const double identity = (i == j) ? 1.0 : 0.0;
                block[i][j] = (form == Form::MinusIdentity) ? (projector[i][j] - identity)
                                                            : (identity - projector[i][j]);
            }
        }

        const double sign = (form == Form::Zaopo) ? -1.0 : 1.0;
        return assemble(n, sign, block);
    }

    Matrix4 DirectionDependentD::householder(double theta, double phi)
    {
        const UnitVector n = direction(theta, phi);
        const double components[3] = {n.x, n.y, n.z};

        double block[3][3]{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                const double identity = (i == j) ? 1.0 : 0.0;
                block[i][j] = identity - 2.0 * components[i] * components[j];
            }
        }
        return assemble(n, 1.0, block);
    }

    void DirectionDependentD::run(Report &report) const
    {
        const Matrix4 eta = metricRegionI();
        const double pi = std::numbers::pi;

        struct Named
        {
            const char *label;
            Form form;
        };
        const Named forms[] = {
            {"A  [[0,-n],[-n, I-P]]", Form::Zaopo},
            {"B         [[0, n],[ n, I-P]]", Form::PlusIdentity},
            {"C         [[0, n],[ n, P-I]]", Form::MinusIdentity}};

        report.subsection("Candidate forms depending on the direction n");

        for (const Named &named : forms)
        {
            bool alwaysInvolution = true;
            bool everFlips = false;
            double determinant = 0.0;

            const double angles[][2] = {
                {0.0, 0.0},
                {pi / 2.0, 0.0},
                {pi / 2.0, pi / 2.0},
                {0.7, 1.3}};

            for (const auto &angle : angles)
            {
                const Matrix4 m = candidate(named.form, angle[0], angle[1]);
                determinant = m.determinant();
                if (!m.isInvolution(1e-10))
                {
                    alwaysInvolution = false;
                }
                if (m.flipsMetric(eta, eta, 1e-10))
                {
                    everFlips = true;
                }
            }

            report.check("    M^2 = I in every direction", alwaysInvolution);
            report.check("    NO genuine signature flip", !everFlips);
            report.check("    det = -1, parity is broken", std::abs(determinant + 1.0) < 1e-9);
        }

        report.subsection("Does the direction dependent form preserve or flip the interval?");
        const Matrix4 zaopo = candidate(Form::Zaopo, 0.0, 0.0);

        const Vector4 inSector(0.3, 0.0, 0.0, 0.9);
        const Vector4 inSectorImage = zaopo * inSector;
        report.checkNear("in the (t,n) sector s'^2 = -s^2: it does flip there",
                         inSectorImage.contract(eta) + inSector.contract(eta), 1e-10);

        const Vector4 perpendicular(0.0, -1.7, 2.4, 0.0);
        const Vector4 perpendicularImage = zaopo * perpendicular;
        report.checkNear("in perpendicular directions s'^2 = s^2: no flip at all",
                         perpendicularImage.contract(eta) - perpendicular.contract(eta), 1e-10);

        const Vector4 event(0.3, -1.7, 2.4, 0.9);
        const Vector4 image = zaopo * event;
        const double before = event.contract(eta);
        const double after = image.contract(eta);
        report.check("for a general event s'^2 != s^2, the interval is NOT preserved",
                     std::abs(after - before) > 1e-10);
        report.check("for a general event s'^2 != -s^2, the sign is NOT flipped either",
                     std::abs(after + before) > 1e-10);

        report.subsection("Sign flipping as a conjugation condition");
        const Matrix4 zaopoMetric = Matrix4::diagonal(-1.0, 1.0, 1.0, 1.0);
        const Matrix4 conjugated = zaopo * zaopoMetric * zaopo.inverse();
        const double conjugationResidual =
            (conjugated + zaopoMetric).maxAbsDifference(Matrix4::zero());
        const double congruenceResidual =
            (zaopo.congruence(zaopoMetric) + zaopoMetric).maxAbsDifference(Matrix4::zero());
        report.check("the conjugation condition does not hold exactly in (1+3) either",
                     conjugationResidual > 1e-9);
        report.check("the congruence condition DOES NOT hold", congruenceResidual > 1e-9);

        report.subsection("Householder type candidate: [[0, n^T],[n, I - 2P]]");
        const Matrix4 house = householder(0.7, 1.3);
        report.check("M^2 = I FAILS: not even an involution", !house.isInvolution(1e-10));
        report.check("NO genuine signature flip", !house.flipsMetric(eta, eta, 1e-10));
    }
}
