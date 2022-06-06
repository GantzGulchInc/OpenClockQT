#include "ConfigurationJson.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QColor>
#include <QFont>

QString ConfigurationJson::getString(const QJsonObject & obj,  QString key, QString defaultValue) {

    QJsonValue value = obj[key];

    if( ! value.isString() ) {
        return defaultValue;
    }

    QString s = value.toString();

    if( s.size() == 0 ) {
        return defaultValue;
    }

    return s;

}

int ConfigurationJson::getInt(const QJsonObject & obj, QString key, int defaultValue) {

    qDebug() << "ConfigurationJson::getInt: Called.";

    QJsonValue value = obj[key];

    qDebug() << "ConfigurationJson::getInt: Called. 1";

    int v = value.isDouble() ? value.toInt() : defaultValue;

    qDebug() << "ConfigurationJson::getInt: intValue: " << v;

    return v;
}

bool ConfigurationJson::getBool(const QJsonObject & obj,  QString key, bool defaultValue) {

    QJsonValue value = obj[key];

    return value.isBool() ? value.toBool() : defaultValue;

}

QColor ConfigurationJson::getColor(const QJsonObject & obj, QString key, QColor defaultValue) {

    QJsonValue value = obj[key];

    return value.isString() ? QColor(value.toString()) :  defaultValue;
}

QTimeZone ConfigurationJson::getTimeZone(const QJsonObject & obj, QString key, QTimeZone defaultValue) {

    QJsonValue value = obj[key];

    if( ! value.isString() ) {
        return defaultValue;
    }

    QTimeZone tz(value.toString().toUtf8());

    if( ! tz.isValid() ) {
        return defaultValue;
    }

    return tz;
}

QFont ConfigurationJson::getFont(const QJsonObject & obj, QString fontNameKey, QString fontHeightKey, QString fontBoldKey, QString fontItalicKey, QFont defaultFont) {

    QString fontName = getString(obj, fontNameKey, defaultFont.family());
    int fontHeight = getInt(obj, fontHeightKey, defaultFont.pointSize());
    bool isBold = getBool(obj, fontBoldKey, defaultFont.bold());
    bool isItalic = getBool(obj, fontItalicKey, defaultFont.italic());

    QFont f(fontName, fontHeight);
    f.setBold(isBold);
    f.setItalic(isItalic);

    return f;
}














void ConfigurationJson::getString(const QJsonValue & val,  QString & stringValue) {

    if( val.isString() ) {

        QString s = val.toString();

        if(s.size() > 0 ) {
            stringValue = s;
        }
    }

}

void ConfigurationJson::getInt(const QJsonValue & val, int * intValue) {
    if( val.isDouble() ) {
        *intValue = val.toInt();
    }
}

void ConfigurationJson::getBool(const QJsonValue & val, bool * boolValue) {
    if( val.isBool() ) {
        *boolValue = val.toBool();
    }
}

void ConfigurationJson::getColor(const QJsonValue & val, QColor & colorValue) {

    QString colorHex;

    getString(val, colorHex);

    QColor c(colorHex);

    if( c.isValid() ) {
        colorValue = c;
    }
}

void ConfigurationJson::getTimeZone(const QJsonValue & val,  QTimeZone & timezoneValue) {

    QString timezoneText;

    getString(val, timezoneText);

    QTimeZone tz( timezoneText.toUtf8());

    if( tz.isValid() ) {
        timezoneValue = tz;
    }
}