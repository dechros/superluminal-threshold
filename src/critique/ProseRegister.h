#pragma once

#include "core/Section.h"

#include <string>
#include <vector>

namespace slm
{

    /// Measurable rules for the register the manuscript is written in.
    ///
    /// The manuscript is in Turkish and had drifted into a register that is
    /// Turkish by vocabulary and unreadable by construction. The rules below are
    /// not assembled by ear: they come from the conventions Turkish journals
    /// state for scientific prose, and from measuring prose that is agreed to be
    /// well written in that language. Each one is a number, so the text can be
    /// held to it rather than argued about.
    ///
    /// FIRST PERSON IS FORBIDDEN. Turkish academic convention rules out first
    /// person singular and plural, and possessive forms of the work itself. This
    /// matters here because the obvious cure for the next rule is first person,
    /// and that cure is not available.
    ///
    /// PASSIVES MAY NOT STACK. The passive is normal in this register and is not
    /// a fault on its own. Three or more in one paragraph is, because by then
    /// nothing in the paragraph has a subject. The way out is neither the
    /// passive nor the first person: it is to let the object under study act.
    /// The table shows, the scan leaves eight, the closed form gives no delay,
    /// the code refuted the line. Well written Turkish scientific prose does
    /// this throughout, with an impersonal subject that is nonetheless an agent.
    ///
    /// SENTENCES STAY SHORT. Measured on Turkish prose of this kind, sentences
    /// run from eight to twenty words, with an occasional longer one carrying a
    /// list. Past thirty two words a sentence in this manuscript was reliably
    /// doing three jobs at once.
    ///
    /// THE TEXT DOES NOT DISCUSS THE TEXT. Sentences saying that something must
    /// be recorded, must not be confused, or must not be exaggerated instruct
    /// the reader about the document instead of stating the claim the wrapper
    /// contains. The claim always survived on its own.
    ///
    /// SENTENCES DO NOT OPEN WITH A BARE CONJUNCTION. Formal Turkish does not
    /// begin a sentence with "Ve" or "Ama". This rule is here because breaking
    /// the long sentences introduced nine of them: splitting a clause off and
    /// leaving its conjunction in front is the easiest way to turn written
    /// Turkish into spoken Turkish, and it happened while fixing something else.
    ///
    /// NOMINALISATION MAY NOT CHAIN. Three or more verbal nouns in one sentence
    /// is the fault that survives every other rule: each is grammatical, and
    /// together they put four nouns in front of the verb and the reader holds
    /// all of them until it arrives. The cure is to let the sentence have a
    /// verb early, and to make a list into a list.
    ///
    /// A SUFFIX AGREES WITH HOW ITS NUMBER IS READ. Turkish attaches a case
    /// ending to a numeral according to the sound of the spoken word, not the
    /// digit, so a reference to chapter five takes one ending and a reference to
    /// chapter six takes another. Fifteen references in this manuscript had the
    /// wrong possessive, which reads as a misspelling to anyone who says the
    /// sentence aloud; the first version of this check covered the possessive
    /// alone and passed the manuscript, and a later reading found thirty eight
    /// more in the locative, the dative and the accusative. So the check now
    /// speaks the number and derives every ending from it: the trailing digit
    /// names the word unless it is a zero, where the tens word takes over, and
    /// the word's last vowel and last consonant fix both the vowel and the stop
    /// of the ending. The locative after chapter six is voiced and back, after
    /// chapter three voiceless and front, and nothing about the digits says so.
    /// The ending does not have to touch the digits either: a citation closes its
    /// bracket and a number closes its arithmetic delimiter first, and thirty
    /// bibliography references sat behind that bracket where the first two
    /// versions of this check could not see them. A fraction is read digit by
    /// digit, so its trailing zero is a zero rather than a thousand.
    ///
    /// NO EM DASH, which is a house rule rather than a language one, and is
    /// checked here with the rest so there is one place to look.
    class ProseRegister
    {
    public:
        /// A place in the text that breaks a rule.
        struct Fault
        {
            std::string rule;
            int line = 0;
            std::string excerpt;
        };

        /// Longest a sentence may be, in words.
        static constexpr int sentenceWordLimit = 32;

        /// Most passive constructions one paragraph may carry.
        static constexpr int passivesPerParagraph = 2;

        /// Most verbal nouns one sentence may carry.
        static constexpr int nominalsPerSentence = 2;

        /// The manuscript, or an empty string when it cannot be opened.
        static std::string text();

        /// Sentences longer than the limit, excluding tables, display equations
        /// and headings, and excluding sentences that are enumerations, since a
        /// list of five items reads better as one sentence than as five.
        static std::vector<Fault> longSentences(const std::string &text);

        /// Paragraphs carrying more passives than the limit.
        static std::vector<Fault> stackedPassives(const std::string &text);

        /// Sentences written in the first person.
        static std::vector<Fault> firstPerson(const std::string &text);

        /// Sentences that instruct the reader about the text.
        static std::vector<Fault> selfReference(const std::string &text);

        /// Sentences opening with a bare conjunction.
        static std::vector<Fault> openingConjunctions(const std::string &text);

        /// Sentences carrying more verbal nouns than the limit. Enumerations are
        /// excluded, since a list of nominalised results reads better as one
        /// sentence than as five.
        static std::vector<Fault> nominalChains(const std::string &text);

        /// Numerals whose case ending disagrees with how the number is read
        /// aloud, in any of the cases the manuscript uses.
        static std::vector<Fault> numberSuffixes(const std::string &text);

        /// Occurrences of the em dash.
        static std::vector<Fault> emDashes(const std::string &text);

        /// Every fault, in one list.
        static std::vector<Fault> faults(const std::string &text);
    };

    /// Section holding the manuscript to the register it declares.
    class ProseRegisterSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The register the manuscript is held to";
        }
        void run(Report &report) const override;
    };

}
