#ifndef JSONHELPER_H
#define JSONHELPER_H

#include "eximhelper.h"

#include <QJsonDocument>
#include <QString>
#include <QScopedPointer>
#include <QVariant>

class JsonHelper: public ExImHelper
{
public:
    JsonHelper();

    bool load(QString &path);
    bool save(QString &path);
    bool read();
    void write(const QVariantList &data);
    QVariantList getData();

private:
    uint64_t index;
    QScopedPointer<QJsonDocument> document;
};

#endif // JSONHELPER_H
