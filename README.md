# superluminal-threshold

A C++26 simulation of moving a particle backwards in time: send it across the light-speed threshold, drive it a distance on the far side, bring it back, and find it earlier than it left. Every claim is checked by the program itself.

## What it simulates

Displacing a particle in time is the aim, and the six steps below are what the aim requires. The time gained is set entirely by step 4, the distance covered on the far side; steps 2, 3 and 5 exist because reaching that side and returning from it are what make the distance available. The threshold is treated as a continuous crossing rather than an instantaneous jump:

1. **Below light speed.** The particle starts as an ordinary object, governed by the standard dispersion relation `omega(k) = c*sqrt(k^2 + mu)`.
2. **The threshold itself.** A new coordinate, the crossing angle `theta`, interpolates the spacetime metric from the near-side signature to the far-side one, `g(theta) = eta * cos(2*theta)`. At `theta = pi/4` the metric is degenerate; a fixed-mass particle has no real momentum past that point. A constant force added to the mass shell (the same constrained-Hamiltonian technique used in step 4) drives `theta` through the degenerate point with no singularity and no turning back.
3. **Above light speed.** Once `theta` reaches `pi/2` the particle is on the far side, whose coordinates are `(t1, t2, t3, r)`: three time axes and one space axis. The discrete map between the two sides is found by scanning all 384 signed permutation matrices down to the 8 that survive every structural constraint. A fourth filter, handedness, cuts those 8 to 4: three far-side coordinates carry free motion onto the three near-side directions that also carry free motion, and a map reached as the endpoint of a continuous crossing cannot reflect them, because a reflection is not connected to the identity in the rotation group. The determinant of that block and the sign of the near-side time multiply to `-1` in all eight, so the filter settles both at once.
4. **Motion on the far side.** Along the far side's single space axis, a constant force drives the particle to any target distance in finite, closed form — the same mechanism as step 2, applied earlier in the project's history to this axis.
5. **The return.** The return is the time reverse of the outward leg: the far-side momentum is reflected and the same force carries the particle back along the same curve, so `theta` falls from `pi/2` to `0`, both Hamilton equations hold on the way, and energy, momentum magnitude and mass return to their exact starting values; only direction can differ.
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

**The return needs nothing of its own.** It is the outward curve run backwards, with the far-side momentum reflected: the decelerating particle falls back through light speed at the outward crossing parameter less the outward luminal one, then comes to rest at the parameter the outward crossing took. The mass parameter it arrives with is the one it left with, because the shell is the same shell and the state at the end of the reversed curve is the state at the start of the forward one.

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

## Six round trips, six ways across, and a viewer

`src/journey/` sends three travellers on the whole trip, each along `+r` (backward in time) and along `-r` (forward): a massless particle, a hydrogen atom and a methane molecule with its five atoms placed. All six are run by `RoundTripSection` and every leg is checked: the shell on the outward leg, the signed far-side branch, the join at `pi/2`, both Hamilton equations on the return by central difference, and the state at return. Three results are specific to this section:

- **The massless traveller is born at light speed.** It has no rest frame, so its start angle is `pi/4` and its entry momentum is exactly `c*sqrt(pi*F/2)`, the momentum the massive crossing demands at light speed. Anchoring the shell there with `mu = 0` is the one posited element added: the massless traveller enters in the state a massive one passes through. It needs no acceleration up to the threshold, only away from it.
- **A molecule becomes a pattern in time.** Its atoms' offsets land entirely in the far side's three times, with no spread along `r`, so the molecule is a point in far-side space and an extended object in far-side time; every atom receives the same clock shift, every bond length returns unchanged, and the signed volume of the labelled bonds keeps its sign, so handedness survives the trip. A metre along `r` shifts the clock by 3.34 ns whether a massless particle or a molecule travelled.
- **The handoff between the legs is stated.** The crossing ends with the angle's momentum at `p(sigma_out)`; that momentum is held while the angle stands at `pi/2`, and the return starts from it reflected. The far-side drive starts from the shell's rest state there, with no energy along the three time axes, because any such energy would move the traveller along what is the near side's space and it would not return to the place it left. Two elements are posited in all of this and nothing else: the extended shell, and the massless traveller's entry at the threshold.
- **Two readings of what the crossing costs are kept side by side.** Under the field-wall reading the threshold has a width and the round trip through it costs a delay; under the velocity reading the threshold has no width, and the map's contribution is the whole shift. The gap between the forward and backward trips is `2s/c` under both.

`CrossingMethodsSection` tries six ways across on each traveller and says what each mechanics supplies, what completes it, and what it costs: Newtonian passage with no speed limit (completed by the signature change), the standard shell (completed by the extended one), the extended shell under a constant force (complete by itself), bending the metric through its degenerate point (completed by reversing the shell with it, at the tension of the wall it creates), bending it with the shell reversed (complete, but external to the traveller), and quantum tunnelling across a degenerate layer (lossless for the massless traveller, completed by a far-side state to land in). The way chosen for each traveller is the complete one of least cost that needs nothing beyond the traveller and its accelerator; it is the extended shell for all three, started from the threshold for the massless traveller and through it for the other two. The list is open: a way is admitted when its mathematics closes.

`JourneyState` samples the trip at any progress for the viewer, and `JourneyStateSection` checks that the sample is continuous across every phase join, starts and ends in the traveller's own state, and ends with the clock shift the round trip establishes. The Qt Quick 3D viewer in `gui/` draws nothing the library does not compute: the two regions as their axes and metric, the metric's four entries shrinking to zero at the threshold and reappearing with the opposite signs, the molecule's atoms at their far-side coordinates, the marker along `r` and the near-side clock running backward or forward with it. Pick the traveller and the direction, press Play.

## Layout

The code is layered, lowest first, and each layer is its own static library that links only the one beneath it. `tools/check_layers.py` runs under `ctest` and fails on any include that points upward.

- `src/core/` — `Matrix4`, `Vector4`, `Report` (pass/fail bookkeeping) and `Section` (one unit of verification).
- `src/physics/` — `dynamics/` (dispersion relations, the metric family), `mechanism/` (the domain wall), `transform/` (the involution, the relabelling objection), `scan/` (the signed-permutation scan, its direction families, the handedness filter), `intermediate/` (the intermediate-region geometry, the degenerate window), `units/` (physical constants and the metre-to-second exchange rate).
- `src/particle/` — the one constant-force trajectory (`ConstantForce`) and its readings (threshold angle, far-side space axis), the velocity dictionary, the paired excursion and the coordinate map between sides.
- `src/journey/` — the travellers, the six round trips, the six ways across, and the sampler the viewer reads.
- `checks/` — one `NameSection.h` and `NameSection.cpp` per library, mirroring the tree above; the claims live here and the computations live in `src/`.
- `app/main.cpp` — runs every section in order against one report.
- `gui/` — the Qt Quick 3D viewer: a model object over `JourneyState`, and the QML scene. It links the journey layer and nothing above it.

Headers carry the Doxygen documentation and use include guards; translation units carry no comments.

## Adding a section

Implement `Section` (`title()`, `run(Report&)`) in `checks/` beside the library it verifies and add one line to `buildSections()` in `app/main.cpp`. There is no registration macro and no global state.

## Build

- CMake 3.28 or later, a C++26 compiler (GCC 16 and Clang 23 are what the project is built with)
- The library and the check suite need the standard library only
- The viewer needs Qt 6.8 or later with Quick, Quick3D and QuickControls2; it is skipped when Qt is not found

```bash
cmake -S . -B build/cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build/cmake -j
```

## Run

```bash
./build/cmake/superluminal          # the check suite
ctest --test-dir build/cmake        # the suite and the layering check
./build/cmake/gui/superluminal-gui  # the viewer
./build/cmake/gui/superluminal-gui --snapshot frame.png --progress 0.5 --traveller 2 --sense 0
./build/cmake/gui/superluminal-gui --autoplay 3 --traveller 2 --sense 1   # plays the trip, verifies the end state, exits 0
```

The viewer offers six travellers: the reference three and water, ammonia and bromochlorofluoromethane, the last of which is chiral without any labelling.

Output is one block per section, each listing its checks as pass or fail lines, ending in a summary. Exit code is `0` only when every check passes.
