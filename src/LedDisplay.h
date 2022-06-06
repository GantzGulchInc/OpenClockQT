#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QFont>

class LedDisplay : public QWidget {

    Q_OBJECT

public:
    LedDisplay(QWidget *parent);

    void configure(QFont & font, QColor & textColor, QColor & shadowColor, QString & text, QString & shadow);

    void update(const QString & text);

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QFont m_font {"DSEG14 Modern", 28};
    QColor m_textColor{"#ffffff"};
    QColor m_shadowColor{"#404040"};
    int m_textHeight;
    int m_textWidth;
    int m_textAscent;
    int m_textXOffset;
    QString m_text{"abc"};
    QString m_shadow{"abc"};


    void updateUI();

// private slots:
//    void updateClocks();

};


