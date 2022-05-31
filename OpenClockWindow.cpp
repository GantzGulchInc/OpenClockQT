#include "OpenClockWindow.h"

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


    edit = new QTextEdit(this);
    edit->setText("0");

    setCentralWidget(edit);

    statusBar()->showMessage("Ready");


    QTimer * timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &OpenClockWindow::updateClocks);

    timer->start(1000);

}


void OpenClockWindow::updateClocks() {

    qDebug() << "Timer event";

    QDateTime dateTime = QDateTime::currentDateTimeUtc();


    QString s = dateTime.toString(Qt::DateFormat::ISODate);

    edit->setText(s);
}
