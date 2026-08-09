#pragma once

#include <string>
#include <vector>

namespace slm
{

    /// Structural checks on a markdown document that have nothing to do with
    /// what it argues, only with whether the file itself survived editing
    /// intact.
    ///
    /// A TOOL THAT EDITS THROUGH AN ESCAPING LANGUAGE. A tool that edits the
    /// text through a language with backslash escapes can turn a markup macro
    /// into the control character its escape names, silently and without
    /// changing the length of the line; the rendered output merely loses a
    /// symbol, so the damage survives review. Counting stray control
    /// characters costs nothing and turns that class of accident into a
    /// failure.
    ///
    /// THE ONE ESCAPE THE COUNT ABOVE CANNOT SEE. A backslash followed by the
    /// letter n names the line break itself, so a macro beginning with that
    /// letter does not become a control character: it becomes a real line
    /// break, and the rest of the macro becomes prose at the start of the
    /// next line. What that leaves behind is always the same shape, a line
    /// whose last character is a single backslash.
    ///
    /// A REWRITE THAT REBUILDS THE DOCUMENT FROM ITS BLOCKS can drop the
    /// block that was never numbered, and every check keyed on numbers would
    /// still pass; the title is keyed on the thing that has no number.
    ///
    /// A REFERENCE THAT RESOLVES IS NOT THEREBY CORRECT. A rewrite that
    /// applies a mapping twice leaves every reference pointing at some
    /// section, just not the intended one, and an existence check passes. A
    /// reference announced as an appendix must land after the heading that
    /// opens the appendix, which is a stronger requirement where one is
    /// available.
    class DocumentIntegrity
    {
    public:
        /// Number of control characters in the text other than the line
        /// break.
        static int controlCharacters(const std::string &text);

        /// Lines ending in a lone backslash, which is a macro cut in half.
        static std::vector<int> splitMacros(const std::string &text);

        /// Whether the text opens with a title at the top level.
        static bool carriesTitle(const std::string &text);

        /// Section identifiers the text refers to as belonging to its
        /// appendix, that are not in fact placed there.
        static std::vector<std::string> appendixReferencesOutsideIt(const std::string &text);
    };

}
