#include "OpenClockWindow.h"

#include "Configuration.h"

#include "ClockLogging.h"

#include <QApplication>
#include <QDateTime>
#include <iostream>
#include <QTimeZone>
#include <QDebug>

int main(int argc, char *argv[]) {

    qInstallMessageHandler(gantzgulch::openclock::openClockMessageHandler);

    gantzgulch::openclock::Configuration config;

    config.load();

    QApplication app(argc, argv);

    gantzgulch::openclock::OpenClockWindow window(nullptr, config);

    window.resize(350, 250);
    window.setWindowTitle("OpenClockQT");
    window.show();

    return app.exec();
}
