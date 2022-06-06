#include "Configuration.h"

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QJsonArray>

Configuration::Configuration() {

}


bool Configuration::readFile(const QString & path, QByteArray & bytes) {

    QFile file;

    qDebug() << "Configuration::readFile: Reading: " << path;

    file.setFileName(path);

    if( file.open(QIODevice::ReadOnly)) {

        bytes = file.readAll();

        file.close();

        return true;

    }

    qWarning() << "Configuration::readFile: Error opening file.";

    return false;
}

bool Configuration::parseJson(const QByteArray & data) {

    document = QJsonDocument::fromJson(data, &jsonError);

    if( jsonError.error != QJsonParseError::NoError ) {

        qWarning() << "Configuration::parseJson: Error parsing json: " << jsonError.errorString() << " Offset: " << jsonError.offset;

        return false;
    }

    qDebug() << "Configuration::parseJson: Read: " << document.toJson();

    if( document.isObject() ) {

        qDebug() << "Configuration::parseJson: Document is an object.";

        jsonObject = document.object();

        return true;

    } else {
        qDebug() << "Configuration::parseJson: Document is NOT an object.";
    }

    return false;
}

bool Configuration::load() {

    QString path = QDir::homePath() + "/.openclock/openclock.json";

    QByteArray data;

    if( !  readFile(path, data) ) {

        qWarning() << "Configuration::load: read failed.";

        return false;

    };

    if( ! parseJson(data) ) {

        qWarning() << "Configuration load: parse failed.";

        return false;
    };


    qDebug() << "Configuration::load: Looking for display.";

    QJsonValue displayValue = jsonObject["display"];

    qDebug() << "Configuration::load: Found display.";

    if( displayValue.isObject() ) {

        qDebug() << "Configuration::load: Found display.";

        QJsonObject displayObject = displayValue.toObject();

        configDisplay.update(displayObject);
    }

    qDebug() << "Configuration::load: Looking for faces.";

    QJsonValue configArray = jsonObject["clockFaces"];

    if( configArray.isArray() ) {

        QJsonArray array = configArray.toArray();

        for(int i=0; i<array.size(); i++ ) {

            QJsonValue v = array[i];

            if( v.isObject() ) {
                m_clockConfigs.append(v.toObject());
            }
        }

    }

    qDebug() << "Configuration::load: Done.";

    return true;
}

QList<QJsonObject> Configuration::clockConfigs() {
    return m_clockConfigs;
}







