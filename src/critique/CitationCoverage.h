#pragma once

#include "core/Section.h"

#include <string>
#include <vector>

namespace slm
{

    /// Whether every citation in the text has an entry behind it, and every
    /// entry a citation in front of it.
    ///
    /// A bibliography rots in two directions and neither one announces itself.
    /// A citation can point past the end of the list, which happens when the
    /// list is renumbered or shortened. An entry can sit in the list with
    /// nothing pointing at it, which happens when the passage that cited it is
    /// cut. Both survive a reading, because a reader checks the numbers that
    /// catch the eye rather than all of them.
    ///
    /// The failure this exists for is heavier than either. When a section is
    /// deleted, everything after it in the file goes with it, and the
    /// bibliography is the last thing in the file. Nothing in a numerical check
    /// notices that the list is gone, because a citation is not a number a
    /// calculation produces. So the first thing checked here is that the list
    /// exists at all and is not empty.
    ///
    /// Reading the document is part of the check rather than a precondition for
    /// it. A check that cannot find its input and passes anyway reports success
    /// for having done nothing.
    class CitationCoverage
    {
    public:
        /// Numbers the prose cites, in ascending order and without repeats.
        /// Bracketed numbers inside the bibliography itself are excluded, since
        /// an entry that cites another entry is not the prose citing it.
        static std::vector<int> cited(const std::string &document);

        /// Numbers the bibliography defines, in the order they are listed.
        /// Numbering restarts under each thematic heading in the list, so the
        /// running position rather than the printed digit carries the identity.
        static std::vector<int> listed(const std::string &document);

        /// Citations with no entry behind them.
        static std::vector<int> danglingCitations(const std::string &document);

        /// Entries with no citation in front of them.
        static std::vector<int> uncitedEntries(const std::string &document);

        /// Whether the bibliography heading is present and carries at least one
        /// entry. False when the list has been truncated away.
        static bool bibliographyPresent(const std::string &document);
    };

    /// Section checking the bibliography against the citations in the prose.
    class CitationCoverageSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The bibliography against the citations that point into it";
        }
        void run(Report &report) const override;
    };

}
