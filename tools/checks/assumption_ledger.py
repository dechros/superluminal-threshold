"""Audit of a document against a ledger the document itself carries.

A text can be disciplined about its assumptions and still drift, because the
discipline lives in the prose and nothing enforces it. This module turns the
discipline into a check. It reads the text, finds every passage that asserts
an assumption, and requires each one to appear in a ledger with a
disposition.

NEITHER DOCUMENT NAMES THE OTHER. The ledger and the vocabulary of
dispositions are not held here; they are parsed out of the text at run time,
so this module contains no headings, numbers or wording belonging to it. The
only thing it knows is the file to open and the shape of a markdown table. A
text that renumbers its own sections therefore carries its ledger along with
it and leaves nothing here to rot.

WHAT IS ENFORCED. Every passage asserting an assumption must appear in the
ledger; every ledger row must be complete; and every disposition used must be
one the text itself declares. The last of these is what stops a ledger from
absorbing an assumption by inventing a comfortable word for it.

THE READING IS NOT OPTIONAL. If the text cannot be opened, or carries no
ledger, the check fails; it does not skip, because a check that disappears
when its input is missing reports success for having done nothing.

Mirrors src/critique/AssumptionLedger.h/.cpp.
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

from . import document_integrity
from .report import Report

_MARKER = "varsay"

_EXCLUSIONS = (
    "varsayılmaz", "varsayılmamış", "varsaymadan",
    "varsayım yapmadan", "varsayım eklenmemiş", "varsayılmak yerine",
    "varsayım **değil", "varsayım değil", "varsayım olmaktan çıkar",
)

Table = list[list[str]]


@dataclass
class Entry:
    section: str = ""
    statement: str = ""
    disposition: str = ""
    settled_at: str = ""


def _trimmed(value: str) -> str:
    return value.strip(" \t*")


def _is_separator(line: str) -> bool:
    return line.strip("|-: \t") == ""


def _cells(line: str) -> list[str]:
    result = [_trimmed(field) for field in line.split("|")]
    if result and result[0] == "":
        result.pop(0)
    if result and result[-1] == "":
        result.pop()
    return result


def _lines(text: str) -> list[str]:
    return [line[:-1] if line.endswith("\r") else line for line in text.split("\n")]


def _tables(text: str) -> list[Table]:
    result: list[Table] = []
    current: Table = []
    for line in _lines(text):
        if line.startswith("|"):
            if not _is_separator(line):
                current.append(_cells(line))
            continue
        if len(current) > 1:
            result.append(current)
        current = []
    if len(current) > 1:
        result.append(current)
    return result


def _first_column(table: Table) -> list[str]:
    return [row[0] for row in table[1:] if row]


def _every_disposition_is_declared(ledger: Table, known: list[str]) -> bool:
    if len(ledger) < 2 or not known:
        return False
    for row in ledger[1:]:
        if len(row) < 4:
            return False
        if row[2] not in known:
            return False
    return True


def _find_ledger(text: str) -> Table:
    all_tables = _tables(text)
    found: Table = []
    matches = 0
    for candidate in all_tables:
        if not candidate or len(candidate[0]) != 4:
            continue
        for declaration in all_tables:
            if not declaration or len(declaration[0]) != 2:
                continue
            if _every_disposition_is_declared(candidate, _first_column(declaration)):
                found = candidate
                matches += 1
                break
    return found if matches == 1 else []


def _find_vocabulary(text: str) -> Table:
    ledger = _find_ledger(text)
    if not ledger:
        return []
    for declaration in _tables(text):
        if (
            declaration
            and len(declaration[0]) == 2
            and _every_disposition_is_declared(ledger, _first_column(declaration))
        ):
            return declaration
    return []


def vocabulary(text: str) -> list[str]:
    return _first_column(_find_vocabulary(text))


def entries(text: str) -> list[Entry]:
    ledger = _find_ledger(text)
    result = []
    for row in ledger[1:]:
        result.append(
            Entry(
                section=row[0] if len(row) > 0 else "",
                statement=row[1] if len(row) > 1 else "",
                disposition=row[2] if len(row) > 2 else "",
                settled_at=row[3] if len(row) > 3 else "",
            )
        )
    return result


def asserted_in(text: str) -> list[str]:
    sections: list[str] = []
    heading = ""
    for line in _lines(text):
        if line.startswith("#"):
            heading = line
            continue
        if line.startswith("|"):
            continue
        if _MARKER not in line:
            continue
        if any(phrase in line for phrase in _EXCLUSIONS):
            continue
        start = 0
        while start < len(heading) and heading[start] in "# ":
            start += 1
        if start >= len(heading):
            continue
        end = heading.find(" ", start)
        section = heading[start:] if end == -1 else heading[start:end]
        section = section.rstrip(".")
        if section and section not in sections:
            sections.append(section)
    return sections


def uncovered(text: str) -> list[str]:
    ledger = entries(text)
    return [
        section
        for section in asserted_in(text)
        if not any(entry.section == section for entry in ledger)
    ]


def incomplete(text: str) -> list[Entry]:
    return [
        entry
        for entry in entries(text)
        if not (entry.section and entry.statement and entry.disposition and entry.settled_at)
    ]


def outside_vocabulary(text: str) -> list[Entry]:
    known = vocabulary(text)
    return [entry for entry in entries(text) if entry.disposition not in known]


def count_with(text: str, disposition: str) -> int:
    return sum(1 for entry in entries(text) if entry.disposition == disposition)


def run(report: Report, article_path: Path = Path("article/article.md")) -> None:
    try:
        document = article_path.read_text(encoding="utf-8")
    except OSError:
        document = ""

    report.subsection("The text and its ledger both have to be found")
    report.check(
        "the text was opened and is not empty, so what follows was measured against it "
        "rather than against nothing",
        len(document) > 1000,
    )
    controls = document_integrity.control_characters(document)
    report.check(
        f"it carries no stray control character, of which {controls} were found, so no "
        "markup macro has been silently turned into the character its escape names",
        controls == 0,
    )
    for line in document_integrity.split_macros(document):
        report.check(f"  line {line} ends in a lone backslash", False)
    report.check(
        "no line ends in a lone backslash, so no macro has been cut in half by the one "
        "escape the count above cannot see, the line break itself",
        not document_integrity.split_macros(document),
    )
    report.check(
        "its first line is a title at the top level, which is the one block the text "
        "carries without a number and so the one a renumbering cannot miss losing",
        document_integrity.carries_title(document),
    )
    stray_appendices = document_integrity.appendix_references_outside_it(document)
    for wanted in stray_appendices:
        report.check(
            f"  section {wanted} is referred to as an appendix but is not placed in one",
            False,
        )
    report.check(
        "every section the text calls an appendix is placed in the appendix, so a "
        "reference that merely resolves is not mistaken for one that is right",
        not stray_appendices,
    )

    ledger = entries(document)
    known = vocabulary(document)
    report.check(
        f"a ledger of {len(ledger)} rows was located in it, by matching a four column table "
        "against a two column declaration of the dispositions it uses",
        bool(ledger),
    )
    report.check(f"and the declaration offers {len(known)} dispositions", bool(known))
    if not ledger or not known:
        report.check(
            "the audit cannot proceed without both, and reports that as a failure rather "
            "than skipping",
            False,
        )
        return

    report.subsection("Every assumption the text asserts is in the ledger")
    asserted = asserted_in(document)
    missing = uncovered(document)
    report.check(f"the text asserts an assumption in {len(asserted)} sections", bool(asserted))
    for section in missing:
        report.check(
            f"  section {section} asserts an assumption the ledger does not cover", False
        )
    report.check("no section asserts an assumption the ledger does not cover", not missing)

    report.subsection("Every row is complete and uses a declared disposition")
    for entry in incomplete(document):
        report.check(f"  the row for section {entry.section} has an empty cell", False)
    report.check("no row is left with an empty cell", not incomplete(document))
    for entry in outside_vocabulary(document):
        report.check(
            f"  the row for section {entry.section} uses a disposition the text does not "
            "declare",
            False,
        )
    report.check(
        "no row invents a disposition of its own, which is what would let a ledger absorb "
        "an assumption by finding a comfortable word for it",
        not outside_vocabulary(document),
    )

    report.subsection("The shape of the ledger")
    total = 0
    for disposition in known:
        count = count_with(document, disposition)
        total += count
        report.check(f"  {disposition} : {count} rows", count >= 0)
    report.check(
        "every row carries one of the declared dispositions, so the rows are accounted for "
        "exactly once",
        total == len(ledger),
    )
