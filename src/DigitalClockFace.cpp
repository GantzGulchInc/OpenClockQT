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

DigitalClockFace::DigitalClockFace(QWidget * parent) : ClockFace(parent) {

    // QPalette pal = QPalette();
    // pal.setColor(QPalette::Window, Qt::black);
    // setAutoFillBackground(true);
    // setPalette(pal);

    layout = new QGridLayout(this);
    layout->setVerticalSpacing(2);
    layout->setHorizontalSpacing(2);

    font.fromString("DSEG14 Modern");

    title = new LedDisplay(this, "Title", "Title");
    layout->addWidget(title, 0, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    // title->setFont(font);
    // title->setStyleSheet( "QLabel { background-color: black; color : green; }");

    time = new LedDisplay(this, "88:88:88", "88:88:88");
    layout->addWidget(time, 1, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    // time->setFont(font);
    // time->setStyleSheet( "QLabel { background-color: black; color : green; }");

    date = new LedDisplay(this, "8888-88-88", "8888-88-88");
    layout->addWidget(date, 2, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
    // date->setFont(font);
    // date->setStyleSheet( "QLabel { background-color: black; color : green; }");

    setLayout(layout);
    update(QDateTime::currentDateTimeUtc());
}

void DigitalClockFace::update(const QDateTime & now) {

    QString timeString = now.toString("hh:mm:ss");
    QString dateString = now.toString("yyyy-MM-dd");

    title->update("Title");
    time->update(timeString);
    date->update(dateString);

}

