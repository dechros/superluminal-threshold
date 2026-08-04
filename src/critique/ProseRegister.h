#pragma once

#include "core/Section.h"

#include <string>
#include <utility>
#include <vector>

namespace slm
{

    /// Measurable rules for the register a Turkish scientific text is written in.
    ///
    /// Each rule is a number, so a text can be held to it instead of argued
    /// about. The rules come from the conventions Turkish journals state for
    /// scientific prose and from measuring prose accepted as well written in
    /// that language.
    ///
    /// FIRST PERSON IS FORBIDDEN. Turkish academic convention rules out first
    /// person singular and plural, and possessive forms of the work itself. It
    /// is not enough to look for first person verbs: Turkish marks a possessor
    /// with a suffix, so a noun can be in the first person while every verb in
    /// the sentence is impersonal, and a case ending may follow that suffix. A
    /// few ordinary words end in the same letters and are listed as exceptions.
    ///
    /// NEITHER IS THE READER ADDRESSED. The second person is the same fault
    /// seen from the other side, and it arrives by a different route: a section
    /// meant to be reproducible slips into instructions, telling the reader to
    /// compute this and compare that. The register states what a computation
    /// gives, not what a reader should do.
    ///
    /// PASSIVES MAY NOT STACK. The passive is normal in this register and is not
    /// a fault on its own. Three or more in one paragraph is, because by then
    /// nothing in the paragraph has a subject. The way out is neither the
    /// passive nor the first person, both of which are unavailable here: it is to
    /// let the object under study act. The table shows, the scan leaves eight,
    /// the closed form gives no delay. Well written Turkish scientific prose
    /// does this throughout, with an impersonal subject that is still an agent.
    ///
    /// SENTENCES STAY SHORT. Measured on Turkish prose of this kind, sentences
    /// run from eight to twenty words, with an occasional longer one carrying a
    /// list. Past the limit set below a sentence is usually doing several jobs
    /// at once.
    ///
    /// THE TEXT DOES NOT DISCUSS THE TEXT. A sentence saying that something must
    /// be recorded, must not be confused, or must not be exaggerated instructs
    /// the reader about the document instead of stating the claim it wraps. The
    /// claim reads the same without the wrapper.
    ///
    /// SENTENCES DO NOT OPEN WITH A BARE CONJUNCTION. Formal Turkish does not
    /// begin a sentence with "Ve" or "Ama". Splitting a long sentence and
    /// leaving its conjunction in front is the usual way this appears, so the
    /// rule matters most while another rule is being satisfied.
    ///
    /// NOMINALISATION MAY NOT CHAIN. Three or more verbal nouns in one sentence
    /// survives every other rule: each is grammatical, and together they put
    /// several nouns in front of the verb and the reader holds all of them until
    /// it arrives. The cure is a verb early in the sentence, and a list written
    /// as a list.
    ///
    /// A CASE ENDING AGREES WITH HOW ITS NUMBER IS READ. Turkish attaches the
    /// ending by the sound of the spoken word, not by the digit, so the ending
    /// cannot be looked up from the numeral: it has to be derived. The trailing
    /// digit names the spoken word, unless it is a zero, where the tens word
    /// does; that word's last vowel gives the vowel of the ending and its last
    /// consonant gives the stop. Five and six therefore take different endings
    /// in every case, and so do three and four. Two further details decide
    /// whether the check sees an ending at all: it need not touch the digits,
    /// since a reference closes its bracket and a quantity closes its arithmetic
    /// delimiter first, and a fraction is read digit by digit, so a trailing zero
    /// after the separator is a zero rather than a thousand.
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

        /// Longest a heading may be, in words.
        static constexpr int headingWordLimit = 8;

        /// Bands the predicate mix and the passive density have to fall in.
        static constexpr int copulaShareLimit = 33;
        static constexpr int continuousShareFloor = 2;
        static constexpr int passivePerThousandLimit = 40;

        /// The text under review, or an empty string when it cannot be opened.
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
        /// aloud, in any of the cases the text uses.
        static std::vector<Fault> numberSuffixes(const std::string &text);

        /// Occurrences of the em dash.
        static std::vector<Fault> emDashes(const std::string &text);

        /// Headings that assert rather than name: a finite verb, a colon, a
        /// question, or more words than a name needs.
        static std::vector<Fault> verbalHeadings(const std::string &text);

        /// Share of prose sentences ending in each predicate form, in whole
        /// percentages, keyed by the ending.
        static std::vector<std::pair<std::string, int>> predicateMix(const std::string &text);

        /// Passive constructions per thousand words of prose.
        static double passiveDensity(const std::string &text);

        /// Every fault, in one list.
        static std::vector<Fault> faults(const std::string &text);
    };

    /// Section holding a text to the register it declares.
    class ProseRegisterSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The register the text is held to";
        }
        void run(Report &report) const override;
    };

}
