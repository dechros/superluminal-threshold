#ifndef SLM_GUI_JOURNEYMODEL_H
#define SLM_GUI_JOURNEYMODEL_H

#include "journey/JourneyState.h"
#include "journey/RoundTrip.h"
#include "journey/Traveller.h"

#include <QObject>
#include <QStringList>
#include <QString>
#include <QTimer>
#include <QVariantList>
#include <QtQml/qqmlregistration.h>

#include <vector>

namespace slm::gui
{

    /// The one object the viewer reads. It owns a traveller, a sense and a
    /// progress, asks JourneyState for the sample at that progress, and exposes
    /// the sample's numbers and coordinates as properties. Nothing is computed
    /// here beyond unit conversions for display; every value comes from the
    /// library the check suite runs.
    class JourneyModel : public QObject
    {
        Q_OBJECT
        QML_ELEMENT

        Q_PROPERTY(int travellerIndex READ travellerIndex WRITE setTravellerIndex NOTIFY inputChanged)
        Q_PROPERTY(int senseIndex READ senseIndex WRITE setSenseIndex NOTIFY inputChanged)
        Q_PROPERTY(double progress READ progress WRITE setProgress NOTIFY sampleChanged)
        Q_PROPERTY(bool playing READ playing NOTIFY playingChanged)
        Q_PROPERTY(double farDistance READ farDistance WRITE setFarDistance NOTIFY inputChanged)

        Q_PROPERTY(QString travellerName READ travellerName NOTIFY inputChanged)
        Q_PROPERTY(QString senseName READ senseName NOTIFY inputChanged)
        Q_PROPERTY(QString phaseName READ phaseName NOTIFY sampleChanged)
        Q_PROPERTY(int phaseIndex READ phaseIndex NOTIFY sampleChanged)
        Q_PROPERTY(int phaseCount READ phaseCount NOTIFY inputChanged)
        Q_PROPERTY(double theta READ theta NOTIFY sampleChanged)
        Q_PROPERTY(double beta READ beta NOTIFY sampleChanged)
        Q_PROPERTY(double metricScale READ metricScale NOTIFY sampleChanged)
        Q_PROPERTY(double clockRate READ clockRate NOTIFY sampleChanged)
        Q_PROPERTY(double momentum READ momentum NOTIFY sampleChanged)
        Q_PROPERTY(double mu READ mu NOTIFY inputChanged)
        Q_PROPERTY(double r READ r NOTIFY sampleChanged)
        Q_PROPERTY(double nearClockShiftNs READ nearClockShiftNs NOTIFY sampleChanged)
        Q_PROPERTY(double finalShiftNs READ finalShiftNs NOTIFY inputChanged)
        Q_PROPERTY(double thresholdMomentum READ thresholdMomentum NOTIFY inputChanged)
        Q_PROPERTY(QVariantList metric READ metric NOTIFY sampleChanged)
        Q_PROPERTY(QVariantList nearAtoms READ nearAtoms NOTIFY sampleChanged)
        Q_PROPERTY(QVariantList farAtoms READ farAtoms NOTIFY sampleChanged)
        Q_PROPERTY(QVariantList atomRadii READ atomRadii NOTIFY inputChanged)
        Q_PROPERTY(bool onFarSide READ onFarSide NOTIFY sampleChanged)
        Q_PROPERTY(double massKg READ massKg NOTIFY inputChanged)
        Q_PROPERTY(QStringList travellerNames READ travellerNames CONSTANT)
        Q_PROPERTY(double secondsPerTrip READ secondsPerTrip WRITE setSecondsPerTrip NOTIFY inputChanged)

    public:
        explicit JourneyModel(QObject *parent = nullptr);

        int travellerIndex() const;
        void setTravellerIndex(int index);
        int senseIndex() const;
        void setSenseIndex(int index);
        double progress() const;
        void setProgress(double progress);
        bool playing() const;
        double farDistance() const;
        void setFarDistance(double metres);

        QString travellerName() const;
        QString senseName() const;
        QString phaseName() const;
        int phaseIndex() const;
        int phaseCount() const;
        double theta() const;
        double beta() const;
        double metricScale() const;
        double clockRate() const;
        double momentum() const;
        double mu() const;
        double r() const;
        double nearClockShiftNs() const;
        double finalShiftNs() const;
        double thresholdMomentum() const;
        QVariantList metric() const;
        QVariantList nearAtoms() const;
        QVariantList farAtoms() const;
        QVariantList atomRadii() const;
        bool onFarSide() const;
        double massKg() const;
        QStringList travellerNames() const;
        double secondsPerTrip() const;
        void setSecondsPerTrip(double seconds);

        /// True when the state the viewer has actually reached is the end of
        /// the trip and agrees with RoundTrip::run: progress one, the last
        /// phase, the chosen far-side distance with its sign, and the clock
        /// shift the round trip establishes.
        Q_INVOKABLE bool endStateMatchesRoundTrip() const;

        /// Starts the trip from where the progress stands, or from the start
        /// when it has finished.
        Q_INVOKABLE void play();
        Q_INVOKABLE void pause();
        Q_INVOKABLE void reset();
        Q_INVOKABLE void togglePlay();

    signals:
        void inputChanged();
        void sampleChanged();
        void playingChanged();
        void finished();

    private:
        void resample();
        const Traveller &traveller() const;
        RoundTrip::Sense sense() const;

        std::vector<Traveller> travellers_;
        RoundTrip::Settings settings_;
        int travellerIndex_ = 2;
        int senseIndex_ = 0;
        double progress_ = 0.0;
        JourneyState::Sample sample_;
        QTimer timer_;
        double secondsPerTrip_ = 14.0;
    };

}

#endif
