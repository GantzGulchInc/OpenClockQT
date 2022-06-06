#pragma once

#include "ConfigurationDisplay.h"

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QColor>
#include <QTimeZone>
#include <QList>

class Configuration {

public:
    Configuration();
    bool load();
    QList<QJsonObject> clockConfigs();


private:
    QJsonParseError jsonError;
    QJsonDocument document;
    QJsonObject jsonObject;

    ConfigurationDisplay configDisplay;
    QList<QJsonObject> m_clockConfigs;

    bool readFile(const QString & path, QByteArray & bytes);
    bool parseJson(const QByteArray & data);
};


