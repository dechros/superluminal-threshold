"""Prepare the manuscript for a LaTeX build.

The manuscript uses a single hash for two different things: the document title
on the first line, and the parts that group the sections. A converter maps both
to the same level, so the title would become a section and the parts would
disappear into the section sequence. This separates them, writing the title into
a metadata block and each part as a raw part command.

Sections carry their own numbers in the text, so automatic numbering is left off
and the numbers in the headings are the ones that print.

Both title and subtitle are quoted in the metadata, because either may contain a
colon and a bare value with one is not valid there.

Writes the prepared source and the metadata block, and reports what it found.
"""

import io
import re
import sys

SUBTITLE = "Öte tarafta mekânda mesafe kat etme yolunun hesabı"


def main(source: str, prepared: str, metadata: str) -> int:
    lines = io.open(source, encoding="utf-8").read().split("\n")

    if not lines or not lines[0].startswith("# "):
        print("the first line is expected to carry the title", file=sys.stderr)
        return 1
    title = lines[0][2:].strip()

    out = []
    parts = 0
    for line in lines[1:]:
        part = re.match(r"^# (.+)$", line)
        if part:
            parts += 1
            out.append("")
            out.append("\\part{" + part.group(1).strip() + "}")
            out.append("")
            continue
        out.append(line)

    io.open(prepared, "w", encoding="utf-8", newline="\n").write("\n".join(out))
    io.open(metadata, "w", encoding="utf-8", newline="\n").write(
        "---\n"
        f'title: "{title}"\n'
        f'subtitle: "{SUBTITLE}"\n'
        "lang: tr\n"
        "---\n"
    )
    print(f"title : {title}")
    print(f"parts : {parts}")
    print(f"lines : {len(out)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1], sys.argv[2], sys.argv[3]))
