#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ganalytics.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    GoogleAnalytics ganalytics;
    ganalytics.initTracker();
    engine.rootContext()->setContextProperty("gAnalytics", &ganalytics);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));



    return app.exec();
}
