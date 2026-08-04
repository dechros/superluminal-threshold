#pragma once

#include "core/Section.h"

#include <string>
#include <vector>

namespace slm
{

    /// Whether the numbers the text quotes are the numbers the libraries
    /// compute.
    ///
    /// A manuscript and the code behind it drift apart in one direction only.
    /// A number is computed, written into the text, and then the calculation
    /// changes; the text keeps the old value and nothing complains, because
    /// nothing was watching. Every other check here guards the code against
    /// itself. This one guards the text against the code.
    ///
    /// Each entry pairs a value obtained by calling the library that owns it
    /// against the exact string the text is expected to contain. The string is
    /// written the way the text writes numbers, with a comma for the decimal
    /// separator, so a match is a match on what a reader sees rather than on a
    /// normalised form neither side uses.
    ///
    /// The pairing is deliberately literal. Recomputing the string from the
    /// value and searching for that would pass whenever the formatting agreed,
    /// including when both sides were wrong in the same way. Here the expected
    /// string is written out by hand and the value is computed, so the check
    /// fails when either moves.
    class ArticleSync
    {
    public:
        /// One quoted number, with where it came from and how the text writes
        /// it.
        struct Quotation
        {
            std::string subject;  ///< what the number is
            double computed;      ///< the value the libraries give
            std::string asWritten;///< the exact text the article must contain
        };

        /// Every number the article quotes from a calculation.
        static std::vector<Quotation> quotations();

        /// Whether the article contains the given string.
        static bool textContains(const std::string &document, const std::string &needle);

        /// Quotations the article does not contain as written.
        static std::vector<std::string> missing(const std::string &document);

        /// Whether the written form is consistent with the computed value, to
        /// the precision the text quotes it at. This catches a value that
        /// changed while the string stayed, which is the failure the class
        /// exists for.
        static bool writtenMatchesComputed(const Quotation &quotation);

        /// Quotations whose written form no longer agrees with the value.
        static std::vector<std::string> stale();
    };

    /// Section checking the article against the calculations it quotes.
    class ArticleSyncSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The numbers the text quotes against the numbers computed";
        }
        void run(Report &report) const override;
    };

}
