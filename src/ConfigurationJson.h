#pragma once

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QColor>
#include <QTimeZone>
#include <QList>

namespace gantzgulch {
namespace openclock {

class ConfigurationJson {

public:

    static QJsonObject getObject(const QJsonObject & obj, QString key);

    static QString getString(const QJsonObject & obj,  QString key, QString defaultValue);

    static int getInt(const QJsonObject & obj, QString key, int defaultValue);

    static bool getBool(const QJsonObject & obj, QString key, bool defaultValue);

    static QColor getColor(const QJsonObject & obj, QString key, QColor defaultValue);

    static QTimeZone getTimeZone(const QJsonObject & obj,  QString key, QTimeZone defaultValue);

    static QFont getFont(const QJsonObject & obj, QString fontNameKey,  QString fontHeightKey, QString fontBoldKey, QString fontItalicKey, QFont defaultFont);


    static void getObject(const QJsonValue & val, QJsonObject & objectValue);

    static void getString(const QJsonValue & val,  QString & stringValue, QString & defaultValue);

    static void getInt(const QJsonValue & val, int * intValue, int defaultValue);

    static void getBool(const QJsonValue & val, bool * boolValue, bool defaultValue);

    static void getColor(const QJsonValue & val, QColor & colorValue, QColor & defaultValue);

    static void getTimeZone(const QJsonValue & val,  QTimeZone & timezoneValue, QTimeZone & defaultValue);


};


}
}
