#include "critique/AssumptionLedger.h"

#include "core/Report.h"

#include <algorithm>
#include <format>
#include <fstream>
#include <sstream>

namespace slm
{

    namespace
    {
        const char *const kMarker = "varsay";

        const std::vector<std::string> &exclusions()
        {
            static const std::vector<std::string> list = {
                "varsayılmaz",       "varsayılmamış",       "varsaymadan",
                "varsayım yapmadan", "varsayım eklenmemiş", "varsayılmak yerine",
                "varsayım **değil",  "varsayım değil",      "varsayım olmaktan çıkar"};
            return list;
        }

        std::string trimmed(const std::string &value)
        {
            const std::size_t first = value.find_first_not_of(" \t*");
            if (first == std::string::npos)
            {
                return {};
            }
            const std::size_t last = value.find_last_not_of(" \t*");
            return value.substr(first, last - first + 1);
        }

        bool isSeparator(const std::string &line)
        {
            return line.find_first_not_of("|-: \t") == std::string::npos;
        }

        std::vector<std::string> cells(const std::string &line)
        {
            std::vector<std::string> result;
            std::string field;
            std::istringstream stream(line);
            while (std::getline(stream, field, '|'))
            {
                result.push_back(trimmed(field));
            }
            if (!result.empty() && result.front().empty())
            {
                result.erase(result.begin());
            }
            if (!result.empty() && result.back().empty())
            {
                result.pop_back();
            }
            return result;
        }

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

        using Table = std::vector<std::vector<std::string>>;

        std::vector<Table> tables(const std::string &text)
        {
            std::vector<Table> result;
            Table current;
            for (const std::string &line : lines(text))
            {
                if (!line.empty() && line.front() == '|')
                {
                    if (!isSeparator(line))
                    {
                        current.push_back(cells(line));
                    }
                    continue;
                }
                if (current.size() > 1)
                {
                    result.push_back(current);
                }
                current.clear();
            }
            if (current.size() > 1)
            {
                result.push_back(current);
            }
            return result;
        }

        std::vector<std::string> firstColumn(const Table &table)
        {
            std::vector<std::string> column;
            for (std::size_t row = 1; row < table.size(); ++row)
            {
                if (!table[row].empty())
                {
                    column.push_back(table[row][0]);
                }
            }
            return column;
        }

        bool everyDispositionIsDeclared(const Table &ledger, const std::vector<std::string> &known)
        {
            if (ledger.size() < 2 || known.empty())
            {
                return false;
            }
            for (std::size_t row = 1; row < ledger.size(); ++row)
            {
                if (ledger[row].size() < 4)
                {
                    return false;
                }
                if (std::find(known.begin(), known.end(), ledger[row][2]) == known.end())
                {
                    return false;
                }
            }
            return true;
        }

        Table findLedger(const std::string &text)
        {
            const auto all = tables(text);
            Table found;
            int matches = 0;
            for (const Table &candidate : all)
            {
                if (candidate.empty() || candidate.front().size() != 4)
                {
                    continue;
                }
                for (const Table &declaration : all)
                {
                    if (declaration.empty() || declaration.front().size() != 2)
                    {
                        continue;
                    }
                    if (everyDispositionIsDeclared(candidate, firstColumn(declaration)))
                    {
                        found = candidate;
                        ++matches;
                        break;
                    }
                }
            }
            return matches == 1 ? found : Table{};
        }

        Table findVocabulary(const std::string &text)
        {
            const Table ledger = findLedger(text);
            if (ledger.empty())
            {
                return {};
            }
            for (const Table &declaration : tables(text))
            {
                if (!declaration.empty() && declaration.front().size() == 2 &&
                    everyDispositionIsDeclared(ledger, firstColumn(declaration)))
                {
                    return declaration;
                }
            }
            return {};
        }
    }

    std::string AssumptionLedger::text()
    {
        std::ifstream file("article/article.md", std::ios::binary);
        if (!file)
        {
            return {};
        }
        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    std::vector<std::string> AssumptionLedger::vocabulary(const std::string &text)
    {
        return firstColumn(findVocabulary(text));
    }

    std::vector<AssumptionLedger::Entry> AssumptionLedger::entries(const std::string &text)
    {
        const Table ledger = findLedger(text);
        std::vector<Entry> result;
        for (std::size_t row = 1; row < ledger.size(); ++row)
        {
            const auto &line = ledger[row];
            Entry entry;
            entry.section = !line.empty() ? line[0] : std::string{};
            entry.statement = line.size() > 1 ? line[1] : std::string{};
            entry.disposition = line.size() > 2 ? line[2] : std::string{};
            entry.settledAt = line.size() > 3 ? line[3] : std::string{};
            result.push_back(entry);
        }
        return result;
    }

    std::vector<std::string> AssumptionLedger::assertedIn(const std::string &text)
    {
        std::vector<std::string> sections;
        std::string heading;
        for (const std::string &line : lines(text))
        {
            if (!line.empty() && line.front() == '#')
            {
                heading = line;
                continue;
            }
            if (!line.empty() && line.front() == '|')
            {
                continue;
            }
            if (line.find(kMarker) == std::string::npos)
            {
                continue;
            }
            bool excluded = false;
            for (const std::string &phrase : exclusions())
            {
                if (line.find(phrase) != std::string::npos)
                {
                    excluded = true;
                    break;
                }
            }
            if (excluded)
            {
                continue;
            }
            const std::size_t first = heading.find_first_not_of("# ");
            if (first == std::string::npos)
            {
                continue;
            }
            const std::size_t last = heading.find(' ', first);
            std::string section =
                heading.substr(first, last == std::string::npos ? last : last - first);
            while (!section.empty() && section.back() == '.')
            {
                section.pop_back();
            }
            if (!section.empty() &&
                std::find(sections.begin(), sections.end(), section) == sections.end())
            {
                sections.push_back(section);
            }
        }
        return sections;
    }

    std::vector<std::string> AssumptionLedger::uncovered(const std::string &text)
    {
        const auto ledger = entries(text);
        std::vector<std::string> missing;
        for (const std::string &section : assertedIn(text))
        {
            const bool covered =
                std::any_of(ledger.begin(), ledger.end(),
                            [&section](const Entry &entry) { return entry.section == section; });
            if (!covered)
            {
                missing.push_back(section);
            }
        }
        return missing;
    }

    std::vector<AssumptionLedger::Entry> AssumptionLedger::incomplete(const std::string &text)
    {
        std::vector<Entry> broken;
        for (const Entry &entry : entries(text))
        {
            if (entry.section.empty() || entry.statement.empty() || entry.disposition.empty() ||
                entry.settledAt.empty())
            {
                broken.push_back(entry);
            }
        }
        return broken;
    }

    std::vector<AssumptionLedger::Entry> AssumptionLedger::outsideVocabulary(const std::string &text)
    {
        const auto known = vocabulary(text);
        std::vector<Entry> strays;
        for (const Entry &entry : entries(text))
        {
            if (std::find(known.begin(), known.end(), entry.disposition) == known.end())
            {
                strays.push_back(entry);
            }
        }
        return strays;
    }

    int AssumptionLedger::countWith(const std::string &text, const std::string &disposition)
    {
        int count = 0;
        for (const Entry &entry : entries(text))
        {
            if (entry.disposition == disposition)
            {
                ++count;
            }
        }
        return count;
    }

    void AssumptionLedgerSection::run(Report &report) const
    {
        const std::string document = AssumptionLedger::text();

        report.subsection("The text and its ledger both have to be found");
        report.check("the text was opened and is not empty, so what follows was measured "
                     "against it rather than against nothing",
                     document.size() > 1000);
        report.check(std::format("it carries no stray control character, of which {} were "
                                 "found, so no markup macro has been silently turned into the "
                                 "character its escape names",
                                 DocumentIntegrity::controlCharacters(document)),
                     DocumentIntegrity::controlCharacters(document) == 0);
        for (const int line : DocumentIntegrity::splitMacros(document))
        {
            report.check(std::format("  line {} ends in a lone backslash", line), false);
        }
        report.check("no line ends in a lone backslash, so no macro has been cut in half by "
                     "the one escape the count above cannot see, the line break itself",
                     DocumentIntegrity::splitMacros(document).empty());
        report.check("its first line is a title at the top level, which is the one block the "
                     "text carries without a number and so the one a renumbering cannot miss "
                     "losing",
                     DocumentIntegrity::carriesTitle(document));
        for (const std::string &wanted : DocumentIntegrity::appendixReferencesOutsideIt(document))
        {
            report.check(std::format("  section {} is referred to as an appendix but is not "
                                     "placed in one",
                                     wanted),
                         false);
        }
        report.check("every section the text calls an appendix is placed in the appendix, so a "
                     "reference that merely resolves is not mistaken for one that is right",
                     DocumentIntegrity::appendixReferencesOutsideIt(document).empty());
        const auto ledger = AssumptionLedger::entries(document);
        const auto known = AssumptionLedger::vocabulary(document);
        report.check(std::format("a ledger of {} rows was located in it, by matching a four "
                                 "column table against a two column declaration of the "
                                 "dispositions it uses",
                                 ledger.size()),
                     !ledger.empty());
        report.check(std::format("and the declaration offers {} dispositions", known.size()),
                     !known.empty());
        if (ledger.empty() || known.empty())
        {
            report.check("the audit cannot proceed without both, and reports that as a failure "
                         "rather than skipping",
                         false);
            return;
        }

        report.subsection("Every assumption the text asserts is in the ledger");
        const auto asserted = AssumptionLedger::assertedIn(document);
        const auto missing = AssumptionLedger::uncovered(document);
        report.check(std::format("the text asserts an assumption in {} sections", asserted.size()),
                     !asserted.empty());
        for (const std::string &section : missing)
        {
            report.check(std::format("  section {} asserts an assumption the ledger does not "
                                     "cover",
                                     section),
                         false);
        }
        report.check("no section asserts an assumption the ledger does not cover", missing.empty());

        report.subsection("Every row is complete and uses a declared disposition");
        for (const auto &entry : AssumptionLedger::incomplete(document))
        {
            report.check(std::format("  the row for section {} has an empty cell", entry.section),
                         false);
        }
        report.check("no row is left with an empty cell",
                     AssumptionLedger::incomplete(document).empty());
        for (const auto &entry : AssumptionLedger::outsideVocabulary(document))
        {
            report.check(std::format("  the row for section {} uses a disposition the text does "
                                     "not declare",
                                     entry.section),
                         false);
        }
        report.check("no row invents a disposition of its own, which is what would let a ledger "
                     "absorb an assumption by finding a comfortable word for it",
                     AssumptionLedger::outsideVocabulary(document).empty());

        report.subsection("The shape of the ledger");
        int total = 0;
        for (const std::string &disposition : known)
        {
            const int count = AssumptionLedger::countWith(document, disposition);
            total += count;
            report.check(std::format("  {} : {} rows", disposition, count), count >= 0);
        }
        report.check("every row carries one of the declared dispositions, so the rows are "
                     "accounted for exactly once",
                     total == static_cast<int>(ledger.size()));
    }

}
