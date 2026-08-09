#include "prose/TypographyRegister.h"

#include <cctype>

namespace slm
{
    std::vector<ProseFault> TypographyRegister::emDashes(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (lines[index].find("\xe2\x80\x94") != std::string::npos)
            {
                faults.push_back({"uzun tire", static_cast<int>(index) + 1,
                                  ProseText::shorten(lines[index])});
            }
        }
        return faults;
    }

    std::vector<ProseFault> TypographyRegister::decimalPoints(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            const std::string &line = lines[index];
            bool inside = false;
            bool found = false;
            for (std::size_t i = 0; i < line.size() && !found; ++i)
            {
                if (line[i] == '$')
                {
                    inside = !inside;
                    continue;
                }
                if (!inside || line[i] != '.' || i == 0 || i + 1 >= line.size())
                {
                    continue;
                }
                if (std::isdigit(static_cast<unsigned char>(line[i - 1])) != 0 &&
                    std::isdigit(static_cast<unsigned char>(line[i + 1])) != 0)
                {
                    found = true;
                }
            }
            if (found)
            {
                faults.push_back({"ondalik nokta", static_cast<int>(index) + 1,
                                  ProseText::shorten(line)});
            }
        }
        return faults;
    }

}
