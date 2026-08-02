# Literature notes

Working notes taken while reading `literature/` (200 paper files). One entry per
paper that bears on the article, filed under the part of `article/article.md`
it speaks to. Each entry records what the paper establishes, how it relates to a
section of the article, and whether it precedes, supports, or contradicts that
section.

Status legend: **PRIOR** the result predates ours, **SUPPORT** independent
agreement, **CHALLENGE** direct objection, **CONTEXT** background only. Compound
markers are used where a paper supports one reading and attacks another; that is
information, not indecision.

Reference numbers `[N]` are stable and are cited from the article, so they are
preserved through this refiling. Entries `[1]` to `[172]` keep the numbers they
were first given; `[173]` to `[227]` are new. The numbered items
("What this changes", items 1 to 59, and 60 onward) are likewise preserved with
their original numbers and redistributed under the part they bear on.

The organising question is the one the article now states: from a massive
particle's four-dimensional orientation and motion in a region of signature
$(3,1)$, three times and one space direction, to the four coordinates
$(t,x,y,z)$ of the event at which it returns to our $(1,3)$ region. Travel in
time is read off that map, not assumed.

**Four of our own results were computed since the previous version of these
notes, and they change verdicts recorded below.** They are attached to the
entries they overturn, and summarised at the end.

1. The Winful dwell-time reading was tested against our own numbers and it
   applies. In the barrier regime the phase delay is $1{,}4629$ and the
   stored-norm dwell time is $0{,}5193$, at thicknesses $d = 2, 4, 8$, a ratio
   fixed at $2{,}817$ to one part in $10^{6}$ and independent of thickness. The
   phase delay is therefore not an independent transit clock there. In the
   propagating regime the stored norm grows linearly with thickness
   ($1{,}000$, $2{,}000$, $4{,}000$ at $d = 1, 2, 4$) and the transit reading
   survives. See `[158]`, `[149]`, `[161]`, Section 14.7.
2. The multi-time zero-curvature criterion was applied. The free far-side theory
   is flat: the three generators are components of one energy vector, they
   commute, all three curvature components vanish exactly, and the holonomy of a
   closed path of length $1000$ is zero. The interior records nothing. The
   curvature comes from the two threshold surfaces and only in the two planes
   touching the crossing slot, value $3{,}000$ against a return-moment shift of
   $1{,}6383$, zero against zero in the plane of the other two slots. This
   agrees case by case with a phase calculation done independently
   (Section 18.15 and Section 24.6). See `[225]`.
3. The energy conditions were evaluated on our own layer. Every profile carrying
   a layer violates the dominant energy condition (linear and $\tanh$ profiles:
   density $-1{,}000$, pressure $+1{,}000$, null satisfied, weak and dominant
   not). Thickening the region weakens the violation without removing it:
   density $-2{,}0$ at $d = 0{,}5$, $-1{,}0$ at $1$, $-0{,}25$ at $4$,
   $-0{,}025$ at $40$. The only escape is the profile stationary at the turning
   point, which carries no layer at all. See `[186]`, `[113]`, `[179]`,
   Section 3.6.
4. The outcome table was recounted. The exit face and the turn are not
   independent labels, so the $8 \times 8 = 64$ ordered face pairings reach only
   $6$ distinct outcomes rather than $9$, splitting three that keep our energy
   and three that return it with the opposite sign. See Section 18.4 and the
   orientation part below.

---

# Part A. Our region and the transformation

The superluminal branch, the factorisation of a superboost, the $D$ matrix, and
what is already published about all three. Bears on Sections 1, 2, 2.1, 2.2,
20 and 21.

### [1] Dragan, Ekert, *Quantum principle of relativity*, New J. Phys. 22 (2020) 033038, arXiv:1910.02780
CONTEXT. The origin of this whole branch. Argues that keeping the superluminal
family of solutions in special relativity forces a non-deterministic picture
with superpositions and complex amplitudes. Only 1+1 dimensional.

### [2] Dragan, Debski, Charzynski, Turzynski, Ekert, *Relativity of superluminal observers in 1+3 spacetime*, Class. Quantum Grav. 40 (2023) 025013, arXiv:2209.01836
PRIOR, the direct source of our setting. Extends the above to 1+3, where the
metric of a superluminal frame becomes 3+1. Establishes that superluminal
observers are mutually indistinguishable, that superboosts preserve the speed
of light, and that point particle dynamics has to give way to field theory.

**Priority note that must stay in the article.** The decomposition of a
superboost into an infinite-speed flip composed with an ordinary boost by the
dual velocity `c^2/V` is already remarked upon in this paper. Section 1
therefore does not introduce the factorisation; what it adds is the systematic
use of it as the organising principle, the proof by exhaustive scan that the
flip is forced (Section 2.1), and the separation of the closure failure onto the
boost layer.

### [3] Zaopo, *Group representations of Lorentz transformations extended to superluminal observers*, arXiv:2510.25385
PRIOR and far more complete than our Section 2.2. Builds the extension as a
Klein four-group realisation depending on polar and azimuthal angles, so it is
direction covariant where our $D$ is not. Defines the extended Poincare group,
classifies all its unitary irreducible representations by Mackey induction,
shows how each restricts to a sum of ordinary Poincare UIRs, and derives the
wave equations from the Casimir eigenvalue problem, recovering Klein-Gordon,
Dirac and Maxwell plus new tachyonic and massless classes. Also contains the
factorisation and the `V = c^2/v` map.

Our position relative to it: our $D$ is not in his extended group, because the
`x <-> y` swap $D$ contains has three-dimensional determinant $-1$. The scan of
Section 2.1 verifies this. That is a real difference but a narrow one.

### [4] Lake, *The (1+3)-dimensional 'quantum principle of relativity' is Einstein's principle of relativity*, Eur. Phys. J. C 85 (2025) 92, arXiv:2410.07017
CHALLENGE, peer reviewed, aimed straight at Sections 1 and 2. Four claims: the
superboosts are ordinary Lorentz boosts in nonstandard notation; the superflip is
the identity plus an arbitrary relabelling; of the 24 permutations 6 preserve the
line element and 18 do not; and the 18 always swap one fixed axis regardless of
the boost direction, which is coordinate dependent and so unphysical. Our $D$ is
the first matrix in his list.

Note the structure of his argument: his step 2 is exactly our factorisation,
which he uses as a lemma on the way to concluding that a superboost is just a
subluminal boost. Section 20.4 concedes the substance of this, and Section 21.1
recounts the line-element-preserving permutations independently and reproduces
his 6.

### [5] Horodecki, *Comment on 'Quantum principle of relativity'*, New J. Phys. 25 (2023) 128001, arXiv:2301.07802
CHALLENGE. The subluminal and superluminal branches are separable: no coherent
formalism connects them, so the programme is incomplete. This was close to the
old reflecting-threshold conclusion, reached from the other side. Under the
current transmitting thesis it is the objection the transmission coefficient of
Section 6 answers with a number rather than with a formalism, which is a weaker
answer than he asks for and should be said so.

### [6] Del Santo, Horvat, *Comment on 'Quantum principle of relativity'*, arXiv:2203.03661
CHALLENGE. Argues the derivation of indeterminism and superposition from
superluminal frames is unwarranted.

### [7] Dragan, Ekert, *Reply to the comment*, arXiv:2206.15247 and *Reply*, New J. Phys. 25 (2023) 128002, arXiv:2309.00020
CONTEXT. In the second reply the authors concede the sharpest question, whether
the proposal yields measurable effects, and answer it only conditionally: yes if
tachyons exist. Directly relevant to Section 23, where the distinguishing
measurement is still unbuilt, and to Section 10.13, where the Casimir signature
sits on a surface we cannot reach.

### [8] Grudka, Stempin, Wojcik, Wojcik, *Superluminal observers do not explain quantum superpositions*, Phys. Lett. A 487 (2023) 129127, arXiv:2306.03961
CHALLENGE, peer reviewed. Used consistently, the generalised transformation gives
no correspondence between a definite classical path and the multiple paths of
quantum mechanics.

### [9] Sen, Del Santo, *Superluminal transformations and indeterminism*, arXiv:2601.15263
CHALLENGE, and the sharpest formal result in this part. A theory-independent
no-go theorem: any framework admitting non-order-preserving superluminal
transformations must give up one of four things, finite information,
time-symmetric informational content, the past storing memory, or time fixing a
preferred causal ordering. Section 12.1 derives loss of determinism from the
equation type; this theorem says something stronger and more general about what
that loss costs. Our indeterminism cannot come from finite information.

### [10] Sen, Salzger, Rudnicki, *Superluminal quantum reference frames*, arXiv:2506.11787
SUPPORT. Extends quantum reference frames to superluminal Lorentz
transformations and resolves the negative-energy paradox inside that framework,
also showing Bell probabilities are conserved. Relevant to Section 16.1, where
the same negative-energy issue appears as the three-component energy vector, and
to the recount of Section 18.4, whose three opposite-sign outcomes are exactly
the negative-energy branch.

### [11] Sienicki, Sienicki, *From kinematics to interference*, arXiv:2512.05164
CHALLENGE, organisational. Separates kinematics, operational content, and
dynamics, and insists that writing coordinate maps is not providing a physical
theory. Superposition is defined by closed-loop interference, not by drawing
paths. This is the cleanest statement of what the core map of Section 25 has to
answer: a map from orientation to return event is a kinematic object until a
closed-loop interference is computed for it.

### [12] Nanni, *Electromagnetic field theory in superluminal spacetime*, Indian J. Phys. (2023), arXiv:2305.12505
PRIOR to Section 19.7. Obtains Maxwell equations and the single-photon wave
equation by superluminal transformation of the ordinary ones, without complex
quantities, and finds X-shaped solutions in the region bounded by the infinite
light cone. Goes further than we do: we verify that the invariant survives under
$D$, he solves the transformed equations.

### [13] Peacock, *Superluminal transformations in spacetimes of definite metric*, arXiv:2308.03796
CONTEXT. Revives Sutherland and Shepanski 1986: positive definite metric,
Lorentz factor `1/sqrt(beta^2-1)`, real proper times for superluminal frames. An
older alternative to signature change, worth one sentence of contrast.

### [14] Ibison, *Tachyons and superluminal boosts*, arXiv:0704.3277
CONTEXT. Extensions of the Lorentz group, discussion of whether imaginary
coordinates are admissible in superluminal frame transformations.

### [15] Perepelitsa, *Looking for a theory of faster-than-light particles*, arXiv:1407.3245
CONTEXT with one sharp claim: a preferred reference frame is mandatory in any
tachyon theory if causality is to be conserved. Sets a condition our model does
not currently meet or discuss.

### [86] Lake, *Towards a group structure for superluminal velocity boosts*, arXiv:2409.01773
PRIOR and directly aimed at Section 2.2, by the author of [4]. Constructs
superluminal boosts as an explicit map between the two-sheeted hyperboloids
inside the light cone and the one-sheeted hyperboloids outside it, and asks what
group structure the resulting operators carry. Our closure failure should be
compared against this construction directly; it is the same question posed
geometrically rather than matricially.

### [173] Evans, Robertson, Weinfurtner, *Tachyonic media and analogue special relativity*, arXiv:2305.12113
CONTEXT, and it reframes the relativity-of-observers argument in a way our
Section 1 can borrow. In sonic models of special relativity the medium's
violation of ordinary Lorentz symmetry is apparent to external observers but not
to observers inside it, and the paper shows the situation is symmetric: internal
observers judge the external laboratory to violate their own sonic Lorentz
symmetries. Generalised to several phonon fields with different invariant speeds,
every observer is free to choose which field is symmetry preserving and hence
which others carry an "ether", the choice being influenced but not fixed by
simplicity. Sending information faster than sound is then a model of exactly our
crossing. The bearing on us: the mutual indistinguishability of [2] has a
worked analogue in which "which side is superluminal" is a choice of reference
field rather than a fact, which is the strongest available defence of the
inclusive reading of Section 27.1 and also its clearest limit, since a choice of
reference field does not survive into a claim about a measured number.

### [174] Miralles, Parra, Vaz, *Signature change and Clifford algebras*, arXiv:math-ph/0003041
CONTEXT, algebraic, and the one entry that speaks to what $D$ *is* rather than
what it does. Given the real Clifford algebra of a quadratic space of one
signature, a new product is defined on the same underlying structure that
simulates the Clifford product of a different signature. With it one writes the
Minkowskian Dirac equation over Euclidean spacetime and defines a duality
operation giving self-dual and anti-self-dual gauge field solutions over
Minkowski spacetime analogous to the Euclidean ones, all without complexifying
the real algebra. Two uses. First, this is a signature change implemented as a
change of product on a fixed algebra rather than as a change of manifold, which
is the algebraic counterpart of Section 2.2's claim that $D$ acts on labels; if
the article wants to argue the far side is the same object read differently, this
is the existing formalisation. Second, it does the job without complexification,
which matters because the complex-lapse machinery of `[118]` is under attack from
`[139]` precisely for the arbitrariness complexification introduces. Compare with
`[72]`, where the neutral-signature analogue replaces $i$ by a para-complex unit
with $e^2 = +1$, which is the structure our $D$ has.

---

# Part B. The intermediate region and its junction

The article treats the intermediate region as a first-class subject: four kinds
(none, Kleinian $(2,2)$, Euclidean $(4,0)$, degenerate layer) against five
thicknesses (zero, thin, finite, thick, unbounded). Bears on Sections 3, 3.1 to
3.7, 4, 4.1, 4.2, 5, 6, 7.1 to 7.6.

**A fact from `[84]` that decides how much of this part applies, and which the
article states at the top of Section 6.** In the Kleinian slab the dispersion
relation reads $\omega^2/c^2 = k_x^2 + k_y^2 - k_z^2 + \mu^2$ where $z$ is the
crossing direction, so **$k_z$ must be purely imaginary inside the slab**; the
paper substitutes $k_z \to ip$ and obtains $|r|^2 + |t|^2 = 1$. The interior of a
$(2,2)$ layer is therefore **evanescent in the direction of crossing**, not
propagating, provided the crossing direction is one of the axes that turns. The
crossing is then a tunnelling process, and the Euclidean and Kleinian cells of
the grid behave alike. Section 14.8 records that this is the most fragile
assumption in the whole table: if instead the transverse axes turn, the Kleinian
region is a cavity and not a barrier, and Section 27.1 files that as one of the
five disagreements resolved by turning a single parameter.

## B1. Which junction condition, and what it costs

### [16] Hayward, *Junction conditions for signature change*, Class. Quantum Grav. 9 (1992) 1851, arXiv:gr-qc/9303034
PRIOR to Section 4.1, and the closest single precedent in the corpus. Treats the
Klein-Gordon field on a signature-changing background and finds the junction
condition as the coefficient of the Dirac distribution in the field equations,
giving `phi' delta = 0` and `a' delta = 0`, that is, the vanishing of the normal
derivative at the junction. This is the strong condition `pi|Sigma = 0`.

Two differences that matter. First, he does not assume the condition in order to
make sense of the equations; it falls out of the distributional structure.
Second, he obtains the gravitational counterpart as well, the vanishing of the
second fundamental form of the junction surface, which is Section 4.2's subject.

### [17] Embacher, *Actions for signature change*, Phys. Rev. D 51 (1995) 6764, arXiv:gr-qc/9501004
PRIOR and, for Section 4.1, the most consequential paper in this part. It frames
the controversy the article is taking a side in: whether the extrinsic curvature
near the surface must merely be **continuous** (weak signature change) or must
**vanish** (strong signature change). Embacher writes down eight candidate
actions and works out which junction condition each implies, settling on `S_7` as
the best strong model and `S_8` as the best weak one.

The article adopts the **weak** condition and quotes a transmitted flux of
$0{,}868$ for a $d = 1$ slab against $0$ under the strong condition
(Section 27.2, first row). That is the whole dispute reduced to two numbers, and
Section 4.1 is right to present the choice as a choice.

### [18] Alty, Fewster, *Initial value problems and signature change*, Class. Quantum Grav. 13 (1996) 1129, arXiv:gr-qc/9501026
PRIOR to Section 12.1 and rigorous where we are heuristic. Operator theory on a
two-dimensional signature-changing spacetime: boundary conditions come from
self-adjoint extensions of the Schrodinger Hamiltonian, and requiring that they
take the form of junction conditions with a continuous field picks out one
particular set. The Klein-Gordon initial value problem is then proved ill posed,
with solutions unstable and the `L^2` norm divergent in finite time for smooth
compactly supported data.

Section 12.1 reaches the same verdict by inspecting the sign of a mode
coefficient. Theirs is a proof; ours is a demonstration. Note that Section 12.2
then restricts to the mass shell and finds nothing blows up there, which is one
of the four claims Section 26.1 records as withdrawn: the far side is badly posed
off shell and well posed on it, and both are true of different data.

### [19] Egusquiza, *Self-adjoint extensions and signature change*, Class. Quantum Grav. 12 (1995) L89, arXiv:gr-qc/9503015
CHALLENGE, and it lands on Sections 4.1 and 10.13. Studying self-adjoint
extensions of the spatial d'Alembertian with two signature changes, he identifies
boundary conditions parametrised by `U(2)` that correspond to **Dirichlet**
conditions for the fields. Our threshold condition is Neumann. He further argues
that quantum fields then make the signature-changing boundaries **unstable**, so
the Kleinian region either collapses or expands without bound.

The Casimir dispute of Section 27.2, third row, is this question with numbers
attached: same condition on both walls gives $-0{,}006854$ and attraction,
opposite conditions give $+0{,}005997$ and repulsion. Egusquiza's argument is
that the wall choice is not free, and the article's honest position is that it
has computed both and decided neither.

### [20] Dray, *Einstein's equations in the presence of signature change*, J. Math. Phys. 37 (1996) 5627, arXiv:gr-qc/9610064
PRIOR and a warning. Derives a generalised Lanczos equation by variational
methods: no distributional term in the stress tensor, and so no surface layer,
exactly when the extrinsic curvature is continuous. The conclusion is blunt:
there are no canonical Einstein equations in the presence of signature change,
because formal substitution of a signature-changing metric into equations derived
for constant signature is not obviously derivable from any starting principle,
and for a continuous signature-changing metric there is no metric volume element
at the surface at all. Section 4.2 must declare which version of the field
equations it is using and why.

### [21] Dray, Ellis, Hellaby, Manogue, *Gravity and signature change*, Gen. Rel. Grav. 29 (1997) 591, arXiv:gr-qc/9610063
PRIOR. Using proper time as the coordinate admits smooth generalised orthonormal
frames, which makes both the variational treatment of Einstein's equations and
distribution theory tractable across the change. The practical route into
Section 4.2.

### [22] Dray, *Tensor distributions in the presence of degenerate metrics*, Int. J. Mod. Phys. D 6 (1997) 717, arXiv:gr-qc/9701047
CONTEXT, machinery. Tensor distributions without assuming a metric, which is what
a degenerate surface requires.

### [23] Dray, Ellis, Hellaby, *Note on signature change and Colombeau theory*, Gen. Rel. Grav. 33 (2001) 1041, arXiv:gr-qc/0012047
CHALLENGE to the framing of the whole area, and it disciplines us. The so-called
controversies are disagreements about unstated assumptions; different
mathematical choices give different boundary conditions and may suit different
physical situations, and labelling any one choice as *the* Einstein equations is
rhetoric rather than physics. Section 4.1 states its assumptions and does not
present its junction condition as forced, which is the correct response.

### [67] Hartley, Tucker, Tuckey, Dray, *Tensor distributions on signature-changing space-times*, Gen. Rel. Grav. 32 (2000) 491, arXiv:gr-qc/9701046
SUPPORT for Section 4. Establishes that covariant differentiation can be defined
on a class of tensor distributions wide enough to be physically interesting, for
both continuous and discontinuous signature change. This is the technical licence
Section 4 uses implicitly when it writes distributional quantities at the
threshold.

### [63] Hellaby, Dray, *Comparison of approaches to classical signature change*, Phys. Rev. D 52 (1995) 7333, arXiv:gr-qc/9601040
PRIOR, and the paper Section 4.1 most needs. It sets out explicitly the two
philosophies the article has to choose between: Hayward's Lagrangian route, which
amounts to an imaginary proper time on one side, versus a strictly classical
route, and Darmois-Israel junction conditions versus Lichnerowicz ones. It also
states plainly that there is as yet **no rigorous derivation** of the
distributional field equations, so both sides are postulates.

### [64] Dray, Manogue, Tucker, *Boundary conditions for the scalar field in the presence of signature change*, Class. Quantum Grav. 12 (1995) 2767, arXiv:gr-qc/9501034, and [65] Hayward, *Comment*, arXiv:gr-qc/9502001
CHALLENGE, taken together the sharpest exchange in this literature. Hayward's
comment charges that the proposed solutions do not satisfy the equation, that the
variational equations are singular at the change, and that the distributional
field equations are ill defined. Whichever side one takes, the exchange shows
that the choice of boundary condition at a signature change is contested at the
level of whether the objects exist, not merely of which is preferable.

### [66] Kriele, *Distinguished solutions for discontinuous signature change with weak junction conditions*, arXiv:gr-qc/9610016
SUPPORT for the current thesis, CHALLENGE to the old one. Takes the **weak**
junction condition, imposes regularity, and shows the solution space for dust and
scalar field models is still controlled, a one-parameter family of Riemannian
three-manifolds. So the weak condition is not degenerate or empty; it is a live
competitor with its own uniqueness structure. Under the old reflecting thesis
this was the entry that forced a caveat; under the transmitting thesis it is the
entry that licenses the choice.

### [87] Dray, Manogue, Tucker, *The scalar field equation in the presence of signature change*, Phys. Rev. D 48 (1993) 2587, arXiv:gr-qc/9303002
PRIOR, and the paper Section 4.1 is a special case of. Demanding a conserved
momentum in the homogeneous case selects one propagation rule across the surface,
and that rule is shown to give the unique solutions of the distributional wave
equation, reachable also from a Lagrangian. Two things matter. First, the
selection principle is flux conservation, the same one Section 4.1 uses, but it
selects **transmission**, not total reflection. Second, what comes out the far
side is a **mix of positive and negative frequencies** whose ratio depends only
on the total conformal size of the spacelike region and not on the profile of the
metric.

That second result is now load-bearing in a way it was not: since our own numbers
show the delay saturates and carries no thickness information in the barrier
regime (finding 1 above), the frequency mixing is the observable that still does.
Section 14.9 is built on this.

### [88] Dray, Hellaby, *The patchwork divergence theorem*, J. Math. Phys. 35 (1994) 5922, arXiv:gr-qc/9404002
PRIOR for the machinery of Section 4.1. The divergence theorem for piecewise
smooth fields, derived so that it holds independently of the signature on either
side and therefore across a change of signature. Our flux argument at $V = c$ is
an application of this theorem. The structural point is that the patched theorem
carries a boundary term; a flux balance written without that term is not the
conservation law.

### [89] Hellaby, Dray, *Failure of standard conservation laws at a classical change of signature*, Phys. Rev. D 49 (1994) 5096, arXiv:gr-qc/9404001
CHALLENGE, and one of the two most serious single objections in this part. The
Israel identities that normally force conservation of matter across a junction do
not hold when the signature changes; the modified identities carry a finite
source on the surface itself, physical vector fields jump in at least one
component, and current is not conserved either. The authors' own conclusion is
that recovering standard conservation laws requires restrictions no realistic
model satisfies.

Consequence for Section 4.1: the premise "the flux must balance, therefore the
amplitude is fixed" is not available. Under the weak condition the surface is
allowed to be a source, so flux conservation determines neither total reflection
nor a specific transmission coefficient. The article's thesis is not defeated by
this, but a derivation resting on flux alone would be, and Section 4.1 must name
what fixes the amplitude if conservation does not.

### [90] Hayward, *Comment on 'Failure of standard conservation laws at a classical change of signature'*, Phys. Rev. D 52 (1995) 7331, arXiv:gr-qc/9606045
CHALLENGE to the current thesis, from the opposite direction to `[89]`. Hayward's
reply is that nothing fails: if the field equations are satisfied then the
junction conditions and the conservation equations both hold, and the reported
failure is an artefact of not making sense of equations that are singular at the
surface. Read with `[89]` and his own gr-qc/9303034, this is the strong-condition
camp asserting that the weak condition is not a legitimate alternative but a
mistake. Section 4.1 cannot adopt the weak condition by preference; it has to
engage the specific claim that the strong condition is a theorem once the field
equations are imposed.

### [91] Dray, Hellaby, *Comment on 'Smooth and discontinuous signature type change in general relativity'*, Gen. Rel. Grav. 28 (1996) 1401, arXiv:gr-qc/9610062
SUPPORT, and the best single citation for the choice made in Section 4.1. Against
Kossowski and Kriele's boundary conditions, the authors show the derivation rests
on a postulated form of the field equations, that there is **no canonical form of
the Einstein equations at a change of signature**, and that a weaker formulation
exists in which the field equations still hold, the smoothness assumptions are
milder, and the energy-momentum tensor stays bounded **without** the extrinsic
curvature having to vanish. This is the licence for dropping the strong
condition, and it should be cited at the point of the choice.

### [113] Hayward, *Signature change at material layers and step potentials*, arXiv:gr-qc/9509052
CHALLENGE, and the single most damaging paper for the transmitting thesis. For a
contravariant 4-metric changing from Lorentzian to Riemannian across a spacelike
hypersurface, the mixed Einstein tensor is manifestly non-singular; in Gaussian
normal coordinates the metric contains a step function and the Einstein tensor
contains a Dirac delta supported at the junction, whose coefficient is a linear
combination of the second fundamental form. Hayward draws the consequence
sharply: **unless the junction has vanishing extrinsic curvature, the metric
describes a layer of matter at the junction** (with stresses but no energy or
momentum), and **such metrics do not satisfy the vacuum Einstein equations, nor
the Einstein-Klein-Gordon equations**. The scalar counterpart is the same: the
d'Alembertian of a Klein-Gordon field carries a Dirac delta whose coefficient is
the momentum of the field, so **if the field momentum does not vanish at the
junction the field does not satisfy the massless Klein-Gordon equation**.

**Verdict changed by finding 3.** The old note said the price of the weak
condition is a matter layer that has to be supplied by something. Section 3.6 has
now evaluated the layer, and the price is worse than that: the layer carries
surface density $-1{,}000$ and pressure $+1{,}000$ for the linear and $\tanh$
profiles alike, satisfies the null energy condition, and **violates the weak and
the dominant energy conditions**. Thickening does not save it: density
$-2{,}0$ at $d = 0{,}5$, $-1{,}0$ at $1$, $-0{,}25$ at $4$, $-0{,}025$ at $40$,
with the dominant condition violated at every thickness. The only profile that
escapes is the one stationary at the turning point, which escapes by carrying no
layer at all, and that is a tuned special case rather than a general arrangement.
So Hayward's "supply the layer" is not a matter of finding better matter; see
`[186]`, which proves it cannot be done.

### [114] Hayward, *Comment on 'Comparison of approaches to classical signature change'*, arXiv:gr-qc/9606044
CHALLENGE, the closing move of the exchange recorded as `[63]`, `[64]`, `[65]`
and `[90]`, to be read with `[113]`. Hayward restates that the Hellaby-Dray
solutions do not satisfy the Einstein-Klein-Gordon equations at the change, that
substituting them in unit normal coordinates yields delta terms describing source
layers, and that this calculation involves no imaginary time, no modified field
equations, and nothing but classical objects. He further charges that the attempt
to remove the delta terms is mathematically invalid, involving division by zero
and products of distributions.

The bearing is procedural. Our licence for the weak condition is `[91]`, a Dray
and Hellaby paper. This is the specific technical accusation against that line of
work. Section 4.1 should state which side of the exchange it stands on. Note that
`[181]` and `[180]` are the modern answer: rebuilt on Colombeau algebras, the
products of distributions Hayward objects to are defined.

### [92] Kriele, Martin, *Black holes, cosmological singularities and change of signature*, Class. Quantum Grav. 12 (1995) 503, arXiv:gr-qc/9411063
CHALLENGE, and a priority finding. Signature change cannot be used to remove a
singularity **unless the Einstein equation is abandoned at the surface of
change**. The paper also shows to what extent smooth and discontinuous
signature-changing solutions are equivalent, which speaks directly to Section 6:
if the two are equivalent in the relevant sense, a finite-thickness slab does not
buy as much freedom as the article hopes. The article wants a real tear, a
crossable one, and the field equations to survive it. This paper says pick two.

**Sharpened by finding 3.** The thickness escape is now measured and it fails in
a second, independent way: thickening weakens the energy-condition violation
without removing it. Whatever freedom finite thickness buys, it does not buy
energetic acceptability.

### [93] Kamleh, *Signature changing space-times and the new generalised functions*, arXiv:gr-qc/0004057
CHALLENGE by removing an escape route from Section 4.1. The Colombeau algebra,
the standard tool for giving distributional sense to products of singular
objects, is analysed for both continuous and discontinuous signature change and
found **insufficient to exclude either, and unable to settle the dispute over the
junction conditions**. So the article cannot justify the weak condition by saying
the distributional formulation forces it. The choice stays a choice. See `[115]`,
where the ambiguity is shown not to reach the shell equation, and `[181]`, where
the Colombeau route is carried much further than Kamleh takes it.

### [94] Martin, *Cosmological perturbations and classical change of signature*, Phys. Rev. D 52 (1995) 6708, arXiv:gr-qc/9509053
CHALLENGE for Section 6. For FLRW with a constant scalar field, **no regular
perturbation solution exists that satisfies the junction conditions at the
surface of change**. The closest thing in the literature to a non-existence
result for the configuration the article wants, and it is perturbative, so it is
about exactly the mode-by-mode analysis Section 6 performs. The article should
either show its case falls outside the hypotheses or accept a restriction on
which incident modes can be posed at all.

### [95] Dray, *Piecewise conserved quantities*, in Gravity and the Quantum, Springer 2017, arXiv:1701.02863
CONTEXT, the settled modern statement of `[88]` and `[89]`. Conservation laws on
glued spacetimes acquire a boundary term, worked through for junctions of
Schwarzschild regions of different mass and for junctions between regions of
different signature. The right single reference when Section 4.1 states what its
conservation law actually is.

### [99] Zhang, *Alternative route towards the change of metric signature*, Phys. Rev. D 100 (2019) 064043, arXiv:1909.10669
PRIOR and structurally the closest paper in the corpus to our construction. The
traditional route flips the sign of the lapse, so the far side is Euclidean.
Zhang instead flips the sign of the **spatial** metric eigenvalues, so that the
far side is **purely timelike**, and then derives the junction conditions for
that case. That is our $D$ matrix's effect stated in the language of the
signature-change literature: our far side is three times and one space, and it is
reached by turning spatial directions timelike, not by turning time spacelike.
Sections 4.1 and 10.10 should both cite this, and the article should state which
of Zhang's junction conditions it is adopting. This is the only paper in the
corpus whose far side is ours, and it occupies the "no intermediate region at
all" cell of the grid on its own.

### [115] Racskó, *Variational formalism for generic shells in general relativity*, arXiv:2203.03049
SUPPORT, and the machinery Section 4.1 lacks. A variational principle for thin
shells of **completely unconstrained signature**, unifying the timelike and null
treatments. The shell equation appears as the natural boundary condition of a
broken extremal problem along a hypersurface where the metric is allowed to be
non-differentiable, and since the second-order Einstein-Hilbert action makes that
boundary value problem ill defined, several regularisation schemes are introduced
and proved equivalent. The results reproduce Barrabes-Israel for fixed causal
type and Mars-Senovilla for generic shells.

This is the right frame for our threshold. A surface where the causal character
is not fixed is precisely what $V = c$ is, and here it is treated by a
variational principle rather than by picking a distributional convention. The
equivalence of the regularisations answers `[93]`: the ambiguity is real but does
not reach the shell equation.

### [116] Senovilla, *Junction conditions for general gravitational theories*, arXiv:2603.04645
SUPPORT and CHALLENGE at once, and it supplies the one theory-independent
constraint in this whole area. Working distributionally for actions built from
arbitrary functions of curvature scalar invariants, shells arise if the $m$th
covariant derivative of the Riemann tensor is continuous at the matching
hypersurface, and a proper junction without shells needs the $(m+1)$th derivative
continuous as well. Two results bear directly on us.

First, and Section 4.2 and Section 19 both need it: **General Relativity and
$F(R)$ are extraordinary in admitting shells of curvature, that is, impulsive
gravitational waves**, because every other theory in the class requires the jump
of the second fundamental form to vanish across the matching hypersurface. So the
freedom the weak condition asks for exists in general relativity and essentially
nowhere else, and what it buys is exactly an impulsive gravitational wave at the
surface. The price `[113]` identifies as a matter layer is, on the gravitational
side, radiation emitted at the crossing. That is the carrier Section 19.5 is
looking for.

Second, the universal statement: **continuity of the normal components of the
energy-momentum tensor across the matching hypersurface is proved to be a
property independent of the field equations**. This is a necessary condition our
crossing has to satisfy no matter which version of the field equations
Section 4.2 adopts, and it is the only constraint in the corpus with that status.

### [175] Mars, Senovilla, Vera, *Lorentzian and signature changing branes*, Phys. Rev. D 76 (2007) 044029, arXiv:0705.3380
PRIOR, and the strongest existence result in the corpus for a *regular*
signature-changing junction. General hypersurface layers are considered with no
restriction on the causal character of the hypersurface, so that internal changes
of signature are allowed, and the authors confirm that a good, regular and
consistent description of signature change is achieved in a brane or shell
scenario **while keeping the hypersurface and the bulk completely regular**. The
formalism treats traditional timelike branes, signature-changing branes and pure
null ones in one language, which permits a direct comparison of the three. Applied
to hypersurface layers in static bulks it gives a general Robertson-Walker
geometry on the layer, possibly with a signature change, with explicit anti de
Sitter examples and a classification of the permitted behaviours for
$Z_2$-mirror branes, asymmetric shells and signature-changing branes.

Two things for us. First, this is the counterweight to `[113]`: the layer can be
made regular, in the sense that nothing in the geometry blows up. It does not
follow that the layer is energetically acceptable, and `[186]` says it is not, so
the honest reading is that regularity and the energy conditions are separate
questions and this paper settles only the first. Second, the paper's own
classification includes **asymmetric shells** as a distinct permitted class,
which is our configuration: the entry crossing and the exit crossing are not the
same surface. Section 4.1 should place its slab inside this classification.

### [176] Mars, Senovilla, Vera, *Signature change on the brane*, arXiv:gr-qc/0012099
PRIOR, the letter that `[175]` strengthens. Anti de Sitter bulks matched across a
signature-changing hypersurface, with the conformal diagram showing umbilical
regions on the Euclidean and Lorentzian sides separated by a non-umbilical
intermediate stretch. The intermediate non-umbilical stretch is the structural
point for us: the change is not a single surface but an interval over which the
matching data are of a third kind, which is the braneworld form of the article's
finite-thickness slab.

### [177] Mars, Senovilla, *Geometry of general hypersurfaces in spacetime: junction conditions*, arXiv:gr-qc/0201054
PRIOR, and the foundation under `[175]`, `[182]` and `[184]`. Hypersurfaces whose
causal character changes from point to point are given inherited geometric
structures by two constructions, the standard rigged connection induced by a
rigging vector, and a more physically adapted "rigged metric connection" induced
by each observer. Gauss and Codazzi equations are generalised, and the matching
problem across a general hypersurface is attacked with this machinery, with the
result that the preliminary junction conditions allowing Einstein's equations to
be defined distributionally reduce to **continuity of the first fundamental
form**. The bearing on Section 4.1 is that the minimal condition is on the
induced metric, not on the extrinsic curvature; everything the strong/weak
dispute is about lives above that floor, and this paper marks where the floor is.

### [178] Huber, *Junction conditions and local spacetimes in general relativity*, Eur. Phys. J. C 80 (2020) 1132, arXiv:1908.08735
SUPPORT, methodological. A framework of local geometric deformations for joining
spacetimes with different geometries, in which two Lorentzian manifolds are shown
to match in agreement with Darmois-Israel by locally deforming the two metrics
relative to each other, and which handles problems standard gluing cannot state.
The value for us is the strategy rather than the theorem: instead of asking
whether a given pair of metrics happens to satisfy the matching conditions, one
asks how much local deformation is needed to make them do so. That is the natural
way to quantify how far our threshold is from a shell-free match, and it
converts a yes/no question into a magnitude.

### [179] Chu, Tan, *Generalized Darmois-Israel junction conditions*, arXiv:2103.06314
SUPPORT, and it independently predicts the scaling our own calculation found. A
general recipe for deriving junction conditions by integrating the bulk field
equations across the singular hypersurface, handling terms more singular than a
delta by representing the delta as the limit of a sequence of ordinary functions.
That regularisation is procedurally identical to what the article does when it
replaces the threshold with a slab of finite thickness. The technical point:
compatibility of the field equations with a delta-function source **forces
constraints on the extrinsic curvature**; the conditions are not free but dictated
by which terms are allowed to blow up. In general relativity this reduces to the
delta piece of the Einstein tensor being proportional to the jump of the second
fundamental form, so a shell-free match requires that jump to vanish. The paper
also shows earlier claimed results for $F(R)$ and quadratic gravity were
inaccurate, a warning that layer bookkeeping is easy to get wrong.

**Pair with finding 3.** The one-over-thickness behaviour of the layer strength
is generic on this analysis, not an artefact of our profile, and our numbers are
exactly that: $-2{,}0$, $-1{,}0$, $-0{,}25$, $-0{,}025$ at $d = 0{,}5, 1, 4, 40$,
each the reciprocal of the thickness to the quoted precision. Section 3.6 should
cite this as the reason the scaling is expected, which strengthens the finding:
the violation decays as slowly as it possibly can and never reaches zero.

### [180] *Generalized junction conditions for discontinuous metrics*, arXiv:2601.07936
SUPPORT, and the direct modern answer to `[114]`. The Darmois-Israel formalism is
extended to **discontinuous metrics** within Colombeau algebras, giving a
consistent treatment of products and derivatives of distributions. Relaxing the
usual continuity condition on the metric, the generalised junction conditions
include higher-order singular terms in the curvature and in the surface
energy-momentum tensor, representing new geometric degrees of freedom associated
with genuine discontinuities. Traditional Darmois-Israel is recovered as a limit.
Our threshold is a discontinuous metric by construction, so this is the formalism
in which its junction conditions are properly stated, and the "new degrees of
freedom" are where the article's extra distributional content has to live.

### [181] Huber, *General shells and generalized functions*, arXiv:2504.14402
SUPPORT, and the most complete version of the Colombeau route. The mixed
thin-shell formalism is rebuilt on Colombeau generalized functions, working
throughout with smooth regularisations of the step function and the delta rather
than with Schwartz distributions, so that nonlinear curvature expressions never
require an ill-defined product. Three of the applications are ours: matching of
spacetimes whose metrics are themselves distributional across a common boundary;
setting up the **dominant energy condition for shells inside the regularised
framework**; and nonlinear distribution-valued curvature invariants. The
regularised step function plays exactly the role of our finite-thickness
transition profile, so this supplies the rigorous version of the limit our slab
calculation performs by hand. Penrose cut-and-paste results are recovered, which
supports using the same machinery for our two crossings.

**Directly relevant to finding 3.** Our dominant-condition evaluation is done on a
regularised profile family; this is the paper that says such an evaluation is
legitimate rather than an artefact of the smoothing.

### [182] Manzano, Mars, *Abstract formulation of the spacetime matching problem and null thin shells*, arXiv:2309.14874
SUPPORT, and the right formalism for a threshold with two inequivalent faces. The
matching problem is reformulated in terms of abstract hypersurface data, so the
joining surface is treated on its own rather than as something embedded in a
chosen ambient spacetime. That is what our threshold needs, because the two sides
have different signatures and there is no single ambient manifold in which to
place a unit normal. Two features matter. First, the construction is
intrinsically **asymmetric**: the two boundaries are supplied independently and
the matching is encoded in a diffeomorphism between the abstract data sets, so
the two faces of a slab may carry genuinely different conditions. Second, when
several matchings of the same pair of regions are possible, explicit formulas are
given for the shell content of any one relative to a known matching, which is the
right tool for comparing our entry crossing with our exit crossing rather than
treating each from scratch. If the article wants to argue that the asymmetry of
the two crossings is an opening, and `[155]` says asymmetry is the one opening
left, this is the machinery in which that argument has to be made.

### [183] Mars, *Abstract null geometry, energy-momentum map and the constraint tensor*, arXiv:2402.07488
CONTEXT with a caveat. The geometry of a null manifold, a smooth manifold
carrying a degenerate metric with a one-dimensional radical at each point, is
developed, with ruled null manifolds in one-to-one correspondence with
equivalence classes of null metric hypersurface data, yielding a family of
torsion-free connections related by an explicit gauge group. So differential
geometry can be done where the metric has no inverse. A canonical decomposition
of any symmetric $(0,2)$ tensor on the data, with two compatible differential
operators, splits the constraint tensor into a hierarchy without choosing
coordinates or a foliation, and the null shell equations come out in the same
form. Our threshold is a degenerate surface, and when the transition profile is
stationary at the crossing the degeneracy direction is one-dimensional, which is
this setting. The caution: the degeneracy treated here is that of a null
direction, not of a signature flip, so the geometry transfers but the physical
interpretation does not automatically.

### [184] Shen, Peng, Li, *Multiway junction conditions: booklets and webs*, arXiv:2402.00694
CONTEXT, and the natural home for a two-crossing configuration posed as one
object. The junction condition for gluing an arbitrary number of spacetimes along
one common interface is derived by a geometric technique the authors call reverse
extension, cross-checked by varying the action of Einstein gravity and of dilaton
gravity, and shown invariant under a change of frames. The statement that matters
for us: **the junction condition takes the same form for spacelike and for
timelike interfaces**, which is useful evidence that the machinery is not
sensitive to the causal character of the joining surface in the way one might
fear. A booklet with several pages is formally the same problem as a slab with
two inequivalent faces. Nothing here removes the surface content.

## B2. The layer, and whether it can be made acceptable

### [186] Maeda, *Energy conditions for non-timelike thin shells*, arXiv:2306.07326
CHALLENGE, and after finding 3 the single most important entry in this part. In
arbitrary dimension $n \geq 3$ and in **any** theory of gravity, Maeda settles
what energy conditions a shell can satisfy when the shell is not timelike. The
induced energy-momentum tensor is Hawking-Ellis type I if the shell is spacelike,
and type I, II or III if it is null. The results: **on a spacelike shell, and on
a null shell with non-vanishing surface current, the dominant energy condition is
inevitably violated**; and if the surface pressure on a null shell also vanishes,
the tensor is type III and violates all the standard energy conditions, the null
condition included. No symmetry assumption is used, so the result cannot be
dodged by a clever profile.

A surface of signature change is by construction not timelike, since the normal
changes character there. So any layer our threshold carries falls under these
theorems, and the consequence is decisive: the price of the weak junction
condition is not merely a layer, it is a layer that **cannot be made physically
acceptable by choosing better matter**.

**This is what finding 3 confirms on our own numbers.** Section 3.6 computed the
surface density and pressure profile by profile and got $-1{,}000$ and
$+1{,}000$, null condition satisfied, weak and dominant violated, for both the
linear and the $\tanh$ step, and found the violation persists at every thickness
tested up to $d = 40$. Maeda's theorem says that outcome was forced. The old
notes recorded the layer as a liability to be supplied; it is now a liability that
cannot be discharged. Section 3.6 states this without softening and Section 26.1
lists "a transmitting threshold is energetically harmless" among the claims this
work has withdrawn. That is the correct handling, and this entry is why.

### [154] Eiroa, Figueroa-Aguirre, Senovilla, *Pure double-layer bubbles in quadratic F(R) gravity*, arXiv:1704.00698
SUPPORT, and the best answer available to "can the layer be something other than
ordinary matter". Spherically symmetric bubbles separating two regions of
constant scalar curvature are constructed by the junction formalism in quadratic
$F(R)$. The matching hypersurface supports in general a thin shell **and a
gravitational double layer**, and for appropriate parameter values whenever the
quadratic coefficient is negative, **pure double layers are possible**: the first
example of a pure double layer in a gravitational theory.

A double layer is a dipole-type distributional source, a $\delta'$ rather than a
$\delta$. A **pure** double layer carries no ordinary thin shell at all. That is
a third option beyond the two the article has been choosing between, and it would
meet `[113]` in its own terms, because there would be no layer of matter with
stresses to supply. The price is that the construction lives in quadratic $F(R)$
rather than general relativity, and by `[116]` general relativity is precisely
the theory that does **not** support gravitational double layers as a generic
option.

### [185] Reina, Senovilla, Vera, *Junction conditions in quadratic gravity: thin shells and double layers*, arXiv:1510.05515
PRIOR to `[154]` and `[155]`, and the paper that establishes the double layer as
a general phenomenon rather than an example. The junction conditions for the most
general gravitational Lagrangian containing terms quadratic in the curvature are
derived, both for a concentration of matter on the joining hypersurface and for
proper matching with only finite jumps of the energy-momentum tensor. Two results
for us. First, in the proper-matching case **the conditions are more demanding
than in General Relativity**, which is the price of leaving general relativity to
escape `[113]`. Second, the shells are generically of a new kind: besides the
standard energy-momentum tensor they carry a **double layer contribution which
induces an external energy flux vector and an external scalar pressure or tension
on the shell**, and all these contributions are necessary to make the total
energy-momentum tensor divergence-free. An external energy flux at the shell is
exactly the sort of object Section 19 should be looking at when it asks what the
threshold can emit.

### [155] Rosa, André, Lemos, *Traversable wormholes with double layer thin shells in quadratic gravity*, arXiv:2305.06829
CHALLENGE to the branch `[154]` opens, and it should be read immediately after
it. In $R + \alpha R^2$ plus matter, the junction conditions are six and permit
double layer thin shells; the authors build traversable wormholes in which the
interior region is matched to two exterior vacuum domains **through two double
layer thin shells**, and test the null energy condition throughout. The NEC is
satisfied for the matter in the whole interior, notably at the throat, and for
some components at the double layer, but is **not satisfied for the double layer
stress-energy distribution component itself**. The authors conclude the NEC seems
basically impossible, or very hard, to satisfy when double layer thin shells are
present. Single layer shells are admitted and can satisfy the NEC, but only for
**asymmetric configurations without an interior**.

The geometry is our geometry: an interior region reached through **two** shells,
with a traversal. Combined with `[113]` and now `[186]`, the position is: a
transmitting junction either carries a matter layer that fails the vacuum
equations and violates the dominant condition, or carries a pure double layer
that fails the null energy condition. Section 3.6 picks the first and states the
cost. The one opening is that **asymmetric single-layer** configurations satisfy
the NEC, and our two crossings are naturally asymmetric; see `[182]`, `[187]` and
`[188]`.

### [187] Forghani, Mazharimousavi, Halilsoy, *Asymmetric thin-shell wormholes*, Eur. Phys. J. C 78 (2018) 469, arXiv:1801.05516
CONTEXT for the asymmetric opening, with a discouraging result. Thin-shell
wormholes in which the two sides of the throat carry different sources, breaking
the mirror symmetry the usual embedding-diagram picture assumes, are analysed for
linear stability with a variable equation of state and the corresponding junction
conditions, and tested on cosmic string, Schwarzschild, Reissner-Nordström and
Minkowski examples. The finding is that **symmetry makes a wormhole more
stable**, and that the parameter controlling the radius dependence of the throat
pressure affects the stability strongly. So the asymmetry that `[155]` leaves as
the one energy-condition opening is, on this evidence, bought at the cost of
stability. The article should not present asymmetry as a free lunch.

### [188] Guerrero, Olmo, Rubiera-Garcia, *Double shadows of reflection-asymmetric wormholes supported by positive energy thin-shells*, arXiv:2102.00840
SUPPORT, and the strongest existence result in the asymmetric direction.
Reflection-asymmetric thin-shell wormholes are built in Palatini $f(R)$ gravity
by matching two different electrovacuum patches across a shell, and the
configurations are shown to be linearly stable and **supported by positive-energy
matter**. State precisely what this does and does not give: a physically
acceptable layer, not the absence of a layer, and it is in a theory that is not
general relativity. The observational half is a clean geometric analogue for us:
the two sides have different photon spheres, so an observer on one side sees a
second shadow ring produced by photons that cross the throat and **bounce back
off the higher effective potential on the far side**. Partial transmission and
partial return produced by an asymmetric match is exactly our two crossings, and
the exit face need not behave like the entrance face. Compare Section 18.7, where
the exit face is determined by the sign of the crossing wavenumber.

## B3. The degenerate surface, and computing through it rather than matching across

### [96] Pavlova, Remizov, *Singularities of geodesic flows in smooth signature changing metrics on 2-surfaces*, arXiv:1801.09815
SUPPORT with a hard constraint attached, and the most directly useful classical
result for Section 6 and for whether a massive body can cross. In two dimensions,
at a generic point of the degeneracy curve, geodesics **can** pass through, so
the surface is not an absolute barrier for worldlines; but they cannot pass in
arbitrary tangential directions, only in a finite set of **admissible directions,
numbering one, two or three**. That is the mode-content dependence of Section 6
appearing at the classical level: crossing is not forbidden, it is
direction-selected. The theorem is two-dimensional, so the count in four
dimensions is not established.

Worth noting against finding 4: the article's own recount gives **three**
distinct deflection values in the energy-preserving branch of Section 18.4 and
three in the opposite-sign branch. Whether the classical "one, two or three
admissible directions" and the quantised three-valued deflection spectrum of
Section 18.9 are the same three is not established and should not be asserted,
but the coincidence is worth recording.

### [132] Stoica, *On singular semi-Riemannian manifolds*, arXiv:1105.0201
### [133] Stoica, *Spacetimes with singularities*, arXiv:1108.5099
SUPPORT, taken together, and the most useful pair of tools for Sections 7.1 and
6. The standing difficulty is that when the metric degenerates the inverse
metric, the contraction of covariant indices, the Levi-Civita connection and the
curvature all stop being defined, which is why the literature argues about
conventions instead of computing. Stoica constructs an invariant, canonical
contraction of covariant indices valid for degenerate metrics; uses it with the
Koszul form to define a covariant derivative on radical-stationary singular
semi-Riemannian manifolds; builds the Riemann curvature from it; and shows that on
the class he calls semi-regular **the Riemann curvature is smooth even where the
metric degenerates**. From this he writes a densitized Einstein tensor whose
weight-2 density stays smooth through the degeneracy.

The second paper carries the apparatus to **metrics which change signature**,
states that the operations usually prohibited can still be performed, and obtains
spacelike foliations of the globally hyperbolic regions of the extended solutions
with the consequence that **the initial data can be preserved in reasonable
situations**. Preservation of initial data through a degenerate surface is
exactly what the return-placement problem needs and exactly what `[89]` denied by
a different route. The two are not in direct contradiction, because Stoica changes
the objects rather than the physics: it is the densitized Einstein equation that
stays smooth, not the ordinary one. This is the only construction in the corpus
in which something is carried **through** the degeneracy rather than matched
across it, and it is therefore the natural setting for a transfer relation between
the two crossings.

### [134] Holdom, *Cosmologies with turning points*, arXiv:2302.10716
SUPPORT, and a sharp warning about coordinates. Singularity-free,
geodesically-complete cosmologies are built on manifolds that are **not quite
Lorentzian**: the metric can be smooth everywhere or non-degenerate everywhere,
but not both, and which of the two you see depends on the coordinate system. In
the smooth chart the Einstein tensor is first order in derivatives; in the
non-degenerate chart the metric has a piecewise FLRW form. On such a manifold the
universe can **turn around, expanding to contracting or the reverse, with the
Einstein equations satisfied everywhere and no violation of the standard energy
conditions**, with a corresponding extension of the Kasner vacuum solutions.

Two consequences. First, Section 7.1's degeneracy argument and its counter-model
`[44]` are both partly arguments about which chart is used, so a claim that the
interpolation fails must say in which chart. Second, this is a worked example of
a **turning point** with the field equations intact and no exotic matter, which
is the round trip's shape reduced to one surface. Read against finding 3 the
contrast is instructive and uncomfortable: Holdom gets a turning point with the
standard energy conditions unviolated, and our layer violates the dominant
condition at every thickness. The difference is presumably that his turning point
carries no layer, which puts him in the same cell as our stationary profile.

### [135] Rieger, *Möbius structures and non-orientable semi-Riemannian manifolds*, arXiv:2601.10009
CHALLENGE, a priority finding, and it bears on the far side as much as on the
surface. The question is global: which signature-changing metrics are admissible
on a non-orientable manifold. The main result is that **on non-orientable compact
surfaces the radical of a signature-changing metric cannot be everywhere
transverse along the hypersurface of signature change**. In particular metrics
built by the transformation prescription $\tilde g = g + f V^\flat \otimes
V^\flat$, with $g$ Lorentzian and $f$ a smooth interpolation, **necessarily fail
the transversality condition**. The obstruction is purely global, tied to the
Euler characteristic and the non-existence of nowhere-vanishing vector fields.

The prescription named is that of `[27]`, on which the corpus relies to produce
signature-changing manifolds at all, and the transverse radical is the hypothesis
under which `[28]` and `[45]` work. So: the far side is posited to have no time
orientation (Section 8.4); orientability failures obstruct exactly the
transversality the construction of the change surface assumes; and the
obstruction is topological, so no local smoothing removes it. The article must
show its configuration escapes the theorem, and the compactness hypothesis is the
place to look.

### [27] Hasse, Rieger, *A transformation theorem for transverse signature-type changing semi-Riemannian manifolds*, Diff. Geom. Appl. 103 (2026) 102370, arXiv:2407.09699
PRIOR, structural. A prescription turning an arbitrary Lorentzian manifold into a
signature-type changing one, with a converse theorem, locally and globally. This
is the construction `[135]` obstructs on non-orientable compact surfaces.

### [28] Rieger, Hasse, *Pseudo-timelike loops in signature changing semi-Riemannian manifolds with a transverse radical*, Results in Physics 78 (2025) 108478, arXiv:2409.02403
SUPPORT for the original motivation, CHALLENGE to the return placement. In a
signature-changing manifold with a degenerate but smooth metric, there are
**locally time-reversing loops through every point of the transition
hypersurface**. This is the closest thing in the literature to time reversal at a
signature change, and it is a theorem rather than a suggestion.

The other face of it, and the one that costs us: if there are time-reversing
loops through **every** point of the transition hypersurface, and no consistent
distinction between future- and past-directed vectors around them, then the two
crossings cannot be labelled "outward" and "return" by anything intrinsic to the
surface. The placement of the exit event on our time axis then cannot be read off
the matching alone; it needs a labelling imported from the Lorentzian side, and
Section 14 has to say what supplies it. This is the same degeneracy `[128]`
describes from the observational side, and the paper also notes that the loops
may appear to a nearby observer as **the creation of a particle-antiparticle pair
at two distinct points**.

### [30] Lafuente-Lopez, *About signature-change metrics on manifolds*, arXiv:2601.10793
CONTEXT. A one-parameter family of Lorentz-Riemann signature-change models
generalising Kossowski's, with local expressions around the change hypersurface.

### [105 partial], see Part C. Kleinian geometry entries are filed with the far side.

### [42] Mansouri, Nozari, *Signature change, inflation and the cosmological constant*, arXiv:gr-qc/9806109
CONTEXT, machinery. Colombeau generalised functions adapted to singular
hypersurfaces with signature change; equations for the dynamics of the singular
hypersurface.

### [43] *An approach to the primordial universe using Colombeau's simplified algebra*, arXiv:2303.11907
CONTEXT. The same machinery applied to the no-boundary setting.

### [44] *Time kink: modeling change of metric signature*, arXiv:2204.07828
CHALLENGE to Section 7.1. A continuous signature change driven by a
time-dependent kink in `g_00`. The most direct counter-model: it exhibits a
continuous interpolation and handles the degenerate point instead of treating it
as a wall. Section 26.1 lists "no continuous path between the two signatures can
be built" as a claim this work has **withdrawn**; the path exists, and its cost
is passing through a two-time intermediate region. This paper is why.

### [45] Hasse, Rieger, *Embedding signature-changing manifolds: a braneworld and Kaluza-Klein perspective*, arXiv:2508.08662
CONTEXT. Smooth signature change with a transverse radical, embedded. Depends on
the transversality `[135]` obstructs.

### [46] *A conceptual introduction to signature change through a natural extension of Kaluza-Klein theory*, arXiv:2510.02492
CONTEXT. The higher-dimensional manifold develops a Cauchy horizon instead of
staying globally hyperbolic. Relevant to Section 10.1, where the absence of a
Cauchy surface on the far side is a complaint; here it is a feature to work with.

### [47] *Overall signature of the metric and the cosmological constant*, arXiv:2306.11502
CONTEXT, possibly more. Signature change in the sense of the overall sign of the
metric flipping, with physical consequences, in several formulations of general
relativity. This is close to `s'^2 = -s^2`, which is exactly an overall sign flip
of the interval, and may be the correct frame for Section 1.

### [48] *Smooth signature change as a mechanism for singularity avoidance in BTZ black holes*, arXiv:2512.01486, and *Signature change in f(R, T_phi) theory*, arXiv:2603.08410
CONTEXT. Further degenerate-metric solutions, the second in a modified gravity
theory.

### [136] Kuhfittig, *Periodic signature change and embedding class one*, arXiv:2204.14222
CONTEXT, relevant for its structure. A four-dimensional spacetime of embedding
class two is reduced to class one by a coordinate transformation whose extra
dimension may be spacelike or timelike; making the free parameter a **periodic
function of time** produces a model interpretable as a **periodic change in the
signature of the embedding space**. The content is an oscillating-universe model
and is not ours, but it is the only construction in the corpus producing a
**repeated** signature change rather than one or two, with an explicit driving
parameter. If the article ever wants more than a single round trip, this is the
template.

### [137] Andrew, Steinfelds, Andrew, *Interpolated topology change and spin cobordism*, arXiv:2601.05957
CONTEXT, the companion to `[102]`. Regulated topology change built from smooth
Lorentzian spin cobordisms with interpolating metrics, allowing a **transient
failure of global hyperbolicity** while keeping smoothness, Lorentz signature and
spin compatibility, with a curvature functional weighting the admissible
interpolations and a Stiefel-Whitney constraint enforcing spin consistency. The
signature never changes here, so it is not our configuration. Its use is the
licence it formalises: a transient loss of global hyperbolicity between two
well-behaved Lorentzian ends is something to regulate and weight, not to
prohibit. Section 10.1's complaint that the intermediate region has no Cauchy
surface is exactly a transient failure of that kind, bracketed by two Lorentzian
regions.

### [102] Bais, May Custodio, Torres, *Existence results of Spin(2,n-1) pseudo-Riemannian cobordisms*, arXiv:2306.02749
SUPPORT for Section 7.5, and it makes the tear a computable question. Necessary
and sufficient conditions for a spin cobordism carrying a nondegenerate metric of
signature $(2, n-1)$ whose boundary restriction is a nonsingular time-orientable
Lorentzian metric, with the cobordism groups computed. Section 7.5 asserts a
two-time interlude between the two signatures; this is the framework in which
"does such an interlude exist for these boundary data" has an answer rather than
an argument. The article should state which cobordism class its configuration
falls into.

## B4. Deriving the transition rather than postulating it

Bears on Section 10.10, where the article compares its imposed transition with a
derived one.

### [80] Bojowald, Mielczarek, *Some implications of signature change in cosmological models of loop quantum gravity*, JCAP 08 (2015) 052, arXiv:1503.09154
SUPPORT and CHALLENGE at once, for Sections 12.1 and 10.10. The effective
equations that produce signature change are locally regular, so the derivation is
reliable; but the resulting problem is of **mixed type**, and the article works
out what that means by importing the Tricomi problem. That is the precise
mathematical name for our two-region split, and it comes with global obstructions
the paper spells out.

### [81] Bojowald, Brahma, *Signature change in loop quantum gravity: general midisuperspace models and dilaton gravity*, Phys. Rev. D 95 (2017) 124014, arXiv:1610.08840
PRIOR for Section 10.10. Signature change is derived, not postulated, for **all**
midisuperspace models without local degrees of freedom, as a consequence of
deformed covariance with holonomy modifications. The strongest existing answer to
whether a transition can come out of a theory rather than be put in by hand.

### [82] Magueijo, Rodriguez-Vazquez, Westman, Zlosnik, *Cosmological signature change in Cartan gravity with dynamical symmetry breaking*, Phys. Rev. D 89 (2014) 063542, arXiv:1311.4481
SUPPORT for Section 10.10 by a second, independent route. In a first-order
$SO(1,4)$ gauge theory with a symmetry-breaking Higgs field and no presupposed
metric, the signature is whatever the Higgs norm makes it, so a change of
signature is a change of phase of the symmetry breaking. The closest thing in the
literature to a mechanism for our transition, and it is gauge-theoretic rather
than kinematic.

### [83] Pedram, Jalalzadeh, *Signature change from Schutz's canonical quantum cosmology and its classical analogue*, Phys. Rev. D 77 (2008) 123529, arXiv:0805.4099
SUPPORT. Wave packets built from the Schrödinger-Wheeler-DeWitt equation with a
perfect fluid exhibit a transition from a finite Euclidean to a Lorentzian domain,
with a classical analogue in which the effect is reproduced by a repulsive fluid.
A signature change read off a quantum cosmological wave packet, with an
effective-source description on the other side. Note that this is one of only two
hits in the entire corpus for "signature change" together with "wave packet"; see
`[172]`.

### [110] Bojowald, Duque, *Emergent modified gravity*, Class. Quantum Grav. 41 (2024) 095008, arXiv:2404.06375
PRIOR for Section 10.10, and the foundation of arXiv:2312.09217. A complete
canonical formulation of general covariance allows the fundamental gravitational
fields to differ from an **emergent** spacetime metric, evading the usual
uniqueness theorems. This is the structure inside which signature change comes out
of the theory rather than being imposed on it. Citing 2312.09217 without this is
citing a consequence without its premise.

### [111] Tartaglia, *On the emergence of the Lorentz signature in an expanding universe*, arXiv:1207.0626
SUPPORT for Section 10.10 by an elementary route. Adding the strain of the
manifold as a field in the Lagrangian produces a boundary dividing the manifold
into a Euclidean and a Lorentzian region, and the boundary survives homogeneous
matter. The point is the cheapness of the mechanism: one extra term in the
action, no quantum gravity. arXiv:1707.07235 gets a signature change even more
cheaply, as an automatic consequence of Ricci flow through a critical point.
Derivations of signature change now exist at several very different levels of
sophistication, which weakens any claim that the transition is exotic.

### [191] Bojowald, Brahma, *Loop quantum gravity, signature change, and the no-boundary proposal*, arXiv:2011.02884
SUPPORT for Section 10.10, and it connects the derived transition to the
placement problem. Covariant models of loop quantum gravity generically imply
dynamical signature change at high density, and the paper works out the interplay
with the no-boundary and tunnelling wave-function proposals. Two results for us.
The **instabilities of inhomogeneous perturbations found in a Lorentzian
path-integral treatment are naturally cured** by the dynamical signature change,
which is the opposite verdict to `[19]`'s instability of the signature-changing
boundary and should be recorded as such. And **dynamical signature change does
not require Planckian densities when off-shell instantons are relevant**, which
is the only statement in the corpus that puts our threshold at a reachable scale
rather than at the Planck scale.

### [192] Ghaneh, Darabi, Motavalli, *Signature change in noncommutative FRW cosmology*, arXiv:1205.1037
### [193] Ghaneh, Darabi, Motavalli, *Signature change by GUP*, arXiv:1212.1577
CONTEXT, a pair. Conditions under which the no-boundary proposal has a classical
realisation as a continuous change of signature, for FRW with a self-interacting
scalar field on a **noncommutative phase space**; the model is quantised and
classical-quantum correspondence survives the noncommutativity, with the signature
transition supported for a continuous spectrum of negative bare cosmological
constant bounded by the noncommutativity parameters. The companion replaces
noncommutativity by a **generalized uncertainty principle** deformation and finds
that the transition then occurs even for a free massless scalar field with a
cosmological constant, without any ad hoc potential. Use for us: the transition is
cheap to obtain once the phase space is deformed, which is a third route
alongside `[81]`, `[82]` and `[111]`, and it is the route that costs the least in
matter content.

### [194] Vakili, Jalalzadeh, *Signature transition in Einstein-Cartan cosmology*, arXiv:1308.2877
CONTEXT. In Einstein-Cartan gravity with a Weyssenhoff perfect fluid, classical
FLRW solutions admit a degenerate metric in which the scale factor is smooth
across the Euclidean to Lorentzian transition, and it is the **spin-spin contact
interaction** of the Riemann-Cartan $U_4$ structure that makes such solutions
possible. Torsion, not exotic matter, is what supplies the transition here. Worth
noting against Section 3.6: this is a fourth way of getting a smooth change
without a matter layer, and its cost is a non-Riemannian connection.

### [195] Vakili, Jalalzadeh, Sepangi, *Spinor cosmology with signature change*, arXiv:gr-qc/0502076
### [196] *Bianchi type I spinor cosmology with signature change*, arXiv:gr-qc/0508090
### [197] *Compactification and signature transition in a Kaluza-Klein cosmology with a spinor field*, arXiv:gr-qc/0605015
CONTEXT, a cluster with one useful common finding. The matter source is a massive
Dirac spinor. In the flat Robertson-Walker case the Einstein-Dirac solutions are
classified for zero, negative and positive $\Lambda$, and **signature transitions
from a Euclidean to a Lorentzian domain occur for $\Lambda < 0$**; for massless
spinors, signature-changing solutions do not exist when the field is free but may
exist when it is self-interacting. The Bianchi I companion finds the same
$\Lambda < 0$ condition with smooth scale factors, and shows a close relation
between the quantum states of the Wheeler-DeWitt equation and the
signature-changing classical solutions. The $4+1$ Kaluza-Klein companion adds an
internal scale factor and gets $a \sim R^{-1}$ compactification in the Lorentzian
region.

The reason to keep these together: they are the only place in the corpus where a
**fermion** crosses a signature change and something survives. Set against
`[58]`, where no form of the Dirac equation across the change carries a conserved
inner product, the tension is real and unresolved: these papers get classical
Einstein-Dirac solutions through the change, `[58]` says there is no conserved
product on the solution space. Both can hold if the surviving object is not a
probability amplitude, which is `[130]`'s reading.

### [198] Darabi, Sepangi, *Signature transition and compactification in Kaluza-Klein cosmology*, arXiv:gr-qc/9905008
### [199] Embacher, *Signature change induces compactification*, arXiv:gr-qc/9410012
### [200] Embacher, *The trace left by signature-change-induced compactification*, arXiv:gr-qc/9411028
CONTEXT, and the third is the one with content for us. `[198]` and `[199]` both
find that classical signature change forces compactification of internal
dimensions, with the internal scale factor of order $\Lambda^{-1/2}$ and the
solutions stable against small perturbations, and the effective four-dimensional
metric Lorentzian, inflating and unique. `[200]` then asks what an infinite
succession of signature changes leaves behind: a minimally coupled scalar field
on such an oscillating background obeys, after coarse graining, a
four-dimensional field equation **containing a coupling to a non-metric
structure**, and in a multidimensional FRW model that structure is identical to a
**massive scalar field in its homogeneous mode**.

That is the only result in the corpus that answers the question "what does a
crossing leave in the equation obeyed on our side", and its answer is a mass-like
term. Compare Section 18.16, which asks what the interior path leaves behind, and
Section 25.5, which compares the map with an uninterrupted signal. If repeated
crossings show up as an effective mass, then a single crossing showing up as a
phase is the same statement at first order, and this entry is the precedent.

### [201] Nashed, *Effect of signature change in new general relativity*, arXiv:gr-qc/0202040
CONTEXT, narrow. The field equations of new general relativity, a teleparallel
theory, are solved for an absolute parallelism space with three unknown radial
functions, once by the conventional procedure and once allowing for signature
change. The second scheme yields a solution **different from Schwarzschild**, and
the energies computed by the superpotential method differ between the two
solutions. The point for us is small but real: in a theory where the fundamental
variable is a frame rather than a metric, allowing a signature change changes the
energy content of the solution, not merely its chart. That is the teleparallel
counterpart of Section 16.1's question about what our three-component energy is.

### [202] Darabi, *Signature change and vacuum condensation*, arXiv:gr-qc/0703154
CONTEXT, and one framing worth taking over. A duality-symmetric model with a
scalar field, an internal vector and a metric signature in which an effective
scalar equation appears at small scale whose potential acts like a Higgs
potential, **with the metric signature playing the role of an order parameter**.
Non-vanishing vacuum condensation occurs once a Euclidean to Lorentzian signature
change forms, and the mass scale of the excitations may contribute to the
cosmological constant in the Lorentzian sector. Signature as an order parameter is
the cleanest available statement of why a threshold is a phase boundary rather
than a coordinate artefact, and it is the same idea `[82]` implements
gauge-theoretically and `[206]` implements holographically.

### [203] Stern, Xu, *Signature change in matrix model solutions*, Phys. Rev. D 98 (2018) 086015, arXiv:1808.07963
### [204] *Complex Langevin studies of the emergent spacetime in the type IIB matrix model*, arXiv:2201.13200
### [205] *Signature change of the emergent spacetime in the IKKT matrix model*, arXiv:2205.04726
CONTEXT, the matrix-model cluster, and it is the one place where signature change
is an **output of a simulation** rather than a construction. `[203]`: classical
solutions of lower-dimensional IKKT-like Lorentzian matrix models, taken to their
commutative limit, give Poisson manifolds whose induced and effective metrics
**generically change signature** once quadratic and cubic terms are in the
bosonic action, and **a single manifold may exhibit multiple signature changes**;
the singularities at the changes are resolved away from the commutative limit.
`[204]` and `[205]` study the type IIB matrix model non-perturbatively with the
complex Langevin method to beat the sign problem, and investigate a scenario in
which the signature changes dynamically from Euclidean at early times to
Lorentzian at late times, with a Lorentz-invariant mass term added and numerical
support for a $(3+1)$-dimensional expanding late-time spacetime.

Three uses. Multiple signature changes on one manifold is our two-crossing
topology arising without being imposed. The resolution of the singularity away
from the commutative limit is an existence proof that the degeneracy of
Section 7.1 can be an artefact of a limit. And the sign problem being beaten by a
complex Langevin contour is a concrete instance of the complex-contour question
that `[139]` to `[143]` make central for the return placement.

### [206] *Signature change as a phase transition in holography*, arXiv:2505.13349
CONTEXT, speculative but on target. In holographic quantum gravity, Euclidean
pieces of spacetime appear in the large $N$ limit as semi-classical states, and
the essay argues that duals of entangled states are geometries **containing
Euclidean regions in order to preserve classical connectivity**, extending
ER-EPR to regimes where the Einstein-Rosen bridge becomes unstable but the
entanglement persists. For us: a Euclidean intermediate region as the thing that
maintains connectivity when a Lorentzian bridge cannot, which is precisely the
role our intermediate region plays, and it is here read as **entanglement**
rather than as travel. Section 19.4's insistence that correlation is not a signal
is the same distinction seen from the other side, and this paper is the reason the
distinction has to be made carefully rather than asserted.

### [207] *Signature change by a morphism of spectral triples*, arXiv:2402.05839
CONTEXT, algebraic. A connection between twisted spectral triples and
pseudo-Riemannian spectral triples, rooted in the interplay between twists and
Krein products; a notion of morphism of spectral triples is introduced that
transforms one triple into its dual, and on even-dimensional manifolds this
implements a **local signature change via the parity operator induced by the
twist**, so that the signature change transformation is governed solely by the
unitary implementing the twist. This is the noncommutative-geometry counterpart of
`[174]`: signature change as a single unitary acting on a fixed algebra, which is
what our $D$ is. If Section 2.2 wants a home for $D$ in an existing formalism,
this and `[174]` are the two candidates.

### [208] *Dynamical signature in models of gravity with complex manifolds and gauge fields*, arXiv:2111.06095
CONTEXT. Scenarios for dynamical signature change in Einstein-Cartan gravity:
complexification of the manifold and coordinates through new gauge fields, an
additional gauge symmetry for the vierbein, and a non-flat tangent space. A small
parameter measures the deviation of the signature from the background one and, in
the models with gauge fields, is the coupling constant of the gauge group.
Relevant because it makes the signature deviation a **continuously tunable
coupling**, which is the structure Section 24.6's curvature calculation has: our
surface curvature is proportional to a coupling strength and vanishes when the
coupling is set to zero.

### [209] *An emergent big bang scenario*, arXiv:2602.02646
CONTEXT. Physics rewritten in a purely Riemannian four-dimensional space, with
Lorentzian patches emerging from the interaction of all matter fields with a
**clock field** responsible for a signature change; if our universe is inside one
such patch the initial singularity is replaced by a smooth boundary where the
signature flips, and solutions are exhibited with a primordial nearly de Sitter
phase. The clock field is the mechanism worth noting: the article's threshold is
placed by hand at $V = c$, and this is an existing construction in which the
location of the flip is determined by a field rather than by a stipulation.

### [210] Shestakova, *On the Sakharov hypothesis of cosmological transitions with changes in the signature of the metric*, arXiv:2106.09416
CONTEXT, and it states our open problem in the path-integral language. Defining a
path integral over regions of different signature requires a prescription; one
option is to let time and space coordinates become purely imaginary, with the
signature in each region fixed by gauge conditions on the metric components. The
unresolved question isolated is exactly ours: **what boundary conditions should be
imposed on the boundaries between regions of different signature, and how those
conditions enter the definition of the integral**. That is the quantum
counterpart of the strong-versus-weak choice, and the paper confirms the choice is
not fixed by the formalism, which is why the two conditions give the two numbers
of Section 27.2. It is also evidence that post-2015 work on signature change has
moved to path-integral and quantum-cosmology framings rather than extending the
classical junction analysis. Do not expect a transmission coefficient from it.

### [189] Koyama, Soda, *Topology and signature changes in braneworlds*, arXiv:hep-th/0402024
SUPPORT for Section 7.5, and it is the cheapest existence argument in the corpus.
Topology and signature change of the universe have been believed to require
singularities classically or instantons quantum mechanically; in the braneworld
context such an event is **a classical, smooth event**. Explicit examples are
given from the Dirac-Born-Infeld action: topology change of the brane universe by
self-intersecting branes, and signature change on the brane **in an everywhere
Lorentzian bulk**. The boundary of the signature change is a curvature
singularity from the brane point of view but the event is completely smooth from
the bulk point of view. That last sentence is the strongest available answer to
`[92]`: the field equations survive because the singular description is the
induced one, and there is a higher-dimensional chart in which nothing is singular.
The article should say whether it is prepared to postulate a bulk.

### [190] *Gravitational collapse and singularity avoidance on a brane with a timelike extra dimension*, arXiv:2510.20874
CONTEXT, and the only entry that combines an extra **timelike** dimension with an
explicit matching problem. Homogeneous dust collapse in the Shtanov-Sahni
braneworld, whose extra dimension is timelike: the interior is
Friedmann-Lemaitre, the exterior a Vaidya envelope settling to
Reissner-Nordström with positive tidal charge. Smooth matching between interior
and static exterior is **precluded by the breakdown of Birkhoff's theorem** in
the braneworld, but as long as braneworld effects remain significant the brane
tension stays finite, the scalar curvature stays bounded, and no singularity
forms. Two points. The breakdown of Birkhoff is worth recording against `[104]`,
where a Kleinian Birkhoff theorem does hold; whether a uniqueness theorem is
available on the far side depends on which extra-dimensional structure is
assumed. And an extra timelike dimension is here used to **avoid** a singularity,
which is the constructive counterpart of `[92]`'s prohibition.

### [211] *Special geometry and the swampland for general spacetime signature*, arXiv:2111.09017
CONTEXT, and it belongs with `[72]` and `[106]`. Bosonic Lagrangians of vector
and hypermultiplets coupled to four-dimensional $\mathcal{N} = 2$ supergravity
are obtained in signatures $(0,4)$, $(1,3)$ and $(2,2)$ by compactifying type-II
strings in $(0,10)$, $(1,9)$ and $(2,8)$ on a Calabi-Yau threefold. Depending on
the signature the scalar geometries are special Kähler or special **para**-Kähler
for vector multiplets and quaternionic or para-quaternionic Kähler for
hypermultiplets, and the four-dimensional theories are related by spacelike,
timelike and mixed, **signature-changing T-dualities**. The para-structures are
the same $e^2 = +1$ objects `[72]` identifies as the neutral-signature replacement
for $i$, which is what $D$ is; and a signature-changing duality is a change of
signature that is a relabelling of one theory rather than a passage between two,
which is the strongest form of the inclusive reading of Section 27.1.

### [212] Zheltukhin, *Tensionless strings and spacetime signature change*, arXiv:hep-th/9908053
CONTEXT, narrow but pointed. A tensionless string model is constructed in
$\mathbf{R}^{2,2}$ and the string equations solved. The signature change
**radically changes the structure of the holonomy group of the null worldsheet**,
and as a result a worldsheet Dirac operator invariant under the holonomy group
becomes constructible, whereas in $(3+1)$-dimensional Minkowski space no such
possibility exists. Two uses: it is a second instance, after `[130]`, of the
spinorial structure being available on the exotic side and unavailable on ours,
which is the opposite of the usual direction of such statements; and holonomy is
the object Section 24.6's curvature criterion computes, so this is a precedent for
holonomy being the quantity that distinguishes the two signatures.

---
