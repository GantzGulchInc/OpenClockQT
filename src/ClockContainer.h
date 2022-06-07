#pragma once

#include "ClockFace.h"

#include <QWidget>
#include <QVector>
#include <QGridLayout>

class ClockContainer : public QWidget {

    Q_OBJECT

public:
    ClockContainer(QWidget *parent = nullptr);
    void addClockFace(ClockFace * clockFace);
    void updateClocks();

private:

    int columnCount;

    QGridLayout * layout;

    int currentRow;
    int currentColumn;

    QVector<ClockFace *> clockList;

// private slots:
//    void updateClocks();

};


