"""Case endings checked against how their number is read aloud.

Turkish attaches a case ending by the sound of the spoken word, not by the
digit, so the ending cannot be looked up from the numeral: it has to be
derived. The trailing digit names the spoken word, unless it is a zero, where
the tens word does; that word's last vowel gives the vowel of the ending and
its last consonant gives the stop. Five and six therefore take different
endings in every case, and so do three and four.

Two further details decide whether an ending is seen at all: it need not
touch the digits, since a reference closes its bracket and a quantity closes
its arithmetic delimiter first, and a fraction is read digit by digit, so a
trailing zero after the separator is a zero rather than a thousand.

Mirrors src/prose/NumberSuffixAgreement.h/.cpp.
"""

from __future__ import annotations

import re
from dataclasses import dataclass

from . import prose_text
from .prose_text import ProseFault


@dataclass
class _SpokenNumber:
    back: bool = False
    voiceless_final: bool = False
    vowel_final: bool = False
    harmony: str = ""


_ONES = [
    _SpokenNumber(True, False, False, "ı"),
    _SpokenNumber(False, False, False, "i"),
    _SpokenNumber(False, False, True, "i"),
    _SpokenNumber(False, True, False, "ü"),
    _SpokenNumber(False, True, False, "ü"),
    _SpokenNumber(False, True, False, "i"),
    _SpokenNumber(True, False, True, "ı"),
    _SpokenNumber(False, False, True, "i"),
    _SpokenNumber(False, False, False, "i"),
    _SpokenNumber(True, False, False, "u"),
]

_TENS = [
    _SpokenNumber(True, False, False, "u"),
    _SpokenNumber(False, False, True, "i"),
    _SpokenNumber(True, False, False, "u"),
    _SpokenNumber(True, True, False, "ı"),
    _SpokenNumber(False, False, True, "i"),
    _SpokenNumber(True, True, False, "ı"),
    _SpokenNumber(False, True, False, "i"),
    _SpokenNumber(False, False, False, "i"),
    _SpokenNumber(True, False, False, "ı"),
]


def _spoken_number(digits: str, fraction: bool) -> _SpokenNumber:
    value = 0
    for ch in digits:
        if ch.isdigit():
            value = value * 10 + int(ch)

    if fraction or value % 10 != 0:
        return _ONES[value % 10]
    if value % 100 != 0:
        return _TENS[(value // 10) % 10 - 1]
    if value % 1000 != 0:
        return _SpokenNumber(False, False, False, "ü")
    if value % 1_000_000 != 0:
        return _SpokenNumber(False, False, False, "i")
    return _SpokenNumber(True, False, False, "u")


def _agreeing_suffix(number: str, written: str, fraction: bool) -> str:
    dot = number.rfind(".")
    spoken = _spoken_number(number if dot == -1 else number[dot + 1 :], fraction)

    low = "a" if spoken.back else "e"
    stop = "t" if spoken.voiceless_final else "d"
    locative = stop + low
    dative = ("y" + low) if spoken.vowel_final else low
    accusative = ("y" + spoken.harmony) if spoken.vowel_final else spoken.harmony
    genitive = ("n" + spoken.harmony + "n") if spoken.vowel_final else (spoken.harmony + "n")
    possessed = ("s" + spoken.harmony) if spoken.vowel_final else spoken.harmony

    if re.fullmatch("[dt][ae]ki", written):
        return locative + "ki"
    if re.fullmatch("[dt][ae]d(ı|i)r", written):
        return locative + ("dır" if spoken.back else "dir")
    if re.fullmatch("[dt][ae]n", written):
        return locative + "n"
    if re.fullmatch("[dt][ae]", written):
        return locative
    if re.fullmatch("y?[ae]", written):
        return dative
    if re.fullmatch("n?(ı|i|u|ü)n", written):
        return genitive
    if re.fullmatch("s(ı|i|u|ü)", written):
        return possessed
    if re.fullmatch("y?(ı|i|u|ü)", written):
        return accusative
    return ""


_PATTERN = re.compile(r"([0-9]+(?:\.[0-9]+)*)[\]$}]*'([a-zçğıöşü]+)")


def number_suffixes(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    for index, line in enumerate(prose_text.split_lines(text)):
        for match in _PATTERN.finditer(line):
            written = match.group(2)
            start = match.start(1)
            fraction = start > 0 and line[start - 1] in ("}", ",")
            wanted = _agreeing_suffix(match.group(1), written, fraction)
            if wanted and wanted != written:
                faults.append(
                    ProseFault(
                        "sayı eki uyumsuz",
                        index + 1,
                        f"{match.group(0)} -> '{wanted}",
                    )
                )
    return faults
