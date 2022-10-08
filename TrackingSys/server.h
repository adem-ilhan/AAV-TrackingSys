#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>

class Server : public QTcpServer
{
    Q_OBJECT
public:
   explicit Server(QObject *parent =0);
};

#endif // SERVER_H
