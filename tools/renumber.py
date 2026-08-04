"""Renumber every heading in reading order and repoint every reference.

Sections carry their own numbers in the text, so moving one leaves the numbers
disagreeing with the order. This rewrites the headings in document order, which
yields a mapping from the old identifier to the new one, and applies that
mapping to every reference: prose references, appendix references, and the first
column of any table whose cells are lists of section identifiers. The ledger the
verification reads is one of those tables, so it moves with the rest.

Each pass touches a line once. Prose replacement skips table rows, because
applying both it and the cell pass to the same text would map an already mapped
identifier a second time. That failure is quiet: the reference still resolves, it
just resolves somewhere else.

Skipping table rows in the prose pass is not on its own enough. A table row
carries two different kinds of reference: the first column may be a bare
identifier, and any later column may carry a prefixed reference in running text.
An earlier version of this script remapped only the first column, so a prefixed
reference sitting in a later column was left pointing at whatever section had
since taken its number. That is the same quiet failure from the other side, and
it happened: a row naming the section on reversed world lines kept its old number
after a subsection was inserted above it, and every check passed because the
number it now named also existed. Both parts of a row are therefore remapped
here, in one pass, and they cannot collide because the first column holds bare
identifiers while the remapping of the rest requires a prefix.

Numbering starts wherever the manuscript starts it rather than at one. A chapter
numbered zero is deliberate here: it carries the core calculation and stands
before the first chapter on purpose. An earlier version began counting at one
regardless, so running it shifted every chapter up by one, moved every reference
along with them, and reported that every reference resolved, which was true and
useless. That is the failure this whole file exists to prevent, arriving through
the one number nobody thought to allow for.

The mapping is also refused when one number sits on two headings, which is what
inserting a subsection by hand invites: the new heading is given the number the
old one had and the old one is pushed down, so the number appears twice, the
second occurrence replaces the first in the mapping, and every reference to it
follows whichever heading came last. That happened, and it left five references
pointing at a section inserted above the one they meant while the number they
named still existed. Numbering the inserted heading with something no heading
carries yet, and letting this script assign the order, is what avoids it.

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


def renumber(lines, repeated=None):
    """Rewrite headings in document order, returning the old to new mapping.

    A number appearing on two headings cannot be mapped, because the mapping is
    keyed on it and the second occurrence would silently replace the first. Every
    reference to that number would then follow whichever heading came last. The
    repeated numbers are collected so the caller can refuse to write.
    """
    mapping = {}
    first = next((m.group(1) for m in
                  (re.match(r"^## (\d+)\. ", line) for line in lines) if m), "1")
    section = int(first) - 1
    subsection = subsubsection = 0

    def record(old, new):
        if old in mapping and repeated is not None:
            repeated.add(old)
        mapping[old] = new

    for index, line in enumerate(lines):
        head = re.match(r"^## (\d+)\. (.*)$", line)
        if head:
            section += 1
            subsection = subsubsection = 0
            record(head.group(1), str(section))
            lines[index] = f"## {section}. {head.group(2)}"
            continue
        head = re.match(r"^### (\d+)\.(\d+)\.(\d+) (.*)$", line)
        if head:
            subsubsection += 1
            old = f"{head.group(1)}.{head.group(2)}.{head.group(3)}"
            new = f"{section}.{subsection}.{subsubsection}"
            record(old, new)
            lines[index] = f"### {new} {head.group(4)}"
            continue
        head = re.match(r"^### (\d+)\.(\d+) (.*)$", line)
        if head:
            subsection += 1
            subsubsection = 0
            old = f"{head.group(1)}.{head.group(2)}"
            new = f"{section}.{subsection}"
            record(old, new)
            lines[index] = f"### {new} {head.group(3)}"
    return mapping


def repoint_cells(lines, mapping, unmapped):
    """Rewrite references in table rows, first column and running text alike."""
    changed = 0

    def prefixed(match):
        prefix, number = match.group(1), match.group(2)
        if number in mapping:
            return prefix + mapping[number]
        unmapped.add(number)
        return match.group(0)

    for index, line in enumerate(lines):
        if not line.startswith("|"):
            continue

        match = CELL.match(line)
        if match:
            def bare(inner):
                value = inner.group(0)
                if value in mapping:
                    return mapping[value]
                unmapped.add(value)
                return value

            cell = re.sub(r"\d+(?:\.\d+)*", bare, match.group(2))
            if cell != match.group(2):
                changed += 1
            head = match.group(1) + cell + match.group(3)
            rest = line[match.end():]
        else:
            head = ""
            rest = line

        rewritten = re.sub(REFERENCE, prefixed, rest)
        if rewritten != rest:
            changed += 1
        lines[index] = head + rewritten
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


def repoint_wrapped(lines, mapping, unmapped):
    """Rewrite references whose prefix and number sit on different lines.

    The pass above works a line at a time and so cannot see them. They are taken
    here, on the pair of lines, which keeps the rule that each reference is
    touched exactly once: this pass only ever rewrites a number at the start of a
    line whose predecessor ends in a prefix, and that number carried no prefix of
    its own for the earlier pass to have matched.
    """
    changed = 0
    for index in range(len(lines) - 1):
        if lines[index].startswith("|") or lines[index + 1].startswith("|"):
            continue
        if not re.search(r"(?:Bölüm|§|Ek)\s*$", lines[index]):
            continue
        head = re.match(r"^(\s*)([0-9]+(?:\.[0-9]+)*)", lines[index + 1])
        if not head:
            continue
        number = head.group(2)
        if number not in mapping:
            unmapped.add(number)
            continue
        if mapping[number] != number:
            changed += 1
        lines[index + 1] = (head.group(1) + mapping[number] +
                            lines[index + 1][head.end():])
    return changed


def unresolved(text):
    """References pointing at a section the text does not contain.

    The prefix and the number are allowed to be separated by a line break,
    because the manuscript is hard wrapped and a reference that happens to fall
    on a boundary is still a reference. Matching on a literal space missed those
    entirely: they were neither remapped nor checked, and three of them pointed
    at sections that had never existed.

    A range written as one prefix and two numbers is also read, since only the
    first number carries the prefix and the second was invisible for the same
    reason.
    """
    have = set(re.findall(r"^#{2,3} ([0-9]+(?:\.[0-9]+)*)", text, re.M))
    refs = set(re.findall(r"(?:Bölüm|§|Ek)\s+([0-9]+(?:\.[0-9]+)*)", text))
    refs |= set(re.findall(
        r"(?:Bölüm|§|Ek)\s+[0-9]+(?:\.[0-9]+)*\s*[–-]\s*([0-9]+(?:\.[0-9]+)*)", text))
    return sorted(r for r in refs if r not in have)


def main() -> int:
    lines = io.open(PATH, encoding="utf-8").read().split("\n")
    repeated = set()
    mapping = renumber(lines, repeated)
    if repeated:
        print("numbers carried by more than one heading, nothing written:",
              sorted(repeated), file=sys.stderr)
        return 1
    unmapped = set()
    changed = repoint_cells(lines, mapping, unmapped)
    repoint_prose(lines, mapping, unmapped)
    wrapped = repoint_wrapped(lines, mapping, unmapped)
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
    print(f"wrapped references : {wrapped} repointed")
    print("references         : every one resolves")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
