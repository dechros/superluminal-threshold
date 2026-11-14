#include "core/Report.h"

#include <cmath>
#include <format>
#include <print>

namespace slm
{
    void Report::section(std::string_view title)
    {
        std::println("");
        std::println("================================================================");
        std::println("  {}", title);
        std::println("================================================================");
    }

    void Report::subsection(std::string_view title)
    {
        std::println("\n-- {}", title);
    }

    void Report::record(std::string_view claim, bool ok, std::string_view detail)
    {
        if (ok)
        {
            ++passedCount_;
        }
        else
        {
            ++failedCount_;
        }

        std::print("{}{}", ok ? "  [ok]   " : "  [FAIL] ", claim);
        if (!ok && !detail.empty())
        {
            std::print("   {}", detail);
        }
        std::println("");
    }

    void Report::check(std::string_view claim, bool condition)
    {
        record(claim, condition, {});
    }

    void Report::checkNear(std::string_view claim, double residual, double tolerance)
    {
        const bool ok = std::isfinite(residual) && std::abs(residual) <= tolerance;
        const std::string detail =
            std::isfinite(residual)
                ? std::format("(residual {:.3e}, tolerance {:.0e})", residual, tolerance)
                : std::format("(residual {}, tolerance {:.0e})", residual, tolerance);
        record(claim, ok, detail);
    }

    void Report::summary() const
    {
        std::println("");
        std::println("================================================================");
        if (failedCount_ == 0 && passedCount_ == 0)
        {
            std::println("  NOTHING WAS CHECKED");
        }
        else if (failedCount_ == 0)
        {
            std::println("  ALL PASSED: {} checks", passedCount_);
        }
        else
        {
            std::println("  FAILED: {} of {} checks", failedCount_, total());
        }
        std::println("================================================================");
    }

    bool Report::allPassed() const
    {
        return failedCount_ == 0;
    }

    std::size_t Report::passed() const
    {
        return passedCount_;
    }

    std::size_t Report::failed() const
    {
        return failedCount_;
    }

    std::size_t Report::total() const
    {
        return passedCount_ + failedCount_;
    }
}
