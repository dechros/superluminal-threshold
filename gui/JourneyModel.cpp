#include "JourneyModel.h"

#include "physics/units/PhysicalScales.h"

#include <QVector3D>

#include <algorithm>
#include <cmath>

namespace slm::gui
{
    namespace
    {
        constexpr int kFrameMilliseconds = 16;
        constexpr double kAngstrom = 1e-10;
    }

    JourneyModel::JourneyModel(QObject *parent)
        : QObject(parent),
          travellers_(Traveller::all()),
          settings_(RoundTrip::referenceSettings())
    {
        timer_.setInterval(kFrameMilliseconds);
        connect(&timer_, &QTimer::timeout, this, [this] {
            const double step = kFrameMilliseconds / 1000.0 / secondsPerTrip_;
            setProgress(progress_ + step);
            if (progress_ >= 1.0)
            {
                pause();
                emit finished();
            }
        });
        resample();
    }

    const Traveller &JourneyModel::traveller() const
    {
        return travellers_[static_cast<std::size_t>(travellerIndex_)];
    }

    RoundTrip::Sense JourneyModel::sense() const
    {
        return senseIndex_ == 0 ? RoundTrip::Sense::PlusR : RoundTrip::Sense::MinusR;
    }

    void JourneyModel::resample()
    {
        sample_ = JourneyState::at(traveller(), sense(), settings_, progress_);
        emit sampleChanged();
    }

    int JourneyModel::travellerIndex() const { return travellerIndex_; }

    void JourneyModel::setTravellerIndex(int index)
    {
        const int clamped = std::clamp(index, 0, static_cast<int>(travellers_.size()) - 1);
        if (clamped == travellerIndex_)
        {
            return;
        }
        travellerIndex_ = clamped;
        emit inputChanged();
        resample();
    }

    int JourneyModel::senseIndex() const { return senseIndex_; }

    void JourneyModel::setSenseIndex(int index)
    {
        const int clamped = std::clamp(index, 0, 1);
        if (clamped == senseIndex_)
        {
            return;
        }
        senseIndex_ = clamped;
        emit inputChanged();
        resample();
    }

    double JourneyModel::progress() const { return progress_; }

    void JourneyModel::setProgress(double progress)
    {
        progress_ = std::clamp(progress, 0.0, 1.0);
        resample();
    }

    bool JourneyModel::playing() const { return timer_.isActive(); }

    double JourneyModel::farDistance() const { return settings_.farDistance; }

    void JourneyModel::setFarDistance(double metres)
    {
        if (metres <= 0.0 || metres == settings_.farDistance)
        {
            return;
        }
        settings_.farDistance = metres;
        emit inputChanged();
        resample();
    }

    QString JourneyModel::travellerName() const { return QString::fromStdString(traveller().name); }

    QString JourneyModel::senseName() const
    {
        return senseIndex_ == 0 ? QStringLiteral("+r, backward in time")
                                : QStringLiteral("-r, forward in time");
    }

    QString JourneyModel::phaseName() const
    {
        return QString::fromStdString(JourneyState::name(sample_.phase));
    }

    int JourneyModel::phaseIndex() const
    {
        const auto list = JourneyState::phases(traveller());
        const auto it = std::ranges::find(list, sample_.phase);
        return static_cast<int>(std::distance(list.begin(), it));
    }

    int JourneyModel::phaseCount() const
    {
        return static_cast<int>(JourneyState::phases(traveller()).size());
    }

    double JourneyModel::theta() const { return sample_.theta; }
    double JourneyModel::beta() const { return sample_.beta; }
    double JourneyModel::metricScale() const { return sample_.metricScale; }
    double JourneyModel::clockRate() const { return sample_.clockRate; }
    double JourneyModel::momentum() const { return sample_.momentum; }
    double JourneyModel::mu() const { return traveller().mu(); }
    double JourneyModel::r() const { return sample_.r; }
    double JourneyModel::nearClockShiftNs() const { return sample_.nearClockShift * 1e9; }

    double JourneyModel::finalShiftNs() const
    {
        return RoundTrip::run(traveller(), sense(), settings_).mapShift * 1e9;
    }

    double JourneyModel::thresholdMomentum() const
    {
        return RoundTrip::run(traveller(), sense(), settings_).thresholdMomentum;
    }

    QVariantList JourneyModel::metric() const
    {
        QVariantList list;
        for (double entry : sample_.metric)
        {
            list.push_back(entry);
        }
        return list;
    }

    QVariantList JourneyModel::nearAtoms() const
    {
        QVariantList list;
        for (const auto &atom : sample_.nearAtoms)
        {
            list.push_back(QVector3D(static_cast<float>(atom[0] / kAngstrom),
                                     static_cast<float>(atom[1] / kAngstrom),
                                     static_cast<float>(atom[2] / kAngstrom)));
        }
        return list;
    }

    QVariantList JourneyModel::farAtoms() const
    {
        QVariantList list;
        for (const auto &atom : sample_.farAtoms)
        {
            list.push_back(QVector3D(static_cast<float>(atom[0] / kAngstrom),
                                     static_cast<float>(atom[1] / kAngstrom),
                                     static_cast<float>(atom[2] / kAngstrom)));
        }
        return list;
    }

    QVariantList JourneyModel::atomRadii() const
    {
        QVariantList list;
        for (double radius : traveller().radii)
        {
            list.push_back(radius / kAngstrom);
        }
        return list;
    }

    QStringList JourneyModel::travellerNames() const
    {
        QStringList names;
        for (const Traveller &t : travellers_)
        {
            names.push_back(QString::fromStdString(t.name));
        }
        return names;
    }

    double JourneyModel::secondsPerTrip() const { return secondsPerTrip_; }

    void JourneyModel::setSecondsPerTrip(double seconds)
    {
        if (seconds > 0.0)
        {
            secondsPerTrip_ = seconds;
            emit inputChanged();
        }
    }

    bool JourneyModel::endStateMatchesRoundTrip() const
    {
        const RoundTrip::Outcome outcome = RoundTrip::run(traveller(), sense(), settings_);
        const auto phases = JourneyState::phases(traveller());
        const double signedDistance =
            (sense() == RoundTrip::Sense::PlusR ? 1.0 : -1.0) * settings_.farDistance;
        return progress_ >= 1.0 && sample_.phase == phases.back() &&
               std::abs(sample_.r - signedDistance) < 1e-9 &&
               std::abs(sample_.nearClockShift - outcome.mapShift) < 1e-24 &&
               std::abs(sample_.theta - traveller().startAngle()) < 1e-9;
    }

    bool JourneyModel::onFarSide() const
    {
        return sample_.theta > std::numbers::pi / 4.0;
    }

    double JourneyModel::massKg() const { return traveller().mass; }

    void JourneyModel::play()
    {
        if (progress_ >= 1.0)
        {
            setProgress(0.0);
        }
        timer_.start();
        emit playingChanged();
    }

    void JourneyModel::pause()
    {
        timer_.stop();
        emit playingChanged();
    }

    void JourneyModel::reset()
    {
        pause();
        setProgress(0.0);
    }

    void JourneyModel::togglePlay()
    {
        if (playing())
        {
            pause();
        }
        else
        {
            play();
        }
    }
}
