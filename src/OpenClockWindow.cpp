#include "OpenClockWindow.h"
#include "ClockContainer.h"
#include "ClockFaceLed.h"
#include "ConfigurationJson.h"
#include "ClockLogging.h"

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>
#include <QTextEdit>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

OpenClockWindow::OpenClockWindow(QWidget * parent, Configuration & config) : QMainWindow(parent), m_config(config) {

    createToolBar();
    createStatusBar();
    createClocks();
    createTimer();

}

void OpenClockWindow::createClocks() {

    m_clockContainer = new ClockContainer(this);
    setCentralWidget(m_clockContainer);

    ClockFace * clockFace = nullptr;
    QString type{"Led"};
    QString defaultType{"Led"};

    for(QJsonObject json : m_config.clockConfigs()) {


        ConfigurationJson::getString(json["type"], type, defaultType);

        qCDebug(ocUi) << "ctor: type: " << type;

        if( type == "Led" ) {
            clockFace = new ClockFaceLed(m_clockContainer);
        } else {
            qWarning() << "Unknown clock face type: " << type;
        }

        if( clockFace != nullptr ) {

            clockFace->configure(json);

            m_clockContainer->addClockFace(clockFace);
        }

        clockFace = nullptr;
        type = "Led";
    }




}

void OpenClockWindow::createToolBar() {

    QPixmap newpix("/usr/share/icons/gnome/32x32/actions/document-new.png");
    QPixmap openpix("/usr/share/icons/gnome/32x32/actions/document-open.png");
    QPixmap quitpix("/usr/share/icons/gnome/32x32/actions/exit.png");

    auto * quit = new QAction("&Quit", this);

    QMenu * file = menuBar()->addMenu("&File");
    file->addAction(quit);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QToolBar * toolbar = addToolBar("main toolbar");
    toolbar->addAction(QIcon(newpix), "New File");
    toolbar->addAction(QIcon(openpix), "Open File");
    toolbar->addSeparator();

    QAction *quit2 = toolbar->addAction(QIcon(quitpix), "Quit Application");
    connect(quit2, &QAction::triggered, qApp, &QApplication::quit);

}

void OpenClockWindow::createStatusBar() {

    statusBar()->showMessage("Ready");

}

void OpenClockWindow::createTimer() {

    m_timer = new QTimer(this);

    connect(m_timer, &QTimer::timeout, m_clockContainer, &ClockContainer::updateClocks);

    m_timer->start(1000);

}

void OpenClockWindow::updateClocks() {

    qCDebug(ocUi) << "updateClocks: Timer event";

    m_clockContainer->updateClocks();
}
