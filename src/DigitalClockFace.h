#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

class DigitalClockFace : public QWidget {

    Q_OBJECT

public:
    DigitalClockFace(QWidget *parent = nullptr);
    void update(const QDateTime & dateTime);

private:
    QLabel *title;
    QLabel *time;
    QLabel *date;

// private slots:
//    void updateClocks();

};


