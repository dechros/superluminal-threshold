#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// Chains of verbal nouns in one sentence.
    ///
    /// Three or more verbal nouns in one sentence survives every other rule:
    /// each is grammatical, and together they put several nouns in front of
    /// the verb while the reader holds all of them until it arrives. The cure
    /// is a verb early in the sentence, and a list written as a list.
    class NominalChainRegister
    {
    public:
        /// Most verbal nouns one sentence may carry.
        static constexpr int nominalsPerSentence = 2;

        /// Sentences carrying more verbal nouns than nominalsPerSentence.
        /// Enumerations are excluded, since a list of nominalised results
        /// reads better as one sentence than as five.
        static std::vector<ProseFault> nominalChains(const std::string &text);
    };

}
