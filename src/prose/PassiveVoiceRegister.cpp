#include "prose/PassiveVoiceRegister.h"

#include <algorithm>
#include <format>
#include <regex>
#include <sstream>

namespace slm
{
    namespace
    {
        const std::vector<std::string> kPassive = {"mektedir", "maktadır", "mıştır",
                                                    "miştir",   "muştur",   "müştür"};

        int passiveCount(const std::string &text)
        {
            static const std::regex passive(
                "(^|[^a-zçğıöşü])([a-zçğıöşü]{2,})(ıl|il|ul|ül|[aeıioöuü]n)"
                "(mış|miş|muş|müş|makta|mekte|ır|ir|ur|ür)"
                "(tır|tir|tur|tür|dır|dir|dur|dür)?([^a-zçğıöşü]|$)");
            static const std::regex ability("(abil|ebil)$");
            static const std::regex ablative("(den|dan)$");
            static const std::vector<std::string> lexical = {
                "kullanır", "tükenir", "bulunur", "görünür", "bilinir", "dayanır",
                "uzanır", "inanır", "değildir", "kalınır", "sunar"};

            int hits = 0;
            for (std::sregex_iterator it(text.begin(), text.end(), passive), stop;
                 it != stop; ++it)
            {
                const std::string base = (*it)[2].str() + (*it)[3].str();
                std::string word = base + (*it)[4].str() + (*it)[5].str();
                if (std::regex_search(base, ability) || std::regex_search(base, ablative))
                {
                    continue;
                }
                if (std::find(lexical.begin(), lexical.end(), word) != lexical.end())
                {
                    continue;
                }
                ++hits;
            }
            return hits;
        }
    }

    std::vector<ProseFault> PassiveVoiceRegister::stackedPassives(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        std::string paragraph;
        int startLine = 1;
        const auto flush = [&]()
        {
            if (paragraph.empty())
            {
                return;
            }
            const int total = passiveCount(paragraph);
            if (total > passivesPerParagraph)
            {
                faults.push_back({std::format("{} edilgen", total), startLine,
                                  ProseText::shorten(paragraph)});
            }
            paragraph.clear();
        };
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!ProseText::isProse(lines[index]))
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

    double PassiveVoiceRegister::passiveDensity(const std::string &text)
    {
        int words = 0;
        int hits = 0;
        for (const std::string &sentence : ProseText::proseSentences(text))
        {
            std::istringstream in(sentence);
            std::string word;
            while (in >> word)
            {
                ++words;
            }
            hits += passiveCount(sentence);
        }
        return words == 0 ? 0.0 : 1000.0 * hits / words;
    }

}
