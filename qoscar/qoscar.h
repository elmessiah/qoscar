#ifndef QOSCAR_H
#define QOSCAR_H

#include <QObject>
#include <QTextCodec>

#include "qoscarstuff.h"
#include "qoscarsocket.h"
#include "qoscarident.h"
#include "qoscaroservice.h"
#include "qoscaricbm.h"
#include "qoscarimd.h"
#include "qoscarfeedbag.h"

//! A class for OSCAR protocol (ICQ/AIM)
//! \todo BUGS: Jimm incoming encoding
class QOscar : public QObject
{
    Q_OBJECT

    public:
	explicit QOscar(const QString &sn = QString(), const QString &password = QString(),
			const QString &server = "login.icq.com", quint16 port = 5190, quint16 tag = 0);
        ~QOscar();
        QString getSn();
        QString getPassword();
        QString getServer();
        quint16 getPort();
        QString getCodec();
        quint16 getState();
        quint16 getStatus();
        quint16 getStatusFlags();
        QOscarIdent getIdent();
        quint16 getTag();

    signals:
	void onLoggedIn(QOscar *sender);
	void onLoggedOff(QOscar *sender);
	void onError(QOscarError error, QOscar *sender);
	void onMessage(const QMessage &message, QOscar *sender);
	void onRoster(QOscar *sender);
	void onOfflineMessageReceived(QOscar *oscar);
	void onArrived(const QRosterEntry &entry, QOscar *oscar);
	void onDeparted(const QRosterEntry &entry, QOscar *oscar);
        void stateChanged();       // internal use

    public slots:
	void login();
	void logoff();
        void setSn(const QString &sn);
        void setPassword(const QString &password);
        void setServer(const QString &server);
        void setPort(quint16 port);
        void setTag(quint16 tag);
        void setCodec(const QString &codec);
        void setStatus(quint16 status);
        void setStatusFlags(quint16 statusFlags);
        void setIdent(const QOscarIdent &ident);
	void setWebAware(bool auth, bool webAware);
	void setInfo(const QOscarUserInfo &info);
	void requestRoster();
	void requestOfflineMessages();
	void sendTypingNotification(const QString &sn, bool start);
	void sendMessage(const QString &sn, const QString &message);
    
    private slots:
	void onSocketConnected();
	void onSocketDisconnected();
	void onSocketError(QAbstractSocket::SocketError socketError);
	void onSocketDataRead(const QOscarBA &data);
	void onOserviceLoggedIn();
	void onOserviceServerCapabilities();
	void onIcbmMessage(const QMessage &message);
	void onRosterReceived();
	void onBuddyArrived(const QRosterEntry &entry);
	void onBuddyDeparted(const QRosterEntry &entry);
	void onOfflineMessage(const QOfflineMessage &message);
	void onOfflineMessagesDone();
	void onPingTimer();
        void onStateChange();

    private:

        typedef enum ClientState_ {
          StOffline,
          StStart,             // do Connect-to-Host
          StConnecting,        // Connect-to-Host
          StConnected,         // Waiting-for-Welcome-Message (NEW_CHANNEL)
          StLogin,             // Send Login/Password
          StWaitForCookie,     // Wait for the Cookie
          StSessionReady,      // Session-Cookie ok
          StReConnecting,      // Re-Connect to Host
          StReConnected,       // Waiting-for-Welcome-Message (NEW_CHANNEL), the second time ;)
          StOpenSession,       // Send Cookie
          StWaitForServices,   // Get Server Capabilities
          StSendMyServices,    // Send Client Capabilities
          StWaitForServiceAck, // Ack Capabilities..
         
          StRunning,           // YEA.. UP AND RUNNING
 
          StClose,             // Close Connection 
          StError              // Error.. disconnected/offline
        } eClientState;

        // Communication
	QString roastPassword();
	void incSequence();
	void handlePacket(const QOscarBA &data);
	void handleNewPacket();
	void handleClosePacket(const QOscarBA &data);
	void handleSnac(const QOscarBA &data);
	void sendFlap(quint8 channel = 0, const QOscarBA &data = QOscarBA(), bool isFirst = false);
	void sendSnac(quint16 group, quint16 type, quint16 flags, quint32 sequence, const QOscarBA &data);

        // Statemachine
        void setState(eClientState newState);

	QString oscarSN;
	QString oscarPassword;
	QString oscarServer;
	quint16 oscarPort;
	QString oscarCodec;
	QTimer timer;
        QOscarSocket oscarSocket;
	eClientState oscarState;  // Connecting-Sequence..
	QOscarIdent oscarIdent;
	QOscarOService oservice;
	QOscarIcbm icbm;
	QOscarIMD imd;
	QOscarFeedbag feedbag;
	QOscarBA oscarBOSCookie;
	QString oscarBOSServer;
	quint16 oscarStatus;
	quint16 oscarStatusFlags;
	quint16 oscarSequence; 
	quint64 oscarSent;
	quint64 oscarReceived;
	quint16 oscarTag;

};

#endif // QOSCAR_H
