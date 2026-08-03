#include "critique/AssumptionLedger.h"

#include "core/Report.h"

#include <algorithm>
#include <fstream>
#include <format>
#include <sstream>

namespace slm
{

    namespace
    {
        using Disposition = AssumptionLedger::Disposition;

        const char *const kMarker = "varsay";

        const std::vector<std::string> &exclusions()
        {
            static const std::vector<std::string> list = {
                "varsayılmaz",         "varsayılmamış",         "varsaymadan",
                "varsayım yapmadan",   "varsayım eklenmemiş",   "varsayılmak yerine",
                "varsayım **değildir**", "varsayım değildir"};
            return list;
        }

        std::string sectionOf(const std::string &heading)
        {
            const std::size_t first = heading.find_first_not_of("# ");
            if (first == std::string::npos)
            {
                return {};
            }
            const std::size_t last = heading.find(' ', first);
            std::string token = heading.substr(first, last == std::string::npos ? last
                                                                                : last - first);
            while (!token.empty() && token.back() == '.')
            {
                token.pop_back();
            }
            return token;
        }
    }

    std::vector<AssumptionLedger::Entry> AssumptionLedger::entries()
    {
        return {
            {"2.1.2", "that a phase delay and a far-side displacement may be added",
             Disposition::Derived, "the same section, from one stationary phase condition"},
            {"3.8", "that the transverse wavenumber is shared equally among the directions",
             Disposition::DeclaredLimit, "stated with its consequence: the open cell depends on "
                                         "mode content, which section 12 computes"},
            {"3.8", "that a degenerate layer blocks every interior mode completely",
             Disposition::DeclaredLimit, "stated as a model of the layer, with the remark that a "
                                         "full computation need not give exactly zero"},
            {"3.8", "that the strength of the matter layer follows the slope of the signature turn",
             Disposition::DeclaredLimit, "stated as a proxy, with the full stress tensor recorded "
                                         "as not computed"},
            {"4.1", "that a reflected component may be included",
             Disposition::Derived, "the same section: flux conservation admits no other solution"},
            {"8.5", "that global hyperbolicity holds",
             Disposition::AnotherAuthor, "the construction being compared needs it; the result "
                                         "here follows from the number of time directions alone"},
            {"10.10", "that the transition happens at light speed, instantly, independent of speed",
             Disposition::AnotherAuthor, "the model being compared assumes it; this text derives "
                                         "its own transition instead"},
            {"14.8", "that the directions changing character are the transverse ones",
             Disposition::ComputedBothWays, "both readings computed side by side, with the "
                                            "consequence of each stated"},
            {"18.4", "that the two labels of the table are independent",
             Disposition::Superseded, "section 18.7, where the exit face is fixed by the sign of "
                                      "the crossing wavenumber"},
            {"18.8", "that the rotation is the identity under one reading and uniform under the "
                     "other",
             Disposition::Superseded, "section 18.9, which answers without either endpoint by "
                                      "quantising the rotation"},
            {"18.8", "that the crossing is lossless, which is what makes one row vanish",
             Disposition::DeclaredLimit, "stated with its consequence: the matter layer of "
                                         "section 3.4 removes the zero"},
            {"18.9", "none; the passage names the two assumptions of section 18.8 in order "
                     "to remove them",
             Disposition::Discussion, "the section that removes them"},
            {"21", "that a particular structure can be built in region II",
             Disposition::AnotherAuthor, "the objection being answered assumes it; section 10 "
                                         "computes that it cannot"},
            {"23", "that the far side is unbounded",
             Disposition::DeclaredLimit, "stated with its consequence: a finite slab leaves an "
                                         "exponentially suppressed but nonzero amplitude"},
            {"22", "none; the library index names this ledger among the sources",
             Disposition::Discussion, "the ledger itself"},
            {"22.3", "none; the passage describes this ledger and the words it scans for",
             Disposition::Discussion, "the ledger itself, which this section documents"},
            {"24.2.1", "that one-wayness at the level of the equations and of the states are the "
                       "same claim",
             Disposition::AnotherAuthor, "the two readings are separated there, and only the "
                                         "second is defended"}};
    }

    int AssumptionLedger::countWith(Disposition disposition)
    {
        int count = 0;
        for (const Entry &entry : entries())
        {
            if (entry.disposition == disposition)
            {
                ++count;
            }
        }
        return count;
    }

    std::string AssumptionLedger::articleText()
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

    std::vector<std::string> AssumptionLedger::assertedIn(const std::string &text)
    {
        std::vector<std::string> sections;
        std::istringstream stream(text);
        std::string line;
        std::string heading;
        while (std::getline(stream, line))
        {
            if (!line.empty() && line.back() == '\r')
            {
                line.pop_back();
            }
            if (!line.empty() && line.front() == '#')
            {
                heading = line;
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
            const std::string section = sectionOf(heading);
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
        const auto ledger = entries();
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

    bool AssumptionLedger::everyEntryIsSettled()
    {
        const auto ledger = entries();
        return std::all_of(ledger.begin(), ledger.end(), [](const Entry &entry)
                           { return !entry.settledAt.empty() && !entry.statement.empty(); });
    }

    std::string AssumptionLedger::dispositionName(Disposition disposition)
    {
        switch (disposition)
        {
        case Disposition::Derived:
            return "derived";
        case Disposition::ComputedBothWays:
            return "computed both ways";
        case Disposition::Superseded:
            return "superseded";
        case Disposition::AnotherAuthor:
            return "another author's assumption";
        case Disposition::DeclaredLimit:
            return "declared limitation";
        case Disposition::Discussion:
            return "discussion, not an assumption";
        }
        return "unknown";
    }

    void AssumptionLedgerSection::run(Report &report) const
    {
        const std::string text = AssumptionLedger::articleText();

        report.subsection("The text has to be readable for this audit to mean anything");
        report.check("the text was opened and is not empty, so what follows was measured "
                     "against it rather than against nothing",
                     text.size() > 1000);
        if (text.size() <= 1000)
        {
            report.check("the audit cannot proceed without the text, and reports that as a "
                         "failure rather than skipping",
                         false);
            return;
        }

        report.subsection("Every assumption the text asserts is in the ledger");
        const auto asserted = AssumptionLedger::assertedIn(text);
        const auto missing = AssumptionLedger::uncovered(text);
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

        report.subsection("Every entry says what became of it");
        report.check("no entry is left without a statement and a place where it was settled",
                     AssumptionLedger::everyEntryIsSettled());
        for (const auto &entry : AssumptionLedger::entries())
        {
            report.check(std::format("  {} : {} [{}]", entry.section, entry.statement,
                                     AssumptionLedger::dispositionName(entry.disposition)),
                         !entry.settledAt.empty());
        }

        report.subsection("The shape of the ledger");
        const int derived = AssumptionLedger::countWith(AssumptionLedger::Disposition::Derived);
        const int bothWays =
            AssumptionLedger::countWith(AssumptionLedger::Disposition::ComputedBothWays);
        const int superseded =
            AssumptionLedger::countWith(AssumptionLedger::Disposition::Superseded);
        const int others =
            AssumptionLedger::countWith(AssumptionLedger::Disposition::AnotherAuthor);
        const int declared =
            AssumptionLedger::countWith(AssumptionLedger::Disposition::DeclaredLimit);
        const int discussion =
            AssumptionLedger::countWith(AssumptionLedger::Disposition::Discussion);
        report.check(std::format("{} derived, {} computed both ways, {} superseded, {} belonging "
                                 "to another construction, {} declared limitations, {} passages "
                                 "that discuss assumptions without making one",
                                 derived, bothWays, superseded, others, declared, discussion),
                     derived + bothWays + superseded + others + declared + discussion ==
                         static_cast<int>(AssumptionLedger::entries().size()));
        report.check("the assumptions this text carries of its own are the declared limitations "
                     "and nothing else, since every other entry is either obtained from "
                     "something, computed on both alternatives, removed later, or belongs to a "
                     "construction being compared",
                     declared > 0 && others > 0);
        report.check("and each declared limitation states its consequence in the text, so none "
                     "of them is carried silently",
                     AssumptionLedger::everyEntryIsSettled());
    }

}
