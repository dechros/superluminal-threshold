#pragma once

#include "core/Section.h"
#include "prose/FirstPersonRegister.h"
#include "prose/HeadingRegister.h"
#include "prose/NominalChainRegister.h"
#include "prose/NumberSuffixAgreement.h"
#include "prose/OpeningConjunctionRegister.h"
#include "prose/PassiveVoiceRegister.h"
#include "prose/PredicateMixRegister.h"
#include "prose/ProseText.h"
#include "prose/SelfReferenceRegister.h"
#include "prose/SentenceLengthRegister.h"
#include "prose/TypographyRegister.h"

#include <string>
#include <vector>

namespace slm
{

    /// Measurable rules for the register a Turkish scientific text is written
    /// in, gathered from the article file and folded into one list.
    ///
    /// Each rule is a number, so a text can be held to it instead of argued
    /// about, and each rule is owned by its own class under the prose folder.
    /// The rules come from the conventions Turkish journals state for
    /// scientific prose and from measuring prose accepted as well written in
    /// that language. This class opens the file the rules are measured
    /// against and combines their findings; it states no rule of its own.
    class ProseRegister
    {
    public:
        /// The text under review, or an empty string when it cannot be
        /// opened.
        static std::string text();

        /// Every fault the rules below find, in one list: sentence length,
        /// stacked passives, first person, self-reference, opening
        /// conjunctions, nominal chains, number suffixes, the em dash and the
        /// decimal point. Excluded are verbal headings, the heading length
        /// mean, the predicate mix and the passive density, each of which is
        /// reported as a measurement rather than as a list of faults.
        static std::vector<ProseFault> faults(const std::string &text);
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
