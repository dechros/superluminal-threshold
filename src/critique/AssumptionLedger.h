#pragma once

#include "core/Section.h"
#include "critique/DocumentIntegrity.h"

#include <string>
#include <vector>

namespace slm
{

    /// Audit of a document against a ledger the document itself carries.
    ///
    /// A text can be disciplined about its assumptions and still drift, because
    /// the discipline lives in the prose and nothing enforces it. This class
    /// turns the discipline into a check. It reads the text, finds every passage
    /// that asserts an assumption, and requires each one to appear in a ledger
    /// with a disposition.
    ///
    /// NEITHER DOCUMENT NAMES THE OTHER. The ledger and the vocabulary of
    /// dispositions are not held here; they are parsed out of the text at run
    /// time, so this class contains no headings, numbers or wording belonging to
    /// it. The only thing it knows is the file to open and the shape of a
    /// markdown table. A text that renumbers its own sections therefore carries
    /// its ledger along with it and leaves nothing here to rot.
    ///
    /// WHAT IS ENFORCED. Every passage asserting an assumption must appear in
    /// the ledger; every ledger row must be complete; and every disposition used
    /// must be one the text itself declares. The last of these is what stops a
    /// ledger from absorbing an assumption by inventing a comfortable word for
    /// it.
    ///
    /// THE READING IS NOT OPTIONAL. If the text cannot be opened, or carries no
    /// ledger, the check fails; it does not skip, because a check that
    /// disappears when its input is missing reports success for having done
    /// nothing.
    class AssumptionLedger
    {
    public:
        /// One row of the ledger the text carries.
        struct Entry
        {
            std::string section;
            std::string statement;
            std::string disposition;
            std::string settledAt;
        };

        /// Contents of the text, empty when it cannot be read.
        static std::string text();

        /// Dispositions the text declares as permissible.
        static std::vector<std::string> vocabulary(const std::string &text);

        /// Ledger rows the text carries.
        static std::vector<Entry> entries(const std::string &text);

        /// Section identifiers of every passage in the text that asserts an
        /// assumption, with negated and withdrawn phrasings excluded.
        static std::vector<std::string> assertedIn(const std::string &text);

        /// Sections asserting an assumption the ledger does not cover.
        static std::vector<std::string> uncovered(const std::string &text);

        /// Ledger rows with an empty cell.
        static std::vector<Entry> incomplete(const std::string &text);

        /// Ledger rows whose disposition the text does not declare.
        static std::vector<Entry> outsideVocabulary(const std::string &text);

        /// Number of rows carrying the given disposition.
        static int countWith(const std::string &text, const std::string &disposition);
    };

    /// Section auditing a text against the ledger it carries.
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
