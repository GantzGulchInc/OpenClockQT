#include "OpenClockWindow.h"
#include "ClockContainer.h"
#include "ClockFaceLed.h"
#include "ConfigurationJson.h"

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


    clockContainer = new ClockContainer(this);
    setCentralWidget(clockContainer);

    ClockFace * clockFace = nullptr;
    QString type{"Led"};
    QString defaultType{"Led"};

    for(QJsonObject json : m_config.clockConfigs()) {


        ConfigurationJson::getString(json["type"], type, defaultType);

        qDebug() << "OpenClockWindow::ctor: type: " << type;

        if( type == "Led" ) {
            clockFace = new ClockFaceLed(clockContainer);
        } else {
            qWarning() << "Unknown clock face type: " << type;
        }

        if( clockFace != nullptr ) {

            qDebug() << "OpenClockWindow: add clock face: 1";

            clockFace->configure(json);

            qDebug() << "OpenClockWindow: add clock face: 2";

            clockContainer->addClockFace(clockFace);
        }

        clockFace = nullptr;
        type = "Led";
    }



    statusBar()->showMessage("Ready");

    QTimer * timer = new QTimer(this);

    connect(timer, &QTimer::timeout, clockContainer, &ClockContainer::updateClocks);

    timer->start(1000);

}


void OpenClockWindow::updateClocks() {

    qDebug() << "Timer event";

    QDateTime dateTime = QDateTime::currentDateTimeUtc();

    clockContainer->updateClocks();
}
