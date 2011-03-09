#include "qoscar.h"

//#define OSCARDEBUG

//! Constructor
//! \param sn ICQ UIN
//! \param password ICQ password
//! \param server ICQ server
//! \param tag
QOscar::QOscar(const QString &sn, const QString &password, const QString &server, quint16 port, quint16 tag)
{
    oscarSN = sn;
    oscarPassword = password;
    oscarServer = server;
    oscarPort = port;
    oscarCodec = "Windows-1251";

    oscarState = osOffline;
    oscarStatus = STATUS_ONLINE;
    oscarStatusFlags = STATUS_WEBAWARE | STATUS_BIRTHDAY;
    oscarSequence = 0;
    oscarSent = oscarReceived = 0;
    oscarTag = tag;

    oscarIdent.clientName = "ICQ Client";
    oscarIdent.majorVersion = 6;
    oscarIdent.minorVersion = 5;
    oscarIdent.lesserVersion = 3;
    oscarIdent.build = 104;
    oscarIdent.unknown = 0x010A;
    oscarIdent.subBuild = 30007;
    oscarIdent.language = "ru";
    oscarIdent.country = "ru";

    icbm.setEncoding(oscarCodec);

    connect(&socket, SIGNAL(onConnected()), this, SLOT(onSocketConnected()));
    connect(&socket, SIGNAL(onDisconnected()), this, SLOT(onSocketDisconnected()));
    connect(&socket, SIGNAL(onError(QAbstractSocket::SocketError)),
	    this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(&socket, SIGNAL(onDataRead(QOscarBA)), this, SLOT(onSocketDataRead(QOscarBA)));

    connect(&oservice, SIGNAL(onLoggedIn()), this, SLOT(onOserviceLoggedIn()));

    connect(&icbm, SIGNAL(onMessage(QMessage)), this, SLOT(onIcbmMessage(QMessage)));
    connect(&feedbag, SIGNAL(onRosterReceived()), this, SLOT(onRosterReceived()));
    connect(&feedbag, SIGNAL(onBuddyArrived(QRosterEntry)), this, SLOT(onBuddyArrived(QRosterEntry)));
    connect(&feedbag, SIGNAL(onBuddyDeparted(QRosterEntry)), this, SLOT(onBuddyDeparted(QRosterEntry)));
    connect(&imd, SIGNAL(onOfflineMessage(QOfflineMessage)), this, SLOT(onOfflineMessage(QOfflineMessage)));
    connect(&imd, SIGNAL(onOfflineMessagesDone()), this, SLOT(onOfflineMessagesDone()));

    connect(&timer, SIGNAL(timeout()), this, SLOT(onPingTimer()));
}

//! Start login sequence
void QOscar::login()
{
    if ( (oscarState != osOffline) && (oscarState != osError) ) {
#ifdef OSCARDEBUG
	qDebug() << "[Main] {Error} You are already online or connecting!";
#endif
	return;
    }

    oscarState = osConnecting;
    socket.connectToServer(oscarServer, oscarPort);
}

//! Logoff
void QOscar::logoff()
{
    sendFlap(CLOSE_CHANNEL, createCLI__GOODBYE());
    oscarState = osOffline;
    emit onLoggedOff(this);
}

//! Roast password
//! \return roasted password
QString QOscar::roastPassword()
{
    QString result;
    for ( qint32 i = 0; i < oscarPassword.length(); i++ )
	result.append(oscarPassword.at(i).toAscii() ^ QRoastArray[i]);
    return result;
}

//! Increase Sequence
void QOscar::incSequence()
{
    if ( oscarSequence < 0x8000 )
	oscarSequence++;
    else
	oscarSequence = 0;
}

//! Handle received packet
//! \param data
//! \sa QOscarBA
void QOscar::handlePacket(const QOscarBA &data)
{
    QOscarBA ba(data);

#ifdef OSCARDEBUG
    qDebug() << "[Main] {Message} Handling FLAPs...";
#endif

    while ( true ) {

	QFlap flap(ba);
	if ( ! flap.isValid() ) {
#ifdef OSCARDEBUG
	    qDebug() << "[Main] {Error} Flap is not valid!" << flap.channel() << ":" << flap.sequence() << ":" << flap.data();
#endif
	    break;
	}

        switch ( flap.getChannel() ) {

	    case NEW_CHANNEL:					    // New connection negonation
#ifdef OSCARDEBUG
		qDebug() << "[Main] {Message} NEW_CHANNEL FLAP";
#endif
		handleNewPacket();
		break;

	    case CLOSE_CHANNEL:					    // Close connection
#ifdef OSCARDEBUG
		qDebug() << "[Main] {Message} CLOSE_CHANNEL FLAP";
#endif
		handleClosePacket(flap.data());
		break;

	    case SNAC_CHANNEL:					    // SNAC channel
		handleSnac(flap.data());
		break;

	    default:
		break;

	}

	if ( flap.isLast() ) {
#ifdef OSCARDEBUG
	    qDebug() << "[Main] {Message} All FLAPs are handled!";
#endif
	    break;
	}

        if ( (quint32) ba.length() < flap.getLength() + 10 )
	    break;
        ba.remove(0, flap.getLength() + 10);
    }
}

//! Handle NEW_CHANNEL Flap
void QOscar::handleNewPacket()
{
    if ( oscarState == osConnected )
	sendFlap(NEW_CHANNEL, createCLI__IDENT(oscarIdent, oscarSN, roastPassword()), true);
    else
	sendFlap(NEW_CHANNEL, createCLI__COOKIE(oscarBOSCookie), true);
}

//! Handle CLOSE_CHANNEL Flap
void QOscar::handleClosePacket(const QOscarBA &data)
{
    QOscarBA ba(data);

    while ( true ) {

	QTlv tlv(ba);

	if ( ! tlv.isValid() ) {
#ifdef OSCARDEBUG
	    qDebug() << "[Main] {Error} TLV is not valid!" << tlv.type();
#endif
	    break;
	}

        switch ( tlv.getType() ) {

	    case TLV_BOS_IDENT:
                oscarBOSServer = tlv.getData();
		oscarBOSServer.chop(5);			    // Dirty hack!!! (deleting port)
		break;

	    case TLV_COOKIE_IDENT:
                oscarBOSCookie = tlv.getData();
		oscarState = osConnectingToBOS;
		socket.disconnectFromServer();
		socket.connectToServer(oscarBOSServer, oscarPort);

		break;

	    case RATE_LIMIT_EXCEEDED:			    // Rate limit!
		emit onError(eRateLimit, this);
		oscarState = osError;
		break;

            case 8:
                if ( tlv.getData().readU16() == 0x0005 )
                    emit onError(eLogonFailed, this);
                else
                    emit onError(eRateLimit, this);		// HACK!!!
		oscarState = osError;
		break;

	    default:
		break;
	}

	if ( tlv.isLast() ) {
#ifdef OSCARDEBUG
	    qDebug() << "[Main] {Message} All TLVs are parsed!";
#endif
	    break;
	}

        if ( ba.length() < tlv.getLength() + 2 + 2)
	    break;

        ba.remove(0, tlv.getLength() + 2 + 2);
    }
}

//! Handling SNAC packet
//! \param data
//! \sa QOscarBA
void QOscar::handleSnac(const QOscarBA &data)
{
    QSnac snac(data);

    if ( ! snac.isValid() ) {
#ifdef OSCARDEBUG
	qDebug() << "[Main] {Error} SNAC is not valid!";
#endif
	return;
    }

    switch ( snac.getGroup() ) {

	case FOODGROUP_OSERVICE:		// OSERVICE PACKET
            oservice.handlePacket(snac.data(), snac.getType());
	    break;

	case FOODGROUP_ICBM:			// ICBM PACKET
	    icbm.handlePacket(snac);
	    break;

	case FOODGROUP_FEEDBAG:
	    feedbag.handlePacket(snac);
	    break;

	default:
	    break;
    }
#ifdef OSCARDEBUG
    qDebug() << "[Main] {Message} SNAC: " << snac.group() << snac.type();
#endif
}

//! Sending FLAP to socket
//! \param channel
//! \param data
//! \param isFirst
//! \sa QOscarBA
void QOscar::sendFlap(quint8 channel, const QOscarBA &data, bool isFirst)
{
    if ( ! socket.isWritable() ) {
#ifdef OSCARDEBUG
	qDebug() << "[Main] {Error} Socket is not writable!";
#endif
	return;
    }

    QFlap flap(channel, oscarSequence, data);
    oscarSent += socket.write(flap.toByteArray(isFirst));
    incSequence();
}

//! Sending SNAC to socket
//! \param group
//! \param type
//! \param flags
//! \param sequence
//! \param data
//! \sa QOscarBA
void QOscar::sendSnac(quint16 group, quint16 type, quint16 flags, quint32 sequence, const QOscarBA &data)
{
    QSnac snac(group, type, flags, sequence, data);
    sendFlap(SNAC_CHANNEL, snac.toByteArray());
}

//! Sending message
//! \param sn
//! \param message
void QOscar::sendMessage(const QString &sn, const QString &message)
{
    sendFlap(SNAC_CHANNEL, icbm.createICBM__MESSAGE_TO_HOST(sn, message));
}

//! Set web aware and authorization
//! \param auth
//! \param webAware
void QOscar::setWebAware(bool auth, bool webAware)
{
    sendFlap(SNAC_CHANNEL, imd.createIMD__REQUEST_SET_WEBSTATUS(oscarSN, auth, webAware));
}

//! Set FULL user info
//! \param info
//! \sa QOscarUserInfo
void QOscar::setInfo(const QOscarUserInfo &info)
{
    sendFlap(SNAC_CHANNEL, imd.createIMD__REQUEST_SET_FULL_INFO(oscarSN, info));
}

//! Send typing notification
//! \param sn
//! \param start
void QOscar::sendTypingNotification(const QString &sn, bool start)
{
    sendFlap(SNAC_CHANNEL, icbm.createICBM__CLIENT_EVENT(sn, (start) ? TYPING_BEGIN : TYPING_END));
}

//! Request roster
void QOscar::requestRoster()
{
    sendFlap(SNAC_CHANNEL, feedbag.createFEEDBAG__QUERY());
    sendFlap(SNAC_CHANNEL, feedbag.createFEEDBAG__USE());
}

//! Request offline messages
void QOscar::requestOfflineMessages()
{
    sendFlap(SNAC_CHANNEL, imd.createIMD__REQUEST_OFFLINE_MESSAGES(oscarSN));
}

/** ************************************************************ **/
/**		    SLOTS					 **/
/** ************************************************************ **/

//! Socket is connected to host
void QOscar::onSocketConnected()
{
    if ( oscarState == osConnecting )
	oscarState = osConnected;
    else
	oscarState = osConnectedToBOS;
}

//! Socket is disconnected from host
void QOscar::onSocketDisconnected()
{
    if ( oscarState != osError )
	oscarState = osOffline;

    if ( timer.isActive() )
	timer.stop();
}

//! Socket Error
//! \param socketError
void QOscar::onSocketError(QAbstractSocket::SocketError socketError)
{
    oscarState = osError;
    emit onError(eNetwork, this);
}

//! Socket read some data
//! \param data
void QOscar::onSocketDataRead(const QOscarBA &data)
{
    oscarReceived += data.length();
    handlePacket(data);
}

//! OSERVICE - Logged in
void QOscar::onOserviceLoggedIn()
{
    sendFlap(SNAC_CHANNEL, oservice.createOSERVICE__SET_NICKINFO_FIELDS(oscarStatus, oscarStatusFlags)); // Send OSERVICE__SET_NICKINFO_FIEDS
    sendFlap(SNAC_CHANNEL, oservice.createOSERVICE__CLIENT_ONLINE());					 // Send OSERVICE__CLIENT_ONLINE
    sendFlap(SNAC_CHANNEL, feedbag.createFEEDBAG__USE());						 // For arrived/departed
    oscarState = osOnline;
    emit onLoggedIn(this);
    timer.start(1000 * 60);
}

//! Incoming message
// \param message
void QOscar::onIcbmMessage(const QMessage &message)
{
//    qDebug() << "ICBM Message received: " << message.sender << message.text;
    emit onMessage(message, this);
}

//! Roster part received
void QOscar::onRosterReceived()
{
#ifdef OSCARDEBUG
    qDebug() << "Roster received!";
#endif
    emit onRoster(this);
}

//! On Ping timer
void QOscar::onPingTimer()
{
    sendFlap(KEEP_ALIVE_CHANNEL);
}

//! Offline message received
//! \param message
void QOscar::onOfflineMessage(const QOfflineMessage &message)
{
#ifdef OSCARDEBUG
    qDebug() << "Offline message:" << message.sender << message.time << message.text;
#endif
    emit onOfflineMessageReceived(this);
}

//! All Offline messages received
void QOscar::onOfflineMessagesDone()
{
    sendFlap(SNAC_CHANNEL, imd.createIMD__ACK_OFFLINE_MESSAGES(oscarSN)); // Temporary!!
}

//! Buddy arrived
//! \param entry
//! \sa QRosterEntry
void QOscar::onBuddyArrived(const QRosterEntry &entry)
{
#ifdef OSCARDEBUG
    qDebug() << "Buddy arrived:" << entry.name;
#endif
    emit onArrived(entry, this);
}

//! Buddy departed
//! \param entry
//! \sa QRosterEntry
void QOscar::onBuddyDeparted(const QRosterEntry &entry)
{
#ifdef OSCARDEBUG
    qDebug() << "Buddy departed:" << entry.name;
#endif
    emit onDeparted(entry, this);
}
