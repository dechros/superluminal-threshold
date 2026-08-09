#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// House rules on punctuation and on how a number is written.
    ///
    /// The em dash is a house rule rather than a language one. The decimal
    /// separator rule follows how the text reads its numbers aloud: Turkish
    /// reads a decimal with a comma, and a run of computed values pasted in
    /// from a program carries the program's point instead, often in the same
    /// table a comma-separated value sits in, where a reading does not catch
    /// the mismatch.
    class TypographyRegister
    {
    public:
        /// Occurrences of the em dash.
        static std::vector<ProseFault> emDashes(const std::string &text);

        /// Numbers written with a point for the decimal separator inside
        /// mathematics.
        static std::vector<ProseFault> decimalPoints(const std::string &text);
    };

}
