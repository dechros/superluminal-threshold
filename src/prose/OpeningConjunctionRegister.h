#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// Sentences opening with a bare conjunction.
    ///
    /// Formal Turkish does not begin a sentence with "Ve" or "Ama". Splitting
    /// a long sentence and leaving its conjunction in front is the usual way
    /// this appears, so the rule matters most while another rule is being
    /// satisfied.
    class OpeningConjunctionRegister
    {
    public:
        /// Sentences opening with a bare conjunction.
        static std::vector<ProseFault> openingConjunctions(const std::string &text);
    };

}
