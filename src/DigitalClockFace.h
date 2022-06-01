#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QFont>

#include "LedDisplay.h"

class DigitalClockFace : public QWidget {

    Q_OBJECT

public:
    DigitalClockFace(QWidget *parent = nullptr);
    void update(const QDateTime & dateTime);

private:
    QFont font;

    LedDisplay *title;
    LedDisplay *time;
    LedDisplay *date;

// private slots:
//    void updateClocks();

};


