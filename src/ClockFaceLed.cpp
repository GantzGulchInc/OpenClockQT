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

QString ClockFaceLed::DEFAULT_TITLE{"Detroic"};
QTimeZone ClockFaceLed::DEFAULT_TIMEZONE{"America/Detroit"};
QString ClockFaceLed::DEFAULT_FONT_FAMILY{"DSEG14 Modern"};
int ClockFaceLed::DEFAULT_FONT_HEIGHT{28};
QColor ClockFaceLed::DEFAULT_COLOR{"#ffffff"};
QColor ClockFaceLed::DEFAULT_SHADOW_COLOR{"#909090"};
QString ClockFaceLed::DEFAULT_TIME_FORMAT{"HH:mm:ss"};
QString ClockFaceLed::DEFAULT_DATE_FORMAT{"yyyy-mm-dd"};
QColor ClockFaceLed::DEFAULT_BACKGROUND{"#000000"};


static QString EMPTY_STRING{""};

ClockFaceLed::ClockFaceLed(QWidget * parent) : ClockFace(parent) {

    setFrameStyle(QFrame::Panel);
    setLineWidth(1);

    setStyleSheet("QFrame { background-color: rgb(0,0,0); border-width: 1; border-radius: 15; border-style: solid; border-color: rgb(255, 255, 255);}");

    m_layout = new QGridLayout(this);
    m_layout->setVerticalSpacing(2);
    m_layout->setHorizontalSpacing(2);

    m_titleLedDisplay = new LedDisplay(this);
    m_layout->addWidget(m_titleLedDisplay, 0, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    m_timeLedDisplay = new LedDisplay(this);
    m_layout->addWidget(m_timeLedDisplay, 1, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    m_dateLedDisplay = new LedDisplay(this);
    m_layout->addWidget(m_dateLedDisplay, 2, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);

    setLayout(m_layout);

    updateUI();
}

void ClockFaceLed::configure(QJsonObject & json) {

    QJsonValue paramValue = json.value("parameters");

    if( ! paramValue.isObject() ) {
        return;
    }

    QJsonObject parameters = paramValue.toObject();

    for(const QString & key : parameters.keys()) {

        QJsonValue value = parameters.value(key);

        qDebug() << "configure: key: " << key;

        if( key == "background" ) {
            ConfigurationJson::getColor(value, m_background, DEFAULT_BACKGROUND);

        } else if( key == "title") {
            ConfigurationJson::getString(value, m_title, DEFAULT_TITLE);
        } else if( key == "titleFont" ) {
            ConfigurationJson::getString(value, m_titleFontFamily, DEFAULT_FONT_FAMILY);
        } else if( key == "titleHeight" ) {
            ConfigurationJson::getInt(value, &m_titleFontHeight, DEFAULT_FONT_HEIGHT);
        } else if( key == "titleBold" ) {
            ConfigurationJson::getBool(value, &m_titleFontBold, false);
        } else if( key == "titleItalic" ) {
            ConfigurationJson::getBool(value, &m_titleFontItalic, false);
        } else if( key == "titleColor" ) {
            ConfigurationJson::getColor(value, m_titleColor, DEFAULT_COLOR);
        } else if( key == "titleShadowColor" ) {
            ConfigurationJson::getColor(value, m_titleShadowColor, DEFAULT_SHADOW_COLOR);
        } else if( key == "titleShadow") {
            ConfigurationJson::getString(value, m_titleShadow, EMPTY_STRING);

        } else if( key == "timeFont" ) {
            ConfigurationJson::getString(value, m_timeFontFamily, DEFAULT_FONT_FAMILY);
        } else if( key == "timeHeight" ) {
            ConfigurationJson::getInt(value, &m_timeFontHeight, DEFAULT_FONT_HEIGHT);
        } else if( key == "timeBold" ) {
            ConfigurationJson::getBool(value, &m_timeFontBold, false);
        } else if( key == "timeItalic" ) {
            ConfigurationJson::getBool(value, &m_timeFontItalic, false);
        } else if( key == "timeColor" ) {
            ConfigurationJson::getColor(value, m_timeColor, DEFAULT_COLOR);
        } else if( key == "timeShadowColor" ) {
            ConfigurationJson::getColor(value, m_timeShadowColor, DEFAULT_SHADOW_COLOR);
        } else if( key == "timeFormat" ) {
            ConfigurationJson::getString(value, m_timeFormat, DEFAULT_TIME_FORMAT);
        } else if( key == "timeShadow" ) {
            ConfigurationJson::getString(value, m_timeShadow, EMPTY_STRING);
        } else if( key == "dateFont" ) {
            ConfigurationJson::getString(value, m_dateFontFamily, DEFAULT_FONT_FAMILY);
        } else if( key == "dateHeight" ) {
            ConfigurationJson::getInt(value, &m_dateFontHeight, DEFAULT_FONT_HEIGHT);
        } else if( key == "dateBold" ) {
            ConfigurationJson::getBool(value, &m_dateFontBold, false);
        } else if( key == "dateItalic" ) {
            ConfigurationJson::getBool(value, &m_dateFontItalic, false);
        } else if( key == "dateColor" ) {
            ConfigurationJson::getColor(value, m_dateColor, DEFAULT_COLOR);
        } else if( key == "dateShadowColor" ) {
            ConfigurationJson::getColor(value, m_dateShadowColor, DEFAULT_SHADOW_COLOR);
        } else if( key == "dateFormat" ) {
            ConfigurationJson::getString(value, m_dateFormat, DEFAULT_DATE_FORMAT);
        } else if( key == "dateShadow" ) {
            ConfigurationJson::getString(value, m_dateShadow, EMPTY_STRING);
        } else {
            qDebug() << "ClockFaceLed::configure: Unknown configuration key: " << key;
        }

    }

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

    QDateTime local = now.toTimeZone(m_timeZone);

    QString timeString = local.toString(m_timeFormat);
    QString dateString = local.toString(m_dateFormat);

    m_titleLedDisplay->update(m_title);
    m_timeLedDisplay->update(timeString);
    m_dateLedDisplay->update(dateString);

}

