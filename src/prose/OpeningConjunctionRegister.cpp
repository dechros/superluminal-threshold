#include "prose/OpeningConjunctionRegister.h"

namespace slm
{
    std::vector<ProseFault> OpeningConjunctionRegister::openingConjunctions(
        const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            if (!ProseText::isProse(lines[index]))
            {
                continue;
            }
            for (const auto &mark : {". Ve ", ". Ama ", ". Ki "})
            {
                if (lines[index].find(mark) != std::string::npos)
                {
                    faults.push_back({"cümle bağlaçla açılıyor",
                                      static_cast<int>(index) + 1,
                                      ProseText::shorten(lines[index])});
                    break;
                }
            }
            if (lines[index].rfind("Ve ", 0) == 0 || lines[index].rfind("Ama ", 0) == 0)
            {
                faults.push_back({"cümle bağlaçla açılıyor", static_cast<int>(index) + 1,
                                  ProseText::shorten(lines[index])});
            }
        }
        return faults;
    }

}
