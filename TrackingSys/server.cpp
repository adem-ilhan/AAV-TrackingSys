#include "server.h"
Server::Server(QObject *parent):QTcpServer(parent)
{

}

void Server::startServer()
{
    int port = 1234;

       if(!this->listen(QHostAddress::Any,port))
       {
           qDebug() << "Could not start server";
       }
       else
       {
           qDebug() << "Listening to port " << port << "...";
       }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
       qDebug() << socketDescriptor << " Connecting...";

       SerThread *thread = new SerThread(socketDescriptor, this);


       connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

       thread->start();
}
