#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// Passive constructions, counted per paragraph and per thousand words.
    ///
    /// Turkish marks the passive with -Il after a consonant and with a bare -n
    /// after a vowel, so the morphology is the only thing that separates
    /// "göstermektedir" from "gösterilmektedir"; a pattern built on the tense
    /// suffix alone would count every active -maktadır and -mıştır as well.
    ///
    /// Three shapes wear the same letters without being passive, and each is
    /// excluded or the count doubles: the ability suffix -abil/-ebil, which
    /// ends in the same syllable the passive uses; the ablative followed by
    /// the copula, which is a noun in a case rather than a verb, as in
    /// "türdendir"; and a short list of verbs, "kullanır" and "tükenir" among
    /// them, that end this way without being passive at all.
    ///
    /// The match is also required to be a whole word ending in a finite
    /// tense, which keeps verbal nouns such as "gerçeklendiğini" out of the
    /// count, since a verbal noun is not a predicate and counting it would
    /// report a paragraph as subjectless when it has a subject in every
    /// sentence.
    ///
    /// The passive is normal in this register and is not a fault on its own.
    /// Three or more in one paragraph is, because by then nothing in the
    /// paragraph has a subject.
    class PassiveVoiceRegister
    {
    public:
        /// Most passive constructions one paragraph may carry.
        static constexpr int passivesPerParagraph = 2;

        /// Passive density ceiling, per thousand words of prose.
        static constexpr int passivePerThousandLimit = 34;

        /// Paragraphs carrying more passives than passivesPerParagraph.
        static std::vector<ProseFault> stackedPassives(const std::string &text);

        /// Passive constructions per thousand words of prose.
        static double passiveDensity(const std::string &text);
    };

}
