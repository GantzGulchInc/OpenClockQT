#pragma once

#include <QWidget>
#include <QDateTime>

class ClockFace : public QWidget {

public:
    ClockFace(QWidget *parent = nullptr);
    virtual void update(const QDateTime & now);

};


