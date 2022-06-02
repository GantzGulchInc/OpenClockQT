#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QFont>
#include <QGridLayout>

#include "ClockFace.h"
#include "LedDisplay.h"

class DigitalClockFace : public ClockFace {

    Q_OBJECT

public:
    DigitalClockFace(QWidget *parent, ClockConfiguration * clockConfiguration);
    void update(const QDateTime & now);

private:

    QGridLayout * layout;
    QFont font;

    LedDisplay *title;
    LedDisplay *time;
    LedDisplay *date;

// private slots:
//    void updateClocks();

};


