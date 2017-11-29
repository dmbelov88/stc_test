#include "tcpclient.h"
#include <ctime>
#include <QDataStream>

TcpClient::TcpClient(QObject *parent):
    QTcpSocket(parent)
{
    data_size = 0;

    connect(this, &TcpClient::connected, this, &TcpClient::onConnected);
    connect(this, &TcpClient::disconnected, this, &TcpClient::onDisconnected);
    connect(this, &TcpClient::readyRead, this, &TcpClient::onReadyRead);
}

bool TcpClient::connecting()
{
    connectToHost(QHostAddress::LocalHost, 12345);
    if ( waitForConnected(2000) )
        return true;
    return false;
}

void TcpClient::onConnected()
{
    srand(time(0));
    QString name = "client_" + QString::number(rand()%10 + 1);
    qDebug() << name;

    // get all data
    uint8_t cmd = 0x11;
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream << static_cast<decltype(data_size)>(sizeof(cmd) + name.size());
    stream << (uint8_t)cmd;
    payload.append(name);

    write(payload);
}

void TcpClient::onDisconnected()
{
    qDebug() << "Disconected";
    emit changeStatus(0, 0);
}

void TcpClient::onReadyRead()
{
    while(bytesAvailable() > data_size)
    {
        if (data_size == 0)
        {
            QByteArray payload = read(sizeof(data_size));
            QDataStream dataStream(payload);
            dataStream >> data_size;
        }
        while ( data_size > 0 )
        {
            QByteArray data = read(data_size);
            data_size = 0;
            qintptr handle = -1;
            emit send(handle, data);
        }
    }
}

void TcpClient::onError(QAbstractSocket::SocketError error)
{
    QString errorMessage;

    switch(error)
    {
    case QAbstractSocket::HostNotFoundError:
        errorMessage.append("The host was not found.");
        break;
    case QAbstractSocket::RemoteHostClosedError:
        errorMessage.append("The remote host is closed.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        errorMessage.append("The connection was refused.");
        break;
    default:
        errorMessage.append("The unknown error.");
    }

    emit connectionError(errorMessage);
}

void TcpClient::onStop()
{
    disconnectFromHost();
}

void TcpClient::response(QByteArray data)
{
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream << static_cast<decltype(data_size)>(data.size());
    payload.append(data);

    qDebug() << "write";
    write(payload);
    waitForBytesWritten();
}

// typename std::decay<decltype(data)>::type
