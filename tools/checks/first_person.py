"""First person, singular or plural, and address to the reader.

Turkish academic convention rules out first person singular and plural, and
possessive forms of the work itself. Looking only for first person verbs is
not enough: Turkish marks a possessor with a suffix, so a noun can be in the
first person while every verb in the sentence is impersonal, and a case
ending may follow that suffix. A few ordinary words end in the same letters
and are listed as exceptions.

The second person is the same fault seen from the other side, and it arrives
by a different route: a section meant to be reproducible slips into
instructions, telling the reader to compute this and compare that, rather
than stating what a computation gives.

Mirrors src/prose/FirstPersonRegister.h/.cpp.
"""

from __future__ import annotations

import re

from . import prose_text
from .prose_text import ProseFault

_FIRST_PERSON = (
    "rastlamadım", "sınamadım", "ürettim", "yazdım", "kurdum",
    "karşılaştırdım", "etmiyorum", "almadım", "çıkardım", "türetmedim",
    "buldum", "gördüm", "yaptım", "ettim", "biz ",
    "bize ", "bizim ", "çalışmamız", "makalemiz", "hesabımız",
    "bulamadığım", "seçtiğim", "kurduğum", "gördüğüm", "yaptığım",
    "yoruz", "iyoruz", "uyoruz", "üyoruz", "ıyoruz", "acağız", "eceğiz",
    "malıyız", "meliyiz",
)

_NOT_POSSESSIVE = {"minimize", "Minimize", "temiz", "Temiz"}

_POSSESSIVE = re.compile(
    "[a-zçğıöşüA-ZÇĞİÖŞÜ]+(mız|miz|muz|müz)"
    "(ı|i|u|ü|a|e|la|le|da|de|dan|den|ın|in|un|ün|dır|dir|dur|dür)?"
    "(?![a-zA-ZçğıöşüÇĞİÖŞÜ])"
)
_PLURAL = re.compile(
    "[a-zçğıöşü]+(ırız|iriz|uruz|ürüz|arız|eriz|ayız|eyiz)(?![a-zA-ZçğıöşüÇĞİÖŞÜ])"
)
_READER = re.compile(
    "(^|[^a-zA-ZçğıöşüÇĞİÖŞÜ])"
    "([a-zçğıöşü]*(sınız|siniz|sunuz|sünüz|sanız|seniz)|siz|sizin|size)"
    "(?![a-zA-ZçğıöşüÇĞİÖŞÜ])"
)


def first_person(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    for index, line in enumerate(prose_text.split_lines(text)):
        line_no = index + 1
        marked = False
        for mark in _FIRST_PERSON:
            if mark in line:
                faults.append(ProseFault("birinci şahıs", line_no, prose_text.shorten(line)))
                marked = True
                break
        if marked:
            continue

        for match in _POSSESSIVE.finditer(line):
            if match.group(0) not in _NOT_POSSESSIVE:
                faults.append(ProseFault("birinci şahıs çoğul iyelik", line_no, match.group(0)))
                marked = True
                break
        if marked:
            continue

        found = _PLURAL.search(line)
        if found:
            faults.append(ProseFault("birinci şahıs çoğul fiil", line_no, found.group(0)))
            continue

        found = _READER.search(line)
        if found:
            faults.append(ProseFault("okura hitap", line_no, found.group(0)))
    return faults
