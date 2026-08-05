#include "critique/CitationCoverage.h"

#include "core/Report.h"

#include <algorithm>
#include <cctype>
#include <format>
#include <fstream>
#include <regex>
#include <sstream>

namespace slm
{
    namespace
    {
        const char *const kHeading = "## Kaynakça";

        std::string document()
        {
            std::ifstream file("article/article.md", std::ios::binary);
            std::ostringstream buffer;
            buffer << file.rdbuf();
            return buffer.str();
        }

        std::size_t headingPosition(const std::string &text)
        {
            return text.find(kHeading);
        }

        std::string prose(const std::string &text)
        {
            const std::size_t heading = headingPosition(text);
            return heading == std::string::npos ? text : text.substr(0, heading);
        }

        std::string list(const std::string &text)
        {
            const std::size_t heading = headingPosition(text);
            return heading == std::string::npos ? std::string{} : text.substr(heading);
        }
    }

    std::vector<int> CitationCoverage::cited(const std::string &document)
    {
        const std::string body = prose(document);
        const std::regex pattern("\\[([0-9]+)\\]");
        std::vector<int> numbers;
        for (auto it = std::sregex_iterator(body.begin(), body.end(), pattern);
             it != std::sregex_iterator(); ++it)
        {
            numbers.push_back(std::stoi((*it)[1].str()));
        }
        std::sort(numbers.begin(), numbers.end());
        numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
        return numbers;
    }

    std::vector<int> CitationCoverage::listed(const std::string &document)
    {
        std::istringstream stream(list(document));
        const std::regex entry("^([0-9]+)\\. ");
        std::vector<int> positions;
        std::string line;
        while (std::getline(stream, line))
        {
            if (std::regex_search(line, entry))
            {
                positions.push_back(static_cast<int>(positions.size()) + 1);
            }
        }
        return positions;
    }

    std::vector<int> CitationCoverage::danglingCitations(const std::string &document)
    {
        const std::vector<int> entries = listed(document);
        std::vector<int> dangling;
        for (int number : cited(document))
        {
            if (number < 1 || number > static_cast<int>(entries.size()))
            {
                dangling.push_back(number);
            }
        }
        return dangling;
    }

    std::vector<int> CitationCoverage::uncitedEntries(const std::string &document)
    {
        const std::vector<int> numbers = cited(document);
        std::vector<int> uncited;
        for (int position : listed(document))
        {
            if (std::find(numbers.begin(), numbers.end(), position) == numbers.end())
            {
                uncited.push_back(position);
            }
        }
        return uncited;
    }

    bool CitationCoverage::bibliographyPresent(const std::string &document)
    {
        return headingPosition(document) != std::string::npos && !listed(document).empty();
    }

    void CitationCoverageSection::run(Report &report) const
    {
        const std::string text = document();

        report.subsection("The list has to be found before anything about it is claimed");
        report.check("the article was read and is not empty", !text.empty());
        report.check("it carries a bibliography heading with at least one entry under it",
                     CitationCoverage::bibliographyPresent(text));

        if (text.empty() || !CitationCoverage::bibliographyPresent(text))
        {
            return;
        }

        const std::vector<int> numbers = CitationCoverage::cited(text);
        const std::vector<int> entries = CitationCoverage::listed(text);
        const std::vector<int> dangling = CitationCoverage::danglingCitations(text);
        const std::vector<int> uncited = CitationCoverage::uncitedEntries(text);

        report.subsection("Every citation against every entry");
        report.check(std::format("  the prose cites {} distinct numbers and the list carries {} "
                                 "entries",
                                 numbers.size(), entries.size()),
                     !numbers.empty() && !entries.empty());
        report.check("no citation points past the end of the list, which is what a renumbering "
                     "or a shortening leaves behind",
                     dangling.empty());
        for (int number : dangling)
        {
            report.check(std::format("  citation {} has no entry behind it", number), false);
        }
        report.check("no entry sits in the list with nothing pointing at it, which is what "
                     "cutting the passage that cited it leaves behind",
                     uncited.empty());
        for (int position : uncited)
        {
            report.check(std::format("  entry {} is never cited", position), false);
        }
        report.check("so the citations and the list cover each other exactly, in both directions",
                     dangling.empty() && uncited.empty() &&
                         numbers.size() == entries.size());
    }

}
