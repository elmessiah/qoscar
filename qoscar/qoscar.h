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

/** ************************************* **/
/**	    BUGZ			  **/
/**					  **/
/**  + Jimm incoming encoding		  **/
/** ************************************* **/

class QOscar : public QObject
{
    Q_OBJECT

    public:
	explicit QOscar(const QString &sn = QString(), const QString &password = QString(),
			const QString &server = "login.icq.com", quint16 port = 5190, quint16 tag = 0);
	~QOscar()  { disconnect(); }

	QString sn() const { return oscarSN; }
	QString password() const { return oscarPassword; }
	QString server() const { return oscarServer; }
	quint16 port() const { return oscarPort; }

	QString codec() const { return oscarCodec; }

	quint16 state() const { return oscarState; }
	quint16 status() const { return oscarStatus; }
	quint16 statusFlags() const { return oscarStatusFlags; }
	QOscarIdent ident() const { return oscarIdent; }

	quint16 tag() const { return oscarTag; }

    private:
	QString oscarSN;
	QString oscarPassword;
	QString oscarServer;
	quint16 oscarPort;

	QString oscarCodec;

	QTimer timer;

	QOscarSocket socket;
	QOscarState oscarState;
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


	QString roastPassword();
	void incSequence();

	void handlePacket(const QOscarBA &data);
	void handleNewPacket();
	void handleClosePacket(const QOscarBA &data);
	void handleSnac(const QOscarBA &data);

	void sendFlap(quint8 channel = 0, const QOscarBA &data = QOscarBA(), bool isFirst = false);
	void sendSnac(quint16 group, quint16 type, quint16 flags, quint32 sequence, const QOscarBA &data);

    signals:
	void onLoggedIn(QOscar *sender);
	void onLoggedOff(QOscar *sender);
	void onError(QOscarError error, QOscar *sender);
	void onMessage(const QMessage &message, QOscar *sender);
	void onRoster(QOscar *sender);
	void onOfflineMessageReceived(QOscar *oscar);
	void onArrived(const QRosterEntry &entry, QOscar *oscar);
	void onDeparted(const QRosterEntry &entry, QOscar *oscar);

    public slots:
	void login();
	void logoff();

	void setSN(const QString &sn) { oscarSN = sn; }
	void setPassword(const QString &password) { oscarPassword = password; }
	void setServer(const QString &server) { oscarServer = server; }
	void setPort(quint16 port) { oscarPort = port; }
	void setTag(quint16 tag) { oscarTag = tag; }

	void setCodec(const QString &codec) { oscarCodec = codec; }

	void setStatus(quint16 status) { oscarStatus = status; }
	void setStatusFlags(quint16 statusFlags) { oscarStatusFlags = statusFlags; }
	void setIdent(const QOscarIdent &ident) { oscarIdent = ident; }
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

	void onIcbmMessage(const QMessage &message);
	void onRosterReceived();
	void onBuddyArrived(const QRosterEntry &entry);
	void onBuddyDeparted(const QRosterEntry &entry);
	void onOfflineMessage(const QOfflineMessage &message);
	void onOfflineMessagesDone();

	void onPingTimer();
};

#endif // QOSCAR_H
