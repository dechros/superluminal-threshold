"""Line- and sentence-level reading of prose, shared by every register rule
that scans it.

A line belongs to the prose only when it is not a table row, a heading, a
blockquote, a display-equation delimiter, or a line opening on a digit. A
sentence is prose accumulated across lines until a stop mark closes it, with
display mathematics folded out rather than scanned.

Mirrors src/prose/ProseText.h/.cpp, with one correction: the stop mark search
now requires the punctuation mark to be followed by whitespace or the end of
the text, the way proseSentences() below already did in the C++ original.
Two of the C++ registers (SentenceLengthRegister, NominalChainRegister) used
a cheaper `rfind('.')` instead and so treated the period inside a cross
reference such as "Bölüm 4.1.1" as a sentence end whenever it shared a line
with the sentence's real closing period, inflating the word count of
whatever came after. That divergence is why this port keeps exactly one
stop-mark implementation and has every caller use it.
"""

from __future__ import annotations

from dataclasses import dataclass


@dataclass
class ProseFault:
    rule: str
    line: int
    excerpt: str


_STOP_MARKS = (".", "!", "?")
_EMPHASIS = "*_"


def is_prose(line: str) -> bool:
    if not line:
        return False
    first = line[0]
    return (
        first not in "|#>"
        and not line.startswith("$$")
        and not first.isdigit()
    )


def word_count(s: str) -> int:
    return len(s.split())


def comma_count(s: str) -> int:
    return s.count(",")


def occurrences(haystack: str, needle: str) -> int:
    count = 0
    at = haystack.find(needle)
    while at != -1:
        count += 1
        at = haystack.find(needle, at + 1)
    return count


def shorten(s: str, width: int = 62) -> str:
    flat_parts: list[str] = []
    space = False
    for ch in s:
        if ch in ("\n", " "):
            space = True
            continue
        if space and flat_parts:
            flat_parts.append(" ")
        space = False
        flat_parts.append(ch)
    flat = "".join(flat_parts)
    return flat if len(flat) <= width else flat[:width]


def split_lines(text: str) -> list[str]:
    return text.split("\n")


def trimmed(s: str) -> str:
    return s.strip(" \t\r")


def _closes_sentence(text: str, at: int) -> bool:
    """Whether the stop mark at index `at` actually closes a sentence: it is
    followed, once any closing markdown emphasis (`**bold**`, `_italic_`) is
    skipped over, by whitespace or the end of the text.

    Without the skip, a bold-terminated sentence such as
    "**Katsayı tam olarak bire eşit çıkar.**" never closes, because the
    period is immediately followed by `**` rather than a space, and
    everything after it silently merges into the same "sentence".
    """
    if text[at] not in _STOP_MARKS:
        return False
    j = at + 1
    while j < len(text) and text[j] in _EMPHASIS:
        j += 1
    return j == len(text) or text[j] == " "


def last_sentence_stop(text: str) -> int:
    """Index of the last stop mark that actually closes a sentence, per
    `_closes_sentence`, or -1 if there is none.

    A period inside a decimal or a section number such as "4.1.1" is not
    followed by whitespace and so is skipped, which is exactly the
    distinction the buggy C++ callers were missing.
    """
    for i in range(len(text) - 1, -1, -1):
        if _closes_sentence(text, i):
            return i
    return -1


def prose_sentences(text: str) -> list[str]:
    out: list[str] = []
    paragraph = ""
    inside_math = False

    def flush() -> None:
        nonlocal paragraph
        current = ""
        for at, ch in enumerate(paragraph):
            current += ch
            if _closes_sentence(paragraph, at):
                if len(current) > 12:
                    out.append(current)
                current = ""
        paragraph = ""

    for line in split_lines(text):
        flat = trimmed(line)
        if flat == "$$":
            inside_math = not inside_math
            continue
        if inside_math or not is_prose(flat):
            flush()
            continue
        paragraph = (paragraph + " " + flat) if paragraph else flat
    flush()
    return out


def final_word(sentence: str) -> str:
    words = sentence.split()
    if not words:
        return ""
    last = words[-1]
    while last and last[-1] in ".,;:!?*)":
        last = last[:-1]
    return last
