#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace slm
{

    /// A place in a text that breaks a register rule.
    struct ProseFault
    {
        std::string rule;
        int line = 0;
        std::string excerpt;
    };

    /// Line- and sentence-level reading of prose, shared by every register
    /// rule that scans it.
    ///
    /// A line belongs to the prose only when it is not a table row, a
    /// heading, a blockquote, a display-equation delimiter, or a line opening
    /// on a digit. A sentence is prose accumulated across lines until a stop
    /// mark closes it, with display mathematics folded out rather than
    /// scanned.
    class ProseText
    {
    public:
        /// Whether the line is prose rather than a table row, heading,
        /// blockquote, display-equation delimiter, or a line opening on a
        /// digit.
        static bool isProse(const std::string &line);

        /// Number of whitespace-separated words.
        static int wordCount(const std::string &s);

        /// Number of commas.
        static int commaCount(const std::string &s);

        /// Number of occurrences of needle in haystack, overlapping ones
        /// counted separately.
        static int occurrences(const std::string &haystack, const std::string &needle);

        /// The string with its runs of whitespace collapsed to single spaces,
        /// cut to the given width.
        static std::string shorten(const std::string &s, std::size_t width = 62);

        /// The text split at line breaks.
        static std::vector<std::string> splitLines(const std::string &text);

        /// The string with leading and trailing spaces, tabs and carriage
        /// returns removed.
        static std::string trimmed(const std::string &s);

        /// Prose sentences, assembled across lines and closed at a stop mark,
        /// with display mathematics excluded.
        static std::vector<std::string> proseSentences(const std::string &text);

        /// The last word of a sentence, with trailing punctuation stripped.
        static std::string finalWord(const std::string &sentence);
    };

}
