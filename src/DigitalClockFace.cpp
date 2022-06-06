#include "DigitalClockFace.h"

#include <QDebug>
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

    qDebug() << "DigitalClockFace:ctor: 0";

    setFrameStyle(QFrame::Panel);
    setLineWidth(1);

    setStyleSheet("QFrame { background-color: rgb(0,0,0); border-width: 1; border-radius: 15; border-style: solid; border-color: rgb(255, 255, 255);}");

    qDebug() << "DigitalClockFace:ctor: 1";

    m_layout = new QGridLayout(this);
    m_layout->setVerticalSpacing(2);
    m_layout->setHorizontalSpacing(2);

    m_titleLedDisplay = new LedDisplay(this);
    m_layout->addWidget(m_titleLedDisplay, 0, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    m_timeLedDisplay = new LedDisplay(this);
    m_layout->addWidget(m_timeLedDisplay, 1, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    m_dateLedDisplay = new LedDisplay(this);
    m_layout->addWidget(m_dateLedDisplay, 2, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    // update(QDateTime::currentDateTimeUtc());

    qDebug() << "DigitalClockFace:ctor: 2";

    setLayout(m_layout);

    updateUI();

    qDebug() << "DigitalClockFace:ctor: 3";
}

void DigitalClockFace::configure(QJsonObject & json) {

    Q_UNUSED(json);

    updateUI();
}

void DigitalClockFace::updateUI() {

    m_titleLedDisplay->configure(m_titleFont, m_titleColor, m_titleShadowColor,m_title, m_titleShadow);

    m_timeLedDisplay->configure(m_timeFont, m_timeColor, m_timeShadowColor,m_timeShadow, m_timeShadow);

    m_dateLedDisplay->configure(m_dateFont, m_dateColor, m_dateShadowColor,m_dateShadow, m_dateShadow);
}

void DigitalClockFace::update(const QDateTime & now) {

    qDebug() << "DigitalClockFace: update: now:";

    QDateTime local = now.toTimeZone(m_timeZone);

    QString timeString = local.toString("hh:mm:ss");
    QString dateString = local.toString("yyyy-MM-dd");

    m_titleLedDisplay->update(m_title);
    m_timeLedDisplay->update(timeString);
    m_dateLedDisplay->update(dateString);

}

