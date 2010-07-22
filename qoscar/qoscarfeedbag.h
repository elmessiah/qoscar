#ifndef QOSCARFEEDBAG_H
#define QOSCARFEEDBAG_H

#include <QObject>
#include <QDebug>

#include "qoscarba.h"
#include "qoscarbasic.h"

typedef struct
{
    QString name;
    QString sms;
    QString comment;
    QString nick;
    QString email;
    quint16 group;
    quint16 id;
    quint16 type;
    quint16 warnLevel;
    quint32 status;
    QList<quint16> items;
} QRosterEntry;

typedef QList<QRosterEntry> *QRoster;

class QOscarFeedbag : public QObject
{
    Q_OBJECT

    public:
	QOscarBA createFEEDBAG__QUERY();
	QOscarBA createFEEDBAG__USE();

	void handlePacket(const QSnac &snac);

	QRoster roster() { return &oscarRoster; }

    private:
	QList<QRosterEntry> oscarRoster;

	void handleRosterPacket(const QOscarBA &data);
	void handleBuddyArrived(const QOscarBA &data);
	void handleBuddyDeparted(const QOscarBA &data);


    signals:
	void onRosterReceived();
	void onBuddyArrived(const QRosterEntry &entry);
	void onBuddyDeparted(const QRosterEntry &entry);

};

#endif // QOSCARFEEDBAG_H
