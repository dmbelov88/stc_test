#include "sqlquerymodel.h"
#include <QDebug>

SqlQueryModel::SqlQueryModel(QObject *parent) :
    QSqlQueryModel(parent)
{}

void SqlQueryModel::setTableName(QString name)
{
    tableName = name;
}

void SqlQueryModel::setRole(int key, QByteArray value)
{
    roles[key] = value;
}

QVariant SqlQueryModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QVariantList SqlQueryModel::rowData(const int &rowIndex) const
{
    QVariantList variantList;
    int size = roles.size();
    for(int i = Qt::UserRole + 2; i < Qt::UserRole + 1 + size; ++i)
        variantList << data(index(rowIndex, 0), i);
    return variantList;
}

QHash<int, QByteArray> SqlQueryModel::roleNames() const
{
    return roles;
}

void SqlQueryModel::updateModel()
{
    setQuery("select * from " + tableName);
}

int SqlQueryModel::getId(int row)
{
    return data(index(row, 0), IdRole).toInt();
}
