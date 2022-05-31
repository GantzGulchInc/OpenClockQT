#include "simple.h"

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>


TestWidget::TestWidget(QWidget * parent) : QMainWindow(parent) {

//    auto * frame1 = new QFrame(this);
//    frame1->setFrameStyle(QFrame::Box);
//    frame1->setCursor(Qt::SizeAllCursor);

//    auto * frame2 = new QFrame(this);
//    frame2->setFrameStyle(QFrame::Box);
//    frame2->setCursor(Qt::WaitCursor);

//    auto * frame3 = new QFrame(this);
//    frame3->setFrameStyle(QFrame::Box);
//    frame3->setCursor(Qt::PointingHandCursor);

//    auto * grid = new QGridLayout(this);
//    grid->addWidget(frame1, 0, 0);
//    grid->addWidget(frame2, 0, 1);
//    grid->addWidget(frame3, 0, 2);





//    auto *quitBtn = new QPushButton("Quit", this);
//    quitBtn->setGeometry(50, 40, 75, 30);

//    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);





//    auto * plsBtn = new QPushButton("+", this);
//    auto * minBtn = new QPushButton("-", this);

//    lbl = new QLabel("0", this);

//    auto * grid = new QGridLayout(this);
//    grid->addWidget(plsBtn, 0, 0);
//    grid->addWidget(minBtn, 0, 1);
//    grid->addWidget(lbl, 1, 2);
//    setLayout(grid);
//    connect(plsBtn, &QPushButton::clicked, this, &TestWidget::OnPlus);
//    connect(minBtn, &QPushButton::clicked, this, &TestWidget::OnMinus);


    QPixmap newpix("/usr/share/icons/gnome/32x32/actions/document-new.png");
    QPixmap openpix("/usr/share/icons/gnome/32x32/actions/document-open.png");
    QPixmap quitpix("/usr/share/icons/gnome/32x32/actions/exit.png");

    auto * newa = new QAction(newpix, "&New", this);
    auto * open = new QAction(openpix, "&Open", this);
    auto * quit = new QAction(quitpix, "&Quit", this);
    quit->setShortcut(tr("CTRL+W"));

    QMenu * file = menuBar()->addMenu("&File");
    file->addAction(newa);
    file->addAction(open);
    file->addSeparator();
    file->addAction(quit);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);

}


