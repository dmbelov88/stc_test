#include "dbhelper.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

DbHelper::DbHelper(QObject *parent) : QObject(parent)
{}

DbHelper::~DbHelper()
{
    closeDataBase();
}

bool DbHelper::connectToDataBase(const QString& name)
{
    if(openDataBase(name)) {
        QString personQuery("create table if not exists person (id integer primary key "
                            "autoincrement not null, name varchar(20) not null, phone"
                            " varchar(10) not null, country varchar(10) not null)");
        QString clientsQuery("create table if not exists client (id integer primary key "
                             "autoincrement not null, name varchar(20) not null, "
                             "status int)");

        if (createTable("person", personQuery) && createTable("client", clientsQuery))
        {
            return true;

            QSqlQuery query;
            query.prepare("insert into person ('name', 'phone', 'country') values(:name, :phone, :country)");
            query.bindValue(":name", "qw");
            query.bindValue(":phone", "123456");
            query.bindValue(":country", "USA");
            if(query.exec())
                return true;
        }
    }
    return false;
}

bool DbHelper::openDataBase(const QString& name)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(name);
    if(db.open())
        return true;
    else
        return false;
}

void DbHelper::closeDataBase()
{
    db.close();
}

bool DbHelper::createTable(const QString& tableName, const QString& str)
{
    if (db.tables().contains(tableName))
        return true;

    QSqlQuery query(str);
    if(query.exec())
        return true;
    qDebug() << query.lastError().text();
    return false;
}

bool DbHelper::append(QString name, int status)
{
    QSqlQuery query;
    query.prepare("select * from 'client' where name= :name;");
    query.bindValue(":name", name);

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
        return false;
    }

    if (query.next())
    {
        QString id = query.value(0).toString();
        query.prepare("update client set status = :status where id= :id;");
        query.bindValue(":id", id);
        query.bindValue(":status", QString::number(status));
    }
    else {
        query.prepare("insert into client ('name', 'status') values(:name, :status)");
        query.bindValue(":name", name);
        query.bindValue(":status", QString::number(status));
    }

    if(query.exec())
        return true;

    qDebug() << query.lastError().text();
    return false;
}

bool DbHelper::append(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("insert into person ('name', 'phone', 'country') values(:name, :phone, :country)");
    query.bindValue(":name", data[0].toString());
    query.bindValue(":phone", data[1].toString());
    query.bindValue(":country", data[2].toString());

    if(query.exec())
        return true;

    qDebug() << query.lastError().text();
    return false;
}

bool DbHelper::remove(const int id)
{    
    QSqlQuery query;
    query.prepare("delete from 'person' where id= :id;");
    query.bindValue(":id", id);

    if(query.exec())
    {
        db.commit();
        return true;
    }

    qDebug() << query.lastError().text();
    return false;
}

int DbHelper::find(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("select id from person where name= :name and phone= :phone and country= :country;");
    query.bindValue(":name", data[0].toString());
    query.bindValue(":phone", data[1].toString());
    query.bindValue(":country", data[2].toString());

    if (!query.exec())
    {
        qDebug() << query.lastError().text();
        return -1;
    }

    bool ok;
    if (query.next())
        return query.value(0).toInt(&ok);

    qDebug() << query.lastError().text();
    return -1;
}
