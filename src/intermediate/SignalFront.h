#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

namespace slm
{

    /// The front of a signal as distinct from its peak, and which of the two an
    /// advance belongs to.
    ///
    /// An advanced peak is the standard objection to every claim that something
    /// crossed a barrier faster than light, and the objection is a good one. A
    /// region that transmits some modes better than others reshapes the packet:
    /// the part of the incoming wave that arrives first is attenuated least, so
    /// the outgoing peak is built mostly from what was already the leading edge.
    /// The peak then appears earlier than the incoming peak would predict
    /// without anything having overtaken it. Nothing was sent ahead; a shape was
    /// rebuilt from a piece that was already there.
    ///
    /// The quantity that decides whether information moved is not the peak but
    /// the front, the first disturbance of any size at all. Its speed is set by
    /// the behaviour of the dispersion at unbounded frequency, where every
    /// medium becomes transparent and every mass term becomes negligible, and it
    /// is therefore the same for every region built here regardless of what the
    /// region does at finite frequency.
    ///
    /// These functions compute the phase speed at finite frequency, which
    /// exceeds the speed of light for any massive field and always has, the
    /// limit that the front takes, and the size of the transmitted amplitude
    /// that an advanced peak is carried on.
    class SignalFront
    {
    public:
        /// Speed at which a single frequency carries its phase, which for a
        /// massive field exceeds the speed of light at every finite frequency
        /// without carrying anything.
        static double phaseSpeed(double omega, double c, double mu, double transverseSquared);

        /// Speed at which the energy of a single frequency moves, which stays
        /// below the speed of light.
        static double groupSpeed(double omega, double c, double mu, double transverseSquared);

        /// Phase speed evaluated at a frequency high enough to stand for the
        /// limit, which is what the front travels at.
        static double frontSpeed(double c, double mu, double transverseSquared, double omega);

        /// How far the phase speed at the given frequency still sits above the
        /// limit, in units of the speed of light.
        static double frontExcess(double omega, double c, double mu, double transverseSquared);

        /// Delay the region imposes at a frequency high enough to be above any
        /// barrier, which is the delay the front suffers.
        static double frontDelay(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                 double transverseSquared, double thickness);

        /// Magnitude of the transmitted amplitude, which is what an advanced
        /// peak is carried on and which the barrier drives towards zero.
        static double transmittedMagnitude(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared, double thickness);

        /// Whether the front arrives no earlier than light would, which is the
        /// statement that has to hold for the construction to be consistent.
        static bool frontRespectsLight(IntermediateRegion::Kind kind, double c, double mu,
                                       double transverseSquared, double thickness,
                                       double probeOmega);

        /// Whether an advance of the peak can carry a signal, which it cannot
        /// while the front is bounded by light.
        static bool advanceCarriesSignal(IntermediateRegion::Kind kind, double c, double mu,
                                         double transverseSquared, double thickness,
                                         double probeOmega);
    };

    /// Section separating the front of a signal from its peak.
    class SignalFrontSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The front against the peak, and which of them an advance belongs to";
        }
        void run(Report &report) const override;
    };

}
