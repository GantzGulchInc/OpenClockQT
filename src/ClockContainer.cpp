#include "ClockContainer.h"
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
#include <QVBoxLayout>
#include <QFont>
#include <QPainter>
#include <QDebug>

ClockContainer::ClockContainer(QWidget * parent) : QWidget(parent) {

    layout = new QGridLayout(this);
    layout->setVerticalSpacing(5);
    layout->setHorizontalSpacing(5);
    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 1);
    columnCount = 2;
    currentRow = 0;
    currentColumn = 0;

    setAutoFillBackground(true);

    QPalette p = palette();

    p.setColor(backgroundRole(), Qt::black);

    setPalette(p);

    setLayout(layout);
}

void ClockContainer::addClockFace(ClockFace * clockFace) {

    clockList.append(clockFace);

    layout->addWidget(clockFace, currentRow, currentColumn, 1, 1, Qt::AlignVCenter);

    currentColumn += 1;

    if( currentColumn == columnCount ) {
        currentColumn = 0;
        currentRow += 1;
    }
}

void ClockContainer::updateClocks() {

    qDebug() << "ClockContainer::updateClocks: called.";

    QDateTime dateTime = QDateTime::currentDateTimeUtc();

    for(ClockFace * clockFace : clockList) {
        clockFace->update(dateTime);
    }
}
