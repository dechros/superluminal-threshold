"""Collects the outcome of a run and prints it as it goes.

A run is a sequence of named checks grouped under headings. Each check is
recorded as it is made and printed immediately, so a run that aborts still
leaves everything it had established on the terminal. The totals are kept
alongside, and the process exit code is taken from them rather than from
whether the run reached its end.

Mirrors src/core/Report.h/.cpp exactly, so the article-analysis half of the
test suite (this package) and the physics half (the C++ binary) print in the
same shape and can be read as one run even though they are two processes.
"""

from __future__ import annotations

import math


class Report:
    default_tolerance = 1e-9

    def __init__(self) -> None:
        self._passed = 0
        self._failed = 0

    def section(self, title: str) -> None:
        print()
        print("=" * 64)
        print(f"  {title}")
        print("=" * 64)

    def subsection(self, title: str) -> None:
        print(f"\n-- {title}")

    def check(self, claim: str, condition: bool) -> None:
        self._record(claim, condition, "")

    def check_near(self, claim: str, residual: float, tolerance: float = default_tolerance) -> None:
        finite = math.isfinite(residual)
        ok = finite and abs(residual) <= tolerance
        detail = (
            f"(residual {residual:.3e}, tolerance {tolerance:.0e})"
            if finite
            else f"(residual {residual}, tolerance {tolerance:.0e})"
        )
        self._record(claim, ok, detail)

    def summary(self) -> None:
        print()
        print("=" * 64)
        if self._failed == 0 and self._passed == 0:
            print("  NOTHING WAS CHECKED")
        elif self._failed == 0:
            print(f"  ALL PASSED: {self._passed} checks")
        else:
            print(f"  FAILED: {self._failed} of {self.total} checks")
        print("=" * 64)

    @property
    def all_passed(self) -> bool:
        return self._failed == 0

    @property
    def passed(self) -> int:
        return self._passed

    @property
    def failed(self) -> int:
        return self._failed

    @property
    def total(self) -> int:
        return self._passed + self._failed

    def _record(self, claim: str, ok: bool, detail: str) -> None:
        if ok:
            self._passed += 1
        else:
            self._failed += 1
        line = ("  [ok]   " if ok else "  [FAIL] ") + claim
        if not ok and detail:
            line += "   " + detail
        print(line)
