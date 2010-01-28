#include "qoscar.h"

#include "qmetainfo.h"

QOSCAR::QOSCAR(QObject *parent): QObject(parent)
{
    timer.setInterval(60 * 1000);
    timer.start();

    ident.clientName = "ICQ Client";
    ident.majorVersion = 6;
    ident.minorVersion = 5;
    ident.lesserVersion = 3;
    ident.build = 104;
    ident.unknown = 0x010A;
    ident.subBuild = 30007;
    ident.language = "ru";
    ident.country = "ru";

    qsStatus = Q_OFFLINE;
    oscarStatus = STATUS_ONLINE;
    oscarFlags = STATUS_DCCONT;
    bOnline = bAutoRequestCL = false;

    connect(&timer, SIGNAL(timeout()), this, SLOT(oTimeOut()));
    connect(&qrRoster, SIGNAL(onCLHandled()), this, SLOT(onCLHandled()));
    connect(&ICBM, SIGNAL(onMessage(QMessage)), this, SLOT(onMessage(QMessage)));
    connect(&oservice, SIGNAL(onEvilNotification(quint16)), this,
            SLOT(onEvilNotification(quint16)));
    connect(&socket, SIGNAL(sConnected()), this, SLOT(oConnected()));
    connect(&socket, SIGNAL(sDisconnected()), this, SLOT(oDisconnected()));
    connect(&socket, SIGNAL(sReadyRead()), this, SLOT(oReadyRead()));
    connect(&socket, SIGNAL(sError(QAbstractSocket::SocketError)), this,
                     SLOT(oError(QAbstractSocket::SocketError)));

}

QOSCAR::~QOSCAR()
{

}

/************************************************************/
/**************** SLOTS *************************************/
/***********************************************************/

void QOSCAR::oConnected()
{
    qDebug() << "Connected!";
}

void QOSCAR::oDisconnected()
{
    qDebug() << "Disconnected!";

    if (qsStatus == Q_CONNECTED || qsStatus == Q_CONNECTING_TO_BOS)
        return;
    else
    if ((qsStatus == Q_ONLINE) || (qsStatus == Q_CONNECTING)){
        emit fError(qeConnection, "Disconnected!");
        bOnline = false;
    }else
    if (qsStatus == Q_LOGGING_OFF){
        qsStatus = Q_OFFLINE;
        emit fLoggedOff();
    }
}

void QOSCAR::oError(QAbstractSocket::SocketError socketError)
{
    if ((qsStatus == Q_LOGGING_OFF) || (qsStatus == Q_CONNECTED))
        return;
    else {
        qDebug() << "Error: " << socketError;
        emit fError(qeConnection, "Socket error!");
    }
}

void QOSCAR::oReadyRead()
{
    qDebug() << "Reading data...";
    QByteArray allData(socket.readAllData());
    qDebug() << "Handling packet...";
    handlePacket(allData);
}

void QOSCAR::oTimeOut()
{
    QByteArray bArr;
    if (isOnline())
        sendFlap(KEEP_ALIVE_CHANNEL, bArr, false);
}

void QOSCAR::onCLHandled()
{
    emit fCLHandled();
}

void QOSCAR::onMessage(const QMessage &message)
{
    QMessage mMessage;
    mMessage.sReceiver = sScreenName;
    emit fMessageReceived(mMessage);
}

void QOSCAR::onEvilNotification(quint16 u16Level)
{
    emit fEvilNotification(u16Level);
}

/**************************************************************/
/******** PROCEDURES ******************************************/
/**************************************************************/

/* Setting up the proxy */
void QOSCAR::setProxy(const QNetworkProxy &nProxy)
{
    socket.sock.setProxy(nProxy);
}

/* Handling incoming packet */
void QOSCAR::handlePacket(const QByteArray &fdataArr)
{    
    QByteArray dataArr(fdataArr);
    while (dataArr.size() > 0){

    // if received FLAP
    if (dataArr.at(0) != FLAP_IDENT)
        return;

    QFlap flap(dataArr, true);

    if (flap.channel() == NEW_CHANNEL){ // New connection
        if (qsStatus == Q_CONNECTING)
            send_CLI_IDENT();
        else
            send_CLI_COOKIE();
    }else
        if (flap.channel() == CLOSE_CHANNEL){ // Connection close
            QTlv Tlv;
            QByteArray tmpData(dataArr);
            tmpData.remove(0, 6);
            while (Tlv.notLast()){
                Tlv.handleTlv(tmpData);
                tmpData.remove(0, Tlv.length() + 4);

                if (Tlv.type() == TLV_BOS_IDENT){
                    sBOSServer.append(Tlv.value());
                    sBOSServer.chop(5);
                }else
                if (Tlv.type() == TLV_COOKIE_IDENT){
                    baBOSCookie = Tlv.value();
                    connectToBOS();
                }else
                if (Tlv.type() == MISMATCH_NICK_OR_PASSWORD)
                    emit fError(qeBadPass, "MISMATCH_NICK_OR_PASSWORD");
                else
                if (Tlv.type() == RATE_LIMIT_EXCEEDED)
                    emit fError(qeRateLimited, "RATE_LIMITED");
            }
        }else
        if (flap.channel() == SNAC_CHANNEL)
            handleSnac(dataArr);

    int iLen = dataArr.indexOf(FLAP_IDENT, 2);
    if (iLen > 0)
        dataArr.remove(0, iLen);
    else
        dataArr.clear();
    }
}

/* Handling SNAC */
void QOSCAR::handleSnac(const QByteArray &fdataArr)
{
    QSnac snac;
    QByteArray tmpData(fdataArr);
    tmpData.remove(0, 6);
    snac.handlePacket(tmpData);
    qDebug() << "SNAC: " << snac.familyId() << "; " << snac.familySubType();

    if ( snac.familyId() == 0x0001 && snac.familySubType() == 0x0003 ){
        send_OSERVICE__SET_NICKINFO_FIELDS();
        send_OSERVICE__CLIENT_ONLINE();
        emit fLoggedIn();
        bOnline = true;
    }else
    if ( snac.familyId() == 0x0004 && snac.familySubType() == 0x0007 )
        ICBM.handleMessage(snac.data(), "Windows-1251");
    else
        // CL Received
    if ( snac.familyId() == 0x0013 && snac.familySubType() == 0x0006 ){
        handleRoster(snac.data());
        emit fCLReceived();
    }else
    if ( snac.familyId() == 0x0004 && snac.familySubType() == 0x0001 ){
        bool ok;
        emit fWarning(snac.data().toUInt(&ok, 16), "Bad snac payload!");
    }//else
    //if ( snac.familyId() == 0x0003 && snac.familySubType() == 0x000B )
       // Buddy arrived
//    else
       //if ( snac.familyId() == 0x0003 && snac.familySubType() == 0x000C )
        // Buddy departed

    // 04,14 - CLI_EVENT (type nnotification), 02/00 start/stop
}

/* Sending CLI_IDENT */
void QOSCAR::send_CLI_IDENT()
{
    sendFlap(NEW_CHANNEL, createCLI_IDENT(ident, sScreenName, roastPassword()), true);
}

/* Logging in */
void QOSCAR::login()
{
    if (qsStatus != Q_OFFLINE){
        emit fError(qeOther, "You are already logged in or trying to do it");
        return;
    }
    socket.connect(sServer, 0);
    qsStatus = Q_CONNECTING;
}

/* Roasting Password */
QString QOSCAR::roastPassword()
{
    QString result;
    for (int i = 0; i < sPassword.length(); i++){
        unsigned char tmp = sPassword.at(i).toAscii();
        unsigned char res = tmp ^ QRoastArray[i];
        result.append( res );
    }
    return result;
}

/* Increasing sequence */
void QOSCAR::incSequence()
{
    if ( usSequence >= 0x8000 )
        usSequence = 0;
    else
        usSequence++;
}

/* Connecting to BOS server */
void QOSCAR::connectToBOS()
{
    qsStatus = Q_CONNECTING_TO_BOS;
    socket.sock.disconnectFromHost();
    socket.connect(sBOSServer, 5190);
}

/* Sending CLI Cookie */
void QOSCAR::send_CLI_COOKIE()
{
    sendFlap(NEW_CHANNEL, createCLI_Cookie(baBOSCookie), true);
}

/* Sending CLIENT_ONLINE packet */
void QOSCAR::send_OSERVICE__CLIENT_ONLINE()
{
    sendSnac(0x0001, 0x0002, 0x0000, 0x00000000,
             QOService::createOSERVICE__CLIENT_ONLINE());
}

/* Setting xStatus, Status and DC information */
void QOSCAR::send_OSERVICE__SET_NICKINFO_FIELDS()
{
    sendSnac(0x0001, 0x001E, 0x0000, 0x00000000,
             QOService::createOSERVICE__SET_NICKINFO_FIELDS(oscarStatus, oscarFlags));
}

/* Creating TLV packet */
QByteArray QOSCAR::createTlv(quint16 usType, const QByteArray &baData)
{
    QTlv tlv;
    tlv.setType(usType);
    tlv.setData(baData);
    return tlv.toByteArray();
}

void QOSCAR::setAuthInfo(bool bWA, bool bAuth)
{
    sendFlap(SNAC_CHANNEL, createIMD__REQUEST_AUTH_INFO(screenName(), bWA, bAuth),
             false);
}

/* Sending SNAC packet */
void QOSCAR::sendSnac(quint16 usFamId, quint16 usFamSubType,
                      quint16 usFlags, quint32 ulSequence,
                      const QByteArray &baData)
{
    QSnac snac(true, usFamId, usFamSubType, usFlags, 0);
    snac.setData(baData);

    sendFlap(SNAC_CHANNEL, snac.toByteArray(), false);
}

/* Sending FLAP packet */
void QOSCAR::sendFlap(char cChannel, const QByteArray &baData, bool bHello)
{
    if ( !socket.sock.isWritable() )
        return;

    QFlap flap(baData, false);
    flap.setChannel(cChannel);
    flap.setSequence(usSequence);
    socket.sock.write(flap.toByteArray(bHello));
    incSequence();
}

/* Sending message */
void QOSCAR::sendMessage(const QString &SN, const QString &Message)
{
    QByteArray baSnac = QICBM::createICBM__MESSAGE_TO_HOST(SN, Message);
    sendFlap(SNAC_CHANNEL, baSnac, false);
}

/* Logging in by MD5-Auth */
void QOSCAR::ms5Login(const QString &fSN, const QString &fPass)
{
    //
}

/* Setting Basic information */
void QOSCAR::setBasicInfo()
{
    sendFlap(SNAC_CHANNEL, createSEND_BASIC_INFO(snInfo, sScreenName), false);
}

/* Changing password */
void QOSCAR::changePassword(const QString &sNewPassword)
{
    sendFlap(SNAC_CHANNEL, createChangePassword(sNewPassword, sScreenName), false);
}


/* Logging off */
void QOSCAR::logoff()
{
    qsStatus = Q_LOGGING_OFF;
    sendFlap(CLOSE_CHANNEL, createCLI_GOODBYE(), false);
}

/* Requesting Contact List */
void QOSCAR::requestCL()
{
    sendFlap(SNAC_CHANNEL, create_RequestCL(), false);
}

/* Handling roster */
void QOSCAR::handleRoster(const QByteArray &baData)
{
    qrRoster.handleItems(baData);
}

/* Adding user to roster */
void QOSCAR::addUser(const QString &sSN, const QString &sAlias,
                     const QString &sNote, const quint16 u16Group)
{
    sendFlap(SNAC_CHANNEL, QRoster::createFEEDBAG__INSERT_ITEM(sSN, sAlias, sNote, u16Group), false);
}

/* Deleting user from roster */
void QOSCAR::deleteUser(const QString &sSN)
{
    //sendFlap(SNAC_CHANNEL, QRoster::createCLI_BUDDYLIST_REMOVE(sSN), false);
}

/* Start adding buddy to list */
void QOSCAR::rosterAddStart()
{
    sendFlap(SNAC_CHANNEL, QRoster::createFEEDBAG__ADDSTART(), false);
}

/* End adding buddy to list */
void QOSCAR::rosterAddEnd()
{
    sendFlap(SNAC_CHANNEL, QRoster::createFEEDBAG__ADDEND(), false);
}

/* Typing notifications */
void QOSCAR::sendTypingNotification(const bool bTyping, const QString &sSN)
{
    if ( bTyping )
        sendFlap(SNAC_CHANNEL, QICBM::createICBM__CLIENT_EVENT(sSN, TYPING_BEGIN), false);
    else
        sendFlap(SNAC_CHANNEL, QICBM::createICBM__CLIENT_EVENT(sSN, TYPING_END), false);
}

/* Changing plain status */
void QOSCAR::changeStatus(quint16 u16Status, quint16 u16Flags)
{
    oscarStatus = u16Status;
    oscarFlags = u16Flags;
    send_OSERVICE__SET_NICKINFO_FIELDS();
}

/* Sends evil request for SN to server */
void QOSCAR::sendEvilRequest(const QString &sSN, bool bAnonymous)
{
    sendFlap(SNAC_CHANNEL, QICBM::createICBM__EVIL_REQUEST(sSN, bAnonymous), false);
}

/* Sends auth request to SN */
void QOSCAR::sendAuthRequest(const QString &sSN, const QString &sReason)
{
    sendFlap(SNAC_CHANNEL, QRoster::createFEEDBAG__AUTHORIZE_REQUEST(sSN, sReason),
             false);
}

/* Sends auth response to SN */
void QOSCAR::sendAuthResponse(const QString &sSN, const QString &sReason,
                              bool bAuthorize)
{
    sendFlap(SNAC_CHANNEL, QRoster::createFEEDBAG__AUTHORIZE(sSN, sReason,
                                                             bAuthorize), false);
}
