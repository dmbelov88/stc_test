#include "networkagent.h"

#include <QDataStream>

NetworkAgent::NetworkAgent(QObject *parent) : QObject(parent)
{
    client = new TcpClient();
    if (!client->connecting())
    {
        delete client;
        client = Q_NULLPTR;
        server = new TcpServer();
        server->start();

        connect(server, &TcpServer::send, this, &NetworkAgent::onSend);
        connect(server, &TcpServer::changeStatus, this, &NetworkAgent::onChangeStatus);
    }
    else
    {
        server = Q_NULLPTR;
        connect(client, &TcpClient::send, this, &NetworkAgent::onSend);
        connect(client, &TcpClient::changeStatus, this, &NetworkAgent::onChangeStatus);
    }
}

NetworkAgent::~NetworkAgent()
{
    if (server != Q_NULLPTR)
        delete server;

    if (client != Q_NULLPTR)
        delete client;
}

void NetworkAgent::onSend(qintptr handle, QByteArray data)
{
    emit sendData(handle, data);
}

bool NetworkAgent::isServer()
{
    if (server != Q_NULLPTR)
        return true;
    else
        return false;
}

void NetworkAgent::onSendData(qintptr handle, QByteArray data)
{
    if (isServer())
        server->response(handle, data);
    else
        client->response(data);
}

void NetworkAgent::onChangeStatus(qintptr handle, int status)
{
    emit changeStatus(handle, status);
}
