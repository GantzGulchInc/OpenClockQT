#include "ClockLogging.h"

#include <QDateTime>
#include <iostream>
#include <QTimeZone>
#include <QDebug>
#include <QtMessageHandler>

namespace gantzgulch {
namespace openclock {

Q_LOGGING_CATEGORY(ocUi, "oc.ui")
Q_LOGGING_CATEGORY(ocConfig, "oc.config")

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
    const char * category = context.category != nullptr ? context.category : "";
    const char * file = context.file != nullptr ? context.file : "<none>";

    std::cout
            << nowText.toStdString()
            << " " << category
            << " [" << toString(type).toStdString() << "] "
            << "(" << file << ":" << context.line << ") "
            << msg.toStdString()
            << std::endl;

    // std::cout << nowText.toStdString() << " [" << toString(type).toStdString() << "] ( ) " << msg.toStdString() << std::endl;

}


}
}
