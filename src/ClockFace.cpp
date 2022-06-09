#include "ClockFace.h"

#include "ClockLogging.h"

#include <QWidget>
#include <QDebug>
#include <QDateTime>

namespace gantzgulch {
namespace openclock {

ClockFace::ClockFace(QWidget * parent) : QFrame(parent) {

}

void ClockFace::configure(QJsonObject & json) {

    Q_UNUSED(json);

}

void ClockFace::update(const QDateTime & dateTime)  {

    Q_UNUSED(dateTime);

    qCWarning(ocUi) << "update: Needs to be overridden.";
}

}
}
