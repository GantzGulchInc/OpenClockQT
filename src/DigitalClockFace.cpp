#include "DigitalClockFace.h"

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>
#include <QTextEdit>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QVBoxLayout>

DigitalClockFace::DigitalClockFace(QWidget * parent) : QWidget(parent) {

    auto * vbox = new QVBoxLayout(this);
    vbox->setSpacing(0);

    title = new QLabel("Title");
    time = new QLabel("Time");
    date = new QLabel("Date");

    vbox->addWidget(title);
    vbox->addWidget(time);
    vbox->addWidget(date);

    update(QDateTime::currentDateTimeUtc());
}

void DigitalClockFace::update(const QDateTime & dateTime) {

    QString timeString = dateTime.toString("hh:mm:ss");
    QString dateString = dateTime.toString("yyyy-MM-dd");

    title->setText("Title");
    time->setText(timeString);
    date->setText(dateString);

}

