#ifndef QOSCARSOCKET_H
#define QOSCARSOCKET_H

#include <QTcpSocket>
#include <QTimer>
#include <QDebug>

#include "qoscarba.h"


enum QOscarSocketState { sOffline, sConnecting, sOnline, sError };

class QOscarSocket : public QTcpSocket
{
    Q_OBJECT

    public:
	explicit QOscarSocket();

	void setServer(const QString &Server, quint16 port, quint16 timeout) { oscarServer = Server; oscarPort = port; connectionTimeout = timeout; }
	QOscarBA readAllData() { return QOscarBA(readAll()); }

        QOscarSocketState getState() const { return socketState; }

    private:
	QString oscarServer;
	quint16 oscarPort;
	quint16 connectionTimeout;

	QOscarSocketState socketState;
	QTimer timer;

    signals:
	void onConnected();
	void onDisconnected();
	void onError(QAbstractSocket::SocketError socketError);
	void onDataRead(const QOscarBA &data);

    public slots:
	void connectToServer(const QString &Server, quint16 port);
	void connectToServer();
	void disconnectFromServer();

    private slots:
	void onTimer();
	void onSocketConnected();
	void onSocketDisconnected();
	void onSocketReadyRead();
	void onSocketError(QAbstractSocket::SocketError socketError);
};

#endif // QOSCARSOCKET_H
