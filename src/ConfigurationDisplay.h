#pragma once

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QColor>
#include <QTimeZone>
#include <QList>


namespace gantzgulch {
namespace openclock {

class ConfigurationDisplay  {

public:
    ConfigurationDisplay();
    void update(QJsonObject & json);

    int columns();
    QColor background();

private:
    int m_columns;
    QColor m_background;


};

}
}
