#pragma once

#include "core/Section.h"

#include <string>
#include <vector>

namespace slm
{

    /// Which externally known results these libraries reproduce with their own
    /// tools, and which they only use.
    ///
    /// A result taken from outside and a result computed here do not carry the
    /// same weight, and an account that does not separate them is claiming more
    /// than it has. This register keeps the separation. Each entry names a
    /// result by what it says, states whether something here recomputes it, and
    /// where.
    ///
    /// Results are named by their content and never by where they were
    /// published. That is deliberate: a topic stays true when a section is
    /// renumbered or a preprint is superseded, whereas a citation key rots and
    /// has to be maintained. Anything wanting the bibliographic side of this
    /// register can join it on the topic.
    ///
    /// Three states are distinguished. REPRODUCED means a library here computes
    /// the result independently and its value can be compared. USED means the
    /// result is relied on without being recomputed, so its correctness is not
    /// under this library's guarantee. CONTEXT means it is cited for orientation
    /// and no result is drawn from it.
    class ReproductionLedger
    {
    public:
        enum class State
        {
            Reproduced,
            Used,
            Context
        };

        struct Entry
        {
            const char *result;
            State state;
            const char *library;
        };

        static std::string name(State state);

        /// Every entry in the register.
        static std::vector<Entry> entries();

        /// Number of entries in a given state.
        static int countWith(State state);

        /// Total number of entries.
        static int totalCount();

        /// Whether every reproduced entry names a library, which is what makes
        /// the claim checkable rather than a label.
        static bool everyReproductionNamesALibrary();

        /// Whether any entry claims a reproduction while naming no library,
        /// which would be the failure this register exists to prevent.
        static bool anyUnsupportedReproduction();
    };

    /// Section listing what is reproduced here and what is taken on trust.
    class ReproductionLedgerSection : public Section
    {
    public:
        std::string title() const override
        {
            return "What is recomputed here and what is taken on trust";
        }
        void run(Report &report) const override;
    };

}
