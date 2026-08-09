#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// Sentence length held to a stated cap.
    ///
    /// Measured on Turkish prose of this kind, sentences run from eight to
    /// twenty words, with an occasional longer one carrying a list. Past the
    /// limit below a sentence is usually doing several jobs at once.
    class SentenceLengthRegister
    {
    public:
        /// Longest a sentence may be, in words.
        static constexpr int wordLimit = 32;

        /// Sentences longer than wordLimit, excluding tables, display
        /// equations and headings, and excluding sentences that are
        /// enumerations, since a list of five items reads better as one
        /// sentence than as five.
        static std::vector<ProseFault> longSentences(const std::string &text);
    };

}
