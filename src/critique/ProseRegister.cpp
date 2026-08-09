#include "critique/ProseRegister.h"

#include "core/Report.h"

#include <fstream>
#include <format>
#include <sstream>

namespace slm
{
    std::string ProseRegister::text()
    {
        std::ifstream file("article/article.md", std::ios::binary);
        if (!file)
        {
            return {};
        }
        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    std::vector<ProseFault> ProseRegister::faults(const std::string &text)
    {
        std::vector<ProseFault> all;
        for (const auto &group : {SentenceLengthRegister::longSentences(text),
                                  PassiveVoiceRegister::stackedPassives(text),
                                  FirstPersonRegister::firstPerson(text),
                                  SelfReferenceRegister::selfReference(text),
                                  OpeningConjunctionRegister::openingConjunctions(text),
                                  NominalChainRegister::nominalChains(text),
                                  NumberSuffixAgreement::numberSuffixes(text),
                                  TypographyRegister::emDashes(text),
                                  TypographyRegister::decimalPoints(text)})
        {
            all.insert(all.end(), group.begin(), group.end());
        }
        return all;
    }

    void ProseRegisterSection::run(Report &report) const
    {
        const std::string document = ProseRegister::text();

        report.subsection("The text has to be there to be measured");
        report.check("the text was opened and is not empty", !document.empty());
        if (document.empty())
        {
            return;
        }

        report.subsection("First person, which this register does not allow");
        const auto persons = FirstPersonRegister::firstPerson(document);
        for (const auto &fault : persons)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("no sentence is written in the first person, singular or plural, and the "
                     "work is not spoken of as the writer's own",
                     persons.empty());

        report.subsection("The text discussing the text");
        const auto selves = SelfReferenceRegister::selfReference(document);
        for (const auto &fault : selves)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("no sentence instructs the reader about the document instead of stating "
                     "the claim it was wrapping",
                     selves.empty());

        report.subsection("Sentence length, measured against Turkish prose of this kind");
        const auto longs = SentenceLengthRegister::longSentences(document);
        for (const auto &fault : longs)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check(std::format("no sentence passes {} words unless it is carrying a list",
                                 SentenceLengthRegister::wordLimit),
                     longs.empty());

        report.subsection("Passives, which are allowed but may not stack");
        const auto stacked = PassiveVoiceRegister::stackedPassives(document);
        for (const auto &fault : stacked)
        {
            report.check(std::format("  line {}: {} | {}", fault.line, fault.rule,
                                     fault.excerpt),
                         false);
        }
        report.check(std::format("no paragraph carries more than {} passive constructions, "
                                 "past which nothing in it has a subject",
                                 PassiveVoiceRegister::passivesPerParagraph),
                     stacked.empty());

        report.subsection("Sentences opening with a bare conjunction");
        const auto openers = OpeningConjunctionRegister::openingConjunctions(document);
        for (const auto &fault : openers)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("no sentence begins with a conjunction, which is how breaking a long "
                     "sentence turns written Turkish into spoken Turkish",
                     openers.empty());

        report.subsection("Chains of verbal nouns, the fault the other rules leave behind");
        const auto chains = NominalChainRegister::nominalChains(document);
        for (const auto &fault : chains)
        {
            report.check(std::format("  line {}: {} | {}", fault.line, fault.rule,
                                     fault.excerpt),
                         false);
        }
        report.check(std::format("no sentence carries more than {} verbal nouns unless it is "
                                 "an enumeration",
                                 NominalChainRegister::nominalsPerSentence),
                     chains.empty());

        report.subsection("Suffixes agreeing with how a number is read");
        const auto suffixes = NumberSuffixAgreement::numberSuffixes(document);
        for (const auto &fault : suffixes)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("every reference takes the possessive ending its number takes when it "
                     "is said aloud, which the digit alone does not decide",
                     suffixes.empty());

        report.subsection("Headings that name rather than assert");
        const auto headings = HeadingRegister::verbalHeadings(document);
        for (const auto &fault : headings)
        {
            report.check(std::format("  line {}: {} ({})", fault.line, fault.excerpt,
                                     fault.rule),
                         false);
        }
        report.check("every heading is a noun phrase, which is what the two hundred and "
                     "thirty eight headings of the measured corpus are",
                     headings.empty());
        report.check(std::format("  the headings average {}.{} words, at most {}.{}, against a "
                                 "corpus median of three",
                                 HeadingRegister::headingWordMean(document) / 10,
                                 HeadingRegister::headingWordMean(document) % 10,
                                 HeadingRegister::meanTenths / 10,
                                 HeadingRegister::meanTenths % 10),
                     HeadingRegister::headingWordMean(document) <= HeadingRegister::meanTenths);

        report.subsection("The mix of predicate forms, which a drifting text concentrates");
        const auto mix = PredicateMixRegister::predicateMix(document);
        for (const auto &form : mix)
        {
            report.check(std::format("  {} carries {}% of the sentence endings",
                                     form.first, form.second),
                         true);
        }
        int copula = 0;
        int continuous = 0;
        int aorist = 0;
        int pastPassive = 0;
        for (const auto &form : mix)
        {
            if (form.first == "-dır")
            {
                copula = form.second;
            }
            if (form.first == "-maktadır")
            {
                continuous = form.second;
            }
            if (form.first == "-ir")
            {
                aorist = form.second;
            }
            if (form.first == "-mıştır")
            {
                pastPassive = form.second;
            }
        }
        report.check(std::format("the copula carries {}% of the endings, at most {}",
                                 copula, PredicateMixRegister::copulaShareLimit),
                     copula <= PredicateMixRegister::copulaShareLimit);
        report.check(std::format("the aorist carries {}%, at most {}, so a finding is not "
                                 "always stated as a timeless law",
                                 aorist, PredicateMixRegister::aoristShareLimit),
                     aorist <= PredicateMixRegister::aoristShareLimit);
        report.check(std::format("the present continuous carries {}%, at least {}",
                                 continuous, PredicateMixRegister::continuousShareFloor),
                     continuous >= PredicateMixRegister::continuousShareFloor);
        report.check(std::format("the reported past carries {}%, at least {}, which is the form "
                                 "a completed operation takes",
                                 pastPassive, PredicateMixRegister::pastPassiveShareFloor),
                     pastPassive >= PredicateMixRegister::pastPassiveShareFloor);

        report.subsection("Passive density, which a per-paragraph cap cannot see");
        const double density = PassiveVoiceRegister::passiveDensity(document);
        report.check(std::format("the prose carries {:.1f} passives per thousand words, "
                                 "at most {}",
                                 density, PassiveVoiceRegister::passivePerThousandLimit),
                     density <= PassiveVoiceRegister::passivePerThousandLimit);

        report.subsection("The house rule on the em dash");
        report.check("the em dash appears nowhere", TypographyRegister::emDashes(document).empty());
        report.check("every number inside mathematics carries a comma for its decimal "
                     "separator, the way the text reads it aloud",
                     TypographyRegister::decimalPoints(document).empty());

        report.subsection("What this section still does not measure");
        report.check("word order inside a clause, and whether a paragraph argues in the order a "
                     "reader needs, are not counted anywhere here, so a green run is not a "
                     "certificate that the prose reads well",
                     true);
    }

}
