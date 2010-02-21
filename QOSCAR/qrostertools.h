#ifndef QROSTERTOOLS_H
#define QROSTERTOOLS_H


#include <QStringList>
#include <QByteArray>
#include <QDateTime>
#include <QPointer>
#include <QObject>
#include <QDebug>
#include <QMutex>


#include "qoscarbasic.h"
#include "qoscarconsts.h"

struct QBuddy { quint16     u16WarnLevel,
                            u16UserClass,
                            u16Status,
                            u16StatusFlags,
                            u16IP;
                quint32     u32OnlineTime;
                QString     sScreenName;
                QDateTime   dtRegistered,
                            dtAwayUpdate,
                            dtOnlineSince;
                QByteArray  baCapabilities,
                            baNewCapabilities; };

struct QRosterItem { QString sName,
                             sScreenName;
                     quint16 u16Group,
                             u16Id,
                             u16Type,
                             u16DataLength; };

struct QRawRosterItem { quint16     u16NameLength,
                                    u16Group,
                                    u16Id,
                                    u16Type,
                                    u16DataLength;
                        QByteArray  baScreenName,
                                    baData; };

class QRoster : public QObject
{
    Q_OBJECT

    public:
        QRoster();
        ~QRoster();

        QRosterItem *items() { return riItems; }
        quint16 count() const { return u16Count; }

        void handlePacket(const QByteArray &bafData, const quint16 u16Family,
                          const quint16 u16SubType);
        void handleItems(const QByteArray &baItems);
        void handleAuthRequest(const QByteArray &bafData);
        void handleBuddyDeparted(const QByteArray &bafData);
        void handleBuddyArrived(const QByteArray &bafData);

        static QByteArray createFEEDBAG__INSERT_ITEM(const QString &sSN, const QString &sAlias,
                                                     const QString &sNote, const quint16 u16fGroup);
        static QByteArray create__CLI_BUDDYLIST_REMOVE(const QString &sSN);
        static QByteArray createFEEDBAG__ADDSTART();
        static QByteArray createFEEDBAG__ADDEND();
        static QByteArray createFEEDBAG__AUTHORIZE_REQUEST(const QString &sSN,
                                                           const QString &sReason);
        static QByteArray createFEEDBAG__AUTHORIZE(const QString &sSN,
                                                   const QString &sReason,
                                                   const quint8 u8Flag);
    private:
        QRosterItem *riItems;
        QMutex mutex;
        quint16 u16Count;

        void handleRawItems(QRawRosterItem *rawItems, quint16 u16ItemsCount);

    signals:
        void onCLHandled();
        void onBuddyArrivedOrDeparted(const QBuddy &buddy, const bool arrived);
        void onAuthRequest(const QString &sSN, const QString &sReason);
};

QByteArray create_RequestCL();

#endif // QROSTERTOOLS_H
