#pragma once

#include "core/Section.h"

namespace slm
{

    /// Whether two point masses launched together through the same crossing,
    /// under one shared drive, come back to the same return event.
    ///
    /// A bond is given no dynamics of its own here; none is represented
    /// anywhere in this project, and none is assumed. What is defined instead
    /// is a kinematic test built entirely from @ref ReturnEvent, already
    /// established elsewhere: two masses share one drive frequency, which
    /// fixes each one's own mass-shell length through
    /// @f$ \mathrm{length}^2 = \omega^2/c^2 - \mu @f$, and share one launch
    /// orientation and branch. Each is carried by the identical
    /// @ref ReturnEvent::map already verified for a single mass. Comparing
    /// the two returned events is the whole of the calculation.
    ///
    /// A pair whose two events agree is called bound on return; a pair whose
    /// events differ is called separated on return, and by how much. Neither
    /// outcome is asserted in advance; both are computed. What this class
    /// does not do is model why the masses were bound in region I, or what
    /// keeps them together, or what a relative coordinate means in a region
    /// of one space axis and three time axes: none of that is represented,
    /// and this class reads no further than the two coordinates the existing
    /// map already produces.
    class BoundPairSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Two masses under one drive: does the pair return to the same event";
        }
        void run(Report &report) const override;
    };

}
