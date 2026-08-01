# superluminal-signature-change

C++26 console application that runs a suite of symbolic-style verifications for a discrete-involution model of signature change. Each section of the model is a class implementing a common `Section` interface; `main` runs them in order and prints a pass/fail line per claim, exiting non-zero if any claim fails. There are 191 verifications in total.

Originally a pile of `sympy` scripts. The port replaces symbolic algebra with a small fixed-size linear algebra layer - the matrices involved are integer-valued, so involution, determinant and permutation tests are exact in `double`.

The derivations live in `article/article.md`, which is the written statement of the model; the code is its verification. The two are kept in step: every claim the article makes is checked here, and every check here appears there. Headers carry Doxygen documentation of the software only.

`article/article.md` is written in Turkish and is the only Turkish file in the repository. Everything else, including console output, is English.

## Adding a section

Implement `Section` - `number()`, `title()`, `run(Report&)` - and add one line to `buildSections()` in `main.cpp`. Nothing else is wired up; there is no registration macro and no global state.

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

Output is one block per section, each listing its verifications as pass or fail lines. The final block is a summary reporting how many passed and how many failed. Exit code is `0` only when every verification passes.

## What the model is

Dragan et al. (Class. Quantum Grav. 40 (2023) 025013) extend special relativity to superluminal observers in 1+3 spacetime, where the metric becomes 3+1. This project factors their superboost into `M(V) = D * B(c^2/V)`, with `D` a constant parameter-free involution carrying the signature change and `B` an ordinary subluminal Lorentz boost carrying the velocity, then works out the consequences: group closure, the energy/momentum swap, an ill-posed Cauchy problem on the far side, a reflecting threshold surface, and a closed-form spherical solution. The critique sections implement the counter-arguments too, including Sylvester's law of inertia, which rules out a real transformation flipping the signature outright.
