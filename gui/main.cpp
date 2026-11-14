#include <QCommandLineParser>
#include <QGuiApplication>
#include <QImage>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QQuickWindow>
#include <QTimer>

#include <print>

#include "JourneyModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setApplicationName(QStringLiteral("superluminal-gui"));
    QQuickStyle::setStyle(QStringLiteral("Fusion"));

    QCommandLineParser parser;
    parser.addHelpOption();
    const QCommandLineOption snapshot(QStringLiteral("snapshot"),
                                      QStringLiteral("Render one frame to <file> and exit."),
                                      QStringLiteral("file"));
    const QCommandLineOption progress(QStringLiteral("progress"),
                                      QStringLiteral("Trip progress in [0, 1] for the snapshot."),
                                      QStringLiteral("value"), QStringLiteral("0.5"));
    const QCommandLineOption traveller(QStringLiteral("traveller"),
                                       QStringLiteral("0 massless, 1 hydrogen atom, 2 methane."),
                                       QStringLiteral("index"), QStringLiteral("2"));
    const QCommandLineOption sense(QStringLiteral("sense"),
                                   QStringLiteral("0 drives along +r, 1 along -r."),
                                   QStringLiteral("index"), QStringLiteral("0"));
    const QCommandLineOption autoplay(QStringLiteral("autoplay"),
                                      QStringLiteral("Play the whole trip in <seconds>, verify the end state against the round trip, print the result and exit."),
                                      QStringLiteral("seconds"));
    parser.addOptions({snapshot, progress, traveller, sense, autoplay});
    parser.process(app);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("startProgress"),
                                             parser.value(progress).toDouble());
    engine.rootContext()->setContextProperty(QStringLiteral("startTraveller"),
                                             parser.value(traveller).toInt());
    engine.rootContext()->setContextProperty(QStringLiteral("startSense"),
                                             parser.value(sense).toInt());
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        [] { QCoreApplication::exit(1); }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty(QStringLiteral("autoplaySeconds"),
                                             parser.isSet(autoplay) ? parser.value(autoplay).toDouble() : 0.0);
    engine.loadFromModule("Superluminal", "Main");

    auto *window = qobject_cast<QQuickWindow *>(engine.rootObjects().value(0));
    if (window == nullptr)
    {
        return 1;
    }
    if (parser.isSet(autoplay))
    {
        auto *journey = window->findChild<slm::gui::JourneyModel *>(QStringLiteral("journey"));
        if (journey == nullptr)
        {
            return 1;
        }
        QObject::connect(journey, &slm::gui::JourneyModel::finished, &app, [journey] {
            const bool ok = journey->endStateMatchesRoundTrip();
            std::println("autoplay finished: {}, r = {:.3f} m, clock shift = {:+.4f} ns, end state matches the round trip: {}",
                         journey->phaseName().toStdString(), journey->r(), journey->nearClockShiftNs(), ok);
            QCoreApplication::exit(ok ? 0 : 3);
        });
    }
    if (parser.isSet(snapshot))
    {
        const QString file = parser.value(snapshot);
        QTimer::singleShot(1500, &app, [window, file] {
            const QImage image = window->grabWindow();
            QCoreApplication::exit(image.save(file) ? 0 : 2);
        });
    }
    return QGuiApplication::exec();
}
