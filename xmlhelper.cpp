#include "xmlhelper.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>

XmlHelper::XmlHelper()
{
    index = 0;
    buffer.open(QIODevice::WriteOnly);
    xmlWriter.setDevice(&buffer);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement(QString("table"));
}

bool XmlHelper::load(QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    xmlReader.setDevice(&file);

    while (xmlReader.readNextStartElement())
    {
        if (xmlReader.name() == "row")
        {
            QVariantList data;
            while (xmlReader.readNextStartElement())
                data << xmlReader.readElementText();

            array << data;
        }
    }

    return true;
}

bool XmlHelper::save(QString &path)
{
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    buffer.close();

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QByteArray byteArray = buffer.data();
    qint64 size = file.write(byteArray);

    file.flush();
    file.close();
    return byteArray.size() == size ? true : false;
}

bool XmlHelper::read()
{
    if (array.size() > index)
        return true;
    else
        return false;
}

void XmlHelper::write(const QVariantList &data)
{
    xmlWriter.writeStartElement(QString("row"));
    xmlWriter.writeTextElement(QString("name"), data[0].toString());
    xmlWriter.writeTextElement(QString("phone"), data[1].toString());
    xmlWriter.writeTextElement(QString("country"), data[2].toString());
    xmlWriter.writeEndElement();
}

QVariantList XmlHelper::getData()
{
    QVariantList data;

    if (index >= array.size())
        return data;

    data = array.at(index);
    ++index;
    return data;
}
