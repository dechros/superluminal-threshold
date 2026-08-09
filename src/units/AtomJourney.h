#pragma once

#include "core/Section.h"

namespace slm
{

    /// Whether the proton journey of @ref ProtonJourney still holds once the
    /// traveller is a bound state rather than a bare proton, and what that
    /// does and does not establish.
    ///
    /// @ref ProtonJourney::journey takes a drive frequency and a distance; it
    /// takes no mass. The mass of the object being carried enters this
    /// project's arithmetic in exactly one place, the ceiling of
    /// @ref PhysicalScales::heaviestMass, and nowhere else. So a heavier
    /// object clearing the same ceiling is carried by the identical record:
    /// same debt, same break-even distance, same arrival time. That identity
    /// is what this section checks for a hydrogen atom against the proton
    /// already carried elsewhere.
    ///
    /// What the identity does not establish is separate, and this section
    /// states it rather than leaving it implied: the mass ceiling is the only
    /// place the traveller's composition enters. Nothing here represents the
    /// electron-proton relative coordinate, so nothing here can say whether a
    /// bound state's internal structure is preserved by the crossing, and
    /// nothing here defines what that structure would even mean in a region
    /// with one space axis and three time axes rather than three and one.
    class AtomJourneySection : public Section
    {
    public:
        std::string title() const override
        {
            return "A hydrogen atom against the same mass ceiling, and what that does not settle";
        }
        void run(Report &report) const override;
    };

}
