#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QStandardItemModel>

#include "dbhelper.h"
#include "jsonhelper.h"
#include "networkagent.h"
#include "phonebook.pb.h"
#include "protobufhelper.h"
#include "sqlquerymodel.h"
#include "xmlhelper.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    enum class Operation {
        Insert = 0x10,
        Remove = 0x01,
        GetAll = 0x11,
        Other = 0x00
    };

    enum class ModelType {
        Person,
        Connection
    };

    bool init();
    SqlQueryModel* getTableModel(Controller::ModelType select);

    bool connecting;

signals:
    void sendData(qintptr handle, QByteArray data);

public slots:
    void onSendData(qintptr handle, QByteArray);
    void onChangeStatus(qintptr handle, int status);
    void removeRecord(int id, int index);
    void insertRecord(const QString& name, const QString& phone, const QString& country);
    void exportImport(int operationId, QString path);

private:
    void getAllRecords(const SqlQueryModel *model, stc::Message &message);

    void clientChange(QString name, int status);

    void removeRow(int id);
    void inserRow(const QVariantList& variantDataList);

    void sendAllRecords(qintptr handle);
    void insertRecord(QVariantList &rowData);

    void importFromJson(QString path);
    void exportToJson(QString path);
    void importFromXml(QString path);
    void exportToXml(QString path);

    QMap<qintptr, QString> clientMap;
    QScopedPointer<DbHelper> dataBaseHelper;
    SqlQueryModel *phoneBookModel;
    SqlQueryModel *connectionModel;
    NetworkAgent *network_agent;
    ProtobufHelper protobufHelper;
};

#endif // CONTROLLER_H
