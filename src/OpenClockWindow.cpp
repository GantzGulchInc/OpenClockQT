#include "OpenClockWindow.h"
#include "ClockContainer.h"
#include "DigitalClockFace.h"

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>
#include <QTextEdit>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

OpenClockWindow::OpenClockWindow(QWidget * parent) : QMainWindow(parent) {

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

    ClockConfiguration * c = new ClockConfiguration();

    DigitalClockFace * clockFace1 = new DigitalClockFace(clockContainer, c);
    clockContainer->addClockFace(clockFace1);

    DigitalClockFace * clockFace2 = new DigitalClockFace(clockContainer, c);
    clockContainer->addClockFace(clockFace2);

    DigitalClockFace * clockFace3 = new DigitalClockFace(clockContainer, c);
    clockContainer->addClockFace(clockFace3);

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
