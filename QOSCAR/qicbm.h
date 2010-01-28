#ifndef ICBM_H
#define ICBM_H

#include <QByteArray>
#include <QTextCodec>
#include <QDebug>

#include "qoscarbasic.h"
#include "qoscarconsts.h"

/* Struct for messages */
struct QMessage { QString sSender,
                          sReceiver,
                          sMessage,
                          sSendTime;
                  qint8   cMessageType;
                  quint16 usStatus,
                          usStatusFlags; };

/* SMS Info Reply struct */
struct QSMSInfoReply { quint16 u16Free,
                               u16AsciiLength,
                               u16Utf8Length;
                       QString sCarrier,
                               sCarrierURL,
                               sPhoneCode; };

class QICBM : public QObject
{
    Q_OBJECT

    public:
        QICBM() {};

        QSMSInfoReply handleSMSInfoReply(const QByteArray &bafData);
        void handleClientEvent(const QByteArray &bafData);
        void handleMessage(const QByteArray &baMessage, const QString &sEncoding);


        static QByteArray createICBM__EVIL_REQUEST(const QString &sSN,
                                                   const bool bAnonymous);
        static QByteArray createICBM__MESSAGE_TO_HOST(const QString &SN,
                                                      const QString &Message);
        static QByteArray createICBM__CLIENT_EVENT(const QString &sScreenName,
                                                   const quint16 u16State);
        static QByteArray createICBM__DELETE_PARAMETERS(const quint16 u16Channel);
        static QByteArray createICBM__ADD_PARAMETERS(const quint16 u16Channel,
                                                     const quint32 u32Flags,
                                                     const quint16 u16MaxIncomingLen,
                                                     const quint16 u16MaxSourceEvil,
                                                     const quint16 u16MaxDestEvil,
                                                     const quint16 u16MinInterval);
        QByteArray createICBM__QUERY_SMS_INFO (const QString &sPhoneNum);
        //QByteArray createCLI_ACKOFFLINEMSGS()
        QByteArray cookie() const { return baCookie; }
        void setCookie(const QByteArray &bafCookie) { baCookie = bafCookie; }

    private:
        QByteArray baCookie;

    signals:
        void onMessage(const QMessage &message);
        void onClientEvent(const quint16 u16Channel, const QString &sSN,
                           const quint16 u16Event);
};


#endif // ICBM_H
