#ifndef QOSERVICE_H
#define QOSERVICE_H

#include <QObject>

#include "qoscarbasic.h"

//struct oservice_packet { quint16 u16FamNum,
//                                 u16FamVersion,
//                                 u16ToolId,
//                                 u16ToolVersion; };

class QOService : public QObject
{
    Q_OBJECT

    public:
    QOService() {}

    void handleEvilNotification(const QByteArray &bafData);

    static QByteArray createPacket(const quint16 famNum, const quint16 famVersion,
                                   const quint16 toolId, const quint16 toolVersion);

    static QByteArray createOSERVICE__CLIENT_ONLINE();
    static QByteArray createOSERVICE__SET_NICKINFO_FIELDS(const quint16 u16Status,
                                                          const quint16 u16StatusFlags);

    signals:
        void onEvilNotification(const quint16 u16NewLevel);
};


#endif // QOSERVICE_H
