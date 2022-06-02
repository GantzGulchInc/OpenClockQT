#pragma once

#include "ClockConfiguration.h"

#include <QWidget>
#include <QDateTime>

class ClockFace : public QWidget {

public:
    ClockFace(QWidget *parent, ClockConfiguration * config);
    virtual void update(const QDateTime & now);

protected:
    ClockConfiguration * config;
};


