#ifndef CLOCKLOGGING_H
#define CLOCKLOGGING_H

#include <QtMessageHandler>

void openClockMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // CLOCKLOGGING_H
