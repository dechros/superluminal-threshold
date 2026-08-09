#pragma once

#include "prose/ProseText.h"

#include <string>
#include <utility>
#include <vector>

namespace slm
{

    /// Share of sentence endings carried by each finite predicate form.
    ///
    /// The copula in its -tir shape attaches only after a voiceless
    /// consonant, so a word ending in those letters after a vowel is not a
    /// copula at all: it is a verb whose stem ends in t carrying the aorist.
    /// "üretir" and "türetir" are that shape, and counting them as copulas
    /// moves several points of the mix into the wrong column.
    ///
    /// The bands below come from twenty long Turkish physics texts, some
    /// three hundred thousand words, measured on the same scale this class
    /// applies here. Each bound sits inside the observed range rather than at
    /// its edge, because the range is wide and its edges are single authors.
    ///
    /// Observed, as a share of sentence endings: copula 10.8 to 37.3 with a
    /// median of 15.5; aorist 9.0 to 44.0, median 24.4; past passive 0.0 to
    /// 25.4, median 10.9; present continuous 4.3 to 39.2, median 15.3.
    ///
    /// The floors matter more than the ceilings. A text that states every
    /// finding as a timeless law reads flat, and the form it is missing is
    /// the present continuous: the one that says what the object or the
    /// calculation is doing rather than what is eternally the case.
    class PredicateMixRegister
    {
    public:
        static constexpr int copulaShareLimit = 30;
        static constexpr int aoristShareLimit = 33;
        static constexpr int continuousShareFloor = 8;
        static constexpr int pastPassiveShareFloor = 6;

        /// Share of prose sentences ending in each predicate form, in whole
        /// percentages, keyed by the ending.
        static std::vector<std::pair<std::string, int>> predicateMix(const std::string &text);
    };

}
