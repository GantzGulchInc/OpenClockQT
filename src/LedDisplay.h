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
    LedDisplay(QWidget *parent, const QString & text, const QString & shadow);
    void update(const QString & text);

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QFont font;
    int textHeight;
    int textWidth;
    int textAscent;
    int textXOffset;
    QString text;
    QString shadow;

// private slots:
//    void updateClocks();

};


