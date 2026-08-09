#include "critique/DocumentIntegrity.h"

#include <algorithm>
#include <sstream>

namespace slm
{
    namespace
    {
        std::vector<std::string> lines(const std::string &text)
        {
            std::vector<std::string> result;
            std::istringstream stream(text);
            std::string line;
            while (std::getline(stream, line))
            {
                if (!line.empty() && line.back() == '\r')
                {
                    line.pop_back();
                }
                result.push_back(line);
            }
            return result;
        }
    }

    int DocumentIntegrity::controlCharacters(const std::string &text)
    {
        int count = 0;
        for (unsigned char character : text)
        {
            if (character < 0x20 && character != static_cast<unsigned char>('\n'))
            {
                ++count;
            }
        }
        return count;
    }

    std::vector<int> DocumentIntegrity::splitMacros(const std::string &text)
    {
        std::vector<int> places;
        const auto rows = lines(text);
        for (std::size_t index = 0; index < rows.size(); ++index)
        {
            std::string row = rows[index];
            while (!row.empty() && (row.back() == '\r' || row.back() == ' '))
            {
                row.pop_back();
            }
            if (row.size() >= 2 && row.back() == '\\' && row[row.size() - 2] != '\\')
            {
                places.push_back(static_cast<int>(index) + 1);
            }
        }
        return places;
    }

    bool DocumentIntegrity::carriesTitle(const std::string &text)
    {
        for (const std::string &line : lines(text))
        {
            if (line.empty())
            {
                continue;
            }
            return line.rfind("# ", 0) == 0 && line.rfind("## ", 0) != 0 && line.size() > 8;
        }
        return false;
    }

    std::vector<std::string> DocumentIntegrity::appendixReferencesOutsideIt(
        const std::string &text)
    {
        const auto all = lines(text);
        std::size_t opensAt = all.size();
        std::vector<std::pair<std::string, std::size_t>> placed;
        for (std::size_t index = 0; index < all.size(); ++index)
        {
            const std::string &line = all[index];
            if (line.rfind("# ", 0) == 0 && line.rfind("## ", 0) != 0 &&
                opensAt == all.size() && line.find("Ek") != std::string::npos)
            {
                opensAt = index;
            }
            if (line.rfind("## ", 0) == 0)
            {
                const std::size_t dot = line.find('.');
                if (dot != std::string::npos && dot > 3)
                {
                    placed.emplace_back(line.substr(3, dot - 3), index);
                }
            }
        }

        std::vector<std::string> wrong;
        for (const std::string &line : all)
        {
            std::size_t at = line.find("Ek ");
            while (at != std::string::npos)
            {
                std::size_t end = at + 3;
                while (end < line.size() && line[end] >= '0' && line[end] <= '9')
                {
                    ++end;
                }
                if (end > at + 3)
                {
                    const std::string wanted = line.substr(at + 3, end - at - 3);
                    for (const auto &entry : placed)
                    {
                        if (entry.first == wanted && entry.second < opensAt &&
                            std::find(wrong.begin(), wrong.end(), wanted) == wrong.end())
                        {
                            wrong.push_back(wanted);
                        }
                    }
                }
                at = line.find("Ek ", end);
            }
        }
        return wrong;
    }

}
