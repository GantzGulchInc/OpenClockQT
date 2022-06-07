#include "ClockLogging.h"

#include <QDateTime>
#include <iostream>
#include <QTimeZone>
#include <QDebug>
#include <QtMessageHandler>

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

void openClockMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

    QDateTime now = QDateTime::currentDateTime();
    QString nowText = now.toString("yyyy/MM/dd hh:mm:ss");

    const char * f = context.file != nullptr ? context.file : "<none>";

    std::cout << nowText.toStdString() << " [" << toString(type).toStdString() << "] (" << f << ":" << context.line << ") " << msg.toStdString() << std::endl;

    // std::cout << nowText.toStdString() << " [" << toString(type).toStdString() << "] ( ) " << msg.toStdString() << std::endl;

}


