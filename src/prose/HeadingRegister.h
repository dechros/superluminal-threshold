#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// Headings held to being noun phrases rather than assertions.
    ///
    /// A heading carrying a colon, a question mark, or a finite verb has
    /// stopped naming and started asserting, and naming is what a heading is
    /// for. The aorist cannot be told from a heading noun ending the same way
    /// without a lexicon, since "zincir", "sınır" and any name ending in -er
    /// share the aorist's letters, so the finite forms detected by shape are
    /// supplemented by a list of aorist verbs.
    class HeadingRegister
    {
    public:
        /// Longest a heading may be, in words.
        static constexpr int wordLimit = 8;

        /// Longest the headings may be on average, in tenths of a word. A
        /// single long heading is a local choice; a high average means the
        /// headings are being written as statements rather than as names.
        static constexpr int meanTenths = 40;

        /// Headings that assert rather than name: a finite verb, a colon, a
        /// question, or more words than a name needs.
        static std::vector<ProseFault> verbalHeadings(const std::string &text);

        /// Mean heading length in tenths of a word. Reported in tenths
        /// because the difference between naming and asserting shows up in
        /// the first decimal place, and rounding to whole words hides it.
        static int headingWordMean(const std::string &text);
    };

}
