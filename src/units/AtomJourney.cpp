#include "units/AtomJourney.h"

#include "core/Report.h"
#include "units/PhysicalScales.h"
#include "units/ProtonJourney.h"

#include <cmath>
#include <format>

namespace slm
{
    namespace
    {
        constexpr double kDrive = 1.5e24;
        constexpr double kOpacity = 10.0;
        constexpr double kFarSideMetres = 0.3;
    }

    void AtomJourneySection::run(Report &report) const
    {
        const double protonMass = PhysicalScales::protonMass();
        const double electronMass = PhysicalScales::electronMass();
        const double hydrogenMass = PhysicalScales::hydrogenAtomMass();
        const double bindingMass = PhysicalScales::hydrogenBindingEnergyJoules() /
                                   (PhysicalScales::lightSpeed() * PhysicalScales::lightSpeed());

        report.subsection("The bound state's rest mass against its two free parts");
        report.check(std::format("  proton {:.6e} kg, electron {:.6e} kg, binding energy removes "
                                 "{:.6e} kg", protonMass, electronMass, bindingMass),
                    bindingMass > 0.0 && bindingMass < electronMass);
        report.checkNear("  the atom's mass is the sum of its parts less the binding mass, to "
                        "machine precision",
                        hydrogenMass - (protonMass + electronMass - bindingMass));
        const double electronShare = electronMass / protonMass;
        const double bindingShare = bindingMass / protonMass;
        report.check(std::format("  against the bare proton, the electron adds a relative {:.4e}, "
                                 "the binding energy removes a relative {:.4e}, four orders of "
                                 "magnitude smaller",
                                 electronShare, bindingShare),
                    bindingShare < 1e-4 * electronShare);

        report.subsection("The mass ceiling, bare proton against bound atom");
        const double protonFloor = ProtonJourney::lowestDriveForProton();
        const double hydrogenFloor = PhysicalScales::frequencyNeededFor(hydrogenMass);
        report.check(std::format("  the proton's floor is {:.4e} rad/s, the hydrogen atom's is "
                                 "{:.4e} rad/s, higher by very nearly the electron's mass share",
                                 protonFloor, hydrogenFloor),
                    hydrogenFloor > protonFloor);
        report.checkNear("  the floor's fractional rise matches the electron's mass share, to one "
                        "part in ten thousand",
                        (hydrogenFloor / protonFloor - 1.0) / electronShare - 1.0, 1e-4);
        report.check(std::format("  the drive used throughout this project, {:.4e} rad/s, clears "
                                 "both floors", kDrive),
                    PhysicalScales::driveCanCarry(kDrive, protonMass) &&
                        PhysicalScales::driveCanCarry(kDrive, hydrogenMass));

        report.subsection("What the journey looks like once the floor is cleared");
        const ProtonJourney::Record record = ProtonJourney::journey(kDrive, kFarSideMetres, kOpacity);
        report.check(std::format("  debt {:.4e} s, arrival {:.4e} s relative to departure",
                                 record.debtSeconds, record.arrivalSeconds),
                    record.arrivalSeconds < 0.0);
        report.check("ProtonJourney::journey takes a drive frequency and a distance, and no mass "
                    "argument at all, so this same record is the hydrogen atom's record as well as "
                    "the bare proton's: once a traveller clears its own floor, the crossing debt, "
                    "the break-even distance and the arrival time depend on the drive and the "
                    "distance alone",
                    true);

        report.subsection("What this does and does not show about the bound state itself");
        report.check("the mass ceiling is the one and only place a traveller's composition enters "
                    "this project's arithmetic; past that gate the object is carried as a single "
                    "rest mass and nothing else about it is read",
                    true);
        report.check("so this section establishes that a hydrogen atom can clear the floor and "
                    "share the proton's arrival time, and it does not establish that the returned "
                    "atom keeps its electron bound, because no calculation here represents the "
                    "electron-proton relative coordinate to begin with",
                    true);
        report.check("nor does it say what a three-dimensional bound structure becomes in region "
                    "II, where position narrows to the single axis r (section 11.5): this project "
                    "has no dynamics for a relative coordinate in a region of one space axis and "
                    "three time axes, and none is asserted here",
                    true);
    }

}
