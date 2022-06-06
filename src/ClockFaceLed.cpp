#include "ClockFaceLed.h"
#include "ConfigurationJson.h"

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
#include <QJsonObject>

ClockFaceLed::ClockFaceLed(QWidget * parent) : ClockFace(parent) {

    qDebug() << "ClockFaceLed:ctor: 0";

    setFrameStyle(QFrame::Panel);
    setLineWidth(1);

    setStyleSheet("QFrame { background-color: rgb(0,0,0); border-width: 1; border-radius: 15; border-style: solid; border-color: rgb(255, 255, 255);}");

    qDebug() << "ClockFaceLed:ctor: 1";

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

    qDebug() << "ClockFaceLed:ctor: 2";

    setLayout(m_layout);

    updateUI();

    qDebug() << "ClockFaceLed:ctor: 3";
}

void ClockFaceLed::configure(QJsonObject & json) {

    qDebug() << "configure: json: " << json;

    QJsonValue paramValue = json.value("parameters");

    if( ! paramValue.isObject() ) {
        return;
    }

    QJsonObject parameters = paramValue.toObject();

    for(const QString & key : parameters.keys()) {

        QJsonValue value = parameters.value(key);

        qDebug() << "configure: key: " << key;

        if( key == "background" ) {
            ConfigurationJson::getColor(value, m_background);
        } else if( key == "title") {
            ConfigurationJson::getString(value, m_title);
        } else if( key == "titleFont" ) {
            ConfigurationJson::getString(value, m_titleFontFamily);
        } else if( key == "titleHeight" ) {
            ConfigurationJson::getInt(value, &m_titleFontHeight);
        } else if( key == "titleBold" ) {
            ConfigurationJson::getBool(value, &m_titleFontBold);
        } else if( key == "titleItalic" ) {
            ConfigurationJson::getBool(value, &m_titleFontItalic);
        } else if( key == "titleColor" ) {
            ConfigurationJson::getColor(value, m_titleColor);
        } else if( key == "titleColor" ) {
            ConfigurationJson::getColor(value, m_titleColor);
        } else if( key == "titleShadowColor" ) {
            ConfigurationJson::getColor(value, m_titleShadowColor);
        } else if( key == "titleShadow") {
            ConfigurationJson::getString(value, m_titleShadow);
        } else if( key == "timeFont" ) {
            ConfigurationJson::getString(value, m_timeFontFamily);
        } else if( key == "timeHeight" ) {
            ConfigurationJson::getInt(value, &m_timeFontHeight);
        } else if( key == "timeBold" ) {
            ConfigurationJson::getBool(value, &m_timeFontBold);
        } else if( key == "timeItalic" ) {
            ConfigurationJson::getBool(value, &m_timeFontItalic);
        } else if( key == "timeColor" ) {
            ConfigurationJson::getColor(value, m_timeColor);
        } else if( key == "timeShadowColor" ) {
            ConfigurationJson::getColor(value, m_timeShadowColor);
        } else if( key == "timeFormat" ) {
            ConfigurationJson::getString(value, m_timeFormat);
        } else if( key == "timeShadow" ) {
            ConfigurationJson::getString(value, m_timeShadow);
        } else if( key == "dateFont" ) {
            ConfigurationJson::getString(value, m_dateFontFamily);
        } else if( key == "dateHeight" ) {
            ConfigurationJson::getInt(value, &m_dateFontHeight);
        } else if( key == "dateBold" ) {
            ConfigurationJson::getBool(value, &m_dateFontBold);
        } else if( key == "dateItalic" ) {
            ConfigurationJson::getBool(value, &m_dateFontItalic);
        } else if( key == "dateColor" ) {
            ConfigurationJson::getColor(value, m_dateColor);
        } else if( key == "dateShadowColor" ) {
            ConfigurationJson::getColor(value, m_dateShadowColor);
        } else if( key == "dateFormat" ) {
            ConfigurationJson::getString(value, m_dateFormat);
        } else if( key == "dateShadow" ) {
            ConfigurationJson::getString(value, m_dateShadow);
        } else {
            qDebug() << "ClockFaceLed::configure: Unknown configuration key: " << key;
        }

    }

    qDebug() << "configure: title: " << m_title;

    m_titleFont.setFamily(m_titleFontFamily);
    m_titleFont.setPixelSize(m_titleFontHeight);
    m_titleFont.setBold(m_titleFontBold);
    m_titleFont.setItalic(m_titleFontItalic);

    m_timeFont.setFamily(m_timeFontFamily);
    m_timeFont.setPixelSize(m_timeFontHeight);
    m_timeFont.setBold(m_timeFontBold);
    m_timeFont.setItalic(m_timeFontItalic);

    m_dateFont.setFamily(m_dateFontFamily);
    m_dateFont.setPixelSize(m_dateFontHeight);
    m_dateFont.setBold(m_dateFontBold);
    m_dateFont.setItalic(m_dateFontItalic);

    updateUI();
}

void ClockFaceLed::updateUI() {

    m_titleLedDisplay->configure(m_titleFont, m_titleColor, m_titleShadowColor,m_title, m_titleShadow);

    m_timeLedDisplay->configure(m_timeFont, m_timeColor, m_timeShadowColor,m_timeShadow, m_timeShadow);

    m_dateLedDisplay->configure(m_dateFont, m_dateColor, m_dateShadowColor,m_dateShadow, m_dateShadow);
}

void ClockFaceLed::update(const QDateTime & now) {

    qDebug() << "ClockFaceLed: update: now:";

    QDateTime local = now.toTimeZone(m_timeZone);

    QString timeString = local.toString(m_timeFormat);
    QString dateString = local.toString(m_dateFormat);

    m_titleLedDisplay->update(m_title);
    m_timeLedDisplay->update(timeString);
    m_dateLedDisplay->update(dateString);

}

