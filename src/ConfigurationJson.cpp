#include "ConfigurationJson.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QColor>
#include <QFont>

namespace gantzgulch {
namespace openclock {

static QString EMPTY_STRING{""};

QJsonObject ConfigurationJson::getObject(const QJsonObject & obj, QString key) {

    QJsonValue value = obj[key];

    if( value.isObject() ) {
        return value.toObject();
    }

    return QJsonObject();
}



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

    QJsonValue value = obj[key];

    int v = value.isDouble() ? value.toInt() : defaultValue;

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









void ConfigurationJson::getObject(const QJsonValue & val, QJsonObject & objectValue) {

    if( val.isObject() ) {
        objectValue = val.toObject();
    }

}





void ConfigurationJson::getString(const QJsonValue & val,  QString & stringValue, QString & defaultValue) {

    if( val.isString() ) {

        QString s = val.toString();

        if(s.size() > 0 ) {
            stringValue = s;

            return;
        }
    }

    stringValue = defaultValue;
}

void ConfigurationJson::getInt(const QJsonValue & val, int * intValue, int defaultValue) {

    if( val.isDouble() ) {
        *intValue = val.toInt();
        return;
    }

    *intValue = defaultValue;
}

void ConfigurationJson::getBool(const QJsonValue & val, bool * boolValue, bool defaultValue) {
    if( val.isBool() ) {
        *boolValue = val.toBool();
        return;
    }

    *boolValue = defaultValue;
}

void ConfigurationJson::getColor(const QJsonValue & val, QColor & colorValue, QColor & defaultValue) {

    QString colorHex;

    getString(val, colorHex, EMPTY_STRING);

    QColor c(colorHex);

    if( c.isValid() ) {
        colorValue = c;
        return;
    }

    colorValue = defaultValue;
}

void ConfigurationJson::getTimeZone(const QJsonValue & val,  QTimeZone & timezoneValue, QTimeZone & defaultValue) {

    QString timezoneText;

    getString(val, timezoneText, EMPTY_STRING);

    QTimeZone tz( timezoneText.toUtf8());

    if( tz.isValid() ) {
        timezoneValue = tz;
        return;
    }

    timezoneValue = defaultValue;
}

}
}
