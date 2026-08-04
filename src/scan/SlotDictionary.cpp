#include "scan/SlotDictionary.h"

#include "core/Report.h"
#include "scan/CrossingBranches.h"
#include "transform/SignatureInvolution.h"

#include <algorithm>
#include <cmath>
#include <format>

namespace slm
{

    int SlotDictionary::timeSlot()
    {
        return 0;
    }

    Vector4 SlotDictionary::timeRow(const Matrix4 &crossing)
    {
        const std::size_t row = static_cast<std::size_t>(timeSlot());
        return {crossing.at(row, 0), crossing.at(row, 1), crossing.at(row, 2),
                crossing.at(row, 3)};
    }

    int SlotDictionary::contributingAxes(const Matrix4 &crossing)
    {
        const Vector4 row = timeRow(crossing);
        int count = 0;
        for (std::size_t i = 0; i < 4; ++i)
        {
            if (std::abs(row[i]) > kEps)
            {
                ++count;
            }
        }
        return count;
    }

    int SlotDictionary::sourceAxis(const Matrix4 &crossing)
    {
        if (contributingAxes(crossing) != 1)
        {
            return -1;
        }
        const Vector4 row = timeRow(crossing);
        for (int i = 0; i < 4; ++i)
        {
            if (std::abs(row[static_cast<std::size_t>(i)]) > kEps)
            {
                return i;
            }
        }
        return -1;
    }

    double SlotDictionary::coefficient(const Matrix4 &crossing)
    {
        const int axis = sourceAxis(crossing);
        if (axis < 0)
        {
            return 0.0;
        }
        return timeRow(crossing)[static_cast<std::size_t>(axis)];
    }

    bool SlotDictionary::isUnitOneToOne(const Matrix4 &crossing)
    {
        return sourceAxis(crossing) >= 0 && std::abs(std::abs(coefficient(crossing)) - 1.0) <= kEps;
    }

    double SlotDictionary::clockDisplacement(const Matrix4 &crossing, double distance)
    {
        const int axis = sourceAxis(crossing);
        if (axis < 0)
        {
            return 0.0;
        }
        Vector4 step{};
        step[static_cast<std::size_t>(axis)] = distance;
        return (crossing * step)[static_cast<std::size_t>(timeSlot())];
    }

    double SlotDictionary::additivityResidual(const Matrix4 &crossing, double first, double second)
    {
        const double separately =
            clockDisplacement(crossing, first) + clockDisplacement(crossing, second);
        const double together = clockDisplacement(crossing, first + second);
        return separately - together;
    }

    bool SlotDictionary::isHomogeneous(const Matrix4 &crossing, double distance, double scale)
    {
        const double scaled = clockDisplacement(crossing, scale * distance);
        const double expected = scale * clockDisplacement(crossing, distance);
        return std::abs(scaled - expected) <= kEps;
    }

    bool SlotDictionary::likeSignedAxesContributeNothing(const Matrix4 &crossing)
    {
        const int axis = sourceAxis(crossing);
        if (axis < 0)
        {
            return false;
        }
        for (int other = 0; other < 4; ++other)
        {
            if (other == axis)
            {
                continue;
            }
            Vector4 step{};
            step[static_cast<std::size_t>(other)] = 1.0;
            if (std::abs((crossing * step)[static_cast<std::size_t>(timeSlot())]) > kEps)
            {
                return false;
            }
        }
        return true;
    }

    void SlotDictionarySection::run(Report &report) const
    {
        const auto eight = CrossingBranches::orientationPreserving();

        report.subsection("One far-side axis feeds the clock, and it does so with unit weight");
        report.check("there are eight admissible crossings to check", eight.size() == 8);

        bool everyOneIsUnit = true;
        bool everyOneIsIsolated = true;
        for (const auto &branch : eight)
        {
            everyOneIsUnit = everyOneIsUnit && SlotDictionary::isUnitOneToOne(branch.matrix);
            everyOneIsIsolated =
                everyOneIsIsolated && SlotDictionary::likeSignedAxesContributeNothing(branch.matrix);
        }
        report.check("in every one of them exactly one far-side axis contributes to the time "
                     "slot, with coefficient of magnitude one",
                     everyOneIsUnit);
        report.check("and the other three contribute exactly nothing to it, so travel confined "
                     "to them leaves the clock where it was",
                     everyOneIsIsolated);

        const Matrix4 D = SignatureInvolution::matrix();
        report.check(std::format("for the map used in this work the source axis is {} and the "
                                 "coefficient is {:+.0f}",
                                 SlotDictionary::sourceAxis(D), SlotDictionary::coefficient(D)),
                     SlotDictionary::sourceAxis(D) == 3 &&
                         std::abs(SlotDictionary::coefficient(D) - 1.0) <= kEps);

        report.subsection("So the amount transfers without a factor");
        for (double distance : {0.5, 1.0, 2.0, 4.0, 7.25})
        {
            report.checkNear(std::format("  {:g} along the far-side axis gives {:+.4f} on the "
                                         "clock",
                                         distance,
                                         SlotDictionary::clockDisplacement(D, distance)),
                             SlotDictionary::clockDisplacement(D, distance) - distance);
        }

        report.subsection("Displacements add, because the map is linear");
        bool addsForAll = true;
        for (const auto &branch : eight)
        {
            for (double first : {0.25, 1.0, 3.5})
            {
                for (double second : {0.75, 2.0, 4.5})
                {
                    addsForAll =
                        addsForAll &&
                        std::abs(SlotDictionary::additivityResidual(branch.matrix, first, second)) <=
                            kEps;
                }
            }
        }
        report.check("two legs travelled separately give the same clock displacement as their "
                     "sum travelled once, over all eight crossings and nine pairs of legs",
                     addsForAll);
        report.check("and the map is homogeneous in the amount, so doubling the distance doubles "
                     "the displacement",
                     SlotDictionary::isHomogeneous(D));
        report.checkNear("a leg and its opposite cancel exactly",
                         SlotDictionary::additivityResidual(D, 3.0, -3.0));
        report.checkNear("so a closed far-side excursion returns the clock to where it started",
                         SlotDictionary::clockDisplacement(D, 3.0) +
                             SlotDictionary::clockDisplacement(D, -3.0));

        report.subsection("Both signs transfer the amount equally");
        const auto forward =
            std::find_if(eight.begin(), eight.end(),
                         [](const CrossingBranches::Branch &b) { return b.timeSign > 0; });
        const auto backward =
            std::find_if(eight.begin(), eight.end(),
                         [](const CrossingBranches::Branch &b) { return b.timeSign < 0; });
        report.check("both a forward and a backward crossing exist",
                     forward != eight.end() && backward != eight.end());
        if (forward != eight.end() && backward != eight.end())
        {
            report.checkNear("they carry the same magnitude and opposite sign",
                             SlotDictionary::clockDisplacement(forward->matrix, 4.0) +
                                 SlotDictionary::clockDisplacement(backward->matrix, 4.0));
            report.check("so the dictionary fixes how much the clock moves and not which way",
                         std::abs(std::abs(SlotDictionary::coefficient(forward->matrix)) -
                                  std::abs(SlotDictionary::coefficient(backward->matrix))) <= kEps &&
                             SlotDictionary::coefficient(forward->matrix) *
                                     SlotDictionary::coefficient(backward->matrix) <
                                 0.0);
        }

        report.subsection("What this does and does not settle");
        report.check("everything above concerns far-side displacements only, so nothing here "
                     "by itself licenses adding a delay read from a scattering phase to one "
                     "of them; that addition is settled separately, by placing the "
                     "displacement inside the phase and reading the arrival moment from a "
                     "single stationary-phase condition",
                     true);
    }

}
