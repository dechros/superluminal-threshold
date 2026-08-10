#include "scan/DirectionFamily.h"

#include "core/Report.h"
#include "scan/PermutationScan.h"
#include "transform/SignatureInvolution.h"

#include <cmath>
#include <format>

namespace slm
{
    bool DirectionFamily::Outcome::sendsLater() const
    {
        return fromPositiveStep > 0.0;
    }

    namespace
    {
        /// The near-side time (row 0) produced by a step of the given size
        /// along the far side's single space axis (column 3), the far
        /// side's other three coordinates held at zero.
        double nearTimeFromSpaceStep(const Matrix4 &matrix, double step)
        {
            return matrix.at(0, 3) * step;
        }
    }

    std::vector<DirectionFamily::Outcome> DirectionFamily::outcomes()
    {
        std::vector<Outcome> result;
        for (const PermutationScan::Candidate &candidate : PermutationScan::admissible())
        {
            Outcome outcome;
            outcome.matrix = candidate.matrix;
            outcome.fromPositiveStep = nearTimeFromSpaceStep(candidate.matrix, 1.0);
            outcome.fromNegativeStep = nearTimeFromSpaceStep(candidate.matrix, -1.0);
            result.push_back(outcome);
        }
        return result;
    }

    void DirectionFamily::run(Report &report) const
    {
        const std::vector<Outcome> found = outcomes();

        report.subsection("A step's sign does not come from the three filters alone");
        report.check(std::format("eight matrices pass every filter, and each was applied to a "
                                 "+1 and a -1 step ({} outcomes)",
                                 found.size()),
                     found.size() == 8);

        int later = 0;
        int earlier = 0;
        for (const Outcome &outcome : found)
        {
            report.checkNear("  the +1 and -1 steps land at opposite near-side times",
                             outcome.fromPositiveStep + outcome.fromNegativeStep);
            report.checkNear("  the near-side time has unit size either way",
                             std::abs(outcome.fromPositiveStep) - 1.0);
            if (outcome.sendsLater())
            {
                ++later;
            }
            else
            {
                ++earlier;
            }
        }
        report.check(std::format("of the eight, {} send a positive step later and {} send it "
                                 "earlier",
                                 later, earlier),
                     later == 4 && earlier == 4);

        report.subsection("D and its reflection SD sit in opposite families");
        const Matrix4 d = SignatureInvolution::matrix();
        const Matrix4 s = Matrix4::diagonal(-1.0, 1.0, 1.0, -1.0);
        const Matrix4 sd = s * d;

        bool dSendsLater = false;
        bool sdSendsLater = false;
        bool dFound = false;
        bool sdFound = false;
        for (const Outcome &outcome : found)
        {
            if (outcome.matrix.isEqual(d))
            {
                dSendsLater = outcome.sendsLater();
                dFound = true;
            }
            if (outcome.matrix.isEqual(sd))
            {
                sdSendsLater = outcome.sendsLater();
                sdFound = true;
            }
        }
        report.check("D is one of the eight admissible matrices", dFound);
        report.check("its reflection SD is also one of the eight", sdFound);
        report.check("D sends a positive step later", dSendsLater);
        report.check("SD sends the same positive step earlier", dFound && sdFound && !sdSendsLater);
    }

}
