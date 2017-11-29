#ifndef XMLHELPER_H
#define XMLHELPER_H

#include "eximhelper.h"

#include <QBuffer>
#include <QString>
#include <QVariant>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class XmlHelper: public ExImHelper
{
public:
    XmlHelper();

    bool load(QString &path);
    bool save(QString &path);
    bool read();
    void write(const QVariantList &data);
    QVariantList getData();

private:
    uint64_t index;
    QBuffer buffer;
    QList<QVariantList> array;
    QXmlStreamReader xmlReader;
    QXmlStreamWriter xmlWriter;
};

#endif // XMLHELPER_H
