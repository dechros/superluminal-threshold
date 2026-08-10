"""Sentences that instruct the reader about the text rather than stating the
claim it wraps.

A sentence saying that something must be recorded, must not be confused, or
must not be exaggerated discusses the document instead of the finding. The
claim reads the same without the wrapper.

Mirrors src/prose/SelfReferenceRegister.h/.cpp.
"""

from __future__ import annotations

from . import prose_text
from .prose_text import ProseFault

_SELF_REFERENCE = (
    "karıştırılmamalı", "abartılmamalı", "bırakılmamalı", "kaydedilmeli",
    "yazılmalı", "belirtilmeli", "unutulmamalı", "gösterilmelidir",
    "okunmalıdır", "sunulmamakta", "vurgulanmalı", "ayrılmalıdır",
    "sayılmamalı", "tutulmalıdır", "verilmelidir",
    "karıştırılmaması", "ayrılması gerekir", "karıştırılmamaları",
)


def self_reference(text: str) -> list[ProseFault]:
    faults: list[ProseFault] = []
    for index, line in enumerate(prose_text.split_lines(text)):
        for mark in _SELF_REFERENCE:
            if mark in line:
                faults.append(
                    ProseFault("metin kendinden bahsediyor", index + 1, prose_text.shorten(line))
                )
                break
    return faults
