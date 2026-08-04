import io
import re
import sys

WIDTH = 80


def is_prose(line):
    s = line.strip()
    if not s:
        return False
    if s.startswith(("|", "#", "$$", "```", "!")):
        return False
    if re.match(r"^[-*+]\s", s):
        return False
    if re.match(r"^\d+[.)]\s", s):
        return False
    if line.startswith((" ", "\t")):
        return False
    if s == "---":
        return False
    return True


def wrap(words, prefix=""):
    out = []
    line = ""
    for word in words:
        if not line:
            line = prefix + word
        elif len(line) + 1 + len(word) <= WIDTH:
            line += " " + word
        else:
            out.append(line)
            line = prefix + word
    if line:
        out.append(line)
    return out


path = sys.argv[1]
lines = io.open(path, encoding="utf-8").read().split("\n")

result = []
index = 0
inside_math = False
changed = 0
while index < len(lines):
    line = lines[index]
    if line.strip().startswith("$$") and line.strip() != "$$":
        result.append(line)
        index += 1
        continue
    if line.strip() == "$$":
        inside_math = not inside_math
        result.append(line)
        index += 1
        continue
    if inside_math or not is_prose(line):
        result.append(line)
        index += 1
        continue
    start = index
    while index < len(lines) and is_prose(lines[index]):
        index += 1
    block = lines[start:index]
    quoted = all(l.lstrip().startswith(">") for l in block)
    if quoted:
        words = " ".join(l.lstrip().lstrip(">").strip() for l in block).split()
        wrapped = wrap(words, "> ")
    else:
        words = " ".join(block).split()
        wrapped = wrap(words)
    if wrapped != block:
        changed += 1
    result.extend(wrapped)

print(changed, "paragraf yeniden sarildi")
if "--write" in sys.argv:
    io.open(path, "w", encoding="utf-8", newline="").write("\n".join(result))
