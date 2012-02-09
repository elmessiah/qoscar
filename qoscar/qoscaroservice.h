#ifndef QOSCAROSERVICE_H
#define QOSCAROSERVICE_H

#include <QObject>

#include "qoscarstuff.h"

class QOscarOService : public QObject
{
    Q_OBJECT

    public:
	void handlePacket(const QOscarBA &data, quint16 type);

	QOscarBA createServiceList();

	QOscarBA createPacket(quint16 family, quint16 famVersion, quint16 toolId, quint16 toolVersion);
	QOscarBA createOSERVICE__CLIENT_ONLINE();
	QOscarBA createOSERVICE__SET_NICKINFO_FIELDS(quint16 status, quint16 statusFlags);

    signals:
	void serverCapabilities();  // we got new server capabilities

    private:
        QOscarBA createServiceInfo(quint16 service, quint16 version);
};

#endif // QOSCAROSERVICE_H
