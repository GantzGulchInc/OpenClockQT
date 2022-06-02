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

DigitalClockFace::DigitalClockFace(QWidget * parent, ClockConfiguration * clockConfiguration) : ClockFace(parent, clockConfiguration) {

    // QPalette pal = QPalette();
    // pal.setColor(QPalette::Window, Qt::black);
    // setAutoFillBackground(true);
    // setPalette(pal);

    layout = new QGridLayout(this);
    layout->setVerticalSpacing(2);
    layout->setHorizontalSpacing(2);

    font.fromString("DSEG14 Modern");

    title = new LedDisplay(this, config->titleFont(), config->title(), " ",);
    layout->addWidget(title, 0, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    time = new LedDisplay(this, config->timeFont(), config->timeFormat(), config->timeShadow());
    layout->addWidget(time, 1, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    date = new LedDisplay(this, config->dateFont(), config->dateFormat(), config->dateShadow());
    layout->addWidget(date, 2, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    setLayout(layout);
    update(QDateTime::currentDateTimeUtc());
}

void DigitalClockFace::update(const QDateTime & now) {

    QString timeString = now.toString("hh:mm:ss");
    QString dateString = now.toString("yyyy-MM-dd");

    time->update(timeString);
    date->update(dateString);

}

