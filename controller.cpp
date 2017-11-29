#include "controller.h"
#include "phonebook.pb.h"

#include <QDataStream>

QByteArray serialize(std::string &msg, Controller::Operation cmd)
{
    QByteArray data;
    data = QByteArray::fromStdString(msg);
    data.push_front(static_cast<uint8_t>(cmd));

    return data;
}

Controller::Controller(QObject *parent) : QObject(parent)
{
    dataBaseHelper.reset(new DbHelper(this));
    network_agent = new NetworkAgent();
    connect(network_agent, &NetworkAgent::sendData, this, &Controller::onSendData);
    connect(network_agent, &NetworkAgent::changeStatus, this, &Controller::onChangeStatus);
    connect(this, &Controller::sendData, network_agent, &NetworkAgent::onSendData);
}

Controller::~Controller()
{
    delete network_agent;
    delete phoneBookModel;
    delete connectionModel;
}

bool Controller::init()
{
    phoneBookModel = new SqlQueryModel();
    phoneBookModel->setTableName("person");
    phoneBookModel->setRole(SqlQueryModel::IdRole, "id");
    phoneBookModel->setRole(SqlQueryModel::NameRole, "name");
    phoneBookModel->setRole(SqlQueryModel::PhoneRole, "phone");
    phoneBookModel->setRole(SqlQueryModel::CountryRole, "country");

    connectionModel = new SqlQueryModel();
    connectionModel->setTableName("client");
    connectionModel->setRole(SqlQueryModel::IdRoles, "id");
    connectionModel->setRole(SqlQueryModel::NameRoles, "name");
    connectionModel->setRole(SqlQueryModel::StatusRoles, "status");

    QString dbName;
    if (network_agent->isServer())
        dbName = "phoneBook.sqlite3";
    else
        dbName = ":memory:";

    if (!dataBaseHelper->connectToDataBase(dbName))
        return false;
    phoneBookModel->updateModel();
    connectionModel->updateModel();
    return true;
}

void Controller::getAllRecords(const SqlQueryModel *model, stc::Message &message)
{
    int rowCount = model->rowCount();
    for(int i = 0; i < rowCount; ++i)
    {
        QVariantList rowData = model->rowData(i);
        protobufHelper.addRecord(message, rowData);
    }
}

// request to modify model or get all data model
// 0x01 - delete record
// 0x10 - insert record
// 0x11 - get all data
// default client change status
void Controller::onSendData(qintptr handle, QByteArray data)
{
    Controller::Operation command = static_cast<Controller::Operation>(data.at(0));
    data.remove(0, 1);

    stc::Message message;

    switch(command) {
    case Operation::Remove:
    {
        if (message.ParseFromString(data.toStdString()))
        {
            for (int i = 0; i < message.personrecord_size(); ++i)
            {
                auto variantDataList = protobufHelper.getPersonData(message, i);
                removeRow(dataBaseHelper->find(variantDataList));
            }
        }
        if (network_agent->isServer())
        {
            data.push_front(static_cast<uint8_t>(Operation::Remove));
            emit sendData(-handle, data);
        }
        break;
    }
    case Operation::Insert:
    {
        connecting = true;

        bool ok;
        if (message.ParseFromString(data.toStdString()))
        {
            for (int i = 0; i < message.personrecord_size(); ++i)
            {
                auto variantDataList = protobufHelper.getPersonData(message, i);
                inserRow(variantDataList);
            }
            for (int i = 0; i < message.clientrecord_size(); ++i)
            {
                auto variantDataList = protobufHelper.getClientData(message, i);
                clientChange(variantDataList[0].toString(), variantDataList[1].toString().toInt(&ok));
            }
            if (network_agent->isServer())
            {
                data.push_front(0x10);
                emit sendData(-handle, data);
            }
        }
        break;
    }
    case Operation::GetAll:
    {
        clientChange(data, 1);
        clientMap.insert(handle, data);

        sendAllRecords(handle);

        int rowCount = connectionModel->rowCount();
        for(int i = 0; i < rowCount; ++i)
        {
            auto clientDataList = connectionModel->rowData(i);
            protobufHelper.addClient(message, clientDataList);
        }

        std::string msg;
        message.SerializeToString(&msg);

        emit sendData(-handle, serialize(msg, Operation::Insert));

        break;
    }
    default:
    {
        clientChange(QString(data), static_cast<uint8_t>(command));

        if (network_agent->isServer())
        {
            // send to other clients
            QVariantList clientDataList;
            clientDataList << QString(data) << QString::number(static_cast<uint8_t>(command));
            protobufHelper.addClient(message, clientDataList);

            std::string msg;
            message.SerializeToString(&msg);

            emit sendData(-handle, serialize(msg, Operation::Other));
        }
        break;
    }
    }
}

void Controller::onChangeStatus(qintptr handle, int status)
{
    if (network_agent->isServer())
    {
        QString name = *clientMap.find(handle);
        clientChange(name, status);
        clientMap.remove(handle);

        stc::Message message;
        getAllRecords(connectionModel, message);

        std::string msg;
        message.SerializeToString(&msg);

        emit sendData(-handle, serialize(msg, Operation::Insert));
    }
    else{
        if(status == 0)
            connecting = false;
        else
            connecting = true;
    }
}

void Controller::removeRow(int id)
{
    if (id < 0)
    {
        qDebug() << "Controller remove row: id < 0";
        return;
    }

    dataBaseHelper->remove(id);
    phoneBookModel->updateModel();
}

void Controller::inserRow(const QVariantList& variantDataList)
{
    dataBaseHelper->append(variantDataList);
    phoneBookModel->updateModel();
}

void Controller::sendAllRecords(qintptr handle)
{
    stc::Message message;
    getAllRecords(phoneBookModel, message);
    getAllRecords(connectionModel, message);

    std::string msg;
    message.SerializeToString(&msg);

    emit sendData(handle, serialize(msg, Operation::Insert));
}

void Controller::removeRecord(int id, int index)
{
    if(!network_agent->isServer() && !connecting)
        return;

    QVariantList rowData;
    rowData = phoneBookModel->rowData(index);

    removeRow(id);

    std::string msg;
    stc::Message message;
    protobufHelper.addPerson(message, rowData);
    message.SerializeToString(&msg);

    qintptr handle = 0;
    emit sendData(handle, serialize(msg, Operation::Remove));
}

// from network
void Controller::insertRecord(QVariantList &rowData)
{
    QString name = rowData[0].toString();
    QString phone = rowData[1].toString();
    QString country = rowData[2].toString();

    insertRecord(name, phone, country);
}

// from ui
void Controller::insertRecord(const QString& name, const QString& phone, const QString& country)
{
    if(!network_agent->isServer() && !connecting)
        return;

    // insert to table
    QVariantList rowData;
    rowData << name << phone << country;

    inserRow(rowData);

    // send to other clients
    std::string msg;
    stc::Message message;
    protobufHelper.addPerson(message, rowData);
    message.SerializeToString(&msg);

    qintptr handle = 0;
    emit sendData(handle, serialize(msg, Operation::Insert));
}

SqlQueryModel* Controller::getTableModel(ModelType select)
{
    if (select == ModelType::Connection)
        return connectionModel;
    else
        return phoneBookModel;
}

void Controller::clientChange(QString name, int status)
{
    dataBaseHelper->append(name, status);
    connectionModel->updateModel();
}

void Controller::exportImport(int command, QString path)
{
    if(!network_agent->isServer() && !connecting)
        return;

    // remove "file://"
    path.remove(0, 7);

    int rowCount = phoneBookModel->rowCount();

    auto operationId = static_cast<ExImOperationType::ExImOperation>(command);
    QScopedPointer<ExImHelper> exImHelper;
    if (operationId == ExImOperationType::ExImOperation::ImportJson ||
            operationId == ExImOperationType::ExImOperation::ExportJson)
        exImHelper.reset(new JsonHelper);
    else
        exImHelper.reset(new XmlHelper);

    if (operationId == ExImOperationType::ExImOperation::ImportJson ||
            operationId == ExImOperationType::ExImOperation::ImportXml)
    {
        for(int i = rowCount; i > 0; --i)
            removeRecord(phoneBookModel->getId(i-1), i-1);

        exImHelper->load(path);
        while(exImHelper->read())
        {
            QVariantList rowData = exImHelper->getData();
            insertRecord(rowData);
        }
        phoneBookModel->updateModel();
    }
    else
    {
        for(int i = 0; i < rowCount; ++i)
        {
            QVariantList rowData = phoneBookModel->rowData(i);
            exImHelper->write(rowData);
        }
        exImHelper->save(path);
    }
}
