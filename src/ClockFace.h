#pragma once

#include "ClockConfiguration.h"

#include <QWidget>
#include <QDateTime>
#include <QFrame>

class ClockFace : public QFrame {

public:
    ClockFace(QWidget *parent, ClockConfiguration * config);
    virtual void update(const QDateTime & now);

protected:
    ClockConfiguration * config;
};


