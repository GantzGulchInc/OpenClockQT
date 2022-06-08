#include "ClockContainer.h"

#include <QWidget>
#include <QGridLayout>
#include <QDebug>
#include <QDateTime>
#include <QDebug>

ClockContainer::ClockContainer(QWidget * parent) : QWidget(parent) {

    m_layout = new QGridLayout(this);
    m_layout->setVerticalSpacing(5);
    m_layout->setHorizontalSpacing(5);
    m_layout->setColumnStretch(0, 1);
    m_layout->setColumnStretch(1, 1);

    m_columnCount = 2;
    m_currentRow = 0;
    m_currentColumn = 0;

    setAutoFillBackground(true);

    QPalette p = palette();

    p.setColor(backgroundRole(), Qt::black);

    setPalette(p);

    setLayout(m_layout);
}

void ClockContainer::addClockFace(ClockFace * clockFace) {

    m_clockList.append(clockFace);

    m_layout->addWidget(clockFace, m_currentRow, m_currentColumn, 1, 1, Qt::AlignVCenter);

    m_currentColumn += 1;

    if( m_currentColumn == m_columnCount ) {
        m_currentColumn = 0;
        m_currentRow += 1;
    }
}

void ClockContainer::updateClocks() {

    QDateTime dateTime = QDateTime::currentDateTimeUtc();

    for(ClockFace * clockFace : m_clockList) {
        clockFace->update(dateTime);
    }
}
