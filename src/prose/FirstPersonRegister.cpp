#include "prose/FirstPersonRegister.h"

#include <algorithm>
#include <regex>

namespace slm
{
    namespace
    {
        const std::vector<std::string> kFirstPerson = {
            "rastlamadım", "sınamadım",  "ürettim",   "yazdım",   "kurdum",
            "karşılaştırdım", "etmiyorum", "almadım",  "çıkardım", "türetmedim",
            "buldum",     "gördüm",      "yaptım",    "ettim",    "biz ",
            "bize ",      "bizim ",      "çalışmamız", "makalemiz", "hesabımız",
            "bulamadığım", "seçtiğim", "kurduğum", "gördüğüm", "yaptığım",
            "yoruz", "iyoruz", "uyoruz", "üyoruz", "ıyoruz", "acağız", "eceğiz",
            "malıyız", "meliyiz"};

        const std::vector<std::string> kNotPossessive = {"minimize", "Minimize",
                                                         "temiz", "Temiz"};
    }

    std::vector<ProseFault> FirstPersonRegister::firstPerson(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const auto lines = ProseText::splitLines(text);
        const std::regex possessive(
            "[a-zçğıöşüA-ZÇĞİÖŞÜ]+(mız|miz|muz|müz)"
            "(ı|i|u|ü|a|e|la|le|da|de|dan|den|ın|in|un|ün|dır|dir|dur|dür)?"
            "(?![a-zA-ZçğıöşüÇĞİÖŞÜ])");
        const std::regex plural("[a-zçğıöşü]+(ırız|iriz|uruz|ürüz|arız|eriz|ayız|eyiz)"
                                "(?![a-zA-ZçğıöşüÇĞİÖŞÜ])");
        const std::regex reader("(^|[^a-zA-ZçğıöşüÇĞİÖŞÜ])"
                               "([a-zçğıöşü]*(sınız|siniz|sunuz|sünüz|sanız|seniz)|siz|sizin|size)"
                               "(?![a-zA-ZçğıöşüÇĞİÖŞÜ])");
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            bool marked = false;
            for (const auto &mark : kFirstPerson)
            {
                if (lines[index].find(mark) != std::string::npos)
                {
                    faults.push_back({"birinci şahıs", static_cast<int>(index) + 1,
                                      ProseText::shorten(lines[index])});
                    marked = true;
                    break;
                }
            }
            if (marked)
            {
                continue;
            }
            for (std::sregex_iterator it(lines[index].begin(), lines[index].end(), possessive),
                 stop; it != stop; ++it)
            {
                if (std::find(kNotPossessive.begin(), kNotPossessive.end(), (*it)[0].str()) ==
                    kNotPossessive.end())
                {
                    faults.push_back({"birinci şahıs çoğul iyelik",
                                      static_cast<int>(index) + 1, (*it)[0].str()});
                    marked = true;
                    break;
                }
            }
            if (marked)
            {
                continue;
            }
            std::smatch found;
            if (std::regex_search(lines[index], found, plural))
            {
                faults.push_back({"birinci şahıs çoğul fiil",
                                  static_cast<int>(index) + 1, found[0].str()});
                continue;
            }
            if (std::regex_search(lines[index], found, reader))
            {
                faults.push_back({"okura hitap",
                                  static_cast<int>(index) + 1, found[0].str()});
            }
        }
        return faults;
    }

}
