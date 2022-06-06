#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

#include "Configuration.h"
#include "ClockContainer.h"

class OpenClockWindow : public QMainWindow {

    Q_OBJECT

public:
    OpenClockWindow(QWidget *parent, Configuration & cconfig);

private:

    Configuration & m_config;
    ClockContainer * clockContainer;

private slots:
    void updateClocks();

};


