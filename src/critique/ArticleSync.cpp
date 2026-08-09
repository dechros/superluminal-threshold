#include "critique/ArticleSync.h"

#include "charge/ChargedRoundTrip.h"
#include "core/Report.h"
#include "experiment/RoundTripExperiment.h"
#include "identity/RoundTripInvariants.h"
#include "identity/ThresholdSensitivity.h"
#include "intermediate/IntermediateRegion.h"
#include "routes/ThreeRoutes.h"
#include "units/PhysicalScales.h"
#include "units/ProtonJourney.h"
#include "units/SignatureThreshold.h"
#include "units/ThresholdScaling.h"

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
        const auto kind = IntermediateRegion::Kind::Euclidean;
        const double drive = 1.5e24;

        return {
            {"the mass ceiling",
             ThresholdSensitivity::largestAdmissibleMass(1.0, 4.0, 2.8), "3{,}84"},
            {"the widest admissible band",
             ThresholdSensitivity::largestAdmissibleExtent(1.0, 1.0, 4.0, 2.8, 5.0), "0{,}1128"},
            {"the round trip price",
             ThreeRoutes::roundTripReading(ThreeRoutes::Route::Wave, kind, 2.8, 1.0, 1.0, 4.0,
                                           8.0),
             "2{,}925728"},
            {"the point body reading",
             ThreeRoutes::reading(ThreeRoutes::Route::PointBody, kind, 2.8, 1.0, 1.0, 4.0, 8.0),
             "9{,}861"},
            {"the wave reading",
             ThreeRoutes::reading(ThreeRoutes::Route::Wave, kind, 2.8, 1.0, 1.0, 4.0, 8.0),
             "1{,}462864"},
            {"the amplitude reading",
             ThreeRoutes::reading(ThreeRoutes::Route::Amplitude, kind, 2.8, 1.0, 1.0, 4.0, 8.0),
             "0{,}519"},
            {"the cheapest price under a potential",
             ChargedRoundTrip::cheapestThreshold(ThreeRoutes::Route::Wave, kind, 2.8, 1.0, 1.0,
                                                 4.0, 8.0, 1.0, 0.5, 2001, 1.0),
             "2{,}920810"},
            {"the proton admission frequency", ProtonJourney::lowestDriveForProton(), "1{,}4255"},
            {"the crossing debt in seconds", ProtonJourney::debtInSeconds(drive), "5{,}4614"},
            {"the break even distance", ProtonJourney::breakEvenDistance(drive), "1{,}6373"},
            {"the Planck density", SignatureThreshold::planckDensity(), "5{,}15"},
            {"the turning density", SignatureThreshold::turningDensity(), "1{,}06"},
            {"the quantisation parameter", ThresholdScaling::quantisationParameter(), "0{,}2375"},
            {"the derived critical fraction",
             ThresholdScaling::criticalFraction(ThresholdScaling::quantisationParameter()),
             "0{,}4094"},
            {"the beam frequency with kinetic energy",
             RoundTripExperiment::available(RoundTripExperiment::Requirement::BeamEnergy),
             "1{,}7749"},
            {"the far-side displacement", RoundTripExperiment::displacementMetres(), "0{,}2998"},
            {"the launches per arrival", RoundTripExperiment::launchesNeeded(), "4{,}85"},
            {"the running time", RoundTripExperiment::runTimeSeconds(), "0{,}49"},
            {"the density reached",
             RoundTripExperiment::available(RoundTripExperiment::Requirement::RegionDensity),
             "9{,}28"},
            {"the scale that would close the gap",
             ThresholdScaling::scaleThatClosesGap(
                 SignatureThreshold::densityInSphere(2.08e-6, 0.8414e-15)),
             "3{,}74"},
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
