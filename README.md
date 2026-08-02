# superluminal-threshold

A model of the interface between two metric signatures, and a C++26 program that verifies every claim it makes.

Beyond the speed of light the metric of a superluminal frame turns from one time and three spaces into three times and one space. This project does not try to build a full theory of either region. It builds the theory of the surface between them: what crosses it, what does not, under which junction condition, at which thickness, and which of those answers are forced rather than chosen. That is the method of the junction-condition literature in general relativity, and it is where the results here are strongest.

The written statement of the model is `article/article.md`, in Turkish. The code is its proof. The two are kept in step in both directions: every claim the article makes is checked here, and every check here appears there. `article/article.md` is the only Turkish file; everything else, including the console output, is English.

## What it establishes

- Total reflection at the threshold is the only solution of flux conservation, not an added assumption, and it holds for every self-adjoint boundary condition rather than just the one chosen.
- That result covers an unbounded far side. A slab of finite thickness transmits an exponentially suppressed but non-zero amount, so total reflection is the thick-slab limit.
- A future and past split exists exactly when a region has one time direction, which is why the arrow disappears beyond the threshold rather than reversing.
- Degeneracy on any continuous path between the two signatures is unavoidable, but a rank-two degeneracy is not: a staged path through signature (2,2) needs only rank one at every point.
- Geometry permits the crossing that the field forbids, since the two metrics differ by a sum of squares and every timelike direction survives.

The article also records what it does not establish. Gravity enters only at the level of the junction condition, the location of the transition is posited rather than derived, and the one discriminating prediction needs an apparatus nobody can build.

## Literature

`literature/` holds 199 papers as markdown, one file each, with front matter and full text taken from the arXiv LaTeX source so that equations survive. `literature/literature-notes.md` records what each one establishes and whether it precedes, supports, or contradicts a section of the article. Priority is stated in the article wherever a result was obtained earlier by someone else.

## Adding a section

Implement `Section` - `number()`, `title()`, `run(Report&)` - and add one line to `buildSections()` in `main.cpp`. Nothing else is wired up; there is no registration macro and no global state. Verifications belong in C++ and nowhere else.

## Platform

- Linux, g++ with `-std=c++26` (tested on GCC 16)
- Standard library only, no external dependencies

## Build

Driven by VS Code tasks in `.vscode/tasks.json`, which call the `Makefile`:

- **Release Build** - `make -j release` → `build/superluminal` (default build task)
- **Debug Build** - `make -j debug` → `build/superluminal-debug`
- **Run** - depends on Release Build, then runs the binary

`launch.json` provides a gdb configuration that builds debug first.

From a terminal:

```bash
make -j          # release
make -j debug
make run
make clean
```

Sources compile to separate objects under `build/obj`, so a full build takes about 10 s on 8 cores and a single-file change about 3 s. Header dependencies are tracked with `-MMD -MP`.

## Run

```bash
./build/superluminal
```

Output is one block per section, each listing its verifications as pass or fail lines. The final block reports how many passed and how many failed. Exit code is `0` only when every verification passes.
