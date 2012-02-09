#include "qoscar.h"

#define OSCARDEBUG

//! Constructor
//! \param sn ICQ UIN
//! \param password ICQ password
//! \param server ICQ server
//! \param tag
QOscar::QOscar(const QString &sn, const QString &password, const QString &server, quint16 port, quint16 tag)
{
    oscarSN      = sn;
    oscarPassword= password;
    oscarServer  = server;
    oscarPort    = port;
    oscarCodec   = "Windows-1251";

    oscarState   = StOffline;
    oscarStatus  = STATUS_ONLINE;
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

    connect(&oscarSocket, SIGNAL(onConnected()), this, SLOT(onSocketConnected()));
    connect(&oscarSocket, SIGNAL(onDisconnected()), this, SLOT(onSocketDisconnected()));
    connect(&oscarSocket, SIGNAL(onError(QAbstractSocket::SocketError)),
	    this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(&oscarSocket, SIGNAL(onDataRead(QOscarBA)), this, SLOT(onSocketDataRead(QOscarBA)));

    connect(&oservice, SIGNAL(serverCapabilities()), this, SLOT(onOserviceServerCapabilities()));

    connect(&icbm, SIGNAL(onMessage(QMessage)), this, SLOT(onIcbmMessage(QMessage)));
    connect(&feedbag, SIGNAL(onRosterReceived()), this, SLOT(onRosterReceived()));
    connect(&feedbag, SIGNAL(onBuddyArrived(QRosterEntry)), this, SLOT(onBuddyArrived(QRosterEntry)));
    connect(&feedbag, SIGNAL(onBuddyDeparted(QRosterEntry)), this, SLOT(onBuddyDeparted(QRosterEntry)));
    connect(&imd, SIGNAL(onOfflineMessage(QOfflineMessage)), this, SLOT(onOfflineMessage(QOfflineMessage)));
    connect(&imd, SIGNAL(onOfflineMessagesDone()), this, SLOT(onOfflineMessagesDone()));

    connect(&timer, SIGNAL(timeout()), this, SLOT(onPingTimer()));
    connect(this, SIGNAL(stateChanged()), this, SLOT(onStateChange()),Qt::QueuedConnection); // Kick Statemachine..
}
//! Destructor
//!
QOscar::~QOscar()
{
    disconnect();
}
//! Get sn
//! \return
QString QOscar::getSn()
{
    return oscarSN;
}
//! Get password
//! \return
QString QOscar::getPassword()
{
    return oscarPassword;
}
//! Get server
//! \return
QString QOscar::getServer()
{
    return oscarServer;
}
//! Get port
//! \return
quint16 QOscar::getPort()
{
    return oscarPort;
}
//! Get codec
//! \return
QString QOscar::getCodec()
{
    return oscarCodec;
}
//! Get state
//! \return
quint16 QOscar::getState()
{
    return oscarState;
}
//! Get status
//! \return
quint16 QOscar::getStatus()
{
    return oscarStatus;
}
//! Get status flags
//! \return
quint16 QOscar::getStatusFlags()
{
    return oscarStatusFlags;
}
//! Get indent
//! \return
QOscarIdent QOscar::getIdent()
{
    return oscarIdent;
}
//! Get tag
//! \return
quint16 QOscar::getTag()
{
    return oscarTag;
}
//! Start login sequence
//!
void QOscar::login()
{
    if ( (oscarState != StOffline) && (oscarState != StError) ) {
#ifdef OSCARDEBUG
	qDebug() << "[Main] {Error} You are already online or connecting!";
#endif
	return;
    }

    setState(StStart);
}

//! Logoff
//!
void QOscar::logoff()
{
    if (oscarState != StRunning)
        return;

    setState(StClose);
    sendFlap(CLOSE_CHANNEL, createCLI__GOODBYE());
    emit onLoggedOff(this);
    setState(StOffline);
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
//!
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
            qDebug() << "[Main] {Error} Flap is not valid!" << flap.getChannel() << ":" << flap.getSequence() << ":" << flap.getData();
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
                handleClosePacket(flap.getData());
		break;

	    case SNAC_CHANNEL:					    // SNAC channel
                handleSnac(flap.getData());
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
    switch(oscarState) {
      case StConnected  : setState(StLogin)      ; break;  // NEW_CHANNEL ok, send Login
      case StReConnected: setState(StOpenSession); break;  // NEW_CHANNEL ok, send Cookie
      default: Q_ASSERT(0 && "unexpected NEW-Packet");
    }
}

//! Handle CLOSE_CHANNEL Flap
//!
void QOscar::handleClosePacket(const QOscarBA &data)
{
    QOscarBA ba(data);

    while ( true ) {

	QTlv tlv(ba);

	if ( ! tlv.isValid() ) {
#ifdef OSCARDEBUG
            qDebug() << "[Main] {Error} TLV is not valid!" << tlv.getType();
#endif
	    break;
	}

        switch ( tlv.getType() ) {

	    case TLV_BOS_IDENT:
                oscarBOSServer = tlv.getData();
                oscarBOSServer.chop(5);			    //! \todo Dirty hack!!! (deleting port)
		break;

	    case TLV_COOKIE_IDENT:
                oscarBOSCookie = tlv.getData();
                setState(StSessionReady);
		break;

	    case RATE_LIMIT_EXCEEDED:			    // Rate limit!
		emit onError(eRateLimit, this);
                qWarning() << "TODO: RATE_LIMIT_EXCEEDED";
		// oscarState = osError;
		break;

            case 8:                                         // \todo .. what means "8"?
                if ( tlv.getData().readU16() == 0x0005 ) {
                    emit onError(eLogonFailed, this);
                    setState(StError);
                } // else 
                  //   emit onError(eRateLimit, this);		//! \todo HACK!!!
                  // setState(StError);
                qWarning() << "TODO: eRateLimit?";
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
            oservice.handlePacket(snac.getData(), snac.getType());
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
    qDebug() << "[Main] {Message} SNAC: " << snac.getGroup() << snac.getType();
#endif
}

//! Sending FLAP to socket
//! \param channel
//! \param data
//! \param isFirst
//! \sa QOscarBA
void QOscar::sendFlap(quint8 channel, const QOscarBA &data, bool isFirst)
{
    if ( ! oscarSocket.isWritable() ) {
#ifdef OSCARDEBUG
	qDebug() << "[Main] {Error} Socket is not writable!";
#endif
	return;
    }
#ifdef OSCARDEBUG
    qDebug() << "[Main] {Message} Write FLAP Channel " << channel << "(1=login, 2=SNAC, 3=error, 4=disconnect)";
#endif

    QFlap flap(channel, oscarSequence, data);
    oscarSent += oscarSocket.write(flap.toByteArray(isFirst));
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
#ifdef OSCARDEBUG
    qDebug() << "[Main] {Message} Send Snac " << group << type << flags;
#endif
    QSnac snac(group, type, flags, sequence, data);
    sendFlap(SNAC_CHANNEL, snac.toByteArray());
}

//! Switch to new State
//! \param state
void QOscar::setState(QOscar::eClientState newState)
{
#ifdef OSCARDEBUG
    qDebug() << "[Main] {Message} Switching from State " << oscarState << " to " << newState;
#endif
    Q_ASSERT(oscarState != newState);
    oscarState = newState;
    emit stateChanged();  
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
//!
void QOscar::requestRoster()
{
    sendFlap(SNAC_CHANNEL, feedbag.createFEEDBAG__QUERY());
    sendFlap(SNAC_CHANNEL, feedbag.createFEEDBAG__USE());
}

//! Request offline messages
//!
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
  switch(oscarState) {
    case StConnecting  : setState(StConnected); break;    // now wait for the first NEW_CHANNEL
    case StReConnecting: setState(StReConnected); break;  // now wair for the second NEW_CHANNEL
    default: Q_ASSERT(0 && "unexpected socket connection");
  }
}

//! Socket is disconnected from host
void QOscar::onSocketDisconnected()
{
    if ( oscarState != StError )
        setState(StOffline);
    if ( timer.isActive() )
	timer.stop();
}

//! Socket Error
//! \param socketError
void QOscar::onSocketError(QAbstractSocket::SocketError socketError)
{
#ifdef OSCARDEBUG
        qDebug() << "[Main] {Error} Socket Error!!!"<<socketError;
#endif
    emit onError(eNetwork, this);
    setState(StError);
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
    qWarning() <<  "TODO: QOscar::onOserviceLoggedIn";
    // oscarState = osOnline;
    emit onLoggedIn(this);
    timer.start(1000 * 60);
}

//! OSERVICE - Logged in
void QOscar::onOserviceServerCapabilities()
{
    setState(StSendMyServices); 
  
    // \todo: is now the right time for this in the login-sequence..?
    emit onLoggedIn(this); 
    timer.start(1000 * 60);
}


//! Incoming message
// \param message
void QOscar::onIcbmMessage(const QMessage &message)
{
    // qDebug() << "ICBM Message received: " << message.sender << message.text;
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

//! handling new states
void QOscar::onStateChange()
/*
     This is the Init-Sequence of ICQ
*/
{
  switch(oscarState) {
    case StOffline :   
      break;
    case StStart :  {
      oscarSocket.connectToServer(oscarServer, oscarPort);
      setState(StConnecting);
    } break;
    case StConnecting :         // waiting for socket-connection
      break;
    case StConnected :          // waiting for NEW-Flap
      break;
    case StLogin: { 
	sendFlap(NEW_CHANNEL, createCLI__IDENT(oscarIdent, oscarSN, roastPassword()), true);
        setState(StWaitForCookie);
    } break;
    case StWaitForCookie:       // handled by "CLOSE"-Flap
      break;
    case StSessionReady: {
        oscarSocket.disconnectFromServer();
        oscarSocket.connectToServer(oscarBOSServer, oscarPort);
        setState(StReConnecting);
    } break;
    case StReConnecting:       // waiting for socket-connection
      break;
    case StReConnected:        // waiting for NEW-Flap
      break;
    case StOpenSession: {
	sendFlap(NEW_CHANNEL, createCLI__COOKIE(oscarBOSCookie), true);
        setState(StWaitForServices);
    } break;
    case StWaitForServices:      // waiting for the service-list
     break;
    case StSendMyServices: {
       sendSnac(FOODGROUP_OSERVICE, 0x0017, 0x0000, 0x0000, oservice.createServiceList());
       setState(StWaitForServiceAck);
    } break;  
    case StWaitForServiceAck:
      qDebug() << "YEA.. go ahead";
      break;
    case StRunning:
      qDebug() << "YEA.. go ahead";
      break;
    case StError: break;
  };
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
//! Set sn
//! \param sn
void QOscar::setSn(const QString &sn)
{
    oscarSN = sn;
}
//! Set password
//! \param password
void QOscar::setPassword(const QString &password)
{
    oscarPassword = password;
}
//! Set server
//! \param server
void QOscar::setServer(const QString &server)
{
    oscarServer = server;
}
//! Set port
//! \param port
void QOscar::setPort(quint16 port)
{
    oscarPort = port;
}
//! Set tag
//! \param tag
void QOscar::setTag(quint16 tag)
{
    oscarTag = tag;
}
//! Set codec
//! \param codec
void QOscar::setCodec(const QString &codec)
{
    oscarCodec = codec;
}

//! Set status
//! \param status
void QOscar::setStatus(quint16 status)
{
    oscarStatus = status;
    sendFlap(SNAC_CHANNEL, oservice.createOSERVICE__SET_NICKINFO_FIELDS(oscarStatus, oscarStatusFlags)); // Send OSERVICE__SET_NICKINFO_FIEDS
}

//! Set statusFlags
//! \param statusFlags
void QOscar::setStatusFlags(quint16 statusFlags)
{
    oscarStatusFlags = statusFlags;
}

//! Set ident
//! \param ident
void QOscar::setIdent(const QOscarIdent &ident)
{
    oscarIdent = ident;
}
