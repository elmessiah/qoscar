#ifndef QOSCARSOCK_H
#define QOSCARSOCK_H

#include <QObject>
#include <QSslSocket>
#include <QString>

class QOSCARSock : public QObject
{
    Q_OBJECT

    public:
        QOSCARSock();
        QSslSocket sock;

        bool isConnected() const { return bOnline; }
        void connect(const QString &fHost, const int fPort);
        QByteArray readAllData() { return sock.readAll(); }

    private:
        bool bOnline;

    private slots:
        void fConnected();
        void fDisconnected();
        void fError(QAbstractSocket::SocketError socketError);
        void fReadyRead();

    signals:
        void sConnected();
        void sDisconnected();
        void sError(QAbstractSocket::SocketError);
        void sReadyRead();
};

#endif // QOSCARSOCK_H
