#pragma once

#include "core/Section.h"

#include <string>
#include <vector>

namespace slm

{

    /// Audit of every place the text states an assumption, and what became of
    /// it.
    ///
    /// A document can be disciplined about its assumptions and still drift,
    /// because the discipline lives in the prose and nothing enforces it. This
    /// class turns the discipline into a check. It reads the text itself, finds
    /// every passage that asserts an assumption, and requires each one to
    /// appear in a ledger with a disposition. A passage the ledger does not
    /// cover is a failure, so adding an unaccounted assumption to the text
    /// breaks the run rather than passing quietly.
    ///
    /// The dispositions are deliberately few. An assumption is either derived
    /// later, computed on both alternatives so that nothing rests on the
    /// choice, superseded by a later result that removes it, attributed to
    /// another author's construction rather than this one, or declared as a
    /// limitation with its consequence stated. There is no disposition for an
    /// assumption that is merely believed, which is the point of the class.
    ///
    /// The reading of the text is not optional. If the text cannot be opened
    /// the check fails; it does not skip, because a check that disappears when
    /// its input is missing reports success for having done nothing.
    class AssumptionLedger
    {
    public:
        /// What became of an assumption the text states.
        enum class Disposition
        {
            Derived,          ///< Later obtained from something else.
            ComputedBothWays, ///< Both alternatives computed, so the choice carries nothing.
            Superseded,       ///< A later result removes the need for it.
            AnotherAuthor,    ///< Belongs to a construction being compared, not to this one.
            DeclaredLimit,    ///< Kept, with its consequence stated in the text.
            Discussion        ///< Discusses assumptions rather than asserting one.
        };

        /// One entry: a section of the text and the disposition of the
        /// assumption it states.
        struct Entry
        {
            std::string section;
            std::string statement;
            Disposition disposition;
            std::string settledAt;
        };

        /// The ledger.
        static std::vector<Entry> entries();

        /// Number of entries carrying the given disposition.
        static int countWith(Disposition disposition);

        /// Contents of the text, empty when it cannot be read.
        static std::string articleText();

        /// Section identifiers of every passage in the text that asserts an
        /// assumption, with negated and withdrawn phrasings excluded.
        static std::vector<std::string> assertedIn(const std::string &text);

        /// Sections asserting an assumption that the ledger does not cover.
        static std::vector<std::string> uncovered(const std::string &text);

        /// Whether every entry names where it was settled.
        static bool everyEntryIsSettled();

        /// Human readable name of a disposition.
        static std::string dispositionName(Disposition disposition);
    };

    /// Section auditing the text against its own ledger of assumptions.
    class AssumptionLedgerSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Every assumption the text states, and what became of it";
        }
        void run(Report &report) const override;
    };

}
