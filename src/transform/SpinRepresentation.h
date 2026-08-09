#pragma once

#include "core/Section.h"

namespace slm
{

    /// Section on whether region I, the Kleinian intermediate region, and
    /// region II admit a Clifford algebra representation that can be brought
    /// to a real (Majorana) or pseudoreal (symplectic) form.
    ///
    /// Every other section that carries a particle treats it as a scalar
    /// field. A fermion instead needs a representation of the Clifford
    /// algebra fixed by each region's metric, and nothing upstream asks
    /// whether that representation sits in the same reality class on both
    /// sides of the threshold. This section builds the three
    /// representations from the same Dirac matrices used throughout physics,
    /// by the substitution that turns one signature into another, and
    /// searches the sixteen-element Clifford basis directly for a matrix
    /// relating each representation to its own complex conjugate, rather
    /// than reading the answer off the abstract classification of real
    /// Clifford algebras.
    class SpinRepresentation : public Section
    {
    public:
        std::string title() const override
        {
            return "Spin representation across the three signatures";
        }
        void run(Report &report) const override;
    };

}
