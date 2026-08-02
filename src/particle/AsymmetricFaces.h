#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

#include <vector>

namespace slm
{

    /// Closing the fork of section 18.6 by letting the two faces differ.
    ///
    /// The fork was between a turn fixed at zero and a turn distributed
    /// uniformly. Both were assumptions. There is a third answer available
    /// inside the model already, and it is neither.
    ///
    /// Section 2.1 found that eight signed permutation matrices survive every
    /// filter, differing only in how they label the space axes. Each face of
    /// the intermediate region realises one of them. If both faces realise the
    /// same one, the round trip composes to the identity and there is no turn.
    /// If they realise different ones, the round trip is their composition, and
    /// that is a definite rotation rather than a free parameter.
    ///
    /// So the turn is neither always zero nor uniformly distributed. It takes
    /// values in a finite set, and this section computes that set.
    class AsymmetricFaces
    {
    public:
        /// The eight admissible crossing matrices, in scan order.
        static std::vector<Matrix4> admissibleFaces();

        /// The round trip when entry and exit realise the given faces.
        static Matrix4 roundTrip(const Matrix4 &entry, const Matrix4 &exit);

        /// Whether the round trip leaves our energy slot alone, which it must
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
        std::string number() const override { return "20"; }
        std::string title() const override
        {
            return "Letting the two faces differ: the turn is quantised";
        }
        void run(Report &report) const override;
    };

}
