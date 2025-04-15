#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cppsignalsender.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    cppSignalSender sender;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("cppSignalSender", &sender);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("gitTest", "Main");

    return app.exec();
}
