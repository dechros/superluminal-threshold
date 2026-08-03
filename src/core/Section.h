#pragma once

#include <string>

namespace slm
{

    class Report;

    /// One named group of checks in a run.
    ///
    /// Each library that establishes something exposes a section, and a run is
    /// nothing but those sections executed in order against a shared report.
    /// The split matters: a library computes and returns values, a section
    /// states what those values are supposed to satisfy. Keeping the claim out
    /// of the computation is what allows the same library to be called from
    /// elsewhere without dragging the assertions along.
    class Section
    {
    public:
        virtual ~Section() = default;

        /// Heading printed before the section runs.
        virtual std::string title() const = 0;

        /// Performs the checks, recording each against @p report.
        virtual void run(Report &report) const = 0;
    };

}
