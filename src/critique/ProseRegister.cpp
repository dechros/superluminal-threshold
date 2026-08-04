#include "critique/ProseRegister.h"

#include "core/Report.h"

#include <algorithm>
#include <fstream>
#include <format>
#include <regex>
#include <sstream>

namespace slm
{
    namespace
    {
        const std::vector<std::string> kFirstPerson = {
            "rastlamadım", "sınamadım",  "ürettim",   "yazdım",   "kurdum",
            "karşılaştırdım", "etmiyorum", "almadım",  "çıkardım", "türetmedim",
            "buldum",     "gördüm",      "yaptım",    "ettim",    "biz ",
            "bize ",      "bizim ",      "çalışmamız", "makalemiz", "hesabımız",
            "bulamadığım", "seçtiğim", "kurduğum", "gördüğüm", "yaptığım",
            "yoruz", "iyoruz", "uyoruz", "üyoruz", "ıyoruz", "acağız", "eceğiz",
            "malıyız", "meliyiz"};

        const std::vector<std::string> kNotOurs = {"minimize", "Minimize", "temiz",
                                                   "Temiz", "vermiz"};

        const std::vector<std::string> kSelfReference = {
            "karıştırılmamalı", "abartılmamalı", "bırakılmamalı", "kaydedilmeli",
            "yazılmalı",        "belirtilmeli",  "unutulmamalı",  "gösterilmelidir",
            "okunmalıdır",      "sunulmamakta",  "vurgulanmalı",  "ayrılmalıdır",
            "sayılmamalı",      "tutulmalıdır",  "verilmelidir",
            "karıştırılmaması", "ayrılması gerekir", "karıştırılmamaları"};

        const std::vector<std::string> kPassive = {"mektedir", "maktadır", "mıştır",
                                                   "miştir",   "muştur",   "müştür"};

        const std::vector<std::string> kNominal = {"ması", "mesi", "dığı", "diği",
                                                   "tığı", "tiği", "acağı", "eceği"};

        struct SpokenNumber
        {
            bool back = false;
            bool voicelessFinal = false;
            bool vowelFinal = false;
            std::string harmony;
        };

        SpokenNumber spokenNumber(const std::string &digits, bool fraction)
        {
            static const std::vector<SpokenNumber> ones = {
                {true, false, false, "ı"},  {false, false, false, "i"},
                {false, false, true, "i"},  {false, true, false, "ü"},
                {false, true, false, "ü"},  {false, true, false, "i"},
                {true, false, true, "ı"},   {false, false, true, "i"},
                {false, false, false, "i"}, {true, false, false, "u"}};
            static const std::vector<SpokenNumber> tens = {
                {true, false, false, "u"},  {false, false, true, "i"},
                {true, false, false, "u"},  {true, true, false, "ı"},
                {false, false, true, "i"},  {true, true, false, "ı"},
                {false, true, false, "i"},  {false, false, false, "i"},
                {true, false, false, "ı"}};

            long long value = 0;
            for (const char character : digits)
            {
                if (character >= '0' && character <= '9')
                {
                    value = value * 10 + (character - '0');
                }
            }
            if (fraction || value % 10 != 0)
            {
                return ones[static_cast<std::size_t>(value % 10)];
            }
            if (value % 100 != 0)
            {
                return tens[static_cast<std::size_t>((value / 10) % 10) - 1];
            }
            if (value % 1000 != 0)
            {
                return {false, false, false, "ü"};
            }
            if (value % 1000000 != 0)
            {
                return {false, false, false, "i"};
            }
            return {true, false, false, "u"};
        }

        std::string agreeingSuffix(const std::string &number, const std::string &written,
                                   bool fraction)
        {
            const std::size_t dot = number.rfind('.');
            const SpokenNumber spoken =
                spokenNumber(dot == std::string::npos ? number : number.substr(dot + 1), fraction);

            const std::string low = spoken.back ? "a" : "e";
            const std::string stop = spoken.voicelessFinal ? "t" : "d";
            const std::string locative = stop + low;
            const std::string dative = spoken.vowelFinal ? "y" + low : low;
            const std::string accusative =
                spoken.vowelFinal ? "y" + spoken.harmony : spoken.harmony;
            const std::string genitive = spoken.vowelFinal
                                             ? "n" + spoken.harmony + "n"
                                             : spoken.harmony + "n";
            const std::string possessed =
                spoken.vowelFinal ? "s" + spoken.harmony : spoken.harmony;

            if (std::regex_match(written, std::regex("[dt][ae]ki")))
            {
                return locative + "ki";
            }
            if (std::regex_match(written, std::regex("[dt][ae]d(ı|i)r")))
            {
                return locative + (spoken.back ? "dır" : "dir");
            }
            if (std::regex_match(written, std::regex("[dt][ae]n")))
            {
                return locative + "n";
            }
            if (std::regex_match(written, std::regex("[dt][ae]")))
            {
                return locative;
            }
            if (std::regex_match(written, std::regex("y?[ae]")))
            {
                return dative;
            }
            if (std::regex_match(written, std::regex("n?(ı|i|u|ü)n")))
            {
                return genitive;
            }
            if (std::regex_match(written, std::regex("s(ı|i|u|ü)")))
            {
                return possessed;
            }
            if (std::regex_match(written, std::regex("y?(ı|i|u|ü)")))
            {
                return accusative;
            }
            return {};
        }

        bool isProse(const std::string &line)
        {
            if (line.empty())
            {
                return false;
            }
            const char first = line.front();
            return first != '|' && first != '#' && first != '>' &&
                   line.rfind("$$", 0) != 0 && !std::isdigit(static_cast<unsigned char>(first));
        }

        int wordCount(const std::string &s)
        {
            std::istringstream in(s);
            std::string word;
            int count = 0;
            while (in >> word)
            {
                ++count;
            }
            return count;
        }

        int commaCount(const std::string &s)
        {
            return static_cast<int>(std::count(s.begin(), s.end(), ','));
        }

        int occurrences(const std::string &haystack, const std::string &needle)
        {
            int count = 0;
            for (std::size_t at = haystack.find(needle); at != std::string::npos;
                 at = haystack.find(needle, at + 1))
            {
                ++count;
            }
            return count;
        }

        std::string shorten(const std::string &s, std::size_t width = 62)
        {
            std::string flat;
            bool space = false;
            for (char c : s)
            {
                if (c == '\n' || c == ' ')
                {
                    space = true;
                    continue;
                }
                if (space && !flat.empty())
                {
                    flat.push_back(' ');
                }
                space = false;
                flat.push_back(c);
            }
            return flat.size() <= width ? flat : flat.substr(0, width);
        }

        std::vector<std::string> splitLines(const std::string &text)
        {
            std::vector<std::string> lines;
            std::istringstream in(text);
            std::string line;
            while (std::getline(in, line))
            {
                lines.push_back(line);
            }
            return lines;
        }
    }

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

    std::vector<ProseRegister::Fault> ProseRegister::longSentences(const std::string &text)
    {
        std::vector<Fault> faults;
        const auto lines = splitLines(text);
        std::string sentence;
        int startLine = 1;
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!isProse(lines[index]))
            {
                sentence.clear();
                continue;
            }
            if (sentence.empty())
            {
                startLine = static_cast<int>(index) + 1;
            }
            sentence += " " + lines[index];
            const std::size_t stop = sentence.find_last_of('.');
            if (stop == std::string::npos)
            {
                continue;
            }
            const std::string done = sentence.substr(0, stop + 1);
            const int words = wordCount(done);
            if (words > sentenceWordLimit && commaCount(done) < 4)
            {
                faults.push_back({"uzun cümle", startLine, shorten(done)});
            }
            sentence = sentence.substr(stop + 1);
            startLine = static_cast<int>(index) + 1;
        }
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::stackedPassives(const std::string &text)
    {
        std::vector<Fault> faults;
        const auto lines = splitLines(text);
        std::string paragraph;
        int startLine = 1;
        const auto flush = [&]()
        {
            if (paragraph.empty())
            {
                return;
            }
            int total = 0;
            for (const auto &mark : kPassive)
            {
                total += occurrences(paragraph, mark);
            }
            if (total > passivesPerParagraph)
            {
                faults.push_back({std::format("{} edilgen", total), startLine,
                                  shorten(paragraph)});
            }
            paragraph.clear();
        };
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!isProse(lines[index]))
            {
                flush();
                continue;
            }
            if (paragraph.empty())
            {
                startLine = static_cast<int>(index) + 1;
            }
            paragraph += " " + lines[index];
        }
        flush();
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::firstPerson(const std::string &text)
    {
        std::vector<Fault> faults;
        const auto lines = splitLines(text);
        const std::regex ours(
            "[a-zçğıöşüA-ZÇĞİÖŞÜ]+(mız|miz|muz|müz)"
            "(ı|i|u|ü|a|e|la|le|da|de|dan|den|ın|in|un|ün|dır|dir|dur|dür)?"
            "(?![a-zA-ZçğıöşüÇĞİÖŞÜ])");
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            bool marked = false;
            for (const auto &mark : kFirstPerson)
            {
                if (lines[index].find(mark) != std::string::npos)
                {
                    faults.push_back({"birinci şahıs", static_cast<int>(index) + 1,
                                      shorten(lines[index])});
                    marked = true;
                    break;
                }
            }
            if (marked)
            {
                continue;
            }
            for (std::sregex_iterator it(lines[index].begin(), lines[index].end(), ours),
                 stop; it != stop; ++it)
            {
                if (std::find(kNotOurs.begin(), kNotOurs.end(), (*it)[0].str()) ==
                    kNotOurs.end())
                {
                    faults.push_back({"birinci şahıs çoğul iyelik",
                                      static_cast<int>(index) + 1, (*it)[0].str()});
                    break;
                }
            }
        }
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::selfReference(const std::string &text)
    {
        std::vector<Fault> faults;
        const auto lines = splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            for (const auto &mark : kSelfReference)
            {
                if (lines[index].find(mark) != std::string::npos)
                {
                    faults.push_back({"metin kendinden bahsediyor",
                                      static_cast<int>(index) + 1, shorten(lines[index])});
                    break;
                }
            }
        }
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::openingConjunctions(
        const std::string &text)
    {
        std::vector<Fault> faults;
        const auto lines = splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!isProse(lines[index]))
            {
                continue;
            }
            for (const auto &mark : {". Ve ", ". Ama ", ". Ki "})
            {
                if (lines[index].find(mark) != std::string::npos)
                {
                    faults.push_back({"cümle bağlaçla açılıyor",
                                      static_cast<int>(index) + 1, shorten(lines[index])});
                    break;
                }
            }
            if (lines[index].rfind("Ve ", 0) == 0 || lines[index].rfind("Ama ", 0) == 0)
            {
                faults.push_back({"cümle bağlaçla açılıyor", static_cast<int>(index) + 1,
                                  shorten(lines[index])});
            }
        }
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::nominalChains(const std::string &text)
    {
        std::vector<Fault> faults;
        const auto lines = splitLines(text);
        std::string sentence;
        int startLine = 1;
        const auto examine = [&](const std::string &done, int line)
        {
            int total = 0;
            for (const auto &mark : kNominal)
            {
                total += occurrences(done, mark);
            }
            if (total > nominalsPerSentence && commaCount(done) < 3)
            {
                faults.push_back({std::format("{} ad-fiil", total), line, shorten(done)});
            }
        };
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!isProse(lines[index]))
            {
                sentence.clear();
                continue;
            }
            if (sentence.empty())
            {
                startLine = static_cast<int>(index) + 1;
            }
            sentence += " " + lines[index];
            const std::size_t stop = sentence.find_last_of('.');
            if (stop == std::string::npos)
            {
                continue;
            }
            examine(sentence.substr(0, stop + 1), startLine);
            sentence = sentence.substr(stop + 1);
            startLine = static_cast<int>(index) + 1;
        }
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::numberSuffixes(const std::string &text)
    {
        std::vector<Fault> faults;
        const std::regex pattern("([0-9]+(?:\\.[0-9]+)*)[\\]$}]*'([a-zçğıöşü]+)");
        const auto lines = splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            for (std::sregex_iterator it(lines[index].begin(), lines[index].end(), pattern),
                 stop; it != stop; ++it)
            {
                const std::string written = (*it)[2].str();
                const std::size_t start = static_cast<std::size_t>(it->position(1));
                const bool fraction =
                    start > 0 && (lines[index][start - 1] == '}' ||
                                  lines[index][start - 1] == ',');
                const std::string wanted = agreeingSuffix((*it)[1].str(), written, fraction);
                if (!wanted.empty() && wanted != written)
                {
                    faults.push_back({"sayı eki uyumsuz",
                                      static_cast<int>(index) + 1,
                                      (*it)[0].str() + " -> '" + wanted});
                }
            }
        }
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::emDashes(const std::string &text)
    {
        std::vector<Fault> faults;
        const auto lines = splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (lines[index].find("\xe2\x80\x94") != std::string::npos)
            {
                faults.push_back({"uzun tire", static_cast<int>(index) + 1,
                                  shorten(lines[index])});
            }
        }
        return faults;
    }

    std::vector<ProseRegister::Fault> ProseRegister::faults(const std::string &text)
    {
        std::vector<Fault> all;
        for (const auto &group : {longSentences(text), stackedPassives(text),
                                  firstPerson(text), selfReference(text),
                                  openingConjunctions(text), nominalChains(text),
                                  numberSuffixes(text), emDashes(text)})
        {
            all.insert(all.end(), group.begin(), group.end());
        }
        return all;
    }

    void ProseRegisterSection::run(Report &report) const
    {
        const std::string document = ProseRegister::text();

        report.subsection("The manuscript has to be there to be measured");
        report.check("the text was opened and is not empty", !document.empty());
        if (document.empty())
        {
            return;
        }

        report.subsection("First person, which this register does not allow");
        const auto persons = ProseRegister::firstPerson(document);
        for (const auto &fault : persons)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("no sentence is written in the first person, singular or plural, and the "
                     "work is not called ours",
                     persons.empty());

        report.subsection("The text discussing the text");
        const auto selves = ProseRegister::selfReference(document);
        for (const auto &fault : selves)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("no sentence instructs the reader about the document instead of stating "
                     "the claim it was wrapping",
                     selves.empty());

        report.subsection("Sentence length, measured against Turkish prose of this kind");
        const auto longs = ProseRegister::longSentences(document);
        for (const auto &fault : longs)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check(std::format("no sentence passes {} words unless it is carrying a list",
                                 ProseRegister::sentenceWordLimit),
                     longs.empty());

        report.subsection("Passives, which are allowed but may not stack");
        const auto stacked = ProseRegister::stackedPassives(document);
        for (const auto &fault : stacked)
        {
            report.check(std::format("  line {}: {} | {}", fault.line, fault.rule,
                                     fault.excerpt),
                         false);
        }
        report.check(std::format("no paragraph carries more than {} passive constructions, "
                                 "past which nothing in it has a subject",
                                 ProseRegister::passivesPerParagraph),
                     stacked.empty());

        report.subsection("Sentences opening with a bare conjunction");
        const auto openers = ProseRegister::openingConjunctions(document);
        for (const auto &fault : openers)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("no sentence begins with a conjunction, which is how breaking a long "
                     "sentence turns written Turkish into spoken Turkish",
                     openers.empty());

        report.subsection("Chains of verbal nouns, the fault the other rules leave behind");
        const auto chains = ProseRegister::nominalChains(document);
        for (const auto &fault : chains)
        {
            report.check(std::format("  line {}: {} | {}", fault.line, fault.rule,
                                     fault.excerpt),
                         false);
        }
        report.check(std::format("no sentence carries more than {} verbal nouns unless it is "
                                 "an enumeration",
                                 ProseRegister::nominalsPerSentence),
                     chains.empty());

        report.subsection("Suffixes agreeing with how a number is read");
        const auto suffixes = ProseRegister::numberSuffixes(document);
        for (const auto &fault : suffixes)
        {
            report.check(std::format("  line {}: {}", fault.line, fault.excerpt), false);
        }
        report.check("every reference takes the possessive ending its number takes when it "
                     "is said aloud, which the digit alone does not decide",
                     suffixes.empty());

        report.subsection("The house rule on the em dash");
        report.check("the em dash appears nowhere", ProseRegister::emDashes(document).empty());

        report.subsection("What this section still does not measure");
        report.check("word order inside a clause, and whether a paragraph argues in the order a "
                     "reader needs, are not counted anywhere here, so a green run is not a "
                     "certificate that the prose reads well",
                     true);
    }

}
