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
            "bize ",      "bizim ",      "çalışmamız", "makalemiz", "hesabımız"};

        const std::vector<std::string> kSelfReference = {
            "karıştırılmamalı", "abartılmamalı", "bırakılmamalı", "kaydedilmeli",
            "yazılmalı",        "belirtilmeli",  "unutulmamalı",  "gösterilmelidir",
            "okunmalıdır",      "sunulmamakta",  "vurgulanmalı",  "ayrılmalıdır",
            "sayılmamalı",      "tutulmalıdır",  "verilmelidir",
            "karıştırılmaması", "ayrılması gerekir"};

        const std::vector<std::string> kPassive = {"mektedir", "maktadır", "mıştır",
                                                   "miştir",   "muştur",   "müştür"};

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
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            for (const auto &mark : kFirstPerson)
            {
                if (lines[index].find(mark) != std::string::npos)
                {
                    faults.push_back({"birinci şahıs", static_cast<int>(index) + 1,
                                      shorten(lines[index])});
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
                                  firstPerson(text), selfReference(text), emDashes(text)})
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

        report.subsection("The house rule on the em dash");
        report.check("the em dash appears nowhere", ProseRegister::emDashes(document).empty());

        report.subsection("What this section does not measure");
        report.check("chains of nominalisation are the remaining fault of this register and no "
                     "count here detects them, so the absence of failures above is not a "
                     "certificate that the prose reads well",
                     true);
    }

}
