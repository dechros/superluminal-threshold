"""House rules on punctuation and on how a number is written.

The em dash is a house rule rather than a language one. The decimal
separator rule follows how the text reads its numbers aloud: Turkish reads a
decimal with a comma, and a run of computed values pasted in from a program
carries the program's point instead, often in the same table a
comma-separated value sits in, where a reading does not catch the mismatch.

Mirrors src/prose/TypographyRegister.h/.cpp.
"""

from __future__ import annotations

from . import prose_text
from .prose_text import ProseFault


def em_dashes(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    for index, line in enumerate(prose_text.split_lines(text)):
        if "—" in line:
            faults.append(ProseFault("uzun tire", index + 1, prose_text.shorten(line)))
    return faults


def decimal_points(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    for index, line in enumerate(prose_text.split_lines(text)):
        inside = False
        found = False
        for i, ch in enumerate(line):
            if found:
                break
            if ch == "$":
                inside = not inside
                continue
            if not inside or ch != "." or i == 0 or i + 1 >= len(line):
                continue
            if line[i - 1].isdigit() and line[i + 1].isdigit():
                found = True
        if found:
            faults.append(ProseFault("ondalik nokta", index + 1, prose_text.shorten(line)))
    return faults
