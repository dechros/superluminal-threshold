"""Sentence length held to a stated cap.

Measured on Turkish prose of this kind, sentences run from eight to twenty
words, with an occasional longer one carrying a list. Past the limit below a
sentence is usually doing several jobs at once.

Mirrors src/prose/SentenceLengthRegister.h/.cpp, using the corrected stop-mark
search from prose_text.last_sentence_stop (see the note there).
"""

from __future__ import annotations

from . import prose_text
from .prose_text import ProseFault

word_limit = 32


def long_sentences(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    lines = prose_text.split_lines(text)
    sentence = ""
    start_line = 1
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
        done = sentence[: stop + 1]
        words = prose_text.word_count(done)
        if words > word_limit and prose_text.comma_count(done) < 4:
            faults.append(ProseFault("uzun cümle", start_line, prose_text.shorten(done)))
        sentence = sentence[stop + 1 :]
        start_line = index + 1
    return faults
