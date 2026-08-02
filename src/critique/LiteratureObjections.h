#pragma once

#include "core/Section.h"

#include <string>

namespace slm
{

    /// Every objection the surrounding literature raises against a construction
    /// of this kind, with the verdict on each decided by calling the library
    /// that bears on it.
    ///
    /// The objections collected here are not only those aimed at this
    /// construction. Most of them were raised against signature change, against
    /// superluminal transport, or against many-time dynamics long before any of
    /// this, and they apply here because this construction uses all three. An
    /// account that answered only the objections aimed at itself would be
    /// answering the easy half.
    ///
    /// Four verdicts are used and they are not interchangeable. ANSWERED means
    /// a calculation here shows the objection does not reach this construction,
    /// and the calculation is named. CONCEDED means the objection lands and the
    /// claim it defeats has been withdrawn or narrowed rather than defended.
    /// NARROWED means it lands on part of the ground and the surviving part is
    /// stated. UNTESTED means the objection is real, no calculation here bears
    /// on it, and it is carried openly rather than omitted.
    ///
    /// Nothing in this class states a verdict of its own. Each verdict is the
    /// return value of a call into the library that settles it, so an objection
    /// cannot silently change status when the physics underneath it moves.
    class LiteratureObjections
    {
    public:
        enum class Verdict
        {
            Answered,
            Narrowed,
            Conceded,
            Untested
        };

        static std::string name(Verdict verdict);

        /// That no real transformation carries one signature into the other, so
        /// the whole construction is a relabelling. This lands, and the model
        /// keeps a real mass rather than evading it.
        static Verdict signatureFlipIsNotRealisable();

        /// That the field equations lose their standard conservation laws at a
        /// signature change, so nothing can be tracked across it.
        static Verdict conservationLawsFail();

        /// That the distributional term at the surface is of the form zero over
        /// zero and cannot be dropped by declaration.
        static Verdict rateConditionUnmet();

        /// That the layer such a junction carries cannot satisfy the energy
        /// conditions whatever matter is chosen.
        static Verdict layerViolatesEnergyConditions();

        /// That equations with more than one time direction are ill posed, so
        /// nothing can be predicted from data given on a surface.
        static Verdict manyTimesAreIllPosed();

        /// That extra time directions are unobservable, being pure gauge, so
        /// nothing over there can register here.
        static Verdict extraTimesAreUnobservable();

        /// That a region with more than one time direction admits no consistent
        /// split into future and past.
        static Verdict noTimeOrientationExists();

        /// That a delay which saturates with thickness is not a fast crossing
        /// but a property of a stored field.
        static Verdict saturatingDelayIsNotTransit();

        /// That an advanced peak carries no signal because the front is bounded
        /// by light.
        static Verdict advancedPeakCarriesNoSignal();

        /// That a superluminal excitation would radiate into the vacuum and is
        /// therefore excluded by the observed absence of that radiation.
        static Verdict vacuumCherenkovExcludesIt();

        /// That a quantum field theory of superluminal excitations has no
        /// dynamics, its commutator function vanishing identically.
        static Verdict superluminalFieldTheoryIsEmpty();

        /// That transformations of this kind make the evolution indeterministic,
        /// since the state after does not fix the state before.
        static Verdict transformationsGiveIndeterminism();

        /// That a boundary condition at the surface has to be chosen by hand
        /// and the results depend on which is chosen.
        static Verdict boundaryChoiceIsArbitrary();

        /// That the complex-time construction is arbitrary without a criterion
        /// saying which continuations are allowed.
        static Verdict complexTimeIsArbitrary();

        /// That the distributional form of the field equations is not unique,
        /// which both sides of the published exchange concede.
        static Verdict distributionalFormIsNotUnique();

        /// Number of objections carrying a given verdict.
        static int countWith(Verdict verdict);

        /// Total number of objections registered.
        static int totalCount();

        /// Whether the answered ones outnumber the rest, which would indicate
        /// an account written to win rather than to record.
        static bool answersOutnumberTheRest();
    };

    /// Section stating the verdict on every objection in the register.
    class LiteratureObjectionsSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Every objection the literature raises, and the verdict on each";
        }
        void run(Report &report) const override;
    };

}
