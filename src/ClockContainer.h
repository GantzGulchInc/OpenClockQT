#pragma once

#include "ClockFace.h"

#include <QWidget>
#include <QVector>
#include <QGridLayout>

namespace gantzgulch {
namespace openclock {

class ClockContainer : public QWidget {

    Q_OBJECT

public:
    ClockContainer(QWidget *parent = nullptr);
    void addClockFace(ClockFace * clockFace);
    void updateClocks();

private:

    int m_columnCount;

    QGridLayout * m_layout;

    int m_currentRow;
    int m_currentColumn;

    QVector<ClockFace *> m_clockList;

// private slots:
//    void updateClocks();

};

}

}
