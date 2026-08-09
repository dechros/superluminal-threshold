#include "sim/WavePacketField.h"

#include "intermediate/TwoCrossings.h"

#include <algorithm>
#include <cmath>

namespace slm
{
    namespace
    {
        constexpr double kBandwidths = 5.0;

        double normalWavenumber(double omega, double c, double mu, double transverseSquared)
        {
            const double squared = TwoCrossings::outsideSquared(omega, c, mu, transverseSquared);
            return squared > 0.0 ? std::sqrt(squared) : 0.0;
        }

    }

    double WavePacketField::spectrum(double omega, double centre, double spread)
    {
        const double z = (omega - centre) / spread;
        return std::exp(-0.5 * z * z);
    }

    double WavePacketField::lowestPropagatingFrequency(double c, double mu,
                                                        double transverseSquared)
    {
        return c * std::sqrt(transverseSquared + mu);
    }

    double WavePacketField::transmittedField(double time, double observationPoint,
                                             IntermediateRegion::Kind kind, double c, double mu,
                                             double transverseSquared, double thickness,
                                             double centre, double spread, int samples)
    {
        const double floorFrequency =
            lowestPropagatingFrequency(c, mu, transverseSquared) + 1e-3;
        const double low = std::max(centre - kBandwidths * spread, floorFrequency);
        const double high = centre + kBandwidths * spread;
        const double step = (high - low) / samples;
        std::complex<double> total(0.0, 0.0);
        for (int i = 0; i < samples; ++i)
        {
            const double omega = low + (i + 0.5) * step;
            if (omega <= 0.0)
            {
                continue;
            }
            const double weight = spectrum(omega, centre, spread);
            const std::complex<double> crossing =
                TwoCrossings::amplitude(kind, omega, c, mu, transverseSquared, thickness);
            const double k = normalWavenumber(omega, c, mu, transverseSquared);
            const std::complex<double> travel(0.0, k * observationPoint - omega * time);
            total += weight * crossing * std::exp(travel) * step;
        }
        return total.real();
    }

    WavePacketField::Harmonics WavePacketField::harmonics(
        double observationPoint, IntermediateRegion::Kind kind, double c, double mu,
        double transverseSquared, double thickness, double centre, double spread, int samples,
        bool phaseOnly)
    {
        const double floorFrequency =
            lowestPropagatingFrequency(c, mu, transverseSquared) + 1e-3;
        const double low = std::max(centre - kBandwidths * spread, floorFrequency);
        const double high = centre + kBandwidths * spread;
        const double step = (high - low) / samples;
        Harmonics built;
        built.frequency.reserve(samples);
        built.coefficient.reserve(samples);
        for (int i = 0; i < samples; ++i)
        {
            const double omega = low + (i + 0.5) * step;
            if (omega <= 0.0)
            {
                continue;
            }
            const double weight = spectrum(omega, centre, spread);
            std::complex<double> crossing =
                TwoCrossings::amplitude(kind, omega, c, mu, transverseSquared, thickness);
            if (phaseOnly)
            {
                crossing = std::polar(1.0, std::arg(crossing));
            }
            const double k = normalWavenumber(omega, c, mu, transverseSquared);
            built.frequency.push_back(omega);
            built.coefficient.push_back(weight * crossing *
                                       std::exp(std::complex<double>(0.0, k * observationPoint)) *
                                       step);
        }
        return built;
    }

    WavePacketField::Harmonics WavePacketField::roundTripHarmonics(
        IntermediateRegion::Kind kind, double c, double mu, double transverseSquared,
        double thickness, double centre, double spread, int samples, bool phaseOnly)
    {
        const double floorFrequency =
            lowestPropagatingFrequency(c, mu, transverseSquared) + 1e-3;
        const double low = std::max(centre - kBandwidths * spread, floorFrequency);
        const double high = centre + kBandwidths * spread;
        const double step = (high - low) / samples;
        Harmonics built;
        built.frequency.reserve(samples);
        built.coefficient.reserve(samples);
        for (int i = 0; i < samples; ++i)
        {
            const double omega = low + (i + 0.5) * step;
            if (omega <= 0.0)
            {
                continue;
            }
            const double weight = spectrum(omega, centre, spread);
            std::complex<double> crossing =
                TwoCrossings::amplitude(kind, omega, c, mu, transverseSquared, thickness);
            if (phaseOnly)
            {
                crossing = std::polar(1.0, std::arg(crossing));
            }
            built.frequency.push_back(omega);
            built.coefficient.push_back(weight * crossing * step);
        }
        return built;
    }

    double WavePacketField::envelopeOf(const Harmonics &built, double time)
    {
        std::complex<double> total(0.0, 0.0);
        for (std::size_t i = 0; i < built.frequency.size(); ++i)
        {
            total += built.coefficient[i] *
                     std::exp(std::complex<double>(0.0, -built.frequency[i] * time));
        }
        return std::abs(total);
    }

    double WavePacketField::transmittedEnvelope(double time, double observationPoint,
                                                IntermediateRegion::Kind kind, double c,
                                                double mu, double transverseSquared,
                                                double thickness, double centre, double spread,
                                                int samples, bool phaseOnly)
    {
        const double floorFrequency =
            lowestPropagatingFrequency(c, mu, transverseSquared) + 1e-3;
        const double low = std::max(centre - kBandwidths * spread, floorFrequency);
        const double high = centre + kBandwidths * spread;
        const double step = (high - low) / samples;
        std::complex<double> total(0.0, 0.0);
        for (int i = 0; i < samples; ++i)
        {
            const double omega = low + (i + 0.5) * step;
            if (omega <= 0.0)
            {
                continue;
            }
            const double weight = spectrum(omega, centre, spread);
            std::complex<double> crossing =
                TwoCrossings::amplitude(kind, omega, c, mu, transverseSquared, thickness);
            if (phaseOnly)
            {
                crossing = std::polar(1.0, std::arg(crossing));
            }
            const double k = normalWavenumber(omega, c, mu, transverseSquared);
            const std::complex<double> travel(0.0, k * observationPoint - omega * time);
            total += weight * crossing * std::exp(travel) * step;
        }
        return std::abs(total);
    }

    double WavePacketField::freeEnvelope(double time, double observationPoint, double c,
                                         double mu, double transverseSquared, double centre,
                                         double spread, int samples)
    {
        const double floorFrequency =
            lowestPropagatingFrequency(c, mu, transverseSquared) + 1e-3;
        const double low = std::max(centre - kBandwidths * spread, floorFrequency);
        const double high = centre + kBandwidths * spread;
        const double step = (high - low) / samples;
        std::complex<double> total(0.0, 0.0);
        for (int i = 0; i < samples; ++i)
        {
            const double omega = low + (i + 0.5) * step;
            if (omega <= 0.0)
            {
                continue;
            }
            const double weight = spectrum(omega, centre, spread);
            const double k = normalWavenumber(omega, c, mu, transverseSquared);
            const std::complex<double> travel(0.0, k * observationPoint - omega * time);
            total += weight * std::exp(travel) * step;
        }
        return std::abs(total);
    }

    double WavePacketField::roundTripEnvelope(double time, IntermediateRegion::Kind kind,
                                              double c, double mu, double transverseSquared,
                                              double thickness, double farSideDistance,
                                              int branch, double centre, double spread,
                                              int samples, bool phaseOnly)
    {
        const double floorFrequency =
            lowestPropagatingFrequency(c, mu, transverseSquared) + 1e-3;
        const double low = std::max(centre - kBandwidths * spread, floorFrequency);
        const double high = centre + kBandwidths * spread;
        const double step = (high - low) / samples;
        const double sign = branch > 0 ? 1.0 : -1.0;
        std::complex<double> total(0.0, 0.0);
        for (int i = 0; i < samples; ++i)
        {
            const double omega = low + (i + 0.5) * step;
            if (omega <= 0.0)
            {
                continue;
            }
            const double weight = spectrum(omega, centre, spread);
            std::complex<double> crossing =
                TwoCrossings::amplitude(kind, omega, c, mu, transverseSquared, thickness);
            if (phaseOnly)
            {
                crossing = std::polar(1.0, std::arg(crossing));
            }
            const std::complex<double> farSide(0.0, sign * omega * farSideDistance);
            const std::complex<double> observed(0.0, -omega * time);
            total += weight * crossing * std::exp(farSide) * std::exp(observed) * step;
        }
        return std::abs(total);
    }

}
