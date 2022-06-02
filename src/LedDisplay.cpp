#include "LedDisplay.h"

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

LedDisplay::LedDisplay(QWidget * parent, const QString & text, const QString & shadow) : QWidget(parent), text(text), shadow(shadow) {


    font.fromString("DSEG14 Modern");
    font.setPointSize(36);

    QFontMetrics fm(font);

    textWidth = fm.width(text);
    textHeight = fm.height();
    textAscent = fm.ascent();

    qDebug() << "LedDisplay: textWidth: " << textWidth << " textHeight: " << textHeight;

    setFixedWidth(textWidth + 10);
    setFixedHeight(textHeight + 10);
}

void LedDisplay::paintEvent(QPaintEvent *event)  {

    qDebug() << "paintEvent: Called: text: " << text;

    QPainter painter(this);
    painter.setFont(font);


    int sWidth = size().width();
    int sHeight = size().height();

    qDebug() << "paintEvent: sWidth: " << sWidth << " sHeight: " << sHeight;

    // painter.fillRect(0, 0, sWidth, sHeight, QColor(0, 0, 0));

    painter.setPen(QColor(0, 75, 0));
    painter.drawText(5, textAscent + 5, shadow);

    painter.setPen(Qt::green);
    painter.drawText(5, textAscent + 5, text);
}

void LedDisplay::update(const QString & text) {

    this->text = text;

    this->repaint();
}

