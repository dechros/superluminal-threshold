import io
import re
import sys
import unicodedata

BAR = "|"
DASH = "-"


def cells(line):
    body = line.strip()
    assert body.startswith(BAR) and body.endswith(BAR)
    return [c.strip() for c in body[1:-1].split(BAR)]


def width(s):
    return sum(1 for ch in s if not unicodedata.combining(ch))


def is_row(line):
    s = line.strip()
    return s.startswith(BAR) and s.endswith(BAR) and s.count(BAR) >= 2


def is_rule(line):
    return is_row(line) and all(set(c) <= set(DASH + ":") and c for c in cells(line))


def render(row, widths):
    out = []
    for i, c in enumerate(row):
        out.append(" " + c + " " * (widths[i] - width(c) + 1))
    return BAR + BAR.join(out) + BAR


def align(lines):
    result = []
    index = 0
    changed = 0
    while index < len(lines):
        if not is_row(lines[index]):
            result.append(lines[index])
            index += 1
            continue
        start = index
        while index < len(lines) and is_row(lines[index]):
            index += 1
        block = lines[start:index]
        rows = [cells(line) for line in block]
        columns = max(len(r) for r in rows)
        if any(len(r) != columns for r in rows) or not any(is_rule(l) for l in block):
            result.extend(block)
            continue
        widths = [0] * columns
        for r in rows:
            for i, c in enumerate(r):
                if not (set(c) <= set(DASH + ":") and c):
                    widths[i] = max(widths[i], width(c))
        widths = [max(w, 3) for w in widths]
        for line, r in zip(block, rows):
            if is_rule(line):
                fixed = render([DASH * widths[i] for i in range(columns)], widths)
            else:
                fixed = render(r, widths)
            if fixed != line:
                changed += 1
            result.append(fixed)
    return result, changed


path = sys.argv[1]
text = io.open(path, encoding="utf-8").read()
lines = text.split("\n")
fixed, changed = align(lines)
print(changed, "satir hizalandi")
if "--write" in sys.argv and changed:
    io.open(path, "w", encoding="utf-8", newline="").write("\n".join(fixed))
