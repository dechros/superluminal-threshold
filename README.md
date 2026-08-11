# superluminal-threshold

A C++26 simulation of a massive particle crossing the light-speed threshold as a continuous process, with every claim checked by the program itself.

## What it simulates

The threshold between ordinary (subluminal) matter and its superluminal counterpart is modeled as a continuous crossing rather than an instantaneous jump:

1. **Below light speed.** The particle starts as an ordinary object, governed by the standard dispersion relation `omega(k) = c*sqrt(k^2 + mu)`.
2. **The threshold itself.** A new coordinate, the crossing angle `theta`, interpolates the spacetime metric from the near-side signature to the far-side one, `g(theta) = eta * cos(2*theta)`. At `theta = pi/4` the metric is degenerate; a fixed-mass particle has no real momentum past that point. A constant force added to the mass shell (the same constrained-Hamiltonian technique used in step 4) drives `theta` through the degenerate point with no singularity and no turning back.
3. **Above light speed.** Once `theta` reaches `pi/2` the particle is on the far side, whose coordinates are `(t1, t2, t3, r)`: three time axes and one space axis. The discrete map between the two sides is found by scanning all 384 signed permutation matrices down to the 8 that survive every structural constraint, split evenly into a forward-sending and a backward-sending family.
4. **Motion on the far side.** Along the far side's single space axis, a constant force drives the particle to any target distance in finite, closed form — the same mechanism as step 2, applied earlier in the project's history to this axis.
5. **The return.** The same kind of force, applied in reverse, brings `theta` back from `pi/2` to `0`. The map between the two sides is an involution, so energy, momentum magnitude and mass return to their exact starting values; only direction can differ.
6. **The clock.** A distance `s` covered on the far side advances the near-side clock by exactly `s` (coefficient 1, verified across all 8 admissible matrices), so the return happens earlier than it otherwise would by an amount that scales linearly with `s` — one metre buys about 3.34 nanoseconds.

The force in steps 2 and 4 is posited, not derived: it is not known what produces it. That gap is the one place this simulation is explicit about being a consistent model rather than a demonstrated mechanism.

## Layout

- `src/dynamics/` — dispersion relations on both sides, and the threshold field's metric family.
- `src/particle/` — the two constant-force crossings (threshold angle, far-side space axis) and the coordinate map between sides.
- `src/scan/` — the exhaustive permutation scan and its forward/backward classification.
- `src/transform/`, `src/intermediate/`, `src/units/` — the discrete involution, the intermediate-region geometry, physical unit conversions.
- `src/core/` — `Report` (pass/fail bookkeeping) and `Section` (one unit of verification), shared by everything above.

## Adding a section

Implement `Section` (`title()`, `run(Report&)`) and add one line to `buildSections()` in `main.cpp`. There is no registration macro and no global state.

## Build

- Linux/Windows (MSYS2), g++ with `-std=c++26`
- Standard library only, no external dependencies

```bash
make -j          # release -> build/superluminal
make -j debug    # debug   -> build/superluminal-debug
make run         # build release and run it
make clean
```

Sources compile to separate objects under `build/obj`, so a full build takes a few seconds and a single-file change under a second. Header dependencies are tracked with `-MMD -MP`.

## Run

```bash
./build/superluminal
```

Output is one block per section, each listing its checks as pass or fail lines, ending in a summary. Exit code is `0` only when every check passes.
