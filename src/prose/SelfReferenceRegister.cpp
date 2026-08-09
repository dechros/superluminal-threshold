#include "prose/SelfReferenceRegister.h"

namespace slm
{
    namespace
    {
        const std::vector<std::string> kSelfReference = {
            "karıştırılmamalı", "abartılmamalı", "bırakılmamalı", "kaydedilmeli",
            "yazılmalı",        "belirtilmeli",  "unutulmamalı",  "gösterilmelidir",
            "okunmalıdır",      "sunulmamakta",  "vurgulanmalı",  "ayrılmalıdır",
            "sayılmamalı",      "tutulmalıdır",  "verilmelidir",
            "karıştırılmaması", "ayrılması gerekir", "karıştırılmamaları"};
    }

    std::vector<ProseFault> SelfReferenceRegister::selfReference(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            for (const auto &mark : kSelfReference)
            {
                if (lines[index].find(mark) != std::string::npos)
                {
                    faults.push_back({"metin kendinden bahsediyor",
                                      static_cast<int>(index) + 1,
                                      ProseText::shorten(lines[index])});
                    break;
                }
            }
        }
        return faults;
    }

}
