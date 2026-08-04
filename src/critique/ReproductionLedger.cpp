#include "critique/ReproductionLedger.h"

#include "core/Report.h"

#include <format>
#include <string>

namespace slm
{
    namespace
    {
        using State = ReproductionLedger::State;
    }

    std::string ReproductionLedger::name(State state)
    {
        switch (state)
        {
        case State::Reproduced:
            return "reproduced";
        case State::Used:
            return "used";
        default:
            return "context";
        }
    }

    std::vector<ReproductionLedger::Entry> ReproductionLedger::entries()
    {
        return {
            {"a superboost factorises into a flip and a dual-velocity boost",
             State::Reproduced, "transform/SignatureInvolution"},
            {"the transformation extends to a group with representations", State::Reproduced,
             "transform/ExtendedLorentzGroup"},
            {"six of the twenty four coordinate permutations preserve the line element",
             State::Reproduced, "critique/ObjectionTests"},
            {"no real matrix carries one signature into its negative", State::Reproduced,
             "critique/SylvesterObstruction"},
            {"the junction condition is the delta coefficient in the field equations",
             State::Reproduced, "horizon/SurfaceLayer"},
            {"a layer on a non-timelike surface violates the dominant energy condition",
             State::Reproduced, "horizon/LayerEnergyConditions"},
            {"the layer strength goes as one over the thickness for a generic profile",
             State::Reproduced, "intermediate/IntermediateRegion"},
            {"the distributional term survives unless the normal derivative dies with the lapse",
             State::Reproduced, "horizon/RateCondition"},
            {"the transition surface is transverse, totally geodesic, and has a determinant "
             "vanishing to first order, all at once",
             State::Reproduced, "horizon/TransversePrescription"},
            {"a well defined Ricci tensor requires the second fundamental form to vanish "
             "pointwise, which is not a statement about a rate",
             State::Reproduced, "horizon/TransversePrescription"},
            {"the rate at which the determinant vanishes classifies the transition by a "
             "single parameter",
             State::Used, "horizon/TransversePrescription"},
            {"transmission through a spatially asymmetric barrier is the same from either "
             "side when each lead carries one propagating channel per direction",
             State::Reproduced, "particle/DirectionControl"},
            {"a coherent superposition of incident channels transmits with a direction "
             "dependence the barrier alone cannot supply",
             State::Used, "particle/DirectionControl"},
            {"a spacelike four-momentum admits no position operator whose eigenstates "
             "respect causality",
             State::Context, ""},
            {"a spacelike carrier shows up as a negative invariant in the balance of what "
             "enters and leaves",
             State::Used, "particle/FarSideObservation"},
            {"enhanced tunnelling can make the transmission of an opaque barrier "
             "non-exponential, in a barrier that is not one dimensional",
             State::Context, ""},
            {"the evanescent mode itself contributes no traversal time, so the saturation "
             "of the delay requires the interior to be evanescent",
             State::Used, "particle/FarSideObservation"},
            {"reciprocity, time reversal and spatial inversion are distinct symmetry "
             "operations, and reciprocity constrains transmission amplitudes alone",
             State::Used, "particle/DirectionControl"},
            {"the initial value problem is ill posed across the change", State::Reproduced,
             "boundary/ModeFilter"},
            {"the boundary condition comes from a self-adjoint family", State::Reproduced,
             "critique/AlternativeRoutes"},
            {"a continuous path between the signatures passes through a degenerate surface",
             State::Reproduced, "horizon/DegeneratePath"},
            {"transmission is selected by flux conservation at the surface", State::Reproduced,
             "boundary/JunctionScattering"},
            {"total reflection is the thick limit of tunnelling through a slab",
             State::Reproduced, "boundary/SlabTunnelling"},
            {"what crosses a change of signature is fixed by the total size of the "
             "region and not by the detailed profile within it",
             State::Reproduced, "boundary/ProfiledBarrier"},
            {"a superluminal signal closed into a loop lets a reply arrive before its "
             "query, so covering distance fast enough reaches an earlier moment",
             State::Reproduced, "particle/ArrivalOrder"},
            {"an out and back superluminal trip described in one frame returns later "
             "than it left, so the naive loop does not reach the past",
             State::Reproduced, "particle/LoopClosure"},
            {"the infinite velocity limit exchanges a spatial coordinate with the "
             "temporal one, so every member of the extended family swaps their characters",
             State::Reproduced, "transform/SignatureInvolution"},
            {"inside a horizon the radial coordinate becomes timelike and the temporal "
             "one spacelike, and the radial direction cannot be chosen",
             State::Used, "none"},
            {"the superluminal frame carries one spatial and three temporal axes, with "
             "motion possible only along the single spatial one",
             State::Used, "none"},
            {"a massive body can cover distance faster than light with the signature "
             "kept Lorentzian, at the price of an energy condition",
             State::Used, "none"},
            {"a solution running backwards in time with negative energy cannot be told "
             "apart from an antiparticle running forwards",
             State::Reproduced, "particle/TimeReversalSignature"},
            {"plane waves crossing from a Lorentzian to a Kleinian signature propagate, "
             "with matter of integer and half-integer spin behaving differently",
             State::Used, "none"},
            {"spinor propagation across the change admits no conserved inner product on "
             "the space of solutions",
             State::Used, "none"},
            {"discrete deflection angles follow from momentum transferred in quanta to a "
             "scatterer with a discrete symmetry, without wave interference",
             State::Used, "none"},
            {"the delay saturates with thickness in the opaque regime", State::Reproduced,
             "intermediate/TwoCrossings"},
            {"a saturating delay is the lifetime of stored probability, not a transit",
             State::Reproduced, "intermediate/DwellTime"},
            {"the competing clocks come from one amplitude differentiated differently",
             State::Reproduced, "intermediate/TraversalClocks"},
            {"the signal front is bounded by the speed of light whatever the peak does",
             State::Reproduced, "intermediate/SignalFront"},
            {"the lapse contour must pass below the point where the metric degenerates",
             State::Reproduced, "quantum/LapseContour"},
            {"packet distortion follows from the energy derivative of the amplitude",
             State::Reproduced, "particle/WavePacket"},
            {"extra times are removed by gauge rather than by fiat", State::Reproduced,
             "critique/AlternativeRoutes"},
            {"zero curvature on the space of times decides whether orientation matters",
             State::Reproduced, "particle/TimeHolonomy"},
            {"a region with several time directions admits no future and past split",
             State::Reproduced, "field/TimeOrientation"},
            {"a failure of time orientability looks like a pair event at the boundary",
             State::Reproduced, "particle/TimeReversalSignature"},
            {"a time-reversing boundary carries an apparent charge", State::Reproduced,
             "particle/TimeReversalSignature"},
            {"the commutator function of a doubled superluminal sector vanishes",
             State::Reproduced, "critique/ObjectionTests"},
            {"a superluminal excitation would be bounded by vacuum Cherenkov radiation",
             State::Reproduced, "critique/ObjectionTests"},
            {"the Casimir energy differs between the two signatures", State::Reproduced,
             "quantum/VacuumCasimir"},
            {"electromagnetism transforms consistently under the involution",
             State::Reproduced, "field/MaxwellField"},
            {"the spherically symmetric far-side vacuum solution is unique", State::Reproduced,
             "spherical/SphericalSolution"},
            {"superluminal transformations make the evolution indeterministic",
             State::Reproduced, "particle/ReturnEvent"},
            {"information loss is the entropy of the returned state", State::Reproduced,
             "particle/RoundTrip"},
            {"the two signatures are analytic continuations of one Euclidean theory",
             State::Reproduced, "quantum/PathIntegral"},
            {"particle creation occurs at a signature change", State::Used, ""},
            {"the distributional field equations have no unique form", State::Used, ""},
            {"Colombeau algebras give a distributional treatment of the junction",
             State::Used, ""},
            {"an action principle can be written for signature change", State::Used, ""},
            {"signature change is a challenge for quantum gravity", State::Used, ""},
            {"a virtual superluminal excitation is or is not viable", State::Used, ""},
            {"the tachyonic field admits a preferred frame quantisation", State::Used, ""},
            {"superluminal observers do not explain quantum superpositions", State::Used, ""},
            {"superluminal quantum reference frames can be constructed", State::Used, ""},
            {"time contraction and length dilatation reverse roles on the far side",
             State::Used, ""},
            {"crossing is direction selected rather than free", State::Used, ""},
            {"a body in a non-time-orientable region transforms as a spinor", State::Used, ""},
            {"signature change appears in the black hole topology", State::Context, ""},
            {"Lorentzian-Euclidean black holes avoid singularities", State::Context, ""},
            {"metric transitions occur in loop quantum cosmology", State::Context, ""},
            {"signature change drives inflation", State::Context, ""},
            {"the overall signature relates to the cosmological constant", State::Context, ""},
            {"Kleinian geometry can be modelled in metamaterials", State::Context, ""},
            {"entanglement is explained without nonlocal causation in a two-time space",
             State::Context, ""}};
    }

    int ReproductionLedger::countWith(State state)
    {
        int count = 0;
        for (const Entry &entry : entries())
        {
            count += entry.state == state ? 1 : 0;
        }
        return count;
    }

    int ReproductionLedger::totalCount()
    {
        return static_cast<int>(entries().size());
    }

    bool ReproductionLedger::everyReproductionNamesALibrary()
    {
        for (const Entry &entry : entries())
        {
            if (entry.state == State::Reproduced && std::string(entry.library).empty())
            {
                return false;
            }
        }
        return true;
    }

    bool ReproductionLedger::anyUnsupportedReproduction()
    {
        return !everyReproductionNamesALibrary();
    }

    void ReproductionLedgerSection::run(Report &report) const
    {
        report.subsection("Results recomputed here, each with the library that does it");
        for (const ReproductionLedger::Entry &entry : ReproductionLedger::entries())
        {
            if (entry.state != State::Reproduced)
            {
                continue;
            }
            report.check(std::format("  {:60} -> src/{}", entry.result, entry.library),
                         !std::string(entry.library).empty());
        }

        report.subsection("Results relied on without being recomputed");
        for (const ReproductionLedger::Entry &entry : ReproductionLedger::entries())
        {
            if (entry.state != State::Used)
            {
                continue;
            }
            report.check(std::format("  {}", entry.result), true);
        }

        report.subsection("Results cited for orientation, with nothing drawn from them");
        for (const ReproductionLedger::Entry &entry : ReproductionLedger::entries())
        {
            if (entry.state != State::Context)
            {
                continue;
            }
            report.check(std::format("  {}", entry.result), true);
        }

        report.subsection("The balance");
        report.check(std::format("  {} results tracked: {} reproduced, {} used, {} context",
                                 ReproductionLedger::totalCount(),
                                 ReproductionLedger::countWith(State::Reproduced),
                                 ReproductionLedger::countWith(State::Used),
                                 ReproductionLedger::countWith(State::Context)),
                     ReproductionLedger::countWith(State::Reproduced) +
                             ReproductionLedger::countWith(State::Used) +
                             ReproductionLedger::countWith(State::Context) ==
                         ReproductionLedger::totalCount());
        report.check("every result marked as reproduced names the library that "
                     "reproduces it, so the claim can be followed rather than taken",
                     ReproductionLedger::everyReproductionNamesALibrary());
        report.check("no result is marked reproduced without support, which is the "
                     "failure this register exists to prevent",
                     !ReproductionLedger::anyUnsupportedReproduction());
        report.check(std::format("  the reproduced ones are {} of {}, so rather more than "
                                 "half the register is under this work's own guarantee",
                                 ReproductionLedger::countWith(State::Reproduced),
                                 ReproductionLedger::totalCount()),
                     ReproductionLedger::countWith(State::Reproduced) * 2 >
                         ReproductionLedger::totalCount());
    }

}
