#ifndef QOSCAR_H
#define QOSCAR_H

typedef unsigned long DWORD, *PDWORD, *LPDWORD;
typedef unsigned short WORD, *PWORD, *LPWORD;

#include <QObject>
#include <QDateTime>
#include <QByteArray>
#include <QTime>
#include <QTimer>
#include <QTextCodec>
#include <QNetworkProxy>

#include "qoscarconsts.h"
#include "qoscarsock.h"
#include "qoscarbasic.h"
#include "qoservice.h"
#include "qmetainfo.h"
#include "qoscarident.h"
#include "qicbm.h"
#include "qrostertools.h"


#define LIBVERSION 0.5.1;

/*==== 

[QOSCAR — Qt class for OSCAR protocol.]

[=========================================]
[=========================================]

 Created by:
  RankoR
 Thanks to:
  .fry, metal, astako, AndRay (winAnd),
  Miracle, SunDagy, forum.motofan.ru, forum.asechka.ru

  Official site:
    icyqt.org


 Started:       28.10.2009
 Last update:   21.02.2010

 TODO:
    * Доделать сигналы ошибок
    * Смена пароля (осторожно, блять!)
    * Получение КЛ
    + Typing notifications
    + Unicode вынесен из класса
    - You were added
    - SMS
    - Search
    * Запрос инфы
    * Получение инфы
    * Users online/offline
    + Добавление пользователей
    * Удаление пользователей
    - MD5 Login
    * Constants
    * Статусы
    - xStatuses
    * Деструкторы
    * Прокомментировать константы
 BUGS:
    - Смена пароля!!!!!!!!!!!!!!!!!!!!!
    + Разбор КЛ

====*/

class QOSCAR: public QObject
{
    Q_OBJECT

    public:
            QOSCAR(QObject* parent);
            ~QOSCAR();

            void login();
            void logoff();
            void ms5Login(const QString &fSN, const QString &fPass);
            void sendMessage(const QString &SN, const QString &Message);
            bool isOnline() { return bOnline; }
            void setBasicInfo();
            void changePassword(const QString &sNewPassword);
            void requestInfo(const QString &sSN);

            void searchBySN(const QString &sSN);

            void sendEvilRequest(const QString &sSN, const bool bAnonymous);
            void sendAuthRequest(const QString &sSN, const QString &sReason);
            void sendAuthResponse(const QString &sSN, const QString &sReason,
                                  const bool bAuthorize);
            void requestCL();
            void rosterAddStart();
            void rosterAddEnd();
            void addUser(const QString &sSN, const QString &sAlias,
                         const QString &sNote, const quint16 u16Group);
            void deleteUser(const QString &sSN);

            void sendTypingNotification(const bool bTyping, const QString &sSN);

            void changeStatus(const quint16 u16Status, const quint16 u16Flags);

            void setProxy(const QNetworkProxy &nProxy);
            void setScreenName(const QString &sSN) { sScreenName = sSN; }
            void setPassword(const QString &sPass) { sPassword = sPass; }
            void setAutoRequestCL(bool bAuto) { bAutoRequestCL = bAuto; }
            void setInfo(const QSNInfo &info) { snInfo = info; }
            void setAuthInfo(const bool bWA, const bool bAuth);

            QString screenName() { return sScreenName; }
            QString password() { return sPassword; }
            QString server() { return sServer; }
            //QFeedBagArray contactList() { return CL; }
            QSNInfo *info() { return &snInfo; }
            QRoster *roster() { return &qrRoster; }

            quint64 received() const { return u64Received; }
            quint64 sent() const { return u64Sent; }

    private:
            QICBM ICBM;
            QOService oservice;
            QOSCARMetaInfo metaInfo;
            QOSCARSock socket;
            //QFeedBagArray CL;
            QRoster qrRoster;
            QSNInfo snInfo;
            QIdent ident;
            QString sScreenName,
                    sPassword,
                    sServer,
                    sBOSServer;
            quint16 oscarStatus,
                    qsStatus,
                    oscarFlags,
                    usSequence;
            quint64 u64Received,
                    u64Sent;
            QTimer timer;
            QByteArray baBOSCookie;
            bool bAutoRequestCL,
                 bOnline;

            void incSequence();
            void connectToBOS();

            void handlePacket(const QByteArray &fdataArr);
            void handleSnac(const QByteArray &fdataArr);

            QString roastPassword();
            QByteArray createTlv(quint16 usType, const QByteArray &baData);
            void sendSnac(quint16 usFamId, quint16 usFamSubType,
                          quint16 usFlags, quint32 ulSequence,
                          const QByteArray &baData);
            void sendFlap(char cChannel, const QByteArray &baData, bool bHello);

            void send_OSERVICE__CLIENT_ONLINE();
            void send_OSERVICE__SET_NICKINFO_FIELDS();
            void send_CLI_IDENT();
            void send_CLI_COOKIE();

    private slots:
            void oConnected();
            void oDisconnected();
            void oError(QAbstractSocket::SocketError socketError);
            void oReadyRead();
            void oTimeOut();
            void onCLHandled();
            void onMessage(const QMessage &message);
            void onEvilNotification(const quint16 u16Level);
            void onLoggedIn();
            void onMetaInfo(const QSNInfo &info, const quint8 type);
	
    signals:
            void fError(QErrorType, QString);
            void fWarning(const quint16, const QString);
            void fLoggedIn();
            void fMessageReceived(QMessage);
            void fCLReceived();
            void fLoggedOff();
            void fCLHandled();
            void fEvilNotification(const quint16 u16Level);
            void fAuthResponse(const QString &sSN, const QString &sReason,
                               const bool bAuthorized);
            void fMetaInfo(const QSNInfo &info, const quint8 type);
};

#endif // QOSCAR_H
