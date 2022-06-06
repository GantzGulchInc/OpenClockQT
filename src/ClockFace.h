#pragma once

#include <QWidget>
#include <QDateTime>
#include <QFrame>

class ClockFace : public QFrame {

public:
    ClockFace(QWidget *parent);
    virtual void configure(QJsonObject & json);
    virtual void update(const QDateTime & now);
};


