#!/usr/bin/env python3
"""Entry point for the article-analysis half of the test suite.

The other half is the C++ binary (build/superluminal): it checks the
physics, and as its last step writes build/quotations.json, the only bridge
this half needs to the numbers that physics computes. Everything that reads
article/article.md — the assumption ledger, the prose register, the citation
list, and the sync between quoted numbers and the values behind them — lives
here instead of in C++, because none of it is a computation: it is text
analysis, and Python's text tooling fits it better than hand-written
std::regex ever did. See tools/checks/prose_text.py for a concrete case this
port fixed along the way.

Run order mirrors main.cpp's section order exactly, so a reader comparing the
two finds the same four checks in the same place: AssumptionLedger,
ProseRegister, ArticleSync, CitationCoverage.
"""

from __future__ import annotations

import sys
from pathlib import Path

if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8")

sys.path.insert(0, str(Path(__file__).resolve().parent))

from checks import article_sync, assumption_ledger, citation_coverage, prose_register
from checks.report import Report

_SECTIONS = (
    ("Every assumption the text states, and what became of it", assumption_ledger.run),
    ("The register the text is held to", prose_register.run),
    ("The numbers the text quotes against the numbers computed", article_sync.run),
    ("The bibliography against the citations that point into it", citation_coverage.run),
)


def main() -> int:
    report = Report()
    for title, run in _SECTIONS:
        report.section(title)
        run(report)
    report.summary()
    return 0 if report.all_passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
