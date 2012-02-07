#include "qoscarsocket.h"

QOscarSocket::QOscarSocket()
{
    socketState = sOffline;
    oscarServer = "login.oscar.com";
    oscarPort = 5190;
    connectionTimeout = 16000;

    connect(this, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    connect(this, SIGNAL(disconnected()), this, SLOT(onSocketConnected()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

//! Connect to server 2
//! \param server
//! \param port
void QOscarSocket::connectToServer(const QString &server, const quint16 port)
{
    oscarServer = server;
    oscarPort = port;
    connectToServer();
}

//! Connect to server
//!
void QOscarSocket::connectToServer()
{
    if ( (socketState != sOffline) && (socketState != sError) ) {
//	qDebug() << "[SOCKET] {Warning} Cannot connect: socket state is" << socketState;
//	return;
    }

    socketState = sConnecting;
    connectToHost(oscarServer, oscarPort);
    timer.singleShot(connectionTimeout, this, SLOT(onTimer()));
}

//! Disconnect from server
//!
void QOscarSocket::disconnectFromServer()
{
    if ( socketState != sOnline ) {
//	qDebug() << "[SOCKET] {Warning} Cannot disconnect: socket state is" << socketState;
//	return;
    }

    if ( timer.isActive() )
	timer.stop();

    socketState = sOffline;
    disconnectFromHost();
}

/** ********************************************************** **/
/**		    SLOTS				       **/
/** ********************************************************** **/

//! If timer ticked
//!
void QOscarSocket::onTimer()
{
    if ( socketState != sConnecting )
	return;

    socketState = sError;
//    qDebug() << "[SOCKET] {Error} Connection timeout!";
    emit onError(QAbstractSocket::ConnectionRefusedError);
}

//! Socket Connected
//!
void QOscarSocket::onSocketConnected()
{
    socketState = sOnline;
    emit onConnected();
}

//! Socket Disconnected
//!
void QOscarSocket::onSocketDisconnected()
{
    socketState = sOffline;
    emit onDisconnected();
}

//! Socket Error
//!
void QOscarSocket::onSocketError(QAbstractSocket::SocketError socketError)
{
    socketState = sError;
    emit onError(socketError);
}

//! Socket is ready to read
//!
void QOscarSocket::onSocketReadyRead()
{
    emit onDataRead(QOscarBA(readAll()));
}
