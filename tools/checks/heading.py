"""Headings held to being noun phrases rather than assertions.

A heading carrying a colon, a question mark, or a finite verb has stopped
naming and started asserting, and naming is what a heading is for. The
aorist cannot be told from a heading noun ending the same way without a
lexicon, since "zincir", "sınır" and any name ending in -er share the
aorist's letters, so the finite forms detected by shape are supplemented by a
list of aorist verbs.

Mirrors src/prose/HeadingRegister.h/.cpp.
"""

from __future__ import annotations

import re

from . import prose_text
from .prose_text import ProseFault

word_limit = 8
mean_tenths = 40

_OPENER = re.compile(r"^#{1,3} ")
_LABEL = re.compile(r"^#{1,3} [0-9IVX.]*[.]?[ ]*")
_FINITE = re.compile(
    r"(dır|dir|dur|dür|tır|tir|maz|mez|yor|acak|ecek|ıyor|iyor|sın|sin|mıştır|miştir)$"
)
_AORIST = {
    "ulaşır", "belirler", "görür", "çıkar", "verir", "kalır", "artar",
    "azalır", "döner", "değişir", "gider", "gelir", "olur", "yapar",
    "taşır", "bırakır", "kurar", "geçer", "düşer", "biter", "başlar",
    "ölçer", "sağlar", "gerektirir", "içerir", "eder", "kaybeder",
}


def verbal_headings(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    for index, line in enumerate(prose_text.split_lines(text)):
        if not _OPENER.search(line):
            continue
        name = _LABEL.sub("", line)
        line_no = index + 1
        if ":" in name:
            faults.append(ProseFault("başlıkta iki nokta", line_no, name))
            continue
        if "?" in name:
            faults.append(ProseFault("başlıkta soru", line_no, name))
            continue
        words = name.split()
        asserted = False
        for word in words:
            plain = word.rstrip(".,;:!?*")
            if _FINITE.search(plain) or plain in _AORIST:
                faults.append(ProseFault("başlıkta çekimli fiil", line_no, name))
                asserted = True
                break
        if not asserted and len(words) > word_limit:
            faults.append(ProseFault("başlık çok uzun", line_no, name))
    return faults


def heading_word_mean(text: str) -> int:
    headings = 0
    words = 0
    for line in prose_text.split_lines(text):
        if not line.startswith("#"):
            continue
        name = _LABEL.sub("", line)
        if not name:
            continue
        headings += 1
        words += len(name.split())
    return 0 if headings == 0 else 10 * words // headings
