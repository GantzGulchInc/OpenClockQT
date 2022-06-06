#include "ClockFace.h"

#include <QWidget>
#include <QDebug>
#include <QDateTime>

ClockFace::ClockFace(QWidget * parent) : QFrame(parent) {

}

void ClockFace::configure(QJsonObject & json) {

    Q_UNUSED(json);

}

void ClockFace::update(const QDateTime & dateTime)  {

    Q_UNUSED(dateTime);

    qDebug() << "ClockFace: update: Needs to be overridden.";
}

