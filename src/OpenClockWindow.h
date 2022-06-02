#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

#include "ClockContainer.h"

class OpenClockWindow : public QMainWindow {

    Q_OBJECT

public:
    OpenClockWindow(QWidget *parent = nullptr);

private:

    ClockContainer * clockContainer;

private slots:
    void updateClocks();

};


