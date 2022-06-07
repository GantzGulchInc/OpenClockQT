#include "LedDisplay.h"

#include <QWidget>
#include <QDebug>
#include <QFont>
#include <QPainter>
#include <QDebug>

LedDisplay::LedDisplay(QWidget * parent) : QWidget(parent) {
    updateUI();
}

void LedDisplay::configure(QFont & font, QColor & textColor, QColor & shadowColor, QString & text, QString & shadow) {

    m_font = font;
    m_textColor = textColor;
    m_shadowColor = shadowColor;
    m_text = text;
    m_shadow = shadow;

    updateUI();
}


void LedDisplay::updateUI() {

    QFontMetrics fm(m_font);

    QRect r = fm.boundingRect(m_text);

    m_textWidth = r.width();
    m_textHeight = r.height();
    m_textAscent = fm.ascent();
    m_textXOffset = -1 * r.x();

    // qDebug() << "LedDisplay: font: " << m_font;
    // qDebug() << "LedDisplay: text: " << m_text;
    // qDebug() << "LedDisplay: boundingRect: " << r;
    // qDebug() << "LedDisplay: textWidth: " << m_textWidth << " textHeight: " << m_textHeight << " textXOffset: " << m_textXOffset;

    setFixedWidth(m_textWidth + 10);
    setFixedHeight(m_textHeight + 10);
}

void LedDisplay::paintEvent(QPaintEvent *event)  {

    Q_UNUSED(event);

    // qDebug() << "paintEvent: Called: text: " << m_text;

    QPainter painter(this);
    painter.setFont(m_font);

    // qDebug() << "paintEvent: shadowColor: " << m_shadowColor;
    painter.setPen(m_shadowColor);
    painter.drawText(m_textXOffset + 5, m_textAscent + 5, m_shadow);

    // qDebug() << "paintEvent: textColor: " << m_shadowColor;
    painter.setPen(m_textColor);
    painter.drawText(m_textXOffset + 5, m_textAscent + 5, m_text);
}

void LedDisplay::update(const QString & text) {

    this->m_text = text;

    this->repaint();
}

