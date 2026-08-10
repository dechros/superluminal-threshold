"""Structural checks on a markdown document that have nothing to do with what
it argues, only with whether the file itself survived editing intact.

A TOOL THAT EDITS THROUGH AN ESCAPING LANGUAGE. A tool that edits the text
through a language with backslash escapes can turn a markup macro into the
control character its escape names, silently and without changing the length
of the line; the rendered output merely loses a symbol, so the damage
survives review. Counting stray control characters costs nothing and turns
that class of accident into a failure.

THE ONE ESCAPE THE COUNT ABOVE CANNOT SEE. A backslash followed by the letter
n names the line break itself, so a macro beginning with that letter does not
become a control character: it becomes a real line break, and the rest of
the macro becomes prose at the start of the next line. What that leaves
behind is always the same shape, a line whose last character is a single
backslash.

A REWRITE THAT REBUILDS THE DOCUMENT FROM ITS BLOCKS can drop the block that
was never numbered, and every check keyed on numbers would still pass; the
title is keyed on the thing that has no number.

A REFERENCE THAT RESOLVES IS NOT THEREBY CORRECT. A rewrite that applies a
mapping twice leaves every reference pointing at some section, just not the
intended one, and an existence check passes. A reference announced as an
appendix must land after the heading that opens the appendix, which is a
stronger requirement where one is available.

Mirrors src/critique/DocumentIntegrity.h/.cpp.
"""

from __future__ import annotations


def _lines(text: str) -> list[str]:
    return [line[:-1] if line.endswith("\r") else line for line in text.split("\n")]


def control_characters(text: str) -> int:
    return sum(1 for ch in text if ord(ch) < 0x20 and ch != "\n")


def split_macros(text: str) -> list[int]:
    places: list[int] = []
    for index, raw in enumerate(_lines(text)):
        row = raw.rstrip("\r ")
        if len(row) >= 2 and row[-1] == "\\" and row[-2] != "\\":
            places.append(index + 1)
    return places


def carries_title(text: str) -> bool:
    for line in _lines(text):
        if not line:
            continue
        return line.startswith("# ") and not line.startswith("## ") and len(line) > 8
    return False


def appendix_references_outside_it(text: str) -> list[str]:
    all_lines = _lines(text)
    opens_at = len(all_lines)
    placed: list[tuple[str, int]] = []
    for index, line in enumerate(all_lines):
        if (
            line.startswith("# ")
            and not line.startswith("## ")
            and opens_at == len(all_lines)
            and "Ek" in line
        ):
            opens_at = index
        if line.startswith("## "):
            dot = line.find(".")
            if dot != -1 and dot > 3:
                placed.append((line[3:dot], index))

    wrong: list[str] = []
    for line in all_lines:
        at = line.find("Ek ")
        while at != -1:
            end = at + 3
            while end < len(line) and line[end].isdigit():
                end += 1
            if end > at + 3:
                wanted = line[at + 3 : end]
                for name, position in placed:
                    if name == wanted and position < opens_at and wanted not in wrong:
                        wrong.append(wanted)
            at = line.find("Ek ", end)
    return wrong
