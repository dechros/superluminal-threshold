#include "core/Report.h"

#include <cmath>
#include <format>
#include <iostream>

namespace slm
{

    void Report::section(std::string_view title)
    {
        std::cout << "\n";
        std::cout << "================================================================\n";
        std::cout << "  " << title << "\n";
        std::cout << "================================================================\n";
    }

    void Report::subsection(std::string_view title)
    {
        std::cout << "\n-- " << title << "\n";
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

        std::cout << (ok ? "  [ok]   " : "  [FAIL] ") << claim;
        if (!ok && !detail.empty())
        {
            std::cout << "   " << detail;
        }
        std::cout << "\n";
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
        std::cout << "\n";
        std::cout << "================================================================\n";
        if (failedCount_ == 0 && passedCount_ == 0)
        {
            std::cout << "  NOTHING WAS CHECKED\n";
        }
        else if (failedCount_ == 0)
        {
            std::cout << std::format("  ALL PASSED: {} checks\n", passedCount_);
        }
        else
        {
            std::cout << std::format("  FAILED: {} of {} checks\n", failedCount_, total());
        }
        std::cout << "================================================================\n";
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
