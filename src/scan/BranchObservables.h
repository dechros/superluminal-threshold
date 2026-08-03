#pragma once

#include "core/Section.h"

namespace slm
{

    /// Whether anything computed here can tell the two families of crossing
    /// apart.
    ///
    /// The admissible crossings split into two families of four, one sending a
    /// given far-side displacement to a later moment here and one to an earlier
    /// moment. The transformation relating them reverses our time axis and the
    /// far side's distinguished axis together, is an isometry of both metrics
    /// and has unit determinant, so the metric does not choose between them.
    /// That much is settled elsewhere. It leaves the sharper question: is there
    /// any quantity at all, computed anywhere in these libraries, that comes out
    /// differently on the two families?
    ///
    /// If there is, the choice is not free after all and that quantity is where
    /// it is made. If there is not, the degeneracy is exact within everything
    /// built here, which is a stronger and more useful statement than the metric
    /// result on its own, because it says what would have to be added rather
    /// than only what is missing.
    ///
    /// The two published constructions that bear on this both concern a
    /// different reversal. One detects a time non-orientable topology through an
    /// inversion pattern in the vacuum fluctuations a charged particle
    /// experiences; the other builds a bundle over a time-reversing region and
    /// gets an apparent charge on its boundary. Both address a pure reversal of
    /// time. The reversal here is joint, and a quantity odd under one of the two
    /// axes alone is even under the pair, so neither construction transfers
    /// without being redone. That is the gap this class measures rather than
    /// argues.
    class BranchObservables
    {
    public:
        /// Sign the transformation gives our time slot.
        static double timeSign();

        /// Sign it gives the far side's distinguished axis.
        static double distinguishedSign();

        /// Whether a quantity odd in our time alone changes under the joint
        /// reversal, which it does.
        static bool oddInTimeAloneChanges();

        /// Whether a quantity odd in the distinguished axis alone changes,
        /// which it does.
        static bool oddInDistinguishedAloneChanges();

        /// Whether a quantity odd in both together changes, which it does not,
        /// and which is the whole difficulty.
        static bool oddInBothChanges();

        /// Coefficient the dictionary gives, which carries the sign and is
        /// therefore the one quantity that does differ.
        static double dictionaryCoefficient(int family);

        /// Arrival moment on each family, at a given delay and far-side
        /// distance.
        static double arrivalMoment(int family, double delay, double distance);

        /// Whether the arrival moment differs between the families, which it
        /// does, and which is why the question matters at all.
        static bool arrivalDiffers(double delay, double distance);

        /// Transmitted weight on each family, which is built from squared
        /// wavenumbers and is therefore blind to the sign.
        static double transmittedWeight(int family, double normalPart, double transversePart,
                                        double thickness);

        /// Whether the transmitted weight differs, which it does not.
        static bool weightDiffers(double normalPart, double transversePart, double thickness);

        /// Layer strength on each family, which is built from the profile and
        /// is likewise blind.
        static double layerStrength(int family, double thickness);

        /// Whether the layer strength differs, which it does not.
        static bool layerDiffers(double thickness);

        /// Returned entropy on each family.
        static double returnedEntropy(int family, double thickness);

        /// Whether the returned entropy differs, which it does not.
        static bool entropyDiffers(double thickness);

        /// How many observables the sweep tests at all, which is what a caller
        /// asking how much of the far side is visible at its faces should use
        /// rather than writing the number down again.
        static int sweptObservableCount();

        /// How many of the observables tested come out differently on the two
        /// families, counting only those that are not the arrival moment
        /// itself, since that one differs by construction.
        static int discriminatingObservableCount();
    };

    /// Section sweeping the computed observables for one that separates the two
    /// families of crossing.
    class BranchObservablesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "Is there any computed quantity that tells the two families apart";
        }
        void run(Report &report) const override;
    };

}
