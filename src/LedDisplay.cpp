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

LedDisplay::LedDisplay(QWidget * parent,
                       QFont font,
                       QColor textColor,
                       QColor shadowColor,
                       const QString & text,
                       const QString & shadow) :
    QWidget(parent),
    font(font),
    textColor(textColor),
    shadowColor(shadowColor),
    text(text),
    shadow(shadow) {

    QFontMetrics fm(font);

    QRect r = fm.boundingRect(text);

    textWidth = r.width();
    textHeight = r.height();
    textAscent = fm.ascent();
    textXOffset = -1 * r.x();

    qDebug() << "LedDisplay: text: " << text;
    qDebug() << "LedDisplay: boundingRect: " << r;
    qDebug() << "LedDisplay: textWidth: " << textWidth << " textHeight: " << textHeight << " textXOffset: " << textXOffset;

    setFixedWidth(textWidth + 10);
    setFixedHeight(textHeight + 10);
}

void LedDisplay::paintEvent(QPaintEvent *event)  {

    Q_UNUSED(event);

    qDebug() << "paintEvent: Called: text: " << text;

    QPainter painter(this);
    painter.setFont(font);


    int sWidth = size().width();
    int sHeight = size().height();

    // qDebug() << "paintEvent: sWidth: " << sWidth << " sHeight: " << sHeight;

    // painter.fillRect(0, 0, sWidth, sHeight, QColor(0x40, 0x40, 0x40));

    qDebug() << "paintEvent: shadowColor: " << shadowColor;
    painter.setPen(shadowColor);
    painter.drawText(textXOffset + 5, textAscent + 5, shadow);

    qDebug() << "paintEvent: textColor: " << shadowColor;
    painter.setPen(textColor);
    painter.drawText(textXOffset + 5, textAscent + 5, text);
}

void LedDisplay::update(const QString & text) {

    this->text = text;

    this->repaint();
}

