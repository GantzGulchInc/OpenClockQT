#pragma once

#include "Configuration.h"
#include "ClockContainer.h"

#include <QWidget>
#include <QMainWindow>
#include <QTimer>

namespace gantzgulch {
namespace openclock {

class OpenClockWindow : public QMainWindow {

    Q_OBJECT

public:
    OpenClockWindow(QWidget *parent, Configuration & cconfig);

private:

    Configuration & m_config;
    ClockContainer * m_clockContainer;
    QTimer * m_timer;

    void createToolBar();
    void createStatusBar();
    void createClocks();
    void createTimer();


private slots:
    void updateClocks();

};



}
}
