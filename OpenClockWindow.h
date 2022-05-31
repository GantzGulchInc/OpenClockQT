#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

class OpenClockWindow : public QMainWindow {

    Q_OBJECT

public:
    OpenClockWindow(QWidget *parent = nullptr);

private:
    QTextEdit *edit;

private slots:
    void updateClocks();

};


