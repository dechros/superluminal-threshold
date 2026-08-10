#pragma once

#include "core/Section.h"

#include <string>

namespace slm
{

    /// The journey written in kilograms, metres and seconds.
    ///
    /// Every other library here works in units where the speed of light is one,
    /// which is right for the algebra and useless for asking whether a thing can
    /// be done. This class carries the constants and the one conversion that
    /// turn the geometric statements into laboratory ones, and it carries
    /// nothing else.
    ///
    /// The conversion is the exchange rate between distance travelled on the
    /// far side and time recovered on the near side. In geometric units they
    /// are the same number, which hides the size of the bill. In metres and
    /// seconds one second of recovered time costs the light travel distance of
    /// one second, so the rate is the speed of light and the bill is large.
    class PhysicalScales
    {
    public:
        static double lightSpeed();
        static double reducedPlanck();
        static double elementaryCharge();
        static double electronMass();
        static double protonMass();

        /// Ground-state binding energy of hydrogen, in joules. A fixed
        /// textbook constant, not something this project derives.
        static double hydrogenBindingEnergyJoules();

        /// Rest mass of a ground-state hydrogen atom: the proton and the
        /// electron, less the mass equivalent of the energy that binds them.
        static double hydrogenAtomMass();

        /// Far-side distance in metres that buys the given time advance in
        /// seconds. The exchange rate is the speed of light.
        static double distanceForAdvance(double seconds);

        /// Time advance in seconds bought by the given far-side distance in
        /// metres.
        static double advanceForDistance(double metres);
    };

    /// Section reporting the journey in laboratory units.
    class PhysicalScalesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The journey in kilograms, metres and seconds";
        }
        void run(Report &report) const override;
    };

}
