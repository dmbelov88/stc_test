#include "tcpserver.h"
#include "phonebook.pb.h"

#include <QDataStream>
#include <QTcpSocket>

TcpSocket::TcpSocket(qintptr _handle, QObject *parent):
    QTcpSocket(parent)
{
    handle = _handle;
    setSocketDescriptor(handle);
    connect(this, &QTcpSocket::readyRead, this, &TcpSocket::onReadyRead);
    connect(this, &QTcpSocket::disconnected, this, &TcpSocket::onDisconnected);
}

void TcpSocket::onReadyRead()
{
    emit readyRead(handle);
}

void TcpSocket::onDisconnected()
{
    emit disconnected(handle);
}

TcpServer::TcpServer(QObject *parent):
    QTcpServer(parent)
{
    data_size = 0;
}

TcpServer::~TcpServer()
{
    this->close();
}

void TcpServer::incomingConnection(qintptr handle)
{
    qDebug() << "New connection " << handle;

    TcpSocket *socket = new TcpSocket(handle);

    connect(socket, &TcpSocket::readyRead, this, &TcpServer::onReadyRead);
    connect(socket, &TcpSocket::disconnected, this, &TcpServer::onDisconnected);

    socketMap.insert(handle, socket);
}

void TcpServer::onReadyRead(qintptr handle)
{
    QTcpSocket *socket = *socketMap.find(handle);

    while(socket->bytesAvailable() > data_size)
    {
        if (data_size == 0)
        {
            QByteArray payload = socket->read(sizeof(data_size));
            QDataStream dataStream(payload);
            dataStream >> data_size;
        }
        while ( data_size > 0 )
        {
            QByteArray data = socket->read(data_size);
            emit send(handle, data);

            data_size = 0;
        }
    }
}

void TcpServer::onDisconnected(qintptr handle)
{
    qDebug() << "socket disconnected " << handle;
    if (handle != -1){
        emit changeStatus(handle, 0);
        QTcpSocket *socket = *socketMap.find(handle);
        socketMap.remove(handle);
        socket->close();
        socket->deleteLater();
    }
}

void TcpServer::start()
{
    if ( listen(QHostAddress::Any, 12345) )
        qDebug() << "Listening...";
    else
        qDebug() << "Error: " << errorString();
}

void TcpServer::response(qintptr handle, QByteArray data)
{
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream << static_cast<decltype(data_size)>(data.size());
    payload.append(data);

    if (handle > 0)
    {
        QTcpSocket *socket = *socketMap.find(handle);
        socket->write(payload);
    }
    else if (handle < 0)
    {
        for(auto &socket: socketMap)
            if (socket->socketDescriptor() != -handle)
            socket->write(payload);
    }
    else
        for(auto &socket: socketMap)
            socket->write(payload);
}
