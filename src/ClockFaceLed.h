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

class ClockFaceLed : public ClockFace {

    Q_OBJECT

public:
    ClockFaceLed(QWidget *parent);
    void configure(QJsonObject & json);
    void update(const QDateTime & now);

    static QString DEFAULT_TITLE;
    static QTimeZone DEFAULT_TIMEZONE;
    static QString DEFAULT_FONT_FAMILY;
    static int DEFAULT_FONT_HEIGHT;
    static QColor DEFAULT_COLOR;
    static QColor DEFAULT_SHADOW_COLOR;
    static QString DEFAULT_TIME_FORMAT;
    static QString DEFAULT_DATE_FORMAT;
    static QColor DEFAULT_BACKGROUND;

private:
    QString m_type{"Led"};
    QTimeZone m_timeZone{"America/Detroit"};

    QColor m_background{"#000000"};

    QString m_title{"America Detroit"};
    QString m_titleFontFamily{"DSEG14 Modern"};
    int m_titleFontHeight{28};
    bool m_titleFontBold{false};
    bool m_titleFontItalic{false};
    QFont m_titleFont{m_titleFontFamily, m_titleFontHeight};
    QColor m_titleColor{"#ffffff"};
    QColor m_titleShadowColor{"#404040"};
    QString m_titleShadow{"~~~~~~~ ~~~~~~~"};

    QString m_timeFontFamily{"DSEG14 Modern"};
    int m_timeFontHeight{28};
    bool m_timeFontBold{false};
    bool m_timeFontItalic{false};
    QFont m_timeFont{m_titleFontFamily, m_titleFontHeight};
    QColor m_timeColor{"#00D000"};
    QColor m_timeShadowColor{"#004000"};
    QString m_timeFormat{"hh:MM:ss"};
    QString m_timeShadow{"~~:~~:~~"};


    QString m_dateFontFamily{"DSEG14 Modern"};
    int m_dateFontHeight{28};
    bool m_dateFontBold{false};
    bool m_dateFontItalic{false};
    QFont m_dateFont{m_titleFontFamily, m_titleFontHeight};
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


