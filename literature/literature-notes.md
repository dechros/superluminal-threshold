# Literature notes

Working notes taken while reading `literature/` (170 papers). One entry per
paper that bears on the article, grouped by theme. Each entry records what the
paper establishes, how it relates to a section of `article/article.md`, and
whether it precedes, supports, or contradicts that section.

Status legend: **PRIOR** the result predates ours, **SUPPORT** independent
agreement, **CHALLENGE** direct objection, **CONTEXT** background only.

---

## Group 1: the superluminal transformation branch

### [1] Dragan, Ekert, *Quantum principle of relativity*, New J. Phys. 22 (2020) 033038, arXiv:1910.02780
CONTEXT. The origin of this whole branch. Argues that keeping the superluminal
family of solutions in special relativity forces a non-deterministic picture
with superpositions and complex amplitudes. Only 1+1 dimensional.

### [2] Dragan, Debski, Charzynski, Turzynski, Ekert, *Relativity of superluminal observers in 1+3 spacetime*, Class. Quantum Grav. 40 (2023) 025013, arXiv:2209.01836
PRIOR, the direct source of our setting. Extends the above to 1+3, where the
metric of a superluminal frame becomes 3+1. Establishes that superluminal
observers are mutually indistinguishable, that superboosts preserve the speed
of light, and that point particle dynamics has to give way to field theory.

**Priority note that must go into the article.** The decomposition of a
superboost into an infinite-speed flip composed with an ordinary boost by the
dual velocity `c^2/V` is already remarked upon in this paper. Our Section 1
therefore does not introduce the factorisation; what it adds is the systematic
use of it as the organising principle, the proof by exhaustive scan that the
flip is forced, and the separation of the closure failure onto the boost layer.

### [3] Zaopo, *Group representations of Lorentz transformations extended to superluminal observers*, arXiv:2510.25385
PRIOR and far more complete than our Section 3. Builds the extension as a Klein
four-group realisation depending on polar and azimuthal angles, so it is
direction covariant where our D is not. Defines the extended Poincare group,
classifies all its unitary irreducible representations by Mackey induction,
shows how each restricts to a sum of ordinary Poincare UIRs, and derives the
wave equations from the Casimir eigenvalue problem, recovering Klein-Gordon,
Dirac and Maxwell plus new tachyonic and massless classes. Also contains the
factorisation and the `V = c^2/v` map.

Our position relative to it: our D is not in his extended group, because the
`x <-> y` swap D contains has three-dimensional determinant -1. Our Section
12.1 verifies this. That is a real difference but a narrow one.

### [4] Lake, *The (1+3)-dimensional 'quantum principle of relativity' is Einstein's principle of relativity*, Eur. Phys. J. C 85 (2025) 92, arXiv:2410.07017
CHALLENGE, peer reviewed, aimed straight at our Sections 1 to 3. Four claims:
the superboosts are ordinary Lorentz boosts in nonstandard notation; the
superflip is the identity plus an arbitrary relabelling; of the 24 permutations
6 preserve the line element and 18 do not; and the 18 always swap one fixed
axis regardless of the boost direction, which is coordinate dependent and so
unphysical. Our D is the first matrix in his list.

Note the structure of his argument: his step 2 is exactly our factorisation,
which he uses as a lemma on the way to concluding that a superboost is just a
subluminal boost. Our Section 17 concedes the substance of this. The article
must say so explicitly rather than leave it to Section 17.

### [5] Horodecki, *Comment on 'Quantum principle of relativity'*, New J. Phys. 25 (2023) 128001, arXiv:2301.07802
CHALLENGE. The subluminal and superluminal branches are separable: no coherent
formalism connects them, so the programme is incomplete. This is close to our
own Section 9 conclusion that Sigma is reflecting, reached from the other side.
Worth citing as independent agreement on the disconnection, while noting he
reads it as a defect and we read it as a result.

### [6] Del Santo, Horvat, *Comment on 'Quantum principle of relativity'*, arXiv:2203.03661
CHALLENGE. Argues the derivation of indeterminism and superposition from
superluminal frames is unwarranted.

### [7] Dragan, Ekert, *Reply to the comment*, arXiv:2206.15247 and *Reply*, New J. Phys. 25 (2023) 128002, arXiv:2309.00020
CONTEXT. In the second reply the authors concede the sharpest question, whether
the proposal yields measurable effects, and answer it only conditionally: yes
if tachyons exist. Directly relevant to our own Section 16 admission that the
Casimir signature sits on an unreachable surface.

### [8] Grudka, Stempin, Wojcik, Wojcik, *Superluminal observers do not explain quantum superpositions*, Phys. Lett. A 487 (2023) 129127, arXiv:2306.03961
CHALLENGE, peer reviewed. Used consistently, the generalised transformation
gives no correspondence between a definite classical path and the multiple
paths of quantum mechanics.

### [9] Sen, Del Santo, *Superluminal transformations and indeterminism*, arXiv:2601.15263
CHALLENGE, and the sharpest formal result in this group. A theory-independent
no-go theorem: any framework admitting non-order-preserving superluminal
transformations must give up one of four things, finite information,
time-symmetric informational content, the past storing memory, or time fixing a
preferred causal ordering. Our Section 6 derives loss of determinism from the
equation type; this theorem says something stronger and more general about what
that loss costs. Our indeterminism cannot come from finite information.

### [10] Sen, Salzger, Rudnicki, *Superluminal quantum reference frames*, arXiv:2506.11787
SUPPORT. Extends quantum reference frames to superluminal Lorentz
transformations and resolves the negative-energy paradox inside that framework,
also showing Bell probabilities are conserved. Relevant to our Section 4, where
the same negative-energy issue appears as the three-component energy vector.

### [11] Sienicki, Sienicki, *From kinematics to interference*, arXiv:2512.05164
CHALLENGE, organisational. Separates kinematics, operational content, and
dynamics, and insists that writing coordinate maps is not providing a physical
theory. Superposition is defined by closed-loop interference, not by drawing
paths. This is the cleanest statement of what our article currently lacks: it
is entirely layer K, with a little of layer D, and nothing in layer O.

### [12] Nanni, *Electromagnetic field theory in superluminal spacetime*, Indian J. Phys. (2023), arXiv:2305.12505
PRIOR to our Section 11. Obtains Maxwell equations and the single-photon wave
equation by superluminal transformation of the ordinary ones, without complex
quantities, and finds X-shaped solutions in the region bounded by the infinite
light cone. Goes further than we do: we verify that the invariant survives, he
solves the transformed equations.

### [13] Peacock, *Superluminal transformations in spacetimes of definite metric*, arXiv:2308.03796
CONTEXT. Revives Sutherland and Shepanski 1986: positive definite metric,
Lorentz factor `1/sqrt(beta^2-1)`, real proper times for superluminal frames.
An older alternative to signature change, worth one sentence of contrast.

### [14] Ibison, *Tachyons and superluminal boosts*, arXiv:0704.3277
CONTEXT. Extensions of the Lorentz group, discussion of whether imaginary
coordinates are admissible in superluminal frame transformations.

### [15] Perepelitsa, *Looking for a theory of faster-than-light particles*, arXiv:1407.3245
CONTEXT with one sharp claim: a preferred reference frame is mandatory in any
tachyon theory if causality is to be conserved. Sets a condition our model does
not currently meet or discuss.

---

## Group 2: signature change, junction conditions, degenerate metrics

### [16] Hayward, *Junction conditions for signature change*, Class. Quantum Grav. 9 (1992) 1851, arXiv:gr-qc/9303034
PRIOR to our Section 9, and the closest single precedent in the corpus. Treats
the Klein-Gordon field on a signature-changing background and finds the
junction condition as the coefficient of the Dirac distribution in the field
equations, giving `phi' delta = 0` and `a' delta = 0`, that is, the vanishing of
the normal derivative at the junction. This is our `pi|Sigma = 0`.

Two differences that matter. First, he does not assume the condition in order
to make sense of the equations; it falls out of the distributional structure.
Second, he obtains the gravitational counterpart as well, the vanishing of the
second fundamental form of the junction surface, which we do not touch.

### [17] Embacher, *Actions for signature change*, Phys. Rev. D 51 (1995) 6764, arXiv:gr-qc/9501004
PRIOR and, for us, the most consequential paper in the group. It frames a
controversy we did not know we were taking a side in: whether the extrinsic
curvature near the surface must merely be **continuous** (weak signature
change) or must **vanish** (strong signature change). Embacher writes down
eight candidate actions and works out which junction condition each implies,
settling on `S_7` as the best strong model and `S_8` as the best weak one.

Our `pi|Sigma = 0`, and hence the reflecting threshold of Section 9, is the
**strong** condition. The article currently presents it as the only
possibility. It is one of two, and the choice has to be argued rather than
assumed.

### [18] Alty, Fewster, *Initial value problems and signature change*, Class. Quantum Grav. 13 (1996) 1129, arXiv:gr-qc/9501026
PRIOR to our Section 6 and rigorous where we are heuristic. Operator theory on
a two-dimensional signature-changing spacetime: boundary conditions come from
self-adjoint extensions of the Schrodinger Hamiltonian, and requiring that they
take the form of junction conditions with a continuous field picks out one
particular set. The Klein-Gordon initial value problem is then proved ill posed,
with solutions unstable and the `L^2` norm divergent in finite time for smooth
compactly supported data.

Our Section 6 reaches the same verdict by inspecting the sign of a mode
coefficient. Theirs is a proof; ours is a demonstration. The article should cite
them and say so.

### [19] Egusquiza, *Self-adjoint extensions and signature change*, Class. Quantum Grav. 12 (1995) L89, arXiv:gr-qc/9503015
CHALLENGE, and it lands on Sections 9 and 16. Studying self-adjoint extensions
of the spatial d'Alembertian with two signature changes, he identifies boundary
conditions parametrised by `U(2)` that correspond to **Dirichlet** conditions
for the fields. Our threshold condition is Neumann. He further argues that
quantum fields then make the signature-changing boundaries **unstable**, so the
Kleinian region either collapses or expands without bound.

If the correct boundary condition is Dirichlet rather than Neumann, then the
Casimir sign and coefficient in Section 16 change, and the reflecting reading of
Section 9 needs restating. This has to be addressed head on.

### [20] Dray, *Einstein's equations in the presence of signature change*, J. Math. Phys. 37 (1996) 5627, arXiv:gr-qc/9610064
PRIOR and a warning. Derives a generalised Lanczos equation by variational
methods: no distributional term in the stress tensor, and so no surface layer,
exactly when the extrinsic curvature is continuous. The conclusion is blunt:
there are no canonical Einstein equations in the presence of signature change,
because formal substitution of a signature-changing metric into equations
derived for constant signature is not obviously derivable from any starting
principle, and for a continuous signature-changing metric there is no metric
volume element at the surface at all.

Anything we add on gravity has to declare which version of the field equations
it is using and why.

### [21] Dray, Ellis, Hellaby, Manogue, *Gravity and signature change*, Gen. Rel. Grav. 29 (1997) 591, arXiv:gr-qc/9610063
PRIOR. Using proper time as the coordinate admits smooth generalised
orthonormal frames, which makes both the variational treatment of Einstein's
equations and distribution theory tractable across the change. This is the
practical route into the gravity gap.

### [22] Dray, *Tensor distributions in the presence of degenerate metrics*, Int. J. Mod. Phys. D 6 (1997) 717, arXiv:gr-qc/9701047
CONTEXT, machinery. Tensor distributions without assuming a metric, which is
what a degenerate surface requires.

### [23] Dray, Ellis, Hellaby, *Note on signature change and Colombeau theory*, Gen. Rel. Grav. 33 (2001) 1041, arXiv:gr-qc/0012047
CHALLENGE to the framing of the whole area, and it disciplines us. The
so-called controversies are disagreements about unstated assumptions; different
mathematical choices give different boundary conditions and may suit different
physical situations, and labelling any one choice as *the* Einstein equations is
rhetoric rather than physics. Our Section 9 should state its assumptions
instead of presenting its junction condition as forced.

### [24] Hellaby, Sumeruk, Ellis, *Classical signature change in the black hole topology*, Int. J. Mod. Phys. D 6 (1997) 211, arXiv:gr-qc/9907042
PRIOR to our Section 13. Models the rebirth of a Schwarzschild black hole as a
double signature change, joining two Lorentzian universes through a Euclidean
bounce, viable with and without matter, with realistic models hiding the change
surfaces inside the horizon. Notes that removing all surface effects needs not
only vanishing extrinsic curvature but also vanishing three-dimensional Ricci
scalar, which rules out realistic cosmological models.

### [25] Capozziello, De Bianchi, Battista, *Avoiding singularities in Lorentzian-Euclidean black holes*, arXiv:2404.17267
PRIOR to Section 13 and much stronger. A Schwarzschild metric changing
signature across the horizon, regularised by Hadamard partie finie, **proved to
solve the vacuum Einstein equations**, with atemporality as the mechanism that
removes the singularity, quantified by a regularised Kretschmann invariant.

### [26] Bartolo, Caponio, Germinario, Sanchez, *Lorentzian-Euclidean black holes and Lorentzian to Riemannian metric transitions*, Phys. Rev. D 111 (2025) 104058, arXiv:2502.14108
PRIOR and partially corrective of [25]: proper time to reach the horizon stays
finite, so the Lorentzian-Euclidean model needs revision. Also observes that
the change hypersurface is naturally spacelike and identifiable with the causal
boundary of the Lorentzian sector, that degeneracy of the metric collapses the
causal cones to a line while degeneracy of the dual metric collapses them to a
hyperplane.

The cone-collapse picture is the geometric content of our Section 13.3
degeneracy argument, stated far more precisely.

### [27] Hasse, Rieger, *A transformation theorem for transverse signature-type changing semi-Riemannian manifolds*, Diff. Geom. Appl. 103 (2026) 102370, arXiv:2407.09699
PRIOR, structural. A prescription turning an arbitrary Lorentzian manifold into
a signature-type changing one, with a converse theorem, locally and globally.

### [28] Rieger, Hasse, *Pseudo-timelike loops in signature changing semi-Riemannian manifolds with a transverse radical*, Results in Physics 78 (2025) 108478, arXiv:2409.02403
SUPPORT, and the single most interesting result in the corpus for the original
motivation behind this project. In a signature-changing manifold with a
degenerate but smooth metric, there are **locally time-reversing loops through
every point of the transition hypersurface**.

This is the closest thing in the literature to time reversal at a signature
change, and it is a theorem rather than a suggestion. Our Section 7 concludes
that region II has no arrow at all; this paper says something sharper about the
hypersurface itself. Worth a section of its own.

### [29] White, Weinfurtner, Visser, *Signature change events: a challenge for quantum gravity?*, Class. Quantum Grav. 27 (2010) 045007, arXiv:0812.3744
CHALLENGE to Sections 15 and 16. Whatever the underlying classical theory, a
quantum field on a signature-changing background has severe problems, in
particular the production of a naively infinite number of particles. They relate
the production to quantum tunnelling half-way up a barrier and give WKB
estimates.

Our Section 16 says region II is a correlation theory rather than a particle
theory. That reads as a reformulation of their problem rather than an answer to
it, and the article should say which.

### [30] Lafuente-Lopez, *About signature-change metrics on manifolds*, arXiv:2601.10793
CONTEXT. A one-parameter family of Lorentz-Riemann signature-change models
generalising Kossowski's, with local expressions around the change hypersurface.

---

## Group 3: multiple time dimensions

### [31] Bars, *Two-time physics*, arXiv:hep-th/9809034; *Two-time physics in field theory*, Phys. Rev. D 62 (2000) 046007, arXiv:hep-th/0003100; *Survey*, Class. Quantum Grav. 18 (2001) 3113, arXiv:hep-th/0008164
PRIOR to our Section 8 in spirit. An `Sp(2,R)` gauge symmetry makes many
one-time systems different gauge fixings of a single two-time system in `d+2`
dimensions, so the extra time is removed by gauge rather than by fiat. Our
Section 8 finds the superluminal rest states to be a single `O(3)/O(2)` orbit,
that is, a gauge redundancy. Same mechanism, and Bars has the mature version:
field theory, interactions, gravity and gauge backgrounds.

### [32] Piceno, Rosado, Sadurni, *Fundamental constraints on two-time physics*, Eur. Phys. J. Plus 131 (2016) 352, arXiv:1512.05345
CHALLENGE to region II as a whole. Extending Newton's second law to `1+2`
dimensions and integrating it exactly gives **effective single-time evolution
for any initial condition**. In the quantum case, imposing probability
conservation on a two-time unitary evolution yields a generalised uncertainty
relation that bounds the observability of the second temporal axis by level
spacings, total duration and Planck's constant.

If extra times collapse to an effective single time whenever probability is
conserved, region II may be less exotic than our Section 7 claims. The article
has to engage with this rather than ignore it.

### [33] Nash, *Possible consistent extra time dimensions in the early universe*, arXiv:1310.0697
SUPPORT. An early universe with four time dimensions in which the extra times
do not source instabilities: the perturbations have decaying quasi-normal modes.
Useful as a counterweight to the usual claim that extra times are automatically
fatal.

### [34] Pettini, *Quantum entanglement without nonlocal causation in (3,2)-dimensional spacetime*, Phys. Rev. Research 7 (2025) 013261, arXiv:2311.17070
SUPPORT, peer reviewed. Uses an extra time dimension with a warping factor so
that finite-velocity information exchange reproduces entanglement correlations,
and the warp confines massive particles in the extra time, explaining why it is
not experienced. Proposes a Bell-type experiment.

This is the only paper in the corpus that turns extra time into a proposed
measurement. It is the closest model for our own Priority D.

### [35] Holland, *A note on the ultrahyperbolic wave equation in 3+3 dimensions*, arXiv:1211.4164
CONTEXT, mathematics. The ultrahyperbolic wave operator and the Xi transform
form an exact couple. Relevant to the structure of solutions when the number of
times exceeds one.

---

## Group 4: tachyon quantum field theory

### [36] Paczos, Debski, Cedrowski, Charzynski, Turzynski, Dragan, Ekert, *Covariant quantum field theory of tachyons*, Phys. Rev. D 109 (2024) 018501, arXiv:2308.00450
CHALLENGE to our Section 14, and the one the article must answer. Claims that
the three standard obstructions, spectrum unbounded from below, unstable
frame-dependent vacuum, and non-covariant commutators, are artefacts of
representing the Lorentz group in too small a Hilbert space, and that doubling
the space to `F (x) F*` removes all three.

Our Section 14 lists three obstructions of the same character. If this
construction works, our section is answered.

### [37] Jodlowski, *Covariant quantum field theory of tachyons is unphysical*, Phys. Rev. D 110 (2024) 115042, arXiv:2406.14225
SUPPORT for our Section 14, and it settles the previous entry. Shows that the
doubled-space theory **is not quantum at all**: the tachyon field commutes at
every point, so the canonical commutation relations fail, and what remains is a
classical theory with no quantum dynamics in the twin space. Also finds the
Feynman prescription there violates unitarity, and that the LSZ asymptotic
condition cannot be established by substituting non-normalisable plane waves.

So the obstructions of our Section 14 survive the proposed cure. This is a
peer-reviewed result we can lean on, and it should be cited exactly where we
state the three obstructions.

### [38] Jodlowski, *Is a covariant virtual tachyon viable?*, Phys. Rev. D 113 (2026) 065016, arXiv:2602.20474
SUPPORT, stronger. Purely virtual tachyons under the fakeon prescription do not
cure the instability either, and their interactions with Standard Model fields
induce Lorentz violation with a quantitative bound. Together with the previous
paper this establishes that no covariant quantum field theory of superluminal
objects, propagating or virtual, is currently available.

Read against our Section 14 this is agreement; read against the model as a
whole it is a warning that the far side may not admit a quantum field theory in
any formulation, ours included.

### [39] Ostrowski, *Casimir effect for tachyonic fields*, Found. Phys. Lett. 18 (2005) 227, arXiv:hep-th/0307051
PRIOR to our Section 16 and in direct numerical conflict with it. Computing the
renormalised vacuum energy by the Abel-Plana formula in an absolute
synchronisation scheme, the tachyonic Casimir energy and force are **not**
monotonic: they oscillate, change sign repeatedly, are not differentiable in the
separation, and the force has jumps to infinity.

Our Section 16 quotes the ordinary Neumann-Neumann result
`-pi^2 hbar c / (720 L^3)`, smooth and always attractive. Either the far-side
field is not tachyonic in his sense, or one of the two calculations does not
apply. This has to be resolved, not left standing.

### [40] Rembielinski, *Quantization of the tachyonic field and the preferred frame*, arXiv:hep-ph/9509219
PRIOR, and an alternative to our whole approach. Consistent quantisation of an
imaginary-mass field via a choice of synchronisation that keeps absolute
causality and exact Lorentz symmetry, at the price of a preferred frame arising
from spontaneous breaking of the synchronisation group. The relativity
principle is given up, Lorentz symmetry is not.

Together with [15] this is the standing alternative: a preferred frame buys
consistency. Our model pays a different price, the reflecting threshold. The
article should say that these are the two known prices and that we chose one.

### [41] Radzikowski, *Stable, renormalizable, scalar tachyonic quantum field theory with chronology protection*, arXiv:0804.4534
CONTEXT. Microlocal argument that Lorentz symmetry breaking is required for a
renormalizable tachyonic theory, then a model in a preferred tachyon frame with
no exponentially growing modes, satisfying a chronology-protection notion of
causality and the Hadamard condition. Another instance of the same trade.

---

## Group 5: tools for the degenerate surface

These are the papers that supply what our Section 13.3 lacks. Each of them
meets a degenerate metric and works through it rather than stopping.

### [42] Mansouri, Nozari, *Signature change, inflation and the cosmological constant*, arXiv:gr-qc/9806109
Colombeau generalised functions adapted to singular hypersurfaces with
signature change; equations for the dynamics of the singular hypersurface.

### [43] *An approach to the primordial universe using Colombeau's simplified algebra*, arXiv:2303.11907
The same machinery applied to the no-boundary setting.

### [44] *Time kink: modeling change of metric signature*, arXiv:2204.07828
A continuous signature change driven by a time-dependent kink in `g_00`. The
most direct counter-model to our Section 13.3: it exhibits the continuous
interpolation we argue cannot work, and handles the degenerate point instead of
treating it as a wall.

### [45] Hasse, Rieger, *Embedding signature-changing manifolds: a braneworld and Kaluza-Klein perspective*, arXiv:2508.08662
Smooth signature change with a transverse radical, embedded.

### [46] *A conceptual introduction to signature change through a natural extension of Kaluza-Klein theory*, arXiv:2510.02492
The higher-dimensional manifold develops a Cauchy horizon instead of staying
globally hyperbolic. Relevant to our Section 14.1 complaint that region II has
no Cauchy surface: here that is a feature to be worked with.

### [47] *Overall signature of the metric and the cosmological constant*, arXiv:2306.11502
Signature change in the sense of the overall sign of the metric flipping, with
physical consequences, in several formulations of general relativity. This is
close to our `s'^2 = -s^2`, which is exactly an overall sign flip of the
interval, and may be the correct frame for our Section 2.

### [48] *Smooth signature change as a mechanism for singularity avoidance in BTZ black holes*, arXiv:2512.01486, and *Signature change in f(R, T_phi) theory*, arXiv:2603.08410
Further degenerate-metric solutions, the second in a modified gravity theory.

---

## Group 6: the one template for a testable prediction

### [49] *Inflation from covariant signature change: a geometric mechanism*, arXiv:2607.01274
The single most useful paper for Priority D. A smooth Euclidean to Lorentzian
signature change, encoded by a scalar interpolator along a timelike direction,
**drives a finite interval of accelerated expansion**. Signature change is thus
turned into an inflationary mechanism with observable consequences, rather than
a kinematic curiosity.

If our threshold is to predict anything measurable, this is the shape the
argument has to take: put the transition somewhere it can act, then compute
what it does to something we already observe.

### [50] Bojowald et al., *Signature change in loop quantum cosmology*, arXiv:1207.4657
Also derives corrections to the inflationary scalar and tensor power spectra
from the signature change. Same lesson.

---

## Group 7: causality and the experimental bound

### [51] Cohen, Glashow vacuum-Cherenkov constraint, as developed in arXiv:1110.4591, arXiv:1201.1322, arXiv:1112.0264, arXiv:1201.5363, arXiv:1711.02660
The decisive experimental instrument in this whole area. A superluminal
particle radiates pairs, `nu -> nu + e+ + e-`, and loses energy; the absence of
that loss bounds the superluminality. It is what killed the OPERA reading and
what constrains every tachyonic neutrino proposal since.

Our model is currently immune to this only because nothing crosses the
threshold. If we ever allow crossing, this is the first constraint we have to
survive, and it is severe.

### [52] *Velocity requirements for causality violation*, arXiv:1304.5522
Gives an explicit formula for the relative velocity required to produce a
causal contradiction. Useful for stating precisely how far our threshold sits
from any regime where the usual paradoxes bite.

### [53] The OPERA aftermath, arXiv:1111.7050, arXiv:1109.6562, arXiv:1110.0424, arXiv:1109.6160, arXiv:1201.4147, arXiv:1110.1790, arXiv:1112.1324
The measurement, the constraints that contradicted it, and the mundane
explanations, synchronisation conventions, non-inertial frames, weak values,
damped pulses. Collectively: apparent superluminal velocities have so far
always had a subluminal explanation.

### [54] Modern Lorentz invariance tests, arXiv:gr-qc/0502097, arXiv:1304.5795, arXiv:0909.4927, arXiv:1906.05933, arXiv:hep-ph/0407232
The standing bounds. Any coupling between our region II and ordinary matter
would have to hide inside these.

### [55] *Impossibility of superluminal signalling in Minkowski space-time does not rule out causal loops*, arXiv:2206.12887
Separates relativistic causality from operational causality. Relevant because
our Section 9 rules out signalling by construction, which is not the same as
ruling out causal loops.

### [56] *k-essence, superluminal propagation, causality and emergent geometry*, arXiv:0708.0561, and *Attractor scenarios and superluminal signals in k-essence cosmology*, arXiv:0706.3994
Superluminal propagation on a classical background without causal paradoxes,
because the effective cone differs from the light cone. The standard example of
how superluminality can be harmless, and a useful contrast to our sharper claim.

### [57] Chronology protection, arXiv:gr-qc/0009061, arXiv:hep-th/0602293, and the closed timelike curve surveys arXiv:2101.08592, arXiv:1008.1127, arXiv:gr-qc/0405114
Background for any claim about time reversal at the threshold. Read together
with [28], the loops found there are local and at the hypersurface, which is
exactly the regime these protection arguments are least decisive about.

---

## What the reading changes in the article

1. Section 1 must not claim the factorisation as new. It is in [2] and used as
   a lemma by [4].
2. Section 6 must cite [18], which proved the ill-posedness rigorously.
3. Section 9 must present its junction condition as the strong choice among
   the alternatives set out in [17], acknowledge [16] as the precedent, and
   answer the Dirichlet alternative of [19].
4. Section 13 must cite [24], [25], [26] and confront [44], which builds the
   continuous interpolation we argue against.
5. Section 14 is strengthened, not weakened, by [37] and [38].
6. Section 16 conflicts numerically with [39] and must resolve it.
7. Section 7 has to face [32], where extra times collapse to one.
8. A new section is needed on [28], the time-reversing loops.
9. Priority D should follow the template of [49].

---

## Group 8: added by the background sweep

Twenty-nine papers read in a targeted sweep of the four cells that Bölüm 21
leaves empty: particle production on a signature-changing background, the
strong versus weak junction condition, the field theory of a (2,2) region, and
probability conservation with more than one time.

### Particle production and quantum fields on a signature-changing background

### [58] Romano, *Scalar and spinor fields in signature changing spacetimes*, Phys. Rev. D 47 (1993) 4328, arXiv:gr-qc/9303033
PRIOR, and the first real literature behind Bölüm 16.2. Reviews the Dray et al.
result that a signature change produces particles for a massless scalar, then
tries to extend it to spin one half. The extension fails: of the inequivalent
forms the Dirac equation can take across the change, **none** carries a
conserved inner product on the solution space. That is a direct precedent for
our Bölüm 14 obstruction, obtained thirty years earlier and for the same
reason, and it also means our Bölüm 11 electromagnetic treatment cannot simply
be assumed to carry over to fermions.

### [59] Weinfurtner, White, Visser, *Trans-Planckian physics and signature change events in Bose gas hydrodynamics*, Phys. Rev. D 76 (2007) 124008, arXiv:gr-qc/0703117
SUPPORT for the possibility of a calculation, CHALLENGE to Bölüm 9.1's wall.
An emergent metric in a Bose gas whose signature can be driven Lorentzian to
Riemannian by tuning the microscopics, with the **number of particles produced
by a finite-duration Euclidean event actually computed**. This is the concrete
template for Bölüm 16.2: the question we leave open has a worked answer in an
analogue system, and the answer is that production is large and depends on the
duration of the event, not zero.

### [60] Weinfurtner, White, Visser, *Signature-change events in emergent spacetimes with anisotropic scaling*, J. Phys. Conf. Ser. 189 (2009) 012046, arXiv:0905.4530
SUPPORT. The companion analysis. The anisotropic (Lifshitz-like) scaling of the
microscopic theory regulates the particle production that would otherwise
diverge. Bears on Bölüm 9.1's quantum stability question: what makes a
signature-changing surface survive is a short-distance modification, not the
junction condition.

### [61] Castelló Gomar, Mena Marugán, *Uniqueness of the Fock quantization of scalar fields and processes with signature change in cosmology*, arXiv:1403.6984
SUPPORT for Bölüm 14 and 16. Invariance of the vacuum under the spatial
symmetries plus unitary implementability of the dynamics fixes the Fock
representation uniquely, and the criterion still applies through a signature
change. This is the missing piece of Bölüm 16: our vacuum is currently chosen
by hand, and there is a uniqueness theorem that says how to choose it.

### [62] Darabi, Setare, *Casimir effect in a two dimensional signature changing spacetime*, J. Math. Phys. 47 (2006) 032501, arXiv:gr-qc/0507043
PRIOR, and the closest existing result to Bölüm 16's Casimir signature. A
massless scalar on a two-dimensional cylinder with a signature-changing metric
gives a **nonzero pressure on the surface of signature change**, which
destabilises the signature-changing region and back-reacts on the spectrum.
Two consequences for us: our Bölüm 16 Casimir number is not on an unreachable
surface in this setting, and Bölüm 9.1's quantum stability question is answered
negatively in the analogous two-dimensional case.

### Strong versus weak junction condition, the Bölüm 9.1 dispute

### [63] Hellaby, Dray, *Comparison of approaches to classical signature change* (reply comment), Phys. Rev. D 52 (1995) 7333, arXiv:gr-qc/9601040
PRIOR, and the paper Bölüm 9.1 most needs. It sets out explicitly the two
philosophies our article has to choose between: Hayward's Lagrangian route,
which amounts to an imaginary proper time on one side, versus a strictly
classical route, and Darmois-Israel junction conditions versus Lichnerowicz
ones. It also states plainly that there is as yet **no rigorous derivation** of
the distributional field equations, so both sides are postulates. Our Bölüm 9.1
must present its strong condition as a postulate of this kind rather than as a
derivation.

### [64] Dray, Manogue, Tucker, *Boundary conditions for the scalar field in the presence of signature change*, Class. Quantum Grav. 12 (1995) 2767, arXiv:gr-qc/9501034, and [65] Hayward, *Comment*, arXiv:gr-qc/9502001
CHALLENGE, taken together the sharpest exchange in this literature. Hayward's
comment charges that the proposed solutions do not satisfy the equation, that
the variational equations are singular at the change, and that the
distributional field equations are ill defined. Whichever side one takes, the
exchange shows that the choice of boundary condition at a signature change is
contested at the level of whether the objects exist, not merely of which is
preferable. Bölüm 9.1 currently reads as if the strong condition were the
obvious one.

### [66] Kriele, *Distinguished solutions for discontinuous signature change with weak junction conditions*, arXiv:gr-qc/9610016
CHALLENGE, directly to Bölüm 9.1. Takes the **weak** junction condition, the
alternative we reject, imposes regularity, and shows the solution space for
dust and scalar field models is still controlled, a one-parameter family of
Riemannian three-manifolds. So the weak condition is not degenerate or empty;
it is a live competitor with its own uniqueness structure. Our argument that
total reflection is the only flux-conserving option holds only under the strong
condition, and this paper is what forces us to say so.

### [67] Hartley, Tucker, Tuckey, Dray, *Tensor distributions on signature-changing space-times*, Gen. Rel. Grav. 32 (2000) 491, arXiv:gr-qc/9701046
SUPPORT for Bölüm 9. Establishes that covariant differentiation can be defined
on a class of tensor distributions wide enough to be physically interesting,
for both continuous and discontinuous signature change. This is the technical
licence Bölüm 9 uses implicitly when it writes distributional quantities at the
threshold, and it should be cited there.

### The (2,2) region: what is actually known about Kleinian field theory

### [68] Heckman, Joyce, Sakstein, Trodden, *Exploring 2+2 answers to 3+1 questions*, arXiv:2208.02267
SUPPORT, and the single most useful addition for Bölüm 13.5. Argues that
Kleinian signature is a legitimate computational arena: just as Euclidean
continuation constructs the ground state, continuation to (2,2) constructs a
state of **low particle flux** along the continued direction, and (2,2) admits
its own supersymmetry algebra constraining correlators. Our (2,2) intermediate
region therefore has a defensible status, but as an auxiliary continuation
rather than as a region anything lives in.

### [69] Crawley, Guevara, Miller, Strominger, *Black holes in Klein space*, arXiv:2112.03954
SUPPORT for Bölüm 13. Kerr-Taub-NUT continued to (2,2) has a global structure
with a toric Penrose diagram resembling its Lorentzian counterpart, and the
continuation is induced naturally by continuation of the S-matrix. Directly
relevant to Bölüm 13's horizon comparison: the Kleinian side of a black hole
is a well-defined geometry, not a breakdown.

### [70] Atanasov, Ball, Melton, Raclariu, Strominger, *(2,2) scattering and the celestial torus*, arXiv:2101.09591
CONTEXT for Bölüm 13.5 and 6. In (2,2), null infinity has only one connected
component and becomes a null interval times a celestial torus; there is no
clean separation into past and future infinity. That is the asymptotic
statement of the same thing Bölüm 6 says about predictability: an
ultrahyperbolic region has no in-state/out-state split to hang a Cauchy problem
on.

### [71] Pavšič, *Quantum field theories in spaces with neutral signatures*, arXiv:1210.6820
SUPPORT with a caveat, for Bölüm 14 and 16. In neutral signature the positive
and negative energy contributions cancel and the vacuum energy vanishes, so
there is no cosmological constant problem. Stability under interactions is the
open issue, and the toy oscillator in $M_{1,1}$ stays bounded for some
interactions and runs away for others. This is the best available answer to
Bölüm 14's third obstacle, and it is a conditional one.

### [72] Sabra, *Flow equations in arbitrary signature*, arXiv:2111.05141
CONTEXT for Bölüm 12 and 15. Four-dimensional N=2 supergravity written in
$(t,s)$ signature for all $(t,s)$, with the Euclidean and neutral cases governed
by para-special Kähler geometry (para-complex rather than complex structures).
The technical point that matters to us: passing to neutral signature replaces
$i$ by a para-complex unit with $e^2 = +1$, which is exactly the structure our
$D$ has, and which Bölüm 15's Wick rotation rule is groping towards.

### Multiple times: well-posedness and probability conservation

### [73] Craig, Weinstein, *On determinism and well-posedness in multiple time dimensions*, arXiv:0812.0210
PRIOR and decisive for Bölüm 6 and 7.3. For the ultrahyperbolic equation the
Cauchy problem on a codimension-one hypersurface of mixed signature **is** well
posed in Sobolev spaces, but only under a nonlocal constraint on the data; on
higher-codimension hypersurfaces it is ill posed through failure of uniqueness.
Bölüm 6 says predictability collapses on the far side. This paper says the
truth is finer: it collapses locally but can be restored by a nonlocal
constraint, and the price of that constraint is what we should be arguing about.

### [74] Weinstein, *Multiple time dimensions*, arXiv:0812.3869
CHALLENGE to the framing of Bölüm 6. The companion essay, stating the
conclusion bluntly: contrary to conventional wisdom there is a well-posed,
deterministic, stable initial value problem in multiple time dimensions. If
this is right, then item 6 of our seven-point list is not a consequence of the
equation type but of a particular choice of initial surface.

### [75] Tumulka, *Multi-time wave functions versus multiple timelike dimensions*, Found. Phys. 47 (2017) 1582, arXiv:1708.03376
CHALLENGE, and the paper Bölüm 7.3 has to answer. Draws the distinction our
article blurs: multi-time wave functions, one time per particle, are well
behaved and have unique solutions with a conserved probability current;
equations on a manifold with several timelike **dimensions**, signature
$++--$ and the like, are typically ill posed and presumably unphysical. Our
region II is the second kind, not the first, and this paper says so explicitly.

### [76] Petrat, Tumulka, *Multi-time Schrödinger equations cannot contain interaction potentials*, J. Math. Phys. 55 (2014) 032302, arXiv:1308.1065
PRIOR. The consistency condition on the $N$ Hamiltonians rules out interaction
by multiplication operators. Read against Bölüm 11: if our three times were
ever given independent evolution equations, interaction could not be put in as
a potential, which is a structural constraint on any dynamics we write in
region II.

### [77] Nickel, Deckert, *Consistency of multi-time Dirac equations with general interaction potentials*, J. Math. Phys. 57 (2016) 072301, arXiv:1603.02538
CHALLENGE to [76] and therefore useful to us. Shows admissible potentials do
exist once spin coupling is allowed, gives an explicit example, but then shows
that **none of them is Poincaré invariant**. The escape route from the no-go
exists and costs the symmetry we care most about.

### [78] Lienert, Petrat, Tumulka, *Multi-time wave functions*, J. Phys. Conf. Ser. 880 (2017) 012006, arXiv:1702.05282
CONTEXT. The review of the whole multi-time programme, including the
consistency condition and how probability conservation is arranged when it can
be. The right single citation for Bölüm 7.3.

### [79] Hirsch, Payne, Zhang, *The spacetime positive mass theorem with multiple time dimensions*, arXiv:2602.20081
SUPPORT, and the first result we have for Bölüm 9.2. The spacetime positive
mass theorem survives with $m$ time dimensions: the energy is bounded below by
the trace norm of the linear momenta $J^1,\dots,J^m$, with rigidity in the
equality case. So a multi-time region is not automatically energetically
pathological, and this is the shape our Bölüm 4 energy-momentum swap should be
tested against.

### Deriving the transition rather than assuming it

### [80] Bojowald, Mielczarek, *Some implications of signature change in cosmological models of loop quantum gravity*, JCAP 08 (2015) 052, arXiv:1503.09154
SUPPORT and CHALLENGE at once, for Bölüm 6 and 15.6. The effective equations
that produce signature change are locally regular, so the derivation is
reliable; but the resulting problem is of **mixed type**, and the article works
out what that means by importing the Tricomi problem. This is the precise
mathematical name for our region I / region II split, and it comes with global
obstructions the paper spells out.

### [81] Bojowald, Brahma, *Signature change in loop quantum gravity: general midisuperspace models and dilaton gravity*, Phys. Rev. D 95 (2017) 124014, arXiv:1610.08840
PRIOR for Bölüm 15.6. Signature change is derived, not postulated, for **all**
midisuperspace models without local degrees of freedom, as a consequence of
deformed covariance with holonomy modifications. The strongest existing answer
to our open question of whether a transition can come out of a theory rather
than be put in by hand.

### [82] Magueijo, Rodriguez-Vazquez, Westman, Zlosnik, *Cosmological signature change in Cartan gravity with dynamical symmetry breaking*, Phys. Rev. D 89 (2014) 063542, arXiv:1311.4481
SUPPORT for Bölüm 15.6 by a second and independent route. In a first-order
$SO(1,4)$ gauge theory with a symmetry-breaking Higgs field and no presupposed
metric, the signature is whatever the Higgs norm makes it, so a change of
signature is a change of phase of the symmetry breaking. This is the closest
thing in the literature to a mechanism for our transition, and it is
gauge-theoretic rather than kinematic.

### [83] Pedram, Jalalzadeh, *Signature change from Schutz's canonical quantum cosmology and its classical analogue*, Phys. Rev. D 77 (2008) 123529, arXiv:0805.4099
SUPPORT. Wave packets built from the Schrödinger-Wheeler-DeWitt equation with
a perfect fluid exhibit a transition from a finite Euclidean to a Lorentzian
domain, with a classical analogue in which the effect is reproduced by a
repulsive fluid. Relevant to Bölüm 15: a signature change can be read off a
quantum cosmological wave packet, and it has an effective-source description on
the other side.

### Analogue systems, the one route to something measurable

### [84] Figueiredo, Gomes, Fumeron, Berche, Moraes, *Modeling Kleinian cosmology with electronic metamaterials*, Phys. Rev. D 94 (2016) 044039, arXiv:1608.03812
SUPPORT, and the most important paper here for the article's missing testable
prediction. Klein-Gordon particles crossing a **discontinuous** change from
$(-,+,+,+)$ to Kleinian $(-,+,+,-)$, realised as electrons at a junction
between an anisotropic semiconductor and an electronic metamaterial. The result
at the planar boundary is a **mirror-like behaviour for the particle flux**,
which is Bölüm 9.1's total reflection obtained independently and in a system
that can be built. The paper then does what we do not: it examines a slab of
finite thickness and finds **tunnelling** through it. That is the experimental
handle, and it says our threshold is perfectly reflecting only if it is
infinitely thick.

### [85] Fumeron, Berche, Santos, Pereira, Moraes, *Optics near a hyperbolic defect*, Phys. Rev. A 92 (2015) 063806, arXiv:1510.06868
SUPPORT. In a hyperbolic metamaterial the effective metric has Kleinian
signature, two timelike coordinates, and light near a disclination follows
Poinsot spirals and is trapped for any impact parameter. A second, optical
realisation of a (2,2) region with a geodesic structure one can measure.
Bears on Bölüm 13.5's question of whether a (2,2) region is physically
defensible: in the analogue sense it demonstrably is.

### The Dragan branch, one recent item

### [86] Lake, *Towards a group structure for superluminal velocity boosts*, arXiv:2409.01773
PRIOR and directly aimed at Bölüm 3, by the author of [4]. Constructs superluminal boosts as an
explicit map between the two-sheeted hyperboloids inside the light cone and the
one-sheeted hyperboloids outside it, and asks what group structure the
resulting operators carry, with the implications for the Dragan-Ekert quantum
principle of relativity spelled out. Our Bölüm 3 closure failure should be
compared against this construction directly; it is the same question posed
geometrically rather than matricially.

### What this group changes

10. Bölüm 16.2 is no longer an open question with no literature. [58], [59],
    [60] and [62] all compute particle production or vacuum pressure at a
    signature change, and none of them gets zero.
11. Bölüm 9.1 must be rewritten as a choice between documented alternatives,
    citing [63] for the two philosophies, [64]/[65] for the dispute over
    whether the distributional equations exist at all, and [66] for the weak
    condition's own solution space.
12. Bölüm 7.3's objection is now sharpened by [75], which separates our case,
    several timelike dimensions, from the well-behaved multi-time case, and
    calls ours presumably unphysical. [73] and [74] argue the opposite. That
    disagreement should be presented, not resolved by assertion.
13. Bölüm 9.1's total reflection has independent confirmation in [84], and
    with it a finite-thickness correction, tunnelling, that we have not
    considered.
14. Bölüm 15.6 has three separate derivations of signature change from a
    theory now, [81], [82] and [80]. The article can no longer say the
    transition has never been derived.
