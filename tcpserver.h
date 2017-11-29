#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpSocket: public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket(qintptr handle, QObject *parent = Q_NULLPTR);
    ~TcpSocket() = default;

signals:
    void readyRead(qintptr handle);
    void disconnected(qintptr handle);

public slots:
    void onReadyRead();
    void onDisconnected();

private:
    qintptr handle;
};

class TcpServer: public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = Q_NULLPTR);
    ~TcpServer();

    void start();
    void incomingConnection(qintptr handle);
    void response(qintptr handle, QByteArray data);

signals:
    void send(qintptr handle, QByteArray &data);
    void changeStatus(qintptr handle, int status);

public slots:
    void onReadyRead(qintptr handle);
    void onDisconnected(qintptr handle);

private:
    QString error;
    QMap<qintptr, QTcpSocket*> socketMap;
    qint64 data_size;
};

#endif // SIMPLESERVER_H
