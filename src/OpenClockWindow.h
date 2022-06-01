#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

#include "DigitalClockFace.h"

class OpenClockWindow : public QMainWindow {

    Q_OBJECT

public:
    OpenClockWindow(QWidget *parent = nullptr);

private:
    DigitalClockFace * clockFace;

private slots:
    void updateClocks();

};


