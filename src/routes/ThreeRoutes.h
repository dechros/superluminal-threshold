#pragma once

#include "core/Section.h"
#include "intermediate/IntermediateRegion.h"

#include <string>
#include <vector>

namespace slm
{

    /// The same round trip set up three times over, from the point body, from
    /// the wave, and from the amplitude, so that the three can be made to
    /// disagree in public rather than in private.
    ///
    /// Each description supplies its own reading of how long the region detains
    /// the state. The point body divides a length by a speed. The wave
    /// differentiates a phase with respect to frequency. The amplitude divides
    /// a stored norm by an incident flux. In a transparent region these
    /// coincide and the choice among them is idle. In an opaque one they do
    /// not, and which of them answers a given question has to be settled rather
    /// than assumed.
    ///
    /// The question settled here is narrow and is the only one the round trip
    /// needs: which reading places the returning state on the near-side time
    /// axis. That is decided by comparing each reading against the peak of a
    /// propagated packet, which is an independent measurement and is not a
    /// reading at all. Exactly one of the three survives the comparison. The
    /// other two are not thereby wrong; they answer questions about residence
    /// and about the forbidden interior, and reporting them as candidate
    /// arrival times is the confusion this class exists to prevent.
    ///
    /// The readings are also compared for whether each stops growing with
    /// thickness, because a reading that saturates and a reading that does not
    /// cannot both be a transit time across that thickness.
    class ThreeRoutes
    {
    public:
        enum class Route
        {
            PointBody, ///< a length divided by a speed built from the interior wavenumber
            Wave,      ///< the frequency derivative of the transmitted phase
            Amplitude  ///< the stored norm divided by the incident flux
        };

        static std::vector<Route> all();

        static std::string name(Route route);

        /// What the route divides by what, in one clause.
        static std::string construction(Route route);

        /// The route's reading of the time the region detains the state, for a
        /// single traversal.
        static double reading(Route route, IntermediateRegion::Kind kind, double omega, double c,
                              double mu, double transverseSquared, double thickness);

        /// The round trip reading, which is twice the single traversal.
        static double roundTripReading(Route route, IntermediateRegion::Kind kind, double omega,
                                       double c, double mu, double transverseSquared,
                                       double thickness);

        /// Far-side distance the route says brings the state home exactly when
        /// it left, which is that route's threshold.
        static double thresholdFromRoute(Route route, IntermediateRegion::Kind kind, double omega,
                                         double c, double mu, double transverseSquared,
                                         double thickness);

        /// Relative difference between the route's threshold and the one the
        /// propagated packet measures. The measurement is not any of the three
        /// readings, so this comparison can fail for all of them.
        static double departureFromMeasurement(Route route, IntermediateRegion::Kind kind,
                                               double c, double mu, double transverseSquared,
                                               double thickness, double centre, double spread,
                                               int samples);

        /// Whether the route's threshold is the measured one to the given
        /// relative tolerance.
        static bool reproducesMeasurement(Route route, IntermediateRegion::Kind kind, double c,
                                          double mu, double transverseSquared, double thickness,
                                          double centre, double spread, int samples,
                                          double tolerance);

        /// How many of the three reproduce the measurement.
        static int reproducingCount(IntermediateRegion::Kind kind, double c, double mu,
                                    double transverseSquared, double thickness, double centre,
                                    double spread, int samples, double tolerance);

        /// Whether the route's reading stops growing when the region thickens.
        static bool saturates(Route route, IntermediateRegion::Kind kind, double omega, double c,
                              double mu, double transverseSquared);

        /// Whether any two routes disagree on the reading at the given
        /// configuration, which is what makes the choice among them matter.
        static bool routesDisagree(IntermediateRegion::Kind kind, double omega, double c, double mu,
                                   double transverseSquared, double thickness, double tolerance);

        /// Moment the state returns, measured from its departure, as the given
        /// description places it after the given far-side distance. Negative
        /// means it is back before it left. The description enters through its
        /// reading of the round trip and nothing else.
        static double returnMoment(Route route, IntermediateRegion::Kind kind, double omega,
                                   double c, double mu, double transverseSquared, double thickness,
                                   double farSideDistance);

        /// Whether that moment falls before the departure.
        static bool arrivesEarlier(Route route, IntermediateRegion::Kind kind, double omega,
                                   double c, double mu, double transverseSquared, double thickness,
                                   double farSideDistance);

        /// Smallest far-side distance for which EVERY description places the
        /// return before the departure, which is the largest of the three
        /// round trip readings.
        ///
        /// This is the number that decides whether the conclusion is an
        /// artefact of choosing a clock. Below it the descriptions disagree
        /// about the sign, and a reader is entitled to ask which clock was
        /// picked and why. Above it they do not disagree, and the conclusion
        /// survives the most conservative reading on offer rather than
        /// resting on the most favourable one.
        static double distanceForUnanimousAdvance(IntermediateRegion::Kind kind, double omega,
                                                  double c, double mu, double transverseSquared,
                                                  double thickness);

        /// Which description is the most conservative here, that is the one
        /// demanding the greatest distance.
        static Route mostConservativeRoute(IntermediateRegion::Kind kind, double omega, double c,
                                           double mu, double transverseSquared, double thickness);
    };

    /// Section running the round trip from all three descriptions.
    class ThreeRoutesSection : public Section
    {
    public:
        std::string title() const override
        {
            return "The same journey from the point body, the wave, and the amplitude";
        }
        void run(Report &report) const override;
    };

}
