#include "Configuration.h"
#include "ClockLogging.h"

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QJsonArray>

Configuration::Configuration() {

}


bool Configuration::readFile(const QString & path, QByteArray & bytes) {

    QFile file;

    qCDebug(ocConfig) << "readFile: Reading: " << path;

    file.setFileName(path);

    if( file.open(QIODevice::ReadOnly)) {

        bytes = file.readAll();

        file.close();

        return true;

    }

    qWarning(ocConfig) << "readFile: Error opening file.";

    return false;
}

bool Configuration::parseJson(const QByteArray & data) {

    m_document = QJsonDocument::fromJson(data, &m_jsonError);

    if( m_jsonError.error != QJsonParseError::NoError ) {

        qWarning(ocConfig) << "parseJson: Error parsing json: " << m_jsonError.errorString() << " Offset: " << m_jsonError.offset;

        return false;
    }

    qDebug(ocConfig) << "parseJson: Read: " << m_document.toJson();

    if( m_document.isObject() ) {

        qDebug(ocConfig) << "parseJson: Document is an object.";

        m_jsonObject = m_document.object();

        return true;

    } else {
        qDebug(ocConfig) << "parseJson: Document is NOT an object.";
    }

    return false;
}

bool Configuration::load() {

    QString path = QDir::homePath() + "/.openclock/openclock.json";

    QByteArray data;

    if( !  readFile(path, data) ) {

        qWarning(ocConfig) << "load: read failed.";

        return false;

    };

    if( ! parseJson(data) ) {

        qWarning(ocConfig) << "load: parse failed.";

        return false;
    };


    QJsonValue displayValue = m_jsonObject["display"];

    if( displayValue.isObject() ) {

        qDebug(ocConfig) << "load: Found display.";

        QJsonObject displayObject = displayValue.toObject();

        m_configDisplay.update(displayObject);
    }

    qDebug(ocConfig) << "load: Looking for faces.";

    QJsonValue configArray = m_jsonObject["clockFaces"];

    if( configArray.isArray() ) {

        QJsonArray array = configArray.toArray();

        for(int i=0; i<array.size(); i++ ) {

            QJsonValue v = array[i];

            if( v.isObject() ) {
                m_clockConfigs.append(v.toObject());
            }
        }

    }

    qDebug(ocConfig) << "load: Done.";

    return true;
}

QList<QJsonObject> Configuration::clockConfigs() {
    return m_clockConfigs;
}







