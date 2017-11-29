#ifndef EXIMHELPER_H
#define EXIMHELPER_H

#include <QString>
#include <QVariantList>

class ExImHelper
{
public:
    virtual ~ExImHelper() = default;
    virtual bool load(QString &path) = 0;
    virtual bool save(QString &path) = 0;
    virtual bool read() = 0;
    virtual void write(const QVariantList &data) = 0;
    virtual QVariantList getData() = 0;
};

class ExImOperationType: public QObject
{
    Q_OBJECT
public:
    enum class ExImOperation {
        ImportJson = 0,
        ExportJson = 1,
        ImportXml = 2,
        ExportXml = 3
    };
    Q_ENUM(ExImOperation)
};

#endif // EXIMHELPER_H
