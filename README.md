# superluminal-threshold

A C++26 simulation of moving a particle backwards in time: send it across the light-speed threshold, drive it a distance on the far side, bring it back, and find it earlier than it left. Every claim is checked by the program itself.

## What it simulates

Displacing a particle in time is the aim, and the six steps below are what the aim requires. The time gained is set entirely by step 4, the distance covered on the far side; steps 2, 3 and 5 exist because reaching that side and returning from it are what make the distance available. The threshold is treated as a continuous crossing rather than an instantaneous jump:

1. **Below light speed.** The particle starts as an ordinary object, governed by the standard dispersion relation `omega(k) = c*sqrt(k^2 + mu)`.
2. **The threshold itself.** A new coordinate, the crossing angle `theta`, interpolates the spacetime metric from the near-side signature to the far-side one, `g(theta) = eta * cos(2*theta)`. At `theta = pi/4` the metric is degenerate; a fixed-mass particle has no real momentum past that point. A constant force added to the mass shell (the same constrained-Hamiltonian technique used in step 4) drives `theta` through the degenerate point with no singularity and no turning back.
3. **Above light speed.** Once `theta` reaches `pi/2` the particle is on the far side, whose coordinates are `(t1, t2, t3, r)`: three time axes and one space axis. The discrete map between the two sides is found by scanning all 384 signed permutation matrices down to the 8 that survive every structural constraint. A fourth filter, handedness, cuts those 8 to 4: three far-side coordinates carry free motion onto the three near-side directions that also carry free motion, and a map reached as the endpoint of a continuous crossing cannot reflect them, because a reflection is not connected to the identity in the rotation group. The determinant of that block and the sign of the near-side time multiply to `-1` in all eight, so the filter settles both at once.
4. **Motion on the far side.** Along the far side's single space axis, a constant force drives the particle to any target distance in finite, closed form — the same mechanism as step 2, applied earlier in the project's history to this axis.
5. **The return.** The same kind of force, applied in reverse, brings `theta` back from `pi/2` to `0`. The map between the two sides is an involution, so energy, momentum magnitude and mass return to their exact starting values; only direction can differ.
6. **The clock.** A distance `s` covered on the far side moves the near-side clock by exactly `s`, and by the handedness filter of step 3 it moves it backwards, so the return happens earlier than it otherwise would by an amount that scales linearly with `s` — one metre buys about 3.34 nanoseconds. The direction is a result of the filters rather than a choice made after them.

## The mechanism: accelerating and decelerating, and nothing else

The crossing angle is not a field and not an extra coordinate. It is the particle's own speed, written as `beta = tan(theta)`. That single identification fixes the whole geometry without anything being arranged to fit:

| angle | speed | metric |
|---|---|---|
| `0` | rest | near-side signature |
| `pi/4` | `beta = 1` | **degenerate** |
| `pi/2` | infinite | far-side signature |

because the family's scale factor becomes a function of the speed alone,

    cos(2*theta) = (1 - beta^2) / (1 + beta^2)

which is positive below light speed, zero at it and negative above. Accelerating the particle *is* driving the metric towards its degenerate point; the two are one operation. The same dictionary explains the scan's result from the other direction: the discrete involution reflects the angle about `pi/4`, and the reflection reads `beta -> 1/beta` in speeds, which is the `v' = c^2/v` the involution section reached by a different route.

**The standard shell forbids the crossing, and the program proves it rather than avoiding it.** Under constant proper acceleration `theta(tau) = arctan(tanh(a*tau/c))`, which stays below `pi/4` for every finite proper time. The failure is not the force running out — the force is never withdrawn — but the angle stalling: its rate falls off like `sech^2(a*tau/c)`, and the energy demanded is the Lorentz factor, `7.07e5` rest energies at a part in a million million short of light speed.

**The obstruction is located exactly, and it is the metric's own degeneracy.** The energy diverges as `1/sqrt(cos(2*theta))`, and `cos(2*theta)` is the factor that degenerates. What stays finite through the point is the energy weighed against the degenerating metric rather than against the near-side one: `E^2*cos(2*theta) = (m*c^2)^2*cos^2(theta)`, which is exactly one half of the squared rest energy at light speed.

**Under the extended shell the accelerated particle arrives.** The work the accelerating force does through the angle enters the shell linearly, `p^2/c^2 = mu + 2*F*theta`, so the momentum demanded at light speed is `c*sqrt(mu + pi*F/2)` — a finite number, verified across nine combinations of mass and force, each reaching `beta = 1` at a finite parameter, subluminal just before it and superluminal just after.

**The return needs nothing of its own.** Reversing the accelerating force reflects the angle about `pi/4`, and the reflection fixes that angle, so the decelerating particle falls back through light speed at exactly the parameter the outward flight reached it, then comes to rest at the parameter the outward crossing took. The mass parameter it arrives with is the one it left with, because the shell at angle zero carries no work term.

The one posited element left is the shell itself: the required energy scales linearly in the angle instead of divergently. The claim is about the shell, not about a force, and the program states the standard shell's verdict alongside it.

## An earlier reading of the same constant

The section below reads the same constant `F` as a coupling to a scalar condensate rather than as the accelerator's force. The two readings compete: only one of them can be the mechanism, and the account above is the one the project keeps. What follows is retained for the geometry it fixes, not as a second way across.

The crossing angle is treated as a real scalar field with the potential `U(theta) = Lambda^4 sin^2(2theta)`, whose two minima are the two regions and whose single maximum falls at `theta = pi/4`, the same angle at which the metric degenerates — neither was arranged to match the other. With that potential the static field equation is sine-Gordon in `4*theta` and has a kink,

    theta(x) = arctan(exp(x/L)),    L = sqrt(lambda / 8*Lambda^4)

which is a solution rather than a choice. Three things follow that a posited force could not give:

- **The width is fixed** by the field's stiffness and potential scale instead of being free, and the far side is reached at a distance growing only as `L*ln(1/tolerance)`.
- **The slope is largest exactly at the degenerate point**, `theta'(0) = 1/2L`, so a particle crossing spends its least distance where the metric is worst. This is the reverse of a barrier, and it is what reconciles the two sections that used to disagree: a degenerate *layer* of thickness `w` suppresses a mode by `exp(-2*sqrt(mu)*w)` and blocks, while the set the crossing meets has width `2L*artanh(epsilon)`, which vanishes with `epsilon`. A blocking layer is not merely absent but excluded, since it would require the field to rest on a maximum of its own potential.
- **The constant comes out numerically the same.** A linear coupling to the field is an ordinary Yukawa term, giving `mu(theta) = mu + 2*F*theta`, and one half the slope of that mass parameter equals the constant the crossing sections use, to twelve digits. The agreement is arithmetic and settles nothing about what the constant *is*: the project reads it as the accelerating force.

What remains posited is the scalar sector itself — its potential scale, its stiffness, and the coupling by which a particle feels it. Those are the ordinary ingredients of a field theory rather than a force invented for one trajectory, and that is the whole of the improvement claimed.

## Both directions, and what the crossing costs them

The far side's space axis carries a sign, so one apparatus reaches both directions in time: drive one particle along `+r` and it returns before it left, drive a second the same distance along `-r` and it returns after, by the same amount. Nothing but the sign of the far-side displacement distinguishes them.

The crossing is not free, and it breaks the symmetry. Reaching the far minimum means traversing a wall of finite thickness, which costs `L*ln(1/tolerance)/(beta*c)` of near-side time going in and the same coming out. That delay is positive for both particles and is blind to which way either was driven, so it **subtracts** from the backward one and **adds** to the forward one:

    dt(+r) = -s/c + 2*tau
    dt(-r) = +s/c + 2*tau

Three consequences follow, and the first two are not symmetric:

- **Forward in time needs no minimum distance.** The delay pushes the `-r` particle further the way it was already going, so any distance works, including none.
- **Backward in time has a break-even distance**, `s* = 2*L*ln(1/tolerance)/beta`, where the far-side travel and the round trip through the wall cancel exactly. Short of `s*` the apparatus returns both particles later than they left and displaces neither one backward. In units of the wall's own width `s*` is a pure number: 37.2 for a tolerance of `1e-8` at `0.99c`. For a wall of field-theory thickness that is about `3.7e-14` m, so the delay decides nothing at laboratory distances — but it decides everything for a thick wall.
- **The gap between the two particles is free of the delay.** It is `2*s/c` — 6.67 ns for a metre — and the shared delay cancels in the difference exactly, across every wall width, tolerance and crossing speed tried. Either particle read alone requires knowing `tau`; the pair does not. What limits the pair instead is preparing both to the same speed: crossing at `0.5c` against `0.99c` leaves `1.2e-22` s of the delay behind in the gap.

## The relabelling objection

The far metric is the near one with every sign reversed and the slots permuted, and no property of a metric alone separates them: they even share a determinant. What the objection leaves out is that a region is a metric *together with the matter in it*. The mass shell reads `p^T g p = mu*c^2`, the relabelling acts on `g`, and `mu` belongs to the particle. Counting the coordinate axes that admit a real on-shell momentum gives 1 on the near side and 3 on the far side for the same ordinary particle, and carrying the shell's solutions through the relabelling demands `mu -> -mu`, which is not a change of convention but an imaginary mass. A second obstruction needs no particle: along the metric family the count of positive entries changes only at the degenerate angle, so the two regions lie in different components of the nondegenerate metrics.

The claim is conditional and the condition is stated rather than hidden: were a particle of negative mass parameter available, the two regions would be the same region.

## Layout

- `src/dynamics/` — dispersion relations on both sides, and the threshold field's metric family.
- `src/mechanism/` — the domain wall: the potential, the kink that solves its field equation, and the coupling that turns the applied force into a mass.
- `src/particle/` — the two constant-force crossings (threshold angle, far-side space axis) and the coordinate map between sides.
- `src/scan/` — the exhaustive permutation scan, its forward/backward classification, and the handedness filter that decides between them.
- `src/transform/`, `src/intermediate/`, `src/units/` — the discrete involution, the answer to the relabelling objection, the intermediate-region geometry, the width of the degenerate set, physical unit conversions.
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
