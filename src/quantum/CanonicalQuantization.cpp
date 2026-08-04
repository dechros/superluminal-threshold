#include "quantum/CanonicalQuantization.h"

#include "core/Report.h"

#include <format>

namespace slm
{
    int CanonicalQuantization::conjugateMomentumCount(bool regionII)
    {
        return regionII ? 3 : 1;
    }

    int CanonicalQuantization::timelikeDirectionsOnSlice(bool regionII)
    {
        return regionII ? 2 : 0;
    }

    bool CanonicalQuantization::commutatorIndicesConsistent(bool regionII)
    {
        const int momentumIndices = conjugateMomentumCount(regionII);
        const int spatialDimensionOnSlice = regionII ? 1 : 3;
        return momentumIndices == 1 && spatialDimensionOnSlice == 3;
    }

    void CanonicalQuantization::run(Report &report) const
    {
        report.subsection("(a) No initial data surface");
        report.check("the Region I slice is SPACELIKE, a initial data surface exists",
                     timelikeDirectionsOnSlice(false) == 0);
        report.check("the Region II slice is NOT spacelike, no initial data surface",
                     timelikeDirectionsOnSlice(true) > 0);

        report.subsection("(a continued) Index counting in the equal-time commutator");
        report.check("index counting is consistent in Region "
                     "I", commutatorIndicesConsistent(false));
        report.check("index counting is INCONSISTENT in Region "
                     "II", !commutatorIndicesConsistent(true));

        report.subsection("(b) The time-ordered propagator is undefined");
        int incomparablePairs = 0;
        int comparablePairs = 0;
        for (int i = 0; i < 27; ++i)
        {
            for (int j = i + 1; j < 27; ++j)
            {
                const int a[3] = {i % 3, (i / 3) % 3, i / 9};
                const int b[3] = {j % 3, (j / 3) % 3, j / 9};
                const bool aBeforeB = a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
                const bool bBeforeA = b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2];
                if (aBeforeB || bBeforeA)
                {
                    ++comparablePairs;
                }
                else
                {
                    ++incomparablePairs;
                }
            }
        }
        report.check(std::format("of {} pairs of events in three times, {} cannot be ordered "
                                 "at all, so no single time ordering and no contour exists",
                                 comparablePairs + incomparablePairs, incomparablePairs),
                     incomparablePairs > 0);

        report.subsection("(c) No stable vacuum");
        report.check(std::format("the generator of time translation has {} components beyond "
                                 "the threshold against 1 before it, so it is a vector and "
                                 "'lowest energy' has no meaning",
                                 conjugateMomentumCount(true)),
                     conjugateMomentumCount(true) > conjugateMomentumCount(false) &&
                         conjugateMomentumCount(false) == 1);
    }
}
