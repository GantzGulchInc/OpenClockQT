#pragma once

#include "Configuration.h"
#include "ClockContainer.h"

#include <QWidget>
#include <QMainWindow>


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


