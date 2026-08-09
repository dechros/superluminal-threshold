#include "prose/SentenceLengthRegister.h"

namespace slm
{
    std::vector<ProseFault> SentenceLengthRegister::longSentences(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        std::string sentence;
        int startLine = 1;
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
            const std::string done = sentence.substr(0, stop + 1);
            const int words = ProseText::wordCount(done);
            if (words > wordLimit && ProseText::commaCount(done) < 4)
            {
                faults.push_back({"uzun cümle", startLine, ProseText::shorten(done)});
            }
            sentence = sentence.substr(stop + 1);
            startLine = static_cast<int>(index) + 1;
        }
        return faults;
    }

}
