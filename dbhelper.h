#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlRecord>

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

class DbHelper : public QObject
{
    Q_OBJECT
public:
    explicit DbHelper(QObject *parent = 0);
    ~DbHelper();
    bool connectToDataBase(const QString& name);

public:
    bool append(QString name, int status);
    bool append(const QVariantList &data);
    bool remove(const int id);
    int find(const QVariantList &data);

private:
    QSqlDatabase db;

    bool openDataBase(const QString& name);
    void closeDataBase();
    bool createTable(const QString& tableName, const QString& str);
};

#endif // DB_HELPER_H
