#pragma once

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QColor>
#include <QTimeZone>
#include <QFont>


class ClockConfiguration  {

public:
    ClockConfiguration();

    QString type();
    QTimeZone timeZone();

    QColor background();

    QString title();
    QFont titleFont();
    QColor titleColor();

    QFont timeFont();
    QColor timeColor();
    QColor timeShadowColor();
    QString timeFormat();
    QString timeShadow();

    QFont dateFont();
    QColor dateColor();
    QColor dateShadowColor();
    QString dateFormat();
    QString dateShadow();

private:
    QJsonObject json;

};


