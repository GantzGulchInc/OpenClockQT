#include "ConfigurationDisplay.h"
#include "ConfigurationJson.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

ConfigurationDisplay::ConfigurationDisplay() {
    m_columns = 2;
    m_background = QColor("#000000");
}

void ConfigurationDisplay::update(QJsonObject & json) {

    qDebug() << "ConfigurationDisplay: update: called";

    int cols = ConfigurationJson::getInt(json, "columns", 2);


    qDebug() << "ConfigurationDisplay::update: cols: " << cols;

    this->m_columns = cols;

    qDebug() << "ConfigurationDisplay: update: called 1";

    m_background = ConfigurationJson::getColor(json, "background", QColor(0,0,0));

    qDebug() << "ConfigurationDisplay: update: called 2";
}

int ConfigurationDisplay::columns() {
    return m_columns;
}

QColor ConfigurationDisplay::background() {
    return m_background;
}
