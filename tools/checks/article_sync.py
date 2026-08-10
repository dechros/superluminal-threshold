"""Whether the numbers the text quotes are the numbers the libraries compute.

A manuscript and the code behind it drift apart in one direction only. A
number is computed, written into the text, and then the calculation changes;
the text keeps the old value and nothing complains, because nothing was
watching. Every other check here guards the code against itself. This one
guards the text against the code.

The computed side of each quotation is not reproduced here: it is exported by
the C++ binary, which is the one place the physics is defined, into
build/quotations.json. This module owns only the other half, the exact
string the article is expected to contain, and does the comparison. Keeping
the formula itself out of this file is the point: a Python copy of the
formula would drift from the C++ original exactly the way the article's
prose can drift from either, and the whole class of check exists to catch
that kind of silent divergence, not to add another instance of it.

Mirrors the checking half of src/critique/ArticleSync.h/.cpp. The computing
half (ArticleSync::quotations(), previously wired to PhysicalScales) now
lives at the end of main.cpp as the small export that produces
build/quotations.json.
"""

from __future__ import annotations

import json
import math
from dataclasses import dataclass
from pathlib import Path

from .report import Report


@dataclass
class Quotation:
    subject: str
    computed: float
    as_written: str


# The exact string the article must contain for each quantity, written the
# way the article writes numbers (a comma for the decimal separator). The
# subject keys must match the ones the C++ export in main.cpp writes.
_AS_WRITTEN = {
    "the light-year distance a year of advance costs": "9{,}46",
    "the nanoseconds a metre of far-side travel buys": "3{,}34",
}


def load_quotations(quotations_path: Path) -> tuple[list[Quotation], list[str]]:
    """Quotations paired with their computed value, and subjects the export
    was expected to carry but did not."""
    computed: dict[str, float] = {}
    errors: list[str] = []
    try:
        computed = json.loads(quotations_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        errors.append(f"quotations file could not be read: {error}")

    quotations = []
    for subject, as_written in _AS_WRITTEN.items():
        if subject not in computed:
            errors.append(f"the export carries no value for: {subject}")
            continue
        quotations.append(Quotation(subject, computed[subject], as_written))
    return quotations, errors


def text_contains(document: str, needle: str) -> bool:
    return needle in document


def missing(document: str, quotations: list[Quotation]) -> list[str]:
    return [q.subject for q in quotations if not text_contains(document, q.as_written)]


def _written_value(text: str) -> float:
    return float(text.replace("{,}", "."))


def _mantissa(value: float) -> float:
    if value == 0.0:
        return 0.0
    decade = math.floor(math.log10(abs(value)))
    return value / (10.0**decade)


def _significant_digits(written: str) -> int:
    digits = 0
    started = False
    i = 0
    while i < len(written):
        if written[i : i + 3] == "{,}":
            i += 3
            continue
        if written[i].isdigit():
            if written[i] == "0" and not started:
                i += 1
                continue
            started = True
            digits += 1
        i += 1
    return digits


def _rounded_to(value: float, written: str) -> float:
    digits = _significant_digits(written)
    factor = 10.0 ** max(0, digits - 1)
    return round(value * factor) / factor


def written_matches_computed(quotation: Quotation) -> bool:
    written = _written_value(quotation.as_written)
    value = _mantissa(quotation.computed)
    stated = _mantissa(written)
    return abs(_rounded_to(value, quotation.as_written) - stated) < 1e-9


def stale(quotations: list[Quotation]) -> list[str]:
    return [q.subject for q in quotations if not written_matches_computed(q)]


def run(
    report: Report,
    article_path: Path = Path("article/article.md"),
    quotations_path: Path = Path("build/quotations.json"),
) -> None:
    try:
        text = article_path.read_text(encoding="utf-8")
    except OSError:
        text = ""
    quotations, errors = load_quotations(quotations_path)

    report.subsection("The article is readable and quotes calculated numbers")
    report.check("the article was located and read", bool(text))
    for error in errors:
        report.check(f"  {error}", False)
    report.check(
        f"{len(_AS_WRITTEN)} numbers in it are quoted from a calculation",
        not errors and bool(quotations),
    )
    if not text or errors:
        return

    report.subsection("Every quoted number appears in the text as written")
    absent = missing(text, quotations)
    for subject in absent:
        report.check(f"  {subject} is not in the text as written", False)
    report.check(
        "no quoted number is absent from the text, so a calculation reported here cannot "
        "be one the text never received",
        not absent,
    )

    report.subsection("Every quoted number still agrees with its calculation")
    for quotation in quotations:
        report.check(
            f"  {quotation.subject:<38} : text says {quotation.as_written}, calculation "
            f"gives {quotation.computed:.6e}",
            written_matches_computed(quotation),
        )
    report.check(
        "no quoted number has drifted from the value the libraries now compute, which is "
        "the one direction a manuscript and its code part company in",
        not stale(quotations),
    )
