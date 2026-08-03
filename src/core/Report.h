#pragma once

#include <cstddef>
#include <string>
#include <string_view>

namespace slm
{

    /// Collects the outcome of a run and prints it as it goes.
    ///
    /// A run is a sequence of named checks grouped under headings. Each check
    /// is recorded as it is made and printed immediately, so a run that aborts
    /// still leaves everything it had established on the terminal. The totals
    /// are kept alongside, and the process exit code is taken from them rather
    /// than from whether the run reached its end.
    ///
    /// Two kinds of check are offered because two kinds of claim are made. A
    /// predicate is either true or it is not. A numerical identity is never
    /// exactly zero in floating point, so it is stated as a residual that must
    /// be small, and the tolerance is part of the claim: a check that passes
    /// only at a tolerance nobody chose is not a check.
    class Report
    {
    public:
        /// Default tolerance for @ref checkNear, used when a call does not name
        /// one. Chosen to be tight enough that an identity which merely looks
        /// plausible does not pass, and loose enough that an exact one computed
        /// through a few hundred double operations still does.
        static constexpr double defaultTolerance = 1e-9;

        /// Begins a top-level heading. One per section of the run.
        void section(std::string_view title);

        /// Begins a heading below the current section.
        void subsection(std::string_view title);

        /// Records a predicate. Passes when @p condition holds.
        void check(std::string_view claim, bool condition);

        /// Records a numerical identity, stated as the quantity that should
        /// vanish. Passes when |@p residual| does not exceed @p tolerance.
        ///
        /// The residual rather than the two sides is taken because the claim
        /// being made is about their difference, and printing it on failure
        /// says by how much the identity missed.
        void checkNear(std::string_view claim, double residual,
                       double tolerance = defaultTolerance);

        /// Prints the totals.
        void summary() const;

        /// True when no check has failed. Note that a run in which nothing was
        /// checked at all also returns true, so a caller that cares should look
        /// at @ref total as well.
        bool allPassed() const;

        /// Number of checks that passed.
        std::size_t passed() const;

        /// Number of checks that failed.
        std::size_t failed() const;

        /// Number of checks made.
        std::size_t total() const;

    private:
        void record(std::string_view claim, bool ok, std::string_view detail);

        std::size_t passedCount_ = 0;
        std::size_t failedCount_ = 0;
    };

}
