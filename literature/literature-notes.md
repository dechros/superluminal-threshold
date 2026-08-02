# Literature notes

Working notes taken while reading `literature/` (191 papers). One entry per
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

---

## Group 9: the crossable threshold

This group was collected after the article was retargeted. The thesis under test
is no longer that the threshold reflects, but that it transmits: the weak
junction condition is adopted, crossing is controlled by finite thickness and by
the mode content of the incident field, and the region beyond carries no arrow
of time. Entries that damage that thesis are marked and put first within each
sub-block, because they are the ones the article has to answer.

### The weak junction condition, which is now the load-bearing choice

### [87] Dray, Manogue, Tucker, *The scalar field equation in the presence of signature change*, Phys. Rev. D 48 (1993) 2587, arXiv:gr-qc/9303002
PRIOR, and the paper the new Bölüm 9.1 is a special case of. Demanding a
conserved momentum in the homogeneous case selects one propagation rule across
the surface, and that rule is shown to give the unique solutions of the
distributional wave equation, reachable also from a Lagrangian. Two things
matter for us. First, the selection principle is the same one our Bölüm 9.1
uses, flux conservation, but it selects **transmission**, not total reflection.
Second, what comes out the far side is a **mix of positive and negative
frequencies** whose ratio depends only on the total conformal size of the
spacelike region and not on the profile of the metric. If the article is going
to argue the threshold is crossable, this is the result to build 9.1 on, and the
frequency mixing is a prediction it inherits whether it wants it or not.

### [88] Dray, Hellaby, *The patchwork divergence theorem*, J. Math. Phys. 35 (1994) 5922, arXiv:gr-qc/9404002
PRIOR for the machinery of Bölüm 9.1. The divergence theorem for piecewise
smooth fields, derived so that it holds independently of the signature on either
side and therefore across a change of signature. Our flux argument at $V = c$ is
an application of this theorem and should cite it rather than rederive it. The
important structural point is that the patched theorem carries a boundary term.
A flux balance written without that term is not the conservation law.

### [89] Hellaby, Dray, *Failure of standard conservation laws at a classical change of signature*, Phys. Rev. D 49 (1994) 5096, arXiv:gr-qc/9404001
CHALLENGE, and the most serious single objection to the article in either its
old or its new form. The Israel identities that normally force conservation of
matter across a junction do not hold when the signature changes; the modified
identities carry a finite source on the surface itself, physical vector fields
jump in at least one component, and current is not conserved either. The
authors' own conclusion is that recovering standard conservation laws requires
restrictions no realistic model satisfies. Consequence for Bölüm 9.1: the
premise "the flux must balance, therefore the amplitude is fixed" is not
available. Under the weak condition the surface is allowed to be a source, so
flux conservation determines neither total reflection nor a specific
transmission coefficient. The article's new thesis is not defeated by this, but
its derivation is, and Bölüm 9.1 must be rewritten to say what fixes the
amplitude if conservation does not.

### [90] Hayward, *Comment on 'Failure of standard conservation laws at a classical change of signature'*, Phys. Rev. D 52 (1995) 7331, arXiv:gr-qc/9606045
CHALLENGE to the new thesis, from the opposite direction to [89]. Hayward's
reply is that nothing fails: if the field equations are satisfied then the
junction conditions and the conservation equations both hold, and the reported
failure is an artefact of not making sense of equations that are singular at the
surface. Read with [89] and his own gr-qc/9303034, this is the strong-condition
camp asserting that the weak condition is not a legitimate alternative but a
mistake. Bölüm 9.1 cannot adopt the weak condition by preference; it has to
engage this specific claim, that the strong condition is a theorem once the
field equations are imposed rather than a choice.

### [91] Dray, Hellaby, *Comment on 'Smooth and discontinuous signature type change in general relativity'*, Gen. Rel. Grav. 28 (1996) 1401, arXiv:gr-qc/9610062
SUPPORT, and the best single citation for the flip in Bölüm 9.1. Against
Kossowski and Kriele's boundary conditions, the authors show the derivation rests
on a postulated form of the field equations, that there is **no canonical form of
the Einstein equations at a change of signature**, and that a weaker formulation
exists in which the field equations still hold, the smoothness assumptions are
milder, and the energy-momentum tensor stays bounded **without** the extrinsic
curvature having to vanish. Vanishing extrinsic curvature is exactly the strong
condition the old Bölüm 9.1 imposed. This paper is the licence for dropping it,
and it should be cited at the point of the choice rather than in passing.

### [92] Kriele, Martin, *Black holes, cosmological singularities and change of signature*, Class. Quantum Grav. 12 (1995) 503, arXiv:gr-qc/9411063
CHALLENGE, and a second priority finding. Signature change cannot be used to
remove a singularity **unless the Einstein equation is abandoned at the surface
of change**. The paper also shows to what extent smooth and discontinuous
signature-changing solutions are equivalent, which speaks directly to Bölüm 9.4:
if the two are equivalent in the relevant sense, then a finite-thickness slab
does not buy the article as much freedom as it hopes. The article's new backbone
wants a real tear, a crossable one, and the field equations to survive it. This
paper says pick two.

### [93] Kamleh, *Signature changing space-times and the new generalised functions*, arXiv:gr-qc/0004057
CHALLENGE by removing an escape route from Bölüm 9.1. The Colombeau algebra,
which is the standard tool for giving distributional sense to products of
singular objects, is analysed for both continuous and discontinuous signature
change and found **insufficient to exclude either, and unable to settle the
dispute over the junction conditions**. So the article cannot justify the weak
condition by saying the distributional formulation forces it. The choice stays a
choice, and has to be defended physically.

### [94] Martin, *Cosmological perturbations and classical change of signature*, Phys. Rev. D 52 (1995) 6708, arXiv:gr-qc/9509053
CHALLENGE for Bölüm 9.4. For FLRW with a constant scalar field, **no regular
perturbation solution exists that satisfies the junction conditions at the
surface of change**. This is the closest thing in the literature to a
non-existence result for the configuration the article now wants, and it is a
perturbative statement, so it is about exactly the mode-by-mode analysis Bölüm
9.4 will perform. The article should either show its case falls outside the
hypotheses or accept a restriction on which incident modes can be posed at all.

### [95] Dray, *Piecewise conserved quantities*, in Gravity and the Quantum, Springer 2017, arXiv:1701.02863
CONTEXT, the settled modern statement of [88] and [89]. Conservation laws on
glued spacetimes acquire a boundary term, worked through for junctions of
Schwarzschild regions of different mass and for junctions between regions of
different signature. The right single reference when Bölüm 9.1 states what its
conservation law actually is.

### Crossing: geodesics, slabs and mode selectivity

### [96] Pavlova, Remizov, *Singularities of geodesic flows in smooth signature changing metrics on 2-surfaces*, arXiv:1801.09815
SUPPORT with a hard constraint attached, and the most directly useful result in
this group for the new Bölüm 9.4 and for the question of whether a massive body
can cross. In two dimensions, at a generic point of the degeneracy curve,
geodesics **can** pass through, so the surface is not an absolute barrier for
worldlines; but they cannot pass in arbitrary tangential directions, only in a
finite set of **admissible directions, numbering one, two or three**. That is
the mode-content dependence of Bölüm 9.4 appearing at the classical level and in
the sharpest possible form: crossing is not forbidden, it is direction-selected.
The article should take this as its model statement and be explicit that the
theorem is two-dimensional, so the count in four dimensions is not established.

### [97] Smolyaninov, Narimanov, *Metric signature transitions in optical metamaterials*, Phys. Rev. Lett. 105 (2010) 067402, arXiv:1007.1130
SUPPORT for Bölüm 16.2 and for the article's need for something measurable.
Extraordinary waves in an indefinite metamaterial see an effective $(-,-,+,+)$
metric, and during a signature-change transition in that medium a Minkowski
spacetime is created **together with a large number of particles populating
it**. Peer reviewed in PRL and realisable on a bench. Bölüm 16.2 can no longer
be phrased as an open question: particle production at a signature change is a
measured-in-analogue effect, not a conjecture. The companion arXiv:0908.2407
states the same effect and identifies the indefinite medium explicitly with two
times physics in $2+2$; arXiv:1301.6060 makes the signature depend on a lattice
periodicity, that is, gives a knob.

### [98] Nissinen, Volovik, *Effective Minkowski to Euclidean signature change of the magnon BEC pseudo-Goldstone mode in polar 3He*, JETP Lett. 106 (2017) 234, arXiv:1707.00905
SUPPORT, and a second, independent laboratory system. In the coherently
precessing spin-superfluid state of polar 3He in aerogel, the phonon of the
magnon condensate sees an effective metric whose signature changes from
Minkowski to Euclidean at a critical tilting angle of the applied field. The
signature change is an **instability threshold controlled by an external
parameter**, which is the closest existing analogue of our $V = c$ surface being
approached rather than postulated. Bears on Bölüm 16.4: this is a preparable
apparatus, which is what the article said its distinguishing prediction needs.

### [99] Zhang, *Alternative route towards the change of metric signature*, Phys. Rev. D 100 (2019) 064043, arXiv:1909.10669
PRIOR and structurally the closest paper in the corpus to our construction. The
traditional route flips the sign of the lapse, so the far side is Euclidean.
Zhang instead flips the sign of the **spatial** metric eigenvalues, so that the
far side is **purely timelike**, and then derives the junction conditions for
that case. That is our $D$ matrix's effect stated in the language of the
signature-change literature: our region II is three times and one space, and it
is reached by turning spatial directions timelike, not by turning time
spacelike. Bölüm 9.1 and Bölüm 15.6 should both cite this, and the article
should state plainly which of Zhang's junction conditions it is adopting.

### Beyond the threshold: no arrow, and what motion means there

### [100] Lemos, Muller, Reboucas, *Probing time orientability of spacetime*, Eur. Phys. J. C 83 (2023) 461, arXiv:2211.00816
SUPPORT for Bölüm 7.4, and it converts a stipulation into an observable. Time
non-orientability of Minkowski spacetime is shown to be **locally detectable**
through the stochastic motion of a charged particle in the electromagnetic
vacuum, via a statistical orientability indicator that shows an inversion
pattern absent in the orientable case. The article's claim that the far side
carries no future/past split is exactly a claim of time non-orientability, and
this paper says such a claim has a local signature in vacuum fluctuations rather
than being a global convention. This is the second concrete route, after [98],
to the distinguishing measurement Bölüm 16.4 asks for.

### [101] Hanounah, *On completeness of certain locally symmetric pseudo-Riemannian manifolds of signature (2,2)*, arXiv:2506.13924
SUPPORT for Bölüm 13.5. Geodesic completeness is proved for a natural class of
compact locally symmetric $(2,2)$ spaces, the split-signature generalisation of
Cahen-Wallach spaces. The relevance is narrow but real: the article's new
backbone requires free motion inside a region with more than one timelike
direction, and the objection to be answered is that such motion runs off the
manifold or is otherwise ill defined. In this class it does not. It is a
mathematical, not physical, defence of the $(2,2)$ interlude.

### [102] Bais, May Custodio, Torres, *Existence results of Spin(2,n-1) pseudo-Riemannian cobordisms*, arXiv:2306.02749
SUPPORT for Bölüm 13.5, and it makes the tear a computable question. Necessary
and sufficient conditions are given for a spin cobordism carrying a nondegenerate
metric of signature $(2, n-1)$ whose boundary restriction is a nonsingular
time-orientable Lorentzian metric, and the cobordism groups are computed. Bölüm
13.5 asserts a two-time interlude between the two signatures; this is the
framework in which "does such an interlude exist for these boundary data" has an
answer rather than an argument. The article should at least state which
cobordism class its configuration falls into.

### [103] Alves, Barreto, Moraes, *Implications of Kleinian relativity*, Phys. Rev. D 103 (2021) 044023, arXiv:2012.03921
PRIOR for Bölüm 4, 5.1 and 8. A covariant particle mechanics in Kleinian
spacetime with the relativistic momentum and energy written out, the effects
being **time contraction and length dilatation**, that is, our Bölüm 7.2 role
reversal derived independently; plus a constraint on the dispersion relation for
Weyl fermions. The article's energy-momentum swap and its far-side dispersion
relation are not new with us and should be presented as agreeing with this.

### [104] Easson, Pezzelle, *Kleinian black holes*, arXiv:2312.00879
PRIOR for Bölüm 10. A Kleinian extension of Birkhoff's theorem: the vacuum
solution with $SO(2,1)$ spherical symmetry in split signature is unique, locally
isomorphic to split-signature Schwarzschild-(A)dS or Nariai, with Kerr and
Taub-NUT forms given too. Our Bölüm 10 closed-form spherically symmetric solution
sits in this classification and the article should say where, since uniqueness on
the far side is claimed there and proved here.

### [105] Santos, Brito, Filgueiras, *Diamonds in Klein geometry*, Eur. Phys. J. Plus 138 (2023) 1079, arXiv:2312.06611
SUPPORT, and a partial answer to Bölüm 14.3 and 16.1. Using the path integral,
an Unruh-analogue temperature is computed in Kleinian geometry once the action
is restricted to a suitable subspace, together with a diamond temperature for a
static observer of finite lifetime. So quantum field theory in split signature is
not empty and does yield thermal quantities, which is the constructive side of
Bölüm 16.2's "the theory is not empty". Note the qualification: it works after
restriction to a subspace, which is the price the article's Bölüm 14 says it
expects to pay.

### [106] Hull, *Duality and the signature of space-time*, JHEP 9811 (1998) 017, arXiv:hep-th/9807127
CONTEXT, but the strongest one available for Bölüm 13.5's open question of
whether an exotic signature is physically defensible. M-theory admits $(9,2)$ and
$(6,5)$ versions and type II strings in $(10,0)$, $(8,2)$, $(7,3)$, $(6,4)$ and
$(5,5)$, all linked by dualities that **change the number of time dimensions**,
so each is a limit of one underlying theory. The article's multi-time region is
therefore not an unprecedented object, and, more usefully, the precedent is a
case where changing the number of times is a duality rather than a catastrophe.

### The multi-time objections, which the retarget does not remove

### [107] Dvali, Gabadadze, Senjanovic, *Constraints on extra time dimensions*, arXiv:hep-ph/9910207
CHALLENGE for Bölüm 7.3 and 9.2. With gravity propagating in the extra times,
the Newtonian potential is screened by tachyonic Kaluza-Klein gravitons and the
gravitational self-energy acquires an **imaginary part**, read either as an
amplitude to disappear into nothing, giving causality and probability violation
in low-energy processes, or as an artefact of decay into unphysical negative
energy tachyons. Bölüm 9.2 lets gravity see the far side; this is what that
costs, and it is a quantitative phenomenological bound rather than a philosophical
objection.

### [108] Foster, Muller, *Physics with two time dimensions*, arXiv:1001.2485
SUPPORT for Bölüm 7.3, and the paper that gives the article its escape clause.
The standard arguments that rule out two times **do not apply if the dynamics of
the additional time is thermal or chaotic and supports no long-lived timelike
excitations**. That is a testable condition on our region II, and the article's
claim of no arrow of time on the far side is close to, but not the same as, the
condition stated here. Bölüm 7.3 should adopt this as the form its answer has to
take rather than asserting collapse to a single time.

### [109] Kenig, Ponce, Rolvung, Vega, *The general quasilinear ultrahyperbolic Schrodinger equation*, arXiv:math/0503206
SUPPORT for Bölüm 6.1 and 7.3, narrow but real. A local existence theory is
established for the initial value problem of the general quasilinear
ultrahyperbolic Schrodinger equation. Our Bölüm 6.1 derives loss of determinism
from the equation type being ultrahyperbolic; this is a theorem that the
ultrahyperbolic initial value problem is locally well posed in a genuine class.
The article's argument must therefore be about the global problem or about the
choice of initial surface, and it should say which.

### Deriving the transition instead of postulating it

### [110] Bojowald, Duque, *Emergent modified gravity*, Class. Quantum Grav. 41 (2024) 095008, arXiv:2404.06375
PRIOR for Bölüm 15.6, and the foundation of the paper already in the corpus at
arXiv:2312.09217. A complete canonical formulation of general covariance allows
the fundamental gravitational fields to differ from an **emergent** spacetime
metric, evading the usual uniqueness theorems. This is the structure inside which
signature change comes out of the theory rather than being imposed on it, and it
is the mechanism the article's Bölüm 15.6 open question is asking for. Citing
2312.09217 without this is citing a consequence without its premise.

### [111] Tartaglia, *On the emergence of the Lorentz signature in an expanding universe*, arXiv:1207.0626
SUPPORT for Bölüm 15.6 by an elementary route. Adding the strain of the manifold
as a field in the Lagrangian produces a boundary that divides the manifold into a
Euclidean and a Lorentzian region, and the boundary survives the presence of
homogeneous matter. The point for us is the cheapness of the mechanism: one extra
term in the action, no quantum gravity. arXiv:1707.07235 gets a signature change
even more cheaply, as an automatic consequence of Ricci flow through a critical
point. Bölüm 15.6 should note that derivations of signature change now exist at
several very different levels of sophistication, which weakens any claim that the
transition is exotic.

### Casimir and vacuum energy at the surface

### [112] Setare, *Casimir stress on parallel plates in de Sitter space with signature change*, Int. J. Mod. Phys. A 22 (2007) 1771, arXiv:gr-qc/0611151
SUPPORT for Bölüm 16.3, together with arXiv:hep-th/0511077 (spherical shell) and
arXiv:gr-qc/0703153 (concentric spheres, where the Euclidean region is **between**
the shells and the Lorentzian region outside). All three compute a Casimir stress
in a configuration where the signature differs on the two sides of the boundary,
and all three find a **nonvanishing contribution attributable to the signature
change itself**: an attraction of the plates in the first, a transient rapid
expansion in the second, an extra constant pressure in the third. Bölüm 16.3 asks
what the Casimir signature of a threshold surface is; the answer in the
literature is that there is one, it is finite, and its sign depends on the
geometry. The concentric-sphere configuration is the one closest to our Bölüm
9.4 slab and is the natural template for computing the slab's vacuum energy.

### What this group changes

15. Bölüm 9.1's derivation cannot survive the flip as it stands. [89] shows the
    Israel identities fail at a signature change and the surface may carry a
    source, so flux conservation no longer determines an amplitude, in either
    direction. The section has to name a different principle. [87] shows what
    that principle looked like when it worked: conserved momentum plus the
    distributional wave equation, selecting transmission with a definite
    positive/negative frequency mix.
16. The licence to drop the strong condition exists and is precise. [91] shows
    there is no canonical form of the field equations at a signature change and
    that a formulation with bounded energy-momentum and nonvanishing extrinsic
    curvature is available. That, not preference, is the citation for the flip.
17. Two papers stand directly against the new thesis and must be answered, not
    cited in passing. [90] holds that the junction conditions and conservation
    follow from the field equations, so the weak condition is an error rather
    than an option. [92] holds that the field equations must be abandoned at the
    surface for signature change to do any work, and additionally that smooth and
    discontinuous changes are equivalent to an extent that limits what Bölüm 9.4
    gains from finite thickness.
18. The distributional escape route is closed. [93] shows Colombeau theory
    settles neither the continuity of the metric nor the junction conditions, so
    the article cannot argue the weak condition is forced by a rigorous
    formalism.
19. Bölüm 9.4's mode dependence has a classical precedent with a number attached.
    [96] proves that geodesics cross a degeneracy curve only along one, two or
    three admissible directions. Crossing is direction-selected, not free, and
    that is the correct shape for the new central claim. The theorem is
    two-dimensional; the four-dimensional count is not known.
20. [94] is a non-existence result in the perturbative regime Bölüm 9.4 will work
    in, and the article has to show it falls outside its hypotheses.
21. Bölüm 16.2 is settled in the analogue setting. [97] has particle creation at
    a metamaterial signature transition in PRL, and [98] has a signature change
    driven across a threshold by an external field in polar 3He. Together with
    [100], which makes time non-orientability locally detectable in the
    electromagnetic vacuum, Bölüm 16.4 now has three candidate preparable
    apparatuses instead of none.
22. Bölüm 9.1 and 15.6 both need [99]. It changes the signature by flipping the
    **spatial** eigenvalues, so its far side is purely timelike as ours is, and
    it works out the junction conditions for that specific case rather than for
    the Euclidean case the rest of the literature treats.
23. The Kleinian far side is better furnished than the article assumes. [104]
    gives a uniqueness theorem our Bölüm 10 solution must be placed inside, [103]
    derives our Bölüm 7.2 role reversal independently, [105] shows a thermal
    quantum field theory can be built there after restriction, and [101] and
    [102] answer, in a mathematical sense, whether free motion and the tear
    itself are well defined.
24. The multi-time objections are unaffected by the retarget and one of them is
    quantitative. [107] gives an imaginary gravitational self-energy and a
    low-energy probability violation once gravity sees the extra times, which is
    the price of Bölüm 9.2. [108] states the only known condition under which the
    no-go arguments lapse, and Bölüm 7.3 should be rewritten to meet that
    condition rather than to assert collapse to one time. [109] shows the
    ultrahyperbolic initial value problem is locally well posed, so Bölüm 6.1's
    loss of determinism must be a global or initial-surface claim.
25. Bölüm 16.3 has a template. The three Setare and Darabi calculations in [112]
    all obtain a nonzero Casimir contribution from the signature change itself,
    and the concentric-sphere geometry is the closest existing analogue of the
    finite-thickness slab that Bölüm 9.4 is being promoted to a main chapter.

---

## Group 10: the round trip

Collected after the aim was sharpened to a round trip: cross the threshold, act on
the far side, come back, and place the return on our own time axis. The two
deliverables that organise this group are (a) where on our time axis the particle
lands when it returns, which has to come from the matching at the two crossings
because no duration can be read on a side with no time orientation, and (b) the
dictionary that turns a far-side orientation into a statement in our terms. The
weak junction condition is now load-bearing, so entries that damage it come
first. Two further requirements were added while this group was being collected:
predictability on the far side must be recovered rather than conceded, and the
signalling chapter must not rest on photons alone.

### The weak junction condition: the case against it, stated by its principal opponent

### [113] Hayward, *Signature change at material layers and step potentials*, arXiv:gr-qc/9509052
CHALLENGE, and the single most damaging paper in this group for the new thesis.
This is the paper Bölüm 9.1 has to answer before it adopts the weak condition,
and it has not been cited anywhere in the corpus so far. For a contravariant
4-metric changing from Lorentzian to Riemannian across a spacelike hypersurface,
the mixed Einstein tensor is manifestly non-singular; in Gaussian normal
coordinates the metric contains a step function and the Einstein tensor contains
a Dirac delta supported at the junction, whose coefficient is a linear
combination of the second fundamental form. Hayward then draws the consequence
in the sharpest possible terms: **unless the junction has vanishing extrinsic
curvature, the metric describes a layer of matter at the junction** (with
stresses but no energy or momentum), and in particular **such metrics do not
satisfy the vacuum Einstein equations, nor the Einstein-Klein-Gordon
equations**. The scalar counterpart is the same: the d'Alembertian of a
Klein-Gordon field carries a Dirac delta whose coefficient is the momentum of
the field, so **if the field momentum does not vanish at the junction the field
does not satisfy the massless Klein-Gordon equation**; there is a source with a
step potential sitting there.

Translated into our terms, this is not a claim that the crossing is impossible.
It is a claim about what the crossing costs. The weak condition is exactly the
choice to let the extrinsic curvature not vanish and to let the field momentum
at the surface not vanish. Hayward's calculation says the price of that choice
is a matter layer and a source layer at $V = c$ which have to be supplied by
something, and that away from them the field equations we started from are not
the equations being solved. The article can accept the price and say what
supplies the layer, or it can go back to the strong condition. What it cannot do
is present the weak condition as a free alternative.

### [114] Hayward, *Comment on 'Comparison of approaches to classical signature change'*, arXiv:gr-qc/9606044
CHALLENGE, the closing move of the exchange already recorded as [63], [64],
[65] and [90], and it should be read together with [113]. Hayward restates that
the Hellaby-Dray solutions do not satisfy the Einstein-Klein-Gordon equations at
the change, that substituting them in unit normal coordinates yields delta terms
describing source layers, and that this calculation involves no imaginary time,
no modified field equations, and nothing but classical objects. He further
charges that the attempt to remove the delta terms is mathematically invalid,
involving division by zero and products of distributions.

The bearing on us is procedural and it matters. Our licence for the weak
condition is [91], a Dray and Hellaby paper. This is the specific technical
accusation against that line of work, and it is not answered anywhere in the
corpus. Bölüm 9.1 should state which side of this exchange it is standing on and
why, rather than citing one side.

### [115] Racskó, *Variational formalism for generic shells in general relativity*, arXiv:2203.03049
SUPPORT, and the machinery Bölüm 9.1 currently lacks. A variational principle
for thin shells of **completely unconstrained signature**, unifying the timelike
and null treatments. The shell equation appears as the natural boundary
condition of a broken extremal problem along a hypersurface where the metric is
allowed to be non-differentiable, and since the second-order Einstein-Hilbert
action makes that boundary value problem ill defined, several regularisation
schemes are introduced and proved equivalent. The results reproduce
Barrabes-Israel for fixed causal type and Mars-Senovilla for generic shells.

This is the right frame for our threshold. A surface where the causal character
is not fixed is precisely what $V = c$ is, and here it is treated by a
variational principle rather than by picking a distributional convention. The
equivalence of the regularisations is the answer to [93], which showed that
Colombeau theory settles nothing: the ambiguity is real, but here it is shown
not to affect the shell equation.

### [116] Senovilla, *Junction conditions for general gravitational theories*, arXiv:2603.04645
SUPPORT and CHALLENGE at once, and it supplies the one theory-independent
constraint in this whole area. Working distributionally for actions built from
arbitrary functions of curvature scalar invariants, shells arise if the $m$th
covariant derivative of the Riemann tensor is continuous at the matching
hypersurface, and a proper junction without shells needs the $(m+1)$th
derivative continuous as well. Two results bear directly on us.

First, and this is the part Bölüm 9.2 and the signalling chapter both need:
**General Relativity and $F(R)$ are extraordinary in admitting shells of
curvature, that is, impulsive gravitational waves**, because every other theory
in the class requires the jump of the second fundamental form to vanish across
the matching hypersurface. So the freedom the weak condition asks for, a
non-vanishing jump in the extrinsic curvature, exists in general relativity and
essentially nowhere else, and what it buys is exactly an impulsive gravitational
wave at the surface. That is a carrier: the price [113] identifies as a matter
layer is, on the gravitational side, radiation emitted at the crossing.

Second, the universal statement: **continuity of the normal components of the
energy-momentum tensor across the matching hypersurface is proved to be a
property independent of the field equations**. This is a necessary condition our
crossing has to satisfy no matter which version of the field equations Bölüm 9.2
adopts, and it is the only constraint in the corpus with that status.

### Two crossings, and where the return lands

### [117] Dray, Hellaby, *Mirror symmetry and double signature change*, arXiv:2606.21805
PRIOR, and the closest thing in the literature to the geometry the round trip
needs. Already in the corpus, never entered. The black mirror spacetime connects
the two exterior regions of extended Schwarzschild directly, with no interior
region between them, and the authors re-examine it **as a model of double
signature change**, using signature-change techniques. They ask whether there is
a surface layer at the horizon, that is a distributional curvature singularity
corresponding to an impulsive gravitational wave, and confirm that there is
none. They then discuss the global structure and **examine what happens to
worldlines and curves passing through**.

For us this is the template for the whole construction: two changes rather than
one, the question of the surface layer posed at both, and the fate of worldlines
through the pair treated explicitly. It should be read alongside [24], where two
Lorentzian universes are joined through a Euclidean bounce, which is the same
double-crossing topology reached from the cosmological side. Note also the
tension with [113] and [116]: here the double crossing is found to carry **no**
surface layer, which is the outcome the article wants and which [113] says is
available only when the extrinsic curvature vanishes. Whether the black mirror
achieves that by satisfying the strong condition after all is the question to
put to this paper.

### [118] Hayward, *Complex lapse, complex action and path integrals*, arXiv:gr-qc/9511007
PRIOR, and the best existing machinery for the placement deliverable. Instead of
imaginary time, Hayward allows the **lapse function to be complex**. In the 3+1
action for gravity minimally coupled to a Klein-Gordon field this gives a complex
action generating both the Lorentzian theory and its Riemannian analogue, and in
particular **allows a change of signature between the two**; the action and the
variational equations are manifestly well defined in the Hamiltonian
representation, at the price of complex momenta, and the complex action
interpolates between the Lorentzian and Riemannian actions as they appear in the
respective path integrals. Applied to the observed quantum tunnelling of
particles, the theory determines that the argument of the lapse for the universe
now is extremely small but negative.

Why this is the right shape for deliverable (a). Our problem is that no elapsed
duration can be read on the far side, so the return event cannot be placed by
integrating a proper time there. The complex-lapse formulation does not ask for
one: the phase of the lapse is what carries the interpolation, and the placement
of an event on the real time axis follows from the phase acquired between the two
crossings rather than from a duration accumulated between them. It also answers
the objection that a signature change forces imaginary time and is therefore not
classical, which is the objection [63] records against Hayward's own earlier
route. The article should adopt the complex lapse as the variable in which the
two matching conditions are written and read the return placement off its
argument.

### [119] Hayward, *On cosmological isotropy, quantum cosmology and the Weyl curvature hypothesis*, arXiv:gr-qc/9212006
CONTEXT with one framing sentence that the article should take over: signature
change **is a classical model of quantum tunnelling** in quantum cosmology. The
paper's own content, that the signature-change hypothesis implies an initial
inflationary epoch, the magnetic half of the Weyl curvature hypothesis, and a
close analogue of the conformal singularity hypothesis, and that adding the
electric half leaves only homogeneous and isotropic perfect-fluid cosmologies
with the Vilenkin tunnelling solution unique in the cosmological-constant case,
is cosmological and peripheral to us. The framing is not. If the far-side
interlude is the classical model of a tunnelling event, then the placement
question is the tunnelling-time question, and the article inherits both the
machinery and the known difficulties of that subject.

### The finite layer with two interfaces, realised and measured

These three are not signature changes and the article must not present them as
such. What they are is the only place where a wave crossing **two** interfaces
bounding a finite layer, entering and leaving, has been solved with explicit
coefficients and then built. The layer there is a slab in time rather than in
space, which is the dual of our configuration, and the formal structure carries
over.

### [120] Ramaccia, Toscano, Bilotti, *Propagation through metamaterial temporal slabs: transmission, reflection and special cases*, arXiv:1911.04280
SUPPORT, methodological, and the closest worked analogue of Bölüm 9.4. A uniform
medium present in all space for a **limited time**, that is a slab bounded by two
temporal interfaces. The scattering coefficients are derived as functions of the
refractive indices and of the application time, and the response is shown to be
controlled by the application time, **which acts as the electrical thickness of a
conventional spatial slab acts**. That last equivalence is the point for us:
Bölüm 9.4 argues that a finite-thickness threshold transmits and that the
transmission depends on the thickness. Here the same dependence is derived in
closed form for the dual configuration, and thickness is duration. Note honestly
that only the abstract could be retrieved for this file.

### [121] Moussa, Xu, Yin, Galiffi, Radi, Alu, *Observation of temporal reflections and broadband frequency translations at photonic time interfaces*, arXiv:2208.07236
SUPPORT, and it turns [120] into an experiment. Photonic time reflection and the
associated broadband frequency translation are observed in a switched
transmission-line metamaterial. Decisive detail for us: **a pair of temporal
interfaces is combined to demonstrate time-reflection-induced interference,
realising the temporal counterpart of a Fabry-Perot cavity**. So the two-crossing
interference that our round trip predicts has been measured, in the dual
geometry, and what it produces is a cavity resonance condition relating the
phases picked up at the two interfaces. That resonance condition is the analogue
of the matching relation that deliverable (a) wants. Abstract only for this file.

### [122] Molero, Zapata-Cano, Alex-Amor, *Transfer ABCD matrix for time-varying media and time crystals*, arXiv:2503.15063
SUPPORT, and it gives the transfer matrix by name. ABCD parameters are defined
for temporal systems by rearranging $D$ and $B$ at the input and output of the
temporal boundary, the parameters of a temporal slab are derived, the associated
reflection and transmission coefficients are computed from them, and the
formalism is then used to obtain the dispersion diagram of a time crystal. The
value to us is that it makes **multilayer** temporal configurations a matter of
multiplying matrices. If Bölüm 9.4 is to be extended from one slab to a crossing,
an interlude and a return crossing, this is the algebra to copy, and the
composition rule is where the two matchings of deliverable (a) meet.

### Predictability on the far side: what the nonlocal constraint actually is

The requirement is now to recover prediction beyond the threshold rather than
concede its loss. The known route is [73] and [74], where the ultrahyperbolic
Cauchy problem is well posed on a mixed-signature hypersurface **under a nonlocal
constraint**. Those two papers state the constraint but do not say what it is
made of. The following do, and the answer is not comfortable.

### [123] Cobos, Guilfoyle, *An extension of Asgeirsson's mean value theorem for solutions of the ultrahyperbolic equation in dimension four*, arXiv:2011.11330
### [124] Cobos, Guilfoyle, *A conformal mean value theorem for solutions of the ultrahyperbolic equation*, arXiv:2210.08155
PRIOR, taken together, and they identify the nonlocality. Asgeirsson's 1937 theorem
says that a solution of the ultrahyperbolic equation in four variables has equal
integrals over certain **pairs of conjugate circles**. These two papers extend
that to all non-degenerate conjugate conics, conjugate hyperbolae, parabolae and
line-empty pairs, using the conformal invariance of the four-dimensional
ultrahyperbolic equation under the conformal group of the $2+2$ pseudo-Euclidean
space, and identify the admissible pairs with the two rulings of a doubly ruled
surface in Euclidean 3-space.

Two things follow for Bölüm 6.1 and 7.3, and the second is a priority finding.

First, the constructive one. The nonlocal constraint is not an arbitrary side
condition. It is a **mean value identity over conjugate conics**, it is
conformally covariant on a $2+2$ region, and after these two papers the full
family of curve pairs over which it holds is classified. If the article wants a
physical reading of the constraint, this is where it has to come from: the datum
is not a value at a point but an average over a conic, and the conjugate conic
carries the same average. Our region II is $(3,1)$ rather than $(2,2)$, so the
four-variable statement applies to sections of it, not to the whole; the article
must say which.

Second, the uncomfortable one, and it should be stated plainly rather than
buried. **The origin of the constraint is that solutions of the ultrahyperbolic
equation arise as the compatibility condition for a function on line space to be
the line integrals of a function on Euclidean 3-space.** In other words, the
data satisfying the constraint are exactly the data that are already the shadow
of an object living in one dimension fewer, with one time. Imposing the nonlocal
constraint to restore predictability therefore risks smuggling in the answer: it
restores prediction on the far side by restricting to the far-side
configurations that were secretly one-time configurations all along. The article
can still use it, but it cannot claim that predictability has been recovered for
a genuinely multi-time region until it shows its admissible data are not of this
restricted form.

### [125] Guilfoyle, *From CT scans to 4-manifold topology*, arXiv:2309.14826
SUPPORT, and the single reference to cite for the whole of the above. A survey of
the four-dimensional ultrahyperbolic equation from the geometric, analytic and
topological sides at once: the canonical **neutral metric on the space of
oriented geodesics** of a three-dimensional space form, the mean value theorem,
and, the part Bölüm 6.1 needs, **a new solution of the Cauchy problem over a
certain family of null hypersurfaces**. That is a positive well-posedness result
on a class of initial surfaces which is neither the spacelike nor the
mixed-signature class already discussed, and it strengthens the case that the
loss of determinism in Bölüm 6.1 is a statement about the choice of initial
surface rather than about the equation.

### [126] Garetto, Tramontana, *Schrödinger ultrahyperbolic equations with singular coefficients*, arXiv:2603.03170
SUPPORT, and it extends [109] in exactly the direction the threshold needs.
$H^\infty$ well-posedness in the very weak sense is proved for the Cauchy problem
of Schrödinger ultrahyperbolic equations whose coefficients are **less than
continuous**, under assumptions on the distributional structure of the
coefficients and decay of the lower-order terms, with consistency against the
classical smooth results. The relevance is direct: our configuration has a
discontinuous metric at the crossing surfaces, so any well-posedness theorem
requiring smooth coefficients does not apply to it. This one does not require
them. It is the correct technical setting for a Cauchy problem posed across the
threshold rather than inside one region.

### [127] Demchenko, *On a certain representation of a solution to the characteristic problem for the ultrahyperbolic equation*, arXiv:2604.22402
CONTEXT, narrow. A well-posed set-up is discussed for the ultrahyperbolic
characteristic problem with data on a characteristic hyperplane, and a
representation of the solution is obtained that is suitable for analysing its
asymptotics at infinity. Two uses: it is a second class of surface on which the
problem is well posed, adding to [125], and the asymptotic representation is what
one needs to say anything about a far-side solution at large parameter, which is
the only regime in which the return crossing can be discussed.

### No time orientation: what it costs, what it looks like from our side

### [128] Hadley, *The orientability of spacetime*, arXiv:gr-qc/0202031
CHALLENGE, and a priority finding for the observation deliverables. Hadley
considers an experimental test of time orientability and shows that **a failure
of time orientability of a spacetime region would be indistinguishable from a
particle-antiparticle annihilation event**.

This lands squarely on two of the eleven scope items, observing the particle
while it is there and determining after the return what was lost. Our far side is
posited to have no time orientation. This result says that from our side, the
signature of that region is an annihilation, not a departure and a return: what
an observer who never crossed records is a particle and an antiparticle
disappearing. Read constructively it is the dictionary entry the project wants,
because it gives a definite thing to look for. Read as an objection it is severe,
because it says the observation cannot distinguish the round trip from an
ordinary annihilation event, and the article must say what breaks that
degeneracy. Compare [28], where the loops at the change hypersurface may appear
to a nearby observer as **the creation of a particle-antiparticle pair at two
distinct points**: the two results are the same phenomenon seen at the two ends,
and taken together they suggest that the entire observable content of a round
trip is a pair creation at the entry and an annihilation at the exit.

### [129] Hadley, *Electrodynamics and time orientability*, arXiv:1703.05573
SUPPORT, and the most concrete dictionary in the corpus. On a spacetime that is
not time orientable, a $U(1)$ bundle is constructed to **measure the twisting of
the time axis**, and from that single assumption Maxwell's equations, the Lorentz
force law and the Einstein-Maxwell equations follow, along Kaluza-Klein lines but
with the constraints of a $U(1)$ connection rather than a fifth dimension. The
result that matters to us: **apparent net electric charge arises naturally,
because the direction of the electric field reverses along a time-reversing path,
so the boundary of a time-reversing region carries a net electric flux and looks
exactly like a region containing a charge**.

This is a dictionary entry of the kind deliverable (b) asks for, and it is
quantitative. A far-side orientation, which has no meaning in our terms, shows up
on our side as a flux through the threshold surface, that is as an apparent
charge. It also gives the signalling chapter a carrier that is not a photon in
the ordinary sense: the channel is the $U(1)$ connection measuring the twist, and
what crosses is a flux. The treatment is purely classical, which suits the two
layer model.

### [130] Hadley, *Spin half in classical general relativity*, arXiv:gr-qc/0004029
SUPPORT for the scope item on what matter means on the far side. Models of
elementary particles as geons in classical general relativity acquire **the
transformation properties of a spinor precisely when the spacetime manifold is
not time orientable**. So a body defined in a region with no time orientation is
not the same object as a body defined here; the absence of the orientation is
what makes it a spinor rather than a scalar. This is the best available answer to
"define the particle there" that does not require a quantum field theory on the
far side, which [37] and [38] say is not available anyway. It should be read with
[58], where the Dirac equation across a signature change was found to carry no
conserved inner product: this paper says the far-side object is spinorial, that
one says the spinorial object has no conserved product across the crossing.

### [131] Dulac, Wei, *No boundary density matrix in elliptic de Sitter*, arXiv:2512.00704
SUPPORT, and it puts a number on the information question. Elliptic de Sitter is
$dS/\mathbb{Z}_2$, non-time-orientable by antipodal identification. Unlike global
de Sitter, whose vacuum is prepared by a no-boundary Euclidean path integral, the
Euclidean elliptic space **does not define a wavefunction; the proposal is that
the path integral there defines a no-boundary density matrix instead**, and for a
free Dirac fermion in two dimensions the von Neumann and Renyi entropies of that
density matrix are computed analytically, reducing to correlators of vertex
operators on non-orientable surfaces.

This is the closest the corpus comes to the fifth scope item, how much
information survives when the time orientation is gone, and the answer has the
right form: what you get back is a mixed state, and the information lost is its
entropy, computable. The article should take this as the shape of its own
statement, a density matrix rather than a state, with the loss quantified by an
entropy rather than asserted.

There is a second observation in the paper which is a challenge and should not be
passed over: in this setting the **global Hilbert space is one-dimensional**,
while the Hilbert space associated with each individual observer is a nontrivial
Fock space. If that carries over, then there is no global state of the far side
to speak of at all, and every statement about what happens there is necessarily
relative to an observer who is not there. That is a sharper form of the
objection our Bölüm 14 already concedes.

### The degenerate surface: making the crossing calculable rather than arguing about it

### [132] Stoica, *On singular semi-Riemannian manifolds*, arXiv:1105.0201
### [133] Stoica, *Spacetimes with singularities*, arXiv:1108.5099
SUPPORT, taken together, and the most useful pair of tools in this group for Bölüm 13.3 and 9.4.
The standing difficulty at the threshold is that when the metric degenerates the
inverse metric, the contraction of covariant indices, the Levi-Civita connection
and the curvature all stop being defined, which is why the literature argues
about conventions instead of computing. Stoica constructs an invariant, canonical
contraction of covariant indices valid for degenerate metrics, applicable to
radical-annihilator tensor fields; uses it with the Koszul form to define a
covariant derivative on radical-stationary singular semi-Riemannian manifolds;
builds the Riemann curvature from it; and shows that on the class he calls
semi-regular **the Riemann curvature is smooth even where the metric
degenerates**. From this he writes a densitized Einstein tensor whose weight-2
density stays smooth through the degeneracy, giving a densitized Einstein
equation that is smooth everywhere and equivalent to the standard one wherever
the metric is non-degenerate.

The second paper carries the same apparatus explicitly to **metrics which change
signature**, states that the operations usually prohibited can still be
performed in this framework, and, the part that matters for the round trip,
obtains spacelike foliations of the globally hyperbolic regions of the extended
solutions with the consequence that **the initial data can be preserved in
reasonable situations**.

That last clause is the one to hold onto. Preservation of initial data through a
degenerate surface is exactly what deliverable (a) needs and exactly what [89]
denied by a different route. The two are not in direct contradiction, because
Stoica changes the objects rather than the physics: it is the densitized Einstein
equation that stays smooth, not the ordinary one. Bölüm 9.1 should say which
equation it is imposing. But this is the only construction in the corpus in which
something is carried through the degeneracy rather than matched across it, and it
is therefore the natural setting for a transfer relation between the two
crossings.

### [134] Holdom, *Cosmologies with turning points*, arXiv:2302.10716
SUPPORT, and a sharp warning about coordinates. Singularity-free,
geodesically-complete cosmologies are built on manifolds that are **not quite
Lorentzian**: the metric can be smooth everywhere or non-degenerate everywhere,
but not both, and which of the two you see depends on the coordinate system. In
the smooth chart the Einstein tensor is first order in derivatives; in the
non-degenerate chart the metric has a piecewise FLRW form. On such a manifold the
universe can **turn around, expanding to contracting or the reverse, with the
Einstein equations satisfied everywhere and no violation of the standard energy
conditions**, and a corresponding extension of the Kasner vacuum solutions is
given.

Two consequences. First, the article's Bölüm 13.3 argument that no continuous
bridge can be built, and the counter-model [44], are both partly arguments about
which chart is being used; this paper shows that smoothness and
non-degeneracy are not simultaneously available, so a claim that the interpolation
fails must say in which chart. Second, and directly for the round trip, this is a
worked example of a **turning point** on a not-quite-Lorentzian manifold with the
field equations intact and no exotic matter: the geometry goes in one sense,
turns, and comes back. That is the round trip's shape in the cosmological
setting, and the article should compare its two crossings against this single
turning point.

### [135] Rieger, *Möbius structures and non-orientable semi-Riemannian manifolds*, arXiv:2601.10009
CHALLENGE, a priority finding, and already in the corpus without an entry. The
question is global: which signature-changing metrics are admissible on a
non-orientable manifold. The main result is that **on non-orientable compact
surfaces the radical of a signature-changing metric cannot be everywhere
transverse along the hypersurface of signature change**. In particular metrics
built by the transformation prescription $\tilde g = g + f V^\flat \otimes
V^\flat$, with $g$ Lorentzian and $f$ a smooth interpolation, **necessarily fail
the transversality condition**. The obstruction is purely global and is tied to
the Euler characteristic and the non-existence of nowhere-vanishing vector
fields.

This bears on the article at a point it has not defended. The prescription named
here is the one of [27], the transformation theorem the corpus relies on to
produce signature-changing manifolds at all, and the transverse radical is the
hypothesis under which [28] and [45] work. So: the far side is posited to have no
time orientation; orientability failures obstruct exactly the transversality that
the corpus's construction of the change surface assumes; and the obstruction is
topological, so no local smoothing removes it. The article cannot simultaneously
help itself to a non-orientable far side and to the transverse-radical machinery
without saying why its configuration escapes this theorem. The theorem is proved
for compact surfaces, which is the escape route to examine first.

### [136] Kuhfittig, *Periodic signature change and embedding class one*, arXiv:2204.14222
CONTEXT, already in the corpus without an entry, and relevant only for its
structure. A four-dimensional spacetime of embedding class two is reduced to
class one by a coordinate transformation whose extra dimension may be spacelike
or timelike; making the free parameter of the transformation a **periodic
function of time** produces a model interpretable as a **periodic change in the
signature of the embedding space**. The content is an oscillating-universe model
and is not ours, but the construction is the only one in the corpus that produces
a **repeated** signature change rather than one or two, and the parameter that
drives it is explicit. If the article ever wants more than a single round trip,
this is the existing template.

### [137] Andrew, Steinfelds, Andrew, *Interpolated topology change and spin cobordism*, arXiv:2601.05957
CONTEXT, already in the corpus without an entry, and the companion to [102].
Regulated topology change is built from smooth Lorentzian spin cobordisms with
interpolating metrics, allowing a **transient failure of global hyperbolicity**
while keeping smoothness, Lorentz signature and spin compatibility, with a
curvature functional weighting the admissible interpolations and a
Stiefel-Whitney constraint enforcing spin consistency. The signature never
changes here, so it is not our configuration. Its use to us is the licence it
formalises: a transient loss of global hyperbolicity between two well-behaved
Lorentzian ends is treated as something to regulate and weight, not as a
prohibition. Our Bölüm 14.1 complaint that region II has no Cauchy surface is
exactly a transient failure of that kind, bracketed by two Lorentzian regions.

### The analogue that has now been measured

### [138] Smolyaninova, Cartelli, Augstein, Spickard, Devadas, Smolyaninov, *Experimental observation of effective gravity and two times physics in ferrofluid-based hyperbolic metamaterials*, arXiv:2003.01564
SUPPORT, and it upgrades [97] from proposal to observation. The two-times
behaviour of extraordinary waves in hyperbolic metamaterials, proposed in the PRL
recorded as [97], is **reported as experimentally observed** in iron- and
cobalt-based ferrofluid hyperbolic metamaterials via gravity-like nonlinear
optics: alongside the ordinary temporal coordinate, the spatial coordinate along
the optical axis also acquires timelike character.

This is the strongest item the article has for the observation scope items. A
region with more than one timelike direction is not only constructible but has
been built and probed, and the knob is the ferrofluid. Bölüm 16.4 should name
this system. The honest qualification is that the effective metric is $(2,2)$
rather than our $(3,1)$, and that what is observed is the two-times character of
the medium, not a particle making a round trip through it. Only the abstract
could be retrieved for this file.

### Re-read under the new scope

### [24 revisited] Hellaby, Sumeruk, Ellis, arXiv:gr-qc/9907042
The entry in Group 2 files this as a black hole result. Under the round trip it
is something else: **two Lorentzian universes joined through a Euclidean bounce**
is the round trip's topology, with the two crossings explicit and the interlude
finite. The condition it records is the one that now costs us most, that removing
all surface effects needs not only vanishing extrinsic curvature but also
vanishing three-dimensional Ricci scalar. Read with [113], that is the same
statement twice: a crossing with no surface layer is a crossing under the strong
condition, and the weak condition buys transmission by accepting the layer.

### [28 revisited] Rieger, Hasse, arXiv:2409.02403
Group 2 files this as support for the original motivation. Under the round trip
it is a direct threat to deliverable (a), and should be moved. If there are
locally time-reversing loops through **every** point of the transition
hypersurface, and no consistent distinction between future- and past-directed
vectors around them, then the two crossings cannot be labelled "outward" and
"return" by anything intrinsic to the surface. The placement of the exit event on
our time axis then cannot be read off the matching alone; it needs a labelling
imported from the Lorentzian side, and the article has to say what supplies it.
This is the same degeneracy that [128] describes from the observational side.

### What this group changes

26. **The weak junction condition is not free, and the price is now named.**
    [113] shows that a junction with non-vanishing extrinsic curvature *is* a
    matter layer, and that such metrics do not satisfy the vacuum Einstein or
    the Einstein-Klein-Gordon equations; correspondingly, a field with
    non-vanishing momentum at the surface does not satisfy the massless
    Klein-Gordon equation there. Bölüm 9.1 adopts exactly those two
    non-vanishings. It must therefore either supply the layer and the source, or
    return to the strong condition. This is the largest open liability in the
    new article and it is not addressed anywhere in it.
27. The Hellaby-Dray line, on which our licence [91] rests, stands accused in
    [114] of a specific technical error, division by zero and products of
    distributions. Bölüm 9.1 has to take a side in that exchange explicitly.
28. There is now a variational treatment of shells of **unconstrained
    signature**, [115], with several regularisations proved equivalent. That is
    a better foundation for the threshold than any distributional convention,
    and it answers [93]'s point that the formalism settles nothing: the
    ambiguity does not reach the shell equation.
29. One constraint on the crossing is theory-independent. [116] proves that
    continuity of the normal components of the energy-momentum tensor across
    the matching hypersurface holds whatever the field equations. The same paper
    shows that general relativity and $F(R)$ are the only theories in a wide
    class that admit a jump in the second fundamental form, and that what such a
    jump produces is an impulsive gravitational wave. So the freedom Bölüm 9.1
    wants exists essentially only in general relativity, and it has a
    gravitational emission attached to it.
30. Deliverable (a), the placement on our time axis, has a mechanism and it is
    not a duration. [118] replaces imaginary time with a **complex lapse**, gets
    a single complex action interpolating between the Lorentzian and Riemannian
    theories with a signature change between them, and locates events by the
    argument of the lapse. Since no elapsed time can be read on the far side,
    the phase of the lapse acquired between the two crossings is the right
    carrier of the placement. This should become the variable of Bölüm 9.4.
31. The two-crossing geometry exists in the literature: [117] treats a spacetime
    as a **double** signature change, asks after a surface layer at both
    crossings, finds none, and follows worldlines through. It should be read
    with [24], the Euclidean bounce between two Lorentzian universes, and
    against [113]: an absence of surface layer is the signature of the strong
    condition, so the article must explain how a crossable threshold gets one
    without the other.
32. The finite layer with two interfaces has been solved and built, in the dual
    geometry. [120] gives the scattering coefficients of a temporal slab with
    the application time playing the role of thickness, [122] gives the transfer
    matrix so that multilayer configurations compose, and [121] reports the
    **experimental** observation of interference between two temporal
    interfaces, a temporal Fabry-Perot. Bölüm 9.4 should be written as a
    transfer-matrix calculation and should say plainly that its analogue is a
    time slab, not a signature change.
33. **The nonlocal constraint that restores predictability may smuggle in the
    answer, and the article must say so.** [123], [124] and [125] identify it:
    it is Asgeirsson's mean value identity over conjugate conics, conformally
    covariant on a $2+2$ region. But its origin is John's theorem that solutions
    of the ultrahyperbolic equation are the compatibility condition for a
    function on line space to be the line integrals of a function on Euclidean
    3-space. Data satisfying the constraint are the shadow of a one-time object.
    Recovering prediction that way restores it only for far-side configurations
    that were secretly single-time configurations. The article can use the
    constraint but must show its admissible data are not of that form.
34. Predictability nonetheless has three positive results that Bölüm 6.1 does
    not yet use: [125] solves the Cauchy problem over a family of null
    hypersurfaces, [127] gives a well-posed characteristic problem with an
    asymptotic representation, and [126] proves very weak $H^\infty$
    well-posedness for ultrahyperbolic Schrödinger equations with
    **discontinuous coefficients**, which is the only such theorem that applies
    to a problem posed across our threshold rather than inside one region.
    Together with [109] and [73], the article can no longer say prediction
    collapses on the far side; it must say on which initial surfaces it does.
35. **What a round trip looks like from our side may be an annihilation.** [128]
    shows a failure of time orientability is indistinguishable from a
    particle-antiparticle annihilation event, and [28] notes that loops at the
    change hypersurface may appear as a pair creation at two distinct points.
    Taken together, the entire observable content of the round trip is a pair
    creation at the entry and an annihilation at the exit, and the article must
    say what distinguishes that from an ordinary pair event. This is
    simultaneously the concrete prediction the observation scope items want and
    the sharpest degeneracy threatening them.
36. Deliverable (b) has its first quantitative dictionary entry. [129] shows
    that on a non-time-orientable spacetime the twisting of the time axis is
    measured by a $U(1)$ bundle, that Maxwell's equations and the Lorentz force
    follow from it, and that **the boundary of a time-reversing region carries a
    net electric flux and therefore looks exactly like a charge**. A far-side
    orientation, meaningless in our terms, appears here as an apparent charge at
    the threshold. This is also a signalling carrier that is not a photon: the
    channel is the connection, and what crosses is flux.
37. What a particle is on the far side has a classical answer. [130]: geons on a
    manifold that is not time orientable transform as **spinors**. So the object
    defined there is spinorial precisely because the orientation is missing,
    which is the constructive counterpart of [58]'s finding that no conserved
    inner product exists for the Dirac equation across the change.
38. The information question has the right form and a computed example. [131]:
    on a non-time-orientable spacetime the Euclidean path integral gives a
    **density matrix rather than a wavefunction**, and its von Neumann and Renyi
    entropies are computed. The article should state its own loss as an entropy
    of a returned mixed state. The same paper's remark that the global Hilbert
    space is one-dimensional while each observer's is a Fock space is a warning:
    there may be no observer-independent state of the far side at all.
39. The degeneracy can be computed through rather than matched across. [132] and
    [133] give an invariant contraction, connection and curvature for degenerate
    metrics, a densitized Einstein equation that stays smooth through the
    change, and, critically, spacelike foliations under which **initial data can
    be preserved**. This is the only construction in the corpus that carries
    something through the surface, and it is therefore the natural home for a
    transfer relation between the two crossings. The catch is that what stays
    smooth is the densitized equation, not the ordinary one.
40. [134] shows smoothness and non-degeneracy cannot both hold in one chart, so
    Bölüm 13.3's claim that no continuous bridge exists, and its counter-model
    [44], must both specify a chart. It also exhibits a **turning point** with
    the Einstein equations intact and the standard energy conditions unviolated,
    which is the round trip's shape reduced to one surface.
41. **A global obstruction stands against combining a non-orientable far side
    with the corpus's own construction of the change surface.** [135] proves the
    radical cannot be everywhere transverse on non-orientable compact surfaces,
    and that the transformation prescription of [27], on which [28] and [45]
    depend, necessarily fails transversality. The obstruction is topological, so
    no local smoothing removes it. The article must show its configuration
    escapes the theorem, and the compactness hypothesis is the place to look.
42. The two-times region has been observed, not merely proposed. [138] reports
    experimental observation of two-times behaviour in ferrofluid hyperbolic
    metamaterials, which upgrades [97]. Bölüm 16.4 should name this apparatus
    alongside [98] and [100], with the qualification that the effective
    signature is $(2,2)$ and that no round trip has been made through it.
43. Gaps that this sweep did not fill, and that should be recorded rather than
    papered over. First, **wave packets** crossing a signature change: nothing
    exists. The whole literature is plane modes, and [96]'s geodesics; the
    packet-level questions of distortion, delay and what survives have to be
    answered by our own calculation, with [120] and [122] as the only formal
    guide. This is a scope-level finding, not a search gap: the article models
    the particle as a wave packet and interprets it as a point body, and the
    packet layer of that model has no literature behind it at all. **Amended by
    item 58**: the barrier-crossing packet literature supplies the machinery,
    but nothing exists for the signature-changing case specifically.
    Second, **gravitational signalling across the surface**: apart from
    [116]'s impulsive wave and [113]'s matter layer, there is no treatment of a
    gravitational wave crossing a signature change, and no treatment of what a
    mass on one side does to the other. Third, the **originating weak-condition
    paper**, Ellis, Sumeruk, Hellaby and Roberts 1992, cited as the source of
    the condition by [66] and others, was not found on arXiv in this sweep and
    is not in the corpus; it is a 1992 journal paper and may simply predate the
    archive, but that was not verified.
    The load-bearing citation of the new article is currently reached only
    through papers that discuss it.

---

## Group 11: the intermediate region as a first-class object

Collected after the article was restructured around six questions and three
regions. The intermediate region is now a subject rather than a surface, and the
user is computing a grid: four kinds of intermediate region (none, Kleinian
$(2,2)$, Euclidean $(4,0)$, degenerate layer) against five thicknesses (zero,
thin, finite, thick, unbounded). This group is organised to serve that grid.

**A note that must be read before the tunnelling entries.** A large part of this
group comes from the tunnelling-time literature. Those papers are taken here for
their **operational timing content only**: how a delay depends on the width of a
crossed region, and what a packet does to it. Several of them frame their results
in terms of superluminal propagation. That framing is not adopted, is not needed
for anything below, and is the reason the corpus previously discarded the
signalling-paradox papers. Nothing in this group re-imports them.

### Which cells of the grid are already occupied

- **No intermediate region at all.** [99], where the signature is changed by
  flipping the **spatial** eigenvalues, so the far side is purely timelike and is
  reached directly. This is the only paper in the corpus whose far side is ours.
- **Zero thickness.** [16], [87], [113], [90], [91]. The whole junction-condition
  dispute lives in this cell and nowhere else.
- **Finite thickness.** [84], whose second half is a slab of Kleinian spacetime of
  finite length with tunnelling through it, and now the whole Hartman cluster
  below.
- **Unbounded.** [84] again, in its first half: a single planar boundary onto a
  half-space gives mirror-like behaviour of the particle flux.
- **Degenerate layer.** [96] (geodesics crossing along one, two or three
  admissible directions), [132] and [133] (curvature and initial data carried
  through the degeneracy), [135] (the global transversality obstruction), [134]
  (smoothness and non-degeneracy not simultaneously available).
- **Euclidean $(4,0)$, any thickness.** [87] and [24] and [59]; the frequency-mix
  result of [87] is stated for a spacelike region of arbitrary conformal size.

[84] is the single most useful existing entry for this structure because it
occupies two cells in one paper and passes between them by varying one parameter.

**A fact from [84] that decides how the rest of this group applies, and which the
article should state explicitly.** In the Kleinian slab the dispersion relation
reads $\omega^2/c^2 = k_x^2 + k_y^2 - k_z^2 + \mu^2$ where $z$ is the crossing
direction, so **$k_z$ must be purely imaginary inside the slab**; the paper
substitutes $k_z \to ip$ and obtains $|r|^2 + |t|^2 = 1$. The interior of a
$(2,2)$ layer is therefore **evanescent in the direction of crossing**, not
propagating. The crossing is a tunnelling process. That is what licenses
everything below: the Euclidean cell and the Kleinian cell of the grid behave the
same way in the crossing direction, and the barrier-tunnelling results apply to
both. It also means the finite-thickness transmission the article wants is an
exponentially small amplitude, and the thickness dependence of the article's
whole construction is the thickness dependence of a tunnelling amplitude.

### The return placement may be undetermined in principle

### [139] Briscese, *Note on complex metrics, complex time and periodic universes*, arXiv:2206.09767
CHALLENGE, and the priority finding of this group. It lands directly on the
mechanism adopted in [118]. If complex metrics are admitted, then **for any
solution $g_{\mu\nu}$ of Einstein's equations, a complex change of time
constructs infinitely many periodic or bouncing complex solutions $\hat
g_{\mu\nu}$ that are physically indistinguishable from $g_{\mu\nu}$ over an
arbitrarily long time interval.** The construction is by complex
diffeomorphism, and the author's own verdict is that this is an unacceptable
arbitrariness in the theory. He then shows that the Kontsevich-Segal condition
on physically meaningful complex metrics, as discussed by Witten, **restricts the
family of admissible complex diffeomorphisms and removes the arbitrariness**, and
argues the condition should be read as a quantum-gravity generalisation of the
equivalence principle to complex spacetimes.

This is exactly the shape of objection the project most needs to hear, and it is
constructive rather than fatal. Deliverable (a) reads the return placement off a
complex-time construction. This paper says that a complex change of time can
manufacture a bouncing solution, indistinguishable from the original, essentially
at will, so **the placement is not determined by the complex-lapse machinery
alone**. Something has to cut the family down, and the only candidate on offer is
an allowability criterion. Bölüm 9.4 cannot use [118] without also adopting a
criterion of this kind and saying which. Note also that what this paper
manufactures at will is precisely a **bouncing** solution: our round trip is a
bounce, and it is the bounce that is shown to be arbitrary.

### [140] Witten, *A note on complex spacetime metrics*, arXiv:2111.06514
PRIOR, and the criterion [139] appeals to. Complex saddle points seem necessary
in the "Euclidean" path integral of general relativity, but some restriction on
the allowed ones is needed to exclude unphysical examples; a proposal for such a
restriction is made, motivated by Kontsevich and Segal's work on complex metrics
in quantum field theory and by Louko and Sorkin's earlier work on **topology
change from a real time point of view**. The Louko-Sorkin lineage is worth noting
for us: the criterion's ancestry is in exactly the problem of interpolating
between geometries in real time, which is our problem.

The article must decide whether its interpolation between the Lorentzian and the
far-side signature is an allowable complex metric in this sense. That is a
computation, not a matter of taste, and it is the check that makes [118] usable.

### [141] Lehners, *Allowable complex metrics in minisuperspace quantum cosmology*, arXiv:2111.07816
CHALLENGE, and it says the check is tight. Applying the Kontsevich-Segal-Witten
criterion in minisuperspace, **the saddle points of the gravitational path
integral lie right at the edge of the allowable domain of metrics**, even when
the saddles are complex or Euclidean, and **the Lefschetz thimbles, in particular
the steepest descent contours for the lapse integral, are cut off as they intrude
into the domain of non-allowable metrics**. In the de Sitter case the lapse
integral is forced to become asymptotically Euclidean.

For us: the complex lapse contour of [118] and [142] is not free. It is bounded by
allowability, the physically interesting configurations sit on the boundary of
what is allowed, and the contour one would naturally deform to is truncated. Any
argument that fixes the return placement by choosing a lapse contour has to show
the chosen contour stays inside the allowable domain.

### [142] Banihashemi, Jacobson, *On the lapse contour in the gravitational path integral*, arXiv:2405.10307
SUPPORT, and the most directly usable technical result for [118]. The
gravitational path integrand has an **essential singularity at zero lapse, which
is where the spacetime metric degenerates**; the lapse contour must run from
$-\infty$ to $+\infty$ and must not pass through zero, which raises the question
of which contour is correct. Starting from the reduced phase space path integral,
which has no essential singularity, the authors observe that if the momenta are
integrated before the lapse then **the lapse contour should pass below the origin
in the complex lapse plane**, and that this same contour is consistent with
quantum field fluctuation amplitudes having the usual short-distance vacuum form
and with obtaining the Bekenstein-Hawking entropy from a Lorentzian path integral.

Three things for us. First, zero lapse **is** our degenerate threshold surface, so
the essential singularity of the gravitational path integral sits exactly where
$V = c$ sits; the statement that the contour must not pass through zero is the
path-integral form of the statement that the threshold cannot be crossed along the
real axis. Second, going **below** the origin is a definite prescription, which is
what deliverable (a) needs: it fixes the sign of the phase acquired at the
crossing, and with two crossings the two contributions either add or cancel
depending on whether the same side is taken both times. That is the concrete
question the article should now compute. Third, the prescription is derived rather
than postulated, from the reduced phase space, which is the standard [63]
complains does not exist for signature change.

### [143] Jonas, Lehners, Quintin, *Uses of complex metrics in cosmology*, arXiv:2205.15332
CHALLENGE, and the sharpest consequence of the criterion for a round trip.
Complex metrics let one replace singular spacetimes with regular ones, but also
describe unphysical solutions in which quantum transitions become more probable
than ordinary classical evolution. Deciding allowability in general is a
complicated optimisation problem because of the freedom to deform contours, and
the paper gives a fast method for minisuperspace. The results: classical
transitions always sit **on the boundary** of the allowable domain, so contours
must be chosen with care; no-boundary solutions are allowable; and, the part that
bears on us, **the proposed quantum tunnelling transitions from a contracting to
an expanding universe violate the allowability criterion and may thus be
unphysical**.

A contracting-to-expanding transition is a turnaround through a complex region,
which is the cosmological form of our round trip. This says that particular class
of transition is the one the criterion rejects. The article cannot ignore this: it
has to show its own configuration is not of the rejected type, and [134]'s
turning point is the natural comparison.

### How the answer depends on thickness

The grid's second axis. Since [84] shows the crossing direction is evanescent in
a $(2,2)$ layer and a Euclidean layer is evanescent by construction, the
thickness dependence of the article's crossing is the thickness dependence of a
tunnelling amplitude and of a tunnelling delay. Those are two different
dependences and they point in opposite directions, which is the single most
important thing this group establishes.

### [144] Marinov, Segev, *On the concept of the tunneling time*, arXiv:quant-ph/9603018
PRIOR, and the reference to cite when Bölüm 9.4 goes from plane modes to packets.
The asymptotic time evolution of a wave packet incident on a barrier is worked out
with the **Wigner phase-space distribution**, and the result is that the
distortion of the transmitted packet is determined by **two time-like parameters,
given by the energy derivative of the complex transmission amplitude**. The
treatment is consistent with the Buttiker-Landauer time, the complex time and
Wigner's phase time at once, and the speed-up effect and the negative dispersion
are discussed.

This is the machinery the article's packet layer has been missing. Our
transmission amplitude across the slab is complex and thickness-dependent; its
energy derivative therefore gives, by this construction, both the delay of the
returning packet and its distortion, from one object. The two parameters are the
right output for question 5 of the new skeleton, what changes and what stays.

### [145] Saxton, Harris, *Control of arrival time using structured wave packets*, arXiv:2007.11676
SUPPORT with a hard consequence for deliverable (a). Gaussian and non-Gaussian
packets with **identical momentum densities** are scattered from a square barrier,
and the non-Gaussian packets show **different average arrival time delays**. The
difference comes from the non-linear terms in the phase of the momentum wave
function, which change the self-interaction time of the packet, and the average
arrival delay can therefore be **controlled through the momentum wave function
phase, independently of the packet's energy and momentum density**.

Read against the round trip this is not a convenience, it is a constraint. The
return placement is **not fixed by the particle's energy**. Two particles prepared
with the same energy and the same momentum distribution, differing only in the
phase structure of the packet, come back at different times. So the article's
deliverable (a) cannot be a function of the incident energy alone; it is a
functional of the prepared packet. That is a genuine prediction and also a
warning, because it means any single number quoted for the return offset is
underdetermined until the preparation is specified. Abstract only for this file.

### [146] Frentz, Lunardi, Manzoni, *Average clock times for scattering through asymmetric barriers*, arXiv:1312.4000
SUPPORT, and the one that connects packets to the saturation. The
Salecker-Wigner-Peres clock times for reflection and transmission, averaged over
the post-selected reflected and transmitted sub-ensembles, are computed for a
localised wave packet scattering off an **asymmetric** barrier, together with the
dwell time over the same sub-ensembles. Negative average reflection times are
examined; averaging over the reflected sub-ensemble removes the negative peaks at
resonance but still permits negative values for transparent barriers; and **the
saturation of the average times with barrier width, the Hartman effect, is
addressed** in the same framework.

Two reasons to keep this. The barrier is **asymmetric**, which is our case: the
entry crossing and the exit crossing are not the same, since the particle enters
from a Lorentzian region and leaves into one but the interior orientation is not
defined. And the clock is a physical clock read on post-selected sub-ensembles,
which is the operational form question 6 of the new skeleton asks for: what a
thing done there means over here is what a clock here records for the
sub-ensemble that came back.

### [147] Lunardi, Manzoni, *Relativistic tunneling through two successive barriers*, arXiv:0708.3507
CHALLENGE to deliverable (a), and the closest configuration in this group to the
round trip. A **Dirac particle**, so massive and relativistic, tunnelling through
**two successive barriers**, which is two crossings with a region between them.
Both the phase (group) tunnelling time and the dwell time are computed, and **in
the opaque limit the relativistic theory also allows the emergence of the
Generalized Hartman Effect**, previously known non-relativistically and in
electromagnetic analogues.

The Generalized Hartman Effect is the statement that the tunnelling time through
two successive barriers becomes independent not only of the widths of the barriers
but **of the separation between them**. If that carried over to our
configuration, the consequence for the project is severe and should be stated
without softening: **the delay accumulated on the round trip would carry no
information about how thick the intermediate region is, nor about how long the
particle was in it.** The return placement would then be a fixed offset,
independent of the interlude, and question 2 of the new skeleton, what the
calculations give for each definition of the intermediate region, would have the
same answer for every thickness in the grid.

The reasons to think it does not carry over unmodified are entries [148], [149]
and [150]. This is the central dispute of the group and the article should present
it as a dispute.

### [148] Kudaka, Matsumoto, *A mathematically rigorous approach raises questions concerning the generalized Hartman effect*, arXiv:1105.2159
CHALLENGE to [147], and therefore the first escape route. The claim that the
tunnelling time does not depend on the separation between two successive barriers
is argued to rest on **a lack of mathematical rigour in the original reasoning**,
and a rigorous treatment is said to show that **the tunnelling time does depend on
the length of the free space between the barriers**. If this is right, then the
separation between our two crossings, that is the thickness of the intermediate
region, is recoverable from the return after all, and deliverable (a) survives in
the form the article wants.

### [149] Chuprikov, *On the generalized Hartman effect and transmission time for a particle tunnelling through two identical rectangular potential barriers*, arXiv:1005.1323
CHALLENGE to [147] by a different and more informative route, and the most useful
single entry for the grid. The subprocesses, transmission and reflection, are
modelled separately at all stages of scattering, and dwell times together with
local and asymptotic group times are defined for each. The findings that matter:
the asymptotic transmission group time reproduces the Wigner phase time in the
opaque limit and hence reproduces both the usual and the generalized Hartman
effects; but **the transmission dwell time predicts monotonic growth of the
tunnelling time as the distance between the opaque barriers increases**, and the
authors argue that only this time scale is the true average time spent by
transmitted particles in the region. They also note that all transmission times
admit only indirect measurement, so that unambiguous interpretation of tunnelling
time experiments is impossible without knowing the dynamics at all stages.

So the saturation and the growth are properties of **two different clocks**, not
two different physical situations. The group time saturates; the dwell time grows
monotonically with the separation. For our grid this is the decisive
clarification: the thickness of the intermediate region is recoverable, but only
from the dwell time, and the dwell time is the one that cannot be read directly
off the returning packet. Bölüm 9.4 must state which clock its return placement is
in, and the honest answer is that the accessible clock is the saturating one.

### [150] Bhattacharya, Roy, *Hartman effect and dissipative quantum systems*, arXiv:1209.0993
CHALLENGE to [147], the third escape route, and the physically cheapest. For a
dissipative quantum system with an inverted parabolic barrier, **the dwell time
increases with barrier width, which precludes the Hartman effect outright**. So
saturation is a property of the unitary, dissipation-free idealisation. Our
crossing is not obviously dissipation-free: [113] puts a matter layer at the
junction and [89] allows the surface to be a source, both of which are couplings
to something outside the mode. If the threshold dissipates at all, the saturation
is lifted and the thickness becomes readable. This is the most promising of the
three escape routes because it turns the liability identified in [113] into the
thing that rescues deliverable (a).

### [151] Hasan, Mandal, *General(ized) Hartman effect*, arXiv:2010.02755
PRIOR, and it fixes how the grid's thickness axis behaves under repetition. If
the Hartman effect holds for an arbitrary unit-cell potential then it also holds
for a periodic system built from repeated copies of that cell, and moreover **the
tunnelling time for a sufficiently thick single cell equals that of the whole
periodic system, for any value of the intervening gap between consecutive cells**.
The bearing on us is direct and it is the formal statement of the grid's
right-hand column: once the intermediate region is thick enough, adding more of
it, or adding more regions, changes nothing. "Thick" and "unbounded" collapse into
one cell, and by [149] the collapse is a property of the group time only.

### [152] Olkhovsky, Recami, Zaichenko, *Resonant and non-resonant tunnelling through a double barrier*, arXiv:quant-ph/0410128
CONTEXT, and it supplies the exception. An explicit phase time is obtained for a
non-relativistic particle tunnelling through two rectangular barriers in both the
resonant and the non-resonant case. Near a resonance the transmission coefficient
and the phase time have Breit-Wigner type denominators; away from resonance and at
low transmission probability, the phase time depends on the barrier width and on
the separation only **exponentially weakly**. The exception is the resonance: at a
resonance the double-barrier system has structure, a Breit-Wigner line with a
width, and the placement is no longer flat. If the article wants the return to
carry information about the interlude, resonant crossing is the regime to work in,
and it is the regime [121]'s temporal Fabry-Perot realises. Abstract only for this
file.

### [153] Klos, Dadoenkova, Rychly, Dadoenkova, Lyubchanskii, Barnas, *Hartman effect for spin waves in the exchange regime*, arXiv:1801.05876
SUPPORT, and the only preparable apparatus in this cluster. The group delay of a
spin-wave packet tunnelling through a barrier in a thin magnetic film, the barrier
being a locally increased magnetic anisotropy field, is derived and **shown to
saturate with increasing barrier width**, the signature of the Hartman effect,
with general boundary exchange conditions allowing different coupling strengths
between the barrier and its surroundings. A CoFeB layer with perpendicular
anisotropy induced by an MgO overlayer is proposed as a system in which to observe
it.

Two uses. It is a magnon system, so it sits alongside [98], the polar 3He magnon
condensate whose effective metric changes signature: the same class of material
supports both an effective signature change and a measurable tunnelling
saturation, which is the nearest thing to a bench on which the article's thickness
question could be asked. And the boundary exchange conditions are a tunable
junction condition, which is the analogue knob for the strong-versus-weak choice.

### The matter layer, both branches

[113] established that a junction with non-vanishing extrinsic curvature is a
matter layer and that the metric then fails the vacuum equations. The instruction
was to pursue both branches: accept the layer and characterise it, or find a
construction that transmits without one. Both branches have results, and they
pull against each other.

### [154] Eiroa, Figueroa-Aguirre, Senovilla, *Pure double-layer bubbles in quadratic F(R) gravity*, arXiv:1704.00698
SUPPORT, and it is the best answer available to "can the layer be something other
than ordinary matter". Spherically symmetric bubbles separating two regions of
constant scalar curvature, that is two different cosmological constants, are
constructed by the junction formalism in quadratic $F(R)$ theory. The matching
hypersurface supports in general a thin shell **and a gravitational double
layer**, and, for appropriate parameter values whenever the quadratic coefficient
is negative, **pure double layers are possible**: the authors state this is the
first example of a pure double layer in a gravitational theory.

Why this matters to us. A double layer is a dipole-type distributional source, a
$\delta'$ rather than a $\delta$. A **pure** double layer is a junction that
carries no ordinary thin shell at all, only the dipole term. That is a third
option beyond the two the article has been choosing between: not "vanishing
extrinsic curvature, no layer" and not "non-vanishing extrinsic curvature, a
matter layer", but a junction whose entire distributional content is a dipole with
no monopole. If our threshold could be arranged as a pure double layer, [113]'s
objection would be met in its own terms, because there would be no layer of matter
with stresses to supply. The price is that the construction lives in quadratic
$F(R)$ rather than in general relativity, and by [116] general relativity is
precisely the theory that does **not** support gravitational double layers as a
generic option. The article should state whether it is prepared to leave general
relativity for this.

### [155] Rosa, André, Lemos, *Traversable wormholes with double layer thin shells in quadratic gravity*, arXiv:2305.06829
CHALLENGE to the branch [154] opens, and it should be read immediately after it.
In quadratic gravity, $R + \alpha R^2$ plus matter, the junction conditions are six
and permit double layer thin shells; the authors build traversable wormholes in
which the interior region is matched to two exterior vacuum domains **through two
double layer thin shells**, and test the null energy condition throughout. The
result: the NEC is satisfied for the matter in the whole interior, notably at the
throat, and for some components of the stress-energy at the double layer, but is
**not satisfied for the double layer stress-energy distribution component
itself**. The authors conclude that the NEC seems basically impossible, or at
least very hard, to satisfy when double layer thin shells are present. Single
layer shells are admitted by the theory and can satisfy the NEC, but only for
asymmetric configurations without an interior.

For us this is close to decisive on the second branch. The geometry is our
geometry: an interior region reached through **two** shells, with a traversal. The
finding is that the double layer route, which [154] made attractive, buys the
absence of ordinary matter at the price of violating the null energy condition in
the layer's own distributional component. Combined with [113], the position is
now: a transmitting junction either carries a matter layer that fails the vacuum
equations, or carries a pure double layer that fails the NEC. The article's
Bölüm 9.1 has to pick one and say what it costs. That the same paper finds
**asymmetric single-layer** configurations that do satisfy the NEC is the one
opening, and it is worth noting that our two crossings are naturally asymmetric.

### The pair creation degeneracy: essentially nothing found

The instruction was to look for anything that breaks the degeneracy of [128],
that a failure of time orientability is indistinguishable from a
particle-antiparticle annihilation. The honest report is that nothing does, and
the structural reason is the following.

### [156] Hadley, *A gravitational explanation for quantum theory: non-time-orientable manifolds*, arXiv:gr-qc/0703150, and [157] Diemer, Hadley, *Charge and the topology of spacetime*, arXiv:gr-qc/9905069
CONTEXT, and they explain why the degeneracy is hard rather than removing it.
[156] states the programme: manifolds that are not time orientable allow topology
change and have, as additional properties, **net charge from source-free
equations** and spin-half transformation properties, and the logical structure and
probabilities of quantum theory are argued to arise from such acausal spacetimes.
[157] gives the concrete geometry: a class of electrically charged wormholes whose
outer two-sphere is not spanned by a compact co-orientable hypersurface, which can
therefore **display net electric charge from the source-free Maxwell equations**,
extending Sorkin's non-space-orientable construction to spacetimes admitting no
time orientation; the simplest example is spherically symmetric.

It is tempting to read the net charge as the discriminator: an ordinary pair
creation is charge-neutral overall, so a net charge would mark the round trip out.
That reading is wrong, and the article should not use it. On this programme an
ordinary charged particle **is** a non-time-orientable region, and two regions of
opposite twist are exactly a pair. The charge is what makes the far-side region
look like a particle, not what makes it look like something else. [128] and these
two papers are by the same author and are one position, not two.

What [157] does give is quantitative rather than categorical: the charged
non-time-orientable region has a **definite geometry**, spherically symmetric in
the simplest case, with the charge fixed by the topology rather than by a source.
So if there is a discriminator it will be a geometric one, in the field
configuration around the threshold, not a conservation-law one. Bölüm 16.4 should
look there. As matters stand the degeneracy is not broken by anything in the
literature, and the article should say so.

### What this group changes

44. **The crossing direction inside the intermediate region is evanescent, and
    this is already in the corpus.** [84]'s Kleinian slab has $\omega^2/c^2 =
    k_x^2 + k_y^2 - k_z^2 + \mu^2$, so $k_z$ is purely imaginary inside and the
    paper sets $k_z \to ip$, obtaining $|r|^2 + |t|^2 = 1$. The $(2,2)$ and
    $(4,0)$ cells of the grid therefore behave alike in the crossing direction:
    both are tunnelling, not propagation. Everything the barrier literature says
    about thickness applies to both, and the article's finite-thickness
    transmission is an exponentially small amplitude. This should be stated at
    the top of Bölüm 9.4 because it decides which literature is relevant.
45. **The return placement is undetermined in principle unless an allowability
    criterion is adopted.** [139] shows a complex change of time generates
    infinitely many bouncing solutions physically indistinguishable from the
    original over an arbitrarily long interval, and that the Kontsevich-Segal
    condition is what cuts the family down. Our round trip is a bounce and the
    mechanism of [118] is a complex-time construction, so this objection is
    exactly on target. Bölüm 9.4 cannot use the complex lapse without also
    adopting a criterion and demonstrating its configuration satisfies it. [140]
    is the criterion.
46. The criterion is tight, not a formality. [141] finds the saddles sitting on
    the very edge of the allowable domain and the steepest-descent lapse contours
    cut off where they intrude into the non-allowable region. [143] finds that
    the transition most like ours, contracting to expanding through a complex
    region, **violates** allowability and may be unphysical. The article must
    show its configuration is not of that type.
47. There is nevertheless a derived prescription for the lapse contour. [142]:
    the integrand has an **essential singularity at zero lapse, which is where the
    metric degenerates**, that is at our threshold; the contour must not pass
    through zero; and starting from the reduced phase space, with momenta
    integrated first, the contour should pass **below** the origin. This fixes the
    sign of the phase acquired at a crossing, and with two crossings the question
    of whether the two contributions add or cancel becomes a computation the
    article can do. It is also derived rather than postulated, which is what [63]
    says the whole subject lacks.
48. **The thickness of the intermediate region may be unreadable from the
    return, and this is the central new dispute.** [147] finds the Generalized
    Hartman Effect for a **Dirac** particle through **two successive barriers**:
    in the opaque limit the tunnelling time becomes independent of the widths and
    of the separation. Our configuration is two crossings with a region between
    them. If it carries over, every thickness in the grid gives the same return
    offset and question 2 of the skeleton collapses.
49. Three escape routes exist and the article should present all three. [148]
    argues the generalized effect rests on non-rigorous reasoning and that a
    rigorous treatment restores dependence on the separation. [149] shows the
    saturation and the growth belong to **different clocks**: the asymptotic
    group time saturates and reproduces the effect, while the **transmission
    dwell time grows monotonically with the separation** and is the true average
    time spent inside. [150] shows dissipation precludes the effect outright, the
    dwell time increasing with width. The third is the most promising for us,
    because [113]'s matter layer and [89]'s surface source are exactly couplings
    that would make the crossing dissipative, so the liability identified in Group
    10 is what could rescue deliverable (a).
50. **Thickness is recoverable, but only in a clock we cannot read directly.**
    That is the resolution of 48 and 49 together, and it is the honest statement
    for the grid: the dwell time carries the thickness, the group time does not,
    and [149] notes that all transmission times admit only indirect measurement.
    Bölüm 9.4 must say which clock its return placement is expressed in.
51. **The frequency mix is the other thickness readout, and it points the
    opposite way to the delay.** [87] found that the positive/negative frequency
    mixture emerging from a Euclidean region depends only on the **total conformal
    size** of that region and not on the profile of the metric. The delay
    saturates; the frequency content does not. These are not in conflict, they are
    two different observables, and taken together they say deliverable (a) should
    be read off the **frequency mixing** rather than off the delay. That is a
    substantive redirection of the calculation.
52. "Thick" and "unbounded" are one cell, not two. [151] proves that if the
    Hartman effect holds for a unit cell it holds for a periodic repetition, and
    that a sufficiently thick single cell gives the same tunnelling time as the
    whole periodic system for **any** intervening gap. By 50 this collapse is a
    property of the group time only.
53. The exception is resonance. [152]: away from resonance the phase time depends
    on the widths and the separation only exponentially weakly, but near a
    resonance the transmission coefficient and the phase time acquire
    Breit-Wigner denominators, so the placement has structure again. If the
    article wants the return to carry information about the interlude, resonant
    crossing is the regime, and [121]'s temporal Fabry-Perot is where that regime
    has been realised.
54. **The return placement depends on how the packet was prepared, not only on
    its energy.** [145]: non-Gaussian packets with **identical momentum
    densities** have different average arrival delays, controllable through the
    phase of the momentum wave function independently of energy and momentum
    density. So no single number for the return offset is well defined until the
    preparation is specified. This is both a prediction and a constraint on how
    Bölüm 9.4 may state its result.
55. The packet layer of the two-layer model now has machinery. [144] shows the
    distortion of a transmitted packet is fixed by **two time-like parameters
    given by the energy derivative of the complex transmission amplitude**, so
    delay and distortion come from one object, which is exactly the output
    question 5 of the skeleton wants. [146] adds a physical clock read on
    post-selected sub-ensembles through an **asymmetric** barrier, which is our
    case, and treats the saturation in the same framework.
56. **A junction that transmits either carries a matter layer that fails the
    vacuum equations, or a pure double layer that fails the null energy
    condition.** [154] gives the first pure double layer in a gravitational
    theory, a junction whose whole distributional content is a dipole with no thin
    shell, which would meet [113] in its own terms; but it lives in quadratic
    $F(R)$, and by [116] general relativity does not generically support double
    layers. [155] then builds precisely our geometry, an interior reached through
    **two** double-layer shells, and finds the NEC violated in the double layer's
    own stress-energy component, concluding the NEC is very hard to satisfy
    whenever double layers are present. The one opening it leaves is that
    **asymmetric single-layer** configurations do satisfy the NEC, and our two
    crossings are naturally asymmetric.
57. **The pair-creation degeneracy is not broken.** [156] and [157] are by the
    author of [128] and are one position with it: on that programme a charged
    particle **is** a non-time-orientable region and two opposite twists are a
    pair, so the net charge from source-free Maxwell equations does not
    distinguish a round trip from an ordinary pair event. What [157] supplies is a
    definite geometry, spherically symmetric in the simplest case, with the charge
    fixed by topology rather than by a source. If a discriminator exists it will be
    geometric, in the field configuration near the threshold, not a
    conservation-law one. Bölüm 16.4 should say the degeneracy stands.
58. **Item 43's wave-packet gap is amended and priority closed.** There is still
    nothing on wave packets crossing a **signature change** specifically, and that
    remains a real gap. But the barrier-crossing packet literature supplies the
    machinery ([144]), one hard constraint on deliverable (a) ([145]), an
    operational clock for the asymmetric case ([146]), and the whole thickness
    dispute ([147] to [153]). The packet layer of the model is no longer without
    literature; it is without literature **for the signature-changing case**, and
    the transfer of these results to it has to be argued rather than assumed. This
    search is now closed.
