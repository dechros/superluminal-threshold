#include "prose/NumberSuffixAgreement.h"

#include <regex>

namespace slm
{
    namespace
    {
        struct SpokenNumber
        {
            bool back = false;
            bool voicelessFinal = false;
            bool vowelFinal = false;
            std::string harmony;
        };

        SpokenNumber spokenNumber(const std::string &digits, bool fraction)
        {
            static const std::vector<SpokenNumber> ones = {
                {true, false, false, "ı"},  {false, false, false, "i"},
                {false, false, true, "i"},  {false, true, false, "ü"},
                {false, true, false, "ü"},  {false, true, false, "i"},
                {true, false, true, "ı"},   {false, false, true, "i"},
                {false, false, false, "i"}, {true, false, false, "u"}};
            static const std::vector<SpokenNumber> tens = {
                {true, false, false, "u"},  {false, false, true, "i"},
                {true, false, false, "u"},  {true, true, false, "ı"},
                {false, false, true, "i"},  {true, true, false, "ı"},
                {false, true, false, "i"},  {false, false, false, "i"},
                {true, false, false, "ı"}};

            long long value = 0;
            for (const char character : digits)
            {
                if (character >= '0' && character <= '9')
                {
                    value = value * 10 + (character - '0');
                }
            }
            if (fraction || value % 10 != 0)
            {
                return ones[static_cast<std::size_t>(value % 10)];
            }
            if (value % 100 != 0)
            {
                return tens[static_cast<std::size_t>((value / 10) % 10) - 1];
            }
            if (value % 1000 != 0)
            {
                return {false, false, false, "ü"};
            }
            if (value % 1000000 != 0)
            {
                return {false, false, false, "i"};
            }
            return {true, false, false, "u"};
        }

        std::string agreeingSuffix(const std::string &number, const std::string &written,
                                   bool fraction)
        {
            const std::size_t dot = number.rfind('.');
            const SpokenNumber spoken =
                spokenNumber(dot == std::string::npos ? number : number.substr(dot + 1), fraction);

            const std::string low = spoken.back ? "a" : "e";
            const std::string stop = spoken.voicelessFinal ? "t" : "d";
            const std::string locative = stop + low;
            const std::string dative = spoken.vowelFinal ? "y" + low : low;
            const std::string accusative =
                spoken.vowelFinal ? "y" + spoken.harmony : spoken.harmony;
            const std::string genitive = spoken.vowelFinal
                                             ? "n" + spoken.harmony + "n"
                                             : spoken.harmony + "n";
            const std::string possessed =
                spoken.vowelFinal ? "s" + spoken.harmony : spoken.harmony;

            if (std::regex_match(written, std::regex("[dt][ae]ki")))
            {
                return locative + "ki";
            }
            if (std::regex_match(written, std::regex("[dt][ae]d(ı|i)r")))
            {
                return locative + (spoken.back ? "dır" : "dir");
            }
            if (std::regex_match(written, std::regex("[dt][ae]n")))
            {
                return locative + "n";
            }
            if (std::regex_match(written, std::regex("[dt][ae]")))
            {
                return locative;
            }
            if (std::regex_match(written, std::regex("y?[ae]")))
            {
                return dative;
            }
            if (std::regex_match(written, std::regex("n?(ı|i|u|ü)n")))
            {
                return genitive;
            }
            if (std::regex_match(written, std::regex("s(ı|i|u|ü)")))
            {
                return possessed;
            }
            if (std::regex_match(written, std::regex("y?(ı|i|u|ü)")))
            {
                return accusative;
            }
            return {};
        }
    }

    std::vector<ProseFault> NumberSuffixAgreement::numberSuffixes(const std::string &text)
    {
        std::vector<ProseFault> faults;
        const std::regex pattern("([0-9]+(?:\\.[0-9]+)*)[\\]$}]*'([a-zçğıöşü]+)");
        const auto lines = ProseText::splitLines(text);
        for (std::size_t index = 0; index < lines.size(); ++index)
        {
            for (std::sregex_iterator it(lines[index].begin(), lines[index].end(), pattern),
                 stop; it != stop; ++it)
            {
                const std::string written = (*it)[2].str();
                const std::size_t start = static_cast<std::size_t>(it->position(1));
                const bool fraction =
                    start > 0 && (lines[index][start - 1] == '}' ||
                                  lines[index][start - 1] == ',');
                const std::string wanted = agreeingSuffix((*it)[1].str(), written, fraction);
                if (!wanted.empty() && wanted != written)
                {
                    faults.push_back({"sayı eki uyumsuz",
                                      static_cast<int>(index) + 1,
                                      (*it)[0].str() + " -> '" + wanted});
                }
            }
        }
        return faults;
    }

}
