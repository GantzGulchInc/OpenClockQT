#include "ClockFace.h"

#include <QWidget>
#include <QDebug>
#include <QDateTime>

ClockFace::ClockFace(QWidget * parent) : QWidget(parent) {

}

void ClockFace::update(const QDateTime & dateTime) {
    qDebug() << "ClockFace: update: Needs to be overridden.";
}

