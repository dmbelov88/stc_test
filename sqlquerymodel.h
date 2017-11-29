#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class SqlQueryModel : public QSqlQueryModel
{
  Q_OBJECT
public:
  enum Roles {
    IdRole = Qt::UserRole + 1,
    NameRole,
    PhoneRole,
    CountryRole,
  };

  enum ConnectionRoles {
    IdRoles = Qt::UserRole + 1,
    NameRoles = Qt::UserRole + 2,
    StatusRoles = Qt::UserRole + 3
  };

  explicit SqlQueryModel(QObject *parent = 0);

  void setTableName(QString name);
  void setRole(int, QByteArray);
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariantList rowData(const int &index) const;
  void appendRow(QVariantList variantDataList);

protected:
  QHash<int, QByteArray> roleNames() const;

signals:

public slots:
  int getId(int row);
  void updateModel();

private:
  QString tableName;
  QHash<int, QByteArray> roles;
};

#endif // LISTMODEL_H
