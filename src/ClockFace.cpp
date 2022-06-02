#include "ClockFace.h"

#include <QWidget>
#include <QDebug>
#include <QDateTime>

ClockFace::ClockFace(QWidget * parent, ClockConfiguration * clockConfiguration) : QFrame(parent), config(clockConfiguration) {

}

void ClockFace::update(const QDateTime & dateTime)  {

    Q_UNUSED(dateTime);

    qDebug() << "ClockFace: update: Needs to be overridden.";
}

