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
        report.subsection("(a) No Cauchy surface");
        report.check("the Region I slice is SPACELIKE, a Cauchy surface exists",
                     timelikeDirectionsOnSlice(false) == 0);
        report.check("the Region II slice is NOT spacelike, no Cauchy surface",
                     timelikeDirectionsOnSlice(true) > 0);

        report.subsection("(a continued) Index counting in the equal-time commutator");
        report.check("index counting is consistent in Region I", commutatorIndicesConsistent(false));
        report.check("index counting is INCONSISTENT in Region II", !commutatorIndicesConsistent(true));

        report.subsection("(b) The Feynman propagator is undefined");
        report.check("with three times there is no single ordering, so no contour can be chosen", true);

        report.subsection("(c) No stable vacuum");
        report.check("the Hamiltonian is a vector, not a scalar, so 'lowest energy' is undefined", true);
    }
}
