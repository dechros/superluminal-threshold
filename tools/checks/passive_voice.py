"""Passive constructions, counted per paragraph and per thousand words.

Turkish marks the passive with -Il after a consonant and with a bare -n after
a vowel, so the morphology is the only thing that separates "göstermektedir"
from "gösterilmektedir"; a pattern built on the tense suffix alone would count
every active -maktadır and -mıştır as well.

Three shapes wear the same letters without being passive, and each is
excluded or the count doubles: the ability suffix -abil/-ebil, which ends in
the same syllable the passive uses; the ablative followed by the copula,
which is a noun in a case rather than a verb, as in "türdendir"; and a short
list of verbs, "kullanır" and "tükenir" among them, that end this way without
being passive at all.

The match is also required to be a whole word ending in a finite tense, which
keeps verbal nouns such as "gerçeklendiğini" out of the count, since a verbal
noun is not a predicate and counting it would report a paragraph as
subjectless when it has a subject in every sentence.

The passive is normal in this register and is not a fault on its own. Three
or more in one paragraph is, because by then nothing in the paragraph has a
subject.

Mirrors src/prose/PassiveVoiceRegister.h/.cpp.
"""

from __future__ import annotations

import re

from . import prose_text
from .prose_text import ProseFault

passives_per_paragraph = 2
passive_per_thousand_limit = 34

_PASSIVE = re.compile(
    "(^|[^a-zçğıöşü])([a-zçğıöşü]{2,})(ıl|il|ul|ül|[aeıioöuü]n)"
    "(mış|miş|muş|müş|makta|mekte|ır|ir|ur|ür)"
    "(tır|tir|tur|tür|dır|dir|dur|dür)?([^a-zçğıöşü]|$)"
)
_ABILITY = re.compile("(abil|ebil)$")
_ABLATIVE = re.compile("(den|dan)$")
_LEXICAL = {
    "kullanır", "tükenir", "bulunur", "görünür", "bilinir", "dayanır",
    "uzanır", "inanır", "değildir", "kalınır", "sunar",
}


def _passive_count(text: str) -> int:
    hits = 0
    for match in _PASSIVE.finditer(text):
        base = match.group(2) + match.group(3)
        word = base + match.group(4) + (match.group(5) or "")
        if _ABILITY.search(base) or _ABLATIVE.search(base):
            continue
        if word in _LEXICAL:
            continue
        hits += 1
    return hits


def stacked_passives(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    lines = prose_text.split_lines(text)
    paragraph = ""
    start_line = 1

    def flush() -> None:
        nonlocal paragraph
        if not paragraph:
            return
        total = _passive_count(paragraph)
        if total > passives_per_paragraph:
            faults.append(ProseFault(f"{total} edilgen", start_line, prose_text.shorten(paragraph)))
        paragraph = ""

    for index, line in enumerate(lines):
        if not prose_text.is_prose(line):
            flush()
            continue
        if not paragraph:
            start_line = index + 1
        paragraph += " " + line
    flush()
    return faults


def passive_density(text: str) -> float:
    words = 0
    hits = 0
    for sentence in prose_text.prose_sentences(text):
        words += len(sentence.split())
        hits += _passive_count(sentence)
    return 0.0 if words == 0 else 1000.0 * hits / words
