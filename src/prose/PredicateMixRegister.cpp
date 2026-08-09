#include "prose/PredicateMixRegister.h"

#include <regex>

namespace slm
{
    std::vector<std::pair<std::string, int>> PredicateMixRegister::predicateMix(
        const std::string &text)
    {
        const std::regex pastPassive("(mış|miş|muş|müş)t(ı|i)r$");
        const std::regex continuous("(makta|mekte)d(ı|i)r$");
        const std::regex copula("(dır|dir|dur|dür)$|"
                                "([pçtkfhsş])(tır|tir|tur|tür)$");
        const std::regex aorist("(ır|ir|ur|ür|ar|er)$");

        int past = 0;
        int present = 0;
        int isForm = 0;
        int does = 0;
        int total = 0;
        for (const std::string &sentence : ProseText::proseSentences(text))
        {
            const std::string tail = ProseText::finalWord(sentence);
            if (tail.empty())
            {
                continue;
            }
            ++total;
            if (std::regex_search(tail, pastPassive))
            {
                ++past;
            }
            else if (std::regex_search(tail, continuous))
            {
                ++present;
            }
            else if (std::regex_search(tail, copula))
            {
                ++isForm;
            }
            else if (std::regex_search(tail, aorist))
            {
                ++does;
            }
        }
        if (total == 0)
        {
            return {};
        }
        return {{"-mıştır", 100 * past / total},
                {"-maktadır", 100 * present / total},
                {"-dır", 100 * isForm / total},
                {"-ir", 100 * does / total}};
    }

}
