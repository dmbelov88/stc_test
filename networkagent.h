#ifndef NETWORK_AGENT_H
#define NETWORK_AGENT_H

#include <QObject>
#include <QScopedPointer>

#include "tcpserver.h"
#include "tcpclient.h"

class NetworkAgent : public QObject
{
  Q_OBJECT
public:
  explicit NetworkAgent(QObject *parent = Q_NULLPTR);
  ~NetworkAgent();
  bool isServer();

signals:
  void sendData(qintptr handle, QByteArray data);
  void changeStatus(qintptr handle, int status);

public slots:
  void onSend(qintptr handle, QByteArray data);
  void onSendData(qintptr handle, QByteArray);
  void onChangeStatus(qintptr handle, int status);

private:
  TcpClient *client;
  TcpServer *server;
};

#endif // NETWORK_AGENT_H
