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
#include <QFont>

DigitalClockFace::DigitalClockFace(QWidget * parent) : QWidget(parent) {

    QPalette pal = QPalette();

    pal.setColor(QPalette::Window, Qt::black);

    setAutoFillBackground(true);
    setPalette(pal);

    auto * vbox = new QVBoxLayout(this);
    vbox->setSpacing(0);

    font.fromString("DSEG14 Modern");

    title = new LedDisplay(this, "Title", "Title");
    // title->setFont(font);
    // title->setStyleSheet( "QLabel { background-color: black; color : green; }");

    time = new LedDisplay(this, "88:88:88", "88:88:88");
    // time->setFont(font);
    // time->setStyleSheet( "QLabel { background-color: black; color : green; }");

    date = new LedDisplay(this, "8888-88-88", "8888-88-88");
    // date->setFont(font);
    // date->setStyleSheet( "QLabel { background-color: black; color : green; }");

    vbox->addWidget(title);
    vbox->addWidget(time);
    vbox->addWidget(date);

    update(QDateTime::currentDateTimeUtc());
}

void DigitalClockFace::update(const QDateTime & dateTime) {

    QString timeString = dateTime.toString("hh:mm:ss");
    QString dateString = dateTime.toString("yyyy-MM-dd");

    title->update("Title");
    time->update(timeString);
    date->update(dateString);

}

