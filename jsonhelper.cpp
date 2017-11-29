#include "jsonhelper.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

JsonHelper::JsonHelper()
{
    index = 0;
    document.reset(new QJsonDocument());
    document->setArray(QJsonArray());
}

bool JsonHelper::load(QString &path)
{
    index = 0;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QByteArray byteArray = file.readAll();
    *document = QJsonDocument::fromJson(byteArray);

    file.close();
    return document->isEmpty();
}

bool JsonHelper::save(QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QByteArray byteArray = document->toJson();

    qint64 size = file.write(byteArray);

    file.flush();
    file.close();
    return byteArray.size() == size ? true : false;
}

bool JsonHelper::read()
{
    QVariantList List;
    QJsonArray array = document->array();

    if (array.size() > index)
        return true;
    else
        return false;

}

void JsonHelper::write(const QVariantList& data)
{
    QJsonObject object
    {
        {"name", data.at(0).toString()},
        {"phone", data.at(1).toString()},
        {"country", data.at(2).toString()}
    };
    QJsonArray array = document->array();
    array.append(object);
    document->setArray(array);
}

QVariantList JsonHelper::getData()
{
    QVariantList data;

    if (index >= document->array().size())
        return data;

    auto array = document->array().at(index).toVariant().toMap();
    data << array["name"] << array["phone"] << array["country"];
    ++index;
    return data;
}

