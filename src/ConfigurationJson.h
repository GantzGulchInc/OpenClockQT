#pragma once

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QColor>
#include <QTimeZone>
#include <QList>

class ConfigurationJson {

public:
    static QString getString(const QJsonObject & obj,  QString key, QString defaultValue);

    static int getInt(const QJsonObject & obj, QString key, int defaultValue);

    static bool getBool(const QJsonObject & obj, QString key, bool defaultValue);

    static QColor getColor(const QJsonObject & obj, QString key, QColor defaultValue);

    static QTimeZone getTimeZone(const QJsonObject & obj,  QString key, QTimeZone defaultValue);

    static QFont getFont(const QJsonObject & obj, QString fontNameKey,  QString fontHeightKey, QString fontBoldKey, QString fontItalicKey, QFont defaultFont);
};


