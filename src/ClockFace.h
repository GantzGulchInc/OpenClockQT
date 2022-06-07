#pragma once

#include <QFrame>
#include <QJsonObject>
#include <QDateTime>

class ClockFace : public QFrame {

public:
    ClockFace(QWidget *parent);
    virtual void configure(QJsonObject & json);
    virtual void update(const QDateTime & now);
};


