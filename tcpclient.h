#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QAbstractSocket>
#include <QDebug>
#include <QHostAddress>
#include <QObject>
#include <QTcpSocket>
#include <QThread>

class TcpClient: public QTcpSocket
{
    Q_OBJECT
public:
    TcpClient(QObject *parent = Q_NULLPTR);
    bool connecting();
    void response(QByteArray);

private:
    qint64 data_size;

signals:
    void send(qintptr handle, QByteArray data);
    void connectionError(QString);
    void changeStatus(qintptr handle, int status);

public slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError);
    void onStop();
};

#endif // TCP_CLIENT_H
