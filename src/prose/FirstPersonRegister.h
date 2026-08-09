#pragma once

#include "prose/ProseText.h"

#include <string>
#include <vector>

namespace slm
{

    /// First person, singular or plural, and address to the reader.
    ///
    /// Turkish academic convention rules out first person singular and
    /// plural, and possessive forms of the work itself. Looking only for
    /// first person verbs is not enough: Turkish marks a possessor with a
    /// suffix, so a noun can be in the first person while every verb in the
    /// sentence is impersonal, and a case ending may follow that suffix. A few
    /// ordinary words end in the same letters and are listed as exceptions.
    ///
    /// The second person is the same fault seen from the other side, and it
    /// arrives by a different route: a section meant to be reproducible slips
    /// into instructions, telling the reader to compute this and compare
    /// that, rather than stating what a computation gives.
    class FirstPersonRegister
    {
    public:
        /// Sentences written in the first person, singular or plural, or
        /// addressed to the reader.
        static std::vector<ProseFault> firstPerson(const std::string &text);
    };

}
