#pragma once

#include "ClockFace.h"

#include <QString>
#include <QJsonDocument>

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


