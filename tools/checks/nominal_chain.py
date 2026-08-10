"""Chains of verbal nouns in one sentence.

Three or more verbal nouns in one sentence survives every other rule: each is
grammatical, and together they put several nouns in front of the verb while
the reader holds all of them until it arrives. The cure is a verb early in
the sentence, and a list written as a list.

Mirrors src/prose/NominalChainRegister.h/.cpp, using the corrected stop-mark
search from prose_text.last_sentence_stop (see the note there).
"""

from __future__ import annotations

from . import prose_text
from .prose_text import ProseFault

nominals_per_sentence = 2

_NOMINAL = ("ması", "mesi", "dığı", "diği", "tığı", "tiği", "acağı", "eceği")


def nominal_chains(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    lines = prose_text.split_lines(text)
    sentence = ""
    start_line = 1

    def examine(done: str, line: int) -> None:
        total = sum(prose_text.occurrences(done, mark) for mark in _NOMINAL)
        if total > nominals_per_sentence and prose_text.comma_count(done) < 3:
            faults.append(ProseFault(f"{total} ad-fiil", line, prose_text.shorten(done)))

    for index, line in enumerate(lines):
        if not prose_text.is_prose(line):
            sentence = ""
            continue
        if not sentence:
            start_line = index + 1
        sentence += " " + line
        stop = prose_text.last_sentence_stop(sentence)
        if stop == -1:
            continue
        examine(sentence[: stop + 1], start_line)
        sentence = sentence[stop + 1 :]
        start_line = index + 1
    return faults
