#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// Case endings checked against how their number is read aloud.
    ///
    /// Turkish attaches a case ending by the sound of the spoken word, not by
    /// the digit, so the ending cannot be looked up from the numeral: it has
    /// to be derived. The trailing digit names the spoken word, unless it is a
    /// zero, where the tens word does; that word's last vowel gives the vowel
    /// of the ending and its last consonant gives the stop. Five and six
    /// therefore take different endings in every case, and so do three and
    /// four.
    ///
    /// Two further details decide whether an ending is seen at all: it need
    /// not touch the digits, since a reference closes its bracket and a
    /// quantity closes its arithmetic delimiter first, and a fraction is read
    /// digit by digit, so a trailing zero after the separator is a zero
    /// rather than a thousand.
    class NumberSuffixAgreement
    {
    public:
        /// Numerals whose case ending disagrees with how the number is read
        /// aloud, in any of the cases the text uses.
        static std::vector<ProseFault> numberSuffixes(const std::string &text);
    };

}
