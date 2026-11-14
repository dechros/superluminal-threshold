#ifndef SLM_JOURNEY_TRAVELLER_H
#define SLM_JOURNEY_TRAVELLER_H

#include <array>
#include <string>
#include <vector>

namespace slm
{

    /// One thing sent on a round trip: a massless particle, a single atom, or a
    /// rigid molecule given by the positions of its atoms.
    ///
    /// The mass sets the mass parameter @f$ \mu = (mc/\hbar)^2 @f$ and nothing
    /// else about the trip depends on its digits. The atom positions are
    /// offsets from the molecule's centre in metres; a point particle has none.
    /// The start speed is the one state the particle can be prepared in: rest
    /// for anything with mass, light speed for anything without, since a
    /// massless particle has no rest frame and no other speed.
    struct Traveller
    {
        using Three = std::array<double, 3>;

        std::string name;
        double mass = 0.0;
        std::vector<Three> atoms;
        std::vector<double> radii;

        /// Van der Waals style display radius of each atom in metres, parallel
        /// to @ref atoms; a point particle has none.
        /// The mass parameter in inverse square metres.
        double mu() const;

        /// The speed in units of @c c the traveller starts and ends at: zero
        /// with mass, one without.
        double startSpeed() const;

        /// The crossing angle of the start speed, @f$ \arctan\beta_0 @f$.
        double startAngle() const;

        /// True when the traveller has at least three labelled atoms, so that a
        /// handedness can be read off it.
        bool hasShape() const;

        /// A particle with no mass and no extent.
        static Traveller massless();

        /// A ground-state hydrogen atom, a point with the atom's mass.
        static Traveller hydrogenAtom();

        /// A methane molecule: carbon at the centre and four labelled hydrogens
        /// at the corners of a regular tetrahedron. The labelling is what gives
        /// the shape a handedness; the unlabelled tetrahedron has none.
        static Traveller methane();

        /// A water molecule, bent, three atoms in a plane.
        static Traveller water();

        /// An ammonia molecule, a pyramid of four atoms.
        static Traveller ammonia();

        /// Bromochlorofluoromethane, a carbon with four different neighbours:
        /// chiral without any labelling, so its handedness is its own.
        static Traveller bromochlorofluoromethane();

        /// The three reference travellers the six round trips use: massless,
        /// atom, molecule.
        static std::vector<Traveller> reference();

        /// Every traveller the viewer offers: the reference three and the
        /// other molecules.
        static std::vector<Traveller> all();
    };

}

#endif
