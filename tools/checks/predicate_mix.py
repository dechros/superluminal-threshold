"""Share of sentence endings carried by each finite predicate form.

The copula in its -tir shape attaches only after a voiceless consonant, so a
word ending in those letters after a vowel is not a copula at all: it is a
verb whose stem ends in t carrying the aorist. "üretir" and "türetir" are
that shape, and counting them as copulas moves several points of the mix
into the wrong column.

The bands below come from twenty long Turkish physics texts, some three
hundred thousand words, measured on the same scale this class applies here.
Each bound sits inside the observed range rather than at its edge, because
the range is wide and its edges are single authors.

Observed, as a share of sentence endings: copula 10.8 to 37.3 with a median
of 15.5; aorist 9.0 to 44.0, median 24.4; past passive 0.0 to 25.4, median
10.9; present continuous 4.3 to 39.2, median 15.3.

The floors matter more than the ceilings. A text that states every finding as
a timeless law reads flat, and the form it is missing is the present
continuous: the one that says what the object or the calculation is doing
rather than what is eternally the case.

Mirrors src/prose/PredicateMixRegister.h/.cpp.
"""

from __future__ import annotations

import re

from . import prose_text

copula_share_limit = 30
aorist_share_limit = 33
continuous_share_floor = 8
past_passive_share_floor = 6

_PAST_PASSIVE = re.compile(r"(mış|miş|muş|müş)t(ı|i)r$")
_CONTINUOUS = re.compile(r"(makta|mekte)d(ı|i)r$")
_COPULA = re.compile(r"(dır|dir|dur|dür)$|([pçtkfhsş])(tır|tir|tur|tür)$")
_AORIST = re.compile(r"(ır|ir|ur|ür|ar|er)$")


def predicate_mix(text: str) -> list[tuple[str, int]]:
    past = present = is_form = does = total = 0
    for sentence in prose_text.prose_sentences(text):
        tail = prose_text.final_word(sentence)
        if not tail:
            continue
        total += 1
        if _PAST_PASSIVE.search(tail):
            past += 1
        elif _CONTINUOUS.search(tail):
            present += 1
        elif _COPULA.search(tail):
            is_form += 1
        elif _AORIST.search(tail):
            does += 1
    if total == 0:
        return []
    return [
        ("-mıştır", 100 * past // total),
        ("-maktadır", 100 * present // total),
        ("-dır", 100 * is_form // total),
        ("-ir", 100 * does // total),
    ]
