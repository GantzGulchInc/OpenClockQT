#include "ConfigurationDisplay.h"
#include "ConfigurationJson.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>


namespace gantzgulch {
namespace openclock {


ConfigurationDisplay::ConfigurationDisplay() {
    m_columns = 2;
    m_background = QColor("#000000");
}

void ConfigurationDisplay::update(QJsonObject & json) {

    this->m_columns = ConfigurationJson::getInt(json, "columns", 2);

    m_background = ConfigurationJson::getColor(json, "background", QColor(0,0,0));
}

int ConfigurationDisplay::columns() {
    return m_columns;
}

QColor ConfigurationDisplay::background() {
    return m_background;
}


}
}
