"""Sentences opening with a bare conjunction.

Formal Turkish does not begin a sentence with "Ve" or "Ama". Splitting a long
sentence and leaving its conjunction in front is the usual way this appears,
so the rule matters most while another rule is being satisfied.

Mirrors src/prose/OpeningConjunctionRegister.h/.cpp.
"""

from __future__ import annotations

from . import prose_text
from .prose_text import ProseFault

_MID_LINE = (". Ve ", ". Ama ", ". Ki ")


def opening_conjunctions(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    for index, line in enumerate(prose_text.split_lines(text)):
        if not prose_text.is_prose(line):
            continue
        for mark in _MID_LINE:
            if mark in line:
                faults.append(
                    ProseFault("cümle bağlaçla açılıyor", index + 1, prose_text.shorten(line))
                )
                break
        if line.startswith("Ve ") or line.startswith("Ama "):
            faults.append(
                ProseFault("cümle bağlaçla açılıyor", index + 1, prose_text.shorten(line))
            )
    return faults
