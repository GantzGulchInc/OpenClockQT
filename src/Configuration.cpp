#include "Configuration.h"

#include <QFile>
#include <QDebug>
#include <QDir>

Configuration::Configuration() {

}



QByteArray Configuration::readFile(const QString & path) {

    QFile file;
    QByteArray data;

    qDebug() << "Configuration::readFile: Reading: " << path;

    file.setFileName(path);

    if( file.open(QIODevice::ReadOnly)) {

        data = file.readAll();

        file.close();

    } else {
        qWarning() << "Configuration::readFile: Error opening file.";
    }

    return data;
}

void Configuration::parseJson(const QByteArray & data) {

    document = QJsonDocument::fromJson(data, &jsonError);

    if( jsonError.error != QJsonParseError::NoError ) {

        qWarning() << "Configuration::parseJson: Error parsing json: " << jsonError.errorString() << " Offset: " << jsonError.offset;

        return;
    }

    qDebug() << "Configuration::parseJson: Read: " << document.toJson();
}

void Configuration::load() {

    QString path = QDir::homePath() + "/.openclock/openclock.json";

    QByteArray data = readFile(path);

    parseJson(data);

}
