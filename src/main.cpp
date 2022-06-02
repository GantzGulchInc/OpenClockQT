#include "OpenClockWindow.h"

#include <QApplication>
#include <QDateTime>
#include <iostream>

QString toString(QtMsgType type) {

    switch(type) {
    case QtDebugMsg:
        return "DEBUG";
    case QtWarningMsg:
        return "WARN";
    case QtCriticalMsg:
        return "CRIT";
    case QtFatalMsg:
        return "FATAL";
    case QtInfoMsg:
        return "INFO";
    default:
        return "UNKN";
    }
}

void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

    QDateTime now = QDateTime::currentDateTime();
    QString nowText = now.toString("yyyy/MM/dd hh:mm:ss");

    std::cout << nowText.toStdString() << " [" << toString(type).toStdString() << "] " << msg.toStdString() << std::endl;
}


int main(int argc, char *argv[]) {

    qInstallMessageHandler(myMessageHandler);

    QApplication app(argc, argv);

    OpenClockWindow window;

    window.resize(350, 250);
    window.setWindowTitle("OpenClockQT");
    window.show();

    return app.exec();
}
