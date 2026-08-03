"""Renumber every heading in reading order and repoint every reference.

Sections carry their own numbers in the text, so moving one leaves the numbers
disagreeing with the order. This rewrites the headings in document order, which
yields a mapping from the old identifier to the new one, and applies that
mapping to every reference: prose references, appendix references, and the first
column of any table whose cells are lists of section identifiers. The ledger the
verification reads is one of those tables, so it moves with the rest.

Each pass touches a line once. Prose replacement skips table rows and cell
replacement only touches the first column, because applying both to the same
text would map an already mapped identifier a second time. That failure is quiet:
the reference still resolves, it just resolves somewhere else.

Nothing is written unless a reference cannot be mapped, a reference points at a
section that does not exist, and the text carries no stray control character.

Run from the repository root.
"""

import io
import re
import sys

PATH = "article/article.md"
CELL = re.compile(
    r"^(\|\s*)((?:Ek\s*)?\d+(?:\.\d+)*(?:\s*[,–-]\s*(?:Ek\s*)?\d+(?:\.\d+)*)*)(\s*\|)"
)
REFERENCE = r"(Bölüm |§|Ek )(\d+(?:\.\d+)*)"


def renumber(lines):
    """Rewrite headings in document order, returning the old to new mapping."""
    mapping = {}
    section = subsection = subsubsection = 0
    for index, line in enumerate(lines):
        head = re.match(r"^## (\d+)\. (.*)$", line)
        if head:
            section += 1
            subsection = subsubsection = 0
            mapping[head.group(1)] = str(section)
            lines[index] = f"## {section}. {head.group(2)}"
            continue
        head = re.match(r"^### (\d+)\.(\d+)\.(\d+) (.*)$", line)
        if head:
            subsubsection += 1
            old = f"{head.group(1)}.{head.group(2)}.{head.group(3)}"
            new = f"{section}.{subsection}.{subsubsection}"
            mapping[old] = new
            lines[index] = f"### {new} {head.group(4)}"
            continue
        head = re.match(r"^### (\d+)\.(\d+) (.*)$", line)
        if head:
            subsection += 1
            subsubsection = 0
            old = f"{head.group(1)}.{head.group(2)}"
            new = f"{section}.{subsection}"
            mapping[old] = new
            lines[index] = f"### {new} {head.group(3)}"
    return mapping


def repoint_cells(lines, mapping, unmapped):
    """Rewrite identifiers in the first column of reference tables."""
    changed = 0
    for index, line in enumerate(lines):
        match = CELL.match(line)
        if not match:
            continue

        def one(inner):
            value = inner.group(0)
            if value in mapping:
                return mapping[value]
            unmapped.add(value)
            return value

        cell = re.sub(r"\d+(?:\.\d+)*", one, match.group(2))
        if cell != match.group(2):
            changed += 1
        lines[index] = match.group(1) + cell + match.group(3) + line[match.end():]
    return changed


def repoint_prose(lines, mapping, unmapped):
    """Rewrite references in running text, leaving table rows alone."""
    def one(match):
        prefix, number = match.group(1), match.group(2)
        if number in mapping:
            return prefix + mapping[number]
        unmapped.add(number)
        return match.group(0)

    for index, line in enumerate(lines):
        if line.startswith("|"):
            continue
        lines[index] = re.sub(REFERENCE, one, line)


def unresolved(text):
    """References pointing at a section the text does not contain."""
    have = set(re.findall(r"^#{2,3} ([0-9]+(?:\.[0-9]+)*)", text, re.M))
    refs = set(re.findall(r"Bölüm ([0-9]+(?:\.[0-9]+)*)", text))
    refs |= set(re.findall(r"§([0-9]+(?:\.[0-9]+)*)", text))
    refs |= set(re.findall(r"Ek ([0-9]+)", text))
    return sorted(r for r in refs if r not in have)


def main() -> int:
    lines = io.open(PATH, encoding="utf-8").read().split("\n")
    mapping = renumber(lines)
    unmapped = set()
    changed = repoint_cells(lines, mapping, unmapped)
    repoint_prose(lines, mapping, unmapped)
    text = "\n".join(lines)

    if unmapped:
        print("unmapped references, nothing written:", sorted(unmapped), file=sys.stderr)
        return 1

    broken = unresolved(text)
    if broken:
        print("references to sections that do not exist:", broken, file=sys.stderr)
        return 1

    control = sum(1 for c in text if ord(c) < 32 and c != "\n")
    if control:
        print(f"{control} stray control characters, nothing written", file=sys.stderr)
        return 1

    io.open(PATH, "w", encoding="utf-8", newline="\n").write(text)
    moved = [f"{k}->{v}" for k, v in mapping.items() if "." not in k and k != v]
    print(f"headings mapped   : {len(mapping)}")
    print(f"sections moved    : {len(moved)}  {' '.join(moved)}")
    print(f"table cells        : {changed} repointed")
    print("references         : every one resolves")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
