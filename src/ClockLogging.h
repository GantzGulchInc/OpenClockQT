#pragma once

#include <QLoggingCategory>
#include <QtMessageHandler>

namespace gantzgulch {
namespace openclock {

Q_DECLARE_LOGGING_CATEGORY(ocUi)
Q_DECLARE_LOGGING_CATEGORY(ocConfig)


void openClockMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

}
}
