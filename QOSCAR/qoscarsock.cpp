#include "qoscarsock.h"


/* constructor */
QOSCARSock::QOSCARSock()
{
    bOnline = false;

    QObject::connect(&sock, SIGNAL(connected()), this, SLOT(fConnected(void)));
    QObject::connect(&sock, SIGNAL(disconnected()), this, SLOT(fDisconnected()));
    QObject::connect(&sock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(fError(QAbstractSocket::SocketError)));
    QObject::connect(&sock, SIGNAL(readyRead()), this, SLOT(fReadyRead()));
}

/* Connecting to host */
void QOSCARSock::connect(const QString &fHost, const int fPort)
{
    QString tHost;
    int tPort;

    if ((fHost.length() == 0) || (fPort == 0)){
        tHost = "login.messaging.aol.com";
        tPort = 5190;
    }else{
        tHost = fHost;
        tPort = fPort;
    }
        sock.connectToHost(tHost, tPort);

    qDebug() << "Connecting to " << tHost;
}

/*************************************/
/********** SIGNALS *****************/
/***********************************/

/* Connected signal */
void QOSCARSock::fConnected()
{
    bOnline = true;
    emit sConnected();
}

/* Disconnected signal */
void QOSCARSock::fDisconnected()
{
    bOnline = false;
    emit sDisconnected();
}

/* Error signal */
void QOSCARSock::fError(QAbstractSocket::SocketError socketError)
{
    bOnline = false;
    emit sError(socketError);
}

/* ReadyRead Signal */
void QOSCARSock::fReadyRead()
{
    emit sReadyRead();
}
