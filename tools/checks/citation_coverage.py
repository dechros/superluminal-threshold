"""Whether every citation in the text has an entry behind it, and every entry
a citation in front of it.

A bibliography rots in two directions and neither one announces itself. A
citation can point past the end of the list, which happens when the list is
renumbered or shortened. An entry can sit in the list with nothing pointing
at it, which happens when the passage that cited it is cut. Both survive a
reading, because a reader checks the numbers that catch the eye rather than
all of them.

The failure this exists for is heavier than either. When a section is
deleted, everything after it in the file goes with it, and the bibliography
is the last thing in the file. Nothing in a numerical check notices that the
list is gone, because a citation is not a number a calculation produces. So
the first thing checked here is that the list exists at all and is not
empty.

Reading the document is part of the check rather than a precondition for it.
A check that cannot find its input and passes anyway reports success for
having done nothing.

Mirrors src/critique/CitationCoverage.h/.cpp.
"""

from __future__ import annotations

import re
from pathlib import Path

from .report import Report

_HEADING = "## Kaynakça"
_CITED = re.compile(r"\[([0-9]+)\]")
_ENTRY = re.compile(r"^([0-9]+)\. ")


def _heading_position(text: str) -> int:
    return text.find(_HEADING)


def _prose(text: str) -> str:
    heading = _heading_position(text)
    return text if heading == -1 else text[:heading]


def _bibliography(text: str) -> str:
    heading = _heading_position(text)
    return "" if heading == -1 else text[heading:]


def cited(document: str) -> list[int]:
    numbers = {int(m.group(1)) for m in _CITED.finditer(_prose(document))}
    return sorted(numbers)


def listed(document: str) -> list[int]:
    positions = []
    for line in _bibliography(document).split("\n"):
        if _ENTRY.search(line):
            positions.append(len(positions) + 1)
    return positions


def dangling_citations(document: str) -> list[int]:
    entries = listed(document)
    return [n for n in cited(document) if n < 1 or n > len(entries)]


def uncited_entries(document: str) -> list[int]:
    numbers = cited(document)
    return [position for position in listed(document) if position not in numbers]


def bibliography_present(document: str) -> bool:
    return _heading_position(document) != -1 and len(listed(document)) > 0


def run(report: Report, article_path: Path = Path("article/article.md")) -> None:
    try:
        text = article_path.read_text(encoding="utf-8")
    except OSError:
        text = ""

    report.subsection("The list has to be found before anything about it is claimed")
    report.check("the article was read and is not empty", bool(text))
    report.check(
        "it carries a bibliography heading with at least one entry under it",
        bibliography_present(text),
    )

    if not text or not bibliography_present(text):
        return

    numbers = cited(text)
    entries = listed(text)
    dangling = dangling_citations(text)
    uncited = uncited_entries(text)

    report.subsection("Every citation against every entry")
    report.check(
        f"  the prose cites {len(numbers)} distinct numbers and the list carries "
        f"{len(entries)} entries",
        bool(numbers) and bool(entries),
    )
    report.check(
        "no citation points past the end of the list, which is what a renumbering or a "
        "shortening leaves behind",
        not dangling,
    )
    for number in dangling:
        report.check(f"  citation {number} has no entry behind it", False)
    report.check(
        "no entry sits in the list with nothing pointing at it, which is what cutting the "
        "passage that cited it leaves behind",
        not uncited,
    )
    for position in uncited:
        report.check(f"  entry {position} is never cited", False)
    report.check(
        "so the citations and the list cover each other exactly, in both directions",
        not dangling and not uncited and len(numbers) == len(entries),
    )
