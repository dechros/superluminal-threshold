#include "prose/HeadingRegister.h"

#include <algorithm>
#include <regex>
#include <sstream>

namespace slm
{
    std::vector<ProseFault> HeadingRegister::verbalHeadings(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const std::regex opener("^#{1,3} ");
        const std::regex label("^#{1,3} [0-9IVX.]*[.]?[ ]*");
        const std::regex finite("(dır|dir|dur|dür|tır|tir|maz|mez|yor|acak|ecek|ıyor|iyor|"
                                "sın|sin|mıştır|miştir)$");
        static const std::vector<std::string> aorist = {
            "ulaşır", "belirler", "görür", "çıkar", "verir", "kalır", "artar",
            "azalır", "döner", "değişir", "gider", "gelir", "olur", "yapar",
            "taşır", "bırakır", "kurar", "geçer", "düşer", "biter", "başlar",
            "ölçer", "sağlar", "gerektirir", "içerir", "eder", "kaybeder"};
        const auto lines = ProseText::splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!std::regex_search(lines[index], opener))
            {
                continue;
            }
            const std::string name = std::regex_replace(lines[index], label, "");
            const int line = static_cast<int>(index) + 1;
            if (name.find(':') != std::string::npos)
            {
                faults.push_back({"başlıkta iki nokta", line, name});
                continue;
            }
            if (name.find('?') != std::string::npos)
            {
                faults.push_back({"başlıkta soru", line, name});
                continue;
            }
            std::istringstream words(name);
            std::string word;
            int count = 0;
            bool asserted = false;
            while (words >> word)
            {
                ++count;
                std::string plain = word;
                while (!plain.empty() &&
                       std::string(".,;:!?*").find(plain.back()) != std::string::npos)
                {
                    plain.pop_back();
                }
                if (std::regex_search(plain, finite) ||
                    std::find(aorist.begin(), aorist.end(), plain) != aorist.end())
                {
                    faults.push_back({"başlıkta çekimli fiil", line, name});
                    asserted = true;
                    break;
                }
            }
            if (!asserted && count > wordLimit)
            {
                faults.push_back({"başlık çok uzun", line, name});
            }
        }
        return faults;
    }

    int HeadingRegister::headingWordMean(const std::string &text)
    {
        const std::regex label("^#{1,3} [0-9IVX.]*[.]?[ ]*");
        int headings = 0;
        int words = 0;
        for (const std::string &line : ProseText::splitLines(text))
        {
            if (line.rfind('#', 0) != 0)
            {
                continue;
            }
            const std::string name = std::regex_replace(line, label, "");
            if (name.empty())
            {
                continue;
            }
            ++headings;
            std::istringstream in(name);
            std::string word;
            while (in >> word)
            {
                ++words;
            }
        }
        return headings == 0 ? 0 : 10 * words / headings;
    }

}
