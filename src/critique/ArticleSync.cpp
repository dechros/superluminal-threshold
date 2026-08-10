#include "critique/ArticleSync.h"

#include "core/Report.h"
#include "units/PhysicalScales.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <format>
#include <fstream>
#include <sstream>

namespace slm
{
    namespace
    {
        std::string document()
        {
            std::ifstream file("article/article.md", std::ios::binary);
            std::ostringstream buffer;
            buffer << file.rdbuf();
            return buffer.str();
        }

        double writtenValue(const std::string &text)
        {
            std::string plain;
            for (std::size_t i = 0; i < text.size(); ++i)
            {
                if (text.compare(i, 3, "{,}") == 0)
                {
                    plain.push_back('.');
                    i += 2;
                    continue;
                }
                plain.push_back(text[i]);
            }
            return std::stod(plain);
        }

        double mantissa(double value)
        {
            if (value == 0.0)
            {
                return 0.0;
            }
            const double decade = std::floor(std::log10(std::abs(value)));
            return value / std::pow(10.0, decade);
        }

        int significantDigits(const std::string &written)
        {
            int digits = 0;
            bool started = false;
            for (std::size_t i = 0; i < written.size(); ++i)
            {
                if (written.compare(i, 3, "{,}") == 0)
                {
                    i += 2;
                    continue;
                }
                if (!std::isdigit(static_cast<unsigned char>(written[i])))
                {
                    continue;
                }
                if (written[i] == '0' && !started)
                {
                    continue;
                }
                started = true;
                ++digits;
            }
            return digits;
        }

        double roundedTo(double value, const std::string &written)
        {
            const int digits = significantDigits(written);
            const double factor = std::pow(10.0, std::max(0, digits - 1));
            return std::round(value * factor) / factor;
        }
    }

    std::vector<ArticleSync::Quotation> ArticleSync::quotations()
    {
        constexpr double kSecondsPerYear = 3.155695e7;

        return {
            {"the light-year distance a year of advance costs",
             PhysicalScales::distanceForAdvance(kSecondsPerYear), "9{,}46"},
            {"the nanoseconds a metre of far-side travel buys",
             PhysicalScales::advanceForDistance(1.0) * 1e9, "3{,}34"},
        };
    }

    bool ArticleSync::textContains(const std::string &text, const std::string &needle)
    {
        return text.find(needle) != std::string::npos;
    }

    std::vector<std::string> ArticleSync::missing(const std::string &text)
    {
        std::vector<std::string> absent;
        for (const Quotation &quotation : quotations())
        {
            if (!textContains(text, quotation.asWritten))
            {
                absent.push_back(quotation.subject);
            }
        }
        return absent;
    }

    bool ArticleSync::writtenMatchesComputed(const Quotation &quotation)
    {
        const double written = writtenValue(quotation.asWritten);
        const double value = mantissa(quotation.computed);
        const double stated = mantissa(written);
        return std::abs(roundedTo(value, quotation.asWritten) - stated) < 1e-9;
    }

    std::vector<std::string> ArticleSync::stale()
    {
        std::vector<std::string> drifted;
        for (const Quotation &quotation : quotations())
        {
            if (!writtenMatchesComputed(quotation))
            {
                drifted.push_back(quotation.subject);
            }
        }
        return drifted;
    }

    void ArticleSyncSection::run(Report &report) const
    {
        const std::string text = document();

        report.subsection("The article is readable and quotes calculated numbers");
        report.check("the article was located and read", !text.empty());
        report.check(std::format("{} numbers in it are quoted from a calculation",
                                 ArticleSync::quotations().size()),
                     !ArticleSync::quotations().empty());

        report.subsection("Every quoted number appears in the text as written");
        for (const std::string &subject : ArticleSync::missing(text))
        {
            report.check(std::format("  {} is not in the text as written", subject), false);
        }
        report.check("no quoted number is absent from the text, so a calculation reported here "
                     "cannot be one the text never received",
                     ArticleSync::missing(text).empty());

        report.subsection("Every quoted number still agrees with its calculation");
        for (const ArticleSync::Quotation &quotation : ArticleSync::quotations())
        {
            report.check(std::format("  {:<38} : text says {}, calculation gives {:.6e}",
                                     quotation.subject, quotation.asWritten, quotation.computed),
                         ArticleSync::writtenMatchesComputed(quotation));
        }
        report.check("no quoted number has drifted from the value the libraries now compute, "
                     "which is the one direction a manuscript and its code part company in",
                     ArticleSync::stale().empty());
    }

}
