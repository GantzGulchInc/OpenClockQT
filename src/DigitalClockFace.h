#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QFont>
#include <QGridLayout>
#include <QTimeZone>

#include "ClockFace.h"
#include "LedDisplay.h"

class DigitalClockFace : public ClockFace {

    Q_OBJECT

public:
    DigitalClockFace(QWidget *parent);
    void configure(QJsonObject & json);
    void update(const QDateTime & now);

private:
    QString m_type{"Led"};
    QTimeZone m_timeZone{"America/Detroit"};

    QColor m_background{"#000000"};

    QString m_title{"America Detroit"};
    QFont m_titleFont{"DSEG14 Modern", 28};
    QColor m_titleColor{"#ffffff"};
    QColor m_titleShadowColor{"#404040"};
    QString m_titleShadow{"~~~~~~~ ~~~~~~~"};

    QFont m_timeFont{"DSEG14 Modern", 28};
    QColor m_timeColor{"#00D000"};
    QColor m_timeShadowColor{"#004000"};
    QString m_timeFormat{"hh:MM:ss"};
    QString m_timeShadow{"~~:~~:~~"};

    QFont m_dateFont{"DSEG14 Modern", 28};
    QColor m_dateColor{"#00C000"};
    QColor m_dateShadowColor{"#004000"};
    QString m_dateFormat{"yyyy-mm-dd"};
    QString m_dateShadow{"~~~~-~~-~~"};

    QGridLayout * m_layout;

    LedDisplay *m_titleLedDisplay;
    LedDisplay *m_timeLedDisplay;
    LedDisplay *m_dateLedDisplay;

    void updateUI();

// private slots:
//    void updateClocks();

};


