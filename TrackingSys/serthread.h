#ifndef SERTHREAD_H
#define SERTHREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>


class SerThread : public QThread
{
    Q_OBJECT
public:
    explicit SerThread(qintptr ID,QObject *parent = 0);
    void run();
    QByteArray Data;

  signals:
      void error(QTcpSocket::SocketError socketerror);

  public slots:
      void readyRead();
      void disconnected();

  private:
      QTcpSocket *socket;
      qintptr socketDescriptor;
};

#endif // SERTHREAD_H
