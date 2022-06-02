#include "ClockConfiguration.h"

#include <QFile>
#include <QDebug>
#include <QDir>


ClockConfiguration::ClockConfiguration() {


}

QString ClockConfiguration::type() {
    return "Unknown";
}

QTimeZone ClockConfiguration::timeZone() {
    return QTimeZone("America/Detroit");
}

QColor ClockConfiguration::background() {
    return QColor(0x00, 0x00, 0x00);
}

QString ClockConfiguration::title() {
    return "New Title";
}

QFont ClockConfiguration::titleFont() {
    QFont font("DSEG14 Modern", 28);
    return font;
}

QColor ClockConfiguration::titleColor() {
    return QColor(0x00, 0xff, 0x00);
}

QFont ClockConfiguration::timeFont() {
    QFont font("DSEG14 Modern", 28);
    return font;
}

QColor ClockConfiguration::timeColor() {
    return QColor(0x00, 0xff, 0x00);
}

QColor ClockConfiguration::timeShadowColor() {
    return QColor(0x00, 0x40, 0x00);
}

QString ClockConfiguration::timeFormat() {
    return "hh:mm:ss";
}

QString ClockConfiguration::timeShadow() {
    return "88:88:88";
}

QFont ClockConfiguration::dateFont() {
    QFont font("DSEG14 Modern", 28);
    return font;
}

QColor ClockConfiguration::dateColor() {
    return QColor(0x00, 0xff, 0x00);
}

QColor ClockConfiguration::dateShadowColor() {
    return QColor(0x00, 0x40, 0x00);
}

QString ClockConfiguration::dateFormat() {
    return "yyyy-MM-dd";
}

QString ClockConfiguration::dateShadow() {
    return "~~~~-~~-~~";
}
