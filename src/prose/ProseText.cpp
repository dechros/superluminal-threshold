#include "prose/ProseText.h"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace slm
{
    bool ProseText::isProse(const std::string &line)
    {
        if (line.empty())
        {
            return false;
        }
        const char first = line.front();
        return first != '|' && first != '#' && first != '>' &&
               line.rfind("$$", 0) != 0 && !std::isdigit(static_cast<unsigned char>(first));
    }

    int ProseText::wordCount(const std::string &s)
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

    int ProseText::commaCount(const std::string &s)
    {
        return static_cast<int>(std::count(s.begin(), s.end(), ','));
    }

    int ProseText::occurrences(const std::string &haystack, const std::string &needle)
    {
        int count = 0;
        for (std::size_t at = haystack.find(needle); at != std::string::npos;
             at = haystack.find(needle, at + 1))
        {
            ++count;
        }
        return count;
    }

    std::string ProseText::shorten(const std::string &s, std::size_t width)
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

    std::vector<std::string> ProseText::splitLines(const std::string &text)
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

    std::string ProseText::trimmed(const std::string &s)
    {
        const std::size_t from = s.find_first_not_of(" \t\r");
        if (from == std::string::npos)
        {
            return {};
        }
        const std::size_t to = s.find_last_not_of(" \t\r");
        return s.substr(from, to - from + 1);
    }

    std::vector<std::string> ProseText::proseSentences(const std::string &text)
    {
        std::vector<std::string> out;
        std::string paragraph;
        bool insideMath = false;
        const auto flush = [&out, &paragraph]() {
            std::string current;
            for (std::size_t at = 0; at < paragraph.size(); ++at)
            {
                current.push_back(paragraph[at]);
                const bool stop = paragraph[at] == '.' || paragraph[at] == '!' ||
                                  paragraph[at] == '?';
                if (stop && (at + 1 == paragraph.size() || paragraph[at + 1] == ' '))
                {
                    if (current.size() > 12)
                    {
                        out.push_back(current);
                    }
                    current.clear();
                }
            }
            paragraph.clear();
        };
        for (const std::string &line : splitLines(text))
        {
            const std::string flat = trimmed(line);
            if (flat == "$$")
            {
                insideMath = !insideMath;
                continue;
            }
            if (insideMath || !isProse(flat))
            {
                flush();
                continue;
            }
            paragraph += (paragraph.empty() ? "" : " ") + flat;
        }
        flush();
        return out;
    }

    std::string ProseText::finalWord(const std::string &sentence)
    {
        std::istringstream in(sentence);
        std::string word;
        std::string last;
        while (in >> word)
        {
            last = word;
        }
        while (!last.empty() && std::string(".,;:!?*)").find(last.back()) != std::string::npos)
        {
            last.pop_back();
        }
        return last;
    }

}
