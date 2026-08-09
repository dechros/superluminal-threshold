#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// Sentences that instruct the reader about the text rather than stating
    /// the claim it wraps.
    ///
    /// A sentence saying that something must be recorded, must not be
    /// confused, or must not be exaggerated discusses the document instead of
    /// the finding. The claim reads the same without the wrapper.
    class SelfReferenceRegister
    {
    public:
        /// Sentences that instruct the reader about the text.
        static std::vector<ProseFault> selfReference(const std::string &text);
    };

}
