#include "prose/NominalChainRegister.h"

#include <format>

namespace slm
{
    namespace
    {
        const std::vector<std::string> kNominal = {"ması", "mesi", "dığı", "diği",
                                                   "tığı", "tiği", "acağı", "eceği"};
    }

    std::vector<ProseFault> NominalChainRegister::nominalChains(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        std::string sentence;
        int startLine = 1;
        const auto examine = [&](const std::string &done, int line)
        {
            int total = 0;
            for (const auto &mark : kNominal)
            {
                total += ProseText::occurrences(done, mark);
            }
            if (total > nominalsPerSentence && ProseText::commaCount(done) < 3)
            {
                faults.push_back({std::format("{} ad-fiil", total), line,
                                  ProseText::shorten(done)});
            }
        };
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!ProseText::isProse(lines[index]))
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

}
