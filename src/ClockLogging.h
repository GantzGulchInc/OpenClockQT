#ifndef CLOCKLOGGING_H
#define CLOCKLOGGING_H

#include <QLoggingCategory>
#include <QtMessageHandler>

Q_DECLARE_LOGGING_CATEGORY(ocUi)
Q_DECLARE_LOGGING_CATEGORY(ocConfig)


void openClockMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // CLOCKLOGGING_H
