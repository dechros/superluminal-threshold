"""Fails when a file includes a header from a layer above its own.

Layers, lowest first: core, physics, particle, journey; above them checks,
gui and app, which may include anything below. Within the library layers a
file may include its own layer and the ones beneath it, never one above.
"""

import pathlib
import re
import sys

LAYERS = {"core": 0, "physics": 1, "particle": 2, "journey": 3}
TOP = {"checks": 4, "gui": 4, "app": 5}
INCLUDE = re.compile(r'^\s*#include\s+"([^"]+)"', re.M)


def layer_of(path: pathlib.Path, root: pathlib.Path) -> tuple[str, int]:
    parts = path.relative_to(root).parts
    if parts[0] == "src":
        return parts[1], LAYERS[parts[1]]
    return parts[0], TOP[parts[0]]


def included_layer(include: str) -> int | None:
    head = include.split("/")[0]
    if head in LAYERS:
        return LAYERS[head]
    return None


def main() -> int:
    root = pathlib.Path(sys.argv[1]).resolve()
    files = [p for d in ("src", "checks", "gui", "app") for p in (root / d).rglob("*") if p.suffix in {".h", ".cpp"}]
    failures = []
    for path in files:
        name, rank = layer_of(path, root)
        for include in INCLUDE.findall(path.read_text()):
            target = included_layer(include)
            if target is not None and target > rank:
                failures.append(f"{path.relative_to(root)} ({name}) includes {include}")
    for line in failures:
        print(line)
    print(f"{len(files)} files checked, {len(failures)} upward includes")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
