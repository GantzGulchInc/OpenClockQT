#pragma once

#include "ClockFace.h"

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QColor>
#include <QTimeZone>


class DisplayConfiguration  {

public:
    DisplayConfiguration();
    void setJson(QJsonObject json);
    int columns();
    QColor background();

private:
    QJsonObject json;

};

class Configuration {

public:
    Configuration();
    void load();



private:
    QJsonParseError jsonError;
    QJsonDocument document;

    QByteArray readFile(const QString & path);
    void parseJson(const QByteArray & data);
};


