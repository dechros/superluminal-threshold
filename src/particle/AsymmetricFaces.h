#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <vector>

namespace slm
{

    /// Round trips built from two independently chosen crossing matrices.
    ///
    /// Eight signed permutation matrices preserve the line element and differ
    /// only in how they label the space axes. A region has two faces, and each
    /// realises one of the eight. The round trip is their composition: equal
    /// faces compose to the identity and turn nothing, unequal faces compose to
    /// a definite rotation.
    ///
    /// The deflections reachable this way therefore form a finite set rather
    /// than a continuum, and that set is what these functions enumerate.
    class AsymmetricFaces
    {
    public:
        /// The eight admissible crossing matrices, in scan order.
        static std::vector<Matrix4> admissibleFaces();

        /// The round trip when entry and exit realise the given faces.
        static Matrix4 roundTrip(const Matrix4 &entry, const Matrix4 &exit);

        /// Whether the round trip leaves the near-side energy slot alone, which it must
        /// if energy is to be conserved.
        static bool conservesEnergy(const Matrix4 &trip);

        /// Deflection of a given three-momentum under the round trip.
        static double deflection(const Matrix4 &trip, double px, double py, double pz);

        /// Every distinct deflection the eight faces can produce, sorted.
        static std::vector<double> deflectionSpectrum(double px, double py, double pz);
    };

    /// Section computing the finite set of turns two faces can produce.
    class AsymmetricFacesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Letting the two faces differ: the turn is quantised";
        }
        void run(Report &report) const override;
    };

}
