#pragma once

#include "ConfigurationDisplay.h"

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>

class Configuration {

public:
    Configuration();
    bool load();
    QList<QJsonObject> clockConfigs();


private:
    QJsonParseError m_jsonError;
    QJsonDocument m_document;
    QJsonObject m_jsonObject;

    ConfigurationDisplay m_configDisplay;
    QList<QJsonObject> m_clockConfigs;

    bool readFile(const QString & path, QByteArray & bytes);
    bool parseJson(const QByteArray & data);
};


